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

#ifndef Entity_H
#define Entity_H

#include "lib.h"

struct carreaux {
	// position en x sur la fenetre
	unsigned int x;

	// position en y sur la fenetre
	unsigned int y;

	// index de la case en x map[x][y]
	Uint8 indexX;

	// index de la case en y map[x][y]
	Uint8 indexY;
};


// classe abstraite
class Entity { 
public:
	// demande un mouvement de tous les objets Entity
	static void move(Sysinfo& sysinfo);

	// crée la forme 
	static void createForme(std::vector<Entity*>& tabForme, Uint8 type, Uint8 color, Uint8 indexX, Uint8 indexY,
		std::vector<std::vector<Tile>> matriceMap);

public: // constructeurs et destructeur
	Entity(std::vector<carreaux>& tabCarreaux, Uint8 type, Uint8 color);
	~Entity();


public: // opérations sur l'objet
	
	bool translate(Uint8 direction);

	bool rotate(Uint8 direction);

public: // affichage
	void afficher(SDL_Renderer*& renderer, std::vector<Texture*> tabTexture);

public: // assesseurs
	std::vector<carreaux> GETtabCarreaux()const;
	std::vector<carreaux>& GETtabCarreauxNONCONST();
	Uint8 GETtype()const;
	Uint8 GETcolor()const;

	void SETtabCarreaux(std::vector<carreaux>& tabCarreaux);
	void SETtype(Uint8 type);
	void SETcolor(Uint8 color);

private:
	std::vector<carreaux> _tabCarreaux;
	Uint8 _type;
	Uint8 _color;
};

#endif // !Entity_H

