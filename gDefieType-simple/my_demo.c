#include "my_demo.h"
#include <stdio.h>
enum
{
	PROP_0,
	PROP_NAME,
	PROP_AGE,
	N_PROPERTIES
};

#define MY_DEMO_GET_PRIVATE(o) (G_TYPE_INSTANCE_GET_PRIVATE ((o), MY_TYPE_DEMO, MyDemoPrivate))
static void my_demo_init(MyDemo *self);
static void my_demo_class_init(MyDemoClass *klass);

/*
 * G_DEFINE_TYPE 可以让 GObject 库的数据类型系统能够识别我们所定义的 MyDemo 类类型，
 * 它接受三个参数，
   第一个参数是类名，即 MyDemo；
   第二个参数则是类的成员函数名称的前缀，例如 my_demo_get_type 函数即为 MyDemo 类的一个成员函数，"my_demo"是它的前缀；  
   第三个参数则指明 MyDemo 类类型的父类型为G_TYPE_OBJECT。
 * G_DEFINE_TYPE中会调用一个 g_type_register_static_simple 的函数，这个函数的作用就是  
   将用户自己定义的类型注册到系统中，
 * G_DEFINE_TYPE还定义了2个函数（my_demo_init 和 my_demo_class_init），需要自己实现这两个函数。  
   它们是对象的初始化函数，相当于c++的构造函数，第一个函数在每个对象创建的时候都会被调用，
 * 第二个函数只有在第一次创建对象的时候被调用(比如在调用g_type_class_ref的时候，如果class没有初始化，  
   就会调用my_demo_class_init)
*/

G_DEFINE_TYPE (MyDemo, my_demo, G_TYPE_OBJECT);
static void my_demo_dispose(GObject *object);
static void my_demo_finalize(GObject *object);

static void my_demo_set_property(GObject *object, guint prop_id, const GValue *value, GParamSpec *pspec)
{
	MyDemo *self;
	g_return_if_fail(object != NULL);
	self = MY_DEMO (object);
	//self->priv = MY_DEMO_GET_PRIVATE(self);

	switch (prop_id)
	{
		case PROP_NAME:
	        printf("set property name........%s\n",g_value_dup_string(value));
			self->priv->name = g_value_dup_string(value);
			break;
		case PROP_AGE:
	        printf("set property age........%ld\n",g_value_get_int64(value));
			self->priv->age = g_value_get_int64(value);
			break;
		default:
			G_OBJECT_WARN_INVALID_PROPERTY_ID(object, prop_id, pspec);
			break;
	}
}

static void my_demo_get_property(GObject *object, guint prop_id, GValue *value, GParamSpec *pspec)
{
	MyDemo *self;
	g_return_if_fail(object != NULL);
	self = MY_DEMO(object);
	switch (prop_id)
	{
		case PROP_NAME:
			g_value_set_string(value, self->priv->name);
			break;
		case PROP_AGE:
			g_value_set_int64(value, self->priv->age);
			break;
		default:
			G_OBJECT_WARN_INVALID_PROPERTY_ID(object, prop_id, pspec);
			break;
	}
}

//类结构体初始化函数
static void my_demo_class_init(MyDemoClass *klass)
{
	printf("%s\n", __FUNCTION__);

	GObjectClass *object_class = G_OBJECT_CLASS(klass);
	object_class->finalize = my_demo_finalize;
	object_class->dispose = my_demo_dispose;
	
	object_class->set_property = my_demo_set_property;
	object_class->get_property = my_demo_get_property;

    printf("g_object_class_install_property name \n");
	g_object_class_install_property(object_class,
					PROP_NAME,
					g_param_spec_string("name",
							    "name",
							    "Specify the name of demo",
							    "Unknown",
							    G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY)
					);

    printf("g_object_class_install_property age \n");
	g_object_class_install_property(object_class,
					PROP_AGE,
					g_param_spec_int64 ("age",
							    "age",
							    "Specify age number",
							    G_MININT64, G_MAXINT64, 0,
							    G_PARAM_WRITABLE | G_PARAM_CONSTRUCT_ONLY)
					);

	// 如果對struct MyDemoPrivate ⾥⾯添加了成员变量，则执⾏下⾯这⾏代码
	g_type_class_add_private(klass, sizeof(MyDemoPrivate));
}

//实例结构体初始化函数
static void my_demo_init(MyDemo *self)
{
	printf("%s\n", __FUNCTION__);
	self->priv = MY_DEMO_GET_PRIVATE(self);
}

static void my_demo_dispose(GObject *object)
{
	printf("%s\n", __FUNCTION__);
}

static void my_demo_finalize(GObject *object)
{
	printf("%s\n", __FUNCTION__);
	MyDemo *self;

	g_return_if_fail(object != NULL);
	self = MY_DEMO(object);

	if (self->priv->name)
		g_free (self->priv->name);
	
	G_OBJECT_CLASS(my_demo_parent_class)->finalize(object);
}

MyDemo *my_demo_new(const gchar *name, gint64 age)
{
	MyDemo *demo;
	demo = MY_DEMO(g_object_new(MY_TYPE_DEMO,
				"name", name,
				"age", age,
				NULL));
	printf("get property name:%s, age:%ld\n", demo->priv->name, demo->priv->age);
	return demo;
}
