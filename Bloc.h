#ifndef BLOC_H
#define BLOC_H

#include <SDL.h>
#include <stdio.h>
#include <iostream>

class Bloc
{
public:
	// Constructeurs 

	Bloc();
	Bloc(int _X, int _Y, int _col);
	Bloc(const Bloc&);
	~Bloc();

	// Get des propriétés de la classe

	int getWidth();
	int getHeight();
	int getColor();
	int getXposition();
	int getYposition();

	void BlockDisp() const;					// Affichage d'un bloc

private:
	int width;								// Largeur d'un bloc
	int height;								// Hauteur 
	int color;								// Couleur 
	int xposition;							// Position x
	int yposition;							// position y 
	int index;								// Servira a l'indexation
};

void Test_Bloc();
#endif