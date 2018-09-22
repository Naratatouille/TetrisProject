#ifndef TEXTURE_H
#define TEXTURE_H
#include <ctime>
#include <cmath>
#include <vector>
#include <exception>
#include <stdexcept>
#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <iostream>
#include "SDL2-2.0.8/include/SDL.h"
#include "SDL2-2.0.8/include/SDL_ttf.h"
#include "SDL2-2.0.8/include/SDL_image.h"

const int SCREEN_WIDTH = 640;
const int SCREEN_HEIGHT = 480;

class Texturer
{
	public:
		Texturer();
		~Texturer();
		bool loadfromfile(std::string path);
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

};


#endif