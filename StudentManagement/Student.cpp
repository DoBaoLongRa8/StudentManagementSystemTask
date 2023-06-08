#include "Student.hpp"
#include <sstream>
using namespace studentSpace;
StudentClass::StudentClass(uint32_t id, std::string name, Time t, uint8_t age, vector<SubjectClass*> s, bool st)
	:studentID(id), studentName(name), dateOfBirth(t), age(age), subjectList(s), status(st){}

StudentClass::StudentClass(std::string name, Time t, vector<SubjectClass*> s , bool st)
	:StudentClass(autoNextID(), name, t, t.calculateAge(t.getYear()), s, st) {}

StudentClass::~StudentClass()
{
	for (auto s : subjectList)
		delete s;
}

void StudentClass::showStudentInfor() 
{
	cout << studentID << "\t" << studentName << "\t" << dateOfBirth.getDay() << "-" << dateOfBirth.getMonth() << "-"
		<< dateOfBirth.getYear() << "\t" << dateOfBirth.calculateAge(dateOfBirth.getYear()) << endl;
	cout << "--List of subjects:" << endl;
	if (subjectList.size() == 0)
	{
		return;
	}
	uint16_t index = 1;
	avgPoint = 0;
	for (auto s : subjectList)
	{
		cout << index++ << ". ";
		s->displaySubject();
		avgPoint += s->getSubjectPoint();
	}
	avgPoint /= subjectList.size();
	cout << "--Average point of the student: " << avgPoint << endl;
}

void StudentClass::inputStudentInfo()
{
	cout << "->Enter student name: ";
	getline(cin, studentName);

	cout << "->Entern date of birth(dd/mm/yyyy): ";
	string dateOB;
	getline(cin, dateOB);
	vector<string> dataList;
	string data;
	stringstream str(dateOB);
	while (getline(str, data, '/'))
	{
		dataList.push_back(data);
	}
	dateOfBirth.setDay(stoi(dataList[0]));
	dateOfBirth.setMonth(stoi(dataList[1]));
	dateOfBirth.setYear(stoi(dataList[2]));
	studentID = autoNextID();

	cout << "\t\t---->Enter the list of subjects students have registered<----" << endl;
	cout << "->Enter number of subjects students have registered: ";
	string nbOfSbStr;
	getline(cin, nbOfSbStr);
	uint16_t numberOfSb = (uint16_t)stoi(nbOfSbStr);
	for (int i = 1; i <= numberOfSb; i++)
	{
		cout << "---->Subject " << i << "<----" << endl;
		SubjectClass *s = new SubjectClass();
		s->inputSubject();
		subjectList.push_back(s);
	}
}
uint32_t StudentClass::nextID = 1;