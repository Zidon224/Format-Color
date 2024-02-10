
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<stdbool.h>

#include"test.c"

//--------------------------------------------------------
// FUNCTION PROTOTYPES
//--------------------------------------------------------
void test_validations(void);
void test_split_combine(void);
void test_conversions(void);

//--------------------------------------------------------
// FUNCTION main
//--------------------------------------------------------
int main()
{
    puts("--------------------");
    puts("| codedrome.com    |");
    puts("| Colour Converter |");
    puts("--------------------\n");

     test_validations();

     test_split_combine();

     test_conversions();
}

//--------------------------------------------------------
// FUNCTION test_validations
//--------------------------------------------------------
void test_validations(void)
{
    // create and validate RGBhex
    RGBhex rgbh;
    bool rgbhvalid;

    rgbh = (RGBhex){.R = "FF", .G = "00", .B = "FF"};
    rgbhvalid = validateRGBhex(rgbh);
    showRGBhex(rgbh);
    printf("RGB Hexadecimal valid: %s\n", rgbhvalid == true ? "Yes" : "No");

    rgbh = (RGBhex){.R = "GG", .G = "00", .B = "HH"};
    rgbhvalid = validateRGBhex(rgbh);
    showRGBhex(rgbh);
    printf("RGB Hexadecimal valid: %s\n", rgbhvalid == true ? "Yes" : "No");
    puts("");

    // create and validate HSL
    HSL hsl;
    bool hslvalid;

    hsl = (HSL){.H = 0, .S = 50, .L = 75};
    hslvalid = validateHSL(hsl);
    showHSL(hsl);
    printf("HSL valid: %s\n", hslvalid == true ? "Yes" : "No");

    hsl = (HSL){.H = 361, .S = -50, .L = 101};
    hslvalid = validateHSL(hsl);
    showHSL(hsl);
    printf("HSL valid: %s\n", hslvalid == true ? "Yes" : "No");
}

//--------------------------------------------------------
// FUNCTION test_split_combine
//--------------------------------------------------------
void test_split_combine(void)
{
    // create an RGBhex by splitting a string
    char hex[] = "00FF00";
    printf("RGBhex created from string %s\n", hex);
    RGBhex rgbh2;
    if(splithex(hex, &rgbh2))
    {
        showRGBhex(rgbh2);
    }
    else
    {
        printf("%s is not a valid colour\n", hex);
    }

    puts("");

    // create a hexadecimal string by combining an RGBhex
    RGBhex rgbh3 = (RGBhex){.R = "00", .G = "00", .B = "FF"};
    printf("hexadecimal string created from RGBhex ");
    showRGBhex(rgbh3);
    char hexstr[7] = "";
    combinehex(rgbh3, hexstr);
    printf("%s\n", hexstr);
}

//--------------------------------------------------------
// FUNCTION test_conversions
//--------------------------------------------------------
void test_conversions(void)
{
    RGBdec rgbd;
    RGBhex rgbh;
    HSL hsl;

    testsample testsamples[SAMPLE_SIZE];

    initialize_samples(testsamples);

    for(int i = 0; i < SAMPLE_SIZE; i++)
    {
        puts("Test Sample\n-----------");

        printf("rgb:     ");
        showRGBdec(testsamples[i].rgbd);
        printf("hex:     ");
        showRGBhex(testsamples[i].rgbh);
        printf("hsl:     ");
        showHSL(testsamples[i].hsl);

        puts("Conversions\n-----------");

        printf("hex2dec: ");
        hex2dec(testsamples[i].rgbh, &rgbd);
        showRGBdec(rgbd);

        printf("hsl2dec: ");
        hsl2dec(testsamples[i].hsl, &rgbd);
        showRGBdec(rgbd);

        printf("dec2hex: ");
        dec2hex(testsamples[i].rgbd, &rgbh);
        showRGBhex(rgbh);

        printf("hsl2hex: ");
        hsl2hex(testsamples[i].hsl, &rgbh);
        showRGBhex(rgbh);

        printf("dec2hsl: ");
        dec2hsl(testsamples[i].rgbd, &hsl);
        showHSL(hsl);

        printf("hex2hsl: ");
        hex2hsl(testsamples[i].rgbh, &hsl);
        showHSL(hsl);

        puts("");
    }
}
