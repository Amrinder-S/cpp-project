
#include "gui.h"
#include "functions.h"
class account {
    private: int account_number;
    char account_name[30];
    char account_type;
    float balance;
    protected:
    char password[30];
    public:
    int returnAccountNumber() {return account_number;}
    float returnBalance() {return balance;}
    void createAccount(int n)
    {
        account_number = n;
        print(centerTextX(30), 8, 30, 15, "Enter your Name: ");
        std::cin.getline(account_name, 30);
        print(centerTextX(30), 10, 30, 15, "Enter your Password: ");
        std::cin.getline(password, 30);
        reEnterAccountType:
        print(centerTextX(30), 12, 30, 15, "Enter your account type(C/S): ");
        account_type = tolower(getch());
        if(!(account_type=='c' || account_type=='s'))
        {
        print(centerTextX(30), 14, 30, 4, "Wrong account type, enter C/S^ ");
        goto reEnterAccountType;
        }
        else
        {
            (account_type=='c')?std::cout<<" Current":std::cout<<" Savings";
            print(centerTextX(30), 14, 31, 497, " "); //clearing the pervious wrong account type message
        }
        print(centerTextX(30), 15, 30, 15, "Enter the starting balance(non 0): ");
        std::string temp = getString(); //getting balance as a string to avoid errors
        balance = strtof(temp.c_str(),NULL); //function to convert string to float
        while(!balance)
        {
            print(centerTextX(30), 16, 40, 4, "Invalid input! Enter balance: ");
            std::string temp = getString();
            balance = strtof(temp.c_str(),NULL);
        }
    }
    void showAccountInfo()
    {
        emptyMenu();
        print(centerTextX(19), 8, 35, 497, "Account Information");
        print(centerTextX(35), 10, 35, 496, "Account Name: ");
        std::cout<<account_name;
        print(centerTextX(35), 12, 35, 496, "Account Number: ");
        std::cout<<account_number;
        print(centerTextX(35), 14, 35, 496, "Account Type: ");
        (account_type=='c')?std::cout<<" Current":std::cout<<" Savings";
        print(centerTextX(35), 16, 35, 496, "Account Balance: ");
        std::cout<<balance;

        print(centerTextX(4), 18, 0, 3, " OK ");
        getch();
    }
    bool authenticate(char str[30]) {
        std::cin.getline(str, 30);
        return (strcmp(str, password)); //returns true if password matches.
    }
    void withdraw()
    {
        emptyMenu();
        float n;
        print(centerTextX(19), 8, 35, 497, "Enter amount to withdraw: ");
        std::cin>>n;
        if(n<0) n=-n; //correction if someone entered negative value
        if(balance>n)
        {
        balance = balance - n;
        print(centerTextX(30), 10, 30, 497, "Amount ");
        std::cout<<n<<" Withdrawn from account number "<<account_number;
        print(centerTextX(19), 12, 35, 497, "New Balance: ");
        std::cout<<balance;
        }
        else
            print(centerTextX(19), 10, 35, 500, "Insufficient Balance.");
        print(centerTextX(4), 14, 0, 3, " OK ");
        getch();
    }
    void deposit()
    {
        emptyMenu();
        float n;
        print(centerTextX(19), 8, 35, 497, "Enter amount to deposit: ");
        std::cin>>n;
        if(n<0) n=-n; //correction if someone entered negative value
        balance = balance + n;
        print(centerTextX(60), 10, 60, 497, "Amount ");
        std::cout<<n<<" Deposited to account number "<<account_number<<" New Balance: "<<balance;
        print(centerTextX(4), 12, 0, 3, " OK ");
        getch();
    }

};