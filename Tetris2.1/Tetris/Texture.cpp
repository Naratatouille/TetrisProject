#include "Texture.h"
#include "Constantes.h"
//The surface contained by the window





//Loads media


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




/*bool loadMedia(StructVar &sv)
{
	//Loading success flag
	bool success = true;
	if (!gKeyPressSurfaces[KEY_PRESS_SURFACE_UP].loadfromfile((std::string)("Selected.png"),sv))
	{
		printf("Failed to load Selected.png");
		success = false;
	}
	if (!gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN].loadfromfile((std::string)("Selected.png"),sv))
	{
		printf("Failed to load Selected.png");
		success = false;
	}

	//Load Foo' texture
	if (!NewGameTexture.loadfromfile((std::string)("NewGame.png"),sv))
	{
		printf("Failed to load NewGame.png!\n");
		success = false;
	}

	//Load background texture
	if (!BackgroundTexture.loadfromfile((std::string)("BackgroundTest.png"),sv))
	{
		printf("Failed to load background texture image!\n");
		success = false;
	}

	if (!ScoreTexture.loadfromfile((std::string)("Scores.png"),sv))
	{
		printf("Failed to load Score.png! \n");
		success = false;
	}
	return success;
}*/
void close(StructVar &sv)
{
	/*//Free loaded images
	NewGameTexture.free();
	BackgroundTexture.free();
	ScoreTexture.free();*/

	//Destroy window	
	SDL_DestroyRenderer(sv.gRenderer);
	SDL_DestroyWindow(sv.gWindow);
	sv.gWindow = NULL;
	sv.gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

/*void Texturer::playgame()
{

	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if (!)
		{
			printf("Failed to load media!\n");
		}
		else
		{
			//Main loop flag
			bool quit = false;

			//Event handler
			SDL_Event e;

			//While application is running
			while (!quit)
			{
				//Handle events on queue
				while (SDL_PollEvent(&e) != 0)
				{
					//User requests quit
					if (e.type == SDL_QUIT)
					{
						quit = true;
					}
					else if (e.key.keysym.sym)
					{
	
						switch (e.key.keysym.sym)
						{
						case SDLK_UP:
							CurrentTexture = gKeyPressSurfaces[KEY_PRESS_SURFACE_UP];
							CurrentTexture2 = ScoreTexture;
							break;

						case SDLK_DOWN:
							CurrentTexture2 = gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN];
							CurrentTexture = NewGameTexture;
							break;
						}

					}
				}

				//Clear screen
				SDL_SetRenderDrawColor(sv.gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(sv.gRenderer);
				//Render background texture to screen
				BackgroundTexture.render(0, 0);

				//Render NewGame to the screen
				NewGameTexture.render(200, 140);
				CurrentTexture.render(200, 140);
				//Render Score to the screen
				ScoreTexture.render(200, 250);

				CurrentTexture2.render(200, 250);
			
				//Update screen
				SDL_RenderPresent(sv.gRenderer);
			}
			BackgroundTexture.render(0, 0);
			SDL_RenderPresent(gRenderer);
		}
	}

	//Free resources and close SDL
	close(&sv);
}*/