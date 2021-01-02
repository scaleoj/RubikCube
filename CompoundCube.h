#pragma once
#include "GameInterface.h"
#include "CubieRenderer.h"
#include "Model/Model.h"
#include "Model/MiniCube.h"
#include "InputSystem.h"
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
	bool boolA;
	bool boolD;
	bool boolQ;
	bool boolE;
	bool boolW;
	bool boolS;
	bool isBusy;
	int disc;

	
};

