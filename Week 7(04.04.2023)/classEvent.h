

#ifndef classEvent.h
#define classEvent.h

#include "classDate.h"
const int MAX_SIZE = 100;

class Event {

	char* name;
	char description[MAX_SIZE];
	Date start;
	Date end;

	void free();
	void copy(const Event& other);

public:
	~Event();
	Event(const Event& other);
	Event(const char* name, const char description[MAX_SIZE], Date start, Date end);
	Event();
	Event& operator=(const Event& other);


	//move semantika
	Event(Event&& other);
	Event& operator=(Event&& other);



};


#endif
