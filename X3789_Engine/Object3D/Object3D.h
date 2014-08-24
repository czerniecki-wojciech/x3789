
#pragma once

class Object3D
{
protected:
	GLuint program_ID;
	GLenum primitive_type;
	VertexStorage* vertices;

	virtual void loadVertexToGPU() = 0;
	virtual void loadUniformsToGPU() = 0;

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
