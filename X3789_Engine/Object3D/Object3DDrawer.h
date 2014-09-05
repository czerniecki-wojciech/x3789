
#pragma once

class DLL_INTERFACE Object3DDrawer
{
	static Object3DDrawer* instance;

	unsigned int allocated_object_num;

	Object3D** objects;

private:
	Object3DDrawer()
		: allocated_object_num(0)
	{
		objects = new Object3D*[10000];
	}
public:
	void addNewObject3D(Object3D* object);
	void drawAll();

	static Object3DDrawer* init()
	{
		if (!instance)
			instance = new Object3DDrawer();
		return instance;
	}

	~Object3DDrawer()
	{
		for (int i = 0; i < allocated_object_num; ++i)
		{
			delete objects[i];
		}
	}
};
