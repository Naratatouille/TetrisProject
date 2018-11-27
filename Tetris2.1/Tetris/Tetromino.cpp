#include "Tetromino.h"
#include "Constantes.h"



Tetromino::Tetromino(int _type, std::vector<carreau>& _form) : type(_type), forme(_form)
{
}

Tetromino::Tetromino(const Tetromino& _t) : type(_t.type)
{
}



Tetromino::~Tetromino()
{
	std::cout << "destructeur Tetromino" << std::endl;
}

void Tetromino::initTabalea(std::vector<std::vector< unsigned int>>& tabTetro, std::vector<std::vector< unsigned int>>& tabTetroModify) //Création d'un tableau permettant de faire des pièces aléatoires
{
	std::vector<unsigned int> board;
	for (unsigned int k = 0; k < 3; k++)
	{
		tabTetro.push_back(board);
	}


	for (unsigned int i = 0; i < 7; i++)
	{
		tabTetro[0].push_back(i);
	}
	tabTetro[1].push_back(0); // Création d'un tableau stockant 2x chaque pièces
	tabTetro[1].push_back(0);
	tabTetro[1].push_back(1);
	tabTetro[1].push_back(1);
	tabTetro[1].push_back(2);
	tabTetro[1].push_back(2);
	tabTetro[1].push_back(3);
	tabTetro[1].push_back(3);
	tabTetro[1].push_back(4);
	tabTetro[1].push_back(4);
	tabTetro[1].push_back(5);
	tabTetro[1].push_back(5);
	tabTetro[1].push_back(6);
	tabTetro[1].push_back(6);

	tabTetro[2].push_back(0); //Création d'un tableau sans S ET Z
	tabTetro[2].push_back(1);
	tabTetro[2].push_back(2);
	tabTetro[2].push_back(3);
	tabTetro[2].push_back(4);
	//unsigned int POSITION = rand() % 6;

	tabTetroModify = tabTetro;


}

