#include "TestGlm.h"
#include <glm/glm.hpp>
#include <glm/ext.hpp>

void TestGlm::Initialize()
{
	glm::mat4 testMat = glm::mat4(1.0f);
	testMat = glm::translate(testMat, glm::vec3(1.0f, -1.0f, 1.0f));
	testMat = glm::rotate(testMat, glm::radians(90.0f), glm::vec3(1.0f, 0.0f, 0.0f));
	testMat = testMat;
}

void TestGlm::Update(double deltaTime) 
{

}
