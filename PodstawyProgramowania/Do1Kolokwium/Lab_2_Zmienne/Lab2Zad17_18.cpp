#include <iostream>
using namespace std;


enum WeekDay {Monday, Tuesday, Wednesday, Thursday, Friday, Saturday, Sunday}



bool leap_year(int year)     
{
     if((year%4==0 && year%100!=0) || year%400==0) 
     {
        return true;
     }
     else return false;

}






int main()
{

   





}


/*#include <iostream>

enum class Weekday {
    Monday,
    Tuesday,
    Wednesday,
    Thursday,
    Friday,
    Saturday,
    Sunday
};

bool isLeapYear(int year) {
    if (year % 4 != 0) {
        return false;
    } else if (year % 100 != 0) {
        return true;
    } else if (year % 400 != 0) {
        return false;
    } else {
        return true;
    }
}

Weekday dayOfWeek(int day, int month, int year) {
    const int monthCodes[] = {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};

    int yearLast2Digits = year % 100;
    int yearFirst2Digits = year / 100;
    int monthCode = monthCodes[month - 1];
    int centuryCode;

    if (yearFirst2Digits >= 16 && yearFirst2Digits <= 23) {
        centuryCode = yearFirst2Digits - 16;
    } else {
        std::cerr << "This program supports years between 1600 and 2299." << std::endl;
        exit(1);
    }

    int dayNumber = (yearLast2Digits + yearLast2Digits / 4 + monthCode + day + centuryCode + (isLeapYear(year) && (month == 1 || month == 2) ? -1 : 0)) % 7;

    return static_cast<Weekday>(dayNumber);
}

int main() {
    int day, month, year;
    std::cout << "Enter a date in the format dd.MM.yyyy: ";
    std::cin >> day;
    std::cin.ignore();  // Ignore the dot
    std::cin >> month;
    std::cin.ignore();  // Ignore the dot
    std::cin >> year;

    Weekday dayOfWeekResult = dayOfWeek(day, month, year);

    const char* weekdays[] = {"Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday", "Sunday"};
    std::cout << "The day of the week for " << day << "." << month << "." << year << " is " << weekdays[static_cast<int>(dayOfWeekResult)] << std::endl;

    return 0;
}
*/