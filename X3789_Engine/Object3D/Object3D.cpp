
#include "stdafx.h"
#include <X3789_Engine\WindowInterface.h>
#include "VertexStorage.h"
#include "UniformStorage.h"
#include "Object3D.h"


const float Object3D::speed = 3.0f;
const float Object3D::mouse_speed = 0.005f;
const float Object3D::initial_FoV = 45.0f;

Object3D::Object3D()
	: program_ID(0)
	, primitive_type(GL_TRIANGLES)
	, vertices(NULL)
	, uniforms(NULL)
	, x(0)
	, y(0)
	, z(-5)
	, horizontal_angle(0.0f)
	, vertical_angle(0.0f)
{
	Move(0); //TMP
}


Object3D::~Object3D()
{}

void Object3D::loadVertexToGPU()
{
	if (!vertices)
		return;

	glGenBuffers(1, &this->vertex_buffer);
	glBindBuffer(GL_ARRAY_BUFFER, this->vertex_buffer);

	glBufferData(GL_ARRAY_BUFFER, this->vertices->getVerticesNum(), this->vertices->getData(), GL_STATIC_DRAW);

	glGenVertexArrays(1, &this->vertex_array);
	glBindVertexArray(this->vertex_array);

	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, this->vertex_buffer);
	glVertexAttribPointer(
		0,                  // attribute 0. No particular reason for 0, but must match the layout in the shader.
		this->vertices->getVerticesNum(),	// size
		GL_FLOAT,							// type
		GL_FALSE,							// normalized?
		0,									// stride
		(void*)0							// array buffer offset
		);

	glDrawArrays(GL_TRIANGLES, 0, this->vertices->getVerticesNum() / 3);

	glDisableVertexAttribArray(0);
}

inline void Object3D::loadUniformsToGPU()
{
	if (uniforms)
		this->uniforms->loadToGPU(this->program_ID);
}

inline void Object3D::draw()
{
	if (this->program_ID)
		glUseProgram(this->program_ID);

	calculateMVPMatrix();

	loadUniformsToGPU();

	loadVertexToGPU();

}

void Object3D::Move(GLenum key)
{
	static double lastTime = glfwGetTime();

	position = glm::vec3(x, y, z);

	current_time = glfwGetTime();
	delta_time = float(current_time - lastTime);
	// Direction : Spherical coordinates to Cartesian coordinates conversion
	direction = glm::vec3(
		cos(vertical_angle) * sin(horizontal_angle),
		sin(vertical_angle),
		cos(vertical_angle) * cos(horizontal_angle)
		);

	// Right vector
	right = glm::vec3(
		sin(horizontal_angle - 3.14f * 0.5f),
		0,
		cos(horizontal_angle - 3.14f * 0.5f)
		);

	// Up vector
	up = glm::cross(right, direction);
	switch (key)
	{
	case GLFW_KEY_UP:
	case GLFW_KEY_W:
		position += direction * delta_time * speed;
		break;
	case GLFW_KEY_DOWN:
	case GLFW_KEY_S:
		position -= direction * delta_time * speed;
		break;
	case GLFW_KEY_RIGHT:
	case GLFW_KEY_D:
		position += right * delta_time * speed;
		break;
	case GLFW_KEY_LEFT:
	case GLFW_KEY_A:
		position -= right * delta_time * speed;
		break;
	}

	// For the next frame, the "last time" will be "now"
	lastTime = current_time;
}

void Object3D::calculateMVPMatrix()
{
	WindowInterface::GetCursorPos(this->x, this->y);
	WindowInterface::SetCursorPosCenter();

	horizontal_angle += mouse_speed * float(SCREEN_WIDTH * 0.5f - x);
	vertical_angle += mouse_speed * float(SCREEN_HEIGHT * 0.5f - y);

	if (horizontal_angle > 3.141592f)
		horizontal_angle = -3.141592f;
	else if (horizontal_angle < -3.141592f)
		horizontal_angle = 3.141592f;

	if (vertical_angle > 3.131592f * 0.5f)
		vertical_angle = 3.131592f * 0.5f;
	else if (vertical_angle < -3.131592f * 0.5f)
		vertical_angle = -3.131592f * 0.5f;

	

	// Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
	ProjectionMatrix = glm::perspective(initial_FoV, 4.0f / 3.0f, 0.1f, 100.0f);
	// Camera matrix
	ViewMatrix = glm::lookAt(
		position,           // Camera is here
		position + direction, // and looks here : at the same position, plus "direction"
		up                  // Head is up (set to 0,-1,0 to look upside-down)
		);

}