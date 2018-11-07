#ifndef TETROMINO_H
#define TETROMINO_H

#include "initialisation.h"

class Tetromino
{
public:
	Tetromino();
	Tetromino(int _forme, int _color);
	Tetromino(const Tetromino&);
	~Tetromino();

	void initTetro(StructVar& sv);

private:

	int color;
	int type;
	std::vector<carreau> forme;
	
};
void Test_Forme();

#endif