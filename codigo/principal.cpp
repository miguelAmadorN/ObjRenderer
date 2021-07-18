#include "Canvas.h"
#include <iostream>
#include <unistd.h>
using namespace std;

int main(int argc, char* argv[])
{
	if(argc != 2){
		perror("Execute with obj file like argument");
		exit(EXIT_FAILURE);
	}

	Canvas *canvas = new Canvas(argv[1]);
	canvas->render();

	return 0;
}
