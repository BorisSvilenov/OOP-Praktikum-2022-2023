#pragma once

#ifndef EVENT_H
#define EVENT_H
#include "time.h" 

const int MAX_LENGTH = 128;
class Event {
private:
	char title[MAX_LENGTH];
	char organizer[MAX_LENGTH];
	Time start_time;
	Time end_time;
public:
	Time get_duration() const;
	Event();
	Event(char title[MAX_LENGTH], char organizer[MAX_LENGTH], Time start_time, Time end_time);
	Event(char title[MAX_LENGTH], char organizer[MAX_LENGTH], int start_time_seconds, int start_time_minutes, int start_time_hours, int end_time_seconds, int end_time_minutes, int end_time_hours);
	bool isDiff(const Event event)const;
};

#endif // !EVENT_H