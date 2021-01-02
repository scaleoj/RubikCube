#include "CompoundCube.h"

#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <iostream>

void CompoundCube::Initialize(GLFWwindow* window)
{
	m_input.SetWindow(window);
	isBusy = false;
	m_input.ObserveKey(GLFW_KEY_SPACE);
	m_input.ObserveKey(GLFW_KEY_RIGHT);
	m_input.ObserveKey(GLFW_KEY_LEFT);
	m_input.ObserveKey(GLFW_KEY_UP);
	disc = 0;
	m_input.ObserveKey(GLFW_KEY_1);
	m_input.ObserveKey(GLFW_KEY_2);
	m_input.ObserveKey(GLFW_KEY_3);
	m_input.ObserveKey(GLFW_KEY_Q);
	boolQ = false;
	m_input.ObserveKey(GLFW_KEY_E);
	boolE = false;
	m_input.ObserveKey(GLFW_KEY_W);
	boolW = false;
	m_input.ObserveKey(GLFW_KEY_S);
	boolS = false;
	m_input.ObserveKey(GLFW_KEY_A);
	boolA = false;
	m_input.ObserveKey(GLFW_KEY_D);
	boolD = false;
	m_input.ObserveKey(GLFW_KEY_DOWN);

	m_model.Initialize();
	//TestCube();
	m_model.PrintModel();

	m_cubieRenderer.Initialize(m_model);
}

void CompoundCube::Render(float aspectRatio)
{
	glm::mat4 globalTransformation = glm::perspective(glm::radians(45.0f), aspectRatio, 0.1f, 100.0f) *
		glm::lookAt(glm::vec3(0.0f, 0.0f, -9.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f)) *
		glm::mat4_cast(m_orientationQuaternion);


	float offset = m_cubieRenderer.GetCubieExtension() + 0.1f;
	for (int i = 0; i < 3; ++i)
	{
		for (int j = 0; j < 3; ++j)
		{
			for (int k = 0; k < 3; ++k)
			{

				glm::mat4 compound = glm::translate(globalTransformation, glm::vec3((i - 1) * offset, (j - 1) * offset, (k - 1)*offset));



				if ((boolW || boolS) && i == disc)
				{
					float dir = 0.0f;
					if (boolW)
					{
						dir = 90.0f;

						
					}
					else
					{
						dir = -90.0f;


						
					}
					//compound = glm::rotate(compound, glm::radians(dir), glm::vec3(1.0f, 0.0f, 0.0f));
					
				}

				if ((boolA || boolD)  && j == disc)
				{
					float dir = 0.0f;
					if (boolA)
					{
						dir = -90.0f;


					}
					else
					{
						dir = 90.0f;

					}
					//compound = glm::rotate(compound, glm::radians(dir), glm::vec3(0.0f, 1.0f, 0.0f));
				}

				if ((boolQ || boolE) && k == disc)
				{
					float dir = 0.0f;
					if (boolQ)
					{
						dir = -90.0f;

					}
					else
					{
						dir = 90.0f;

					}
					//compound = glm::rotate(compound, glm::radians(dir), glm::vec3(0.0f, 0.0f, 1.0f));
				}

				//compound = glm::rotate(compound, glm::radians(0.0f)* (i % 2), glm::vec3(1.0f, 0.0f, 0.0f));
				//compound = glm::rotate(compound, glm::radians(0.0f)* (j % 2), glm::vec3(0.0f, 1.0f, 0.0f));
				//compound = glm::rotate(compound, glm::radians(0.0f)* (k % 2), glm::vec3(0.0f, 0.0f, 1.0f));
				m_cubieRenderer.Render(compound, i, j, k);
				
			}
		}
	}
	boolA = false;
	boolD = false;
	boolQ = false;
	boolE = false;
	boolW = false;
	boolS = false;
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


	if (m_input.IsKeyDown(GLFW_KEY_A)&&!isBusy)
	{
		boolA = true;
		isBusy = true;
		m_model.RotateY(false, disc);
		m_model.PrintModel();
	}
	if (m_input.WasKeyReleased(GLFW_KEY_A))
	{
		isBusy = false;
	}

	if (m_input.IsKeyDown(GLFW_KEY_D) && !isBusy)
	{
		boolD = true;
		isBusy = true;
		m_model.RotateY(true, disc);
		m_model.PrintModel();
	}
	if (m_input.WasKeyReleased(GLFW_KEY_D))
	{
		isBusy = false;
	}



	if (m_input.IsKeyDown(GLFW_KEY_Q) && !isBusy)
	{
		boolQ = true;
		isBusy = true;
		m_model.RotateZ(true, disc);
		m_model.PrintModel();
	}
	if (m_input.WasKeyReleased(GLFW_KEY_Q))
	{
		isBusy = false;
	}

	if (m_input.IsKeyDown(GLFW_KEY_E) && !isBusy)
	{
		boolE = true;
		isBusy = true;
		m_model.RotateZ(false, disc);
		m_model.PrintModel();
	}
	if (m_input.WasKeyReleased(GLFW_KEY_E))
	{
		isBusy = false;
	}



	if (m_input.IsKeyDown(GLFW_KEY_W) && !isBusy)
	{
		boolW = true;
		isBusy = true;
		m_model.RotateX(false, disc);
		m_model.PrintModel();
	}
	if (m_input.WasKeyReleased(GLFW_KEY_W))
	{
		isBusy = false;
	}

	if (m_input.IsKeyDown(GLFW_KEY_S) && !isBusy)
	{
		boolS = true;
		isBusy = true;
		m_model.RotateX(true, disc);
		m_model.PrintModel();
	}
	if (m_input.WasKeyReleased(GLFW_KEY_S))
	{
		isBusy = false;
	}



	if (m_input.IsKeyDown(GLFW_KEY_1))
	{
		disc = 2;
	}
	if (m_input.IsKeyDown(GLFW_KEY_2))
	{
		disc = 1;
	}
	if (m_input.IsKeyDown(GLFW_KEY_3))
	{
		disc = 0;
	}


	glm::quat velocityQuaternion = glm::quat(0.0f, glm::vec3(xVel, yVel, 0.0f));

	m_orientationQuaternion += 0.5f * ((float)deltaTime) *velocityQuaternion * m_orientationQuaternion;
	m_orientationQuaternion = normalize(m_orientationQuaternion);

}

void CompoundCube::TestCube()
{

	m_model.PrintModel();
	m_model.RotateX(true, 0);
	m_model.PrintModel();
	m_model.RotateY(true, 0);
	m_model.PrintModel();

}
