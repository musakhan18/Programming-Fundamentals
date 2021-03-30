//#include<iostream>
//#include<fstream>
//#include<string>
//using namespace std;
//int main()
//{
//	char arr[100];
//	int count = 0;
//	string s;
//	fstream task;
//	task.open("inputfile.txt");
//	while (getline(task,s))
//	{
//		for (int i = 0; i < s.size(); i++)
//		{
//			if (s[i] != ' ')
//			{
//				arr[count] += s[i];
//			}
//			if (s[i] == ' ')
//			{
//				count++;
//			}
//		}
//		count++;
//	}
//	task.close();
//	fstream output;
//	output.open("out.txt");
//	output << "total words are: " << count << endl;
//
//}
#include<iostream>
#include<string>
using namespace std;
int main()
{
	string s = "UNIVERSITY";
	cout << s.substr(3, 4);
	return 0;
}