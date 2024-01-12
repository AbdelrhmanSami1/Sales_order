#include "Credit.h"

Credit::Credit() :number("unnown"), expire_date(0, 0, 0), type("unnown")
{
}

void Credit::set_payment()
{
    char c;
    Payment::set_payment();
    cout << "ENTER CREDIT NUMBER: ";
    cin.ignore();
    getline(cin, number);

    cout << "ENTER CREDIT EXPIRE DATE[DD/MM/Y]: " << endl;
    cin >> expire_date.day >> c >> expire_date.month >> c >> expire_date.year;

    cout << "ENTER CREDIT TYPE: ";
    cin.ignore();
    getline(cin, type);
}

void Credit::dispaly_payment()
{
    int width = 40; // Set the width of the box
    cout << "+" << setfill('-') << setw(width - 2) << "+" << endl;
    cout << "|" << setfill(' ') << setw(width - 2) << "|" << endl;
    cout << "| DATE: " << setw(width - 20) << paid_date.day << " \\" << paid_date.month << " \\" << paid_date.year << " |" << endl;
    cout << "| AMOUNT: " << setw(width - 13) << amount << " |" << endl;
    cout << "| CREDIT NUMBER: " << setw(width - 20) << number << " |" << endl;
    cout << "| EXPIRE DATE: " << setw(width - 27) << expire_date.day << " \\" << expire_date.month << " \\" << expire_date.year << " |" << endl;
    cout << "| TYPE: " << setw(width - 11) << type << " |" << endl;
    cout << "|" << setfill(' ') << setw(width - 2) << "|" << endl;
    cout << "+" << setfill('-') << setw(width - 2) << "+" << endl;


}

void Credit::update()
{
    int option;
    char c;
    while (true)
    {
        cout << "=========[EDIE CREDIT]=========" << endl;
        cout << "| 1. EDIT AMOUNT               |" << endl;
        cout << "| 2. EDIT ADDED DATE           |" << endl;
        cout << "| 3. EDIT CREDIT NUMBER        |" << endl;
        cout << "| 4. EDIT EXPIRE DATE          |" << endl;
        cout << "| 5. EDIT CREDIT TYPE          |" << endl;
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
            cout << "CREDIT NUMBER: " << number << endl;
            cout << "NEW CREDIT NUMBER: ";
            cin.ignore();
            getline(cin, number);
            break;
        case 4:
            cout << "DATE: " << expire_date.day << " \\" << expire_date.month << " \\" << expire_date.year << " |" << endl;
            cout << "NEW DATE: ";
            cin >> expire_date.day >> c >> expire_date.month >> c >> expire_date.year;
            break;
        case 5:
            cout << "CREDIT TYPE: "  << type << endl;
            cout << "NEW CREDIT TYPE: ";
            cin.ignore();
            getline(cin, type);
            break;
        case 0:
            return;

        default:
            cout << "ENTER VALID OPTION" << endl;
        }

    }
}
