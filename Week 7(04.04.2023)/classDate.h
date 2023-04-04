#ifndef classDate.h
#define classDate.h


class Date{
	int second;
	int minute;
	int hour;
	int day;
	int month;
	int year;

	void copy(const Date& other);
public:
	//setters
	void setYear(int year);
	void setMonth(int month);
	void setDay(int day);
	void setHour(int hour);
	void setMinute(int minute);
	void setSecond(int second);

	bool isLeap();
	Date();
	Date(int second, int minute, int hour, int day, int month, int year);
	Date(const Date& other);
	Date& operator=(const Date& other);

	//move semantika
	Date(Date&& other);
	Date& operator=(Date&& other);



};

#endif