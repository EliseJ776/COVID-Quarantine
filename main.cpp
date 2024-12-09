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

int main()
{
    char testResult;
    string printedDate;
    int dayPositive;
    int monthPositive;
    int yearPositive;
    int dayExposed;
    int monthExposed;
    int yearExposed;
    int dayVac;
    int monthVac;
    int yearVac;

    //Asks the user if they have been exposed to COVID
    cout << "Have you tested positive for COVID-19?";
    cout << "\nEnter y for yes and n for no: ";
    cin >> testResult;

    if (testResult == 'y')
    {
        Date datePositive;

        //If the user has COVID, they will be asked
        //when and their dates validated
        cout << "Day tested positive: ";
        cin >> dayPositive;
        cout << "Month tested positive: ";
        cin >> monthPositive;
        cout << "Year tested positive: ";
        cin >> yearPositive;

        datePositive.setMonth(monthPositive);
        datePositive.setDay(dayPositive);
        datePositive.setYear(yearPositive);

        cout << "Test result: positive\n"; 
        cout << "Date tested positive: ";
        printedDate = datePositive.showDate();
        cout << printedDate << endl;
        cout << "Length of isolation: 5 days";
    }

    if (testResult == 'n')
    {
        char exposure;
        
        //Askes if user was exposed to COVID
        cout << "Were you exposed to a positive case? ";
        cin >> exposure;

        if (exposure == 'n')
        {
            cout << "Test result: negative\n";
            cout << "Exposed to positive case: No\n";
            cout << "Length of isolation: 0 days";
        }
        
        if (exposure == 'y')
        {
            Date dateExposed;

            //Asks the user when they were exposed
            //and validates the answer
            cout << "Day exposed: ";
            cin >> dayExposed;
            cout << "Month exposed: ";
            cin >> monthExposed;
            cout << "Year exposed: ";
            cin >> yearExposed;

            dateExposed.setMonth(monthExposed);
            dateExposed.setDay(dayExposed);
            dateExposed.setYear(yearExposed);

            char vaccination;

            //Asks the user if they received their second vaccination
            cout << "Have you received your second vaccination? ";
            cin >> vaccination;

            if (vaccination == 'n')
            {
                cout << "Test result: negative\n";
                cout << "Exposed to positive case: Yes\n";
                cout << "Date exposed to positive case: ";
                printedDate = dateExposed.showDate();
                cout << printedDate << endl;
                cout << "Second vaccination does received: No\n";
                cout << "Vaccination status at time of exposure: not fully vaccinated\n";
                cout << "Length of isolation: 10 days";
            }
            if (vaccination == 'y')
            {
                Date dateSecondDose;

                //If the user received their second vaccination,
                //they will be asked when and their answer validated
                cout << "When did you receive your second dose?\n";
                cout << "Day vaccinated: ";
                cin >> dayVac;
                cout << "Month vaccinated: ";
                cin >> monthVac;
                cout << "Year vaccinated: ";
                cin >> yearVac;

                dateSecondDose.setMonth(monthVac);
                dateSecondDose.setDay(dayVac);
                dateSecondDose.setYear(yearVac);

                int diff;
                //Difference between second dose and the date the user
                //was exposed is calculated
                diff = calcDays(dateSecondDose, dateExposed); 

                if (diff <= 14)
                {
                    cout << "Test result: negative\n";
                    cout << "Exposed to positive case: Yes\n";
                    cout << "Date exposed to positive case: ";
                    printedDate = dateExposed.showDate();
                    cout << printedDate << endl;
                    cout << "Second vaccination does received: Yes\n";
                    cout << "Date second vaccination dose received: ";
                    printedDate = dateSecondDose.showDate();
                    cout << printedDate << endl;
                    cout << "Vaccination status at time of exposure: not fully vaccinated\n";
                    cout << "Length of isolation: 10 days";
                }
                if (diff >= 14)
                {
                    cout << "Test result: negative\n";
                    cout << "Exposed to positive case: Yes\n";
                    cout << "Date exposed to positive case: ";
                    printedDate = dateExposed.showDate();
                    cout << printedDate << endl;
                    cout << "Second vaccination does received: Yes\n";
                    cout << "Date second vaccination dose received: ";
                    printedDate = dateSecondDose.showDate();
                    cout << printedDate << endl;
                    cout << "Vaccination status at time of exposure: fully vaccinated\n";
                    cout << "Length of isolation: 5 days\n";
                }
            }
        }
    }

    return 0;
}