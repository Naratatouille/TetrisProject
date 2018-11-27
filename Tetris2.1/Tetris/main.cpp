#include "Tetromino.h"
#include "Constantes.h"
#include "Texture.h"
#include "Game.h"

SDL_Color coucoutest = { 128,128,128 };


void initGrille(std::vector<std::vector<carreau>>& grille);
void initGrille(std::vector<std::vector<carreau>>& grille)
{
	std::vector<carreau> initve;
	carreau initia;
	for (unsigned int i = 0; i < LARGEUR_GRILLE; i++)
	{
		grille.push_back(initve);
		for (unsigned int j = 0; j < HAUTEUR_GRILLE; j++)
		{

			initia.index_ligne = i;
			initia.index_col = j;
			initia.xpos = i * TAILLE_CARREAU + SCREEN_WIDTH / 2 - (LARGEUR_GRILLE / 2) * TAILLE_CARREAU;
			initia.ypos = j * TAILLE_CARREAU + SCREEN_HEIGHT / 2 - (HAUTEUR_GRILLE / 2)* TAILLE_CARREAU;

			if (i == 0 || i == LARGEUR_GRILLE - 1|| j == HAUTEUR_GRILLE - 1)
			{
				initia.bloc = 1;
			}
			else {
				initia.bloc = 0;
			}
			grille[i].push_back(initia); //rempli la grille
		}
	}
}

void initImages(std::vector<Texturer*> &tabText, StructVar &sv);
void initImages(std::vector<Texturer*> &tabText, StructVar &sv)
{
	Texturer::loadfromfile(tabText, sv, (std::string)("Background.png"), 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT);
	Texturer::loadfromfile(tabText, sv, (std::string)("Carre_Elem.png"), 0, 0);
	Texturer::loadfromfile(tabText, sv, (std::string)("Carree_Bleu.bmp"), 0, 0, TAILLE_CARREAU, TAILLE_CARREAU);
	Texturer::loadfromfile(tabText, sv, (std::string)("Carree_Rouge.bmp"), 0, 0, TAILLE_CARREAU, TAILLE_CARREAU);
	Texturer::loadfromfile(tabText, sv, (std::string)("Blue.png"), 0, 0,TAILLE_CARREAU, TAILLE_CARREAU);
}

void initText(std::vector<Texturer*> &tabText, StructVar &sv);
void initText(std::vector<Texturer*> &tabText, StructVar &sv)
{

	Texturer::loadfromrenderedtext(tabText, sv, (std::string)("NEW GAME : Press (N)"), coucoutest, 0, 0);
	Texturer::loadfromrenderedtext(tabText, sv, (std::string)("SCORES : Press (C)"), coucoutest, 0, 0);
}


int main(int argc, char* argv[])
{
	srand((unsigned int)time(NULL));
	//Initialize SDL_ttf
	if (TTF_Init() == -1)
	{
		printf("SDL_ttf could not initialize! SDL_ttf Error: %s\n", TTF_GetError());

	}
	
	int Selection = 0;
	StructVar  sv;  // instanciation de la structure 
	initGrille(sv.grille);

	// Creer fenetre
	sv.gWindow = SDL_CreateWindow("Tetris", 0, 0, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	sv.gRenderer = SDL_CreateRenderer(sv.gWindow, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);// presentvsync : permet de synchroniser frequence de la boucle avec taux de raffraichissement de l'ecran
	sv.gFont = TTF_OpenFont("arial.ttf", 40);

	initImages(sv.tabText, sv);
	initText(sv.tabText, sv);
	Tetromino::initTabalea(sv.tabTetro, sv.tabTetroModify);

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
					
					Tetromino::initTetro(sv);


					break;
				case SDLK_n:

					Game::PlayGame(sv);
					Selection = NewGame;

					break;

				case SDLK_UP:
				
					break;
				case SDLK_DOWN:
					break;

				}
			}

		}

		switch (Selection)
		{
		case Menu:
			SDL_RenderClear(sv.gRenderer);
			for (unsigned int k = 0; k < sv.tabText.size(); k++)
			{
				sv.tabText[k]->render(0, 0, (std::string)("Background.png"), sv);
				sv.tabText[k]->render(50, (SCREEN_HEIGHT / 2) - 100, (std::string)("NEW GAME : Press (N)"), sv);
				sv.tabText[k]->render(50, (SCREEN_HEIGHT / 2) + 100, (std::string)("SCORES : Press (C)"), sv);

			}


			SDL_RenderPresent(sv.gRenderer);
			break;
		case NewGame:
			SDL_SetRenderDrawColor(sv.gRenderer, 128, 128, 128, 255);
			SDL_RenderClear(sv.gRenderer);
			for (unsigned int i = 0; i < sv.grille.size(); i++)
			{
				for (unsigned int j = 0; j < sv.grille[i].size(); j++)
				{
					for (unsigned int k = 0; k < sv.tabText.size(); k++)
					{
						if (sv.grille[i][j].bloc == 0) 
						{
							sv.tabText[k]->render(sv.grille[i][j].xpos, sv.grille[i][j].ypos, (std::string)("Carre_Elem.png"), sv);
						}

						else if (sv.grille[i][j].bloc == 2)
						{
							sv.tabText[k]->render(sv.grille[i][j].xpos, sv.grille[i][j].ypos, (std::string)("Carree_Rouge.bmp"), sv);
						}
					}

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
	TTF_Quit();
	IMG_Quit();
	SDL_Quit();

	return 0;
}

