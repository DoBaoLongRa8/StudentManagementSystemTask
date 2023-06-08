#include "Subject.hpp"
#include "Student.hpp"
#include "StudentManagementSystem.hpp"
using namespace studentSpace;
using namespace subjectSpace;
using namespace studentManagementSpace;
int main()
{
	StudentManagementClass stdManagement;
	StudentClass* std = new StudentClass();
	std->inputStudentInfo();
	std->showStudentInfor();
	stdManagement.addStudent(std);
	stdManagement.updateStudentInfoByID(std->getStudentID());
	std->showStudentInfor();
	return 0;
}