/* 
    The purpose of this program is to calculate the
    number of days an individual must quarintine 
    based upon given factors such as whether they
    tested positive, whether they have been exposed
    to COVID, when they have been exposed to COVID,
    if they had their second dose of the COVID
    vaccine, and how long it has been between
    their COVID vaccine and their exposure.
    Elise James
    Project 1
    2 February, 2023
*/

#include "Date.h"
#include "calcDays.h"

Date::Date()
{
    day = 1;
    month = 1;
    year = 2021;
}

Date::Date(int d, int m, int y) : day(d), month(m), year(y)
{
    if((setDay(d)) && (setMonth(m)) && (setYear(y)))
    {
        day = d;
        month = m;
        year = y;
    }
    else
    {
        Date();
        day = 1;
        month = 1;
        year = 2021;
    }
}

string Date::showDate() 
{
//Formats dates to MM/DD/YYYY format 
 string date, s1, s2, s3;

    s1 = to_string(getDay());
    s2 = to_string(getMonth());
    s3 = to_string(getYear());
    
    while(s1.length() < 2)
        s1 = "0" + s1;
     while(s2.length() < 2)
        s2 = "0" + s2;
     while(s3.length() < 4)
        s3 = "0" + s3;

    date = s2 + "/" + s1 + "/" + s3;

    return date;
}

bool Date::setDay(int d)
{
    int month;

    month = getMonth();
    
    if (month == 2)
    {
       if (d >= 0.0 && d <= 28) //checks if the int is greater than zero
        {
            day = d;
            return true;
        }

        else
        {
            return false;
        } 
    }

    if (month == 4 || month == 6 || month == 9 || month == 11)
    {
       if (d >= 0.0 && d <= 30) //checks if the int is greater than zero
        {
            day = d;
            return true;
        }

        else
        {
            return false;
        } 
    }

    if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month ==12)
        if (d >= 0.0 && d <= 31) //checks if the int is greater than zero
        {
            day = d;
            return true;
        }

        else
        {
            return false;
        }
    else
    {
        return false;
    }
}

bool Date::setMonth(int m)
{
    if (m >= 0.0 && m <= 12) //checks if the int is greater than zero
  {
    month = m;
  return true;
  }

  else
  {
    return false;
  }
}

bool Date::setYear(int y)
{
    if (y >= 2021.0 && y <= 2022.0 ) //checks if the year is between 2021 and 2022
  {
    year = y;
  return true;
  }

  else
  {
    return false;
  }
}

int Date::getDay() const
{
    return day;
}

int Date::getMonth() const
{
    return month;
}

int Date::getYear() const
{
    return year;
}