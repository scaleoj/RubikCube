#include "CompoundCube.h"
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>

void CompoundCube::Initialize(GLFWwindow* window)
{
	m_input.SetWindow(window);

	m_viewProject = glm::mat4(1.0f);
	m_input.ObserveKey(GLFW_KEY_SPACE);
	m_input.ObserveKey(GLFW_KEY_RIGHT);
	m_input.ObserveKey(GLFW_KEY_LEFT);
	m_input.ObserveKey(GLFW_KEY_UP);
	m_input.ObserveKey(GLFW_KEY_DOWN);


	m_cubieRenderer.Initialize();
}

void CompoundCube::Render(float aspectRatio)
{
	glm::mat4 globalTransformation = glm::perspective(glm::radians(45.0f), aspectRatio, 0.1f, 100.0f) *
		glm::lookAt(glm::vec3(0.0f, 0.0f, -9.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)) *
		glm::mat4_cast(m_orientationQuaternion);

	m_viewProject = glm::perspective(glm::radians(45.0f), aspectRatio, 0.1f, 100.0f)*
		glm::lookAt(glm::vec3(0.0f, 0.0f, -9.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

	float offset = m_cubieRenderer.GetCubieExtension() + 0.1f;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			for (int k = 0; k < 3; ++k)
			{
				glm::mat4 compound = glm::translate(globalTransformation, glm::vec3((i - 1) * offset, (j - 1) * offset, (k - 1)*offset));
				compound = glm::rotate(compound, glm::radians(90.0f)* (i % 2), glm::vec3(1.0f, 0.0f, 0.0f));
				compound = glm::rotate(compound, glm::radians(90.0f)* (j % 2), glm::vec3(0.0f, 1.0f, 0.0f));
				compound = glm::rotate(compound, glm::radians(90.0f)* (k % 2), glm::vec3(0.0f, 0.0f, 1.0f));


				m_cubieRenderer.Render(compound);
			}
		}
	}
}

void CompoundCube::ClearResources()
{
	m_cubieRenderer.ClearResources();
}

void CompoundCube::Update(double deltaTime)
{
	m_input.Update();
	if (m_input.WasKeyPressed(GLFW_KEY_SPACE))
	{
		m_orientationQuaternion = glm::quat(1.0f, glm::vec3(0.0f, 0.0f, 0.0f));
	}

	float xVel = 0.0f;
	if (m_input.IsKeyDown(GLFW_KEY_UP))
	{
		xVel = glm::radians(90.0f);
	}
	if (m_input.IsKeyDown(GLFW_KEY_DOWN))
	{
		xVel = glm::radians(-90.0f);
	}

	float yVel = 0.0f;
	if (m_input.IsKeyDown(GLFW_KEY_RIGHT))
	{
		yVel = glm::radians(90.0f);
	}
	if (m_input.IsKeyDown(GLFW_KEY_LEFT))
	{
		yVel = glm::radians(-90.0f);
	}

	if (m_input.isLeftMouseButtonDown())
	{
		glm::vec3 position, direction;

		m_input.GetPickingRay(m_viewProject, position, direction);
	}


	glm::quat velocityQuaternion = glm::quat(0.0f, glm::vec3(xVel, yVel, 0.0f));

	m_orientationQuaternion += 0.5f * ((float)deltaTime) *velocityQuaternion * m_orientationQuaternion;
	m_orientationQuaternion = normalize(m_orientationQuaternion);



	
}
