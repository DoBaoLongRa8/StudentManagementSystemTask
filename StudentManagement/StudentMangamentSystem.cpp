#include "StudentManagementSystem.hpp"
#include <algorithm>
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
	cout << "In what order would you like to see the list of students sorted (0-Increasing ID/1-Decrease point)"
}