#include <stdio.h>
#include <stdlib.h>
#include <tchar.h>
#include <Windows.h>

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>

#define GLM_FORCE_RADIANS

#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/transform.hpp>

#define SCREEN_WIDTH 1024
#define SCREEN_HEIGHT 768

#define TRILINEAR_FILTERING