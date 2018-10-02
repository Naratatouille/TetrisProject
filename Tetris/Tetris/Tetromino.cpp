#include "Tetromino.h"
#include "Constantes.h"


Tetromino::Tetromino() :
	A(), B(), C(), D(), forme(T), color(0)
{
	std::cout << "Constructeur Tetromino" << std::endl;
}

Tetromino::Tetromino(int _forme, int _color) :
	A(), B(), C(), D(), forme(_forme), color(_color)
{
}

Tetromino::Tetromino(const Tetromino& _t) :
	A(_t.A), B(_t.B), C(_t.C), D(_t.D), forme(_t.forme), color(_t.color)
{
}


Tetromino::~Tetromino()
{
	std::cout << "destructeur Tetromino" << std::endl;
}

void Tetromino::TetroDisp(StructVar& sv) const
{

	//Current displayed texture
	SDL_Texture* gTexture = NULL;
	SDL_Surface* gScreenSurface = NULL;


	SDL_Surface* gCube = NULL;

	SDL_Rect posCube1;

	SDL_Rect posCube2;

	SDL_Rect posCube3;

	SDL_Rect posCube4;



	// Creer surface de fenetre
	gScreenSurface = SDL_GetWindowSurface(sv.gWindow);
	//Main loop flag

	bool quit = false;
	//Event handler
	SDL_Event e;

	while (!quit) {

		while (SDL_PollEvent(&e) != 0) {
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
				}
			case SDL_MOUSEBUTTONDOWN: // test sur le type d'événement click souris (enfoncé)
				//mouse(information, event);
				break;
			case SDL_MOUSEWHEEL:
				//wheel(information, event.wheel.y);
				break;
			}

		}

		// Charger les image
		//gGreenCube = SDL_LoadBMP("Carree_Vert.bmp");
		//gBlueCube = SDL_LoadBMP("Carree_Bleu.bmp");
		switch (forme)
		{
		case I:

			posCube1.y = SCREEN_HEIGHT / 2;
			posCube1.x = SCREEN_WIDTH / 2 - 60;

			posCube2.y = SCREEN_HEIGHT / 2;
			posCube2.x = SCREEN_WIDTH / 2 - 30;

			posCube3.y = SCREEN_HEIGHT / 2;
			posCube3.x = SCREEN_WIDTH / 2;

			posCube4.y = SCREEN_HEIGHT / 2;
			posCube4.x = SCREEN_WIDTH / 2 + 30;

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
			SDL_BlitSurface(gCube, NULL, gScreenSurface, &posCube1);
			SDL_BlitSurface(gCube, NULL, gScreenSurface, &posCube2);
			SDL_BlitSurface(gCube, NULL, gScreenSurface, &posCube3);
			SDL_BlitSurface(gCube, NULL, gScreenSurface, &posCube4);
			break;

		case O:
			posCube1.y = SCREEN_HEIGHT / 2;
			posCube1.x = SCREEN_WIDTH / 2;

			posCube2.y = SCREEN_HEIGHT / 2;
			posCube2.x = SCREEN_WIDTH / 2 - 30;

			posCube3.y = SCREEN_HEIGHT / 2 - 30;
			posCube3.x = SCREEN_WIDTH / 2;

			posCube4.y = SCREEN_HEIGHT / 2 - 30;
			posCube4.x = SCREEN_WIDTH / 2 - 30;

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
			SDL_BlitSurface(gCube, NULL, gScreenSurface, &posCube1);
			SDL_BlitSurface(gCube, NULL, gScreenSurface, &posCube2);
			SDL_BlitSurface(gCube, NULL, gScreenSurface, &posCube3);
			SDL_BlitSurface(gCube, NULL, gScreenSurface, &posCube4);
			break;

		case T:
			posCube1.y = SCREEN_HEIGHT / 2;
			posCube1.x = SCREEN_WIDTH / 2;

			posCube2.y = SCREEN_HEIGHT / 2;
			posCube2.x = SCREEN_WIDTH / 2 - 30;

			posCube3.y = SCREEN_HEIGHT / 2;
			posCube3.x = SCREEN_WIDTH / 2 + 30;

			posCube4.y = SCREEN_HEIGHT / 2 + 30;
			posCube4.x = SCREEN_WIDTH / 2;

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
			SDL_BlitSurface(gCube, NULL, gScreenSurface, &posCube1);
			SDL_BlitSurface(gCube, NULL, gScreenSurface, &posCube2);
			SDL_BlitSurface(gCube, NULL, gScreenSurface, &posCube3);
			SDL_BlitSurface(gCube, NULL, gScreenSurface, &posCube4);
			break;

		case L:
			posCube1.y = SCREEN_HEIGHT / 2;
			posCube1.x = SCREEN_WIDTH / 2;

			posCube2.y = SCREEN_HEIGHT / 2 - 30;
			posCube2.x = SCREEN_WIDTH / 2;

			posCube3.y = SCREEN_HEIGHT / 2;
			posCube3.x = SCREEN_WIDTH / 2 + 30;

			posCube4.y = SCREEN_HEIGHT / 2 - 60;
			posCube4.x = SCREEN_WIDTH / 2;

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
			SDL_BlitSurface(gCube, NULL, gScreenSurface, &posCube1);
			SDL_BlitSurface(gCube, NULL, gScreenSurface, &posCube2);
			SDL_BlitSurface(gCube, NULL, gScreenSurface, &posCube3);
			SDL_BlitSurface(gCube, NULL, gScreenSurface, &posCube4);
			break;

		case J:
			posCube1.y = SCREEN_HEIGHT / 2;
			posCube1.x = SCREEN_WIDTH / 2;

			posCube2.y = SCREEN_HEIGHT / 2;
			posCube2.x = SCREEN_WIDTH / 2 - 30;

			posCube3.y = SCREEN_HEIGHT / 2 - 30;
			posCube3.x = SCREEN_WIDTH / 2;

			posCube4.y = SCREEN_HEIGHT / 2 - 60;
			posCube4.x = SCREEN_WIDTH / 2;

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
			SDL_BlitSurface(gCube, NULL, gScreenSurface, &posCube1);
			SDL_BlitSurface(gCube, NULL, gScreenSurface, &posCube2);
			SDL_BlitSurface(gCube, NULL, gScreenSurface, &posCube3);
			SDL_BlitSurface(gCube, NULL, gScreenSurface, &posCube4);
			break;

		case S:
			posCube1.y = SCREEN_HEIGHT / 2;
			posCube1.x = SCREEN_WIDTH / 2;

			posCube2.y = SCREEN_HEIGHT / 2 + 30;
			posCube2.x = SCREEN_WIDTH / 2;

			posCube3.y = SCREEN_HEIGHT / 2;
			posCube3.x = SCREEN_WIDTH / 2 + 30;

			posCube4.y = SCREEN_HEIGHT / 2 + 30;
			posCube4.x = SCREEN_WIDTH / 2 - 30;

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
			SDL_BlitSurface(gCube, NULL, gScreenSurface, &posCube1);
			SDL_BlitSurface(gCube, NULL, gScreenSurface, &posCube2);
			SDL_BlitSurface(gCube, NULL, gScreenSurface, &posCube3);
			SDL_BlitSurface(gCube, NULL, gScreenSurface, &posCube4);
			break;

		case Z:
			posCube1.y = SCREEN_HEIGHT / 2;
			posCube1.x = SCREEN_WIDTH / 2;

			posCube2.y = SCREEN_HEIGHT / 2;
			posCube2.x = SCREEN_WIDTH / 2 - 30;

			posCube3.y = SCREEN_HEIGHT / 2 + 30;
			posCube3.x = SCREEN_WIDTH / 2;

			posCube4.y = SCREEN_HEIGHT / 2 + 30;
			posCube4.x = SCREEN_WIDTH / 2 + 30;

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
			SDL_BlitSurface(gCube, NULL, gScreenSurface, &posCube1);
			SDL_BlitSurface(gCube, NULL, gScreenSurface, &posCube2);
			SDL_BlitSurface(gCube, NULL, gScreenSurface, &posCube3);
			SDL_BlitSurface(gCube, NULL, gScreenSurface, &posCube4);
			break;
		}
		// Mettre à jour la surface
		SDL_UpdateWindowSurface(sv.gWindow);
		//Clear screen
		SDL_RenderClear(sv.gRenderer);
		//Render texture to screen
		SDL_RenderCopy(sv.gRenderer, gTexture, NULL, NULL);
		//Update screen
		SDL_RenderPresent(sv.gRenderer);



	}
	//Deallocate surface
	SDL_FreeSurface(gCube);
	gCube = NULL;

}

// COULEURS : 
// I = Cyan 
// O = Jaune 
// T = Violet
// L = Orange 
// J = Bleu 
// Z = Rouge 
// S = Vert

void Test_Forme()
{
	Tetromino T1;
	//T1.TetroDisp();
}
