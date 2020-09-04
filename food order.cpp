#include <iostream>
#include <string>
#include <fstream>
#include <Windows.h>
#include <ctime>
using namespace std;
struct foods {
	string fname;
	int price;
	foods *next;
	foods *prev;
} *heady = NULL;

struct fastfood {
	string fname;
	int price;
	fastfood *next;
	fastfood *prev;
} *head = NULL;

struct customer {
	int id;
	string name;
	string address;
	int amount;
	customer *next;
	customer *prev;
} *headd = NULL;
customer *infoCust=NULL;

int FasFood_Count = 0;
int totalCount = 0;
int totalPKR = 0;
char* current_time();
char* current_time()   /// current time()
{
	time_t now = time(0);
   time_t r=time(0);
   char* dt = ctime(&now);
   char* rt=ctime(&r);
   tm *gmtm = gmtime(&now);
   return dt;
}
void insertcustomer(int id,string name,string address,int amount){
	customer *newcustomer=new customer;
}
/*
void insertCustomer(int id,string name,string address,int amount)
{
	customer *newcustomer = new customer;
	customer *temp;
	newcustomer->id = id;
	newcustomer->name = name;
	newcustomer->address = address;
	newcustomer->amount = amount;
	newcustomer->next = NULL;
	newcustomer->prev = NULL;
	
	if(headd == NULL)
	{
		headd = newcustomer;
		cout<<"suces"<<endl;
	}
	else{
		temp = headd;
		while(temp->next != NULL)
		{
			temp = temp->next;
		}
		temp->next = newcustomer;
		newcustomer->prev = temp;
		cout<<"succes"<<endl;
	
	}ofstream file("BillOrder.txt",ios::app|ios::ate);
	file<<id<<" "<<name<<" "<<address<<" "<<amount<<endl;
	file.close();
}
*/
void insert_fileCustomer(){
	
	string name,address;
	int amount,id;
	bool flag = false;
	customer *temp;
	ifstream myfile("BillOrder.txt");
	if (!myfile){
		cout<<"open nai ho rha "<<endl;
	}
	while (!myfile.eof())
	{
		myfile >>id>> name >> address >> amount;
		customer *newcust = new customer;
		newcust->id = id;
		newcust->name = name;
		newcust->address = address;
		newcust->amount = amount;
		newcust->next = NULL;
		newcust->prev = NULL;
		if(headd == NULL)
		{
			headd = newcust;
			flag = true;
		}
		else{
			temp = headd;
			{
				while(temp->next != NULL)
				{
					temp = temp->next;
				}
				temp->next = newcust;
				newcust->prev = temp;
				
			}
		}
	}
	myfile.close();
}

void insert_fileFastfood() {

	string fname; int price;
	bool flag = false;
	fastfood *temp;
	ifstream myfile("fastfood.txt");
	while (!myfile.eof())
	{
		myfile >> fname >> price;
		fastfood *newfood = new fastfood;
		newfood->fname = fname;
		newfood->price = price;
		newfood->next = NULL;
		newfood->prev = NULL;
		if (head == NULL)
		{
			head = newfood;
			flag = true;
		}
		else
		{
			temp = head;
			{
				while (temp->next != NULL)
				{
					temp = temp->next;
				}
				temp->next = newfood;
				newfood->prev = temp;
			}
		}
}
	myfile.close();

}
void insertfastfood(string fname,int price) {
	fastfood *newfood = new fastfood;
	newfood->fname = fname;
	newfood->price = price;
	newfood->next = NULL;
	newfood->prev = NULL;
	fastfood *temp;
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
	ofstream file;
	file.open("fastfood.txt", ios::app | ios::ate);
	file << fname << " " << price << endl;
	file.close();
	
}
struct drink {
	string name;
	int price;
	drink *next;
	drink *prev;
}*head1=NULL;

void insertdrink(string name, int price) {
	drink *newdrink = new drink;
	drink *temp;
	newdrink->name = name;
	newdrink->price = price;
	newdrink->next = NULL;
	newdrink->prev = NULL;
	if (head1 == NULL) {
		head1 = newdrink;
	}
	else {
		temp = head1;
		while (temp->next != NULL) {
			temp = temp->next;
		}
		temp->next = newdrink;
	}
}

