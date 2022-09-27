#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<fstream>
#include<string>
#include <conio.h>
#include<Windows.h>
#include"Header.h"
using namespace std;
//Book Class Methods
books::books()
{
	CODE = NULL;
	B_NAME = NULL;
	W_NAME = NULL;
	PRICE = 0;
}
books::~books()
{
	delete[] CODE;
	CODE = NULL;
	delete[] B_NAME;
	B_NAME = NULL;
	delete[] W_NAME;
	W_NAME = NULL;
}
void books::Enter_data()
{
	cout << "\nBook name   :";
	cin.ignore();
	cin.getline(b_name, 20, '\n');
	cout << "\nBook code   : ";
	cin.getline(code, 10, '\n');
	cout << "\nWriter name :";
	cin.getline(w_name, 20, '\n');
	cout << "\nPrice       :";
	cin >> price;
	cout << endl;
	setValues(code, b_name, w_name, price);
}
void books::book_data()
{
	fstream file("All_Books.txt", ios::out | ios::app);

	file.width(20);

	file << b_name;

	file.width(20);
	file << w_name;

	file.width(10);
	file << code;

	file.width(10);
	file << price << endl;

	file.close();
}
void books::setValues(char * n, char *b, char *  w, float p){
	CODE = new char[strlen(n) + 1];
	strcpy(CODE, n);

	B_NAME = new char[strlen(b) + 1];
	strcpy(B_NAME, b);

	W_NAME = new char[strlen(w) + 1];
	strcpy(W_NAME, w);

	PRICE = p;
}

//Literature Books Method
void Literature::book_data()
{
	fstream file1("Literature.txt", ios::out | ios::app);
	file1 << "Book Name   :" << b_name << endl;
	file1 << "Writer Name :" << w_name << endl;
	file1 << "Book Code   :" << code << endl;
	file1 << "Price       :" << price << endl;
	file1.close();
}

//Literature Books Method
void Philosophy::book_data()
{

	fstream file1("Philosophy.txt", ios::out | ios::app);
	file1 << "Book Name   :" << b_name << endl;
	file1 << "Writer Name :" << w_name << endl;
	file1 << "Book Code   :" << code << endl;
	file1 << "Price       :" << price << endl;
	file1.close();
}

//Science Books Method
void Science::book_data()
{
	fstream file1("Science.txt", ios::out | ios::app);
	file1 << "Book Name   :" << b_name << endl;
	file1 << "Writer Name :" << w_name << endl;
	file1 << "Book Code   :" << code << endl;
	file1 << "Price       :" << price << endl;
	file1.close();

}

//Comics Books Method
void Comics::book_data()
{
	fstream file1("Comics.txt", ios::out | ios::app);
	file1 << "Book Name   :" << b_name << endl;
	file1 << "Writer Name :" << w_name << endl;
	file1 << "Book Code   :" << code << endl;
	file1 << "Price       :" << price << endl;
	file1.close();

}

