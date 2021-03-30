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
	ifstream file;
	file.open("UserData.txt",ios::in);
	// file has been created 
	
	string username, password;
	cout<<"Please enter your Username: "<<endl;
	getline(cin, username);
	// read username/Email of user
	
	
	cout<<"please enter your Password: "<<endl;
	getline(cin, password);
	// read password of user
	
	string list[10000];
	string xyz;
	int counter=0;
	while (getline(file, xyz))
	{
		list[counter]=xyz;
//		cout<<list[counter]<<endl;
//		cout<<xyz;
		counter++;
	}
	
	bool status=false;
	for ( int i=0;i<counter;i=i+2)
	{
//		cout<<sizeof(username)<<"-"<<username<<" : "<<sizeof(list[i])<<"-"<<list[i]<<endl;
//		cout<<password<<" : "<<list[i+1]<<endl;
		
		
		if(list[i]==username)
		{
//			cout<<"username matched";
			if(list[i+1]==password)
			{
				status = true;
//				cout<<"Passed.... "<<endl<<endl;
			}
		}
		
		
	}
	
	if(status==true)
	cout<<"Login Successfull...";
	else
	cout<<"Invalid username OR Password";
	
	
	return 0;
}
