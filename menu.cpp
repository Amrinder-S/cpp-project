#include<iostream>
#include<conio.h>
#include<Windows.h>
COORD coord = {0,0};
HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);

void gotoxy(int a, int b){
    coord.X = a;
    coord.Y = b;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
void print(int x,int y,int erase,const std::string& s) {
gotoxy(x,y);
using namespace std;
std::cout<<string(erase, ' ')<<string(erase, '\b');
std::cout<<s;
}

void menu(int option, int size,std::string x[])
{
    for(int i=0;i<size;i++)
    {
        
        if(option==(i+1))
        {
            if(i==size-1) SetConsoleTextAttribute(console_color, 4); else SetConsoleTextAttribute(console_color, 10);
            print(50, 3+i,x[i].length()+14, "--->   "+x[i]+"   <---");
            SetConsoleTextAttribute(console_color, 15);
        }
        else
            print(50, 3+i, x[i].length()+14, x[i]);
    }
}


int main()
{

    std::string x[5] = {
        "First",
        "Second",
        "Third",
        "Fourth",
        "Fifth"
    };

    while(1)
    {    
    menu(int(getch()-48), 5, x);
    }

    return EXIT_SUCCESS;
}