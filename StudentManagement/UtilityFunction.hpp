#ifndef UTILITY_FUNCTION_INCLUDE_HPP
#define UTILITY_FUNCTION_INCLUDE_HPP
#include <cstdint>
namespace utilitySpace
{
	const uint16_t currentYear = 2023;
	class Time
	{
	private:
		uint16_t day;
		uint16_t month;
		uint16_t year;
	public:
		Time(){}
		explicit Time(uint16_t, uint16_t, uint16_t);
			uint16_t calculateAge(uint16_t birthYear);
			uint16_t getDay() 
			{
				return this->day;
			}

			uint16_t getMonth() 
			{
				return this->month;
			}

			uint16_t getYear() 
			{
				return this->year;
			}

			void setDay(uint16_t d)
			{
				this->day = d;
			}

			void setMonth(uint16_t m)
			{
				this->month = m;
			}

			void setYear(uint16_t y)
			{
				this->year = y;
			}
	};
}
#endif