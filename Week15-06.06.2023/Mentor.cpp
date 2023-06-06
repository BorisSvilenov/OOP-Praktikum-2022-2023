#include "Mentor.h"

double Mentor::get_annual_raise_multiplier()
{
    double result = mentorRaisePercentage;
    int temp = mentorExperience;
    while (temp > 0) {
        result += 0.05 * interns.size();
        temp--;
    }
    return result;
}
