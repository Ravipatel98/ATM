#pragma once
# include <iostream>
# include <string>
#include <fstream>
#include <iomanip>
#include <stdlib.h>

using namespace std;

struct Student
{
	string Number;
	string Name;
	string Prg;
	float Grade;

};

void DisplayTitle(string Title)
{
	cout << "\t";
	for (int i = 0; i < Title.length(); i++)
	{
		cout << (char)toupper(Title[i]);
	}
	cout << "\n\t";
	for (int i = 0; i < Title.length(); i++)
	{
		cout << "-";
	}
	cout << "\n";
}


void DisplayMenu()
{
	
	cout << "1 - Display All The Students\n";
	cout << "2 - Add a new Student At the End\n";
	cout << "3 - Find a Student By Number\n";
	cout << "4-Display All Student By Reverse order\n";
	cout << "5 - Quit The Program\n";
}

short GetChoice(short min, short max)
{
	short nb;
	do
	{
		cout << "Enter Your Choice :";
		cin >> nb;
	} while (nb<min || nb>max);
	return nb;
}

void OpenFile(Student tabStuds[], float mark)
{
	DisplayTitle("All Students In order");
	short nb;
	fstream MyFile;
	MyFile.open("college.txt", ios::in);
	short i = 0;

	while (!MyFile.eof())
	{
		char tmp[5];


		Student st;
		getline(MyFile, st.Number);
		getline(MyFile, st.Name);
		getline(MyFile, st.Prg);
		MyFile.getline(tmp, 5);
		st.Grade = atoi(tmp);
		tabStuds[i] = st;
		i++;

	}
	nb = i;
	MyFile.close();

	cout << left << setw(10) << "Numbers" 
		<< setw(30) << "Student Names" 
		<< setw(20) << "Programs" 
		<< setw(15) << "Grades" 
		<< setw(10) << "Results" << "\n";
	for (short i = 0; i < nb; i++)
		
	{

		cout << left << setw(10) << tabStuds[i].Number
			<< setw(30) << tabStuds[i].Name << setw(20) << tabStuds[i].Prg
			<< setw(15) << tabStuds[i].Grade << setw(10) << ((tabStuds[i].Grade >= mark) ? "pass" : "Fail") << "\n";

	}
	system("Pause");
}

void FindStudent(Student tabStuds[])
{
	fstream MyFile;
	string num;
	short foundIndex = -1;

	MyFile.open("college.txt", ios::in);
	short i = 0, nb = 0;

	while (!MyFile.eof())
	{
		char tmp[5];


		Student st;
		getline(MyFile, st.Number);
		getline(MyFile, st.Name);
		getline(MyFile, st.Prg);
		MyFile.getline(tmp, 5);
		st.Grade = atoi(tmp);
		tabStuds[i] = st;
		i++;

	}
	nb = i;
	MyFile.close();
	cout << "\n\nEnter the student number to find: ";
	cin >> num;
	for (short i = 0; i < nb; i++)
	{
		if (num == tabStuds[i].Number)
		{
			foundIndex = i;
			break;
		}
	}
	cout << left << setw(10) << "Numbers" << setw(30) << "Student Names" << setw(20) << "Programs" << setw(15) << "Grades\n";

	if (foundIndex == -1)
	{
		cout << "Student not found.\n";
	}
	else
	{
		cout << left << setw(10) << tabStuds[foundIndex].Number
			<< setw(30) << tabStuds[foundIndex].Name << setw(20) << tabStuds[foundIndex].Prg
			<< setw(15) << tabStuds[foundIndex].Grade << setw(10) << "\n";
	}

	system("pause");
}

void AddStudent(Student tabStuds[])

{
	DisplayTitle("Add a new student");

	short nb{};
	fstream MyFile;
	MyFile.open("College.txt", ios::app);
	cin.ignore();
	cout << "\tNumber :";
	getline(cin, tabStuds[nb].Number);
	cout << "\tEnter a new name: ";
	cin.ignore();
	getline(cin, tabStuds[nb].Name);
	cout << "\tProgram :";
	getline(cin, tabStuds[nb].Program);
	cout << "\tGrade :";
	cin >> tabStuds[nb].Grade;


	for (short i = 0; i < nb + 1; i++)
	{
		MyFile << tabStuds[nb].Number << endl;
		MyFile << tabStuds[nb].Name << endl;
		MyFile << tabStuds[nb].Program << endl;
		MyFile << tabStuds[nb].Grade << endl;
	}

	MyFile.close();
	system("pause");
}
void Reverse(Student tabStuds[], float passingmark)
{
	DisplayTitle("All Students In order");
	short nb;
	fstream MyFile;
	MyFile.open("college.txt", ios::in);
	short i = 0;

	while (!MyFile.eof())
	{
		char tmp[5];


		Student st;


		getline(MyFile, st.Number);
		getline(MyFile, st.Name);
		getline(MyFile, st.Prg);
		MyFile.getline(tmp, 5);
		st.Grade = atoi(tmp);
		tabStuds[i] = st;
		i++;

	}
	nb = i;
	MyFile.close();




	cout << left << setw(10) << "Numbers" << setw(30) << "Student Names" << setw(20) << "Programs" << setw(15) << "Grade" << setw(10) << "Result" << "\n";
	for (short i = nb - 1; i >= 0; i--)
	{

		cout << left << setw(10) << tabStuds[i].Number
			<< setw(30) << tabStuds[i].Name << setw(20) << tabStuds[i].Prg
			<< setw(15) << tabStuds[i].Grade << setw(10) << ((tabStuds[i].Grade >= passingmark) ? "pass" : "Fail") << "\n";

	}

	system("pause");
}
