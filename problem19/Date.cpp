
#include "Date.h"

bool Date::isLeapYear() {
    return (year % 400) == 0 || (year % 4 == 0 && year % 100 != 0);
}

int Date::getDaysInThisMonth() {
    int numDays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return numDays[month-1] + (month==2 && isLeapYear()) ? 1 : 0;
}

Date::Date(int day, int month, int year, DayOfWeek dayOfWeek) : dayOfWeek(dayOfWeek), day(day),
                                                                 month(month), year(year) {
}

int Date::getDay() {
    return day;
}

int Date::getMonth() {
    return month;
}

int Date::getYear() {
    return year;
}

Date::DayOfWeek Date::getDayOfWeek() {
    return dayOfWeek;
}

void Date::addDays(int days) {
    this->day += days;
    while ( this->day > getDaysInThisMonth()) {
        this->day -= getDaysInThisMonth();
        month++;
        if(month==13) {
            year++;
            month = 1;
        }
    }
    dayOfWeek = (Date::DayOfWeek)((dayOfWeek + days) % 7);
}

