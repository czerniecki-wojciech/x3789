
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
	GLuint vertex_array;

	VertexStorage* vertices;
	UniformStorage* uniforms;

	void loadVertexToGPU();
	void loadUniformsToGPU();

	float x, y, z;
	float horizontal_angle;
	float vertical_angle;

	float current_time;
	float delta_time;

	glm::mat4 ViewMatrix;
	glm::mat4 ProjectionMatrix;
	glm::vec3 position;

	glm::vec3 direction;
	glm::vec3 right;
	glm::vec3 up;

	static const float initial_FoV;
	static const float speed;
	static const float mouse_speed;
public:
	Object3D();
	~Object3D();

	void draw();
	void calculateMVPMatrix();
	void Move(GLenum key);

	inline void setProgram(GLuint program_ID)
	{
		this->program_ID = program_ID;
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
};

#endif