void Tetromino::initTetro(StructVar& sv)				// Initialisation des différentes pièces
{

	unsigned int choicetab = rand() % sv.tabTetroModify.size();

	unsigned int choiceform =rand() % sv.tabTetroModify[choicetab].size() ;

	if (sv.tabTetroModify[choicetab].size() > 0)
	{
		sv.tabTetroModify[choicetab].erase(sv.tabTetroModify[choiceform].begin() + choiceform);

		if (sv.tabTetroModify[choicetab].size() == 0)
		{
			sv.tabTetroModify.erase(sv.tabTetroModify.begin() + choicetab);
		}
		if (sv.tabTetroModify.size() == 0)
		{
			sv.tabTetroModify = sv.tabTetro;
		}
	}

	std::vector<carreau> Tetromin;
	carreau caro;

	for (unsigned int j = 0; j < 4; j++)
	{
		Tetromin.push_back(caro);
	}
	switch (sv.tabTetroModify[choicetab][choiceform]) 
	{
	case I:
		Tetromin[0].index_col = sv.grille[LARGEUR_GRILLE / 2][0].index_col;
		Tetromin[0].index_ligne = sv.grille[LARGEUR_GRILLE / 2][0].index_ligne;
										// Ligne plus importante pour affichage
		Tetromin[1].index_col = sv.grille[LARGEUR_GRILLE / 2][1].index_col;
		Tetromin[1].index_ligne = sv.grille[LARGEUR_GRILLE / 2][1].index_ligne;
		
		Tetromin[2].index_col = sv.grille[LARGEUR_GRILLE / 2][2].index_col;
		Tetromin[2].index_ligne = sv.grille[LARGEUR_GRILLE / 2][2].index_ligne;
	
		Tetromin[3].index_col = sv.grille[LARGEUR_GRILLE / 2][3].index_col;
		Tetromin[3].index_ligne = sv.grille[LARGEUR_GRILLE / 2][3].index_ligne;
		
		break;

	case O:
		Tetromin[0].index_col = sv.grille[LARGEUR_GRILLE / 2][0].index_col;
		Tetromin[0].index_ligne = sv.grille[LARGEUR_GRILLE / 2][0].index_ligne;
		
		Tetromin[1].index_col = sv.grille[LARGEUR_GRILLE / 2][1].index_col;
		Tetromin[1].index_ligne = sv.grille[LARGEUR_GRILLE / 2][1].index_ligne;
	
		Tetromin[2].index_col = sv.grille[LARGEUR_GRILLE / 2 - 1][0].index_col;
		Tetromin[2].index_ligne = sv.grille[LARGEUR_GRILLE / 2 - 1][0].index_ligne;
		
		Tetromin[3].index_col = sv.grille[LARGEUR_GRILLE / 2 - 1][1].index_col;
		Tetromin[3].index_ligne = sv.grille[LARGEUR_GRILLE / 2 - 1][1].index_ligne;

		break;

	case T:
		Tetromin[0].index_col = sv.grille[LARGEUR_GRILLE / 2][0].index_col;
		Tetromin[0].index_ligne = sv.grille[LARGEUR_GRILLE / 2][0].index_ligne;
	
		Tetromin[1].index_col = sv.grille[LARGEUR_GRILLE / 2][1].index_col;
		Tetromin[1].index_ligne = sv.grille[LARGEUR_GRILLE / 2][1].index_ligne;
		
		Tetromin[2].index_col = sv.grille[LARGEUR_GRILLE / 2][2].index_col;
		Tetromin[2].index_ligne = sv.grille[LARGEUR_GRILLE / 2][2].index_ligne;
		
		Tetromin[3].index_col = sv.grille[LARGEUR_GRILLE / 2 - 1][1].index_col;
		Tetromin[3].index_ligne = sv.grille[LARGEUR_GRILLE / 2 - 1][1].index_ligne;

		break;

	case L:
		Tetromin[0].index_col = sv.grille[LARGEUR_GRILLE / 2 - 1][0].index_col;
		Tetromin[0].index_ligne = sv.grille[LARGEUR_GRILLE / 2 -1][0].index_ligne;
	
		Tetromin[1].index_col = sv.grille[LARGEUR_GRILLE / 2 - 1][1].index_col;
		Tetromin[1].index_ligne = sv.grille[LARGEUR_GRILLE / 2 - 1][1].index_ligne;
	
		Tetromin[2].index_col = sv.grille[LARGEUR_GRILLE / 2][2].index_col;
		Tetromin[2].index_ligne = sv.grille[LARGEUR_GRILLE / 2][2].index_ligne;
		
		Tetromin[3].index_col = sv.grille[LARGEUR_GRILLE / 2][2].index_col;
		Tetromin[3].index_ligne = sv.grille[LARGEUR_GRILLE / 2][2].index_ligne;
	
		break;

	case J:
		Tetromin[0].index_col = sv.grille[LARGEUR_GRILLE / 2][0].index_col;
		Tetromin[0].index_ligne = sv.grille[LARGEUR_GRILLE / 2][0].index_ligne;
	
		Tetromin[1].index_col = sv.grille[LARGEUR_GRILLE / 2][1].index_col;
		Tetromin[1].index_ligne = sv.grille[LARGEUR_GRILLE / 2][1].index_ligne;
	
		Tetromin[2].index_col = sv.grille[LARGEUR_GRILLE / 2][2].index_col;
		Tetromin[2].index_ligne = sv.grille[LARGEUR_GRILLE / 2][2].index_ligne;
		
		Tetromin[3].index_col = sv.grille[LARGEUR_GRILLE / 2 -  1][2].index_col;
		Tetromin[3].index_ligne = sv.grille[LARGEUR_GRILLE / 2 - 1][2].index_ligne;
	
		break;

	case Z:
		Tetromin[0].index_col = sv.grille[LARGEUR_GRILLE / 2][0].index_col;
		Tetromin[0].index_ligne = sv.grille[LARGEUR_GRILLE / 2][0].index_ligne;

		Tetromin[1].index_col = sv.grille[LARGEUR_GRILLE / 2 - 1][0].index_col;
		Tetromin[1].index_ligne = sv.grille[LARGEUR_GRILLE / 2 - 1][0].index_ligne;
		
		Tetromin[2].index_col = sv.grille[LARGEUR_GRILLE / 2][1].index_col;
		Tetromin[2].index_ligne = sv.grille[LARGEUR_GRILLE / 2][1].index_ligne;
	
		Tetromin[3].index_col = sv.grille[LARGEUR_GRILLE / 2 + 1][1].index_col;
		Tetromin[3].index_ligne = sv.grille[LARGEUR_GRILLE / 2 + 1][1].index_ligne;
		
		break;

	case S:
		Tetromin[0].index_col = sv.grille[LARGEUR_GRILLE / 2][0].index_col;
		Tetromin[0].index_ligne = sv.grille[LARGEUR_GRILLE / 2][0].index_ligne;
		
		Tetromin[1].index_col = sv.grille[LARGEUR_GRILLE / 2 + 1][0].index_col;
		Tetromin[1].index_ligne = sv.grille[LARGEUR_GRILLE / 2 + 1][0].index_ligne;

		Tetromin[2].index_col = sv.grille[LARGEUR_GRILLE / 2][1].index_col;
		Tetromin[2].index_ligne = sv.grille[LARGEUR_GRILLE / 2][1].index_ligne;
	
		Tetromin[3].index_col = sv.grille[LARGEUR_GRILLE / 2 - 1][1].index_col;
		Tetromin[3].index_ligne = sv.grille[LARGEUR_GRILLE / 2 - 1][1].index_ligne;

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
