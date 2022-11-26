#include "account.h"

//!     function Declaration
void welcomeScreen();
void mainMenu();

int main()
{
    welcomeScreen();
std::string mainMenuOptions[7] = {"New Account","Deposit Amount","Withdraw Amount","Balance Enquiry","Modify Account","Delete Account","Exit"};
void (*mainMenuFunctions[7])(void)            = {NULL          ,            NULL,             NULL,             NULL,            NULL,            NULL, NULL};
mainMenu(1, 7, mainMenuOptions, mainMenuFunctions);
    setConsoleColor(15);
    return EXIT_SUCCESS;
}



void welcomeScreen()
{
    system("cls");
setConsoleColor(15);
    std::string logo[] = {
        
"                                _.--._",
"                           _.-.'      `.-._",
"                         .' ./`--...--' \\  `.",
"                         `.'.`--.._..--'   .'",
"                         ( (-..__    __..-'",
"                          )_)    ````",
"    __    _, ____, __    ____   ____, ___  ,   ____,    ____, ____,       ",
"   (-| | |  (-|_, (-|   (-/  ` (-/  \\(-|\\ /|  (-|_,    (-|   (-/  \\       ",
"    _|_|_|   _|__, _|__,  \\___,  \\__/ _| | |_, _|__,    _|     \\__/       ",
"   (        (     (                  (        (        (                  ",
"                        ____, __   _, ____,",
"                       (-|   (-|__|  (-|_, ",
"                        _|    _|  |_, _|__,",
"                       (     (       (     ",
" ___,   ____, ____,    __   _, ___,   ____,    ___,  ___,   __  ,   __  _,",
"(-|_)  (-|_, (-|  \\   (-|__|  (-|_\\_,(-|      (-|_) (-|_\\_,(-|\\ |  (-|_/  ",
" _| \\_, _|__, _|__/    _|  |_, _|  )  _|       _|__) _|  )  _| \\|_, _| \\_,",
"(      (     (        (       (      (        (     (      (       (      ",
" ",
"                       Press any key to continue..."


    };
        int logosize = sizeof(logo)/sizeof(logo[0]);
    displayAscii(centerTextX(75),1,4,logosize,logo);

    getch();
}