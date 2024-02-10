
#include"test.h"
#include<stdlib.h>

//--------------------------------------------------------
// FUNCTION initialize_samples
//--------------------------------------------------------
void initialize_samples(testsample testsamples[SAMPLE_SIZE])
{
    testsamples[0] = (testsample){.rgbd = (RGBdec){.R = 255, .G = 0, .B = 0},
                                 .rgbh = (RGBhex){.R = "FF", .G = "00", .B = "00"},
                                 .hsl = (HSL){.H = 0, .S = 100, .L = 50}};

    testsamples[1] = (testsample){.rgbd = (RGBdec){.R = 0, .G = 0, .B = 0},
                                 .rgbh = (RGBhex){.R = "00", .G = "00", .B = "00"},
                                 .hsl = (HSL){.H = 0, .S = 0, .L = 0}};

    testsamples[2] = (testsample){.rgbd = (RGBdec){.R = 128, .G = 128, .B = 128},
                                 .rgbh = (RGBhex){.R = "80", .G = "80", .B = "80"},
                                 .hsl = (HSL){.H = 0, .S = 0, .L = 50.2}};

    testsamples[3] = (testsample){.rgbd = (RGBdec){.R = 255, .G = 255, .B = 255},
                                 .rgbh = (RGBhex){.R = "FF", .G = "FF", .B = "FF"},
                                 .hsl = (HSL){.H = 0, .S = 0, .L = 100}};

    testsamples[4] = (testsample){.rgbd = (RGBdec){.R = 255, .G = 128, .B = 0},
                                 .rgbh = (RGBhex){.R = "FF", .G = "80", .B = "00"},
                                 .hsl = (HSL){.H = 30, .S = 100, .L = 50}};

    testsamples[5] = (testsample){.rgbd = (RGBdec){.R = 0, .G = 128, .B = 255},
                                 .rgbh = (RGBhex){.R = "00", .G = "80", .B = "FF"},
                                 .hsl = (HSL){.H = 210, .S = 100, .L = 50}};

    testsamples[6] = (testsample){.rgbd = (RGBdec){.R = 32, .G = 64, .B = 128},
                                 .rgbh = (RGBhex){.R = "20", .G = "40", .B = "80"},
                                 .hsl = (HSL){.H = 220, .S = 60, .L = 31.4}};

    testsamples[7] = (testsample){.rgbd = (RGBdec){.R = 128, .G = 192, .B = 128},
                                 .rgbh = (RGBhex){.R = "80", .G = "C0", .B = "80"},
                                 .hsl = (HSL){.H = 120, .S = 33.68, .L = 62.75}};
}
