/*

	Pac-Man
	Copyright SAUTER Robin and Joeffrey VILLERONCE 2018-2019 (robin.sauter@orange.fr)
	last modification on this file on version:0.14

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

#include "Entity.h"
#include "Pac_Man_lib.h"
#include "Texture.h"


///////////////////////////// ENTITY //////////////////////////////
/* ENTITY :: STATIC */
void Entity::move(Sysinfo& sysinfo) {

	if (sysinfo.var.statescreen == STATEplay && sysinfo.var.select == selectnothing) {

		sysinfo.var.modulo = (sysinfo.var.modulo + 1) % 60; // bouge vers le bas toute les secondes
		if (sysinfo.var.modulo == 0) {
			for (unsigned int i = 0; i < sysinfo.tabForme.size(); i++)
				sysinfo.tabForme[i]->translate(DOWN);
		}
	}
}
void Entity::createForme(std::vector<Entity*>& tabForme, Uint8 type, Uint8 color, Uint8 indexX, Uint8 indexY,
	std::vector<std::vector<Tile>> matriceMap){

	std::vector<carreaux> tabCarreaux;
	carreaux blankCarreaux;

	switch (type) {
	case I:
		for (unsigned int i = 0; i < 4; i++) {
			blankCarreaux.indexX = indexX + i;
			blankCarreaux.indexY = indexY;
			blankCarreaux.x = matriceMap[indexX + i][indexY].tile_x;
			blankCarreaux.y = matriceMap[indexX + i][indexY].tile_y;
			tabCarreaux.push_back(blankCarreaux);
		}
		break;
	case J:
		break;
	case L:
		break;
	case O:
		for (unsigned int i = 0; i < 4; i++) {
			if (i < 2) {
				blankCarreaux.indexX = indexX + i;
				blankCarreaux.indexY = indexY;
				blankCarreaux.x = matriceMap[indexX + i][indexY].tile_x;
				blankCarreaux.y = matriceMap[indexX + i][indexY].tile_y;
			}
			else {
				blankCarreaux.indexX = indexX + i - 2;
				blankCarreaux.indexY = indexY + 1;
				blankCarreaux.x = matriceMap[indexX + i - 2][indexY + 1].tile_x;
				blankCarreaux.y = matriceMap[indexX + i - 2][indexY + 1].tile_y;
			}
			
			tabCarreaux.push_back(blankCarreaux);
		}
		break;

		/*
		Todo
		
		*/
	}
	tabForme.push_back(new Entity(tabCarreaux, type, color));

}

/* ENTITY :: METHODES */
Entity::Entity(std::vector<carreaux>& tabCarreaux, Uint8 type, Uint8 color)
	: _tabCarreaux(tabCarreaux), _type(type), _color(color)
{
}
Entity::~Entity()
{
}

bool Entity::translate(Uint8 direction) {

	// TODO collision
	for (unsigned int i = 0; i < _tabCarreaux.size(); i++) {
		switch (direction) {
		case DOWN:
			_tabCarreaux[i].indexY++; 
			_tabCarreaux[i].y += TILE_SIZE;
			break;
		case LEFT:
			_tabCarreaux[i].indexX--;
			_tabCarreaux[i].x -= TILE_SIZE;
			break;
		case RIGHT:
			_tabCarreaux[i].indexX++;
			_tabCarreaux[i].x += TILE_SIZE;
			break;
		}
		
	}
	return true;
}

bool Entity::rotate(Uint8 direction) {
	return true;
}



std::vector<carreaux> Entity::GETtabCarreaux()const {
	return _tabCarreaux;
}
std::vector<carreaux>& Entity::GETtabCarreauxNONCONST() {
	return _tabCarreaux;
}
Uint8 Entity::GETtype()const {
	return _type;
}
Uint8 Entity::GETcolor()const {
	return _color;
}

void Entity::SETtabCarreaux(std::vector<carreaux>& tabCarreaux) {
	_tabCarreaux = tabCarreaux;
}
void Entity::SETtype(Uint8 type) {
	_type = type;
}
void Entity::SETcolor(Uint8 color) {
	_color = color;
}



void Entity::afficher(SDL_Renderer*& renderer, std::vector<Texture*> tabTexture) {
	for (unsigned int i = 0; i < _tabCarreaux.size(); i++)
		tabTexture[_color]->render(renderer, _tabCarreaux[i].x, _tabCarreaux[i].y);
}