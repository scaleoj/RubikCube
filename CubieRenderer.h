#pragma once
#include <glm/mat4x4.hpp>
#include <GL/glew.h>
#include <vector>
#include "Model/Model.h"

class CubieRenderer
{
public:
	void Initialize();
	void Initialize(Model m_model);
	void Render(const glm::mat4& transformationMatrix);
	void ClearResources();
	void BuildCubeInformation(int i, int j, int k);

	float GetCubieExtension() const { return 2.0f * m_offset; }

private:
	const float m_offset = 0.5f;

	void AddSidePosition(int sideType, int direction, std::vector<glm::vec3>& positionArray);
	void AddSideColor(int sideType, int direction, std::vector<glm::vec3>& colorArray, int i, int j, int k);
	void TranscribeToFloatArray(std::vector<glm::vec3>& vecArray, float* floatArray);
	
	Model model;
	float floatArray[6 * 6 * 3];
	std::vector<glm::vec3> positionField;
	std::vector<glm::vec3> colorField;
	GLuint m_arrayBufferObject;
	GLuint m_vertexBufferObject[2];
	GLuint m_shaderProgram;
	GLint m_transformLocation;

};

