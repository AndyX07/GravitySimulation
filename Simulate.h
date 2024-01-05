#ifndef _SIMULATE_H_
#define _SIMULATE_H_

#include "/usr/include/SDL2/SDL.h"
#include "Planet.h"
#include <vector>

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