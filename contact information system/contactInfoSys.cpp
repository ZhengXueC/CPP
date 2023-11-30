#include <iostream>
using namespace std;
#include<string>
#define MAX 1000
struct Person {
	string m_Name;
	int m_Sex;
	int m_Age;
	string m_Phone;
	string m_Addr;
};
struct Addressbooks {
	struct Person personArr[MAX];
	int m_Size;
};

void addPerson(Addressbooks* abs) {
	if (abs->m_Size == MAX) {
		cout << "the Addressbook is full! You cannot add!" << endl;
		return;
	}
	else {
		string name;
		cout << "Please enter the name: " << endl;
		cin >> name;
		abs->personArr[abs->m_Size].m_Name = name;
		cout << "Please enter the sex: " << endl;
		cout << "1---Male" << endl;
		cout << "2--Female" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArr[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "Wrong sex enter, choose the sex again" << endl;
		}
		cout << "Please enter the age: " << endl;
		int age = 0;
		cin >> age;
		abs->personArr[abs->m_Size].m_Age =age;
		cout << "Please enter the telephone number: " << endl;
		string phone;
		cin >> phone;
		abs->personArr[abs->m_Size].m_Phone = phone;
		cout << "Please ente the address: " << endl;
		string address;
		cin >> address;
		abs->personArr[abs->m_Size].m_Addr = address;
		abs->m_Size++;
		cout << name<<" added successfully " << endl;
		system("pause");
		system("cls");
	}
}

int isExist(Addressbooks* abs, string name) {
	for (int i = 0;i < abs->m_Size;i++) {
		if (abs->personArr[i].m_Name == name) {
			return i;
		}
	}
	return -1;
}

void deletePerson(Addressbooks* abs2) {
	cout << "Please enter the name of the person you want to delete" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs2, name);
	if (ret != -1) {
		for (int i = ret;i < abs2->m_Size;i++) {
			abs2->personArr[i] = abs2->personArr[i + 1];
		}
		abs2->m_Size--;
		cout << "Deleted successfully" << endl;
	}
	else {
		cout << "Cannot find this person" << endl;
	}
	system("pause");
	system("cls");

}

void showPerson(Addressbooks* abs) {
	if (abs->m_Size == 0) {
		cout << "The addressbook is empty" << endl;
	}
	else {
		for (int i = 0;i < abs->m_Size;i++) {
			cout << "name: " << abs->personArr[i].m_Name << "\t";
			cout << "sex: " << (abs->personArr[i].m_Sex==1?"Male":"Female" )<< "\t";
			cout << "age: " << abs->personArr[i].m_Age << "\t";
			cout << "telephone: " << abs->personArr[i].m_Phone << "\t";
			cout << "address: " << abs->personArr[i].m_Addr << endl;
		}
	}
	system("pause");
	system("cls");
}

void findPerson(Addressbooks*abs) {
	cout << "Please enter the name of the person you want to find" << endl;
	string name;
	cin >> name;
	int ret=isExist(abs, name);
	if (ret != -1) {
		cout << "name: " << abs->personArr[ret].m_Name << "\t";
		cout << "sex: " << (abs->personArr[ret].m_Sex == 1 ? "Male":"Female") << "\t";
		cout << "age: " << abs->personArr[ret].m_Age << "\t";
		cout << "telephone: " << abs->personArr[ret].m_Phone << "\t";
		cout << "Address: " << abs->personArr[ret].m_Addr << endl;
	}
	else {
		cout << "Can not find the person" << endl;
	}
	system("pause");
	system("cls");
}

void modifyPerson(Addressbooks* abs) {
	cout << "Please enter the name you want to edit" << endl;
	string name;
	cin >> name;
	int ret = isExist(abs, name);
	if (ret != -1) {
		string name;
		cout << "Enter the name: " << endl;
		cin >> name;
		abs->personArr[ret].m_Name = name;
		cout << "Please enter the sex: " << endl;
		cout << "1---Male" << endl;
		cout << "2--Female" << endl;
		int sex = 0;
		while (true) {
			cin >> sex;
			if (sex == 1 || sex == 2) {
				abs->personArr[ret].m_Sex = sex;
				break;
			}
			cout << "Wrong sex enter, choose the sex again" << endl;
		}
		cout << "Please enter the age: " << endl;
		int age = 0;
		cin >> age;
		abs->personArr[ret].m_Age = age;
		cout << "Please enter the telephone number: " << endl;
		string phone;
		cin >> phone;
		abs->personArr[ret].m_Phone = phone;
		cout << "Please ente the address: " << endl;
		string address;
		cin >> address;
		abs->personArr[ret].m_Addr = address;
		cout << name << " Edit successfully " << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "Cannot find the person" << endl;
	}
}

void cleanPerson(Addressbooks* abs) {
	abs->m_Size = 0;
	cout << " All recordings are cleared" << endl;
	system("pause");
	system("cls");
}
void showMenu() {
	cout << "*************************************" << endl;
	cout << "*****  1, Add Contact Person    *****" << endl;
	cout << "*****  2, Show Contact Person   *****" << endl;
	cout << "*****  3, Delete Contact Person *****" << endl;
	cout << "*****  4, Search Contact Person *****" << endl;
	cout << "*****  5, Edit Contact Person   *****" << endl;
	cout << "*****  6, Delete All            *****" << endl;
	cout << "*****  0, Exit Address Book     *****" << endl;
	cout << "*************************************" << endl;
	
}
int main() {
	Addressbooks abs;
	abs.m_Size = 0;


	int select=0;
	while (true) {
		showMenu();
		cin >> select;
		switch (select) {
		case 1:
			addPerson(&abs);
			break;
		case 2:
			showPerson(&abs);
			break;
		case 3:
		/*{cout << "Please enter the name who you want to delete" << endl;
		string name;
		cin >> name;
		if (isExist(&abs, name) == -1) {
			cout << "Cannot find this person" << endl;
		}
		else {
			cout << "find this person" << endl;
		}}*/
			deletePerson(&abs);
			break;
		case 4:
			findPerson(&abs);
			break;
		case 5:
			modifyPerson(&abs);
			break;
		case 6:
			cleanPerson(&abs);
			break;
		case 0:
			cout << "Welcome to use next time" << endl;
			system("pause");
			return 0;
			break;

		}
	}
}
