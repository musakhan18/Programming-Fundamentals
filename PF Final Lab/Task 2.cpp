#include<iostream>
#include<fstream>
#include<string>
using namespace std;
void read_file(int sindh[], int punjab[], int bloch[], int gilgit[],int  khyber[])
{
	 
	fstream file("punjab.txt", ios::in);
	char ignore[100];
	for (int i = 0; !file.eof(); i++)
	{
		file.getline(ignore, 1000, '=');
		file >> punjab[i];
	}
	file.close();
	fstream file2("sindh.txt", ios::in);
	for (int i = 0; !file2.eof(); i++)
	{
		file2.getline(ignore, 1000, '=');
		file2 >> sindh[i];

	}
	file2.close();
	fstream file3("bloch.txt", ios::in);
	for (int i = 0; !file3.eof(); i++)
	{
		file3.getline(ignore, 1000, '=');
		file3 >> bloch[i];

	}
	file3.close();
	fstream file4("gilgit.txt", ios::in);
	for (int i = 0; !file4.eof(); i++)
	{
		file4.getline(ignore, 1000, '=');
		file4 >> gilgit[i];

	}
	file4.close();
	fstream file5("khyber.txt", ios::in);
	for (int i = 0; !file5.eof(); i++)
	{
		file5.getline(ignore, 1000, '=');
		file5 >> khyber[i];

	}
	file5.close();
	/*display(punjab, sindh, bloch, gilgit, khyber);*/
}
int main()
{
	int sindh[1000]; int punjab[1000]; int bloch[100], gilgit[1000], khyber[1000];
	read_file(punjab, sindh, bloch, gilgit, khyber);
	int ven = punjab[5] + sindh[5] + bloch[5] + khyber[5] + gilgit[5];
	int test = punjab[3] + sindh[3] + bloch[3] + khyber[3] + gilgit[3];
	int death = punjab[2] + sindh[2] + bloch[2] + khyber[2] + gilgit[2];
	int recv = punjab[1] + sindh[1] + bloch[1] + khyber[1] + gilgit[1];
	int total = punjab[0] + sindh[0] + bloch[0] + khyber[0] + gilgit[0];

    cout << "Total No Of Patients In Pakistan\t\t:\t" << total << endl;
	cout << "Total No Of Recovered Patients In Pakistan\t:\t" << recv << endl;
	cout << "Total No Of Deaths In Pakistan\t\t\t:\t" <<death<< endl;
	cout << "Province Running Maximum No of Tests Per Day\t:\t" << test << endl;
	cout << "Total No Of Ventilators In Pakistan\t\t:\t" <<ven  << endl;
	return 0;
}
