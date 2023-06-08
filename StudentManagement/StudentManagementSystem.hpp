#ifndef STUDENT_MANAGEMENT_SYSTEM_INCLUDE_HPP
#define STUDENT_MANAGEMENT_SYSTEM_INCLUDE_HPP
#include "Student.hpp"
#include <vector>
using namespace std;
using namespace studentSpace;
namespace studentManagementSpace
{
	class StudentManagementClass
	{
	private:
		vector<StudentClass*> stdList;
	public:
		StudentManagementClass() = default;
		~StudentManagementClass();
		StudentManagementClass(const StudentManagementClass& s) = delete;
		StudentManagementClass& operator=(const StudentManagementClass& s) = delete;
		bool addStudent(StudentClass* s);
		StudentClass* findStudentByID(uint32_t id);
		uint16_t sortType = 0;
		void sortCommodities();
		void sortCommoditiesByType(uint16_t type);
		void viewAllCommodities();
	};
}
#endif
