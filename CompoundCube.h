#pragma once
#include "GameInterface.h"
#include "CubieRenderer.h"
#include "InputSystem.h"
#include "Model/MiniCube.h"
#include <glm/ext/quaternion_float.hpp>

class CompoundCube : public GameInterface
{
public:
	virtual void Initialize(GLFWwindow* window);
	virtual void Render(float aspectRatio);
	virtual void ClearResources();
	virtual void Update(double deltaTime);

private:
	CubieRenderer m_cubieRenderer;
	InputSystem m_input;
	glm::quat m_orientationQuaternion;
	glm::mat4 m_viewProject;
	MiniCube m_model[3][3][3];
};

