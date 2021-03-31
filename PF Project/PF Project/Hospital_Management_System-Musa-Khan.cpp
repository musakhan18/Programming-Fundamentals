#include<iostream>
#include<fstream>
#include<string>
#include<ctime>
using namespace std;

int size(char arr[]);
string* regrow(string* OldArray, string value, int size);
void copy(string* OldArray, string* new_array, int size);
int signUPorIN();
void signup();
void ByWho(string arr[]);
int menu();
char service(int num);
void OPD(string Ename, string Eid);
void Emergency(string Ename, string Eid);
int SearchByName(int num);
int SearchById(int num);
void Edit(int x, int num);
void WriteInFile(int num, char name[], char disease[], string doctor, int id, int age, char gen, int roomN, string Ename, string Eid);
void WriteInDoc(string line[], char doctor[], int sizeS, int x);
void Doctor();
void List(int num);
void Discharge(int x, int num);

int main()
{
	string use, pass, un, Ino, arr[1000], id, Sname;
	int d = 0, c = 0, yes = 1, task, place = 0, x = 0, num;
	char ser;
	/*arr = new string[sizeN];*/
	string str, strr;
	cout << "                                                 ****************" << endl;
	cout << "                                                 <<  Hospital  >>" << endl;
	cout << "                                                 << Management >>" << endl;
	cout << "                                                 <<   System   >>" << endl;
	cout << "                                                 <<     By     >>" << endl;
	cout << "                                                 <<  Musa Khan >>" << endl;
	cout << "                                                 ****************" << endl;
	cout << endl;
	do
	{
		int choose = signUPorIN();

		if (choose == 1)
		{
			cout << endl << "Enter username: "; cin >> use;
			cout << "Enter password: "; cin >> pass;
			ifstream file;
			file.open("pass.txt");
			if (file)
			{
				while (!file.eof())
				{
					file >> str >> strr;
					if (str == use && strr == pass)
					{
						d = 1;
						place = x;
					}
					x++;
				}
			}
			if (d == 1)
			{
				cout << endl;
				ByWho(arr);
				un = arr[place - 1]; Ino = arr[place];
				cout << "Login sussesfull!" << endl << endl;
				cout << "  Username: " << un << "\t\t\t\t " << "UserID: " << Ino << endl << endl;
				do
				{
					yes = 1;
					cout << endl;
					task = menu();
					cout << endl;
					if (task == 1) //To add Patient
					{
						num = 1;
						ser = service(num);
						if (ser == 'd' || ser == 'D') //To add patient in OPD
						{
							while (yes == 1)
							{
								OPD(un, Ino);

								cout << "press (0) to choose your task." << endl;
								cout << "Press (1) to continue Adding patients in OPD." << endl;
								cin >> yes;
								while (yes != 0 && yes != 1)
								{
									cout << "Invalid Input" << endl;
									cout << "press (0) to choose your task." << endl;
									cout << "Press (1) to continue Adding patients in OPD." << endl;
									cin >> yes;
								}
							}
						}
						if (ser == 'm' || ser == 'M')
						{
							while (yes == 1)
							{
								Emergency(un, Ino);

								cout << "press (0) to choose your task." << endl;
								cout << "Press (1) to continue Adding patients in Emergency." << endl;
								cin >> yes;
								while (yes != 0 && yes != 1)
								{
									cout << "Invalid Input" << endl;
									cout << "press (0) to choose your task." << endl;
									cout << "Press (1) to continue Adding patients in Emergency." << endl;
									cin >> yes;
								}
							}
						}
					}
					if (task == 2)
					{
						num = 2;
						ser = service(num);
						if (ser == 'd' || ser == 'D')
						{
							while (yes != 0)
							{
								cout << endl;
								num = 3;
								ser = service(num);
								if (ser == 'n' || ser == 'N')
								{
									while (yes != 0)
									{
										int num = 1;
										int want = SearchByName(num);
										if (want >= 1)
										{
											cout << endl;
											cout << "Press (E) to Edit This Record." << endl;
											cout << "Press (C) to Discharge this patient." << endl;
											cout << "Press (0) to Choose Your Task." << endl;
											cin >> ser;
											if (ser == 'E' || ser == 'e')
											{
												want -= 1;
												cout << endl;
												Edit(want, num);
												yes = 0;
											}
											if (ser == 'c' || ser == 'C')
											{
												want -= 1;
												num = 1;
												Discharge(want, num);
												yes = 0;
											}
											else
											{
												yes = 0;
											}
										}
										else
										{
											yes = 0;
										}
									}
								}
								if (ser == 'i' || ser == 'I')
								{
									while (yes != 0)
									{
										num = 1;
										int want = SearchById(num);
										if (want >= 1)
										{
											cout << endl;
											cout << "Press (E) to Edit This Record." << endl;
											cout << "Press (C) to Discharge this patient." << endl;
											cout << "Press (0) to Choose Your Task." << endl;
											cin >> ser;
											if (ser == 'E' || ser == 'e')
											{
												want -= 1;
												cout << endl;
												Edit(want, num);
												yes = 0;
											}
											if (ser == 'c' || ser == 'C')
											{
												want -= 1;
												num = 1;
												Discharge(want, num);
												yes = 0;
											}
											else
											{
												yes = 0;
											}
										}
										if (want == 0)
										{
											yes = 0;
										}
									}
								}
							}
						}
						if (ser == 'M' || ser == 'm')
						{
							while (yes != 0)
							{
								cout << endl;
								num = 3;
								ser = service(num);
								if (ser == 'n' || ser == 'N')
								{
									int num = 2;
									int want = SearchByName(num);
									if (want >= 1)
									{
										cout << endl;
										cout << "Press (E) to Edit This Record." << endl;
										cout << "Press (C) to Discharge this patient." << endl;
										cout << "Press (0) to Choose Your Task." << endl;
										cin >> ser;
										if (ser == 'E' || ser == 'e')
										{
											while (yes != 0)
											{
												want -= 1;
												cout << endl;
												Edit(want, num);
												yes = 0;
											}
										}
										if (ser == 'c' || ser == 'C')
										{
											want -= 1;
											num = 2;
											Discharge(want, num);
											yes = 0;
										}
										else
										{
											yes = 0;
										}
									}
									if (want == 0)
									{
										yes = 0;
									}
								}
								if (ser == 'i' || ser == 'I')
								{
									while (yes != 0)
									{
										num = 2;

										int want = SearchById(num);
										if (want >= 1)
										{
											while (yes != 0)
											{
												cout << endl;
												cout << "Press (E) to Edit This Record." << endl;
												cout << "Press (C) to Discharge this patient." << endl;
												cout << "Press (0) to Choose Your Task." << endl;
												cin >> ser;
												if (ser == 'E' || ser == 'e')
												{
													while (yes != 0)
													{
														want -= 1;
														cout << endl;
														Edit(want, num);
														yes = 0;
													}
												}
												if (ser == 'c' || ser == 'C')
												{
													want -= 1;
													num = 2;
													Discharge(want, num);
													yes = 0;
												}
												else
												{
													yes = 0;
												}
											}
										}
										if (want == 0)
										{
											yes = 0;
										}
									}
								}
							}
						}
					}
					if (task == 3)
					{
						while (yes != 0)
						{
							Doctor();
							yes = 0;
						}
					}
					if (task == 4)
					{
						while (yes != 0)
						{
							num = 4;
							ser = service(num);
							if (ser == 'd' || ser == 'D')
							{
								num = 1;
								List(num);
								yes = 0;
							}
							else if (ser == 'm' || ser == 'M')
							{
								num = 2;
								List(num);
								yes = 0;
							}
							else if (ser == 't' || ser == 'T')
							{
								num = 3;
								List(num);
								yes = 0;
							}
						}

					}
					if (task == 5)
					{
						c = 1;
					}
				} while (yes == 0);
			}
			else
			{
				cout << "User not found!" << endl << endl;
				c = 1;
				x = 0;
				place = 0;
			}

		}
		if (choose == 2)
		{
			signup();
			c = 1;
			cout << endl;
		}
	} while (c == 1);
}

