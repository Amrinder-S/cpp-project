#include<fstream>
#include<cctype>
#include<iomanip>
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<cstdlib>
#define ENTER_ACCOUNT cout<<"Enter account number:";cin>>num;

#define MAIN_MENU 0
using namespace std;
int menuID = 0;
HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);
void insertLines (int x) {for(int i=0;i<x;i++)cout<<"\n";}
using namespace std;

class account
{
	int account_number;
	char name[50];
	int deposit;
	char type;
public:
	void create_account();
	void show_account() const;
	void modify();	
	void dep(int);
	void draw(int);
	void report() const;
	int returnAccountNumber() const;	
	int retdeposit() const;	
	char rettype() const;
};

void account::create_account()
{
	cout<<"\nEnter The account No. :";
	cin>>account_number;
	cout<<"\n\nEnter The Name of The account Holder : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\nEnter Type of The account (C/S) : ";
	cin>>type;
	type=toupper(type);
	cout<<"\nEnter The Initial amount(>=500 for Saving and >=1000 for current ) : ";
	cin>>deposit;
	cout<<"\n\n\nAccount Created..";
}

void account::show_account() const
{
	cout<<"\nAccount No. : "<<account_number;
	cout<<"\nAccount Holder Name : ";
	cout<<name;
	cout<<"\nType of Account : "<<type;
	cout<<"\nBalance amount : "<<deposit;
}


void account::modify()
{
	cout<<"\nAccount No. : "<<account_number;
	cout<<"\nModify Account Holder Name : ";
	cin.ignore();
	cin.getline(name,50);
	cout<<"\nModify Type of Account : ";
	cin>>type;
	type=toupper(type);
	cout<<"\nModify Balance amount : ";
	cin>>deposit;
}

	
void account::dep(int x)
{
	deposit+=x;
}
	
void account::draw(int x)
{
	deposit-=x;
}
	
void account::report() const
{
	cout<<account_number<<setw(10)<<" "<<name<<setw(10)<<" "<<type<<setw(6)<<deposit<<endl;
}

	
int account::returnAccountNumber() const
{
	return account_number;
}

int account::retdeposit() const
{
	return deposit;
}

char account::rettype() const
{
	return type;
}



//!    	function declaration

void write_account();
void display_sp(int);
void modify_account(int);	
void delete_account(int);	
void display_all();		
void deposit_withdraw(int, int); 
void menu(int option, int size,string x[]);
void mainMenu();

//!     main function
int main()
{
mainMenu();
return 0;
}

//!         function definitions
void menu(int option, int size,string x[])
{
    system("cls");
    for(int i=0;i<size;i++)
    {
        if(option==(i+1))
        {
            if(i==size-1) SetConsoleTextAttribute(console_color, 4); else SetConsoleTextAttribute(console_color, 10);
            cout<<"--->   "<<x[i]<<"   <--\n";
            SetConsoleTextAttribute(console_color, 15);
        }
        else
            cout<<x[i]<<"\n";
    }
}

void mainMenu()
{
int maxOptions = 7; // Max Options means number of items in the menu
string mainMenuOptions[maxOptions] = 
{
"New Account",
"Deposit Amount.",
"Withdraw Amount.",
"Balance Enquiry.",
"Modify Account.",
"Delete Account.",
"Exit"
};
int option=1;

menu(option,maxOptions,mainMenuOptions);
char ch;
int num;
while(menuID == MAIN_MENU) // Main menu bool, to keep track of when main menu is visible
{
    ch = getch(); //getting the pressed key
    if(ch=='P') //Down key
    {
        option++;
        if(option>maxOptions)
            option=1;
    }
    if(int(ch)==72) //Up key
        {
            option--;
            if(option<1)
                option=maxOptions;
        }
    if(int(ch)==13) //if enter was pressed
    {
        switch(option)
        {
            case 1:
                menuID = 1; 
                write_account();
                break;
            case 2: 
				menuID = 2;
				system("cls");
				ENTER_ACCOUNT
				deposit_withdraw(num,1);
                break;
            case 3:
				ENTER_ACCOUNT
				deposit_withdraw(num,2);
				menuID = 3;
                break;
			case 4:
				system("cls");
				ENTER_ACCOUNT
				display_sp(num);
				break;
            case 5:
				ENTER_ACCOUNT
				modify_account(num);
				break;
			case 6:
				ENTER_ACCOUNT
				delete_account(num);
				break;
			case 7:
				exit(3);
			
        }
    }
    menu(option,maxOptions,mainMenuOptions);
    
}
}