//Mini Services Methods
void Mini_services::display(){
	int choice; int flag = 0;
	char code[10] = { '\0' }, ch = 0;
	while (1)
	{

		if (flag != 0)
		{
			system("CLS");
		}
		cout << "\n\n...................DISPLAY.....................\n\n";
		cout << "=======================\n";
		cout << "|Press 1 for All Books" << endl;
		cout << "|Press 2 for Literature" << endl;
		cout << "|Press 3 for Philosophy" << endl;
		cout << "|Press 4 for Science" << endl;
		cout << "|Press 5 for Comics" << endl;
		cout << "|Press 0 for Back" << endl;
		cout << "=======================\n";
		cout << "\nEnter Ur Choice:";
		cin >> choice;

		if (choice == 1)
		{
			system("CLS");
			flag = 1;
			cout << endl;
			cout.width(20);
			cout << "Book Name";

			cout.width(20);
			cout << "Writer Name";

			cout.width(10);
			cout << "Code";

			cout.width(10);
			cout << "Price" << endl << endl;

			fstream file("All_Books.txt", ios::in);
			file.seekg(0);
			while (file)
			{
				file.get(ch);
				cout << ch;
			}
			file.close();
			cout << "For Back ";
			system("pause");
		}

		else if (choice == 2)
		{
			system("CLS");
			flag++;

			fstream file("Literature.txt", ios::in);
			file.seekg(0);
			cout << "\n";
			while (file)
			{
				file.get(ch);

				cout << ch;
			}
			file.close();
			cout << "For Back ";
			system("pause");
		}

		else if (choice == 3)
		{
			system("CLS");
			flag++;

			fstream file("Philosophy.txt", ios::in);
			file.seekg(0);
			cout << "\n";
			while (file)
			{
				file.get(ch);

				cout << ch;
			}
			file.close();
			cout << "For Back ";
			system("pause");
		}

		else if (choice == 4)
		{
			system("CLS");
			flag++;
			fstream file("Science.txt", ios::in);
			file.seekg(0);
			cout << "\n";
			while (file)
			{
				file.get(ch);
				cout << ch;
			}
			file.close();
			cout << "For Back ";
			system("pause");
		}

		else if (choice == 5)
		{
			system("CLS");
			flag++;
			fstream file("Comics.txt", ios::in);
			file.seekg(0);
			cout << "\n";
			while (file)
			{
				file.get(ch);
				cout << ch;
			}
			file.close();
			cout << "For Back ";
			system("pause");
		}
		else
		{
			system("CLS");
			break;
		}
	}                                   // while (choice) ends
}                                    // display class ends
void Mini_services::add_books()
{
	int choice, flag = 0;
	while (1)
	{
		if (!flag){
			system("CLS");
		}
		cout << "....................Add Books................";
		cout << "\n|Press 1 for Literature Books \n|Press 2 for Philosophy books \n|Press 3 for Science Books \n|Press 4 for Comics books \n|Press any other key for back \n";
		cout << "\nChoice:";
		cin >> choice;

		if (choice == 1)
		{
			flag++;
			t1.Enter_data();
			t1.book_data();
			t1.books::book_data();
			cout << "Book Added Successfully\n\n"; int ch;
			cout << "Do you want to add more Books \n|Enter 1 for Yes\n|Enter Any other number  for no\nEnter choos :"; cin >> ch;
			if (ch == 1)
			{
				flag = 0;
			}
			else
			{

				break;
			}
		}
		else if (choice == 2)
		{
			flag++;
			t2.Enter_data();
			t2.book_data();
			t2.books::book_data();
			cout << "Book Added Successfully\n\n"; int ch;
			cout << "Do you want to add more Books \n|Enter 1 for Yes\n|Enter Any other number  for no\nEnter choos :"; cin >> ch;
			if (ch == 1)
			{
				flag = 0;
			}
			else
			{
				system("CLS");
				break;
			}
		}
		else if (choice == 3)
		{
			flag++;
			t3.Enter_data();
			t3.book_data();
			t3.books::book_data();
			cout << "Book Added Successfully\n\n"; int ch;
			cout << "Do you want to add more Books \n|Enter 1 for Yes\n|Enter Any other number  for no\nEnter choos :"; cin >> ch;
			if (ch == 1)
			{
				flag = 0;
			}
			else
			{
				system("CLS");
				break;
			}
		}
		else if (choice == 4)
		{
			flag++;
			t4.Enter_data();
			t4.book_data();
			t4.books::book_data();
			cout << "Book Added Successfully\n\n"; int ch;
			cout << "Do you want to add more Books \n|Enter 1 for Yes\n|Enter Any other number  for no\nEnter choos :"; cin >> ch;
			if (ch == 1)
			{
				flag = 0;
			}
			else
			{
				system("CLS");
				break;
			}
		}
		else
		{
			system("CLS");
			break;
		}

	}

}
void Mini_services::start()
{
	int choice;
	while (1)
	{

		cout << "\n\n.........Enter Ur Choice........\n\n";
		cout << "|Press 1 for Add Books\n";
		cout << "|Press 2 for Display Book Data\n";
		cout << "|Press any other key for Back\n";
		cout << "Enter Choice:";
		cin >> choice;

		if (choice == 1)
		{
			add_books();
		}

		else if (choice == 2)
		{
			display();
		}
		else
			break;
	}



}
Mini_services::Mini_services(){
	//cunstructor;
}
Mini_services::~Mini_services(){
	//Destructor
}

