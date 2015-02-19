
#pragma once

class DLL_INTERFACE VAOTestClass
{
private:
	GLuint vertex_buffer_id;
	GLuint color_buffer_id;
	GLuint vertex_with_colors_id;
public:
	VAOTestClass();
	void PreDraw();
	void Draw(GLuint shader);
	void PostDraw();
	~VAOTestClass();

	float* getVerticesWithColors();
};

