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

typedef enum
{
  PROP_FILENAME = 1,
  PROP_ZOOM_LEVEL,
  N_PROPERTIES
} ViewerFileProperty;

static GParamSpec *obj_properties[N_PROPERTIES] = { NULL, };

/* will create viewer_file_get_type and set viewer_file_parent_class */
G_DEFINE_TYPE (ViewerFile, viewer_file, G_TYPE_OBJECT)


static void viewer_file_set_property (GObject      *object,
		guint         property_id,
		const GValue *value,
		GParamSpec   *pspec)
{
	ViewerFile *self = VIEWER_FILE (object);

	switch ((ViewerFileProperty) property_id)
	{
		case PROP_FILENAME:
			g_free (self->filename);
			self->filename = g_value_dup_string (value);
			g_print ("filename: %s\n", self->filename);
			break;

		case PROP_ZOOM_LEVEL:
			self->zoom_level = g_value_get_uint (value);
			g_print ("zoom level: %u\n", self->zoom_level);
			break;

		default:
			/* We don't have any other property... */
			G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
			break;
	}
}

static void viewer_file_get_property (GObject    *object,
		guint       property_id,
		GValue     *value,
		GParamSpec *pspec)
{
	ViewerFile *self = VIEWER_FILE (object);

	switch ((ViewerFileProperty) property_id)
	{
		case PROP_FILENAME:
			g_value_set_string (value, self->filename);
			break;

		case PROP_ZOOM_LEVEL:
			g_value_set_uint (value, self->zoom_level);
			break;

		default:
			/* We don't have any other property... */
			G_OBJECT_WARN_INVALID_PROPERTY_ID (object, property_id, pspec);
			break;
	}
}

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

	object_class->set_property = viewer_file_set_property;
	object_class->get_property = viewer_file_get_property;

	obj_properties[PROP_FILENAME] =
		g_param_spec_string ("filename",
				"Filename",
				"Name of the file to load and display from.",
				NULL  /* default value */,
				//G_PARAM_CONSTRUCT_ONLY | G_PARAM_READWRITE);
				G_PARAM_READWRITE);

	obj_properties[PROP_ZOOM_LEVEL] =
		g_param_spec_uint ("zoom-level",
				"Zoom level",
				"Zoom level to view the file at.",
				0  /* minimum value */,
				10 /* maximum value */,
				2  /* default value */,
				G_PARAM_READWRITE);

	g_object_class_install_properties (object_class,
			N_PROPERTIES,
			obj_properties);
}

static void viewer_file_init (ViewerFile *self)
{
	/* initialize the object */
	printf("viewer_file_init \n");
}

void main ()
{

	ViewerFile *file;
	//GValue val = G_VALUE_INIT;
	file = g_object_new (VIEWER_TYPE_FILE, NULL);

	//multiple set
	g_object_set (G_OBJECT (file),
              "zoom-level", 6, 
              "filename", "~/some-file.txt", 
              NULL);

	//g_object_set_property (G_OBJECT (file), "zoom-level", &val);
	//g_value_unset (&val);
}
