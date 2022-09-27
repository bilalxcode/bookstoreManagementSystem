#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<fstream>
#include<string>
#include <conio.h>
#include<Windows.h>

class books
{
private:
	char *CODE, *B_NAME, *W_NAME;
	float PRICE;

protected:
	void books::setValues(char * n, char *b, char *  w, float p);

	char code[10], b_name[30], w_name[30];
	float price;
public:
	books();
	virtual ~books();
	void Enter_data();
	virtual void book_data();

};

class Literature :public books
{
public:
	void book_data();
};

class Philosophy :public books
{
public:
	void book_data();
};

class Science :public books
{
public:
	void book_data();
};

class Comics :public books
{
public:

	void book_data();
};

class Mini_services {
private:
	Literature t1;
	Philosophy t2;
	Science t3;
	Comics t4;
protected:
	void display();
	void add_books();
public:
	virtual void start();
	Mini_services();
	virtual ~Mini_services();
};

class High_Services
{
protected:
	Literature t1;
	Philosophy t2;
	Science t3;
	Comics t4;
protected:
	void search();
	void See_Books();
	void Remove_book();
public:
	High_Services();
	virtual void start();
	virtual ~High_Services();


};

class Services : public Mini_services, public High_Services
{
protected:
	void edit_book();
public:
	Services();

	void start();

	~Services();

};

class User
{
public:
	User();
	User(char *username, char * pass, char * name);
	User(char *username, char * name);

	void set_name(char * name);
	void Set_username(char *username);
	void set_Password(char *pass);
	void set_id(int id);

	void settingAccounts(char * username, char * pass, char * name);
	void Login();
	virtual ~User();

	virtual void Display_info();
protected:
	void verify_password(char  pass[32]);
	char * name;
	int id;
	char *username;
	char *Password;
};

class Admin :public User
{
public:
	Admin();
	Admin(char *username, char * name);
	void menu();

	void Set_admin_data(char *username, char * name);

	~Admin();

	void Display_info();
private:
	Services *admin;

};

class Manager :public User
{
public:
	Manager();
	Manager(char *username, char * pass, char * name, int id);
	void menu();
	~Manager();
	void Display_info();
private:
	High_Services *e;
};

class Employee :public User
{
protected:
	Mini_services  *ptr;
public:
	Employee();
	Employee(char *username, char * pass, char * name, int id);
	~Employee();
	void Menu();
	void Display_info();
};

int menu();

void welcome();

void exitArt();

void  Enter_password(char *password);
//(----------------------------- The End ---------------------------)