int signUPorIN()
{
	int choose;
	cout << "Already a user Press (1) to login" << endl;
	cout << "Not a user yet press (2) to sign up" << endl;
	cin >> choose;
	if (choose != 2 || choose != 1)
	{
		while (choose > 2 || choose < 1)
		{
			cout << endl;
			cout << "Invalid input!!" << endl;
			cout << "Press (1) login" << endl;
			cout << "Press (2) sign up" << endl;
			cin >> choose;
		}
		return choose;
	}
}

string* regrow(string* OldArray, string value, int size)
{
	string* new_array = NULL;
	new_array = new string[size + 1];
	for (int i = 0; i < size; i++)
	{
		new_array[i] = OldArray[i];
	}
	new_array[size - 1] = value;
	delete[] OldArray;
	return new_array;
}

void copy(string* OldArray, string* new_array, int size)
{
	new_array = new string[size];
	for (int i = 0; i < size; i++)
	{
		new_array[i] = OldArray[i];
	}
}

int size(char arr[])
{
	int size = 0;
	while (arr[size] != '\0')
	{
		size++;
	}
	return size;
}

void signup()
{
	string use, pass, s;
	char* Fname = new char[100];
	int sizeP, sizeU, size = 0, id;
	/*ifstream file;
	file.open("pass.txt");
	while (getline(file,s))
	{
		size++;
	}
	string* arr = new string[size];
	while (!file.eof())
	{
		for (int i = 0; i < size; i++)
		{
			file >> arr[i];
		}
	}*/
	ofstream write;
	write.open("name.txt", ios::app);
	cout << "Enter following details to make profile:" << endl;
	cout << endl;
	cout << "Enter username: "; cin >> use;
	/*bool flag = true;
	for (int i = 0; i < size; i++)
	{
		if (arr[i]==use)
		{
			flag = false;
		}
	}
	while (!flag)
	{
		cout << "This Username is already Taken!" << endl;
		cout << "Enter username: "; cin >> use;
		for (int i = 0; i < size; i++)
		{
			if (arr[i] == use)
			{
				flag = false;
			}
			else
			{
				flag = true;
			}
		}
	}
	delete[]arr;
	file.close();*/
	cout << "Enter password (must have more then 6 characters): "; cin >> pass;
	sizeP = pass.size();
	if (sizeP < 6)
	{
		while (sizeP < 6)
		{
			cout << "password is too short!" << endl;
			cout << "Enter password (must have more then 6 characters): "; cin >> pass;
			sizeP = pass.size();
		}
	}
	cout << "Enter your Name: "; cin >> Fname;
	srand((unsigned)time(0));
	id = rand();
	cout << "Your id number is: " << id << endl;
	cout << "Successfully signed up!" << endl << endl;
	ofstream data;
	data.open("pass.txt", ios::app);
	data << use << endl << pass << endl;
	write << Fname << endl << id << endl;
	delete[]Fname;
	data.close();
	write.close();
}

