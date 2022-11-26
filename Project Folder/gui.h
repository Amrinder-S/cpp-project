#include<iostream>
#include<windows.h>
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

HWND hWnd=GetConsoleWindowNT();
//!     Function Definitions
void gotoxy(int, int);
void print(int x,int y,int erase, int color,const std::string& s);
void setConsoleColor(int);
void createBox(int x, int y, int size_x, int size_y, int color, int fill);
void createLogo(int x,int y,int color, int logosize, std::string logo[]);

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


void createLogo(int x,int y,int color, int logosize, std::string logo[])
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
                {
                    print(j, i, 0, color, " ");
                }
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