#ifndef FACE_H
#define FACE_H
#include "Coor.h"

class Face
{
private:
	int v1;
	int v2;
	int v3;
public:
	Face();
	Face(int v1, int v2, int v3);
	void init(int v1, int v2, int v3);
	int getV1();
	int getV2();
	int getV3();
	void setV1(int vertex);
	void setV2(int vertex);
	void setV3(int vertex);
	~Face();

};


#endif