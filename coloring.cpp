#include <iostream>
#include <windows.h>

using namespace std;
  

int main()
{
    // Color of the console
    HANDLE console_color;
    console_color = GetStdHandle(
        STD_OUTPUT_HANDLE);
  
    for (int P = 0; P < 257; P++) {
	cout<<"                                        ";
SetConsoleTextAttribute(console_color, P);
	cout<<P<<" Hello This is a test Yes this is a test "<<P<<endl;
	if((P+1)%16==0)
		cout<<"\n";
SetConsoleTextAttribute(console_color, 15);
    }
SetConsoleTextAttribute(console_color, 15);
    return 0;
} //███▊