void ByWho(string arr[])
{
	int sizeN = 0;
	ifstream By;
	By.open("name.txt");
	while (!By.eof())
	{

		By >> arr[sizeN];
		sizeN++;
	}
}

int menu()
{
	cout << "********************************************** <<<  Menu  >>> **************************************************" << endl;
	cout << endl;
	int task;
	cout << "Enter your task number: " << endl;
	cout << "Press (1) to Add new patient." << endl;
	cout << "Press (2) to Search a patient." << endl;
	cout << "Press (3) to Add Doctor." << endl;
	cout << "Press (4) to See the List of patients." << endl;
	cout << "Press (5) to Logout." << endl;
	cin >> task;
	if (task != 1 && task != 2 && task != 3 && task != 4 && task != 5)
	{
		while (task != 1 && task != 2 && task != 3 && task != 4 && task != 5)
		{
			cout << "Invalid input please choose the right option." << endl;
			cout << "Press (1) to Add new patient." << endl;
			cout << "Press (2) to Search a patient." << endl;
			cout << "Press (3) to Add Doctor." << endl;
			cout << "Press (4) to See the List of patients." << endl;
			cout << "Press (5) to Logout." << endl;
			cin >> task;
		}
	}
	return task;
}

char service(int num)
{
	char ser;
	if (num == 1)
	{
		cout << "Where you want add the patient." << endl;
		cout << "Press (D) for OPD" << endl;
		cout << "Press (M) for Emergency" << endl;
		cin >> ser;
		cout << endl;
		while (ser != 'm' && ser != 'M' && ser != 'D' && ser != 'd')
		{
			cout << "Invalid input" << endl;
			cout << "Where you want add the patient." << endl;
			cout << "Press (D) for OPD" << endl;
			cout << "Press (M) for Emergency" << endl;
			cin >> ser;
		}
		return ser;
	}
	if (num == 2)
	{
		cout << "From Where You Want Search The Patient Record." << endl;
		cout << "Press (D) for OPD Service" << endl;
		cout << "Press (M) for Emergency Service" << endl;
		cin >> ser;
		cout << endl;
		while (ser != 'm' && ser != 'M' && ser != 'D' && ser != 'd')
		{
			cout << "Invalid input" << endl;
			cout << "From Where You Want Search The Patient Record." << endl;
			cout << "Press (D) for OPD Service" << endl;
			cout << "Press (M) for Emergency Service" << endl;
			cin >> ser;
		}
		return ser;
	}
	if (num == 3)
	{
		cout << "Press (N) To Search Patient By Name." << endl;
		cout << "Press (I) To Search Patient By ID No." << endl;
		cin >> ser;
		cout << endl;
		while (ser != 'n' && ser != 'N' && ser != 'i' && ser != 'I')
		{
			cout << "Invalid input" << endl;
			cout << "Press (N) To Search Patient By Name." << endl;
			cout << "Press (I) To Search Patient By ID No." << endl;
			cin >> ser;
		}
		return ser;
	}
	if (num == 4)
	{
		cout << "Which list you want to see." << endl;
		cout << "Press (D) for OPD" << endl;
		cout << "Press (M) for Emergency" << endl;
		cout << "Press (T) for Doctors" << endl;
		cin >> ser;
		cout << endl;
		while (ser != 'm' && ser != 'M' && ser != 'D' && ser != 'd' && ser != 't' && ser != 'T')
		{
			cout << "Invalid input" << endl;
			cout << "Which list you want to see." << endl;
			cout << "Press (D) for OPD" << endl;
			cout << "Press (M) for Emergency" << endl;
			cout << "Press (T) for Doctors" << endl;
			cin >> ser;
		}
		return ser;
	}
	if (num == 5)
	{
		cout << "From where you want Discharge the patient." << endl;
		cout << "Press (D) for OPD" << endl;
		cout << "Press (M) for Emergency" << endl;
		cin >> ser;
		cout << endl;
		while (ser != 'm' && ser != 'M' && ser != 'D' && ser != 'd')
		{
			cout << "Invalid input" << endl;
			cout << "From where you want Discharge the patient." << endl;
			cout << "Press (D) for OPD" << endl;
			cout << "Press (M) for Emergency" << endl;
			cin >> ser;
		}
		return ser;
	}
}