void display() {
		fastfood *temp;
		temp = head;
		int i = 1;
		if (head == NULL) {
			cout << "FOOD !NOT AVAILABLE " << endl;
		}
		else {
			while (temp->next != NULL) {
			
				cout <<"["<<i++<<"] Fast Food:" << temp->fname << "\tPRICE " << temp->price << "[PKR]" << endl;
				temp = temp->next;
				cout<<endl;
			}
		}
}
bool searchcust(int id){
	customer *temp;
	temp=headd;
	bool flag=false;
	if (headd==NULL){
		cout<<"Emmpty "<<endl;
	}
	else {
		while(temp->next!=NULL){
			if (id==temp->id){
				flag=true;
				infoCust=temp;
				break;
			}
			else {
			temp=temp->next;
			}
		}
		
	}
	if (flag==true){
		return true;
	}
	else {
		return false;
	}
}
void displayBill(char *time,int id)
{
       customer *tempp;
		tempp = headd;
		if(headd == NULL)
		{
			cout<<"No Bill to Display"<<endl;
		}	
		else{
			while(tempp->next != NULL)
			{
				
				cout<<"Customer ID :\t"<<tempp->id;
				cout<<"Customer Name :\t"<<tempp->name<<endl;
				cout<<"Customer Address :\t"<<tempp->address<<endl;
				cout<<"Total Bill :\t"<<tempp->amount<<endl;
				cout<<"Date and Time: "<<time;
				cout<<endl; 
			tempp=tempp->next;	
			}
					
}
		}

bool searchfastfood(string fname) {
	fastfood *temp;
	temp = head;
	bool flag = false;
	while (temp->next != NULL) {
		if (fname == temp->fname) {
			return true;
		}
		else{
			temp = temp->next;
		}
	}
	return false;
}
void updatefastfood(string name) {
	fstream file;
	file.open("fastfood.txt", ios::app | ios::ate);
}

