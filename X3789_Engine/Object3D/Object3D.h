
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
	GLuint MatrixID;

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
	glm::mat4 ModelMatrix;

	glm::mat4 MVP;

	glm::vec3 position;

	glm::vec3 direction;
	glm::vec3 right;
	glm::vec3 up;

	static const float initial_FoV;
	static const float speed;
	static const float mouse_speed;

	float mouse_x, mouse_y;
public:
	Object3D();
	~Object3D();

	void draw();
	void endObjectDefinition();
	void calculateMVPMatrix();
	void Move(GLenum key);

	inline void setProgram(GLuint program_ID)
	{
		this->program_ID = program_ID;
		MatrixID = glGetUniformLocation(this->program_ID, "MVP");
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

	inline void printDebugInfo()
	{
		printf("(%f, %f, %f) \t h: %f v: %f\n", position.x, position.y, position.z, horizontal_angle, vertical_angle);
		//horizontal_angle += 0.01f;
		//vertical_angle += 0.05f;
	}
};

#endif
