#ifndef YESNOQUESTION_H
#define YESNOQUESTION_H

#include "Question.h"
class YesNoQuestion:public Question{
	int currentGrade;
	bool correctAnswer;

public:
	YesNoQuestion(const char* question, int maxGrade, bool answer);

};

#endif

