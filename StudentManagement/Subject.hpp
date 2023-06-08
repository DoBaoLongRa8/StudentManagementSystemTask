#ifndef SUBJECT_INCLUDE_HPP
#define SUBJECT_INCLUDE_HPP
#include <iostream>
#include <string>
using namespace std;

namespace subjectSpace
{
	class SubjectClass
	{
	private:
		string subjectCode;
		string subjectName;
		float subjectPoint;

	public:
		SubjectClass() {}
		explicit SubjectClass(string code, string name, float point);
		void displaySubject() const;
		void inputSubject();
		void setSubjectCode(string code)
		{
			this->subjectCode = code;
		}
		void setSubjectName(string name)
		{
			this->subjectName = name;
		}

		void setSubjectPoint(float point)
		{
			this->subjectPoint = point;
		}

		string getSubjectCode() const
		{
			return this->subjectCode;
		}

		string getSubjectName() const
		{
			return this->subjectName;
		}

		float getSubjectPoint() const
		{
			return this->subjectPoint;
		}

	};
}
#endif