
#include "gui.h"
#include "functions.h"
void createAccount();
class account {
    private: int account_number;
    protected:
    std::string account_name;
    std::string password;
    char account_type;
    float balance;
    public:
    int returnAccountNumber() {return account_number;}
    void createAccount()
    {
        account_number = 1;
        print(centerTextX(30), 8, 30, 15, "Enter your Name: ");
        account_name = getString();
        print(centerTextX(30), 9, 30, 15, "Enter your Password: ");
        password = getString();
        reEnterAccountType:
        print(centerTextX(30), 10, 30, 15, "Enter your account type(C/S): ");
        account_type = tolower(getch());
        if(!(account_type=='c' || account_type=='s'))
        {
        print(centerTextX(30), 11, 30, 4, "Wrong account type, enter C/S^ ");
        goto reEnterAccountType;
        }
        print(centerTextX(30), 11, 30, 15, "Enter the starting balance(non 0): ");
        std::string temp = getString();
        balance = strtof(temp.c_str(),NULL);
        while(!balance)
        {
            print(centerTextX(30), 12, 40, 4, "Invalid input! Enter balance: ");
            std::string temp = getString();
            balance = strtof(temp.c_str(),NULL);
        }
    }
    void showAccountInfo()
    {
        gotoxy(15,6);
        std::cout<<"Name:"<<account_name<<" password:"<<password<<" account type: "<<account_type<<" bal:"<<balance;
    }
    void alterBalance(float n)
    {
        balance += n;
    }
};

void createAccount()
{   
    emptyMenu();
    account a;
    a.createAccount();
    a.showAccountInfo();
}