void OPD(string Ename, string Eid)
{
	char* name = new char[100]; char* disease = new char[100];
	int id, age, OroomCh[6], OroomN, Oroom, size = 0; bool flag = false;
	char gen; string doctor, s;
	string* doc = new string[100]; char* spac = new char[100];
	ofstream doct;
	doct.open("doc.txt", ios::app);
	srand((unsigned)time(0));
	id = rand();
	cout << "Patient id: " << id << endl;
	cout << "Enter Patient name: "; cin >> name;
	cout << "Enter patient disease: "; cin >> disease;
	cout << "Enter patient age: "; cin >> age;
	cout << "Enter patient gender (m/f): "; cin >> gen;
	while (gen != 'm' && gen != 'M' && gen != 'f' && gen != 'F')
	{
		cout << "Invalid input add patient gender (m/f): "; cin >> gen;
	}
	cout << "Enter docter name of the patient: Dr."; cin >> doctor;
	ifstream file;
	file.open("doc.txt");
	while (!file.eof())
	{
		getline(file, s);
		size++;
	}
	file.close();
	if (size >= 1)
	{
		ifstream read;
		read.open("doc.txt");

		for (int i = 0; i < size; i++)
		{
			read >> doc[i];
			i++;
		}
		for (int i = 0; i < size; i++)
		{
			if (doc[i] == doctor)
			{
				flag = true;
			}
		}
	}
	if (!flag)
	{
		int id = rand();
		cout << "This doctor is not in the record." << endl;
		cout << "Enter the specialization of the doctor: "; cin >> spac;
		cout << "id of this doctor: " << id << endl;
		doct << doctor << " " << id << " " << spac << endl;
	}
	cout << "Choose room number from following room number(1,2,3,4,5)" << endl;
	for (int i = 1; i < 6; i++)
	{
		OroomCh[i] = rand() % 100;
		while (OroomCh[i] < 1)
		{
			OroomCh[i] = rand() % 100;
		}
		cout << i << ") " << OroomCh[i] << endl;
	}
	cin >> OroomN;
	while (OroomN != 1 && OroomN != 5 && OroomN != 2 && OroomN != 3 && OroomN != 4)
	{
		cout << "Invalid Inout Choose correct room number from following rooms numbers(1,2,3,4,5)" << endl;
		cin >> OroomN;
		Oroom = OroomCh[OroomN];
	}
	Oroom = OroomCh[OroomN];
	cout << "Room no.: " << Oroom << endl;
	int num = 1;
	WriteInFile(num, name, disease, doctor, id, age, gen, Oroom, Ename, Eid);
	doct.close();
	delete[]spac;
	delete[]doc;
	delete[]name;
	delete disease;
}

