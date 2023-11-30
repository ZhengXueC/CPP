# include "workerManager.h"

WorkerManager::WorkerManager() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	if (!ifs.is_open()) {
		cout << "file is not exist" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	char ch;
	ifs >> ch;
	if (ifs.eof()) {
		cout << "file is empty" << endl;
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	int num = this->get_EmpNum();
	cout << "employee number is: " << num << endl;
	this->m_EmpNum = num;
	
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	this->init_Emp();

	for (int i = 0;i < this->m_EmpNum;i++) {
		cout << "employee id: " << this->m_EmpArray[i]->m_Id
			<< " name: " << this->m_EmpArray[i]->m_Name
			<< " Department Id: " << this->m_EmpArray[i]->m_DeptId << endl;
	}
}
void WorkerManager::Show_Menu() {
	cout << "*******************************************************" << endl;
	cout << "******  Welcome to Employee Management System    ******" << endl;
	cout << "************  0.Exit System    ************************" << endl;
	cout << "************  1.Add Employee Information  *************" << endl;
	cout << "************  2.Show Employee Information  ************" << endl;
	cout << "************  3.Delete Resigned Employee  *************" << endl;
	cout << "************  4.Edit Employee Information  ************" << endl;
	cout << "************  5.Search Employee Information  **********" << endl;
	cout << "************  6.Sort by ID  ***************************" << endl;
	cout << "************  7.Delete All Data  **********************" << endl;
	cout << "*******************************************************" << endl;
	cout << endl;
}
void WorkerManager::ExitSystem() {
	cout << "Thank you for using the system" << endl;
	system("pause");
	exit(0);
}
void WorkerManager::Add_Emp() {
	cout << "Please enter number of employee" << endl;
	int addNum = 0;
	cin >> addNum;
	if (addNum > 0) {
		int newSize = this->m_EmpNum + addNum;
		Worker** newSpace = new Worker * [newSize];
		if (this->m_EmpArray != NULL) {
			for (int i = 0;i < this->m_EmpNum;i++) {
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		for (int i = 0;i < addNum;i++) {
			int id;
			string name;
			int dSelect;
			cout << "Please enter NO." << i + 1 << " new employee id: " << endl;
			cin >> id;
			cout << "Please enter NO." << i + 1 << " new employee name: " << endl;
			cin >> name;
			cout << "Please choose the employee Department: " << endl;
			cout << "1, employee" << endl;
			cout << "2, manager" << endl;
			cout << "3, boss" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			switch (dSelect) {
			case 1:
				worker = new Employee(id, name, 1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			newSpace[this->m_EmpNum + i] = worker;
		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = newSpace;
		this->m_EmpNum = newSize;

		this->m_FileIsEmpty = false;

		cout << "Successfully added " << addNum << " new employee" << endl;

		this->save();
	}
	else {
		cout << "data error" << endl;
	}
	system("pause");
	system("cls");
}
void WorkerManager::save() {
	ofstream ofs;
	ofs.open(FILENAME, ios::out);

	for (int i = 0;i < this->m_EmpNum;i++) {
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;

	}
	ofs.close();

}

void WorkerManager::init_Emp() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;
	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) {
		Worker* worker = NULL;
		if (dId == 1) {
			worker = new Employee(id, name, dId);
		}
		else if (dId == 2) {
			worker = new Manager(id, name, dId);
		}
		else {
			worker = new Boss(id, name, dId);
		}
		this->m_EmpArray[index] = worker;
		index++;
	}
	ifs.close();
}
int WorkerManager::get_EmpNum() {
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;
	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> dId) {
		num++;
	}
	return num;
}
void WorkerManager::Show_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "file is not exist or no record" << endl;
	}
	else {
		for (int i = 0;i < m_EmpNum;i++) {
			this->m_EmpArray[i]->showInfo();
		}
	}
	system("pause");
	system("cls");
}

void WorkerManager::Del_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "file not exist or no record" << endl;
	}
	else {
		cout << "please enter the id: " << endl;
		int id = 0;
		cin >> id;
		int index = this->IsExist(id);
		if (index != -1) {
			for (int i = index;i < this->m_EmpNum - 1;i++) {
				this->m_EmpArray[i] = this->m_EmpArray[i + 1];
			}
			this->m_EmpNum--;
			this->save();
			cout << "delete successfully" << endl;
		}
		else {
			cout << "fail to delete, cannot find the employee" << endl;
		}
	}
	system("pause");
	system("cls");
}
int WorkerManager::IsExist(int id) {
	int index = -1;
	for (int i = 0;i < this->m_EmpNum;i++) {
		if (this->m_EmpArray[i]->m_Id == id) {
			index = i;
			break;
		}
	}
	return index;
}
void WorkerManager::Mod_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "file not exist or no record" << endl;
	}
	else {
		cout << "please enter the modify employee id: " << endl;
		int id;
		cin >> id;
		int ret=this->IsExist(id);
		if (ret != -1) {
			delete this->m_EmpArray[ret];
			int newId = 0;
			string newName = "";
			int dSelect = 0;
			cout << "found: " << id << " employee, please new employee id: " << endl;
			cin >> newId;
			cout << "Please enter new name: " << endl;
			cin >> newName;
			cout << "Please enter new Department:" << endl;
			cout << "1, employee" << endl;
			cout << "2, manager" << endl;
			cout << "3, boss" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			switch (dSelect) {
			case 1:
				worker = new Employee(newId, newName, dSelect);
				break;
			case 2:
				worker = new Manager(newId, newName, dSelect);
				break;
			case 3:
				worker = new Boss(newId, newName, dSelect);
				break;
			default:
				break;
			}
			this->m_EmpArray[ret] = worker;
			cout << "Successfully Modified" << endl;
			this->save();
		}
		else {
			cout << "fail to modify, cannot find the id" << endl;
		}
		system("pause");
		system("cls");

	}
}
void WorkerManager::Find_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "file not exist or no record" << endl;
	}
	else {
		cout << "Please enter the method" << endl;
		cout << "1, find by id " << endl;
		cout << "2, find by name " << endl;
		int select = 0;
		cin >> select;
		if (select == 1) {
			int id;
			cout << "Please enter the id: " << endl;
			cin >> id;
			int ret = IsExist(id);
			if (ret != -1) {
				cout << "Found successfully, employee info as following: " << endl;
				this->m_EmpArray[ret]->showInfo();
			}
			else {
				cout << "cannot find this person" << endl;
			}
		}
		else if (select == 2) {
			string name;
			cout << "please enter the name:" << endl;
			cin >> name;
			bool flag = false;
			for (int i = 0;i < m_EmpNum;i++) {
				if (this->m_EmpArray[i]->m_Name == name) {
					cout << "Found successfully and employee id is: " << this->m_EmpArray[i]->m_Id << " the employee info as following:" << endl;
					this->m_EmpArray[i]->showInfo();
					flag = true;
				}
			}
			if (flag == false) {
				cout << "cannot find this person" << endl;
			}
		}
		else {
			cout << "wrong entered number!!" << endl;
		}
	}
	system("pause");
	system("cls");
}
void WorkerManager::Sort_Emp() {
	if (this->m_FileIsEmpty) {
		cout << "file not exist or no record" << endl;
		system("pause");
		system("cls");
	}
	else {
		cout << "Please select sort by: " << endl;
		cout << "1, sort in ascending order by id" << endl;
		cout << "2, sort in descending order by id" << endl;
		int select = 0;
		cin >> select;
		for (int i = 0;i < m_EmpNum;i++) {
			int minOrMax = i;
			for (int j = i + 1;j < this->m_EmpNum;j++) {
				if (select == 1) {
					if (this->m_EmpArray[minOrMax]->m_Id > this->m_EmpArray[j]->m_Id) {
						minOrMax = j;
					}
					
				}
				else {
					if (this->m_EmpArray[minOrMax]->m_Id < this->m_EmpArray[j]->m_Id) {
						minOrMax = j;
					}
				}
			}
			if (i != minOrMax) {
				Worker* temp = this->m_EmpArray[i];
				this->m_EmpArray[i] = this->m_EmpArray[minOrMax];
				this->m_EmpArray[minOrMax] = temp;
			}
		}
		cout << "sort successfully" << endl;
		this->save();
		this->Show_Emp();
	}
}
void WorkerManager::Clean_File() {
	cout << "Are you sure to clean all data?" << endl;
	cout << "1, confirm" << endl;
	cout << "2, return" << endl;
	int select = 0;
	cin >> select;
	if (select == 1) {
		ofstream ofs(FILENAME, ios::trunc);
		ofs.close();
		if (this->m_EmpArray != NULL) {
			for (int i = 0;i < this->m_EmpNum;i++) {
				
					delete this->m_EmpArray[i];
					this->m_EmpArray[i] != NULL;
				}
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "clean successfully" << endl;
	}
	system("pause");
	system("cls");
}
WorkerManager::~WorkerManager() {
	if (this->m_EmpArray != NULL) {
		for (int i = 0;i < this->m_EmpNum;i++) {
			if (this->m_EmpArray[i] != NULL) {
				delete this->m_EmpArray[i];
			}
		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}