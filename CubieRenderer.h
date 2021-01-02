#pragma once
#include <glm/mat4x4.hpp>
#include <GL/glew.h>
#include <vector>
#include "Model/Model.h"

class CubieRenderer
{
public:
	void Initialize();
	void Render(const glm::mat4& transformationMatrix);
	void ClearResources();
	void ChangeSideColor(int i, int j, int k);

	float GetCubieExtension() const { return 2.0f * m_offset; }
	void RotateX(bool dir, int disc);
	void RotateY(bool dir, int disc);
	void RotateZ(bool dir, int disc);

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

