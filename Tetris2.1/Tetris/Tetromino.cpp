#include "Tetromino.h"
#include "Constantes.h"


Tetromino::Tetromino() : type(0), color(0)
{
}

Tetromino::Tetromino(int _type, int _color) : type(_type), color(_color)
{
}

Tetromino::Tetromino(const Tetromino& _t) : type(_t.type), color(_t.color)
{
}


Tetromino::~Tetromino()
{
	std::cout << "destructeur Tetromino" << std::endl;
}

void Tetromino::initTetro(StructVar& sv)				// Initialisation des différentes pièces
{
	carreau init;
	for (unsigned int i = 0; i < 4; i++) 
	{
			forme.push_back(init);
	}
	type = rand() % 6;
	switch (type) 
	{
	case I:
		forme[0].xpos = sv.grille[LARGEUR_GRILLE / 2][0].xpos;
		forme[0].ypos = sv.grille[LARGEUR_GRILLE / 2][0].ypos;
		sv.grille[LARGEUR_GRILLE / 2][0].bloc = 2;								// Ligne plus importante pour affichage
		forme[1].xpos = sv.grille[LARGEUR_GRILLE / 2][1].xpos;
		forme[1].ypos = sv.grille[LARGEUR_GRILLE / 2][1].ypos;
		sv.grille[LARGEUR_GRILLE / 2][1].bloc = 2;
		forme[2].xpos = sv.grille[LARGEUR_GRILLE / 2][2].xpos;
		forme[2].ypos = sv.grille[LARGEUR_GRILLE / 2][2].ypos;
		sv.grille[LARGEUR_GRILLE / 2][2].bloc = 2;
		forme[3].xpos = sv.grille[LARGEUR_GRILLE / 2][3].xpos;
		forme[3].ypos = sv.grille[LARGEUR_GRILLE / 2][3].ypos;
		sv.grille[LARGEUR_GRILLE / 2][3].bloc = 2;
		break;

	case O:
		forme[0].xpos = sv.grille[LARGEUR_GRILLE / 2][0].xpos;
		forme[0].ypos = sv.grille[LARGEUR_GRILLE / 2][0].ypos;
		sv.grille[LARGEUR_GRILLE / 2][0].bloc = 2;
		forme[1].xpos = sv.grille[LARGEUR_GRILLE / 2][1].xpos;
		forme[1].ypos = sv.grille[LARGEUR_GRILLE / 2][1].ypos;
		sv.grille[LARGEUR_GRILLE / 2][1].bloc = 2;
		forme[2].xpos = sv.grille[LARGEUR_GRILLE / 2 - 1][0].xpos;
		forme[2].ypos = sv.grille[LARGEUR_GRILLE / 2 - 1][0].ypos;
		sv.grille[LARGEUR_GRILLE / 2 - 1][0].bloc = 2;
		forme[3].xpos = sv.grille[LARGEUR_GRILLE / 2 - 1][1].xpos;
		forme[3].ypos = sv.grille[LARGEUR_GRILLE / 2 - 1][1].ypos;
		sv.grille[LARGEUR_GRILLE / 2 - 1][1].bloc = 2;
		break;

	case T:
		forme[0].xpos = sv.grille[LARGEUR_GRILLE / 2][0].xpos;
		forme[0].ypos = sv.grille[LARGEUR_GRILLE / 2][0].ypos;
		sv.grille[LARGEUR_GRILLE / 2][0].bloc = 2;
		forme[1].xpos = sv.grille[LARGEUR_GRILLE / 2][1].xpos;
		forme[1].ypos = sv.grille[LARGEUR_GRILLE / 2][1].ypos;
		sv.grille[LARGEUR_GRILLE / 2][1].bloc = 2;
		forme[2].xpos = sv.grille[LARGEUR_GRILLE / 2][2].xpos;
		forme[2].ypos = sv.grille[LARGEUR_GRILLE / 2][2].ypos;
		sv.grille[LARGEUR_GRILLE / 2][2].bloc = 2;
		forme[3].xpos = sv.grille[LARGEUR_GRILLE / 2 - 1][1].xpos;
		forme[3].ypos = sv.grille[LARGEUR_GRILLE / 2 - 1][1].ypos;
		sv.grille[LARGEUR_GRILLE / 2 - 1][1].bloc = 2;
		break;

	case L:
		forme[0].xpos = sv.grille[LARGEUR_GRILLE / 2 - 1][0].xpos;
		forme[0].ypos = sv.grille[LARGEUR_GRILLE / 2 -1][0].ypos;
		sv.grille[LARGEUR_GRILLE / 2 - 1][0].bloc = 2;
		forme[1].xpos = sv.grille[LARGEUR_GRILLE / 2 - 1][1].xpos;
		forme[1].ypos = sv.grille[LARGEUR_GRILLE / 2 - 1][1].ypos;
		sv.grille[LARGEUR_GRILLE / 2 - 1][1].bloc = 2;
		forme[2].xpos = sv.grille[LARGEUR_GRILLE / 2][2].xpos;
		forme[2].ypos = sv.grille[LARGEUR_GRILLE / 2][2].ypos;
		sv.grille[LARGEUR_GRILLE / 2 - 1][2].bloc = 2;
		forme[3].xpos = sv.grille[LARGEUR_GRILLE / 2][2].xpos;
		forme[3].ypos = sv.grille[LARGEUR_GRILLE / 2][2].ypos;
		sv.grille[LARGEUR_GRILLE / 2][2].bloc = 2;
		break;

	case J:
		forme[0].xpos = sv.grille[LARGEUR_GRILLE / 2][0].xpos;
		forme[0].ypos = sv.grille[LARGEUR_GRILLE / 2][0].ypos;
		sv.grille[LARGEUR_GRILLE / 2][0].bloc = 2;
		forme[1].xpos = sv.grille[LARGEUR_GRILLE / 2][1].xpos;
		forme[1].ypos = sv.grille[LARGEUR_GRILLE / 2][1].ypos;
		sv.grille[LARGEUR_GRILLE / 2][1].bloc = 2;
		forme[2].xpos = sv.grille[LARGEUR_GRILLE / 2][2].xpos;
		forme[2].ypos = sv.grille[LARGEUR_GRILLE / 2][2].ypos;
		sv.grille[LARGEUR_GRILLE / 2][2].bloc = 2;
		forme[3].xpos = sv.grille[LARGEUR_GRILLE / 2 -  1][2].xpos;
		forme[3].ypos = sv.grille[LARGEUR_GRILLE / 2 - 1][2].ypos;
		sv.grille[LARGEUR_GRILLE / 2 -  1][2].bloc = 2;
		break;

	case Z:
		forme[0].xpos = sv.grille[LARGEUR_GRILLE / 2][0].xpos;
		forme[0].ypos = sv.grille[LARGEUR_GRILLE / 2][0].ypos;
		sv.grille[LARGEUR_GRILLE / 2][0].bloc = 2;
		forme[1].xpos = sv.grille[LARGEUR_GRILLE / 2 - 1][0].xpos;
		forme[1].ypos = sv.grille[LARGEUR_GRILLE / 2 - 1][0].ypos;
		sv.grille[LARGEUR_GRILLE / 2 - 1][0].bloc = 2;
		forme[2].xpos = sv.grille[LARGEUR_GRILLE / 2][1].xpos;
		forme[2].ypos = sv.grille[LARGEUR_GRILLE / 2][1].ypos;
		sv.grille[LARGEUR_GRILLE / 2][1].bloc = 2;
		forme[3].xpos = sv.grille[LARGEUR_GRILLE / 2 + 1][1].xpos;
		forme[3].ypos = sv.grille[LARGEUR_GRILLE / 2 + 1][1].ypos;
		sv.grille[LARGEUR_GRILLE / 2 + 1][1].bloc = 2;
		break;

	case S:
		forme[0].xpos = sv.grille[LARGEUR_GRILLE / 2][0].xpos;
		forme[0].ypos = sv.grille[LARGEUR_GRILLE / 2][0].ypos;
		sv.grille[LARGEUR_GRILLE / 2][0].bloc = 2;
		forme[1].xpos = sv.grille[LARGEUR_GRILLE / 2 + 1][0].xpos;
		forme[1].ypos = sv.grille[LARGEUR_GRILLE / 2 + 1][0].ypos;
		sv.grille[LARGEUR_GRILLE / 2 + 1][0].bloc = 2;
		forme[2].xpos = sv.grille[LARGEUR_GRILLE / 2][1].xpos;
		forme[2].ypos = sv.grille[LARGEUR_GRILLE / 2][1].ypos;
		sv.grille[LARGEUR_GRILLE / 2][1].bloc = 2;
		forme[3].xpos = sv.grille[LARGEUR_GRILLE / 2 - 1][1].xpos;
		forme[3].ypos = sv.grille[LARGEUR_GRILLE / 2 - 1][1].ypos;
		sv.grille[LARGEUR_GRILLE / 2 - 1][1].bloc = 2;
		break;
	}
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
}
