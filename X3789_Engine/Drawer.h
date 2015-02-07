
#ifndef __DRAWER_H__
#define __DRAWER_H__

#include <X3789_Engine\Tools\Singleton.h>


class DrawerImpl
{
	friend class Singleton<DrawerImpl, void>;
private:
	DrawerImpl();
	~DrawerImpl();
public:
	void registerVerticesList(VerticesListBase* vertices_list_base);
	void drawAll();
};

typedef Singleton<DrawerImpl, void> Drawer;
#endif