void Emergency(string Ename, string Eid)
{
	char* name = new char[100]; char* disease = new char[100]; char* spac = new char[100];
	int id, age, EroomCh[6], EroomN, Eroom, size = 0;
	char gen;
	ofstream doct;
	doct.open("doc.txt", ios::app);
	string* doc = new string[1000]; string doctor, s;
	srand((unsigned)time(0));
	id = rand();
	cout << "Patient id: " << id << endl;
	cout << "Enter Patient name: "; cin >> name;
	cout << "Enter patient disease name: "; cin >> disease;
	cout << "Enter patient age: "; cin >> age;
	cout << "Enter patient gender (m/f): "; cin >> gen;
	while (gen != 'm' && gen != 'M' && gen != 'f' && gen != 'F')
	{
		cout << "Invalid input add patient gender (m/f): "; cin >> gen;
	}

	bool flag = false;
	cout << "Enter docter name of the patient: Dr."; cin >> doctor;
	ifstream file;
	file.open("doc.txt");
	while (!file.eof())
	{
		getline(file, s);
		size++;
	}
	if (size >= 1)
	{
		file.close();
		ifstream read;
		read.open("doc.txt");

		for (int i = 0; i < size; i++)
		{
			read >> doc[i];
			i++;
		}
		for (int i = 0; i < size; i++)
		{
			if (doc[i] == doctor)
			{
				flag = true;
			}
		}
	}
	if (!flag)
	{
		int id = rand();
		cout << "This doctor is not in the record." << endl;
		cout << "Enter the specialization of the doctor: "; cin >> spac;
		cout << "id of this doctor: " << id << endl;
		doct << doctor << " " << id << " " << spac << endl;
	}

	cout << "Choose room number from following room number(1,2,3,4,5)" << endl;
	for (int i = 1; i < 6; i++)
	{
		EroomCh[i] = rand() % 100;
		while (EroomCh[i] < 1)
		{
			EroomCh[i] = rand() % 100;
		}
		cout << i << ") " << EroomCh[i] << endl;
	}
	cin >> EroomN;
	while (EroomN != 1 && EroomN != 5 && EroomN != 2 && EroomN != 3 && EroomN != 4)
	{
		cout << "Invalid Inout Choose correct room number from following rooms numbers(1,2,3,4,5)" << endl;
		cin >> EroomN;
		Eroom = EroomCh[EroomN];
	}
	Eroom = EroomCh[EroomN];
	cout << "Bed no.: " << Eroom << endl;
	int num = 2;
	WriteInFile(num, name, disease, doctor, id, age, gen, Eroom, Ename, Eid);
	delete[]name;
	delete[]disease;
	delete[]spac;
	doct.close();
}

void Doctor()
{
	char* name = new char[100];
	char* spac = new char[100];
	int id;
	srand((unsigned)time(0));
	id = rand();
	cout << "Doctor Id: " << id;
	cout << "Enter the name of the doctor: Dr."; cin >> name;
	cout << "Enter the specialization of the doctor: "; cin >> spac;
	cout << "Record Added Successfully!" << endl;
	ofstream doc;
	doc.open("doc.txt", ios::app);
	doc << name << " " << id << " " << spac << endl;
	delete[]name;
	delete[]spac;

}

int SearchByName(int num)
{
	string ret;
	int flag = 0;
	int count = 0, x = 0, size = 0, reapet = 0;
	string id, s; char Sname[100];
	ifstream file;
	if (num == 1)
	{
		file.open("opd.txt");
	}
	if (num == 2)
	{
		file.open("Emergency.txt");
	}
	while (getline(file, s))
	{
		size++;
	}
	file.close();
	ifstream read;
	if (num == 1)
	{
		read.open("opd.txt");
	}
	if (num == 2)
	{
		read.open("Emergency.txt");
	}
	string* name = new string[size];
	string* idS = new string[size];
	string* age = new string[size];
	string* gen = new string[size];
	string* Disease = new string[size];
	string* doctor = new string[size];
	string* room = new string[size];
	string* Uname = new string[size];
	string* Uid = new string[size];
	while (!read.eof())
	{
		for (int i = 0; i < size; i++)
		{
			read >> name[i];
			read >> idS[i];
			read >> age[i];
			read >> gen[i];
			read >> Disease[i];
			read >> doctor[i];
			read >> room[i];
			read >> Uname[i];
			read >> Uid[i];
		}
	}
	cout << "Enter name of the patient: "; cin >> Sname;
	for (int i = 0; i < size; i++)
	{
		if (name[i] == Sname)
		{
			x = i;
			flag = 1;
			reapet++;
		}
	}
	if (flag == 1 && reapet == 1)
	{
		cout << endl;
		cout << "Patient Name: " << name[x] << endl;
		cout << "Patient Id No.: " << idS[x] << endl;
		cout << "Patient Age: " << age[x] << endl;
		cout << "Patient Gender: " << gen[x] << endl;
		cout << "Patient Disease: " << Disease[x] << endl;
		cout << "Patient Doctor Name: Dr." << doctor[x] << endl;
		cout << "Patient Room No.: " << room[x] << endl;
		cout << "Record Of This Patient Was Added By: " << endl << "Username: " << Uname[x] << "\t\t" << "Id: " << Uid[x] << endl;
		ret = idS[x];
		return x + 1;
	}
	if (reapet > 1)
	{
		cout << "There Are More Then One Patent Of this Name!" << endl;
		cout << "Enter Id No. Of This Patient: "; cin >> id;
		for (int i = 0; i < size; i++)
		{
			if (name[i] == Sname && idS[i] == id)
			{
				flag = 1;
				x = i;
			}

		}
		if (flag == 1)
		{
			cout << endl;
			/*for (int i = 0; i < size; i++)
			{
				for (int i = 0; i < size; i++)
				{*/
			cout << "Patient Name: " << name[x] << endl;
			cout << "Patient Id No.: " << idS[x] << endl;
			cout << "Patient Age: " << age[x] << endl;
			cout << "Patient Gender: " << gen[x] << endl;
			cout << "Patient Disease: " << Disease[x] << endl;
			cout << "Patient Doctor Name: Dr." << doctor[x] << endl;
			cout << "Patient Room No.: " << room[x] << endl;
			cout << "Record Of This Patient Was Added By: " << endl << "Username: " << Uname[x] << "\t\t" << "Id: " << Uid[x] << endl;
			//	}/*
			//*/}
			return x + 1;
		}
		if (flag == 0)
		{
			cout << "Invalid Id!" << endl;
			cout << "Patient Not Found!" << endl;
			flag = 0;
			return flag;
		}
	}
	if (flag == 0)
	{
		cout << "Patient Not Found!" << endl;
		flag = 0;
		return flag;
	}
	delete[]name;
	delete[]idS;
	delete[]age;
	delete[]gen;
	delete[]Disease;
	delete[]doctor;
	delete[]room;
	delete[]Uname;
	delete[]Uid;
}

