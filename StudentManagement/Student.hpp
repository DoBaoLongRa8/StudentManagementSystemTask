#ifndef STUDENT_INCLUDE_HPP
#define STUDENT_INCLUDE_HPP
#include "UtilityFunction.hpp"
#include "Subject.hpp"
#include <string>
#include <vector>
using namespace subjectSpace;
using namespace std;
using namespace utilitySpace;

namespace studentSpace
{
	class StudentClass
	{
	private:
		uint32_t studentID;
		std::string studentName;
		Time dateOfBirth;
		uint8_t age;
		vector<SubjectClass*> subjectList;
		float avgPoint;
		bool status;
		static uint32_t nextID;
	public:
		uint32_t autoNextID()
		{
			return nextID++;
		}
		StudentClass() {}
		explicit StudentClass(uint32_t, std::string, Time, uint8_t, vector<SubjectClass*>, bool);
		explicit StudentClass(std::string, Time, vector<SubjectClass*>, bool);
		~StudentClass();
		void showStudentInfor();
		void inputStudentInfo();
		uint32_t getStudentID()
		{
			return studentID;
		}

		float getAvgPoint();

	};
}
#endif