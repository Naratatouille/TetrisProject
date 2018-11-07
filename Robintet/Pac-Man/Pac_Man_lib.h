/*

	Pac-Man
	Copyright SAUTER Robin and Joeffrey VILLERONCE 2018-2019 (robin.sauter@orange.fr)
	last modification on this file on version:0.15

	You can check for update on github.com -> https://github.com/phoenixcuriosity/Pac-Man

	This program is free software: you can redistribute it and/or modify
	it under the terms of the GNU General Public License as published by
	the Free Software Foundation, either version 3 of the License, or
	(at your option) any later version.

	This program is distributed in the hope that it will be useful,
	but WITHOUT ANY WARRANTY; without even the implied warranty of
	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
	GNU General Public License for more details.

	You should have received a copy of the GNU General Public License
	along with this program.  If not, see <http://www.gnu.org/licenses/>.

*/

#ifndef Pac_Man_lib_H
#define Pac_Man_lib_H

#include "lib.h"  // include lib et typedef

#include "IHM.h"
#include "Entity.h"

// ********* CONSTANTES ******** //
//--- Constantes concernant l'ecran et la dimension de la fenetre  -----------------------------------------------------------------------------------

// longueur de la fenetre en pixel
const Uint16 SCREEN_WIDTH = 1920;

// hauteur de la fenetre en pixel
const Uint16 SCREEN_HEIGHT = 1088;

// longueur et hauteur d'une case en pixel
const Uint8 TILE_SIZE = 32;

//--- Constantes concernant la taille des différents tableaux  --------------------------------------------------------------------------------------

// nombre maximal de polices de la font (ici arial)
const Uint8 MAX_FONT = 160;

//--- Constantes concernant les couleurs pour l'utilisation de la SDL  -------------------------------------------------------------------------------

/*
	SDL_Color name {Red, Green, Blue, Alpha (transparance)} 
	chaque parametre est codé sur 8 bit -> Uint8  (de 0 à 255)
*/

const SDL_Color Black = { 0, 0, 0, 255 };
const SDL_Color White = { 255, 255, 255, 255 };
const SDL_Color Red = { 255, 0, 0, 255 };
const SDL_Color Green = { 0, 255, 0, 255 };
const SDL_Color Blue = { 0, 0, 255, 255 };
const SDL_Color Yellow = { 255, 255, 0, 255 };
const SDL_Color WriteColorButton = { 255, 64, 0, 255 }; // orange
const SDL_Color BackColorButton = { 64, 64, 64, 255 }; // gris
const SDL_Color NoColor = { 0, 0, 0, 0 };

// ********* ENUM ******** //
//--- enum concernant les objets Texture  -----------------------------------------------------------------------------------------------------------

/*
	* type de texte :
	*	-> blended : sans couleur de fond
	*	-> shaded : avec une couleur de fond
*/
enum Texte_Type : Uint8 { NA, blended, shaded};

/*
	* type de transparance :
	*	-> 0 transparance totale
	*	-> 255 totalement visible
*/
enum Transparance_Type : Uint8 { transparent = 0, semiTransparent = 128, nonTransparent = 255 };

/*
	* type de centrage :	
	*	-> nocenter : les positions x et y ne changent pas
	*	-> center_x : la position y ne change pas et centre la position x en focntion de la longueur du texte
	*	-> center_y : la position x ne change pas et centre la position y en focntion de hauteur du texte
	*	-> center : centre totalement le texte en fonction de sa longueur et de sa hauteur
*/
enum Center_Type: Uint8 { nocenter, center_x, center_y, center };

// contient les index concernant le tableau de Texture ground
enum Ground_Type: Uint8 { blackTile, whiteTile}; 

//--- enum concernant les objets Entity  -----------------------------------------------------------------------------------------------------------

// contient les différents type
enum _Type : Uint8 { I, J, L, O, S, T, Z};

