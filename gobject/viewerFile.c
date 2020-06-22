/*
    https://developer.gnome.org/gobject/stable/chapter-gobject.html
    gcc `pkg-config --cflags gtk+-3.0` -o viewerFile viewerFile.c `pkg-config --libs gtk+-3.0`
 */
#include <stdlib.h>
#include <gtk/gtk.h>

#define VIEWER_TYPE_FILE viewer_file_get_type ()
G_DECLARE_FINAL_TYPE (ViewerFile, viewer_file, VIEWER, FILE, GObject)

struct _ViewerFile
{
	GObject parent_instance;

	/* instance members */
	gchar *filename;
	guint zoom_level;
};

/* will create viewer_file_get_type and set viewer_file_parent_class */
G_DEFINE_TYPE (ViewerFile, viewer_file, G_TYPE_OBJECT)

static void viewer_file_constructed (GObject *obj)
{
	printf("viewer_file_constructed \n");
	/* update the object state depending on constructor properties */

	/* Always chain up to the parent constructed function to complete object
	 * initialisation. */
	G_OBJECT_CLASS (viewer_file_parent_class)->constructed (obj);
}

static void viewer_file_finalize (GObject *obj)
{
	printf("viewer_file_finalize \n");
	ViewerFile *self = VIEWER_FILE(obj);
	g_free (self->filename);

	/* Always chain up to the parent finalize function to complete object
	 * destruction. */
	G_OBJECT_CLASS (viewer_file_parent_class)->finalize (obj);
}

static void viewer_file_class_init (ViewerFileClass *klass)
{
	printf("viewer_file_class_init \n");
	GObjectClass *object_class = G_OBJECT_CLASS (klass);

	object_class->constructed = viewer_file_constructed;
	object_class->finalize = viewer_file_finalize;
}

static void viewer_file_init (ViewerFile *self)
{
	/* initialize the object */
	printf("viewer_file_init \n");
	self->filename = "helloworld";
}

void main ()
{
	printf("main \n");
	ViewerFile *file = g_object_new (VIEWER_TYPE_FILE, NULL);
	printf("filename:%s \n",file->filename);
}
