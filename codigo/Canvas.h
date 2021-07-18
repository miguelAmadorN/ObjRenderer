#ifndef CANVAS_H
#define CANVAS_H
#include "gfx.h"
#include "Coor.h"
#include "Line.h"
#include "Face.h"
#include <vector>
using namespace std;
const int WIDTH   = 800;
const int HIGH    = 600;
const int HALF_WIDTH   = WIDTH/2;
const int HALF_HIGH    = HIGH/2;
const unsigned char CR = 0,CG = 200,CB = 100;
		
	class Canvas
	{
	private:
		char *file;
		void renderVertex(vector<Coor> *v, int xTranslation, int yTranslation);
		void renderLines(vector<Line> *l, vector<Coor> *v, int xTranslation, int yTranslation);
		void renderFaces(vector<Face> *f, vector<Coor> *v, int xTranslation, int yTranslation);
		void scale(vector<Coor> *v, double scale);
		void rotateX(vector<Coor> *v, int grades);
		void rotateY(vector<Coor> *v, int grades);
		void rotateZ(vector<Coor> *v, int grades);
	public:
		Canvas(char *file);
	 	void render();
	 	
	 	
	};

#endif