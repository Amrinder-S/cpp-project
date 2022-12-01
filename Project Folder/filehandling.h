#include<fstream>
#include "account.h"
account a;

bool searchAccount(int n) {
	using namespace std;
	account acc;
	bool found = false;
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

void saveAccount(account acc) {
	using namespace std;
	fstream file;
	file.open("account.dat",ios::out|ios::binary | ios::app);
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
		errorBox("Error in opening file!!!");
		return -1;
	}
	while(file.read((char*)&acc,sizeof(acc)))
	{
		if(acc.returnAccountNumber()>n)
			n=acc.returnAccountNumber();
	}
	file.close();
	return n+1;
}