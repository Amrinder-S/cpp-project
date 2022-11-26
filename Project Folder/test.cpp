#include "gui.h"
void function1() { std::cout<<" function 1 ";}
void function2() { std::cout<<" function 2 ";}
void function3() { std::cout<<" function 3 ";}
void test(void (*p[])(void), std::string x[]) {
std::cout<<x[0]<<x[1]<<x[2];
p[0]();
p[1]();
p[2]();

}
int main()
{

    void (*x[3])(void) = {function1, function2, function3};
    std::string str[] = {"One ", "Two ", "Three "};
    test(x, str);

    return 0;
}