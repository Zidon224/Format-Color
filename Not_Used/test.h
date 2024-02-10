
#include<stdbool.h>

#include"colourconverter.c"

#define SAMPLE_SIZE 8

// --------------------------------------------------------
// STRUCTS
// --------------------------------------------------------
typedef struct
{
    RGBdec rgbd;
    RGBhex rgbh;
    HSL hsl;
}testsample;

// --------------------------------------------------------
// FUNCTION PROTOTYPES
// --------------------------------------------------------
void initialize_samples(testsample testsamples[SAMPLE_SIZE]);
