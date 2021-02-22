#include <projectsg/main.hpp>

Vector2 vector_a;

int main(int argc, char** argv)
{
	std::cerr << "Project Steins Gate v0.1.0" << std::endl;

    GuiInitSDL();

    enum GuiStatus AppGuiStatus;

    while(1) {
        GuiEventHandler(&AppGuiStatus);

        if (AppGuiStatus == GUI_EVENT_QUIT) {
            return 0;
        }
    }

	return 0;
}
