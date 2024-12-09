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
int calcDays (const Date &date1, const Date &date2)
{
    int daysDiff1 = 0; 
    int daysDiff2 = 0;
    int daysDiff3 = 0;
  
    int d1, m1, y1;
    d1 = date1.getDay(); 
    m1 = date1.getMonth(); 
    y1 = date1.getYear();
    int d2, m2, y2;
    d2 = date2.getDay(); 
    m2 = date2.getMonth(); 
    y2 = date2.getYear();

    // Calculate number of days between 01/01/2021 and date1
    for (int i = 2021; i < y1; i++) 
    {
        daysDiff1 += 365;
    }

    for (int i = 1; i < m1; i++) 
    {
        if (i == 2) 
        {
            daysDiff1 += 28;
        } 
            else if (i == 4 || i == 6 || i == 9 || i == 11) 
            {
                daysDiff1 += 30;
            } 
            else 
            {
                daysDiff1 += 31;
            }
        }

    daysDiff1 += d1 - 1;

    // Calculate number of days between 01/01/2021 and date2
    for (int i = 2021; i < y2; i++) 
    {
            daysDiff2 += 365;
    }

    for (int i = 1; i < m2; i++) {
        if (i == 2) 
        {
            daysDiff2 += 28;
        } 
        else if (i == 4 || i == 6 || i == 9 || i == 11) 
        {
            daysDiff2 += 30;
        } 
        else 
        {
            daysDiff2 += 31;
        }
        }

    daysDiff2 += d2 - 1;

    // Calculate number of days between daysDiff1 and daysDiff2
    daysDiff3 = abs(daysDiff2 - daysDiff1);

    return daysDiff3;
}
