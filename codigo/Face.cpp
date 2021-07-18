#include <iostream>
#include "Face.h"
#include <cmath>

Face::Face()
{
}

Face::Face(int v1, int v2, int v3)
{
	this->v1=v1;
	this->v2=v2;
	this->v3=v3;
}


void Face::init(int v1, int v2, int v3)
{
	this->v1=v1;
	this->v2=v2;
	this->v3=v3;
}

int Face::getV1()
{
	return v1;
}

int Face::getV2()
{
	return v2;
}

int Face::getV3()
{
	return v3;
}

void Face::setV1(int vetex)
{
	v1=vetex;
}

void Face::setV2(int vetex)
{
	v2=vetex;
}

void Face::setV3(int vetex)
{
	v3=vetex;
}

Face::~Face()
{

}