//High Services Method
void High_Services::search()
{
	int choice, flag = 0;
	char fil[20] = { '\0' };
	char  c[20] = { '\0' };
	while (1)
	{

		cout << "\n\n....................SEARCH...................\n\n";
		cout << "====================\n";
		cout << "|Press 1 for Searching a book of Literatture\n";
		cout << "|Press 2 for Searching a book of Philosophy\n";
		cout << "|Press 3 for Searching a book of Science\n";
		cout << "|Press 4 for Searching a book of Comics\n";
		cout << "Press any other number for Back\n";
		cout << "=====================";
		cout << "\nEnter Chioce:";
		cin >> choice;
		if (choice == 1){
			flag++;
			cout << "Enter Code:";
			cin >> c;
			int x = 0;
			ifstream fin("Literature.txt");
			if (fin.is_open())
			{
				while (!fin.eof())
				{
					string name, writername, price; char ig[30];
					char cod[10] = { '\0' }; int k = 0;
					getline(fin, name);
					getline(fin, writername);
					fin.getline(ig, 29, '\n');
					for (int i = 0; ig[i] != '\0'; i++)
					{
						if (ig[i] >= '0'&&ig[i] <= '9')
						{
							cod[k++] = ig[i];
						}
					}
					getline(fin, price);

					if (strcmp(cod, c) == 0)
					{
						x++;
						cout << "\nBook is found\n";
						cout << endl;
						cout << name << endl; cout << writername << endl;
						cout << ig << endl; cout << price << endl;
					}
				}
				if (!x)
				{
					cout << "\nBook is Not found\n";
				}
			}
			else
			{
				cout << "Literature File is missing!!!!\n";
			}

		}
		else if (choice == 2){
			flag++;
			cout << "Enter Code:";
			cin >> c;
			int x = 0;
			ifstream fin("Philosophy.txt");
			if (fin.is_open())
			{

				while (!fin.eof())
				{
					string name, writername, price; char ig[30];
					char cod[10] = { '\0' }; int k = 0;
					getline(fin, name);
					getline(fin, writername);
					fin.getline(ig, 29, '\n');
					for (int i = 0; ig[i] != '\0'; i++)
					{
						if (ig[i] >= '0'&&ig[i] <= '9')
						{
							cod[k++] = ig[i];
						}
					}
					getline(fin, price);
					cout << cod << endl;
					if (strcmp(cod, c) == 0)
					{
						x++;
						cout << "\nBook is found\n";
						cout << endl;
						cout << name << endl; cout << writername << endl;
						cout << ig << endl; cout << price << endl;
					}
				}
				if (!x)
				{
					cout << "\nBook is Not found\n";
				}
			}
			else
			{
				cout << "Philosophy file is missing!!!\n";
			}

		}
		else if (choice == 3)
		{
			flag++;
			cout << "Enter Code:";
			cin >> c;
			int x = 0;
			ifstream fin("Science.txt");
			if (fin.is_open())
			{

				while (!fin.eof())
				{
					string name, writername, price; char ig[30];
					char cod[10] = { '\0' }; int k = 0;
					getline(fin, name);
					getline(fin, writername);
					fin.getline(ig, 29, '\n');
					for (int i = 0; ig[i] != '\0'; i++)
					{
						if (ig[i] >= '0'&&ig[i] <= '9')
						{
							cod[k++] = ig[i];
						}
					}
					getline(fin, price);
					if (strcmp(cod, c) == 0)
					{
						x++;
						cout << "\nBook is found\n";
						cout << endl;
						cout << name << endl; cout << writername << endl;
						cout << ig << endl; cout << price << endl;
					}
				}
				if (!x)
				{
					cout << "\nBook is Not found\n";
				}
			}
			else
			{
				cout << "Science file is missing!!!\n";
			}
		}
		else if (choice == 4)
		{
			flag++;
			cout << "Enter Code:";
			cin >> c;
			int x = 0;
			ifstream fin("Comics.txt");
			if (fin.is_open())
			{
				while (!fin.eof())
				{
					string name, writername, price; char ig[30];
					char cod[10] = { '\0' }; int k = 0;
					getline(fin, name);
					getline(fin, writername);
					fin.getline(ig, 29, '\n');
					for (int i = 0; ig[i] != '\0'; i++)
					{
						if (ig[i] >= '0'&&ig[i] <= '9')
						{
							cod[k++] = ig[i];
						}
					}
					getline(fin, price);
					if (strcmp(cod, c) == 0)
					{
						x++;
						cout << "\nBook is found\n";
						cout << endl;
						cout << name << endl; cout << writername << endl;
						cout << ig << endl; cout << price << endl;
					}
				}
				if (!x)
				{
					cout << "\nBook is Not found\n";
				}
			}
			else
			{
				cout << "Comics file is missing!!!\n";
			}

		}
		else
		{
			break;
		}
	}
}
void High_Services::See_Books(){
	int choice; int flag = 0;
	char code[10] = { '\0' }, ch = 0;
	while (1)
	{

		if (flag != 0)
		{
			system("CLS");
		}
		cout << "\n\n...................DISPLAY.....................\n\n";
		cout << "=======================\n";
		cout << "|Press 1 for All Books" << endl;
		cout << "|Press 2 for Literature" << endl;
		cout << "|Press 3 for Philosophy" << endl;
		cout << "|Press 4 for Science" << endl;
		cout << "|Press 5 for Comics" << endl;
		cout << "|Press 6 for Back" << endl;
		cout << "=======================\n";
		cout << "\nEnter Ur Choice:";
		cin >> choice;

		if (choice == 1)
		{
			system("CLS");
			flag = 1;
			cout << endl;
			cout.width(20);
			cout << "Book Name";

			cout.width(20);
			cout << "Writer Name";

			cout.width(10);
			cout << "Code";

			cout.width(10);
			cout << "Price" << endl << endl;

			fstream file("All_Books.txt", ios::in);
			file.seekg(0);
			while (file)
			{
				file.get(ch);
				cout << ch;
			}
			file.close();
			cout << "For Back ";
			system("pause");
		}

		else if (choice == 2)
		{
			system("CLS");
			flag++;

			fstream file("Literature.txt", ios::in);
			file.seekg(0);
			cout << "\n";
			while (file)
			{
				file.get(ch);

				cout << ch;
			}
			file.close();
			cout << "For Back ";
			system("pause");
		}

		else if (choice == 3)
		{
			system("CLS");
			flag++;

			fstream file("Philosophy.txt", ios::in);
			file.seekg(0);
			cout << "\n";
			while (file)
			{
				file.get(ch);

				cout << ch;
			}
			file.close();
			cout << "For Back ";
			system("pause");
		}

		else if (choice == 4)
		{
			system("CLS");
			flag++;
			fstream file("Science.txt", ios::in);
			file.seekg(0);
			cout << "\n";
			while (file)
			{
				file.get(ch);
				cout << ch;
			}
			file.close();
			cout << "For Back ";
			system("pause");
		}

		else if (choice == 5)
		{
			system("CLS");
			flag++;
			fstream file("Comics.txt", ios::in);
			file.seekg(0);
			cout << "\n";
			while (file)
			{
				file.get(ch);
				cout << ch;
			}
			file.close();
			cout << "For Back ";
			system("pause");
		}
		else
		{
			system("CLS");
			break;
		}
	}
}
void High_Services::Remove_book(){
	int choice, flag = 0;
	char fil[20] = { '\0' };
	char  c[20] = { '\0' };
	while (1)
	{
		ofstream t("temp.txt");
		t.close();
		cout << "\n\n....................Remove...................\n\n";
		cout << "=========================\n";
		cout << "|Press 1 for Remove a book in Literatture\n";
		cout << "|Press 2 for Remove a book in Philosophy\n";
		cout << "|Press 3 for Remove a book in Science\n";
		cout << "|Press 4 for Remove a book in Comics\n";
		cout << "Press any other number for Back\n";
		cout << "==========================";
		cout << "\nEnter Chioce:";
		cin >> choice;
		if (choice == 1){
			flag++;
			cout << "Enter Code:";
			cin >> c;
			int x = 0;
			string name, writername, price; char ig[30];
			char cod[10] = { '\0' };
			ifstream fin("Literature.txt");
			if (fin.is_open())
			{
				while (getline(fin, name))
				{
					int k = 0;
					getline(fin, writername);
					fin.getline(ig, 29, '\n');
					for (int i = 0; ig[i] != '\0'; i++)
					{
						if (ig[i] >= '0'&&ig[i] <= '9')
						{
							cod[k++] = ig[i];
						}
					}
					getline(fin, price);

					if (strcmp(cod, c) == 0)
					{
						x++;
					}
					else
					{
						t.open("temp.txt", ios::app);
						{
							t << name << endl << writername << endl << ig << endl << price << endl;
							t.close();
						}
					}

				}
				fin.close();
				ofstream fou("Literature.txt", ios::out);
				ofstream fout("Literature.txt", ios::app);
				{
					string ch;
					ifstream f("temp.txt");
					{
						getline(f, ch);
						fout << ch;
						while (!f.eof())
						{
							getline(f, ch);
							fout << endl << ch;
						}
						f.close();
					}
					fout.close();
					remove("temp.txt");
				}
				if (!x)
				{
					cout << "\nBook Not Found\n";
				}
				else
				{
					cout << "\nBook Remove Successfully!!!!\n";
				}
			}
			else
			{
				cout << "Literature File is missing!!!!\n";
			}

		}
		else if (choice == 2){
			flag++;
			cout << "Enter Code:";
			cin >> c;
			int x = 0;
			string name, writername, price; char ig[30];
			char cod[10] = { '\0' };
			ifstream fin("Philosophy.txt");
			if (fin.is_open())
			{
				while (getline(fin, name))
				{
					int k = 0;

					getline(fin, writername);
					fin.getline(ig, 29, '\n');
					for (int i = 0; ig[i] != '\0'; i++)
					{
						if (ig[i] >= '0'&&ig[i] <= '9')
						{
							cod[k++] = ig[i];
						}
					}
					getline(fin, price);

					if (strcmp(cod, c) == 0)
					{
						x++;
					}
					else
					{
						t.open("temp.txt", ios::app);
						{
							t << name << endl << writername << endl << ig << endl << price << endl;
							t.close();
						}
					}

				}
				fin.close();
				ofstream fou("Philosophy.txt", ios::out);
				ofstream fout("Philosophy.txt", ios::app);
				{
					string ch;
					ifstream f("temp.txt");
					{
						getline(f, ch);
						fout << ch;
						while (!f.eof())
						{
							getline(f, ch);
							fout << endl << ch;
						}
						f.close();
					}
					fout.close();
					remove("temp.txt");
				}
				if (!x)
				{
					cout << "\nBook Not Found\n";
				}
				else
				{
					cout << "\nBook Remove Successfully!!!!\n";
				}
			}
			else
			{
				cout << "Philosophy File is missing!!!!\n";
			}

		}
		else if (choice == 3)
		{
			flag++;
			cout << "Enter Code:";
			cin >> c;
			int x = 0;
			string name, writername, price; char ig[30];
			char cod[10] = { '\0' };
			ifstream fin("Science.txt");
			if (fin.is_open())
			{
				while (getline(fin, name))
				{
					int k = 0;

					getline(fin, writername);
					fin.getline(ig, 29, '\n');
					for (int i = 0; ig[i] != '\0'; i++)
					{
						if (ig[i] >= '0'&&ig[i] <= '9')
						{
							cod[k++] = ig[i];
						}
					}
					getline(fin, price);

					if (strcmp(cod, c) == 0)
					{
						x++;
					}
					else
					{
						t.open("temp.txt", ios::app);
						{
							t << name << endl << writername << endl << ig << endl << price << endl;
							t.close();
						}
					}
				}
				fin.close();
				ofstream fou("Science.txt", ios::out);
				ofstream fout("Science.txt", ios::app);
				{
					string ch;
					ifstream f("temp.txt");
					{
						getline(f, ch);
						fout << ch;
						while (!f.eof())
						{
							getline(f, ch);
							fout << endl << ch;
						}
						f.close();
					}
					fout.close();
					remove("temp.txt");
				}
				if (!x)
				{
					cout << "\nBook Not Found\n";
				}
				else
				{
					cout << "\nBook Remove Successfully!!!!\n";
				}
			}
			else
			{
				cout << "Science File is missing!!!!\n";
			}

		}
		else if (choice == 4)
		{
			flag++;
			cout << "Enter Code:";
			cin >> c;
			int x = 0;
			string name, writername, price; char ig[30];
			char cod[10] = { '\0' };
			ifstream fin("Comics.txt");
			if (fin.is_open())
			{
				while (getline(fin, name))
				{
					int k = 0;
					getline(fin, writername);
					fin.getline(ig, 29, '\n');
					for (int i = 0; ig[i] != '\0'; i++)
					{
						if (ig[i] >= '0'&&ig[i] <= '9')
						{
							cod[k++] = ig[i];
						}
					}
					getline(fin, price);

					if (strcmp(cod, c) == 0)
					{
						x++;
					}
					else
					{
						t.open("temp.txt", ios::app);
						{
							t << name << endl << writername << endl << ig << endl << price << endl;
							t.close();
						}
					}

				}
				fin.close();
				ofstream fou("Comics.txt", ios::out);
				ofstream fout("Comics.txt", ios::app);
				{
					string ch;
					ifstream f("temp.txt");
					{
						getline(f, ch);
						fout << ch;
						while (!f.eof())
						{
							getline(f, ch);
							fout << endl << ch;
						}
						f.close();
					}
					fout.close();
					remove("temp.txt");
				}
				if (!x)
				{
					cout << "\nBook Not Found\n";
				}
				else
				{
					cout << "\nBook Remove Successfully!!!!\n";
				}
			}
			else
			{
				cout << "Comics File is missing!!!!\n";
			}
		}
		else
		{
			break;
		}
	}
}
void High_Services::start()
{
	int choice;
	while (1)
	{

		cout << "\n\n............Enter Ur Choice............\n\n";
		cout << "|Press 1 for Search a Book\n";
		cout << "|Press 2 for See All BooKs\n";
		cout << "|Press 3 for Remove a book\n";
		cout << "|Press any other number for Back\n";
		cout << "Enter Choice:";
		cin >> choice;

		if (choice == 1)
		{
			system("CLS");

			search();
		}

		else if (choice == 2)
		{
			system("CLS");

			See_Books();
		}

		else if (choice == 3)
		{
			Remove_book();
		}

		else
			break;
	}



}
High_Services::High_Services()
{
	//cunstructor
}
High_Services::~High_Services()
{
	//Destructor
}

