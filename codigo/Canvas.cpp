#include "Canvas.h"
#include "Line.h"
#include "Face.h"
#include <iostream>
#include <unistd.h>
#include <cmath>
#include <string.h>
#include <stdio.h>
using namespace std;
#define c M_PI / 180

Canvas::Canvas(char *_file){
	file = _file;
	gfx_open(WIDTH, HIGH, file);
	gfx_color(CR,CG,CB);
}

void Canvas::render()
{
	vector<Coor> v;
	vector<Line> l;
	vector<Face> f, f1, f2, f3 ;
	vector<Coor> _v;

	int vertex = 0, lines = 1, faces = 1, _f1 = 0, _f2 = 0, _f3 = 0;

	FILE *fp = fopen(file, "r");
	char ch, chn, chs, key; 
	
	if (fp == NULL){
	    perror("Error while opening the file.\n");
	    exit(EXIT_FAILURE);
	}

	double x, y, z;
	int p1, p2, v1,v2,v3, t1,t2,t3, n1,n2,n3;

	while((chn = fgetc(fp)) != EOF){
		char aux[] = "";
	   	char caux;
	   	strncat(aux, &chn, 1);
	   	while((caux = fgetc(fp)) != '\n'){
	   		strncat(aux, &caux, 1);
	   	}
	   //	

	   	if(aux[1] == ' '){
	   		if(aux[0] == 'v'){
	   			sscanf(aux, "v %lf %lf %lf", &x, &y, &z);
	   			Coor coor(x,y,z);
	   			v.push_back(coor);
	   		}else if(aux[0] == 'f'){
	   			//printf("%s\n", aux);
	   			int i = 0, type = 0;
	   			while(aux[i++] != '/');
	   			if(aux[i] == '/') type = 2;
	   			else{
	   				type = 1;
	   				while(aux[++i] != '/' && aux[i] != ' ');
	   				if(aux[i] == '/') type = 3;
	   			}
				//printf("T: %d\n", type);
	   			switch(type){
	   				case 1:
	   				{
	   					sscanf(aux, "f %d/%d %d/%d %d/%d", &v1, &t1, &v2, &t2, &v3, &t3); //vertex/texture
	   					Face f_1(v1,v2,v3);
	   					f1.push_back(f_1);
	   					f.push_back(f_1);
	   					break;
	   				}
	   				case 2:
	   				{
	   					sscanf(aux, "f %d//%d %d//%d %d//%d", &v1, &n1, &v2, &n2, &v3, &n3);// vertex//normal
	   					Face f_2(v1,v2,v3);
	   					f2.push_back(f_2);
	   					f.push_back(f_2);
	   					break;
	   				}
	   				case 3:
	   				{
	   						sscanf(aux, "f %d/%d/%d %d/%d/%d %d/%d/%d",&v1, &n1, &t1, &v2, &n2, &t2, &v3, &n3, &t3 );//vertex/normal/texture
	   						Face f_3(v1,v2,v3);
		   					f3.push_back(f_3);
		   					f.push_back(f_3);
		   			
	   					break;
	   				}
	   			}

	   		}

	   	}
	}

/*
   	while((chn = fgetc(fp)) != EOF){
	   		if(chn == 'v' && (chs = fgetc(fp)) == ' '){
	   			fscanf(fp, "%lf %lf %lf", &x, &y, &z);
	   			Coor coor(x,y,z);
	   			v.push_back(coor);
	   		}
	   		else if(chn == 'l'  && (chs = fgetc(fp)) == ' '){
	   			fscanf(fp, "%d %d", &p1, &p2);
	   			Line line(p1, p2);
	   			l.push_back(line);
	   		}
	   		else if(chn == 'f' && (chs = fgetc(fp)) == ' '){
	   			char aux[] = "";
	   			char caux, au[1];
	   			while((caux = fgetc(fp)) != '/'){
	   				au[0] = caux;
	   				strncat(aux, au, 1);
	   			}
   				au[0] = caux;
   				strncat(aux, au, 1);
	   			if((caux = fgetc(fp)) == '/'){
	   				type = 2;
	   				au[0] = caux;
   					strncat(aux, au, 1);
   					while((caux = fgetc(fp)) != '\n'){
	   					au[0] = caux;
	   					strncat(aux, au, 1);
	   				}
	   			}
	   			else{
	   				while(caux != '/' && caux != ' '){
	   					caux = fgetc(fp);
	   					au[0] = caux;
	   					strncat(aux, au, 1);
	   				}
	   				if(caux == ' ') type = 1;
	   				else if(caux == '/') type = 3;
	   			}
	   			
	   			
	   		}
   	}*/

   fclose(fp);

	int xGrades = 0;
	int yGrades = 0;
	int zGrades = 0;
	int xTranslation = 0;
	int yTranslation = 0;
	double _scale = 1.0;
	_v = v;
	const char ESC = 27;
	unsigned char operate;
	while(key != ESC)
	{
		xGrades %= 360;
		yGrades %= 360;
		if(xGrades < 0) xGrades = 360;

		
		gfx_clear();
		//draw
		if(vertex)
			renderVertex(&_v, xTranslation, yTranslation);
		if(lines)
			renderLines(&l, &_v, xTranslation, yTranslation);
		if(faces)
			renderFaces(&f, &_v, xTranslation, yTranslation);
		if(_f1)
			renderFaces(&f1, &_v, xTranslation, yTranslation);
		if(_f2)
			renderFaces(&f2, &_v, xTranslation, yTranslation);
		if(_f3)
			renderFaces(&f3, &_v, xTranslation, yTranslation);
		
		gfx_flush();
		usleep(10);	
		_v = v;
		
		key = gfx_wait();
		printf("%c\n", key );
		
		switch(key){
			case '1':
				_f1 = !_f1;
				break;
			case '2':
				_f2 = !_f2;
				break;
			case '3':
				_f3 = !_f3;
				break;
			case 'v':
				vertex = !vertex;
				break;
			case 'l':
				lines = !lines;
				break;
			case 'f':
				faces = !faces;
				break;
			case 'R':
				--yGrades;
				break;
			case 'Q':
				--zGrades;
				break;
			case 'T':
				++yGrades;
				break;
			case 'S':
				 ++zGrades; 
				break;
			case '6':
				++xGrades;
				break;
			case '7':
				 --xGrades; 
				break;
			case 'w':
				yTranslation -= 5;
				break;
			case 'a':
				xTranslation -= 5;
				break;
			case 's':
				yTranslation += 5;
				break;
			case 'd':
				xTranslation += 5;
				break;
			case 4:
				if(_scale > 2){
					_scale -= 1;
				}
				else if(_scale > 0.2){
					_scale -= 0.1;
				}
				break;
			case 5:
				_scale += 1;
				break;
		}

		scale(&_v, _scale );
		rotateX(&_v, xGrades );
		rotateY(&_v, yGrades );
		rotateZ(&_v, zGrades );
	}

	printf("\n--Finish--");
}

