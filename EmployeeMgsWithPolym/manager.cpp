#include"manager.h"


Manager::Manager(int id, string name, int dId) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
	}

void Manager::showInfo() {
	cout << "Employee ID: " << this->m_Id
		<< "\tEmployee Name: " << this->m_Name
		<< "\tDepartment: " << this->getDeptName()
		<< "\tResponsibility: Complete tasks from boss and give tasks to employee" << endl;
	}

string Manager::getDeptName() {
	return string("manager");
	 }