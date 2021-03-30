#include<iostream>
#include<fstream>
#include<string>
using namespace std;


bool passwordCorrection(string pass)
{
	int len=pass.size();	
	
	if(len<6)
	return false;
	
	else
	{
		for (int i=0;i<len;i++)
		{
			if(int(pass[i])>47 && int(pass[i])<58)
			return true;
			
		}
		
		return false;
		
	}
	
}


int main()
{
	
	//creating a file 
	ofstream file;
	file.open("UserData.txt",ios::out|ios::app);
	// file has been created 
	
	string username, password;
	cout<<"Please enter your Username: "<<endl;
	getline(cin, username);
	// read username/Email of user
	
	
	cout<<"please enter your Password: "<<endl;
	getline(cin, password);
	// read password of user
	
	bool status=false;
	while (status==false)
	{
		status=passwordCorrection(password);
		if(status==false)
		{
		cout<<"In-correct password, please enter your Password again: (It must include a digit and length should be greater than 5)"<<endl;
		getline(cin, password);
		// read password of user again
			
		}
	}
	
	cout<<endl<<"Saving your data into data file...";
	
	file<<username<<endl;
	file<<password<<endl;
	file.close();
	cout<<"\nData saved...";
	return 0;
}
