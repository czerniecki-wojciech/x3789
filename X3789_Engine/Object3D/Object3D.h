
#pragma once

class Object3D
{
private:
	Vertex* vertices;
public:
	Object3D();
	~Object3D();

	void setVertices(Vertex* vertices);
};
