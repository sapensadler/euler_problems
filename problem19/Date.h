#ifndef DATE_CLASS
#define DATE_CLASS

// Date class to calculate the day of week for a specific date
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

#endif

