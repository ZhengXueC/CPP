#include"boss.h"


Boss::Boss(int id, string name, int dId) {
	this->m_Id = id;
	this->m_Name = name;
	this->m_DeptId = dId;
}

void Boss::showInfo() {
	cout << "Employee ID: " << this->m_Id
		<< "\tEmployee Name: " << this->m_Name
		<< "\tDepartment: " << this->getDeptName()
		<< "\tResponsibility: Manage all tasks in the company" << endl;
}

string Boss::getDeptName() {
	return string("boss");
}
