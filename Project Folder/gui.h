#include<iostream>
#include<windows.h>
#include<conio.h>
COORD coord = {0,0}; //Coords are used to set coordinates of cursor in console
HANDLE console_handle = GetStdHandle(STD_OUTPUT_HANDLE); //Output Handle, useful for changing color of text
int x_coord = GetSystemMetrics(SM_CXSCREEN);
int y_coord = GetSystemMetrics(SM_CYSCREEN);
HWND WINAPI GetConsoleWindowNT(void) //this is used to set console size, to make sure everything draws well
{
    typedef HWND WINAPI(*GetConsoleWindowT)(void);
    GetConsoleWindowT GetConsoleWindow;
    HMODULE hk32Lib = GetModuleHandle(TEXT("KERNEL32.DLL"));
    GetConsoleWindow = (GetConsoleWindowT)GetProcAddress(hk32Lib, TEXT("GetConsoleWindow"));
    if(GetConsoleWindow == NULL){
        return NULL;
    }
    return GetConsoleWindow();
}

int getConsoleCoords(char coord)
{
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(console_handle, &csbi);
    if(tolower(coord)=='x')
        return csbi.srWindow.Right - csbi.srWindow.Left-1;
    else
        return csbi.srWindow.Bottom - csbi.srWindow.Top;
}
int centerTextX(int text_length)
{
        return (getConsoleCoords('x')-text_length)/2;
}

HWND hWnd=GetConsoleWindowNT();
//!     Function Definitions
void gotoxy(int, int);
void print(int x,int y,int erase, int color,const std::string& s);
void setConsoleColor(int);
void createBox(int x, int y, int size_x, int size_y, int color, int fill);
void displayAscii(int x,int y,int color, int logosize, std::string logo[]);
void createTextBox(int x, int y, int color, std::string text);
void menu(int option, int size,std::string x[]);

//!     Function Declaration
void gotoxy(int a, int b){
    coord.X = a;
    coord.Y = b;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord); //used to jump console-cursor to the position we desire
}
void print(int x,int y,int erase, int color,const std::string& s) { //function to print text at given x,y coords on console
gotoxy(x,y);
setConsoleColor(color);
std::cout<<std::string(erase, ' ')<<std::string(erase, '\b')<<s;

}
void setConsoleColor(int color)
{
    SetConsoleTextAttribute(console_handle, color);
}


void displayAscii(int x,int y,int color, int logosize, std::string logo[])
{
    for(int i=0;i<logosize;i++)
    {
        print(x,y+i,0,color,logo[i]);
    }
}


void createBox(int x, int y, int size_x, int size_y, int color, int fill)
{
size_x += x;
size_y += y;
    if(fill)
    {
        for(int i=y;i<size_y;i++)
            for(int j=x;j<size_x;j++)
                    print(j, i, 0, color, " ");
    }
    else
    {
        for(int i=x; i<size_x;i++)
        {
            print(i, y, 0, color, " ");
            print(i, size_y, 0, color, " ");
        }

        for(int i=y;i<size_y;i++)
        {
            print(x , i, 0, color,"  ");
            print(size_x , i, 0, color,"  ");
        }
        print(size_x, size_y, 0, color, "  ");
    }
}
void menu(int option, int size,std::string x[]) //accepted arguments: option selected, number of options, array of strings(options)
{
    for(int i=0;i<size;i++)
    {
        
        if(option==(i+1))
        {
            if(i!=size-1)
                print(centerTextX(20)+1, 8+i, 20,32,std::string((20-x[i].length())/2, ' ')+x[i]);
            else
                print(centerTextX(20)+1, 8+i, 20,64,std::string((20-x[i].length())/2, ' ')+x[i]);
        }
        else
            print(centerTextX(20)+1, 8+i, 20,15,std::string((20-x[i].length())/2, ' ')+x[i]);
    }
}


void mainMenu(int option, int maxOptions, std::string mainMenuOptions[], void (*p[])(void) )
{
    resetMainMenu:
    setConsoleColor(384);
    int x = getConsoleCoords('x'), y = getConsoleCoords('y');
    system("cls");
    createBox(0, 0, x, y, 47,0);

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
    displayAscii(2,1,4,logosize2,logo);
    gotoxy(0,0);
    
char ch;
menu(option, maxOptions, mainMenuOptions);
while(1) // Main menu bool, to keep track of when main menu is visible
{
    ch = getch(); //getting the pressed key
    if(ch=='P') //Down key
    {
        option++;
        if(option>maxOptions)
            option=1;
    }
    if(int(ch)==72) //Up key
        {
            option--;
            if(option<1)
                option=maxOptions;
        }
    if(x!=getConsoleCoords('x'))
        goto resetMainMenu;
    menu(option,maxOptions,mainMenuOptions); //sending it to another function, which lets us refresh the menu many times with minimal updations.
}

}