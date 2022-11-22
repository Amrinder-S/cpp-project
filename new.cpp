#include<iostream>
#include<conio.h>
using namespace std;
void test0() {
cout<<"function 1\n";
}
void test1() {
cout<<"function 2\n";
}
void test2() {
cout<<"function 3\n\a";
}

int main() {
void (*p[3])(void);
p[0]=&test0;
p[1]=&test1;
p[2]=&test2;
while(1)
{
cout<<"Enter the function to execute:";
(p[int(getch())-49])();
}

	return 0;
}
