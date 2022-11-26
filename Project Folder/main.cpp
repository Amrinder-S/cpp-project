#include "gui.h"
#include<conio.h>
int main()
{
    system("cls");
setConsoleColor(15);
    std::string logo2[] = {
        
"                                _.--._",
"                           _.-.'      `.-._",
"                         .' ./`--...--' \\  `.",
"                         `.'.`--.._..--'   .'",
"                         ( (-..__    __..-'",
"                          )_)    ````",
"    __    _, ____, __    ____   ____, _____,   ____,    ____, ____,       ",
"   (-| | |  (-|_, (-|   (-/  ` (-/  \\(-| | |  (-|_,    (-|   (-/  \\       ",
"    _|_|_|   _|__, _|__,  \\___,  \\__/ _| | |_, _|__,    _|     \\__/       ",
"   (        (     (                  (        (        (                  ",
"                        ____, __   _, ____,",
"                       (-|   (-|__|  (-|_, ",
"                        _|    _|  |_, _|__,",
"                       (     (       (     ",
" ___,   ____, ____,    __   _, ___,   ____,    ___,  ___,   ____,   __  _,",
"(-|_)  (-|_, (-|  \\   (-|__|  (-|_\\_,(-|      (-|_) (-|_\\_,(-|  |  (-|_/  ",
" _| \\_, _|__, _|__/    _|  |_, _|  )  _|       _|__) _|  )  _|  |_, _| \\_,",
"(      (     (        (       (      (        (     (      (       (      ",
" ",
"                       Press any key to continue..."


    };
        int logosize = sizeof(logo2)/sizeof(logo2[0]);
    createLogo(2,1,4,logosize,logo2);

    getch();
    setConsoleColor(384);
    system("cls");
    createBox(0, 0, getConsoleCoords('x'), getConsoleCoords('y'), 47,0);



    std::string logo[] = {
        "         _.--._THE",
        "    _.-.'      `.-._RED",
        "  .' ./`--...--' \\  `.HAT",
        "  `.'.`--.._..--'   .' BANK",
        "  ( (-..__    __..-'",
        "   )_)    ````"
    };
    createBox(2,1,getConsoleCoords('x')-2,6,4,1);
    int logosize2 = sizeof(logo)/sizeof(logo[0]);
    createLogo(2,1,4,logosize2,logo);
    gotoxy(0,0);

    setConsoleColor(15);
    return EXIT_SUCCESS;
}


