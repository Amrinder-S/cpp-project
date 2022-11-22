#include<iostream>
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

for(int i=0;i<3;i++)
	(*p[i])();

	return 0;
}