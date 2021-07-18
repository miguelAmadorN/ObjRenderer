#ifndef LINE_H
#define LINE_H
#include "Coor.h"

class Line
{
private:
	int p1;
	int p2;
public:
	Line();
	Line(int p1, int p2);
	void init(int p1, int p2);
	int getP1();
	int getP2();
	void setP1(int point);
	void setP2(int point);
	~Line();

};


#endif