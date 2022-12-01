#include<fstream>
#include "account.h"
account a;

bool searchAccount(int n) {
	using namespace std;
	bool found = false;
	account acc;
	fstream file;
	file.open("account.dat",ios::in|ios::binary);
	if(!file){
		errorBox("Error in opening file!!!");
		return -1;
	}
	while(file.read((char*)&acc,sizeof(acc)))
	{
		if(acc.returnAccountNumber()==n)
			{
				found = true;
				a = acc;
			}
	}
	file.close();
	return found;
}

void saveAccount(account acc, int newFile) {
	using namespace std;
	fstream file;
	if(!newFile)
		file.open("account.dat",ios::out|ios::binary | ios::app);
	else
		file.open("temp.dat",ios::out|ios::binary | ios::app);
	
	if(!file){
		errorBox("Error in creating the file!!!");
	}
	file.write((char*)&acc,sizeof(acc));
	file.close();
}

int getAvailableAccountNumber()
{
	using namespace std;
	account acc;
	int n=0;
	fstream file;
	file.open("account.dat",ios::in|ios::binary);
	if(!file){
		file.open("account.dat",ios::out|ios::binary);
	}
	while(file.read((char*)&acc,sizeof(acc)))
	{
		if(acc.returnAccountNumber()>n)
			n=acc.returnAccountNumber();
	}
	file.close();
	return n+1;
}

void removeAccount(int n)
{
	using namespace std;
	account acc;
	fstream file;
	file.open("account.dat",ios::in|ios::binary);
	if(!file){
		errorBox("Error in opening file!!!");
	}
	while(file.read((char*)&acc,sizeof(acc)))
	{
		if(acc.returnAccountNumber()!=n)
			{
				saveAccount(acc, 1);
			}
	}
	system("rename temp.dat account.dat > nul && delete temp.dat > nul");
	file.close();
}

void updateAccount()
{
	removeAccount(a.returnAccountNumber());
	saveAccount(a, 0);
}