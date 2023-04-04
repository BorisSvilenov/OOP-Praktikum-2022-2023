#include "classDate.h"

bool Date::isLeap() {
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0) return true;
			else return false;
		}
		return true;
	}
	else
	{
		return false;
	}
}
void Date::setYear(int year) {
	this->year = year;
}
void Date::setMonth(int month) {
	if (month >= 1 && month <= 12) {
		this->month = month;
		return;
	}
	this->month = 1;
}
void Date::setDay(int day) {
	if (month == 2){
		if (isLeap()) {
			if (day >= 1 && day <= 29) {
				this->day=day;
			}
		}
	}
	else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12) {
		if (day >= 1 && day <= 31){
			this->day = day;
		}
	}
	else if (day >= 1 && day <= 30) {
		this->day = day;
	}
	
}
void Date::setHour(int hour) {
	if (hour >= 0 && hour <= 23) {
		this->hour = hour;
	}
}
void Date::setMinute(int minute) {
	if (minute >= 0 && minute <= 59) {
		this->minute = minute;
	}
}
void Date::setSecond(int second) {
	if (second >= 0 && second <= 59) {
		this->second = second;
	}
}

void Date::copy(const Date& other) {
	setYear(other.year);
	setMonth(other.month);
	setDay(other.day);
	setHour(other.hour);
	setMinute(other.minute);
	setSecond(other.second);

}
Date::Date() {
	setYear(0);
	setMonth(1);
	setDay(1);
	setHour(0);
	setMinute(0);
	setSecond(0);
}
Date::Date(int second,int minute,int hour,int day,int month,int year) {
	setYear(year);
	setMonth(month);
	setDay(day);
	setHour(hour);
	setMinute(minute);
	setSecond(second);
}

Date::Date(const Date& other) {
	copy(other);
}
Date& Date::operator=(const Date& other) {
	if (this != &other) {
		copy(other);
	}
	return *this;
}
Date::Date(Date&& other) {
	copy(other);

	other = Date();
}
Date& Date::operator=(Date&& other) {
	copy(other);

	other = Date();
}