#include <iostream>
/*#include <fstream>
#include <string>
#include <conio.h>
#include <Windows.h>
#include <stdio.h>
#include <dos.h>
#include <cstdlib>
using namespace std;
int count_fast = 0;
int counter_food = 0;
struct Food {
	string name;
	int price;
	string type;
	Food *next;
	Food *prev;
}*head=NULL;

void fastFoodFile() {
	Food *food = new Food;
	ofstream  file;// ("fastfood.txt");
	file.open("fastfood.txt", ios::app | ios::ate);
	file << food->name << endl;
}
void colddrinkfile() {
	Food *food = new Food;
	ofstream file;
	file.open("coldrink.txt");
	file << food->name << endl;
}
void desertfile() {
	Food *food = new Food;
	ofstream file;
	file.open("desert.txt");
	file << food->name << endl;
}
void addFood(string name, int price,string type) {
	Food *newfood = new Food;
	newfood->name = name;
	newfood->price = price;
	newfood->type = type;
	newfood->prev = NULL;
	newfood->next = NULL;
	Food *temp;
	
	//file << newfood->name << endl;
	if (head == NULL) {
		head = newfood;
	}
	else {
		temp = head;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newfood;
		newfood->prev = temp;
	}
	if (type == "fastfood" || type == "Fastfood") {
		fastFoodFile();
	}
	else if (type == "drink" || type == "Drink") {
		colddrinkfile();
	}
	else if (type == "desert" || type == "Desert") {
		desertfile();
	}
	count_fast++;
}
bool searchfood(string name) {
	//Food *food = new Food;
	Food *temp;
	temp = head;
	bool flag = false;
	cout << temp->name;
	if (head == NULL) {
		cout << "Empty food" << endl;
	}
	else {
		while (temp->next != NULL) {
			if (temp->name == name) {
				flag = true;
				break;
			}
			else {
				counter_food++;
				temp = temp->next;
			}
		}
	}
	return flag;
}
void removeAtFront() {
	Food *food = new Food;
	Food *temp;
	temp = head;
	head = head->next;
	delete temp;
}
void removeAtEnd() {
	Food *food = new Food;
	Food *temp;
	temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->prev->next = NULL;
	delete temp;
}
void removeAtPosition() {
	Food *food = new Food;
	Food *temp;
	temp = head;
	string item;
	cout << "Enter item name: ";
	cin >> item;
	if (searchfood(item)==true) {
		if (counter_food == 1) {
			removeAtFront();
		}
		else if (counter_food == count_fast) {
			removeAtEnd();
		}
		else {
			for (int i = 1; i <= counter_food; i++) {
				temp = temp->next;
			}
			temp->next->prev = temp->prev;
			temp->prev->next = temp->next;
			delete temp;
		}
	}
	else
	{
		cout << "not found"
			<< endl;
	}
}
void display() {
	//Food *food = new Food;
	Food *temp;
	temp = head;
	
	if (head == NULL) {
		cout << "Empty ";
	}
	else {
		cout << temp->name << " " << temp->price << " " << temp->type;
		while (temp->next != NULL) {
			
			cout << temp->name << " " << temp->price << " " << temp->type;
			temp = temp->next;
		}
	}
	
}

int main() {
	string foodname, foodtype;
	//window(6, 21, 80, 25);
	//system("color 2f");
	//system("colr 0e");
	char a = 177, b = 219;
	cout << "\n\n\n\t\t\t\t\tLoading.....";
	cout << "\n\n\n";
	cout << "\t\t\t\t\t";
	for (int i = 0; i <= 25; i++) {
		cout << a;
		Sleep(20);
	}
	cout << "\r";
	cout << "\t\t\t\t\t";
	for (int i = 0; i <= 25; i++) {
		cout << b;
		Sleep(50);
	}
	system("cls");
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_RED&FOREGROUND_GREEN| FOREGROUND_BLUE| FOREGROUND_INTENSITY);
	cout << "****************************************" << endl;
	cout << "Online Food ordering system" << endl;
	cout << "****************************************" << endl;
	SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
	int price;
	//system("COLOR 1F");
	//system("COLOR 2");
	//system("COLOR 4");
	int num;
	//int choice;
	do {
		cout << "********************************";
		cout << endl;
		cout << "[1] add item " << endl;
		cout << "[2] delete item " << endl;
		cout << "[3] display " << endl;
		cout << "[0] exit" << endl;
		cin >> num;
		switch (num) {
		case 1:
		{
			cout << "Enter food type ";
			cin >> foodtype;
			cout << "Enter food name : ";
			cin >> foodname;
			cout << "Enter price: ";
			cin >> price;
			addFood(foodname, price, foodtype);
			break;
		}
		case 2: {
			removeAtPosition();
			break;
		}
		case 3:
		{display();
			break;
		}
		default:
				cout << "invalid" << endl;
		}
		

	} while (num != 0);
	//getch();
	system("pause>0");
}*/