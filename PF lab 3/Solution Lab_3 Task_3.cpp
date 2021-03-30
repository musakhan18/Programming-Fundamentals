

#include<iostream>
#include<fstream>
#include<string>
using namespace std;
string word[10000];
string words[10000];
int counter=0;


void splitWords(string s)
{
	
	int start=0;
	int i=0;
	words[counter]="";
	for (i=0;i<s.size();i++)
	{
//		cout<<s[i];
		if(s[i]!=' ')
		{
			words[counter]+=s[i];
		}
		
		if(s[i]==' ')
		{
//			word[counter]=s.substr(start, i-start);
//			start=i+1;
			
//			cout<<endl<<"Word: "<<s.substr(start, i-start)<<" # "<<start<<"-"<<i-start<<endl;
			counter++;
		}
		
	}
//	word[counter]=s.substr(start, i-start);
		counter++;	
}




int main()
{
	
	//creating a file 
	ifstream file;
	file.open("textfile.txt",ios::in);
	// file has been created 
	
	string word;
	cout<<"Please enter a word: "<<endl;
	getline(cin, word);
	// read username/Email of user
	
	string line;
	while(getline(file, line))
	{
//		cout<<"\nLine found: "<<line<<endl;
		splitWords(line);
		
	}
	cout<<"\n\n______________ OUTPUT ____________________-\n\nTotal words found in the file: "<<counter;
	
	int wordCount=0;
	for (int i=0;i<counter;i++)
	{
//		cout<<endl<<word<<" - "<<word.size()<<" Vs "<<words[i]<<" - "<<words[i].size()<<endl;
		if(word==words[i])
		wordCount++;
	}

	
	cout<<"\n OUTPUT: Entered Word '"<<word<<"' appeard '"<<wordCount<<"' times in file. ";
	return 0;
}
