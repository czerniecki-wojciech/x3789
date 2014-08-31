
#ifndef __Object3D__
#define __Object3D__

class VertexStorage;
class UniformStorage;

class DLL_INTERFACE Object3D
{
protected:
	GLuint shader;
	GLenum primitive_type;
	GLuint vertex_buffer;
	GLuint color_buffer;
	GLuint uv_buffer;

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

	inline bool checkShader(GLuint shader)
	{
		return this->shader == ShaderInterface::getInstance()->getShader(shader);
	}

	inline void setShader(GLuint shader_id)
	{
		this->shader = ShaderInterface::getInstance()->getShader(shader_id);
		mvp_id = glGetUniformLocation(this->shader, "MVP");
		object_position_id = glGetUniformLocation(this->shader, "object_position");
	}

	inline GLuint getShader()
	{
		return this->shader;
	}
	
	inline void setPrimitiveType(GLenum primitive_type)
	{
		this->primitive_type = primitive_type;
	}

	inline GLenum getPrimitiveType()
	{
		return this->primitive_type;
	}

	inline void setPosition(float x, float y, float z)
	{
		this->position = glm::vec3(x, y, z);
	}
};

#endif
