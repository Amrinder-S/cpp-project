#include "filehandling.h"

//!     function Declaration
void welcomeScreen();
void loginMenu();
void accountManagementMenu();
void inputSomething();
void createAccount();
void close() {setConsoleColor(15);system("cls");exit(3);}
void accountInfo();
void login();
void deposit();
void withdraw();
void deleteAccount();
void modifyAccount();

int main()
{
    toggleCursor(false);
    welcomeScreen();
    loginMenu();
    setConsoleColor(15);
    return EXIT_SUCCESS;
}

void loginMenu()
{
    std::string menuOptions[3] = {"Create Account" , "Login" , "Exit"};
    void (*menuFunctions[3])(void) = {createAccount,  login  ,  close};
    showMenu(1, 3, menuOptions, menuFunctions, 3);
}
void login()
{
int account_number;
char pass[30];
emptyMenu();
print(centerTextX(18), 8, 18, 496, "Account Number: ");
std::cin>>account_number;
print(centerTextX(18), 10, 18, 496, "Password: ");
std::cin.getline(pass, 30);
if(searchAccount(account_number)) //if account is found
{
    if(a.authenticate(pass)) //if password matches.
    {
        accountManagementMenu(); //show account management menu.
    }
    else
        errorBox(" Invalid Password ");
    loginMenu();
}
else
    errorBox(" Account Not Found! ");
}
void accountManagementMenu()
{
    std::string menuOptions[7] =      {"Account Information", "Deposit Amount","Withdraw Amount","Modify Account","Delete Account","Log-out"  ,"Exit"};
    void (*menuFunctions[7])(void) = {           accountInfo,          deposit,         withdraw,   modifyAccount,   deleteAccount, loginMenu, close };
    showMenu(1, 7, menuOptions, menuFunctions, 2);
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
void createAccount()
{   
    emptyMenu();
    account acc;
    acc.createAccount(getAvailableAccountNumber());
    acc.showAccountInfo();
    saveAccount(acc, 0);
    getch();
    loginMenu();
}
void accountInfo()
{
    a.showAccountInfo();
    accountManagementMenu();
}
void deposit()
{
    a.deposit();
    updateAccount();
    accountManagementMenu();
}
void withdraw()
{
    a.withdraw();
    updateAccount();
    accountManagementMenu();
}
void deleteAccount()
{
    removeAccount(a.returnAccountNumber());
    loginMenu();
}
void modifyAccount()
{
    emptyMenu();
    a.modify();
    updateAccount();
    emptyMenu();
    print(centerTextX(16), 10, 0, 500, "Account Updated!");
    print(centerTextX(4), 12, 0, 400, " OK ");
    getch();
    loginMenu();
}