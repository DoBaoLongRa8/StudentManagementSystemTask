#include "Subject.hpp"
using namespace subjectSpace;
SubjectClass::SubjectClass(string code, string name, float point) : subjectCode(code), subjectName(name), subjectPoint(point){}
void SubjectClass::displaySubject() const
{
	cout << subjectCode << " - " << subjectName << " - " << subjectPoint << endl;
}

void SubjectClass::inputSubject()
{
	cin.ignore();
	cout << "Enter the course code: ";
	getline(cin, subjectCode);
	cout << "Enter subject name: ";
	getline(cin, subjectName);
	cout << "Enter subject point: ";
	cin >> subjectPoint;
}