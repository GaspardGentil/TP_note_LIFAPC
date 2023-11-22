//Gaspard Gentil

#pragma once

#include "arc.hpp"

#define INTENSITY_MAX = 255
#define INTENSITY_MIN = 0

class Pixel {
    private :
    int intensity;
    bool state;
    Arc north, south, east, west;

public:
    Pixel(){intensity = 0; state = false; }
    Pixel(const int i){intensity = i; state = false;}

    int getIntensity() {return intensity; }
    void setIntensity(int i) {intensity = i;}

    int getState() {return state;}
    void setState(int s) {state = s;}
};