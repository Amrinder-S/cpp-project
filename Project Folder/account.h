
#include "gui.h"
class account {
    private: int account_number;
    protected:
    std::string account_name;
    std::string password;
    char account_type;
    float balance;
    public:
    int returnAccountNumber() {return account_number;}
    void createAccount(int a, std::string name, std::string pw, char type, float bal)
    {
        account_number = a;
        account_name = name;
        password = pw;
        account_type = type;
        balance = bal;
    }
    void alterBalance(float n)
    {
        balance += n;
    }
};

