

#include <iostream>
#include <cstring>
#include "time.h"
#include "event.h"

const int MAX_LENGTH = 128;

int Time::getSeconds() const{
    return this->seconds;
}
int Time::getMinutes() const{
    return this->minutes;
}
int Time::getHours() const {
    return this->minutes;
}
void Time::setSeconds(int seconds) {
    if (seconds >= 0 && seconds <= 59) {
        this->seconds = seconds;
    }
    else this->seconds = 0;
}
void Time::setMinutes(int minutes) {
    if (minutes >= 0 && minutes <= 59) {
        this->minutes = minutes;
    }
    else this->minutes = 0;
}
void Time::setHours(int hours) {
    if (hours >= 0 && hours <= 23) {
        this->hours = hours;
    }
    else this->hours = 0;
}
bool Time::is_smaller_or_equal(const Time other_time) const{
    return hours < other_time.hours
        || (hours == other_time.hours
            && (minutes < other_time.minutes
                || (minutes == other_time.minutes
                    && seconds <= other_time.seconds)
                )
            );

}
Time Time::find_difference(const Time other_time) const {
    if (!this->is_smaller_or_equal(other_time)) {
        return other_time.find_difference(*this);
    }

    Time result;
    result.hours = other_time.hours - hours;
    result.minutes = other_time.minutes - minutes;
    result.seconds = other_time.seconds - seconds;
    return result;
}
void Time::print() const {
    std::cout << "Hours: " << hours << std::endl
        << "Minutes: " << minutes << std::endl
        << "Seconds: " << seconds << std::endl;
}
Time::Time() {
    this->seconds = 0;
    this->minutes = 0;
    this->hours = 0;
}
Time::Time(int hours,int minutes,int seconds) {
    setHours(hours);
    setMinutes(minutes);
    setSeconds(seconds);
}

Time Event::get_duration() const {
    return start_time.find_difference(end_time);
}
Event::Event() {
    strcpy(title, "");
    strcpy(organizer, "");
    start_time = Time();
    end_time = Time();
}
Event::Event(char title1[MAX_LENGTH], char organizer1[MAX_LENGTH], Time start_time1, Time end_time1) {
    strcpy(title, title1);
    strcpy(organizer, organizer1);
    start_time = start_time1;
    end_time = end_time1;
}
Event::Event(char title1[MAX_LENGTH], char organizer1[MAX_LENGTH], int start_time_seconds, int start_time_minutes,
int start_time_hours, int end_time_seconds, int end_time_minutes, int end_time_hours) {
    strcpy(title, title1);
    strcpy(organizer, organizer1);
    start_time.setSeconds(start_time_seconds);
    start_time.setMinutes(start_time_minutes);
    start_time.setHours(start_time_hours);
    end_time.setSeconds(end_time_seconds);
    end_time.setMinutes(end_time_minutes);
    end_time.setHours(end_time_hours);
}
bool Event::isDiff(const Event event1) const {
    //some code
}
int main()
{
    std::cout << "Hello World!\n";
}


