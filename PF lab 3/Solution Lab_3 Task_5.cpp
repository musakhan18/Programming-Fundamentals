

#include<iostream>
#include<fstream>
#include<string>
using namespace std;
string uniqueWords[10000];
string words[10000];
int frequency[10000];
int counter=0;


void splitWords(string s)
{
	
	int start=0;
	int i=0;
	words[counter]="";
	for (i=0;i<s.size();i++)
	{
		if(s[i]!=' ')
		{
			words[counter]+=s[i];
		}
		
		if(s[i]==' ')
		{
			counter++;
		}
		
	}
		counter++;	
}




int main()
{
	
	//creating a file 
	ifstream file;
	file.open("textfile.txt",ios::in);
	// file has been created 
	
	
	string line;
	while(getline(file, line))
	{
		splitWords(line);
		
	}
	cout<<"\n\n______________ OUTPUT ____________________-\n\nTotal words found in the file: "<<counter;
	cout<<"\n\n------------------------------------------------------------\nWord\t\t"<<"Frequency\n------------------------------------------------------------\n";

	for (int i=0;i<counter;i++)
	{ 		
		int frq=0;
		for(int j=0;j<counter;j++)
		{
	
		if(words[i]==words[j])
		frq++;
	
		}
	cout<<endl<<words[i]<<" - \t\t"<<frq;
		
		
	}

	
//	cout<<"\n OUTPUT: \nThe Frquency of "<<unqIndex<<" words in file is as following: \n\n";
//	for(int k=0;k<unqIndex;k++)
//	{
//	}
	
	
	return 0;
}
