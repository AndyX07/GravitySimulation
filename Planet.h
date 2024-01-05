#ifndef _PLANET_H_
#define _PLANET_H_

#include <SDL2/SDL.h>

using namespace std;

class Planet {
    public:
        Planet(float x1, float y1, float m, float rad, bool sun);
        ~Planet();
        float getX();
        float getY();
        float getR();
        float getMass();
        void drawRect(SDL_Renderer *renderer, int x1, int y1, int radius);
        void drawCircle(SDL_Renderer *renderer, int x, int y, int radius);
        void calcAttraction(Planet *other);
        void draw(SDL_Renderer *renderer);
    private:
        float x;
        float y;
        float r;
        float mass;
        bool s;
        float x_v;
        float y_v;
};

#endif
