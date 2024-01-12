#include "Cash.h"

Cash::Cash() :cash_value(0.0)
{
}

void Cash::set_payment()
{
    Payment::set_payment();
    cout << "ENTER CASH VALUE: ";
    cin >> cash_value;
}

void Cash::dispaly_payment()
{
    int width = 40; // Set the width of the box
    cout << "+" << setfill('-') << setw(width - 2) << "+" << endl;
    cout << "|" << setfill(' ') << setw(width - 2) << "|" << endl;
    cout << "| DATE: " << setw(width - 20) << paid_date.day << " \\" << paid_date.month << " \\" << paid_date.year << " |" << endl;
    cout << "| AMOUNT: " << setw(width - 13) << amount << " |" << endl;
    cout << "| CASH VALUE: " << setw(width - 17) << cash_value << " |" << endl;
    cout << "|" << setfill(' ') << setw(width - 2) << "|" << endl;
    cout << "+" << setfill('-') << setw(width - 2) << "+" << endl;
}

void Cash::update()
{
    int option;
    char c;
    while (true)
    {
        cout << "===========[EDIE CASH]=========" << endl;
        cout << "| 1. EDIT AMOUNT               |" << endl;
        cout << "| 2. EDIT ADDED DATE           |" << endl;
        cout << "| 3. EDIT  CASH VALUE          |" << endl;
        cout << "| 0. SAVE                      |" << endl;
        cout << "================================" << endl;

        cout << "Enter your option[ ]\b\b";
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "AMOUNT: " << amount << endl;
            cout << "NEW AMOUNT: ";
            cin >> amount;
            break;
        case 2:
            cout << "DATE: " << paid_date.day << " \\" << paid_date.month << " \\" << paid_date.year << " |" << endl;
            cout << "NEW DATE: ";
            cin >> paid_date.day >> c >> paid_date.month >> c >> paid_date.year;
            break;
        case 3:
            cout << "CASH VALUE: " << cash_value << endl;
            cout << "NEW CASH VALUE: ";
            cin >> cash_value;
            break;
        case 0:
            return;

        default:
            cout << "ENTER VALID OPTION" << endl;
        }

    }
}
