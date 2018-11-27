#ifndef TETROMINO_H
#define TETROMINO_H

#include "initialisation.h"

class Tetromino
{
public:
	Tetromino(int _type, std::vector<carreau>& _forme);
	Tetromino(const Tetromino&);
	~Tetromino();

	static void initTetro(StructVar& sv); //STATIC????

	static void initTabalea(std::vector<std::vector< unsigned int>>& tabTetro, std::vector<std::vector< unsigned int>>& tabTetroModify);

private:

	
	unsigned int type;
	std::vector<carreau> forme;
};


#endif