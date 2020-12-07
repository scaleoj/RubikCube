#pragma once
#include "GameInterface.h"
#include "CubieRenderer.h"
#include "Model/Model.h"
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
	Model m_model;
	glm::quat m_orientationQuaternion;
	glm::mat4 m_viewProject;
	void TestCube();
	
};

