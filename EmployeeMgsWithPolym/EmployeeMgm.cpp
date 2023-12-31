#include<iostream>
using namespace std;
#include "workerManager.h"

#include"worker.h"
#include"employee.h"
#include"manager.h"
#include"boss.h"
int main() {

	Worker* worker = NULL;
	worker = new Employee(1, "tom", 1);
	worker->showInfo();
	delete worker;

	worker = new Manager(2, "Mary", 2);
	worker->showInfo();
	delete worker;

	worker = new Boss(3, "Jhon", 3);
	worker->showInfo();
	delete worker;



	WorkerManager wm;

	int choice = 0;
	while (true) {
		wm.Show_Menu();
		cout << "Please enter your choice: " << endl;
		cin >> choice;
		switch (choice) {
		case 0:
			wm.ExitSystem();
			break;
		case 1:
			wm.Add_Emp();
			break;
		case 2:
			wm.Show_Emp();
			break;
		case 3:
			wm.Del_Emp();
			break;
		case 4:
			wm.Mod_Emp();
			break;
		case 5:
			wm.Find_Emp();
			break;
		case 6:
			wm.Sort_Emp();
			break;
		
		case 7:
			wm.Clean_File();
			break;
		default:
			system("cls");
			break;
		}
	}
	
	system("pause");
	return 0;
}