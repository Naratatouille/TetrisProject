#include "Bloc.h"

Bloc::Bloc() :
	width(30), height(30), color(1), index(1), xposition(1), yposition(1)
{
	std::cout << "constucteur bloc" << std::endl;
}

Bloc::Bloc(int _X, int _Y, int _col) :
	width(30), height(30), color(_col), index(1), xposition(_X), yposition(_Y)
{
	std::cout << "constucteur value" << std::endl;
}

Bloc::Bloc(const Bloc& _bloc) :
	width(_bloc.width), height(_bloc.height), color(_bloc.color), index(_bloc.index), xposition(_bloc.xposition), yposition(_bloc.yposition)
{
	std::cout << "constucteur recopie" << std::endl;
}

Bloc::~Bloc()
{
	std::cout << "destructeur" << std::endl;
}


int Bloc::getWidth()
{
	return width;
}

int Bloc::getHeight()
{
	return height;
}

int Bloc::getColor()
{
	return color;
}

int Bloc::getXposition()
{
	return xposition;
}

int Bloc::getYposition()
{
	return yposition;
}

void Bloc::BlockDisp() const
{
	const int SCREEN_WIDTH = 640;
	const int SCREEN_HEIGHT = 480;
	SDL_Window* gWindow = NULL;
	SDL_Surface* gScreenSurface = NULL;
	SDL_Surface* gGreenCube = NULL;
	SDL_Surface* gBlueCube = NULL;
	SDL_Rect posGreen;
	posGreen.x = 50;
	posGreen.y = 50;
	//Create window
	gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	//Get window surface
	gScreenSurface = SDL_GetWindowSurface(gWindow);
	//Load splash image
	gGreenCube = SDL_LoadBMP("Carree_Vert.bmp");
	gBlueCube = SDL_LoadBMP("Carree_Bleu.bmp");
	//Apply the image
	SDL_BlitSurface(gGreenCube, NULL, gScreenSurface, &posGreen);
	SDL_BlitSurface(gBlueCube, NULL, gScreenSurface, NULL);
	//Update the surface
	SDL_UpdateWindowSurface(gWindow);
	//Wait five seconds
	SDL_Delay(5000);
}

void Test_Bloc()
{
	Bloc bloc1;
	Bloc bloc2(15, 25, 4);
	Bloc bloc3(bloc2);
	std::cout << "Couleur bloc 1 : " << bloc1.getColor() << std::endl;
	std::cout << "Largeur bloc 1 : " << bloc1.getWidth() << std::endl;
	std::cout << "Hauteur bloc 1 : " << bloc1.getHeight() << std::endl;
	std::cout << "Hauteur bloc 2 : " << bloc2.getYposition() << std::endl;
	std::cout << "Hauteur bloc 3 : " << bloc3.getXposition() << std::endl;
	bloc1.BlockDisp();
}
