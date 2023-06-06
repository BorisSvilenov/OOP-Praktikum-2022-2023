#include "Intern.h"

double Intern::get_annual_raise_multiplier()
{   
    double result = internRaisePercentage;
    int temp = internExperience;
    while (temp > 0) {
        result += 0.05;
        temp -= 12;
    }
    return result;
}

