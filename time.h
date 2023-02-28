#pragma once
#ifndef TIME_H
#define TIME_H

class Time {
	private:
		int hours;
		int minutes;
		int seconds;
	public:
		void setHours(int hours);
		void setMinutes(int minutes);
		void setSeconds(int seconds);
		int getHours() const;
		int getMinutes() const;
		int getSeconds() const;
		bool is_smaller_or_equal(const Time other_time) const;
		Time find_difference(const Time other_time) const;
		void print() const;
		Time();
		Time(int hours,int minutes,int seconds);
};

#endif // !TIME_H