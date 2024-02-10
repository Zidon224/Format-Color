//Contains all information about the program when the "-h" or "--help" command is used and other commands



#pragma once




#include <string>




std::string fullHelp = 
"Usage: color -ICF <color type + input color> -OFC <output type> [Options]\n"
"---- Command Line Argument Options ----\n"
"=== Basic arguments ===\n"
"-h   | --help           -> Shows help info\n"
"-v   | --version        -> Shows version\n"
"-inf | --info           -> Shows full info about the program\n"
"-ui  | --user_interface -> Starts the program in User Interface mode\n"
"-cpk | --color_picker   -> Triggers open the OS integrated Color picker. Default type: HSL\n"
"-Show_ICF               -> Shows Input Color Formats\n"
"-Show_OCF               -> Shows Output Color Formats\n"
"-Show_CPK_FMT           -> Shows Color Picker formats\n"
"--license               -> Shows the software License of the used components\n"
"▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬\n"
"Advanced CLI Options\n"
"[Argument] -------- [Parameters] ---- [Must be specified] ---- [Description]\n"
"-icf:               RGB, HSL, HEX     Yes                      Input color format specification\n"
"-ocf:               RGB, HSL, HEX     Yes                      Output color format\n"
"Important notice!!! all color formats must end with '=' (Example: -icf: RGB= '<RGB color>'\n"
"This only applies to input color format\n"
"▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬▬\n"
"-vc | --view_color                    (Optional)               Prints a bar with the input color to STD Output\n"
"-fi | --file_input  <file/path>       (optional)               Reads an array of colors stored into a text file\n"
"-fi | --file_output <file/path>       (Optional)               Writes a text files with the converted color array\n"
;


//Command: "-sl", "--show_license"
std::string Licenses = 
"---- Software Components Licenses ----\n"
" ___  _    _   ___ ___\n"
"|  _|| |  | | | _ \\ _ \\   CLIPP - command line interfaces for modern C++\n"
"| |_ | |_ | | |  _/  _/   version 1.2.3\n"
"|___||___||_| |_| |_|     https://github.com/muellan/clipp\n"
"\n"
"Licensed under the MIT License <http://opensource.org/licenses/MIT>.\n"
"Copyright (c) 2017-2018 André Müller <foss@andremueller-online.de>\n"
"\n"
"---------------------------------------------------------------------------\n"
"Permission is hereby granted, free of charge, to any person obtaining a\n"
"copy of this software and associated documentation files (the 'Software'),\n"
"to deal in the Software without restriction, including without limitation\n"
"the rights to use, copy, modify, merge, publish, distribute, sublicense,\n"
"and/or sell copies of the Software, and to permit persons to whom the\n"
"Software is furnished to do so, subject to the following conditions:\n"
"\n"
"The above copyright notice and this permission notice shall be included in\n"
"all copies or substantial portions of the Software.\n"
"\n"
"THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND, EXPRESS\n"
"OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,\n"
"FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL\n"
"THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR\n"
"OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE,\n"
"ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR\n"
"OTHER DEALINGS IN THE SOFTWARE.\n"
"\n"
"[ANSI_utils.h]\n"
"MIT License\n"
"\n"
"Copyright (c) 2023 Zidon224\n"
"\n"
"Permission is hereby granted, free of charge, to any person obtaining a copy\n"
"of this software and associated documentation files (the 'Software'), to deal\n"
"in the Software without restriction, including without limitation the rights\n"
"to use, copy, modify, merge, publish, distribute, sublicense, and/or sell\n"
"copies of the Software, and to permit persons to whom the Software is\n"
"furnished to do so, subject to the following conditions:\n"
"\n"
"The above copyright notice and this permission notice shall be included in all\n"
"copies or substantial portions of the Software.\n"
"THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND, EXPRESS OR\n"
"IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,\n"
"FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE\n"
"AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER\n"
"LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,\n"
"OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE\n"
"SOFTWARE.\n"
"\n"
"\n"
;

//Command: "-scf" / "--show_color_fmts"
std::string ColorFMTs = 
"RGB - Red Green Blue\n"
"HSL - Hue Sat Lightness\n"
"HEX - As Color Code\n";

std::string FullInfo = 
"---- Full info ----\n"
"\n"
"Program name: color\n"
"Version: 1.0.0\n"
"Description: Converts colors from any formats\n"
"\n"
"=== sources ===\n"
"Code: https://github.com/Zidon224/Color-converter-CLI\n"
"Original converting algorithms: https://github.com/CodeDrome/colour-converter-c\n"
"\n"
"=== Deps ===\n"
"Clipp: https://github.com/muellan/clipp\n"
"Ansi utils: https://github.com/Zidon224/ANSI-Utilities\n"
"\n"
"Built with GCC / G++ V10.3.0 (tdm64-1)\n"
"\n"
;
