#pragma once


#include <string.h>
#include <ctype.h>
#include "color_defs.h"




static int procHue(RGB rgb)
{
    double min = 0;
    double max = 0;

    double dR;
    double dG;
    double dB;

    double hue;

    dR = (double)rgb.R / 255.0;
    dG = (double)rgb.G / 255.0;
    dB = (double)rgb.B / 255.0;

    if(dR >= dG && dR >= dB)
        max = dR;
        //G B G R
    else if(dG >= dB && dG >= dR)
        max = dG;
        //B G B R
    else if(dB >= dG && dB >= dR)
        max = dB;
    

    if(max == min)
        hue = 0;
    else
    {
        if(max == dR)
            hue = (dG - dB) / (max - min);
        else if(max == dG)
            hue = 2.0 + (dB - dR) / (max - min);
        else if(max == dB)
            hue = 4.0 + (dR - dG) / (max - min);

        hue *= 60.0;

        if(hue < 0.0)
            hue += 360.0;
    }
    return hue;       
}

//Saturation proc

static double procSat(RGB rgb, double lightness)
{
    double min = 0;
    double max = 0;

    double dR;
    double dG;
    double dB;

    dR = (double)rgb.R / 255.0;
    dG = (double)rgb.G / 255.0;
    dB = (double)rgb.B / 255.0;

    if(dR >= dG && dR >= dB)
        max = dR;
    else if(dG >= dB && dG >= dR)
        max = dG;
    else if(dB >= dG && dB >= dR)
        max = dB;

    if(dR <= dG && dR <= dB)
        min = dR;
    else if(dG <= dB && dG <= dR)
        min = dG;
    else if(dB <= dG && dB <= dR)
        min = dB;

    double sat;

    if(min == max)
        sat = 0.0;
    else
    {
        if(lightness < 50.0)
            sat = ((max - min) / (max + min)) * 100.0;
        else
            sat = ((max - min) / (2.0 - max - min)) * 100.0;
    }
    return sat;
}

static double procLight(RGB rgb)
{
    double min = 0;
    double max = 0;

    double dR;
    double dG;
    double dB;

    dR = (double)rgb.R / 255.0;
    dG = (double)rgb.G / 255.0;
    dB = (double)rgb.B / 255.0;

    if(dR >= dG && dR >= dB)
        max = dR;
    else if(dG >= dB && dG >= dR)
        max = dG;
    else if(dB >= dG && dB >= dR)
        max = dB;

    if(dR <= dG && dR <= dB)
        min = dR;
    else if(dG <= dB && dG <= dR)
        min = dG;
    else if(dB <= dG && dB <= dR)
        min = dB;

    double light = ((min - max) / 2.0) * 100.0;

    return light;
}
