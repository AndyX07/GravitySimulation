#ifndef _SIMULATE_H_
#define _SIMULATE_H_

#include <SDL2/SDL.h>
#include <vector>
#include "Planet.h"

class Simulate {
    public:
        Simulate();
        ~Simulate();
        void getPlanets();
        void drawPlanets();
        void run();
    private:
        int w;
        int h;
        SDL_Renderer* renderer;
        SDL_Window* window;
        bool quit;
        std::vector<Planet*> p;
};

#endif
