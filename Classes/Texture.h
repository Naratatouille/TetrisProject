#ifndef TEXTURE_H
#define TEXTURE_H

#include "Constantes.h"

class Texturer
{
	public:
		Texturer();
		~Texturer();
		bool loadfromfile(std::string path, std::vector<SDL_Rect>& posimages);
		void free();
		void render(int x, int y);

		//Gets image dimensions
		int getWidth();
		int getHeight();
		static void playgame();
	
	private:
		//The actual hardware texture
		SDL_Texture * mTexture;


		//Image dimensions
		int ImWidth;
		int ImHeight;
		// On peut mettre SDL rect a la place
};


#endif