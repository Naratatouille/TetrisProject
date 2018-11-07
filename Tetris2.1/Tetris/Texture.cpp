#include "Texture.h"
#include "Constantes.h"

//Frees media and shuts down SDL
void close(StructVar &sv);

Texturer::Texturer() : mTexture(nullptr),position(Positionreturn()), msg("")
{
}
Texturer::Texturer(SDL_Texture* text, std::string mess, SDL_Rect pos) : mTexture(text),msg(mess), position(pos)
{
}

SDL_Rect Texturer::Positionreturn()
{
	SDL_Rect rect;
	rect.x = 0;
	return rect;
}

Texturer::~Texturer()
{
	free();
}

void Texturer::free()
{
	//Free texture if it exists
	if (mTexture != NULL)
	{
		SDL_DestroyTexture(mTexture);
		mTexture = NULL;
	}
}




bool Texturer::loadfromfile(std::vector<Texturer*> &tabText,StructVar &sv,const std::string &name,unsigned int x, unsigned int y, unsigned int w, unsigned int h)
{

	//The final texture
	SDL_Texture* newTexture = NULL;
	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(name.c_str());
	
	SDL_Rect posi;
	posi.x = x;
	posi.y = y;

	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", name.c_str(), IMG_GetError());
	}
	else
	{
		//Color key image
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(sv.gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", name.c_str(), SDL_GetError());
		}
		else
		{
			//Get image dimensions
			if (w == 0 && h == 0)
			{
				posi.w = loadedSurface->w;
				posi.h = loadedSurface->h;
			}
			else
			{
				posi.w = w;
				posi.h = h;
			}
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	tabText.push_back(new Texturer(newTexture, name, posi));
	return false;
}

bool Texturer::loadfromrenderedtext(std::vector<Texturer*>& tabText, StructVar & sv, const std::string & textureText, SDL_Color textcolor, unsigned int x, unsigned int y, unsigned int w, unsigned int h)
{
	
	SDL_Texture* newText = NULL;
	SDL_Surface* textSurface = TTF_RenderText_Solid(sv.gFont, textureText.c_str(), textcolor);
	SDL_Rect posit;
	posit.x = x;
	posit.y = y;

	if (textSurface == NULL)
	{
		printf("Unable to render text surface ! SDL_ttf ERROR : %s \n", TTF_GetError());
	}
	else
	{
		newText = SDL_CreateTextureFromSurface(sv.gRenderer, textSurface);
		if (newText == NULL)
		{
			printf("Unable to create texture fro rendered text ! SDL_Error : %s \n", SDL_GetError());

		}
		else
		{
			if (w == 0 && h == 0)
			{
				posit.w = textSurface->w;
				posit.h = textSurface->h;
			}
			else
			{
				posit.w = w;
				posit.h = h;
			}
		}

		SDL_FreeSurface(textSurface);
	}
	tabText.push_back(new Texturer(newText, textureText, posit));
	return false;
}


void Texturer::render(int x, int y,const std::string &nameText, StructVar &sv)
{
	//Set rendering space and render to screen
	position.x = x;
	position.y = y;
	if (msg.compare(nameText) == 0)
	{
		SDL_RenderCopy(sv.gRenderer, mTexture, NULL, &position);
	}
	
}

int Texturer::getWidth()
{
	return position.w;
}

int Texturer::getHeight()
{
	return position.h;
}


void close(StructVar &sv)
{


	//Destroy window	
	SDL_DestroyRenderer(sv.gRenderer);
	SDL_DestroyWindow(sv.gWindow);
	sv.gWindow = NULL;
	sv.gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}