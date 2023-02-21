// OOPPraktikuk01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <cstring>
using namespace std;

int main()
{
	struct Time {
		int second;
		int minute;
		int hour;
		Time get_diff(const Time other_time) const { // za dovurshvane
			Time temp;
			if (hour >= other_time.hour) {
				temp.hour = hour - other_time.hour;
				if (minute >= other_time.minute) {
					temp.minute = minute - other_time.minute;
					if (second >= other_time.second) {
						temp.second = second - other_time.second;
					}else if (second < other_time.second) {
						temp.minute--;
						temp.second = second - other_time.second + 60;
					}
				}
				else if (minute < other_time.minute) {
					temp.hour--;
					temp.minute = minute - other_time.minute + 60;
					if (minute > other_time.minute) {
						temp.minute = minute - other_time.minute;
						if (second > other_time.second) {
							temp.second = second - other_time.second;
						}
					}

				}
				
			}
			else if (hour < other_time.hour) {
				temp.hour = other_time.hour-hour;
			}

			return temp;
		};
		void print() {
			cout << hour << ":" << minute << ":" << second;
		};
	};
	
	}
	struct Event {
		char title[128];
		char organizer[128];
		Time start_time;
		Time end_time;
		Time get_duration();

	};

	Event e1;
	cin.getline(e1.title, 128);
	cin.getline(e1.organizer, 128);
	cin >> e1.start_time.second;
	cin >> e1.start_time.minute;
	cin >> e1.start_time.hour;
	cin >> e1.end_time.second;
	cin >> e1.end_time.minute;
	cin >> e1.end_time.hour;



	struct Student {
		char name[128];
		char surname[128];
		char EGN[128];
		

	};
	struct University {
		char name[128];
		Student students[128];
		bool hasStudent(const Student s1) {
			for (int i = 0; i < sizeof(students); i++) {
				if (students[i].name == s1.name && students[i].surname == s1.surname) {
					return true;
				}
			}
			return false;
		};
		void addStudent(const Student s1) {
			if (!hasStudent(s1)) {
				//za dovurshvane
			}
		};
	};


}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
