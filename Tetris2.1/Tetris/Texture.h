#ifndef TEXTURE_H
#define TEXTURE_H


#include "initialisation.h"

class Texturer
{
	public:
		Texturer();
		~Texturer();
		Texturer(SDL_Texture* text, std::string mess, SDL_Rect pos);
		static bool loadfromfile(std::vector<Texturer*> &tabText,StructVar &sv,const std::string &name, unsigned int x, unsigned int y, unsigned int w = 0,unsigned int h=0);
		static bool loadfromrenderedtext(std::vector<Texturer*> &tabText, StructVar &sv, const std::string &textureText, SDL_Color textcolor, unsigned int x, unsigned int y,unsigned int w = 0, unsigned int h = 0);
		void free();
		void render(int x, int y,const std::string &nameText ,StructVar &sv);
		SDL_Rect Positionreturn();
		//Gets image dimensions
		int getWidth();
		int getHeight();

		//static void playgame();
	
	private:
		//The actual hardware texture
		SDL_Texture * mTexture;

		std::string msg;
		//Image dimensions
		SDL_Rect position;


};


#endif