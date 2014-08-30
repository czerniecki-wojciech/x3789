
#ifndef __Object3D__
#define __Object3D__

class VertexStorage;
class UniformStorage;

class DLL_INTERFACE Object3D
{
protected:
	GLuint program_ID;
	GLenum primitive_type;
	GLuint vertex_buffer;
	GLuint color_buffer;

	GLuint mvp_id;
	GLuint object_position_id;

	VertexStorage* vertices;
	UniformStorage* uniforms;

	void loadVertexToGPU();
	void loadUniformsToGPU();

	glm::vec3 position;
public:
	Object3D();
	~Object3D();

	void draw();
	void endObjectDefinition();

	inline void setProgram(GLuint program_ID)
	{
		this->program_ID = program_ID;
		mvp_id = glGetUniformLocation(this->program_ID, "MVP");
		object_position_id = glGetUniformLocation(this->program_ID, "object_position");
	}

	inline GLuint getProgram()
	{
		return this->program_ID;
	}
	
	inline void setPrimitiveType(GLenum primitive_type)
	{
		this->primitive_type = primitive_type;
	}

	inline GLenum getPrimitiveType()
	{
		return this->program_ID;
	}

	inline void setPosition(float x, float y, float z)
	{
		this->position = glm::vec3(x, y, z);
	}
};

#endif
