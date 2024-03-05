#include "Simulate.h"
#include "bits/stdc++.h"
#include "unistd.h"

using namespace std;

Simulate::Simulate(){
    w = 800;
    h = 600;
    SDL_CreateWindowAndRenderer(w, h, 0, &window, &renderer);
    SDL_SetWindowTitle(window, "Gravity Simulation");
    //p.push_back(sun);
}

void Simulate::getPlanets(){
    bool q = 0;
    while(!q){
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
            case SDL_MOUSEBUTTONDOWN:
                if(event.button.button == SDL_BUTTON_LEFT){
                    Planet *p1 = new Planet(event.button.x, event.button.y, 1000, 5, 0);
                    p.push_back(p1);
                }
                else if(event.button.button==SDL_BUTTON_RIGHT){
                    q=1;
                }
            }
        }
        drawPlanets();
        SDL_Delay(10);
    }
}

void Simulate::drawPlanets(){
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    for(auto planet : p){
        planet->draw(renderer);
    }
    SDL_RenderPresent(renderer);
}

void Simulate::run(){
    getPlanets();
    while(!quit){
        for(auto planet : p){
            for(auto planet1 : p){
                planet->calcAttraction(planet1);
            }
        }
        drawPlanets();
        SDL_Event event;
        while (SDL_PollEvent(&event)) {
            switch (event.type) {
                case SDL_QUIT:
                    quit = 1;
                    break;
            }
        }
        SDL_Delay(10);
    }
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

Simulate::~Simulate()
{
    //dtor
}
