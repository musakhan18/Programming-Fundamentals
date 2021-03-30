

#include<iostream>
#include<fstream>
#include<string>
using namespace std;
string uniqueWords[10000];
string words[10000];
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
	
	int unqIndex=0;
	for (int i=0;i<counter;i++)
	{ 	
		int unqCount=0;
		for(int j=0;j<unqIndex;j++)
		{
	
		if(words[i]==uniqueWords[j])
		unqCount++;
	
		}
		if(unqCount==0)
		{
			uniqueWords[unqIndex]=words[i];
			unqIndex++;
		}
		
		
	}

	
	cout<<"\n OUTPUT: \nThese are unique words found in file: "<<unqIndex<<"\n\n";
	for(int k=0;k<unqIndex;k++)
		cout<<uniqueWords[k]<<" ";
	
	
	return 0;
}
