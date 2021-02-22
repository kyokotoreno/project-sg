#pragma once

#include <iostream>
#include <string>
#include <SDL2/SDL.h>
#include <SDL2/SDL2_gfxPrimitives.h>
#include <SDL2/SDL_ttf.h>
//#include <SDL2/SDL_image.h>

#include <projectsg/physics/vectors.hpp>

extern SDL_Event GuiSDLEvent;

extern SDL_Renderer* GuiRenderer;
extern SDL_Window* GuiWindow;
extern SDL_Surface* GuiWindowSurface;
extern TTF_Font* GuiFont;

extern std::string ExternOutputString;

/**
 * \brief Enum for gui statuses.
 */
enum GuiStatus {
    GUI_EVENT_NOTHING = 0,
    GUI_EVENT_QUIT,
    GUI_EVENT_SIMSTART
};

/**
 * @brief Initialize SDL.
 * 
 * @return A non-zero value on error.
 */
extern int GuiInitSDL(void(*OnRenderCallback)());

extern int GuiCloseSDL();

/**
 * \brief Handle SDL Events.
 * 
 * \param GuiStatus* status (A pointer to a GuiStatus variable, used to determine the result of the event handling)
 * \return void
 */
extern int GuiEventHandler();

extern void GuiChangeRenderedText(std::string newText);

extern void GuiRenderVector(Vector2* vector, Uint8 r, Uint8 g, Uint8 b);
extern void GuiRenderVectorAngle(Vector2* from, Vector2* to, Uint8 r, Uint8 g, Uint8 b);
