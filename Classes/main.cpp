
#include "Bloc.h"
#include "Tetromino.h"
#include "Constantes.h"

void initGrille(std::vector<carreau>& grille);
void initGrille(std::vector<carreau>& grille) 
{
	unsigned int k = 0;
	for (unsigned int i = 0; i < LARGEUR_GRILLE; i++)
	{
		for (unsigned int j = 0; j < HAUTEUR_GRILLE; j++)
		{
			grille[k].index = k;
			grille[k].xpos = i * TAILLE_CARREAU + SCREEN_WIDTH / 2;
			grille[k].ypos = j * TAILLE_CARREAU + SCREEN_HEIGHT / 2;

			if (i == 0 || i == LARGEUR_GRILLE - 1 || j == HAUTEUR_GRILLE - 1)
			{
				grille[k].bloc = 1;
			}
			k++;
		}
	}
}

void initImages(std::vector<SDL_Texture*>& images, std::vector<SDL_Rect>& posimages);
void initImages(std::vector<SDL_Texture*>& images, std::vector<SDL_Rect>& posimages)
{

}


int main(int argc, char* argv[]) 
{


	StructVar  sv;  // instanciation de la structure 
	initGrille(sv.grille);

	// Creer fenetre
	sv.gWindow = SDL_CreateWindow("SDL Tutorial", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	sv.gRenderer = SDL_CreateRenderer(sv.gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);	// presentvsync : permet de synchroniser frequence de la boucle avec taux de raffraichissement de l'ecran

	bool quit = false;
	//Event handler
	SDL_Event e;
	while (!quit) {

		while (SDL_PollEvent(&e) != 0) {
			switch (e.type) {
			case SDL_QUIT:	// permet de quitter le jeu avec croix
				quit = true;
				break;
			case SDL_KEYDOWN: // test sur le type d'�v�nement touche enfonc�
				switch (e.key.keysym.sym) {
				case SDLK_ESCAPE:
					quit = true;
					break;
				case SDLK_SPACE:

					break;
				}
			case SDL_MOUSEBUTTONDOWN: // test sur le type d'�v�nement click souris (enfonc�)
									  //mouse(information, event);
				break;
			case SDL_MOUSEWHEEL:
				//wheel(information, event.wheel.y);
				break;
			}

		}
	}

	//Destroy window
	SDL_DestroyWindow(sv.gWindow);
	sv.gWindow = NULL;

	SDL_DestroyRenderer(sv.gRenderer);
	sv.gRenderer = NULL;  // on puet mettre nullptr au lieu de NULL-> nullptr jutse plus recent


	//Quit SDL subsystems
	SDL_Quit();

	//Test_Bloc();
	//Test_Forme();
	return 0;
}


//  A Faire 
// pas un tbleau de sdl_textures mais de texture (classe) pour charger images (pas besoin du sdl rect)
// l.28 texture.cpp
//essayer afficher grille




// Test texture
/*This source code copyrighted by Lazy Foo' Productions (2004-2015)
and may not be redistributed without written permission.*/
/*
//Using SDL, SDL_image, standard IO, and strings

#include "Constantes.h"
#include <stdio.h>
#include <string>


//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The window renderer
SDL_Renderer* gRenderer = NULL;

//Current displayed texture
SDL_Texture* gTexture = NULL;


int main(int argc, char* args[])
{
	//Create window
	gWindow = SDL_CreateWindow("SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	//Create renderer for window
	gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
	//Initialize renderer color
	SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
	//Initialize PNG loading
	int imgFlags = IMG_INIT_PNG;
	bool quit = false;
	//The final texture
	SDL_Texture* newTexture = NULL;
	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load("Carree_Bleu.bmp");
	//Create texture from surface pixels
	gTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
	//Get rid of old loaded surface
	SDL_FreeSurface(loadedSurface);
	//Event handler
	SDL_Event e;
	//While application is running
	while (!quit)
	{
		//Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			//User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
		}
		//Clear screen
		SDL_RenderClear(gRenderer);
		//Render texture to screen
		SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
		//Update screen
		SDL_RenderPresent(gRenderer);
	}
	//Free resources and close SDL
	//Free loaded image
	SDL_DestroyTexture(gTexture);
	gTexture = NULL;

	//Destroy window	
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();

	return 0;
}*/