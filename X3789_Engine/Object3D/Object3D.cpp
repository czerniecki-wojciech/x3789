
#include "stdafx.h"
#include <X3789_Engine\WindowInterface.h>
#include "VertexStorage.h"
#include "Object3D.h"

const float Object3D::speed = 3.0f;
const float Object3D::mouse_speed = 0.005f;
const float Object3D::initial_FoV = 45.0f;

Object3D::Object3D()
	: program_ID(0)
	, primitive_type(GL_TRIANGLES)
	, vertices(0)
	, x(0)
	, y(0)
	, z(-5)
	, horizontal_angle(0.0f)
	, vertical_angle(0.0f)
{
	Move(0);
}


Object3D::~Object3D()
{}

inline void Object3D::draw()
{
	if (this->program_ID)
		glUseProgram(this->program_ID);

	calculateMVPMatrix();


}

void Object3D::Move(GLenum key)
{
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
}

void Object3D::calculateMVPMatrix()
{
	static double lastTime = glfwGetTime();

	position = glm::vec3(x, y, z);

	current_time = glfwGetTime();
	delta_time = float(current_time - lastTime);

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

	// For the next frame, the "last time" will be "now"
	lastTime = current_time;
}