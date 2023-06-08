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

		float getAvgPoint()
		{
			return this->avgPoint;
		}

		bool getStatus() const
		{
			return this->status;
		}

		void setStudentID(uint32_t id)
		{
			this->studentID = id;
		}

		void setStudentName(string name)
		{
			this->studentName = name;
		}

		void setDateOfBirth(uint16_t day, uint16_t month, uint16_t year)
		{
			this->dateOfBirth.setDay(day);
			this->dateOfBirth.setMonth(month);
			this->dateOfBirth.setYear(year);
		}

		void setStudentStatus(bool stat)
		{
			this->status = stat;
		}
	};
}
#endif