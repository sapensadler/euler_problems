#include <iostream>
#include "Date.h"

/**
  * Calculates the number of Sundays fell on the first of the month in the 20th Century
  */

int main() {
    Date d = Date(1,1,1901,Date::DayOfWeek::MON);
    int count = 0;
    // From 1/1/1901 Monday, add 1 month's worth of days to get to the first
    // each month and count each sunday until the year 2000
    while (d.getYear() <= 2000) {
        d.addDays(d.getDaysInThisMonth());
        if(d.getDayOfWeek() == Date::DayOfWeek::SUN) {
            count++;
        }
    }
    std::cout << count << std::endl;
    return 0;
}

