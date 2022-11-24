#include<fstream>
#include<cctype>
#include<iomanip>
#include<iostream>
#include<windows.h>
#include<conio.h>
#include<cstdlib>
#include<string>
#define ENTER_ACCOUNT 	system("cls");printLogo(47);print(xindex, yindex+1, 0, "Enter account number: ");int n;cin>>n;
#define MAIN_MENU 0
int xindex=10,yindex=7;
using namespace std;
COORD coord = {0,0};
HANDLE console_color = GetStdHandle(STD_OUTPUT_HANDLE);
int menuID = 0;
//!			to set window size
HWND WINAPI GetConsoleWindowNT(void)
{
    typedef HWND WINAPI(*GetConsoleWindowT)(void);
    GetConsoleWindowT GetConsoleWindow;
    HMODULE hk32Lib = GetModuleHandle(TEXT("KERNEL32.DLL"));
    GetConsoleWindow = (GetConsoleWindowT)GetProcAddress(hk32Lib, TEXT("GetConsoleWindow"));
    if(GetConsoleWindow == NULL){
        return NULL;
    }
    return GetConsoleWindow();
}
//!			Class definition
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

//!    	function declaration
void insertLines (int x);
void write_account();
void display_sp();
void modify_account();
void delete_account();	
void display_all();		
void deposit_withdraw(int, int); 
void menu(int option, int size,string x[]);
void mainMenu();
void print(int x,int y,int erase,const std::string& s);
void gotoxy(int, int);
void printLogo(int);
//!     main function
int main()
{
	HWND hWnd=GetConsoleWindowNT();
    MoveWindow(hWnd,100,50,1000,500,TRUE);
	system("title C++ Project by Amrinder Singh ^|^| Bank System using OOP && cls");
mainMenu();
return 0;
}


//!     file operation functions


void write_account()
{
	account ac;
	ofstream outFile;
	outFile.open("account.dat",ios::binary|ios::app);
	ac.create_account();
	outFile.write(reinterpret_cast<char *> (&ac), sizeof(account));
	outFile.close();
    menuID = 0;
    mainMenu();
}

//!    	function to read specific record from file

void display_sp()
{
ENTER_ACCOUNT
	account ac;
	bool flag=false;
	ifstream inFile;
	inFile.open("account.dat",ios::binary);
	if(!inFile)
	{
		cout<<"File could not be open !! Press any Key...";
		return;
	}

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
	{
		SetConsoleTextAttribute(console_color, 4);
		print(xindex, yindex+5, 0, "Record not found.");
		SetConsoleTextAttribute(console_color, 15);

	}
    getch();
    menuID = 0;
    mainMenu();
}


//!    	function to modify record of file

void modify_account()
{
ENTER_ACCOUNT
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
			print(xindex, yindex+2, 0, "Enter new details of the account.");
			ac.modify();
			int pos=(-1)*static_cast<int>(sizeof(account));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			ac.show_account();
			SetConsoleTextAttribute(console_color, 47);
			print(43, yindex-2, 15,"| Record Updated!");
			SetConsoleTextAttribute(console_color, 15);
			found=true;
		  }
	}
	File.close();
	if(found==false)
		cout<<"\n\n Record Not Found ";
    getch();
	system("cls");
    menuID = 0;
    mainMenu();
}

//!    	function to delete record of file


void delete_account()
{
ENTER_ACCOUNT
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
		else
			ac.show_account();
	}
	inFile.close();
	outFile.close();
	remove("account.dat");
	rename("Temp.dat","account.dat");
	SetConsoleTextAttribute(console_color, 4);
	print(xindex, yindex+5, 0, "Record Deleted!!");
	SetConsoleTextAttribute(console_color, 15);
    getch();
    menuID = 0;
    mainMenu();
}


