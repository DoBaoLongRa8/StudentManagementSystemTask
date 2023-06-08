#include "UtilityFunction.hpp"
using namespace utilitySpace;
uint16_t Time::calculateAge(uint16_t birthYear)
{
	return currentYear - birthYear;
}
Time::Time(uint16_t d, uint16_t m, uint16_t y): day(d), month(m), year(y){}