//!     file operation functions


void write_account()
{
    system("cls");
	account ac;
	ofstream outFile;
	outFile.open("account.dat",ios::binary|ios::app);
	ac.create_account();
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
	outFile.close();
    getch();
    menuID = 0;
    mainMenu();
}

//!    	function to read specific record from file

void display_sp(int n)
{
    system("cls");
	account ac;
	bool flag=false;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\nBALANCE DETAILS\n";

    	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if(ac.returnAccountNumber()==n)
		{
			ac.show_account();
			flag=true;
		}
	}
	inFile.close();
	if(flag==false)
		cout<<"\n\nAccount number does not exist";
    getch();
    menuID = 0;
    mainMenu();
}


//!    	function to modify record of file

void modify_account(int n)
{
    system("cls");
	bool found=false;
	account ac;
	fstream File;
	File.open("account.dat",ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.returnAccountNumber()==n)
		{
			ac.show_account();
			cout<<"\n\nEnter The New Details of account"<<endl;
			ac.modify();
			int pos=(-1)*static_cast<int>(sizeof(account));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			cout<<"\n\n\t Record Updated";
			found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"\n\n Record Not Found ";
    getch();
    menuID = 0;
    mainMenu();
}

//!    	function to delete record of file


void delete_account(int n)
{
    system("cls");
	account ac;
	ifstream inFile;
	ofstream outFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	outFile.open("Temp.dat",ios::binary);
	inFile.seekg(0,ios::beg);
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		if(ac.returnAccountNumber()!=n)
		{
			outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
		}
	}
	inFile.close();
	outFile.close();
	remove("account.dat");
	rename("Temp.dat","account.dat");
	cout<<"\n\n\tRecord Deleted ..";
    getch();
    menuID = 0;
    mainMenu();
}


//!    	function to display all accounts deposit list

void display_all()
{
    system("cls");
	account ac;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	cout<<"\n\n\t\tACCOUNT HOLDER LIST\n\n";
	cout<<"====================================================\n";
	cout<<"A/c no.      NAME           Type  Balance\n";
	cout<<"====================================================\n";
	while(inFile.read(reinterpret_cast<char *> (&ac), sizeof(account)))
	{
		ac.report();
	}
	inFile.close();
    getch();
    menuID = 0;
    mainMenu();
}

//!function to deposit and withdraw amounts
void deposit_withdraw(int n, int option)
{
    system("cls");
	int amt;
	bool found=false;
	account ac;
	fstream File;
	File.open("account.dat", ios::binary|ios::in|ios::out);
	if(!File)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}
	while(!File.eof() && found==false)
	{
		File.read(reinterpret_cast<char *> (&ac), sizeof(account));
		if(ac.returnAccountNumber()==n)
		{
			ac.show_account();
			if(option==1)
			{
				cout<<"\n\n\tTO DEPOSITE AMOUNT ";
				cout<<"\n\nEnter The amount to be deposited";
				cin>>amt;
				ac.dep(amt);
			}
			if(option==2)
			{
				cout<<"\n\n\tTO WITHDRAW AMOUNT ";
				cout<<"\n\nEnter The amount to be withdraw";
				cin>>amt;
				int bal=ac.retdeposit()-amt;
				if((bal<500 && ac.rettype()=='S') || (bal<1000 && ac.rettype()=='C'))
					cout<<"Insufficience balance";
				else
					ac.draw(amt);
			}
			int pos=(-1)*static_cast<int>(sizeof(ac));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			cout<<"\n\n\t Record Updated";
			found=true;
	       }
         }
	File.close();
	if(found==false)
		cout<<"\n\n Record Not Found ";
    getch();
    menuID = 0;
    mainMenu();
}