//!function to deposit and withdraw amounts
void deposit_withdraw(int option)
{
ENTER_ACCOUNT
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

				print(xindex, yindex+1, 0, "Enter The amount to be deposited: ");
				cin>>amt;
				if(amt<0) amt=-amt;
				ac.dep(amt);
				print(xindex, yindex+2, 0, "Amount "+to_string(amt)+" deposited");
			}
			if(option==2)
			{
				print(xindex, yindex+1, 0, "Enter The amount to be withdrawn: ");
				cin>>amt;
				if(amt<0) amt=-amt;
				int bal=ac.retdeposit()-amt;
				if((bal<500 && ac.rettype()=='S') || (bal<1000 && ac.rettype()=='C'))
					print(xindex, yindex+2, 0, "Enter The amount to be withdrawn: ");
				else
					ac.draw(amt);
				print(xindex, yindex+3, 0, "Amount "+to_string(amt)+" withdrawn.");
			}
			int pos=(-1)*static_cast<int>(sizeof(ac));
			File.seekp(pos,ios::cur);
			File.write(reinterpret_cast<char *> (&ac), sizeof(account));
			ac.show_account();
			SetConsoleTextAttribute(console_color, 47);
			print(43, yindex-2, 25,"| Record Updated!");
			SetConsoleTextAttribute(console_color, 15);
			found=true;
	       }
         }
	File.close();
	if(found==false)
		print(xindex, yindex+5, 0, "Record not found!");
    getch();
	system("cls");
    menuID = 0;
    mainMenu();
}

//!         function definitions
void menu(int option, int size,std::string x[])
{
    for(int i=0;i<size;i++)
    {
        
        if(option==(i+1))
        {
            if(i==size-1) SetConsoleTextAttribute(console_color, 4); else SetConsoleTextAttribute(console_color, 10);
            print(10, 7+i, x[i].length() + 14,  "--->   "+x[i]+"   <---");
            SetConsoleTextAttribute(console_color, 15);
        }
        else
            print(10, 7+i, x[i].length() + 14, x[i]);
    }
}


void mainMenu()
{
int maxOptions = 7; // Max Options means number of items in the menu
string mainMenuOptions[] = 
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
printLogo(48);
menu(option,maxOptions,mainMenuOptions);
char ch;
void (*p[6])(void);
p[0] = &write_account;
p[1] = NULL;
p[2] = NULL;
p[3] = &display_sp;
p[4] = &modify_account;
p[5] = &delete_account;
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
		if(option==2 || option==3)
			deposit_withdraw(option-1);
		else if(option==7)
			{system("cls");exit(3);}
		else
			p[option-1]();
    }
    menu(option,maxOptions,mainMenuOptions);
}
}

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

void insertLines (int x) {for(int i=0;i<x;i++)cout<<"\n";}


//Class definition

void account::create_account()
{
	system("cls");
	printLogo(47);
	print(xindex, yindex, 0, "Enter the account number:");
	cin>>account_number;
	print(xindex, yindex+1, 0, "Enter name of the account holder:");
	print(xindex, yindex+2, 0, "-> ");
	cin.ignore();
	cin.getline(name,50);
	print(xindex, yindex+3, 0, "Enter the type of account(C/S):");
	cin>>type;
	type=toupper(type);
	print(xindex, yindex+4, 0, "Enter the initial amount:");
	cin>>deposit;
	print(xindex, yindex+5, 0, "Account Successfully Created!");
	getch();
	system("cls");
}

void account::show_account() const
{
	SetConsoleTextAttribute(console_color, 47);
	print(43, yindex-6, 0, "| Account number: ");
	cout<<account_number;
	print(43, yindex-5, 0, "| Name: ");
	cout<<name;
	print(43, yindex-4, 0, "| Type: ");
	cout<<type;
	print(43, yindex-3, 0,"| Balance: ");
	cout<<deposit<<"        ";
	print(43, yindex-2, 0,"|");
	SetConsoleTextAttribute(console_color, 15);
}


void account::modify()
{
	print(xindex, yindex+3, 0, "Account Number: ");
	cout<<account_number;
	print(xindex, yindex+4, 0, "Modify Account Holder Name : ");
	cin.ignore();
	cin.getline(name,50);
	print(xindex, yindex+5, 0, "Modify Type of Account(C/S) : ");
	cin>>type;
	type=toupper(type);
	print(xindex, yindex+6, 0, "Modify Balance amount : ");
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
void printLogo(int color)
{
std::cout<<"                                                                  ";
int index=5;
SetConsoleTextAttribute(console_color, color);
print(index,1,0,"         /    /\\.        \\      THE                               ");
print(index,2,0,"        (    (` -`7       )    BANK                               ");
print(index,3,0,"         \\    |  -\\      /      OF                                ");
print(index,4,0,"          \\   c_ c.)_/  /      CATS                               ");
print(index,5,0,"           \\           /                                          ");
		SetConsoleTextAttribute(console_color, 15);
for(int i=0;i<12;i++)
	{
	print(index,6+i,0,"|");
	print(65+index,6+i,0,"|");
	}
for(int i=index+1;i<65+index;i++)
	print(i, 17, 0, "_");
}