int SearchById(int num)
{

	int flag = 0;
	string* line;
	int count = 0, x = 0, size = 0;
	string  s;
	ifstream file;
	if (num == 1)
	{
		ofstream o;
		o.open("opd.txt", ios::app);
		file.open("opd.txt");
		o.close();
	}
	if (num == 2)
	{
		ofstream m;
		m.open("opd");
		file.open("Emergency.txt");
		m.close();
	}
	while (getline(file, s))
	{
		size++;
	}
	file.close();
	ifstream read;
	if (num == 1)
	{
		read.open("opd.txt");
	}
	if (num == 2)
	{
		read.open("Emergency.txt");
	}
	line = new string[size];
	string* name = new string[size];
	string* idS = new string[size];
	string* age = new string[size];
	string* gen = new string[size];
	string* Disease = new string[size];
	string* doctor = new string[size];
	string* room = new string[size];
	string* Uname = new string[size];
	string* Uid = new string[size];
	while (!read.eof())
	{
		for (int i = 0; i < size; i++)
		{
			read >> name[i];
			read >> idS[i];
			read >> age[i];
			read >> gen[i];
			read >> Disease[i];
			read >> doctor[i];
			read >> room[i];
			read >> Uname[i];
			read >> Uid[i];
			count++;
		}
	}
	string id;
	cout << "Enter Patient Id: "; cin >> id;
	for (int i = 0; i < size; i++)
	{
		if (idS[i] == id)
		{
			x = i;
			flag = 1;
		}
	}
	if (flag == 1)
	{
		cout << endl;

		cout << "Patient Name: " << name[x] << endl;
		cout << "Patient Id No.: " << idS[x] << endl;
		cout << "Patient Age: " << age[x] << endl;
		cout << "Patient Gender: " << gen[x] << endl;
		cout << "Patient Disease: " << Disease[x] << endl;
		cout << "Patient Doctor Name: Dr." << doctor[x] << endl;
		cout << "Patient Room No.: " << room[x] << endl;
		cout << "Record Of This Patient Was Added By: " << endl << "Username: " << Uname[x] << "\t\t" << "Id: " << Uid[x] << endl;

		return x + 1;
	}


	if (flag == 0)
	{
		cout << "Patient Not Found!" << endl;
		delete[]line;
		flag = 0;
		return flag;
	}
	delete[]name;
	delete[]idS;
	delete[]age;
	delete[]gen;
	delete[]Disease;
	delete[]doctor;
	delete[]room;
	delete[]Uname;
	delete[]Uid;
}

