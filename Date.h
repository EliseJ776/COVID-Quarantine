#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>
using namespace std;
#ifndef DATE_H_
#define DATE_H_

class Date
{
    private:
    int day = 1;
    int month = 1;
    int year = 2021;

    public:
    Date();
    Date(int d, int m, int y);
    bool setDay(int d);
    bool setMonth(int m);
    bool setYear(int y);
    int getDay() const;
    int getMonth() const;
    int getYear() const;
    string showDate();
};

#endif