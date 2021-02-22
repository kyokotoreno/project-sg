#include <projectsg/gui/gui.hpp>

SDL_Event GuiSDLEvent;

SDL_Renderer* GuiRenderer = NULL;
SDL_Window* GuiWindow = NULL;
SDL_Surface* GuiWindowSurface = NULL;
SDL_Rect TextRect;
TTF_Font* GuiFont = NULL;

std::string ExternOutputString;

bool currentViewport = true; // true = 1, false = 2

SDL_Rect viewport1;
SDL_Rect viewport2;

SDL_Texture* TextTexture;

void(*AppOnRenderCallback)();

void GuiSwitchViewport()
{
    if (currentViewport) {
        SDL_RenderSetViewport(GuiRenderer, &viewport2);
    }
    else {
        SDL_RenderSetViewport(GuiRenderer, &viewport1);
    }

    currentViewport = currentViewport ? false : true;

    return; 
}

void GuiChangeRenderedText()
{
    SDL_DestroyTexture(TextTexture);

    SDL_Color color;

    color.a = 255;
    color.b = 0;
    color.g = 0;
    color.r = 242;

    std::string newText = "Project Steins;Gate v0.1.0 | 0.5112354";

    newText.append(" ");
    newText.append(ExternOutputString);

    //Render text surface
    SDL_Surface* textSurface = TTF_RenderText_Solid(GuiFont, newText.c_str(), color);

    if(textSurface == NULL) {
        std::cerr << "Unable to render text surface! SDL_ttf Error: " << TTF_GetError() << std::endl;
    }
    else {
        //Create texture from surface pixels
        TextTexture = SDL_CreateTextureFromSurface(GuiRenderer, textSurface);
        
        if (TextTexture == NULL) {
            std::cerr << "Unable to create texture from rendered text! SDL Error: " << SDL_GetError() << std::endl;
        }

        TextRect.w = textSurface->w;
        TextRect.h = textSurface->h;
        TextRect.x = 0;
        TextRect.y = 0;

        //Get rid of old surface
        SDL_FreeSurface(textSurface);
    }

    return;
}

void GuiTextOnRender()
{
    GuiSwitchViewport();

    GuiChangeRenderedText();
    SDL_RenderCopy(GuiRenderer, TextTexture, NULL, &TextRect);

    GuiSwitchViewport();

    return;
}

void GuiRenderVector(Vector2* vector, Uint8 r, Uint8 g, Uint8 b)
{
    filledCircleRGBA(GuiRenderer, (Sint16)vector->x, (Sint16)vector->y, 6, r, g, b , 255);
 
    return;
}

void GuiRenderVectorAngle(Vector2* from, Vector2* to, Uint8 r, Uint8 g, Uint8 b)
{
    trigonRGBA(GuiRenderer, (Sint16)from->x, (Sint16)from->y, (Sint16)to->x, (Sint16)to->y, (Sint16)from->x, (Sint16)to->y, r, g, b, 242);

    return;
}

int GuiEventHandler()
{

    GuiStatus GuiEventStatus = GUI_EVENT_NOTHING;

    while(SDL_PollEvent(&GuiSDLEvent)) {
        if (GuiSDLEvent.type == SDL_QUIT) {
            GuiEventStatus = GUI_EVENT_QUIT;
        }
        if (GuiSDLEvent.type == SDL_KEYDOWN) {
            switch(GuiSDLEvent.key.keysym.sym) {
                case SDLK_ESCAPE:
                    GuiEventStatus = GUI_EVENT_QUIT;
                    break;
                case SDLK_SPACE:
                    GuiEventStatus = GUI_EVENT_SIMSTART;
                    break;
            }
        }
    }

    SDL_SetRenderDrawColor(GuiRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    SDL_RenderClear(GuiRenderer);

    AppOnRenderCallback();
    GuiTextOnRender();

    SDL_RenderPresent(GuiRenderer);

    return (int)GuiEventStatus;
}

int GuiInitSDL(void(*OnRenderCallback)())
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

   //Initialize SDL_ttf
    if(TTF_Init() == -1)
    {
        std::cerr << "SDL_ttf could not initialize! SDL_ttf Error: " << TTF_GetError() << std::endl;
        return -2;
    }

    GuiFont = TTF_OpenFont("nixie.ttf", 24);
    if(GuiFont == NULL)
    {
        std::cerr << "Failed to load lazy font! SDL_ttf Error: " << TTF_GetError() << std::endl;
        return -2;
    }

	SDL_CreateWindowAndRenderer(1450, 980, SDL_WINDOW_SHOWN, &GuiWindow, &GuiRenderer);

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

    AppOnRenderCallback = OnRenderCallback;

    viewport1.x = 0;
    viewport1.y = 0;
    viewport1.w = 1450;
    viewport1.h = 880;
    
    viewport2.x = 0;
    viewport2.y = 880;
    viewport2.w = 1450;
    viewport2.h = 100;

    SDL_RenderSetViewport(GuiRenderer, &viewport1);

    GuiChangeRenderedText();

    GuiTextOnRender();

    return 0;
}

int GuiCloseSDL()
{
    GuiWindowSurface = NULL;
    SDL_DestroyRenderer(GuiRenderer);
    SDL_DestroyWindow(GuiWindow);

    GuiRenderer = NULL;
    GuiWindow = NULL;

    TTF_Quit();
    SDL_Quit();

    return 0;
}
