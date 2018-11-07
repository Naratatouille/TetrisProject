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


#include "IHM.h"
#include "Pac_Man_lib.h"
#include "Texture.h"


///////////////////////////// IHM //////////////////////////////
void IHM::initfile(const std::string& log) {
	std::ofstream logtxt(log);
	if (logtxt) {}
	else
		std::cout << std::endl << "ERREUR: Impossible d'ouvrir le fichier : " + log;
}
void IHM::logfileconsole(const std::string &msg) {
	const std::string logtxt = "log.txt";
	std::ofstream log(logtxt, std::ios::app);

	//std::time_t result = std::time(nullptr);
	//<< std::asctime(std::localtime(&result))

	if (log) {
		std::cout << std::endl << msg;
		log << std::endl << msg;
	}
	else
		std::cout << std::endl << "ERREUR: Impossible d'ouvrir le fichier : " << logtxt;
}
void IHM::logSDLError(std::ostream &os, const std::string &msg) {
	const std::string logtxt = "bin/log/log.txt";
	std::ofstream log(logtxt, std::ios::app);
	if (log) {
		os << msg << " error: " << SDL_GetError() << std::endl;
		log << msg << " error: " << SDL_GetError() << std::endl;
	}
	else
		std::cout << "ERREUR: Impossible d'ouvrir le fichier : " << logtxt << std::endl;
}
bool IHM::initsdl(SDL_Window*& window, SDL_Renderer*& renderer, TTF_Font* font[]) {
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cout << std::endl << "SDL could not initialize! SDL_Error: " << SDL_GetError();
		return false;
	}
	else {
		window = SDL_CreateWindow("Pacman",
			0, 0,
			SCREEN_WIDTH, SCREEN_HEIGHT,
			SDL_WINDOW_OPENGL);

		//	SDL_WINDOW_FULLSCREEN_DESKTOP or SDL_WINDOW_FULLSCREEN
		if (window == nullptr) {
			logSDLError(std::cout, "CreateWindow");
			SDL_Quit();
			return false;
		}
		else
			logfileconsole("CreateWindow Success");
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		//| SDL_RENDERER_PRESENTVSYNC
		if (renderer == nullptr) {
			logSDLError(std::cout, "CreateRenderer");
			SDL_DestroyWindow(window);
			SDL_Quit();
			return false;
		}
		else
			logfileconsole("CreateRenderer Success");

		if (TTF_Init() != 0) {
			logSDLError(std::cout, "TTF_Init");
			SDL_DestroyRenderer(renderer);
			SDL_DestroyWindow(window);
			SDL_Quit();
			return false;
		}
		else
			logfileconsole("TTF_Init Success");


		const std::string fontFile = "arial.ttf";

		for (Uint8 i = 1; i < MAX_FONT; i++)
			font[i] = TTF_OpenFont(fontFile.c_str(), i);

		logfileconsole("SDL_Init Success");
		return true;
	}
}
void IHM::initGrid(Map& map) {
	map.matriceMap.clear();
	Tile blankTile;
	std::vector<Tile> blank;
	for (Uint8 x = 0; x < map.map_length; x++) {
		map.matriceMap.push_back(blank);
		for (Uint8 y = 0; y < map.map_height; y++) {

			blankTile.indexX = x;
			blankTile.indexY = y;
			blankTile.tile_x = TILE_SIZE * x + (SCREEN_WIDTH / 2 - (map.map_length / 2 * TILE_SIZE));
			blankTile.tile_y = TILE_SIZE * y + (SCREEN_HEIGHT / 2 - (map.map_height / 2 * TILE_SIZE));
			if (x == 0 || x == map.map_length - 1 || y == 0 || y == map.map_height - 1) {
				blankTile.wall = true;
			}
			else {
				blankTile.wall = false;
			}
			map.matriceMap[x].push_back(blankTile);
		}
	}
}
void IHM::calculimage(Sysinfo& sysinfo) {
	logfileconsole("_calculimage Start_");

	std::string IPath = "image/";
	sysinfo.var.statescreen = STATEplay;
	sysinfo.var.select = selectnothing;
	Texture::loadImage(sysinfo.screen.renderer, sysinfo.allTextures.ground, sysinfo.var.statescreen, sysinfo.var.select,
		IPath + "tile32/Black.bmp", "Black.bmp", (Uint8)255, -1, -1, TILE_SIZE, TILE_SIZE);
	Texture::loadImage(sysinfo.screen.renderer, sysinfo.allTextures.ground, sysinfo.var.statescreen, sysinfo.var.select,
		IPath + "tile32/White.bmp", "White.bmp", (Uint8)255, -1, -1, TILE_SIZE, TILE_SIZE);
	

	// enum _Type : Uint8 { red, blue, yellow, green, brown };
	Texture::loadImage(sysinfo.screen.renderer, sysinfo.allTextures.color, sysinfo.var.statescreen, sysinfo.var.select,
		IPath + "tile32/Red.bmp", "Red.bmp", (Uint8)255, -1, -1, TILE_SIZE, TILE_SIZE);
	Texture::loadImage(sysinfo.screen.renderer, sysinfo.allTextures.color, sysinfo.var.statescreen, sysinfo.var.select,
		IPath + "tile32/Blue.bmp", "Blue.bmp", (Uint8)255, -1, -1, TILE_SIZE, TILE_SIZE);
	Texture::loadImage(sysinfo.screen.renderer, sysinfo.allTextures.color, sysinfo.var.statescreen, sysinfo.var.select,
		IPath + "tile32/Yellow.bmp", "Yellow.bmp", (Uint8)255, -1, -1, TILE_SIZE, TILE_SIZE);
	Texture::loadImage(sysinfo.screen.renderer, sysinfo.allTextures.color, sysinfo.var.statescreen, sysinfo.var.select,
		IPath + "tile32/Green.bmp", "Green.bmp", (Uint8)255, -1, -1, TILE_SIZE, TILE_SIZE);
	Texture::loadImage(sysinfo.screen.renderer, sysinfo.allTextures.color, sysinfo.var.statescreen, sysinfo.var.select,
		IPath + "tile32/Brown.bmp", "Brown.bmp", (Uint8)255, -1, -1, TILE_SIZE, TILE_SIZE);

	sysinfo.var.select = selectnothing;
	logfileconsole("_calculimage End_");
}
void IHM::alwaysrender(Sysinfo& sysinfo) {
	//clock_t t1, t2;
	//t1 = clock();

	switch (sysinfo.var.statescreen) {
	case STATEplay:
		SDL_RenderClear(sysinfo.screen.renderer);
		SDL_SetRenderDrawColor(sysinfo.screen.renderer, 128, 128, 128, 0xFF);

		afficherMap(sysinfo);

		calculTime(sysinfo.var.gameTime);
		Texte::writeTexte(sysinfo.screen.renderer, sysinfo.allTextes.font, blended,
			std::to_string(sysinfo.var.gameTime.hours) + ":"+ std::to_string(sysinfo.var.gameTime.minutes) + ":"
			+ std::to_string(sysinfo.var.gameTime.seconds), Black, NoColor, 24, SCREEN_WIDTH - 300, 0, center_x);

		
		for (unsigned int i = 0; i < sysinfo.tabForme.size(); i++)
			sysinfo.tabForme[i]->afficher(sysinfo.screen.renderer, sysinfo.allTextures.color);

		SDL_RenderPresent(sysinfo.screen.renderer);
		break;
	}

	//t2 = clock();
	//cout << endl << "temps d'execution de alwaysrender : " + to_string(((double)t2 - (double)t1) / CLOCKS_PER_SEC);
}
void IHM::afficherMap(Sysinfo& sysinfo) {
	
	for (Uint8 i = 0; i < sysinfo.map.map_length; i++) {
		for (Uint8 j = 0; j < sysinfo.map.map_height; j++) {
			if (sysinfo.map.matriceMap[i][j].wall)
				sysinfo.allTextures.ground[blackTile]->render(sysinfo.screen.renderer, sysinfo.map.matriceMap[i][j].tile_x, sysinfo.map.matriceMap[i][j].tile_y);
			else
				sysinfo.allTextures.ground[whiteTile]->render(sysinfo.screen.renderer, sysinfo.map.matriceMap[i][j].tile_x, sysinfo.map.matriceMap[i][j].tile_y);
				
		}
	}

}
void IHM::calculTime(GameTime& gameTime) {
	gameTime.frame = (gameTime.frame + 1) % 60;
	if (gameTime.frame == 0) {
		gameTime.seconds = (gameTime.seconds + 1) % 60;
		if (gameTime.seconds == 0) {
			gameTime.minutes = (gameTime.minutes + 1) % 60;
			if (gameTime.minutes == 0)
				gameTime.hours++;
		}
	}
}
void IHM::deleteAll(Sysinfo& sysinfo) {
	logfileconsole("*********_________ Start DeleteAll _________*********");

	for (Uint8 i = 1; i < MAX_FONT; i++)
		TTF_CloseFont(sysinfo.allTextes.font[i]);

	for (unsigned int i = 0; i < sysinfo.tabForme.size(); i++)
		delete sysinfo.tabForme[i];

	deleteDyTabPlayerAndTextures(sysinfo.allTextures.ground, "ground Texture");
	deleteDyTabPlayerAndTextures(sysinfo.allTextures.color, "color Texture");

	SDL_DestroyRenderer(sysinfo.screen.renderer);
	SDL_DestroyWindow(sysinfo.screen.window);
	sysinfo.screen.renderer = nullptr;
	sysinfo.screen.window = nullptr;
	logfileconsole("*********_________ End DeleteAll _________*********");
}