//Sevices Method
void Services::edit_book(){
	int choice, flag = 0;
	char fil[20] = { '\0' };
	char  c[20] = { '\0' };
	while (1)
	{
		ofstream t("temp.txt");
		t.close();
		cout << "\n\n.......................Edit...................\n\n";
		cout << "=========================\n";
		cout << "|Press 1 for Edit a book in Literatture\n";
		cout << "|Press 2 for Edit a book in Philosophy\n";
		cout << "|Press 3 for Edit a book in Science\n";
		cout << "|Press 4 for Edit a book in Comics\n";
		cout << "Press any other number for Back\n";
		cout << "==========================";
		cout << "\nEnter Chioce:";
		cin >> choice;
		if (choice == 1){
			flag++;
			cout << "Enter Code:";
			cin >> c;
			int x = 0;
			string name, writername, price; char ig[30];
			char cod[10] = { '\0' };
			ifstream fin("Literature.txt");
			if (fin.is_open())
			{
				while (getline(fin, name))
				{
					int k = 0;
					getline(fin, writername);
					fin.getline(ig, 29, '\n');
					for (int i = 0; ig[i] != '\0'; i++)
					{
						if (ig[i] >= '0'&&ig[i] <= '9')
						{
							cod[k++] = ig[i];
						}
					}
					getline(fin, price);

					if (strcmp(cod, c) == 0)
					{
						cout << "Book Name :"; cin.ignore(); getline(cin, name);
						cout << "Publisher Name :"; getline(cin, writername);
						cout << "Book Code :"; cin >> cod;
						cout << "BooK Price :"; cin >> price;
						t.open("temp.txt", ios::app);
						{
							t << "Book Name :" << name << endl;
							t << "Publisher Name :" << writername << endl;
							t << "Book Code :" << cod << endl;
							t << "BooK Price :" << price << endl;

							t.close();
						}
						x++;
					}
					else
					{
						t.open("temp.txt", ios::app);
						{
							t << name << endl << writername << endl << ig << endl << price << endl;
							t.close();
						}
					}

				}
				fin.close();
				ofstream fou("Literature.txt", ios::out);
				ofstream fout("Literature.txt", ios::app);
				{
					string ch;
					ifstream f("temp.txt");
					{
						getline(f, ch);
						fout << ch;
						while (!f.eof())
						{
							getline(f, ch);
							fout << endl << ch;
						}
						f.close();
					}
					fout.close();
					remove("temp.txt");
				}
				if (!x)
				{
					cout << "\nBook Not Found\n";
				}
				else
				{
					cout << "\nBook Edit Successfully!!!!\n";
				}
			}
			else
			{
				cout << "Literature File is missing!!!!\n";
			}

		}
		else if (choice == 2){
			flag++;
			cout << "Enter Code:";
			cin >> c;
			int x = 0;
			string name, writername, price; char ig[30];
			char cod[10] = { '\0' };
			ifstream fin("Philosophy.txt");
			if (fin.is_open())
			{
				while (getline(fin, name))
				{
					int k = 0;
					getline(fin, writername);
					fin.getline(ig, 29, '\n');
					for (int i = 0; ig[i] != '\0'; i++)
					{
						if (ig[i] >= '0'&&ig[i] <= '9')
						{
							cod[k++] = ig[i];
						}
					}
					getline(fin, price);

					if (strcmp(cod, c) == 0)
					{
						cout << "Book Name :"; cin.ignore(); getline(cin, name);
						cout << "Publisher Name :"; getline(cin, writername);
						cout << "Book Code :"; cin >> cod;
						cout << "BooK Price :"; cin >> price;
						t.open("temp.txt", ios::app);
						{
							t << "Book Name :" << name << endl;
							t << "Publisher Name :" << writername << endl;
							t << "Book Code :" << cod << endl;
							t << "BooK Price :" << price << endl;

							t.close();
						}
						x++;
					}
					else
					{
						t.open("temp.txt", ios::app);
						{
							t << name << endl << writername << endl << ig << endl << price << endl;
							t.close();
						}
					}

				}
				fin.close();
				ofstream fou("Philosophy.txt", ios::out);
				ofstream fout("Philosophy.txt", ios::app);
				{
					string ch;
					ifstream f("temp.txt");
					{
						getline(f, ch);
						fout << ch;
						while (!f.eof())
						{
							getline(f, ch);
							fout << endl << ch;
						}
						f.close();
					}
					fout.close();
					remove("temp.txt");
				}
				if (!x)
				{
					cout << "\nBook Not Found\n";
				}
				else
				{
					cout << "\nBook edit Successfully!!!!\n";
				}
			}
			else
			{
				cout << "Philosophy File is missing!!!!\n";
			}

		}
		else if (choice == 3)
		{
			flag++;
			cout << "Enter Code:";
			cin >> c;
			int x = 0;
			string name, writername, price; char ig[30];
			char cod[10] = { '\0' };
			ifstream fin("Science.txt");
			if (fin.is_open())
			{
				while (getline(fin, name))
				{
					int k = 0;
					getline(fin, writername);
					fin.getline(ig, 29, '\n');
					for (int i = 0; ig[i] != '\0'; i++)
					{
						if (ig[i] >= '0'&&ig[i] <= '9')
						{
							cod[k++] = ig[i];
						}
					}
					getline(fin, price);

					if (strcmp(cod, c) == 0)
					{
						cout << "Book Name :"; cin.ignore(); getline(cin, name);
						cout << "Publisher Name :"; getline(cin, writername);
						cout << "Book Code :"; cin >> cod;
						cout << "BooK Price :"; cin >> price;
						t.open("temp.txt", ios::app);
						{
							t << "Book Name :" << name << endl;
							t << "Publisher Name :" << writername << endl;
							t << "Book Code :" << cod << endl;
							t << "BooK Price :" << price << endl;

							t.close();
						}
						x++;
					}
					else
					{
						t.open("temp.txt", ios::app);
						{
							t << name << endl << writername << endl << ig << endl << price << endl;
							t.close();
						}
					}

				}
				fin.close();
				ofstream fou("Science.txt", ios::out);
				ofstream fout("Science.txt", ios::app);
				{
					string ch;
					ifstream f("temp.txt");
					{
						getline(f, ch);
						fout << ch;
						while (!f.eof())
						{
							getline(f, ch);
							fout << endl << ch;
						}
						f.close();
					}
					fout.close();
					remove("temp.txt");
				}
				if (!x)
				{
					cout << "\nBook Not Found\n";
				}
				else
				{
					cout << "\nBook edit Successfully!!!!\n";
				}
			}
			else
			{
				cout << "Science File is missing!!!!\n";
			}

		}
		else if (choice == 4)
		{
			flag++;
			cout << "Enter Code:";
			cin >> c;
			int x = 0;
			string name, writername, price; char ig[30];
			char cod[10] = { '\0' };
			ifstream fin("Comics.txt");
			if (fin.is_open())
			{
				while (getline(fin, name))
				{
					int k = 0;
					getline(fin, writername);
					fin.getline(ig, 29, '\n');
					for (int i = 0; ig[i] != '\0'; i++)
					{
						if (ig[i] >= '0'&&ig[i] <= '9')
						{
							cod[k++] = ig[i];
						}
					}
					getline(fin, price);

					if (strcmp(cod, c) == 0)
					{
						cout << "Book Name :"; cin.ignore(); getline(cin, name);
						cout << "Publisher Name :"; getline(cin, writername);
						cout << "Book Code :"; cin >> cod;
						cout << "BooK Price :"; cin >> price;
						t.open("temp.txt", ios::app);
						{
							t << "Book Name :" << name << endl;
							t << "Publisher Name :" << writername << endl;
							t << "Book Code :" << cod << endl;
							t << "BooK Price :" << price << endl;

							t.close();
						}
						x++;
					}
					else
					{
						t.open("temp.txt", ios::app);
						{
							t << name << endl << writername << endl << ig << endl << price << endl;
							t.close();
						}
					}

				}
				fin.close();
				ofstream fou("Comics.txt", ios::out);
				ofstream fout("Comics.txt", ios::app);
				{
					string ch;
					ifstream f("temp.txt");
					{
						getline(f, ch);
						fout << ch;
						while (!f.eof())
						{
							getline(f, ch);
							fout << endl << ch;
						}
						f.close();
					}
					fout.close();
					remove("temp.txt");
				}
				if (!x)
				{
					cout << "\nBook Not Found\n";
				}
				else
				{
					cout << "\nBook Edit Successfully!!!!\n";
				}
			}
			else
			{
				cout << "Comics File is missing!!!!\n";
			}

		}
		else
		{
			break;
		}
	}
}
Services::Services()
{
	//constructor involk 
}
void Services::start()
{
	int choice;
	while (1)
	{

		system("CLS");
		cout << "\n\n.............Enter Ur Choice..............\n\n";
		cout << "|Press 1 for Add a Books\n";
		cout << "|Press 2 for See All Books\n";
		cout << "|Press 3 for Search a bOoK\n";
		cout << "|Press 4 for Remove a bOoK\n";
		cout << "|Press 5 for Edit a bOoK\n";
		cout << "|Press any other key for Back\n";
		cout << "Enter Choice:";
		cin >> choice;
		if (choice == 1)
		{
			system("CLS");
			add_books();
		}

		else if (choice == 2)
		{
			system("CLS");

			display();
		}

		else if (choice == 3)
		{
			system("CLS");

			search();
		}
		else if (choice == 4)
		{
			system("CLS");

			Remove_book();
		}
		else if (choice == 5)
		{
			system("CLS");

			edit_book();
		}
		else
			break;
	}



}
Services::~Services()
{
	//destructor
}

