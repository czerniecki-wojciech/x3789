
#pragma once

class DLL_INTERFACE VBOTestClass
{
private:
	GLuint vertex_buffer_id;
	GLuint color_buffer_id;
	GLuint indices_buffer_id;
public:
	VBOTestClass();
	void PreDraw();
	void Draw(GLuint shader);
	void PostDraw();
	~VBOTestClass();
};

