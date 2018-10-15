#ifndef BLOC_H
#define BLOC_H

#include "initialisation.h"

class Bloc
{
public:
	// Constructeurs 

	Bloc();
	Bloc(int _X, int _Y, int _col);
	Bloc(const Bloc&);
	~Bloc();

	// Get des propriétés de la classe

	int getWidth() const;
	int getHeight() const;
	int getColor() const;
	int getXposition() const;
	int getYposition() const;

	void setColor(int _c);
	void setXposition(int _x);
	void setYposition(int _y);

	void BlockDisp(int _x, int _y) const;					// Affichage d'un bloc

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