#include "TestGlm.h"

#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <GL/glew.h>
#include "../ShaderUtil.h"

void TestGlm::Initialize()
{
	//Every one of the following statements are independent
	//--------------------------------------------//
	/*

	glm::mat4 testMat = glm::mat4(1.0f);
	testMat = glm::translate(testMat, glm::vec3(1.0f, -1.0f, 1.0f));
	testMat = glm::rotate(testMat, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	testMat = testMat;

	//--------------------------------------------//

	glm::mat4 testMat2 = glm::mat4(1.0f);

	//Lookat(Position Kamera, Punkt zur Ansicht, Ausrichtung oben)
	testMat2 = glm::lookAt(glm::vec3(0.0f, 0.0f, 4.0f), glm::vec3(0.0f, 0.0f, 0.0f), glm::vec3(0.0f, 1.0f, 0.0f));

	//perspective(FOV, Aspect Ratio, )
	testMat2 = glm::perspective(glm::radians(60.0f), 1.0f, 0.1f, 100.0f) * testMat2;

	//------------Skalarprodukt------------------//

	glm::mat4 testMat3 = glm::mat4(1.0f);

	testMat3 = glm::rotate(testMat3, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	glm::vec3 firstColumn = testMat3[0];
	//dot = Skalarprodukt
	float innerProduct = glm::dot(firstColumn, firstColumn);
	innerProduct = innerProduct;

	//-------------Quaternion-------------------//
		*/
	GLuint test = ShaderUtil::CreateShaderProgram("VSimple.glsl", "FSimple.glsl");
	m_orientationQuaternion = glm::quat(1.0f, 0.0f, 0.0f, 0.0f);





}

int passed = 0;

void TestGlm::Update(double deltaTime) 
{
	//hack!!!

	if (passed == 0)
	{
		passed = 1;
		return;
	}

	//-------------Quaternion-------------------//
	glm::quat rotVelocity = glm::quat(0.0f, glm::radians(180.0f), 0.0f, 0.0f);
	glm::quat timeDerivative = 0.5f * rotVelocity * m_orientationQuaternion;

	m_orientationQuaternion += (float)(deltaTime)* timeDerivative;
	m_orientationQuaternion = normalize(m_orientationQuaternion);

	glm::mat4 rotationMatrix = glm::mat4_cast(m_orientationQuaternion);
}
