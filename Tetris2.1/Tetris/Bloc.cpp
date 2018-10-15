#include "Bloc.h"
#include "Constantes.h"

Bloc::Bloc() :
	width(30), height(30), color(1), index(1), xposition(1), yposition(1)
{
	// std::cout << "constucteur bloc" << std::endl;
}

Bloc::Bloc(int _X, int _Y, int _col) :
	width(30), height(30), color(_col), index(1), xposition(_X), yposition(_Y)
{
	// std::cout << "constucteur value" << std::endl;
}

Bloc::Bloc(const Bloc& _bloc) :
	width(_bloc.width), height(_bloc.height), color(_bloc.color), index(_bloc.index), xposition(_bloc.xposition), yposition(_bloc.yposition)
{
	// std::cout << "constucteur recopie" << std::endl;
}

Bloc::~Bloc()
{
	// std::cout << "destructeur" << std::endl;
}


int Bloc::getWidth() const
{
	return width;
}

int Bloc::getHeight() const
{
	return height;
}

int Bloc::getColor() const
{
	return color;
}

int Bloc::getXposition() const
{
	return xposition;
}

int Bloc::getYposition() const
{
	return yposition;
}

void Bloc::setColor(int _c)
{
	color = _c;
}

void Bloc::setXposition(int _x)
{
	if (_x >= 0 && _x <= SCREEN_WIDTH)
		xposition = _x;
	else
		std::cout << "Out of range" << std::endl;
}

void Bloc::setYposition(int _y)
{
	if (_y >= 0 && _y <= SCREEN_HEIGHT)
		xposition = _y;
	else
		std::cout << "Out of range" << std::endl;
}

void Bloc::BlockDisp(int _x,int _y) const
{

	//The window we'll be rendering to
	SDL_Window* gWindow = NULL;
	//Current displayed texture
	SDL_Texture* gTexture = NULL;
	SDL_Surface* gScreenSurface = NULL;
	//The window renderer
	SDL_Renderer* gRenderer = NULL;

	SDL_Surface* gCube = NULL;
	SDL_Rect posCube;
	posCube.x = _x;
	posCube.y = _y;

	// Creer fenetre
	gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	// Creer surface de fenetre
	gScreenSurface = SDL_GetWindowSurface(gWindow);
	//Main loop flag
	bool quit = false;
	//Event handler
	SDL_Event e;
	while (!quit)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
		}
		// Charger les image
		//gGreenCube = SDL_LoadBMP("Carree_Vert.bmp");
		//gBlueCube = SDL_LoadBMP("Carree_Bleu.bmp");
		switch (color)
		{
		case blue: gCube = SDL_LoadBMP("Carree_Bleu.bmp");
			break;
		case cyan: gCube = SDL_LoadBMP("Carree_Cyan.bmp");
			break;
		case yellow: gCube = SDL_LoadBMP("Carree_jaune.bmp");
			break;
		case orange: gCube = SDL_LoadBMP("Carree_Orange.bmp");
			break;
		case red: gCube = SDL_LoadBMP("Carree_rouge.bmp");
			break;
		case green: gCube = SDL_LoadBMP("Carree_vert.bmp");
			break;
		case purple: gCube = SDL_LoadBMP("Carree_Violet.bmp");
			break;
		}
		// Appliquer les images
		SDL_BlitSurface(gCube, NULL, gScreenSurface, &posCube);
		// Mettre à jour la surface
		SDL_UpdateWindowSurface(gWindow);
		//Clear screen
		SDL_RenderClear(gRenderer);
		//Render texture to screen
		SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
		//Update screen
		SDL_RenderPresent(gRenderer);
	}
}


void Test_Bloc()
{
	Bloc bloc1;
	Bloc bloc2(15, 50, yellow);
	Bloc bloc3(bloc2);
	std::cout << "Couleur bloc 1 : " << bloc1.getColor() << std::endl;
	std::cout << "Largeur bloc 1 : " << bloc1.getWidth() << std::endl;
	std::cout << "Hauteur bloc 1 : " << bloc1.getHeight() << std::endl;
	std::cout << "Position en y bloc 2 : " << bloc2.getYposition() << std::endl;
	std::cout << "Position en x bloc 3 : " << bloc3.getXposition() << std::endl;
	bloc3.setXposition(70);
	std::cout << "Position en x bloc 3 apres changement : " << bloc3.getXposition() << std::endl;
	bloc2.BlockDisp(bloc2.getXposition(), bloc2.getYposition());
}
