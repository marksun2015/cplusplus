#include <glib.h>
#include <glib-unix.h>
#include <stdio.h>
#include "my_demo.h"

static GMainLoop *loop = NULL;
static gboolean signal_handler(gpointer user_data)
{
	g_main_loop_quit(loop);
	return FALSE;
}

int main(int argc, char* argv[])
{
#if !GLIB_CHECK_VERSION(2,32,0)
	if (! g_thread_supported ())
		g_thread_init (NULL);
#endif
#if !GLIB_CHECK_VERSION(2,36,0)
	g_type_init ();
#endif
	loop = g_main_loop_new(NULL, FALSE);
	g_unix_signal_add_full(G_PRIORITY_DEFAULT,
			SIGINT,
			signal_handler,
			NULL,
			NULL);
	int i;

	MyDemo *demos[3];
	int len = sizeof(demos) / sizeof(demos[0]);
	for (i = 0; i < len; i++) {
		printf("construction demos[%d]\n", i);
		gchar *name = g_strdup_printf("kobe%d", i);
		demos[i] = my_demo_new(name, i);
		g_free(name);
	}

	for(i = 0; i < len; i++){
		printf("destruction demos[%d]\n", i);
		g_object_unref(demos[i]);
	}
	g_main_loop_run(loop);
	g_main_loop_unref(loop);
	return 0;
}
