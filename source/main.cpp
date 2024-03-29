#include <3rdparty.h>
#include <SceneManager.h>
#include <Intro.h>

//Screen dimension constants
const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 720;
const unsigned TARGETFPS = 60;
const char* WINDOWTITLE = "MyLD_template";
const int MAXFRAMESKIP = 5;

int main(int argc, char** argv)
{
	// SDL every System
	SDL_Init(SDL_INIT_EVERYTHING);

	// Create Window
	SDL_Window* w = SDL_CreateWindow(WINDOWTITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, 0);

	//Create Renderer
	SDL_Renderer* r = SDL_CreateRenderer(w, -1, 0/*SDL_RENDERER_PRESENTVSYNC*/);

	// SDL_mixer only OGG files
	Mix_Init(MIX_INIT_OGG);

	//SDL_image only PNG files
	IMG_Init(IMG_INIT_PNG);

	//SDL_ttf
	TTF_Init();

	//SDL_net
	SDLNet_Init();

	// Application State
	SDL_bool paused = SDL_FALSE, running = SDL_TRUE;

	// Timer
	Uint64 nextFrame = SDL_GetPerformanceCounter();
	float elapsedTime = 0;

	// SceneManager
	SceneManager* manager = new SceneManager();

	// Add Scenes
	manager->addScene(new Intro(), "Intro");

	// Set first Scene
	manager->setActive("Intro");


	// Game Loop
	while (running)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			switch (event.type)
			{
			case SDL_QUIT:
				running = SDL_FALSE;
				paused = SDL_TRUE;
				break;
			case SDL_WINDOWEVENT:
				switch (event.window.event)
				{
				case SDL_WINDOWEVENT_FOCUS_LOST:
					paused = SDL_TRUE;
					break;
				case SDL_WINDOWEVENT_FOCUS_GAINED:
					paused = SDL_FALSE;
					nextFrame = SDL_GetPerformanceCounter();
					break;
				}
			case SDL_KEYDOWN:
				// Input HERE
				manager->InputScene(&event);
				break;
			}

		}
		if (!paused && SDL_GetPerformanceCounter() >= nextFrame)
		{
			int framesSkipped = 0;
			do
			{
				// Update HERE
				manager->UpdateScene(&elapsedTime);

				nextFrame += SDL_GetPerformanceFrequency() / TARGETFPS; /* max fps */
			} while (SDL_GetPerformanceCounter() >= nextFrame && framesSkipped++ < MAXFRAMESKIP);/* maximum frames to skip */

			// ClearColor
			SDL_SetRenderDrawColor(r, 0x00, 0x00, 0x00, 0xFF);
			// Clear Screen
			SDL_RenderClear(r);

			// Rendering HERE
			manager->RenderScene(r);

			// Present
			SDL_RenderPresent(r);
		}
		else
			SDL_Delay(1); /* give back CPU time*/
	}

	// Shutdown
	SDLNet_Quit();
	TTF_Quit();
	Mix_Quit();
	IMG_Quit();
	SDL_DestroyRenderer(r);
	SDL_DestroyWindow(w);
	SDL_Quit();

	return 0;
}