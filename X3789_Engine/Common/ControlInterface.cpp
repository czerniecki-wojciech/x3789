
#include "stdafx.h"
#include <X3789_Engine_Common.h>
#include <X3789_Engine\WindowInterface.h>

#include "ControlInterface.h"

ControlInterface* ControlInterface::instance = NULL;
float ControlInterface::speed = 3.0f;
float ControlInterface::mouse_speed = 0.005f;


void ControlInterface::computeMVP()
{
	static double last_time = glfwGetTime();

	current_time = glfwGetTime();
	delta_time = float(current_time - last_time);
	
	if (delta_time > 0.15)
	{
		last_time = current_time;
		return;
	}

	this->performMouseAction();
	this->performKeyboardAction();

	//float FoV = initialFoV;// - 5 * glfwGetMouseWheel(); // Now GLFW 3 requires setting up a callback for this. It's a bit too complicated for this beginner's tutorial, so it's disabled instead.

	ProjectionMatrix = glm::perspective(initialFoV, 4.0f / 3.0f, 0.1f, 100.0f);
	ViewMatrix = glm::lookAt(
		position,           // Camera is here
		position + direction, // and looks here : at the same position, plus "direction"
		up                  // Head is up (set to 0,-1,0 to look upside-down)
		);

	ModelMatrix = glm::mat4(1.0f);

	MVP = ProjectionMatrix * ViewMatrix * ModelMatrix;

	last_time = current_time;

	//printDebugInfo();
}


void ControlInterface::performMouseAction()
{
	WindowInterface::GetCursorPos(this->x_pos, this->y_pos);
	WindowInterface::SetCursorPosCenter();

	horizontal_angle += mouse_speed * float(SCREEN_WIDTH * 0.5f - x_pos);
	vertical_angle += mouse_speed * float(SCREEN_HEIGHT * 0.5f - y_pos);

	if (horizontal_angle > 3.141592f)
		horizontal_angle = -3.141592f;
	else if (horizontal_angle < -3.141592f)
		horizontal_angle = 3.141592f;

	if (vertical_angle > 3.141592f * 0.5f)
		vertical_angle = 3.141592f * 0.5f;
	else if (vertical_angle < -3.141592f * 0.5f)
		vertical_angle = -3.141592f * 0.5f;

	direction = glm::vec3(
		cos(vertical_angle) * sin(horizontal_angle),
		sin(vertical_angle),
		cos(vertical_angle) * cos(horizontal_angle)
		);

	right = glm::vec3(
		sin(horizontal_angle - 3.14f * 0.5f),
		0,
		cos(horizontal_angle - 3.14f * 0.5f)
		);

	up = glm::cross(right, direction);
}


void ControlInterface::performKeyboardAction()
{
	if (WindowInterface::GetKey(GLFW_KEY_UP) || WindowInterface::GetKey(GLFW_KEY_W))
		position += direction * delta_time * speed;
	if (WindowInterface::GetKey(GLFW_KEY_DOWN) || WindowInterface::GetKey(GLFW_KEY_S))
		position -= direction * delta_time * speed;
	if (WindowInterface::GetKey(GLFW_KEY_RIGHT) || WindowInterface::GetKey(GLFW_KEY_D))
		position += right * delta_time * speed;
	if (WindowInterface::GetKey(GLFW_KEY_LEFT) || WindowInterface::GetKey(GLFW_KEY_A))
		position -= right * delta_time * speed;
	if (WindowInterface::GetKey(GLFW_KEY_SPACE))
		position += glm::vec3(0, 1, 0) * delta_time * speed;
	if (WindowInterface::GetKey(GLFW_KEY_LEFT_CONTROL))
		position -= glm::vec3(0, 1, 0) * delta_time * speed;
}
