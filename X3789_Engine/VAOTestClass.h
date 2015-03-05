
#pragma once

class test_vertex;

class VertexCollector
{
private:
    test_vertex* vertices;
    unsigned int vertices_num;
public:
    VertexCollector();

    ~VertexCollector();

    void addVertex(float x, float y, float z, float r, float g, float b);

    test_vertex* getVertices()
    {
        return vertices;
    }

    unsigned int getVerticesNum()
    {
        return vertices_num;
    }
};

class DLL_INTERFACE VAOTestClass
{
private:
	GLuint vertex_buffer_id;
	GLuint color_buffer_id;
	GLuint vertex_with_colors_id;

    VertexCollector collector;
public:
	VAOTestClass();
	void PreDraw();
	void Draw(GLuint shader);
	void PostDraw();
	~VAOTestClass();

	float* getVerticesWithColors();
};