void Canvas::rotateY(std::vector<Coor> *v, int grades){
	double sin1 = sin(grades * c);
	double cos1 = cos(grades * c);
	int y, z;
	for (auto it = v->begin(); it != v->end(); ++it){
		y = it->getY();
		z = it->getZ();
		it->setY(y * cos1 - z * sin1);
		it->setZ(y * sin1 + z * cos1);
	}
}

void Canvas::rotateZ(std::vector<Coor> *v, int grades){
	double sin1 = sin(grades * c);
	double cos1 = cos(grades * c);
	int x, z;
	for (auto it = v->begin(); it != v->end(); ++it){
		x = it->getX();
		z = it->getZ();
		it->setX(x * cos1 + z * sin1);
		it->setZ(z * cos1 - x * sin1);
	}
}

void Canvas::rotateX(std::vector<Coor> *v, int grades){
	double sin1 = sin(grades * c);
	double cos1 = cos(grades * c);
	int x, y;
	for (auto it = v->begin(); it != v->end(); ++it){
		x = it->getX();
		y = it->getY();
		it->setX(x * cos1 - y * sin1);
		it->setY(x * sin1 + y * cos1);
	}
}

void Canvas::scale(std::vector<Coor> *v, double scale){
	for(auto it = v->begin(); it < v->end(); ++it){
		it->setX(it->getX() * scale);
		it->setY(it->getY() * scale);
		it->setZ(it->getZ() * scale);
	}
}

void Canvas::renderVertex(vector<Coor> *v, int xTranslation, int yTranslation){
	const int X_TRANSLATION = HALF_WIDTH + xTranslation;
	const int Y_TRANSLATION = HALF_HIGH + yTranslation;
	for(auto it = v->begin(); it < v->end(); ++it){
		gfx_line(it->getX() + X_TRANSLATION, 
					(Y_TRANSLATION - it->getY()), 
					it->getX() + X_TRANSLATION, 
					(Y_TRANSLATION - it->getY()));
	}
}

void Canvas::renderLines(vector<Line> *l, vector<Coor> *v, int xTranslation,
 int yTranslation)
{
	auto itv = v->begin();
	const int X_TRANSLATION = HALF_WIDTH + xTranslation;
	const int Y_TRANSLATION = HALF_HIGH + yTranslation;
	for(auto it = l->begin(); it < l->end(); ++it){
		Coor p1 = itv[it->getP1() - 1]; 
		Coor p2 = itv[it->getP2() - 1]; 
		gfx_line(p1.getX() + X_TRANSLATION, 
					(Y_TRANSLATION - p1.getY()), 
					p1.getX() + X_TRANSLATION, 
					(Y_TRANSLATION - p2.getY()));
	
	}
}

void Canvas::renderFaces(vector<Face> *f, vector<Coor> *v, int xTranslation, 
	int yTranslation)
{
	auto itv = v->begin();
	const int X_TRANSLATION = HALF_WIDTH + xTranslation;
	const int Y_TRANSLATION = HALF_HIGH + yTranslation;
	for(auto it = f->begin(); it < f->end(); ++it){

		Coor p1 = itv[it->getV1() - 1];
		Coor p2 = itv[it->getV2() - 1]; 
		Coor p3 = itv[it->getV3() - 1];

		
		gfx_line(p1.getX() + X_TRANSLATION, 
					(Y_TRANSLATION - p1.getY()), 
					p2.getX() + X_TRANSLATION, 
					(Y_TRANSLATION - p2.getY()));

		gfx_line(p2.getX() + X_TRANSLATION, 
					(Y_TRANSLATION - p2.getY()), 
					p3.getX() + X_TRANSLATION, 
					(Y_TRANSLATION - p3.getY()));
					
	
	}
}
