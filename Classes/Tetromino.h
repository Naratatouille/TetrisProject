#ifndef TETROMINO_H
#define TETROMINO_H

#include "Constantes.h"
#include "Bloc.h"

class Tetromino
{
public:
	Tetromino();
	Tetromino(int _forme, int _color);
	Tetromino(const Tetromino&);
	~Tetromino();

	void TetroDisp(StructVar& sv) const;					// Affichage d'un bloc

private:

	Bloc A;
	Bloc B;
	Bloc C;
	Bloc D;
	int color;
	int forme;
};
void Test_Forme();

#endif