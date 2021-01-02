#include "CubieRenderer.h"
#include "ShaderUtil.h"
#include <glm/gtc/type_ptr.hpp>
#include <iostream>


void CubieRenderer::Initialize()
{

}

void CubieRenderer::Initialize(Model m_model)
{

	m_shaderProgram = ShaderUtil::CreateShaderProgram("Shader/VColor.glsl", "Shader/FColor.glsl");
	m_transformLocation = glGetUniformLocation(m_shaderProgram, "transformation");

	model = m_model;

	//Build the cube information
	BuildCubeInformation(0, 0, 0);
}

void CubieRenderer::Render(const glm::mat4 & transformationMatrix, int i, int j, int k)
{
	BuildCubeInformation(i, j, k);
	glUseProgram(m_shaderProgram);
	glBindVertexArray(m_arrayBufferObject);

	glUniformMatrix4fv(m_transformLocation, 1, GL_FALSE, value_ptr(transformationMatrix));
	glDrawArrays(GL_TRIANGLES, 0, 3 * 6 * 6);

	glBindVertexArray(0);
	glUseProgram(0);
	
}

void CubieRenderer::ClearResources()
{
	glDeleteBuffers(2, m_vertexBufferObject);
	glDeleteVertexArrays(1, &m_arrayBufferObject);
	glDeleteProgram(m_shaderProgram);
	
}

void CubieRenderer::AddSidePosition(int sideType, int direction, std::vector<glm::vec3>& positionArray)
{
	
	glm::vec3 cornerPoints[2][2];
	
	int localXDim = (sideType + 1) % 3;
	int localYDim = (sideType + 2) % 3;

	for (int i = 0; i < 2; ++i)
	{
		for (int j = 0; j < 2; ++j)
		{
			glm::vec3 localPoint(direction * m_offset);
			localPoint[localXDim] = (2 * i - 1)* m_offset;
			localPoint[localYDim] = (2 * j - 1)* m_offset;
			cornerPoints[i][j] = localPoint;
		}
	}

	positionArray.push_back(cornerPoints[0][0]);
	positionArray.push_back(cornerPoints[1][0]);
	positionArray.push_back(cornerPoints[0][1]);
	positionArray.push_back(cornerPoints[1][0]);
	positionArray.push_back(cornerPoints[0][1]);
	positionArray.push_back(cornerPoints[1][1]);
	
}

void CubieRenderer::AddSideColor(int sideType, int direction, std::vector<glm::vec3>& colorArray, int i, int j, int k)
{

	glm::vec3 color = model.GetCube(i, j, k).GetFacingData(direction, sideType);

	for (int i = 0; i < 6; ++i)
	{
		colorArray.push_back(color);
	}
	
}

void CubieRenderer::TranscribeToFloatArray(std::vector<glm::vec3>& vecArray, float * floatArray)
{
	int writingCounter = 0;
	for (int i = 0; i < 36; ++i)
	{
		for (int coord = 0; coord < 3; ++coord)
		{
			floatArray[writingCounter++] = vecArray[i][coord];
		}
	}
	
}

void CubieRenderer::BuildCubeInformation(int i, int j, int k)
{
	positionField.clear();
	colorField.clear();
	for (int sideType = 0; sideType < 3; ++sideType)
	{
		for (int direction = -1; direction < 2; direction += 2)
		{
			AddSidePosition(sideType, direction, positionField);
			AddSideColor(sideType, direction, colorField, i, j, k);

		}
	}



	glGenVertexArrays(1, &m_arrayBufferObject);
	glGenBuffers(2, m_vertexBufferObject);

	glBindVertexArray(m_arrayBufferObject);

	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferObject[0]);
	TranscribeToFloatArray(positionField, floatArray);
	glBufferData(GL_ARRAY_BUFFER, sizeof(floatArray), floatArray, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(0);

	glBindBuffer(GL_ARRAY_BUFFER, m_vertexBufferObject[1]);
	TranscribeToFloatArray(colorField, floatArray);
	glBufferData(GL_ARRAY_BUFFER, sizeof(floatArray), floatArray, GL_STATIC_DRAW);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	glEnableVertexAttribArray(1);

	glBindBuffer(GL_ARRAY_BUFFER, 0);
	glBindVertexArray(0);

}
