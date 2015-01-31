
#ifndef __DRAWER_H__
#define __DRAWER_H__

class Drawer
{
    Drawer();
    ~Drawer();

    template<typename T>
    void drawVerticesList(T vertices_list);
};

#endif
