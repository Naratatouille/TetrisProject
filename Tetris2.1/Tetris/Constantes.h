#ifndef CONSTANTES_H
#define CONSTANTES_H


#include "initialisation.h"



const unsigned int SCREEN_WIDTH = 1600;
const unsigned int SCREEN_HEIGHT = 900;

const unsigned int TAILLE_CARREAU = 32;
const unsigned int HAUTEUR_GRILLE = 24;
const unsigned int LARGEUR_GRILLE = 12;



enum { blue, cyan, yellow, orange, red, green, purple };
enum {I, O, T, L, J, Z, S};
enum {Menu,NewGame,Score};
enum KeyPressSurfaces
{
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_TOTAL
};


struct carreau {
	unsigned int index_ligne = 0;
	unsigned int index_col = 0;
	unsigned int xpos = 0;
	unsigned int ypos = 0;
	unsigned int bloc = 0;
};



struct StructVar{  // Structure permettant d'utiliser des variables si appelé

	//The window we'll be rendering to
	SDL_Window* gWindow = NULL;
	//The window renderer
	SDL_Renderer* gRenderer = NULL;
	TTF_Font *gFont = NULL;

	std::vector<std::vector<carreau>> grille;
	std::vector<Texturer*> tabText;
	std::vector<Tetromino*> tabForme;

};



#endif 
