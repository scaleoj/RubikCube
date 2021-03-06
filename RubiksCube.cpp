//includes
#include "GameInterface.h"
#define GLEW_STATIC
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <iostream>


#include "Test/TestGlm.h"
#include "Test/TestTriangle.h"
#include "Test/TestCubie.h"
#include "Test/TestCompoundCube.h"
#include "Test/TestKey.h"
#include "Test/TestMouse.h"
#include "CompoundCube.h"


//Collection of Tesclasses
GameInterface gDummyTest;
TestGlm gTestGlm;
TestTriangle gTestTriangle;
TestCubie gTestCubie;
TestCompoundCube gTestCompoundCube;
TestKey gTestKey;
TestMouse gTestMouse;
CompoundCube gExam;

GameInterface* gUsedInterface;

GLFWwindow* IntializeSystem()
{
	//Setup OpenGL
	glfwInit();
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_OPENGL_DEBUG_CONTEXT, true);

	//Build Window
	GLFWwindow* window = glfwCreateWindow(1024, 768, "Rubiks Cube", nullptr, nullptr);
	
	//Set Action focus on window
	glfwMakeContextCurrent(window);


	glewExperimental = GL_TRUE;
	glewInit();

	gUsedInterface->Initialize(window);
	return window;
}

void RunCoreLoop(GLFWwindow* window)
{
	double lastTime = glfwGetTime();
	double timeDifference = 0.0f;
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();

		gUsedInterface->Update(timeDifference);
		int screenWidth, screenHeight;
		glfwGetFramebufferSize(window, &screenWidth, &screenHeight);
		float aspectRatio = (float)screenWidth / (float) screenHeight;
		glViewport(0,0, screenWidth, screenHeight);
		glEnable(GL_DEPTH_TEST);
		glDepthFunc(GL_LEQUAL);
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		gUsedInterface->Render(aspectRatio);
		glfwSwapBuffers(window);


		double currentTime = glfwGetTime();
		timeDifference = currentTime - lastTime;
		lastTime = currentTime;
	}
}

void ShutdownSystem()
{
	gUsedInterface->clearResources();
	glfwTerminate();
}

int main()
{
	//--Interfaceswaps--

	//gUsedInterface = &gDummyTest;
	//gUsedInterface = &gTestGlm;
	//gUsedInterface = &gTestTriangle;
	//gUsedInterface = &gTestCubie;
	//gUsedInterface = &gTestCompoundCube;
	//gUsedInterface = &gTestKey;
	//gUsedInterface = &gTestMouse;
	gUsedInterface = &gExam;

	//Fenster erzeugen
	GLFWwindow* window = IntializeSystem();
	RunCoreLoop(window);
	ShutdownSystem();
}
