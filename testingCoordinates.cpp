#include<iostream>
#include<windows.h>
#include<conio.h>

COORD coord = {0,0};

void gotoxy(int a, int b){
    coord.X = a;
    coord.Y = b;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}
    void print(int x,int y,const std::string& s) {
    gotoxy(x,y);
    using namespace std;
    cout<<s;
    }

int main()
{
    using namespace std;


    print(50, 4, "Hello There");
    print(50, 5, "How are you");

    getch();
    return 0;
}