void Edit(int x, int num)
{
	char edit;
	int size = 0;
	string s;
	ifstream file;
	if (num == 1)
	{
		file.open("opd.txt");
	}
	if (num == 2)
	{
		file.open("Emergency.txt");
	}
	while (getline(file, s))
	{
		size++;
	}
	file.close();
	ifstream read;
	if (num == 1)
	{
		read.open("opd.txt");
	}
	if (num == 2)
	{
		read.open("Emergency.txt");
	}
	string* name = new string[size];
	string* id = new string[size];
	string* age = new string[size];
	string* gen = new string[size];
	string* Disease = new string[size];
	string* doctor = new string[size];
	string* room = new string[size];
	string* Uname = new string[size];
	string* Uid = new string[size];
	while (!read.eof())
	{
		for (int i = 0; i < size; i++)
		{
			read >> name[i];
			read >> id[i];
			read >> age[i];
			read >> gen[i];
			read >> Disease[i];
			read >> doctor[i];
			read >> room[i];
			read >> Uname[i];
			read >> Uid[i];
		}
	}
	cout << "What You Want To Edit" << endl;
	cout << "Press (N) to edit Patient name." << endl;
	cout << "Press (D) to edit Disease Name." << endl;
	cout << "Press (A) to edit Age." << endl;
	cout << "Press (G) to edit Gender." << endl;
	cout << "Press (R) to edit Room No." << endl;
	cin >> edit;
	/*line[x + 3] = doctor;*/
	if (edit == 'N' || edit == 'n')
	{
		cout << "Enter New Name Of The Patient: "; cin >> name[x];
		cout << "Record updated successfully!" << endl;
	}
	else if (edit == 'D' || edit == 'd')
	{
		cout << "Enter Patient Disease Name: "; cin >> Disease[x];
		cout << "Record updated successfully!" << endl;
	}
	else if (edit == 'A' || edit == 'a')
	{
		cout << "Enter patient's Age: "; cin >> age[x];
		cout << "Record updated successfully." << endl;
	}
	else if (edit == 'G' || edit == 'g')
	{
		cout << "Enter patient's gender(m/f): "; cin >> gen[x];
		/*while (gen[x] != 'm' && gen != 'M' && gen != 'f' && gen != 'F')
		{
			cout << "Invalid input add patient gender (m/f): "; cin >> gen;
		}*/
		cout << "Record updated successfully." << endl;
	}
	else if (edit == 'R' || edit == 'r')
	{
		cout << "Enter patient's room No.: "; cin >> room[x];
		cout << "Record updated successfully." << endl;
	}
	ofstream write;
	if (num == 1)
	{
		write.open("opd.txt");
	}
	if (num == 2)
	{
		write.open("Emergency.txt");
	}
	int j = 0, k = 0;
	for (int i = 0; i < size; i++)
	{
		write << name[i] << " " << id[i] << " " << age[i] << " " << gen[i] << " " << Disease[i] << " " << doctor[i] << " " << room[i] << " " << Uname[i] << " " << Uid[i] << endl;
	}
	delete[]name;
	delete[]id;
	delete[]age;
	delete[]gen;
	delete[]Disease;
	delete[]doctor;
	delete[]room;
	delete[]Uname;
	delete[]Uid;
	/*WriteInDoc(line, doctor, size,x);*/
	write.close();
	//delete[]name;
	//delete[] Disease;
}

void  WriteInFile(int num, char name[], char disease[], string doctor, int id, int age, char gen, int roomN, string Ename, string Eid)
{
	if (num == 1)
	{
		ofstream file;
		file.open("opd.txt", ios::app);
		file << name << " " << id << " " << age << " " << gen << " " << disease << " " << doctor << " " << roomN << " " << Ename << " " << Eid << endl;
	}
	if (num == 2)
	{
		ofstream file;
		file.open("Emergency.txt", ios::app);
		file << name << " " << id << " " << age << " " << gen << " " << disease << " " << doctor << " " << roomN << " " << Ename << " " << Eid << endl;
	}
	//int sizeS = size(doctor);
	//doctor[sizeS] = '.'; doctor[sizeS + 1] = 't'; doctor[sizeS + 2] = 'x'; doctor[sizeS + 3] = 't'; doctor[sizeS + 4] = '\0';
	//ofstream doc;
	//doc.open(doctor,ios::app);
	//doc << name << " " << id << " " << age << " " << gen << " " << disease << " " << doctor << " " << roomN << " " << Ename << " " << Eid << endl;
}
void List(int num)
{
	ofstream o;
	o.open("opd.txt", ios::app);
	ofstream m;
	m.open("emergency.txt", ios::app);
	ofstream d;
	d.open("doc.txt", ios::app);
	m.close();
	o.close();
	d.close();
	if (num == 1)
	{
		int size = 0;
		string s;
		ifstream file;
		file.open("opd.txt");
		while (getline(file, s))
		{
			size++;
		}
		file.close();
		string* name = new string[size];
		string* id = new string[size];
		string* Disease = new string[size];
		string* doctor = new string[size];
		string* gen = new string[size];
		string* room = new string[size];
		string* age = new string[size];
		string* Uname = new string[size];
		string* Uid = new string[size];
		int count = 0;
		ifstream read;
		read.open("opd.txt");
		while (count < size)
		{
			read >> name[count];
			read >> id[count];
			read >> age[count];
			read >> gen[count];
			read >> Disease[count];
			read >> doctor[count];
			read >> room[count];
			read >> Uname[count];
			read >> Uid[count];
			count++;
		}
		cout << "Sr#  " << "Name\t" << " ID\t " << "Age\t " << "Disease\t" << " Doctor\t\t" << "Room#\t" << "    UserName\t  " << "     UserID" << endl;
		cout << "------------------------------------------------------------------------------------------------------" << endl;
		for (int i = 0; i < size; ++i)
		{
			cout << i + 1 << ")   " << name[i] << "\t" << id[i] << "\t " << age[i] << "\t  " << Disease[i] << "\t\t" << "Dr." << doctor[i] << "\t  " << room[i] << "\t      " << Uname[i] << "\t\t" << Uid[i] << endl;
		}
		cout << endl;
		delete[]name;
		delete[]id;
		delete[]age;
		delete[]gen;
		delete[]Disease;
		delete[]doctor;
		delete[]room;
		delete[]Uname;
		delete[]Uid;

	}
	if (num == 2);
	{
		int size = 0;
		string s;
		ifstream file;
		file.open("Emergency.txt");
		while (getline(file, s))
		{
			size++;
		}
		file.close();
		string* name = new string[size];
		string* id = new string[size];
		string* Disease = new string[size];
		string* doctor = new string[size];
		string* gen = new string[size];
		string* room = new string[size];
		string* age = new string[size];
		string* Uname = new string[size];
		string* Uid = new string[size];
		ifstream read;
		read.open("Emergency.txt");
		int count = 0;
		while (count < size)
		{
			read >> name[count];
			read >> id[count];
			read >> age[count];
			read >> gen[count];
			read >> Disease[count];
			read >> doctor[count];
			read >> room[count];
			read >> Uname[count];
			read >> Uid[count];
			count++;
		}

		if (num == 2)
		{
			cout << "Sr#  " << "Name\t" << " ID\t " << "Age\t " << "Disease\t" << " Doctor\t\t" << "Room#\t" << "    UserName\t  " << "     UserID" << endl;
			cout << "------------------------------------------------------------------------------------------------------" << endl;
			for (int i = 0; i < size; ++i)
			{
				cout << i + 1 << ")   " << name[i] << "\t" << id[i] << "\t " << age[i] << "\t " << Disease[i] << "\t\t" << "Dr." << doctor[i] << "\t " << room[i] << "\t      " << Uname[i] << "\t\t" << Uid[i] << endl;
			}
		}
		cout << endl;
		delete[]name;
		delete[]id;
		delete[]age;
		delete[]gen;
		delete[]Disease;
		delete[]doctor;
		delete[]room;
		delete[]Uname;
		delete[]Uid;
		read.close();

	}
	if (num == 3)
	{
		int size = 0;
		string s;
		ifstream file;
		file.open("doc.txt");
		while (getline(file, s))
		{
			size++;
		}
		file.close();
		string* name = new string[size];
		string* spac = new string[size];
		int* id = new int[size];
		ifstream read;
		read.open("doc.txt");
		for (int i = 0; i < size; i++)
		{
			read >> name[i];
			read >> id[i];
			read >> spac[i];
		}
		cout << "Sr#    " << "Name\t\t" << " Id\t\t" << "Specialization" << endl;
		cout << "---------------------------------------------------------" << endl;
		for (int i = 0; i < size; ++i)
		{
			cout << i + 1 << ")   " << "Dr." << name[i] << "\t\t" << id[i] << "\t\t" << spac[i] << endl;
		}
		cout << endl;
		delete[] name;
		delete[] spac;
		delete[]id;
		read.close();

	}
}

