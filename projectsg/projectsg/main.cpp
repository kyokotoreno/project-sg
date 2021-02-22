#include <projectsg/main.hpp>

Vector2 vector_a(750, 400);
Vector2 vector_b(70, 800);
Vector2 vector_target;

std::default_random_engine generator;
std::uniform_int_distribution<int> distribution_x(0, 1280);
std::uniform_int_distribution<int> distribution_y(0, 720);

auto dice_x = std::bind(distribution_x, generator);
auto dice_y = std::bind(distribution_y, generator);

bool AppSimStart = false;

void AppOnRender()
{  
    GuiRenderVector(&vector_a, 255, 128, 0);
    GuiRenderVector(&vector_b, 255, 0, 0);
    GuiRenderVector(&vector_target, 255, 0, 255);

    GuiRenderVectorAngle(&vector_a, &vector_b, 0, 128, 128);
    GuiRenderVectorAngle(&vector_target, &vector_a, 0, 255, 0);
    GuiRenderVectorAngle(&vector_target, &vector_b, 0, 0, 255);

    if (AppSimStart) {

        std::cout << "Step" << std::endl;

        Vector2::Lerp(&vector_a, &vector_b, 2.15f);
        Vector2::Lerp(&vector_b, &vector_target, 2.5f);

        ExternOutputString = "";

        ExternOutputString.append("\nMagnitude of Vector A: ");
        ExternOutputString.append(std::to_string(vector_a.magnitude()));
        ExternOutputString.append(" Magnitude of Vector B: ");
        ExternOutputString.append(std::to_string(vector_b.magnitude()));
        ExternOutputString.append(" Magnitude of Target Vector: ");
        ExternOutputString.append(std::to_string(vector_target.magnitude()));
    }

    if(vector_a.magnitude() == vector_target.magnitude())
    {
        std::cerr << "Target Reached" << std::endl;

        vector_a = Vector2(dice_x(), dice_y());
        vector_b = Vector2(dice_x(), dice_y());
        vector_target = Vector2(dice_x(), dice_y());
    }

    return;
}

int main(int argc, char** argv)
{
	std::cerr << "Project Steins Gate v0.1.0" << std::endl;

    GuiInitSDL(AppOnRender);

    enum GuiStatus AppGuiStatus;

    vector_target = Vector2(vector_b.x + 900, vector_a.y - 200);

    std::cerr << "Start" << std::endl;

    for(;;) {
        auto time = SDL_GetTicks();

        // Rendering and event handling
        AppGuiStatus = (GuiStatus)GuiEventHandler();

        if (AppGuiStatus == GUI_EVENT_QUIT) {
            std::cerr << "Quit" << std::endl;
            break;
        }
        else if (AppGuiStatus == GUI_EVENT_SIMSTART) {

            std::cerr << "Stop" << std::endl;

            AppSimStart = AppSimStart ? false : true;

            if (AppSimStart) {
                vector_a = Vector2(750, 400);
                vector_b = Vector2(70, 800);
                vector_target = Vector2(vector_b.x + 900, vector_a.y - 200);

                std::cerr << "Restart" << std::endl;
            }
        }

        if ((SDL_GetTicks() - time) < 10) {
            std::cerr << "Sleep" << std::endl;
            SDL_Delay(10);
        }
    }

	return 0;
}
