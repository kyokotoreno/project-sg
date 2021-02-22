#pragma once

#include <iostream>
#include <SDL.h>
//#include <SDL2/SDL_image.h>

#include <projectsg/physics/vectors.hpp>

extern SDL_Event GuiSDLEvent;

extern SDL_Renderer* GuiRenderer;
extern SDL_Window* GuiWindow;
extern SDL_Surface* GuiWindowSurface;

enum GuiStatus {
    GUI_EVENT_NOTHING = 0,
    GUI_EVENT_QUIT
};

/**
 * @brief Initialize SDL.
 * 
 * @return A non-zero value on error.
 */
extern int GuiInitSDL();

/**
 * \brief Handle SDL Events.
 * 
 * \param GuiStatus* status (A pointer to a GuiStatus variable, used to determine the result of the event handling)
 * \return void
 */
extern void GuiEventHandler(enum GuiStatus* event);

extern void GuiRenderVector(Vector2* vector);
