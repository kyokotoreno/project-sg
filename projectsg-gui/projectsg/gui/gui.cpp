#include <projectsg/gui/gui.hpp>

SDL_Event GuiSDLEvent;

SDL_Renderer* GuiRenderer = NULL;
SDL_Window* GuiWindow = NULL;
SDL_Surface* GuiWindowSurface = NULL;

int GuiInitSDL()
{

    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		std::cerr << "SDL could not initialize!\n\tSDL Error: " << SDL_GetError() << std::endl;
		return -1;
	}

	/*if (IMG_Init(IMG_INIT_PNG) == 0) {
		std::cerr << "SDL_image could not initialize!\n\tSDL_image Error: " << IMG_GetError() << std::endl;
		return -2;
	}
    */

	SDL_CreateWindowAndRenderer(1280, 720, SDL_WINDOW_SHOWN, &GuiWindow, &GuiRenderer);

	if (GuiWindow == NULL) {
		std::cerr << "Application Window could not be created!\n\tSDL Error: " << SDL_GetError() << std::endl;
		return -3;
	}

	if (GuiRenderer == NULL) {
		std::cerr << "Application Renderer could not be created!\n\tSDL Error: " << SDL_GetError() << std::endl;
        return -4;
	}

	GuiWindowSurface = SDL_GetWindowSurface(GuiWindow);

	if (GuiWindowSurface == NULL) {
		std::cerr << "Application Window Surface could not be retrieved!\n\tSDL Error: " << SDL_GetError() << std::endl;
        return -5;
	}

	SDL_SetWindowTitle(GuiWindow, "Project Steins Gate v0.1.0");
    SDL_SetWindowPosition(GuiWindow, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED);

    return 0;
}

void GuiEventHandler(enum GuiStatus* status)
{
    while(SDL_PollEvent(&GuiSDLEvent)) {
        if (GuiSDLEvent.type == SDL_QUIT) {
            *status = GUI_EVENT_QUIT;
        }
        else {
            *status = GUI_EVENT_NOTHING;
        }
    }

    SDL_SetRenderDrawColor(GuiRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(GuiRenderer);

    return;
}

void GuiRenderVector(Vector2* vector)
{
    

    return;
}
