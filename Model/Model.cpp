#include "Model.h"
#include <iostream>

void Model::Initialize()
{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				MiniCube cube;
				m_model[i][j][k] = cube;
			}
		}
	}
}

void Model::RotateX(bool direction, int disc)
{
	if (disc > 2)
	{
		std::cout << "Error: Wrong Disc Dimension on X-Rotation" << std::endl;
		return;
	}

	MiniCube tempO;
	MiniCube tempI;
	if (direction) //positive rotation on X-Axis direction from zero point
	{

		tempO = m_model[disc][0][0];
		tempI = m_model[disc][1][0];
		m_model[disc][0][0] = m_model[disc][0][2];
		m_model[disc][0][2] = m_model[disc][2][2];
		m_model[disc][2][2] = m_model[disc][2][0];
		m_model[disc][2][0] = tempO;
		m_model[disc][1][0] = m_model[disc][0][1];
		m_model[disc][0][1] = m_model[disc][1][2];
		m_model[disc][1][2] = m_model[disc][2][1];
		m_model[disc][2][1] = tempI;


	}
	else //negative rotation in on X-Axis from zero point
	{

		tempO = m_model[disc][0][0];
		tempI = m_model[disc][1][0];

		m_model[disc][0][0] = m_model[disc][2][0];
		m_model[disc][2][0] = m_model[disc][2][2];
		m_model[disc][2][2] = m_model[disc][0][2];
		m_model[disc][0][2] = tempO;
		m_model[disc][1][0] = m_model[disc][2][1];
		m_model[disc][2][1] = m_model[disc][1][2];
		m_model[disc][1][2] = m_model[disc][0][1];
		m_model[disc][0][1] = tempI;

	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			m_model[disc][i][j].rotateX(direction);
		}
	}

}

void Model::RotateY(bool direction, int disc)
{
	if (disc > 2)
	{
		std::cout << "Error: Wrong Disc Dimension on Y-Rotation" << std::endl;
		return;
	}

	MiniCube tempO;
	MiniCube tempI;
	if (direction) //positive rotation on Y-Axis from zero point
	{

		tempO = m_model[0][disc][0];
		tempI = m_model[1][disc][0];
		m_model[0][disc][0] = m_model[0][disc][2];
		m_model[0][disc][2] = m_model[2][disc][2];
		m_model[2][disc][2] = m_model[2][disc][0];
		m_model[2][disc][0] = tempO;
		m_model[1][disc][0] = m_model[0][disc][1];
		m_model[0][disc][1] = m_model[1][disc][2];
		m_model[1][disc][2] = m_model[2][disc][1];
		m_model[2][disc][1] = tempI;


	}
	else //negative rotation on Y Axis from zero point
	{
		tempO = m_model[0][disc][0];
		tempI = m_model[1][disc][0];
		m_model[0][disc][0] = m_model[2][disc][0];
		m_model[2][disc][0] = m_model[2][disc][2];
		m_model[2][disc][2] = m_model[0][disc][2];
		m_model[0][disc][2] = tempO;
		m_model[1][disc][0] = m_model[2][disc][1];
		m_model[2][disc][1] = m_model[1][disc][2];
		m_model[1][disc][2] = m_model[0][disc][1];
		m_model[0][disc][1] = tempI;

	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			m_model[i][disc][j].rotateY(direction);
		}
	}
	
}

void Model::RotateZ(bool direction, int disc)
{
	if (disc > 2)
	{
		std::cout << "Error: Wrong Disc Dimension on Z-Rotation" << std::endl;
		return;
	}

	MiniCube tempO;
	MiniCube tempI;
	if (direction) //positive rotation on Z-Axis from zero point
	{
		tempO = m_model[0][0][disc];
		tempI = m_model[1][0][disc];
		m_model[0][0][disc] = m_model[2][0][disc];
		m_model[2][0][disc] = m_model[2][2][disc];
		m_model[2][2][disc] = m_model[0][2][disc];
		m_model[0][2][disc] = tempO;
		m_model[1][0][disc] = m_model[2][1][disc];
		m_model[2][1][disc] = m_model[1][2][disc];
		m_model[1][2][disc] = m_model[0][1][disc];
		m_model[0][1][disc] = tempI;
	}
	else //negative rotation on Z-Axis from zero point
	{
		tempO = m_model[0][0][disc];
		tempI = m_model[1][0][disc];
		m_model[0][0][disc] = m_model[0][2][disc];
		m_model[0][2][disc] = m_model[2][2][disc];
		m_model[2][2][disc] = m_model[2][0][disc];
		m_model[2][0][disc] = tempO;
		m_model[1][0][disc] = m_model[0][1][disc];
		m_model[0][1][disc] = m_model[1][2][disc];
		m_model[1][2][disc] = m_model[2][1][disc];
		m_model[2][1][disc] = tempI;
	}

	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			m_model[i][j][disc].rotateZ(direction);
		}
	}

}

 MiniCube Model::GetCube(int x, int y, int z)
{
	return m_model[x][y][z];
}

