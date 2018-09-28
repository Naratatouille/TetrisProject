#include "Texture.h"
//The window renderer
SDL_Renderer* gRenderer = NULL;
//The window we'll be rendering to
SDL_Window* gWindow = NULL;

//The surface contained by the window
SDL_Surface* gScreenSurface = NULL;
enum KeyPressSurfaces
{
	KEY_PRESS_SURFACE_DEFAULT,
	KEY_PRESS_SURFACE_UP,
	KEY_PRESS_SURFACE_DOWN,
	KEY_PRESS_SURFACE_LEFT,
	KEY_PRESS_SURFACE_RIGHT,
	KEY_PRESS_SURFACE_TOTAL
};
//The images that correspond to a keypress
Texturer gKeyPressSurfaces[KEY_PRESS_SURFACE_TOTAL];

Texturer BackgroundTexture;
Texturer NewGameTexture;
Texturer ScoreTexture;
Texturer CurrentTexture;
Texturer CurrentTexture2;
Texturer CurrentTexturedefault;
//The window renderer
//SDL_Renderer* gRenderer = NULL;
//The window we'll be rendering to
//SDL_Window* gWindow = NULL;


bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

Texturer::Texturer() : mTexture(nullptr),position(Positionreturn())
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




bool Texturer::loadfromfile(std::string path)
{
	//Get rid of preexisting texture
	free();

	//The final texture
	SDL_Texture* newTexture = NULL;

	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		printf("Unable to load image %s! SDL_image Error: %s\n", path.c_str(), IMG_GetError());
	}
	else
	{
		//Color key image
		SDL_SetColorKey(loadedSurface, SDL_TRUE, SDL_MapRGB(loadedSurface->format, 0, 0xFF, 0xFF));

		//Create texture from surface pixels
		newTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (newTexture == NULL)
		{
			printf("Unable to create texture from %s! SDL Error: %s\n", path.c_str(), SDL_GetError());
		}
		else
		{
			//Get image dimensions
			position.w = loadedSurface->w;
			position.h = loadedSurface->h;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	//Return success
	mTexture = newTexture;
	return mTexture != NULL;
}

void Texturer::render(int x, int y)
{
	//Set rendering space and render to screen
	position.x = x;
	position.y = y;

	SDL_RenderCopy(gRenderer, mTexture, NULL, &position);
}

int Texturer::getWidth()
{
	return position.w;
}

int Texturer::getHeight()
{
	return position.h;
}




bool init()
{
	//Initialization flag
	bool success = true;

	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}
	else
	{
		//Set texture filtering to linear
		if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1"))
		{
			printf("Warning: Linear texture filtering not enabled!");
		}

		//Create window
		gWindow = SDL_CreateWindow("Tetris", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
		if (gWindow == NULL)
		{
			printf("Window could not be created! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
		else
		{
			//Create renderer for window
			gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
			if (gRenderer == NULL)
			{
				printf("Renderer could not be created! SDL Error: %s\n", SDL_GetError());
				success = false;
			}
			else
			{
				//Initialize renderer color
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

				//Initialize PNG loading
				int imgFlags = IMG_INIT_PNG;
				if (!(IMG_Init(imgFlags) & imgFlags))
				{
					printf("SDL_image could not initialize! SDL_image Error: %s\n", IMG_GetError());
					success = false;
				}
			}
		}
	}

	return success;
}

bool loadMedia()
{
	//Loading success flag
	bool success = true;
	if (!gKeyPressSurfaces[KEY_PRESS_SURFACE_UP].loadfromfile("Selected.png"))
	{
		printf("Failed to load Selected.png");
		success = false;
	}
	if (!gKeyPressSurfaces[KEY_PRESS_SURFACE_DOWN].loadfromfile("Selected.png"))
	{
		printf("Failed to load Selected.png");
		success = false;
	}

	//Load Foo' texture
	if (!NewGameTexture.loadfromfile("NewGame.png"))
	{
		printf("Failed to load NewGame.png!\n");
		success = false;
	}

	//Load background texture
	if (!BackgroundTexture.loadfromfile("BackgroundTest.png"))
	{
		printf("Failed to load background texture image!\n");
		success = false;
	}

	if (!ScoreTexture.loadfromfile("Scores.png"))
	{
		printf("Failed to load Score.png! \n");
		success = false;
	}
	return success;
}
void close()
{
	//Free loaded images
	NewGameTexture.free();
	BackgroundTexture.free();
	ScoreTexture.free();

	//Destroy window	
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	//Quit SDL subsystems
	IMG_Quit();
	SDL_Quit();
}

void Texturer::playgame()
{

	//Start up SDL and create window
	if (!init())
	{
		printf("Failed to initialize!\n");
	}
	else
	{
		//Load media
		if (!loadMedia())
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
				SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);
				SDL_RenderClear(gRenderer);
				//Render background texture to screen
				BackgroundTexture.render(0, 0);

				//Render NewGame to the screen
				NewGameTexture.render(200, 140);
				CurrentTexture.render(200, 140);
				//Render Score to the screen
				ScoreTexture.render(200, 250);

				CurrentTexture2.render(200, 250);
			
				//Update screen
				SDL_RenderPresent(gRenderer);
			}
			BackgroundTexture.render(0, 0);
			SDL_RenderPresent(gRenderer);
		}
	}

	//Free resources and close SDL
	close();
}