#include "account.h"

//!     function Declaration
void welcomeScreen();
void loginMenu();
void accountManagementMenu();
void inputSomething();
int main()
{
    toggleCursor(false);
    welcomeScreen();
    loginMenu();
    setConsoleColor(15);
    return EXIT_SUCCESS;
}
void inputSomething()
{
    emptyMenu();
    createBox(10, 10, 20, 3, 4, 1);
    gotoxy(10,10);
    std::string Hello;
    getline(std::cin >> std::ws, Hello, '\n');
    loginMenu();
}

void loginMenu()
{
    std::string menuOptions[3] = {"Create Account"          , "Login", "Exit"};
    void (*menuFunctions[3])(void) = {inputSomething,  accountManagementMenu  ,     NULL};
    showMenu(1, 3, menuOptions, menuFunctions, 3);
}
void accountManagementMenu()
{
    
std::string menuOptions[7] =      {"Deposit Amount","Withdraw Amount","Balance Enquiry","Modify Account","Delete Account","Back"  ,"Exit"};
void (*menuFunctions[7])(void) = {            NULL,             NULL,             NULL,            NULL,            NULL, loginMenu, NULL };
showMenu(1, 7, menuOptions, menuFunctions, 1);
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