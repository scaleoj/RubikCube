#include "MiniCube.h"
#pragma once
class Model
{

public:
	void Initialize();
	void RotateX(bool direction, int disc);
	void RotateY(bool direction, int disc);
	void RotateZ(bool direction, int disc);
	MiniCube GetCube(int x, int y, int z);
	void PrintModel();
private:
	MiniCube m_model[3][3][3];
};