//User Method
User::User(){
	name = nullptr;
	id = 0;
	username = nullptr;
	Password = nullptr;
}
User::User(char *username, char * pass, char * name){
	this->username = new char[strlen(username) + 1];
	strcpy(this->username, username);
	this->Password = new char[strlen(pass) + 1];
	strcpy(this->Password, pass);
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
User::User(char *username, char * name){
	this->username = new char[strlen(username) + 1];
	strcpy(this->username, username);

	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
void User::set_name(char * name){
	this->name = new char[strlen(name) + 1];
	strcpy(this->name, name);
}
void User::Set_username(char *username){
	this->username = new char[strlen(username) + 1];
	strcpy(this->username, username);
}
void User::set_Password(char *pass){
	this->Password = new char[strlen(pass) + 1];
	strcpy(this->Password, pass);
}
void User::set_id(int id){
	this->id = id;
}
void User::settingAccounts(char * username, char * pass, char * name){
	set_name(name);
	Set_username(username);
	set_Password(pass);
}
void User::Login() {
	char pass[32] = { '\0' };
	cout << "\n\n\n\nWelcome to " << username << " Account " << endl;
	cout << "Enter Password :"; Enter_password(pass); cin.ignore();
	verify_password(pass);
}
User::~User()
{
	delete[] name; name = nullptr;
	delete[] username; username = nullptr;
	delete[] Password; Password = nullptr;
}
void User::Display_info(){
	system("CLS");
	cout << "Name :" << name << endl;
	cout << "ID: " << id << endl;
	cout << "--------------------\n";
}
void User::verify_password(char  pass[32]){
	char Pass[32] = { '\0' };
	while (true)
	{

		cout << Pass << endl;;
		cout << Password << endl;
		if (strcmp(pass, Password) == 0 || strcmp(Pass, Password) == 0)
		{
			cout << username << " Login Account SuccessFul!...\n";
			system("CLS");
			break;

		}
		else
		{
			cout << "\nIncorrect Password !!!\nEnter passsword Again:";  Enter_password(Pass);
		}
	}
}

//Admin method
Admin::Admin()
{
	admin = nullptr;
	settingAccounts("Admin", "admin", "Bilal Mumtaz");
}
Admin::Admin(char *username, char * name) :User(username, name)
{
	Password = { "admin" };
}
void Admin::menu(){
	Login();
	while (true)
	{
		Display_info();
		cout << "\n\n\n\n|Press 1 for Start Work!!!\n";
		cout << "|Press other number for Logout Account\n";
		cout << "----------------------------------\nSelect Option :";
		int ch;
		cin >> ch;
		if (ch == 1)
		{
			admin = new Services;
			admin->start();
		}
		else
		{
			cout << "Your Acoount is Loging out\n";
			Sleep(2500);
			system("CLS");
			break;
		}

	}
}
void Admin::Set_admin_data(char *username, char * name){
	set_name(name);
	Set_username(username);
	set_id(001);
}
Admin::~Admin()
{
	delete admin; admin = nullptr;
}
void Admin::Display_info(){
	system("CLS");
	cout << "<<<<<<<<<<<<<<<(ADMIN)>>>>>>>>>>>>>>\n";
	cout << "Name :" << name << endl;
	cout << "ID: " << id << endl;
	cout << "--------------------\n";
}

//Manager Method
Manager::Manager(){
	e = nullptr;
	set_id(001);
	set_name("Bilal");
	Set_username("Bilal290");
	set_Password("manager");
}
Manager::Manager(char *username, char * pass, char * name, int id) :User(username, pass, name){
	this->id = id;
}
void Manager::menu(){
	Login();
	while (1)
	{
		Display_info();
		cout << "\n\n|Press 1 for Start Work!!!\n";
		cout << "|Press other number for Logout Account\n----------------------------------\nSelect Option :";
		int ch;
		cin >> ch;
		if (ch == 1)
		{
			e = new High_Services();
			e->start();
		}
		else
		{
			cout << "Your Acoount is Logout\n";
			Sleep(2500);
			break;
		}
	}
}
Manager::~Manager()
{
	delete e; e = nullptr;
}
void Manager::Display_info(){
	system("CLS");
	cout << "<<<<<<<<<<<<<<<(MANAGER)>>>>>>>>>>>>>>\n";
	cout << "Name :" << name << endl;
	cout << "ID: " << id << endl;
	cout << "--------------------\n";
}

//Employee Method
Employee::Employee(){
	name = { "Bilal" };
	username = { "Employee" };
	Password = { "employee" };
	id = 001;
	settingAccounts(username, Password, name);
	ptr = nullptr;
}
Employee::Employee(char *username, char * pass, char * name, int id) :User(username, pass, name){
	this->id = id;
}
Employee::~Employee()
{
	delete ptr; ptr = nullptr;
}
void Employee::Menu(){
	Login();
	while (true)
	{
		Display_info();
		cout << "-----------\n\n\n\n|Press 1 for Start Work\n";
		cout << "|Press other number for Logout Account\n";
		int ch;
		cin >> ch;
		if (ch == 1)
		{
			ptr = new Mini_services;
			ptr->start();
		}
		else
		{
			cout << "Your Acoount is Loging out\n";
			Sleep(2500);
			system("CLS");
			break;
		}
	}
}
void Employee::Display_info(){
	system("CLS");
	cout << "<<<<<<<<<<<<<<<(EMPLOYEE)>>>>>>>>>>>>>>\n";
	cout << "Name :" << name << endl;
	cout << "ID: " << id << endl;
	cout << "----------------------------\n";
}

//Extra Methods
void  Enter_password(char *password){

	for (int i = 0; i<32; i++)
	{
		password[i] = _getch();
		cout << "*";

		if (password[i] == '\r')
			break;

		else if (password[i] == '\b'){

			if (i == 0)
				cout << "\b" << " " << "\b";
			else if (i >= 1){
				password[i - 1] = '\0';
				i = i - 2;
				cout << "\b" << " " << "\b\b" << " " << "\b";
			}

		}
	}
	int l = strlen(password);
	password[l - 1] = '\0';

}

int menu(){
	int choise;
	cout << "\n*** To Book Store Management System ****\n";
	cout << "========================================\n";
	cout << "|Press 1 for Admin Account             |\n";
	cout << "|Press 2 for Manager Account           |\n";
	cout << "|Press 3 for Employe Account           |\n";
	cout << "|Press any other Number to Exit Program|\n";
	cout << "========================================\n";
	cout << "Select option :"; cin >> choise;
	return choise;
}

void welcome()
{
	ifstream ifs("welcome.txt");
	string Lines = "";
	if (ifs)
	{

		while (ifs.good())
		{
			string TempLine;
			getline(ifs, TempLine);
			TempLine += "\n";

			Lines += TempLine;
		}

		cout << Lines;


	}
	cout << "\n";
	ifs.close();

}

void exitArt()
{
	ifstream ifs("exit art.txt");
	string Lines = " ";
	if (ifs)
	{
		while (ifs.good())
		{
			string TempLine;
			getline(ifs, TempLine);
			TempLine += "\n";

			Lines += TempLine;
		}

		cout << Lines;

	}
	cout << "\n\t  \t\t\t\t\t\t\t";
	ifs.close();
	exit(0);
}

//(----------------------------- The End ---------------------------)


