#ifndef QUESTION_H
#define QUESTION_H
class Question{
	char* question;
	int maxGrade;

	virtual void ask()=0;
	virtual void grade()=0;
	virtual ~Question();
	
};
#endif

