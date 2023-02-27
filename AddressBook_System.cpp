#include<iostream>
#include<stdlib.h> 
#include<string>
#define MAX 1000
using namespace std;

struct Person{
	string name;
	int gender; //1 tand for male and 2 stand for female
	int age;
	string phone;
	string address;
};

struct AddressBook{
	struct Person personarray[MAX];
	int Size;
};

void showMenu(){
	cout << "******************************" << endl;
	cout << "***** 1. Add Contact *****\n***** 2. Show All Contact *****\n***** 3. Delete Contact *****\n***** 4. Search Contact *****\n***** 5. Update Contact *****\n***** 6. Clear All Data *****\n***** 0. Exit the System *****" << endl;
	cout << "******************************" << endl;
}

void addPerson(AddressBook * abs){
	//determine whether the record reach the MAX
	if(abs->Size == MAX){
		cout << "FULL OF RECORDs" << endl;
		return ;
	}
	else{
		string Name;
		cout << "ENTER NAME: ";
		getline(cin, Name);
		abs->personarray[abs->Size].name = Name;
		
		cout << "PLEASE ENTER YOUR GENDER" << endl;
		cout << "1. MALE\n2. FEMALE" << endl;
		int sex = 0;
		while(true){
			cin >> sex;
			if(sex == 1 || sex == 2){
				abs->personarray[abs->Size].gender = sex;
				break;
			}
			cout << "INVALID INPUT..." << endl;
		}
		cout << "ENTER AGE: ";
		int Age;
		cin >> Age;
		abs->personarray[abs->Size].age = Age;
		cout << "ENTER PHONE NUMBER: ";
		string Phone;
		fflush(stdin);
		getline(cin, Phone);
		abs->personarray[abs->Size].phone = Phone;
		
		cout << "ENTER ADDRESS: ";
		string Address;
		getline(cin,Address);
		abs->personarray[abs->Size].address = Address;
		
		abs->Size ++;
		cout << "THE RECORD ADDED SUCCESSFULLY" << endl;
		system("pause");
		system("cls");
	}
}

void DisplayPerson(AddressBook * abs){
	if(abs->Size == 0){
		cout << "THE RECORD IS EMPTY" << endl;
		return;
	}
	else{
		for(int i=0;i<abs->Size;i++){
			cout << "NAME: " << abs->personarray[i].name << "\t";
			cout << "GENDER: " <<(abs->personarray[i].gender == 1 ? "MALE" : "FEMALE") << "\t";
			cout << "AGE: " <<abs->personarray[i].age << "\t";
			cout << "PHONE NUMBER: " <<abs->personarray[i].phone << "\t";
			cout << "ADDRESS: " << abs->personarray[i].address << "\t";
			cout << "\n" << endl;
		}
	}
	system("pause");
	system("cls");
}

//Determine whether the contact exist if exist return address
int isExist(AddressBook * abs, string Name){
	for(int i=0;i<abs->Size;i++){
		if(abs->personarray[i].name == Name){
			return i;
		}
	}
	return -1;
}

void deletePerson(AddressBook * abs){
	cout << "NAME TO DELETE: ";
	
	string Name;
	getline(cin, Name);
	int del = isExist(abs, Name);
	if(del != -1){
		for(int i = del; i < abs->Size; i++){
			abs->personarray[i] = abs->personarray[i+1];
		}
		abs->Size--;
		cout << "DELETED SUCCESSFULLY" << endl;
	}
	else{
		cout << "RECORD NOT FOUND" << endl;
	}
	
	system("pause");
	system("cls");
}

void SearchPerson(AddressBook * abs){
	string Name;
	
	cout << "ENTER PERSON NAME TO SEARCH: ";
	getline(cin, Name);
	
	int search = isExist(abs, Name);
	
	if(search != -1){
		cout << "NAME: " << abs->personarray[search].name << "\t";
		cout << "GENDER: " << abs->personarray[search].gender<< "\t";
		cout << "AGE: " << abs->personarray[search].age<< "\t";
		cout << "PHONE NUMBER: " << abs->personarray[search].phone<< "\t";
		cout << "ADDRESS: " << abs->personarray[search].address;
	}
	else{
		cout << "RECORD NOT FOUND" <<endl;
	}
	system("pause");
	system("cls");
}

void UpdatePerson(AddressBook * abs){
	string Name;
	
	cout << "ENTER PERSON NAME TO UPDATE ";
	getline(cin, Name);
	
	int update = isExist(abs, Name);
	if(update != -1){
		string NAME;
		cout << "NAME: ";
		getline(cin, NAME);
		abs->personarray[update].name = NAME;
		int GENDER;
		cout << "GENDER(1. MALE, 2. FEMALE): ";
		while(true)
		{
			cin >> GENDER;
			if(GENDER == 1 ||GENDER == 2)
			{
				abs->personarray[update].gender = GENDER;
				break;
			}
			cout << "INVALID INPUT " << endl;
		}
		cout << "AGE: ";
		int AGE;
		cin >> AGE;
		fflush(stdin);
		abs->personarray[update].age = AGE;
		cout << "TEL PHONE NUMBER: ";
		string PHONE;
		getline(cin, PHONE);
		abs->personarray[update].phone;
		cout << "ADDRESS: ";
		string ADDRESS;
		getline(cin, ADDRESS);
		abs->personarray[update].address;
		cout << "UPDATE SUCCESSFULLY";
	}
	else{
		cout << "RECORD NOT FOUND" << endl;
	}
	system("pause");
	system("cls");
}

void ClearRecord(AddressBook * abs){
	abs->Size = 0;
	cout << "ALL THE RECORDS HAVE BEEN CLEAR" << endl;
	system("pause");
	system("cls");
}
int main()
{
	int select =0;
	AddressBook abs;
	abs.Size = 0;
	
	while(true){
		
		showMenu();
		
		cin >> select;
		fflush(stdin);
		
		switch(select){
			case 1:
				//add new contact function
				addPerson(&abs);
				break;
			case 2:
				//show all contact function
				DisplayPerson(&abs);
				break;
			case 3:
				//delete contact function
				deletePerson(&abs);
				break;
			case 4:
				//search contact function
				SearchPerson(&abs);
				break;
			case 5:
				//upate contact function
				UpdatePerson(&abs);
				break;
			case 6:
				//clear all ocntact function
				ClearRecord(&abs);
				break;
			case 0:
				cout << "THANK YOU FOR USING OUR SYSTEM" << endl;
				return 0;
				break;
			default:
				cout << "INVALID INPUT. PLEASE TRY AGAIN... THANK YOU..." << endl;
		}
	}
}