void Model::PrintModel()
{
	std::cout << "[--][--][--][" + m_model[0][0][2].GetFacingString(0) + "][" + m_model[1][0][2].GetFacingString(0) + "][" + m_model[2][0][2].GetFacingString(0) + "][--][--][--]" << std::endl;
	std::cout << "[--][--][--][" + m_model[0][0][1].GetFacingString(0) + "][" + m_model[1][0][1].GetFacingString(0) + "][" + m_model[2][0][1].GetFacingString(0) + "][--][--][--]" << std::endl;
	std::cout << "[--][--][--][" + m_model[0][0][0].GetFacingString(0) + "][" + m_model[1][0][0].GetFacingString(0) + "][" + m_model[2][0][0].GetFacingString(0) + "][--][--][--]" << std::endl;

	std::cout << "[" + m_model[0][0][2].GetFacingString(1) + "][" + m_model[0][0][1].GetFacingString(1) + "][" + m_model[0][0][0].GetFacingString(1) + "][" + m_model[0][0][0].GetFacingString(2) + "][" + m_model[1][0][0].GetFacingString(2) + "][" + m_model[2][0][0].GetFacingString(2) + "][" + m_model[2][0][0].GetFacingString(3) + "][" + m_model[2][0][1].GetFacingString(3) + "][" + m_model[2][0][2].GetFacingString(3) + "]" << std::endl;
	std::cout << "[" + m_model[0][1][2].GetFacingString(1) + "][" + m_model[0][1][1].GetFacingString(1) + "][" + m_model[0][1][0].GetFacingString(1) + "][" + m_model[0][1][0].GetFacingString(2) + "][" + m_model[1][1][0].GetFacingString(2) + "][" + m_model[2][1][0].GetFacingString(2) + "][" + m_model[2][1][0].GetFacingString(3) + "][" + m_model[2][1][1].GetFacingString(3) + "][" + m_model[2][1][2].GetFacingString(3) + "]" << std::endl;
	std::cout << "[" + m_model[0][2][2].GetFacingString(1) + "][" + m_model[0][2][1].GetFacingString(1) + "][" + m_model[0][2][0].GetFacingString(1) + "][" + m_model[0][2][0].GetFacingString(2) + "][" + m_model[1][2][0].GetFacingString(2) + "][" + m_model[2][2][0].GetFacingString(2) + "][" + m_model[2][2][0].GetFacingString(3) + "][" + m_model[2][2][1].GetFacingString(3) + "][" + m_model[2][2][2].GetFacingString(3) + "]" << std::endl;

	std::cout << "[--][--][--][" + m_model[0][2][0].GetFacingString(4) + "][" + m_model[1][2][0].GetFacingString(4) + "][" + m_model[2][2][0].GetFacingString(4) + "][--][--][--]" << std::endl;
	std::cout << "[--][--][--][" + m_model[0][2][1].GetFacingString(4) + "][" + m_model[1][2][1].GetFacingString(4) + "][" + m_model[2][2][1].GetFacingString(4) + "][--][--][--]" << std::endl;
	std::cout << "[--][--][--][" + m_model[0][2][2].GetFacingString(4) + "][" + m_model[1][2][2].GetFacingString(4) + "][" + m_model[2][2][2].GetFacingString(4) + "][--][--][--]" << std::endl;

	std::cout << "[--][--][--][" + m_model[0][2][2].GetFacingString(5) + "][" + m_model[1][2][2].GetFacingString(5) + "][" + m_model[2][2][2].GetFacingString(5) + "][--][--][--]" << std::endl;
	std::cout << "[--][--][--][" + m_model[0][1][2].GetFacingString(5) + "][" + m_model[1][1][2].GetFacingString(5) + "][" + m_model[2][1][2].GetFacingString(5) + "][--][--][--]" << std::endl;
	std::cout << "[--][--][--][" + m_model[0][0][2].GetFacingString(5) + "][" + m_model[1][0][2].GetFacingString(5) + "][" + m_model[2][0][2].GetFacingString(5) + "][--][--][--]" << std::endl;

	
	std::cout << std::endl;
	std::cout << "------------------------------------" << std::endl;
	std::cout << std::endl;
}

