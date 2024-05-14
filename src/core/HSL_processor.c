/*
Algorithms for processing float based HSL
*/




#pragma once

#include "transColor.h"
#include <string.h>
#include <ctype.h>



//These should go into the API list too
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

static double procSat(RGB rgb, double lightness)
{
  double max = 0;
	double min = 0;

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

	double saturation;

	if(max == min)
		saturation = 0.0;
	
	else
	{
		if(lightness < 50.0)
			saturation = ((max - min) / (max + min)) * 100.0;
		
		else
			saturation = ((max - min) / (2.0 - max - min)) * 100.0;
		
	}

	return saturation;
}

static double procLight(RGB rgb)
{
  double max = 0;
	double min = 0;

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

	double lightness = ((min + max) / 2.0) * 100.0;

	return lightness;
}
