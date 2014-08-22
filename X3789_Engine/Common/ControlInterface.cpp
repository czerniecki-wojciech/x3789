
#include "stdafx.h"
#include <X3789_Engine_Common.h>

#include "ControlInterface.h"

//extern GLFWwindow* window;

glm::mat4 ViewMatrix;
glm::mat4 ProjectionMatrix;

glm::mat4 getViewMatrix(){
	return ViewMatrix;
}
glm::mat4 getProjectionMatrix(){
	return ProjectionMatrix;
}

//extern GLFWwindow* window;

// Initial position and angles
glm::vec3 position = glm::vec3(0, 0, -5);
float horizontalAngle = 0.0f;
float verticalAngle = 0.0f;
float initialFoV = 45.0f;

float speed = 3.0f;
float mouseSpeed = 0.005f;

double xpos, ypos;
double currentTime;
float deltaTime;

void computeMatricesFromInputs(){
	/*
	// glfwGetTime is called only once, the first time this function is called
	static double lastTime = glfwGetTime();

	// Compute time difference between current and last frame
	currentTime = glfwGetTime();
	deltaTime = float(currentTime - lastTime);
	//GLFWwindow window;
	glfwGetCursorPos(window, &xpos, &ypos);

	// Reset mouse position for next frame
	glfwSetCursorPos(window, SCREEN_WIDTH * 0.5f, SCREEN_HEIGHT * 0.5f); // 1024/2 768/2

	// Compute new orientation
	horizontalAngle += mouseSpeed * float(SCREEN_WIDTH * 0.5f - xpos);
	verticalAngle += mouseSpeed * float(SCREEN_HEIGHT * 0.5f - ypos);

	if (horizontalAngle > 3.141592f)
		horizontalAngle = -3.141592f;
	else if (horizontalAngle < -3.141592f)
		horizontalAngle = 3.141592f;

	if (verticalAngle > 3.131592f * 0.5f)
		verticalAngle = 3.131592f * 0.5f;
	else if (verticalAngle < -3.131592f * 0.5f)
		verticalAngle = -3.131592f * 0.5f;

	// Direction : Spherical coordinates to Cartesian coordinates conversion
	glm::vec3 direction(
		cos(verticalAngle) * sin(horizontalAngle),
		sin(verticalAngle),
		cos(verticalAngle) * cos(horizontalAngle)
		);

	// Right vector
	glm::vec3 right = glm::vec3(
		sin(horizontalAngle - 3.14f * 0.5f),
		0,
		cos(horizontalAngle - 3.14f * 0.5f)
		);

	// Up vector
	glm::vec3 up = glm::cross(right, direction);

	// Move forward
	if (glfwGetKey(window, GLFW_KEY_UP) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_W) == GLFW_PRESS){
		position += direction * deltaTime * speed;
	}
	// Move backward
	if (glfwGetKey(window, GLFW_KEY_DOWN) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_S) == GLFW_PRESS){
		position -= direction * deltaTime * speed;
	}
	// Strafe right
	if (glfwGetKey(window, GLFW_KEY_RIGHT) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_D) == GLFW_PRESS){
		position += right * deltaTime * speed;
	}
	// Strafe left
	if (glfwGetKey(window, GLFW_KEY_LEFT) == GLFW_PRESS || glfwGetKey(window, GLFW_KEY_A) == GLFW_PRESS){
		position -= right * deltaTime * speed;
	}

	//float FoV = initialFoV;// - 5 * glfwGetMouseWheel(); // Now GLFW 3 requires setting up a callback for this. It's a bit too complicated for this beginner's tutorial, so it's disabled instead.

	// Projection matrix : 45° Field of View, 4:3 ratio, display range : 0.1 unit <-> 100 units
	ProjectionMatrix = glm::perspective(initialFoV, 4.0f / 3.0f, 0.1f, 100.0f);
	// Camera matrix
	ViewMatrix = glm::lookAt(
		position,           // Camera is here
		position + direction, // and looks here : at the same position, plus "direction"
		up                  // Head is up (set to 0,-1,0 to look upside-down)
		);

	// For the next frame, the "last time" will be "now"
	lastTime = currentTime;
	*/
}