void Discharge(int x, int num)
{
	int size = 0;
	string s;
	ifstream file;
	if (num == 1)
	{
		file.open("opd.txt");
	}
	if (num == 2)
	{
		file.open("Emergency.txt");
	}
	while (getline(file, s))
	{
		size++;
	}
	file.close();
	ifstream read;
	if (num == 1)
	{
		read.open("opd.txt");
	}
	if (num == 2)
	{
		read.open("Emergency.txt");
	}
	string* name = new string[size];
	int* id = new int[size];
	string* age = new string[size];
	string* gen = new string[size];
	string* Disease = new string[size];
	string* doctor = new string[size];
	string* room = new string[size];
	string* Uname = new string[size];
	string* Uid = new string[size];
	while (!read.eof())
	{
		for (int i = 0; i < size; i++)
		{
			read >> name[i];
			read >> id[i];
			read >> age[i];
			read >> gen[i];
			read >> Disease[i];
			read >> doctor[i];
			read >> room[i];
			read >> Uname[i];
			read >> Uid[i];
		}
	}
	name[x] = -99;
	id[x] = -99;
	age[x] = -99;
	gen[x] = -99;
	Disease[x] = -99;
	doctor[x] = -99;
	room[x] = -99;
	Uname[x] = -99;
	Uid[x] = -99;
	ofstream write;
	if (num == 1)
	{
		write.open("opd.txt");
	}
	if (num == 2)
	{
		write.open("Emergency.txt");
	}
	int j = 0, k = 0;
	for (int i = 0; i < size; i++)
	{
		if (id[i] != -99)
		{
			write << name[i] << " " << id[i] << " " << age[i] << " " << gen[i] << " " << Disease[i] << " " << doctor[i] << " " << room[i] << " " << Uname[i] << " " << Uid[i] << endl;
		}
	}
	delete[]name;
	delete[]id;
	delete[]age;
	delete[]gen;
	delete[]Disease;
	delete[]doctor;
	delete[]room;
	delete[]Uname;
	delete[]Uid;
	write.close();
}