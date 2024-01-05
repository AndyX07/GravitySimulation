#include "Planet.h"
#include "bits/stdc++.h"
#include "params.h"

using namespace std;

Planet::Planet(float x1, float y1, float m, float rad, bool sun)
{
    x=x1;
    y=y1;
    r=rad;
    mass = m;
    s=sun;
}

float Planet::getX(){
    return x;
}
float Planet::getY(){
    return y;
};
float Planet::getR(){
    return r;
};
float Planet::getMass(){
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
    float x1 = other->getX();
    float y1 = other->getY();
    float distX = x-x1;
    float distY = y-y1;
    float dist = sqrt(distX*distX + distY*distY);
    float force = (-1 * GRAVITY * mass *(other->getMass()))/(dist*dist);
    float acc = force/mass;
    float theta;
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
    x += x_v;
    y += y_v;
}

void Planet::draw(SDL_Renderer *renderer){
    drawCircle(renderer, (int)x, (int)y, (int)r);
}

Planet::~Planet()
{
    //dtor
}
