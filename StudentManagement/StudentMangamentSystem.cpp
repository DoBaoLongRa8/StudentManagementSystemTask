#include "StudentManagementSystem.hpp"
#include <algorithm>
#include <sstream>
using namespace studentManagementSpace;
StudentManagementClass::~StudentManagementClass()
{
	for (auto s : stdList)
	{
		delete s;
	}
}

bool StudentManagementClass::addStudent(StudentClass* s)
{
	StudentClass* sdt = findStudentByID(s->getStudentID());
	if (sdt != nullptr)
	{
		cout << "Student ID already exists" << endl;
		return false;
	}
	stdList.push_back(s);
	return true;
}

StudentClass* StudentManagementClass::findStudentByID(uint32_t id)
{
	vector<StudentClass*>::iterator it = find_if(stdList.begin(), stdList.end(), [=](StudentClass* s) {return s->getStudentID() == id; });
	if (it != stdList.end())
		return *it;
	return nullptr;
}

void StudentManagementClass::sortCommodities()
{
	switch (sortType) {
	case 0:
		sort(stdList.begin(), stdList.end(), [=](StudentClass* s1, StudentClass* s2) {
			return s1->getStudentID() < s2->getStudentID();
			});
		break;
	case 1:
		sort(stdList.begin(), stdList.end(), [=](StudentClass* s1, StudentClass* s2) {
			return s1->getAvgPoint() > s2->getAvgPoint();
			});
		break;
	}
}
void StudentManagementClass::sortCommoditiesByType(uint16_t type)
{
	if (type == sortType)
		return;
	sortType = type;
	sortCommodities();
}

void StudentManagementClass::viewAllCommodities()
{
	if (stdList.size() == 0)
		return;
	cout << "In what order would you like to see the list of students sorted (0-Increasing ID/1-Decrease point):";
}

bool StudentManagementClass::updateStudentInfoByID(uint32_t id)
{
	StudentClass* sdt = findStudentByID(id);
	if (sdt == nullptr)
	{
		cout << "There is no student with student id: " << id << endl;
		return false;
	}

	if (sdt->getStatus() == true)
	{
		cout << ">>Student information cannot be updated while the student is active.<<" << endl;
		return false;
	}

	cout << "\t\t------>Update student information<------" << endl;
	cout << "\t->1. Update student ID<-" << endl;
	cout << "\t->2. Update student name<-" << endl;
	cout << "\t->3. Update student date of birth<-" << endl;
	cout << "\t->0. Exit<-" << endl;
	bool flag = true;
	string sChoice;
	while (true)
	{
		flag = true;
		cout << "-->Enter your choice (1/2/3): ";
		getline(cin, sChoice);

		if (sChoice == "0")
		{
			return true;
		}
		else if (sChoice == "1")
		{
			string stdID;
			cout << "-->Enter the new student ID: ";
			getline(cin, stdID);
			sdt->setStudentID((uint32_t)stoi(stdID));
			cout << "-->Update successful<--" << endl;
		}
		else if (sChoice == "2")
		{
			string name;
			cout << "-->Enter the student's new name: ";
			getline(cin, name);
			sdt->setStudentName(name);
			cout << "-->Update successful<--" << endl;
		}
		else if (sChoice == "3")
		{
			string dateOfBirth;
			cout << "-->Enter the student's new date of birth(dd/mm/yyyy): ";
			getline(cin, dateOfBirth);

			vector<string> dataList;
			string data;
			stringstream str(dateOfBirth);
			while (getline(str, data, '/'))
			{
				dataList.push_back(data);
			}
			sdt->setDateOfBirth(stoi(dataList[0]), stoi(dataList[1]), stoi(dataList[2]));
			cout << "-->Update successful<--" << endl;
		}
		else
		{
			cout << ">>Your selection is not valid. Please try again.<<" << endl;
			flag = false;
		}

		if (flag == true)
		{
			cout << "-->Do you want to continue to update information ? (1. Yes): ";
			string choice2;
			getline(cin, choice2);
			if (choice2 != "1")
			{
				return true;
			}
		}
		
	}
}

bool StudentManagementClass::setStudentStatusByID(uint32_t id, bool stat)
{
	StudentClass* sdt = findStudentByID(id);
	if (sdt == nullptr)
	{
		cout << "-->There is no student with student id: " << id << "<--" << endl;
		return false;
	}

	sdt->setStudentStatus(stat);
}