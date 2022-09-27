//Please Put attach File of Welcome.txt & Exit_Art in Execution project path before Debugging the Program 
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<fstream>
#include<string>
#include <conio.h>
#include<Windows.h>
#include"Header.h"
using namespace std;

int main(){

	while (1)
	{
		system("CLS");
		int choise = 0;
		welcome();
		choise = menu();
		if (choise == 1)
		{
			char name[30] = { '\0' };  char u_name[32] = { '\0' };

			Admin A1;
			cout << "\nEnter name   :";
			cin.ignore();
			cin.getline(name, 30, '\n');

			cout << "\nEnter User Name  : ";
			cin.getline(u_name, 10, '\n');
			system("CLS");
			A1.Set_admin_data(u_name, name);
			A1.menu();

		}
		else if (choise == 2)
		{
			int c, ch;
			cout << "----------------------------\n";
			cout << "\n\n|Press 1 for New Account!! \n";
			cout << "|Press 2 for Default Account!!\n";
			cout << "|Enter Other Number for back \n";
			cout << "----------------------------\n";
			cout << "Select option :"; cin >> c;
			if (c == 1)
			{
				system("CLS");
				char name[30] = { '\0' }; int id; char u_name[32] = { '\0' };
				char password[32] = { '\0' };

				cout << "\nEnter name   :";
				cin.ignore();
				cin.getline(name, 30, '\n');

				cout << "\nEnter User Name  : ";
				cin.getline(u_name, 10, '\n');

				cout << "\nEnter Password :";
				Enter_password(password);

				cout << "\n\nEnter iD       :";
				cin >> id;
				system("CLS");
				Manager M(u_name, password, name, id);
				M.menu();
			}
			else if (c == 2)
			{
				Manager E2;
				E2.menu();

			}
		}
		else if (choise == 3)
		{
			int c = 0, ch = 0;
			cout << "\n\n|Press 1 for New Account!! \n";
			cout << "|Press 2 for Default Account!!\n";
			cout << "|Enter Other Number for back \n";
			cout << "Select option :"; cin >> c;
			if (c == 1)
			{
				system("CLS");
				char name[30] = { '\0' }; int id; char u_name[32] = { '\0' };
				char password[32] = { '\0' };

				cout << "\nEnter name   :";
				cin.ignore();
				cin.getline(name, 30, '\n');

				cout << "\nEnter User Name  : ";
				cin.getline(u_name, 10, '\n');

				cout << "\nEnter Password :";
				Enter_password(password);

				cout << "\nEnter iD       :";
				cin >> id;
				system("CLS");
				Employee x(u_name, password, name, id);
				x.Menu();
			}
			else if (c == 2)
			{
				Employee E2;
				E2.Menu();

			}
			else
			{
				system("CLS");
				//Back
			}
		}
		else
		{
			system("CLS");
			exitArt();
		}
	}
}
//(----------------------------- The End ---------------------------)
