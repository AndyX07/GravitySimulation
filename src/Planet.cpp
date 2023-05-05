#include "Planet.h"
#include "bits/stdc++.h"
#include "SDL.h"

using namespace std;

Planet::Planet(double x1, double y1, double m, double rad, bool sun)
{
    x=x1;
    y=y1;
    r=rad;
    mass = m;
    s=sun;
}

double Planet::getX(){
    return x;
}
double Planet::getY(){
    return y;
};
double Planet::getR(){
    return r;
};
double Planet::getMass(){
    return mass;
}
void Planet::drawRect(SDL_Renderer *renderer, int x1, int y1, int radius){
    if(!s){
        SDL_SetRenderDrawColor(renderer,255, 255, 255, 255);
    }
    else{
        SDL_SetRenderDrawColor(renderer, 214, 123, 19, 255);
    }
    SDL_Rect rect;
    rect.x = x1-radius/2;
    rect.y = y1-radius/2;
    rect.w = radius;
    rect.h = radius;
    SDL_RenderFillRect(renderer, &rect);
}

void Planet::drawCircle(SDL_Renderer *renderer, int x, int y, int radius){
    if(!s){
        SDL_SetRenderDrawColor(renderer,255, 255, 255, 255);
    }
    else{
        SDL_SetRenderDrawColor(renderer, 214, 123, 19, 255);
    }
    for (int w = 0; w < radius * 2; w++)
    {
        for (int h = 0; h < radius * 2; h++)
        {
            int dx = radius - w; // horizontal offset
            int dy = radius - h; // vertical offset
            if ((dx*dx + dy*dy) <= (radius * radius))
            {
                SDL_RenderDrawPoint(renderer, x + dx, y + dy);
            }
        }
    }
}

void Planet::calcAttraction(Planet *other){
    if(this==other){
        return;
    }
    double x1 = other->getX();
    double y1 = other->getY();
    double distX = x-x1;
    double distY = y-y1;
    double dist = sqrt(distX*distX + distY*distY);
    double force = (-1*gravitational_constant*mass*(other->getMass()))/(dist*dist);
    double acc = force/mass;
    double theta;
    if(abs(x-x1)<8 && y>y1 && abs(y-y1)<8){
        theta = M_PI/2;
    }
    else if(abs(x-x1)<8 && y<y1 && abs(y-y1)<8){
        theta = M_PI*3/2;
    }
    else{
        theta = atan(distY/distX);
    }
    if(x < x1){
        x_v -= acc*cos(theta);
        y_v -= acc*sin(theta);
    }
    else{
        x_v += acc*cos(theta);
        y_v += acc*sin(theta);
    }
    x+=x_v;
    y+=y_v;
}

void Planet::draw(SDL_Renderer *renderer){
    drawCircle(renderer, (int)x, (int)y, (int)r);
}

Planet::~Planet()
{
    //dtor
}