// contient les différents type couleur
enum color_Type: Uint8 { red, blue, yellow, green, brown};

// type de directions
enum Heading_Type: Uint8 { UP, LEFT, DOWN, RIGHT };



//--- enum concernant l'état dans le quel ce trouve le programme  ----------------------------------------------------------------------------------

// différents état de l'écran
enum State_Type: Uint8 { STATEnothing, STATEecrantitre, STATEplay, STATEscore };  

// spécifications de la séléction
enum Select_Type: Uint8 { selectnothing, pause, win, lost };	



// ********* STRUCTURE ******** //
//---------------------- Structure niveau 2 ---------------------------------------------------------------------------------------------------------
/*
	*	structure contenant les données en rapport avec le temps du programme
*/
struct GameTime {
	// nombre d'heures de jeu
	Uint8 hours = 0;

	// nombre de minutes de jeu, modulo 60
	Uint8 minutes = 0;

	// nombre de seconde de jeu, modulo 60
	Uint8 seconds = 0;

	Uint8 frame = 0;
};
/*
	*	Structure décrivant une case dans la map
*/
struct Tile {
	// numéro de la case en x map[x][y]
	Uint8 indexX = 0; 

	// numéro de la case en y map[x][y]
	Uint8 indexY = 0; 

	// position en x sur l'écran
	unsigned int tile_x = 0;

	// position en y sur l'écran
	unsigned int tile_y = 0;

	// s'il y a un mur ou non
	bool wall = false;

};
//---------------------- Structure niveau 1 ---------------------------------------------------------------------------------------------------------
struct Screen {
	// ptr sur la fenetre crée par la SDL
	SDL_Window *window = nullptr;

	// ptr sur le renderer crée par la SDL
	SDL_Renderer *renderer = nullptr;
};
/*
	*	Structure contenant tous les noms des fichiers ainsi que leurs chemins
*/
struct File {
	const std::string log = "log.txt";
};
struct Var {
	/*** type primitif	***/

	// variable permettant de quitter la boucle principale donc le jeu
	bool continuer = true;

	// état de la sélection du joueur : selectnothing, pause, win, lost
	Uint8 select = selectnothing;

	// état de l'écran du joueur : STATEnothing, STATEecrantitre, STATEplay, STATEscore
	Uint8 statescreen = STATEnothing;

	// modulo permettant de passer un nombre de fois pré-défini par seconde (max 60/s -> flag : SDL_RENDERER_PRESENTVSYNC)
	Uint8 modulo = 0;


	/*** type personnalisé	***/

	// structure contenant les données en rapport avec le temps du programme
	GameTime gameTime;
};
/*
	*	Contient toutes les Textures images
*/
struct AllTextures {
	// tableau d'images contenu dans le sol de la map
	std::vector<Texture*> ground;
	std::vector<Texture*> color;
};
/*
	*	Contient toutes les Textes
*/
struct AllTextes {
	// tableau de polices de la font arial
	TTF_Font *font[MAX_FONT] = {};

};
/*
	*	Contient tous les boutons
*/
struct Map {
	// Matrice contenant des structures Tile
	std::vector<std::vector<Tile>> matriceMap;

	// longueur de la map en TILE_SIZE
	Uint8 map_length = 12;

	// hauteur de la map en TILE_SIZE
	Uint8 map_height = 32;
};
//---------------------- Structure niveau 0 ---------------------------------------------------------------------------------------------------------
struct Sysinfo {
	// contient les données en rapport à la SDL 
	Screen screen;

	// contient les noms et le chemins des fichiers .txt 
	File file;

	// contient des variables non organisées
	Var var;

	// contient toutes les images
	AllTextures allTextures;

	// contient tous les textes
	AllTextes allTextes;


	// contient les données en rapport à la map
	Map map;

	// tableau de ptr sur les objets Ghost (classe fille de Entity)
	std::vector<Entity*> tabForme;
};

#endif