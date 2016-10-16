#include <iostream>

class Date {
    public:
    enum DayOfWeek{MON, TUE, WED, THU, FRI, SAT, SUN};
    Date(int day, int month, int year, DayOfWeek dayOfWeek);
    void addDays(int numDays);
    int getMonth();
    int getDay();
    int getYear();
    DayOfWeek getDayOfWeek();
    int getDaysInThisMonth();
    private:
    DayOfWeek dayOfWeek;
    bool isLeapYear();
    int day, month,year;
};

bool Date::isLeapYear() {
    return (year % 400) == 0 || (year % 4 == 0 && year % 100 != 0);
}

int Date::getDaysInThisMonth() {
    int numDays[] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return numDays[month-1] + (month==2 && isLeapYear()) ? 1 : 0;
}

Date::Date(int day, int month, int year, DayOfWeek dayOfWeek) : day(day), month(month), year(year), dayOfWeek(dayOfWeek) {
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

int main() {
    Date d = Date(1,1,1901,Date::DayOfWeek::MON);
    int count = 0;
    while (d.getYear() <= 2000) {
        d.addDays(d.getDaysInThisMonth());
        if(d.getDayOfWeek() == Date::DayOfWeek::SUN) {
            count++;
        }
    }
    std::cout << count << std::endl;
    return 0;
}

