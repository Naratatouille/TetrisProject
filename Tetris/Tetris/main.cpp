
#include "Bloc.h"
#include "Tetromino.h"
#include "Constantes.h"
#include "Texture.h"
#include "Game.h"
//bool loadMedia(StructVar &sv);
SDL_Color coucoutest = { 128,128,128 };


void initGrille(std::vector<carreau>& grille);
void initGrille(std::vector<carreau>& grille) 
{
	carreau initia;
	unsigned int k = 0;
	for (unsigned int i = 0; i < LARGEUR_GRILLE; i++)
	{
		for (unsigned int j = 0; j < HAUTEUR_GRILLE; j++)
		{
			
			initia.index = k;
			initia.xpos = i * TAILLE_CARREAU + SCREEN_WIDTH / 2 - (LARGEUR_GRILLE / 2) * TAILLE_CARREAU;
			initia.ypos = j * TAILLE_CARREAU + SCREEN_HEIGHT / 2 - (HAUTEUR_GRILLE / 2)* TAILLE_CARREAU;

			if (i == 0 || i == LARGEUR_GRILLE - 1 || j == HAUTEUR_GRILLE - 1)
			{
				initia.bloc = 1;
			}
			grille.push_back(initia); //rempli la grille
			k++;
		}
	}
}

void initImages(std::vector<Texturer*> &tabText, StructVar &sv);
void initImages(std::vector<Texturer*> &tabText, StructVar &sv)
{
	Texturer::loadfromfile(tabText,sv,(std::string)("Background.png"), 0, 0,SCREEN_WIDTH,SCREEN_HEIGHT);
	Texturer::loadfromfile(tabText, sv, (std::string)("Carre_Elem.png"), 0, 0);

	//Texturer::loadfromfile(tabText, sv, (std::string)("NewGame.png"), 200, 140);
	//Texturer::loadfromfile(tabText, sv, (std::string)("Scores.png"), 200, 250);
}

void initText(std::vector<Texturer*> &tabText, StructVar &sv);
void initText(std::vector<Texturer*> &tabText, StructVar &sv)
{

	Texturer::loadfromrenderedtext(tabText, sv, (std::string)("NEW GAME : Press (N)"),coucoutest,0,0);
	Texturer::loadfromrenderedtext(tabText, sv, (std::string)("SCORES : Press (C)"), coucoutest, 0, 0);
}


int main(int argc, char* argv[]) 
{
	//Initialize SDL_ttf
	if (TTF_Init() == -1)
	{
		printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());

	}
	int Selection=0;
	StructVar  sv;  // instanciation de la structure 
	initGrille(sv.grille);


	// Creer fenetre
	sv.gWindow = SDL_CreateWindow("SDL Tutorial", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	sv.gRenderer = SDL_CreateRenderer(sv.gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);// presentvsync : permet de synchroniser frequence de la boucle avec taux de raffraichissement de l'ecran
	sv.gFont = TTF_OpenFont("arial.ttf", 40);
	
	initImages(sv.tabText, sv);	
	initText(sv.tabText, sv);

	bool quit = false;
	//Event handler
	SDL_Event e;
	while (!quit) {

		while (SDL_PollEvent(&e) != 0) 
		{
			switch (e.type) {
			case SDL_QUIT:	// permet de quitter le jeu avec croix
				quit = true;
				break;
			case SDL_KEYDOWN: // test sur le type d'événement touche enfoncé
				switch (e.key.keysym.sym) {
				case SDLK_ESCAPE:
					quit = true;
					break;
				case SDLK_SPACE:

					break;
				case SDLK_UP:
					//CurrentTexture2 = gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN];
					//CurrentTexture = NewGameTexture;
					//ajouter partie de texture
					break;
				case SDLK_DOWN:
					//pareil
					break;
				case SDLK_n:

					Game::PlayGame(sv);
					Selection = NewGame;

					break;

				}
			/*case SDL_MOUSEBUTTONDOWN: // test sur le type d'événement click souris (enfoncé)
									  //mouse(information, event);
				break;
			case SDL_MOUSEWHEEL:
				//wheel(information, event.wheel.y);
				break;*/
			}

		}

		switch (Selection)
		{
		case Menu:
			SDL_RenderClear(sv.gRenderer);
			for (unsigned int k = 0; k < sv.tabText.size(); k++)
			{
				sv.tabText[k]->render(0, 0, (std::string)("Background.png"), sv);
				sv.tabText[k]->render(50,(SCREEN_HEIGHT/2)-100, (std::string)("NEW GAME : Press (N)"), sv);
				sv.tabText[k]->render(50, (SCREEN_HEIGHT / 2) + 100, (std::string)("SCORES : Press (C)"), sv);

			}


			SDL_RenderPresent(sv.gRenderer);
			break;
		case NewGame:

			SDL_SetRenderDrawColor(sv.gRenderer, 128, 128, 128, 255);
			SDL_RenderClear(sv.gRenderer);
			for (unsigned int i = 0; i < sv.grille.size(); i++)
			{
				for (unsigned int k = 0; k < sv.tabText.size(); k++)
				{
					sv.tabText[k]->render(sv.grille[i].xpos, sv.grille[i].ypos, (std::string)("Carre_Elem.png"), sv);
				}
				
			}
	
			SDL_RenderPresent(sv.gRenderer);
			break;



		}


	}

	//Destroy window
	SDL_DestroyWindow(sv.gWindow);
	sv.gWindow = NULL;

	SDL_DestroyRenderer(sv.gRenderer);
	sv.gRenderer = NULL;  // on peut mettre nullptr au lieu de NULL-> nullptr juste plus recent


	//Quit SDL subsystems
	//Free loaded images
	//NewGameTexture.free();
	//BackgroundTexture.free();
	//ScoreTexture.free();

	//Quit SDL subsystems
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();

	//Test_Bloc();
	//Test_Forme();
	return 0;
}


//  A Faire 
// pas un tbleau de sdl_textures mais de texture (classe) pour charger images (pas besoin du sdl rect)
// l.28 texture.cpp
//essayer afficher grille
//CLASSE bouton


























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