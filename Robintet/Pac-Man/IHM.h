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

#ifndef IHM_H
#define IHM_H

#include "lib.h"

class IHM {
public:
	// initialisation des fichiers
	static void initfile(const std::string& log);

	// permet de d'écrire sur la console ainsi que dans le fichier log.txt
	static void logfileconsole(const std::string &msg);

	static void logSDLError(std::ostream &os, const std::string &msg);

	/*
		initialisation de la fenetre, du renderer et du tableau contenant les polices d'ecriture
		retourne true si aucune erreur n'est survenue
		retourne false si une erreur est survenue
	*/
	static bool initsdl(SDL_Window*&, SDL_Renderer*&, TTF_Font*[]);
	
	// Initialisation d'un niveau unique de Pacman
	static void initGrid(Map& map);
	
	/*
		Chargement Textures en fonction de l'ecran (menu, play, score):
		 -> des images
		 -> des boutons
		 -> des textes
	*/
	static void calculimage(Sysinfo&);

public:

	/*
		Affiche toutes les textures ainsi que les boutons ayant l'attribut _statescreen == STATEplay
		Cette fonction est appelée à la meme fréquence que la boucle principale
	*/
	static void alwaysrender(Sysinfo& syinfo);

	/*
		Affiche la map du niveau chargé :
		-> murs
		-> couloir
		-> bonus
	*/
	static void afficherMap(Sysinfo& sysinfo);

	/*
		Affiche le temps passé depuis le début du New Game
		Compte sur le fait que la boucle fonctionne à la fréquence de l'écran (ici 60Hz)
		si la boucle principale prend plus que 1/60 s alors le temps affiché sera décalé
	*/
	static void calculTime(GameTime& gameTime);



public:
	// Destruction des allocations dynamiques et de la fenetre
	static void deleteAll(Sysinfo&);
};
template<class T>
T max(T& a, T& b) {
	if (a >= b)
		return a;
	else
		return b;
}
template<class T>
void deleteDyTabPlayerAndTextures(T& dytab, const std::string& name) {
	unsigned int size = dytab.size();
	for (unsigned int i = 0; i < size; i++) {
		IHM::logfileconsole("Delete " + name + " name = " + dytab[i]->GETname() + " Success");
		delete dytab[i];
		dytab[i] = nullptr;
	}
	for (unsigned int i = 0; i < size; i++)
		dytab.pop_back();
	if (dytab.size() != 0)
		IHM::logfileconsole("___________ERROR : " + name + ".size() != 0");
	else
		IHM::logfileconsole("Delete ALL " + name + " Success");
}


#endif
