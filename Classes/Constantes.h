#ifndef CONSTANTES_H
#define CONSTANTES_H

#include<stdio.h>
#include <iostream>
#include <ostream>
#include <fstream>
#include <sstream>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <vector>
#include <exception>
#include <stdexcept>

#include "SDL2-2.0.8/include/SDL.h"
#include "SDL2-2.0.8/include/SDL_ttf.h"
#include "SDL2-2.0.8/include/SDL_image.h"

const unsigned int SCREEN_WIDTH = 1600;
const unsigned int SCREEN_HEIGHT = 900;

const unsigned int TAILLE_CARREAU = 32;
const unsigned int HAUTEUR_GRILLE = 24;
const unsigned int LARGEUR_GRILLE = 12;

enum { blue, cyan, yellow, orange, red, green, purple };
enum {I, O, T, L, J, Z, S};

typedef struct carreau carreau;
struct carreau {
	unsigned int index = 0;
	unsigned int xpos = 0;
	unsigned int ypos = 0;
	unsigned int bloc = 0;
};


typedef struct StructVar StructVar; 
struct StructVar{  // Structure permettant d'utiliser des variables si appelé

	//The window we'll be rendering to
	SDL_Window* gWindow = NULL;
	//The window renderer
	SDL_Renderer* gRenderer = NULL;

	std::vector<carreau> grille;
	std::vector<SDL_Texture*> images;
	std::vector<SDL_Rect> posimages;

};

#endif 