void order_fastFood(string name,int count, int &t){   //t stands for total
	fastfood *temp=head;
	int pkr;
	//foods *tempy=heady;
	while(name!=temp->fname){
		temp=temp->next;
	}
//	tempy->fname=name;
//	tempy=tempy->next;
	t=temp->price*count+t;
	temp->price=t;
	pkr=temp->price*count+pkr;
	FasFood_Count++;
	totalPKR = pkr;
}
void totalsales()
{
	
	cout<<"Total sales: "<<FasFood_Count<<endl;
	cout<<"Total Money: "<<totalPKR<<endl;
}
void save_order(int &t){
	fastfood *temp;
	foods *tempy=heady;
	string name,add;
	
	cout<<"enter your name : ";
	cin>>name;
	cout<<"enter your address : ";
	cin>>add;
	ofstream file("Bills.txt", ios::app | ios::ate);
	file<<name<<" "<<add<<endl;
	while(tempy->next!=NULL){
		file<<tempy->fname;
		tempy=tempy->next;
	}
	file<<temp->price;
	t=0;
}
void displaybillCustomer(int id){
	customer *temp;
	temp=headd;
	if (headd==NULL){
		cout<<"not "<<endl;
	}
	else {
		if (searchcust(id)==true){
			cout<<"id\t"<<infoCust->id;
			cout<<"\nname\t"<<infoCust->name<<endl;
		}
		else {
			cout<<"nai mila bhai"<<endl;
		}
	}
}
void mainMenu() {
	foods *temp;
	string fname;
	int price; int num, choicefast, total=0;// , choiceDesert, choiceDrink;
	insert_fileFastfood();
//	insert_fileCustomer();
	HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(h, FOREGROUND_RED | FOREGROUND_GREEN | FOREGROUND_INTENSITY);
	cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
	cout << "*\tOnline Food ordering system   *" << endl;
	cout << "%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%%" << endl;
	SetConsoleTextAttribute(h, FOREGROUND_INTENSITY | FOREGROUND_INTENSITY);
	cout << "W";
	Sleep(50);
	cout << "E"; Sleep(50); cout << "L";  Sleep(50); cout << "C"; Sleep(50); cout << "O"; Sleep(50); cout << "M"; Sleep(50); cout << "E";
	Sleep(50); cout << " T"; Sleep(50); cout << "O"; Sleep(50); cout << " O"; Sleep(50); cout << "U"; Sleep(50); cout << "R"; Sleep(50); cout << " R"; Sleep(50);
	cout << "E"; Sleep(50); cout << "S"; Sleep(50); cout << "T"; Sleep(50);
	cout << "A"; Sleep(50); cout << "U"; Sleep(50); cout << "R"; Sleep(50);
	cout << "A"; Sleep(50); cout << "N"; Sleep(50); cout << "T"; Sleep(100);
	system("cls");
	int choice;
	do {
			 //insert_fileCustomer();
		cout << "[1] for MANAGE FOOD" << endl;
		cout << "[2] for ORDER FOOD" << endl;
		cout << "[3] for CHEK OUT" << endl;
		cout << "[4] for SALES" << endl;
		cout << "[0] for EXIT" << endl;
		cin >> choice;
		 
		if (choice == 1) {
			cout << "[1] for FAST FOOD" << endl;
			cout << "[2] for DESERT FOOD" << endl;
			cout << "[3] for DRINKS" << endl;
			cout << "[0] for EXIT" << endl;
			
			cin >> num;
			do {
				if (num == 1) {					do {

					cout << "[1] ADD FAST FOOD " << endl;
					cout << "[2] DELETE FAST FOOD " << endl;
					cout << "[3] UPDATE FAST FOOD" << endl;
					cout << "[4] SEARCH FAST FOOD" << endl;
					cout << "[5] DISPLAY FAST FOOD " << endl;
					cout << "[0] EXIT" << endl;
					cin >> choicefast;
					if (choicefast == 1) {
						cout << "ENTER FOOD NAME: ";
						cin >> fname;
						cout << "ENTER PRICE : ";
						cin >> price;
						insertfastfood(fname, price);
					}
					else if (choicefast == 0) {
						mainMenu();
					}
					else if (choicefast == 5) {
						display();
					}

					} while (choicefast != 0);
					cout << "ENTER FOOD NAME :";
					cin >> fname;
					cout << "ENTER PRICE [PKR]: ";
					cin >> price;
					insertfastfood(fname, price);
				}
				if (num == 0) {
					mainMenu();
				}
			} while (num != 0);
		}
		 else if(choice==2){
		 	int option;
		 	int qty,id;
		    string name,custName,add;
		    char choice;
		       ofstream file("Order.txt", ios::app | ios::ate);
		 //   ofstream file2("BillOrder.txt", ios::app | ios::ate);
		 	cout<<"1.Fast Food \n2.Dessert \n3.Beverages"<<endl<<endl;
		 	cout<<"Choose from the Given Option : ";
		 	cin>>option;
		 	if(option==1){
		 	
		    
		 
		    do{
		 	display();
		 	cout<<"Enter name of the food you want to order : ";
		 	cin>>name;
		 	cout<<"Enter Qty : ";		 	
		 	cin>>qty;
		   // temp->fname=name;
			order_fastFood(name,qty,total);
			cout<<endl<<endl;
		 	cout<<"                                      "<<"Total: PKR "<<total<<endl;
		 //	temp=temp->next;
		 
	
		 cout<<endl<<"Do you want to make another order (Y/N) : ";
		 cin>>choice;
		 
	        }while(choice=='y' || choice=='Y');
	    }
         cout<<"Customer ID : ";
		 cin>>id;	    
	     cout<<"Enter Customer Name : ";
		 cin>>custName;
		 cout<<"Enter Address : ";
		 cin>>add;
	//	 file<<id<<custName<<" "<<add<<" "<<name<<" "<<total<<endl;
		// file2<<id<<custName<<" "<<add<<" "<<total<<endl;
		 //cout<<"dsadas";
	
		 insertCustomer(id,name,add,total);
	displaybillCustomer(id);
		}
		else if(choice==3)
			{
				save_order(total);
			}
		else if(choice==4)
		{
			totalsales();
		}
		cout << "[1] for MANAGE FOOD" << endl;
		cout << "[2] for ORDER FOOD" << endl;
		cout << "[3] for CHEK OUT" << endl;
		cout << "[4] for SALES" << endl;
		cout << "[0] for EXIT" << endl;
		cin >> choice;
	} while (choice != 0);
}
int main() {
	mainMenu();
	system("pause");
}
