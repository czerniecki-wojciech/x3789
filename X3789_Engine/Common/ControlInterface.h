
#pragma once

class DLL_INTERFACE ControlInterface
{
private:
	const float initialFoV = 45.0f;
	static ControlInterface* instance;

	static float speed;
	static float mouse_speed;

	glm::mat4 ViewMatrix;
	glm::mat4 ProjectionMatrix;
	glm::mat4 ModelMatrix;
	glm::mat4 MVP;

	glm::vec3 position = glm::vec3(0, 0, -5);
	glm::vec3 direction;
	glm::vec3 right;
	glm::vec3 up;

	float horizontal_angle;
	float vertical_angle;
	float x_pos, y_pos;
	
	float delta_time;
	double current_time;

	ControlInterface()
		: horizontal_angle(0.0f)
		, vertical_angle(0.0f)
	{}

	void performMouseAction();
	void performKeyboardAction();

	inline void printDebugInfo()
	{
		printf("(%f, %f, %f) \t h: %f v: %f\n", position.x, position.y, position.z, horizontal_angle, vertical_angle);
		//horizontal_angle += 0.01f;
		//vertical_angle += 0.05f;
	}

public:
	void computeMVP();

	static ControlInterface* getInstance()
	{
		if (!instance)
			instance = new ControlInterface();
		return instance;
	}

	static float* getMVPData()
	{
		return glm::value_ptr(instance->MVP);
	}
};
