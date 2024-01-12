#include "Check.h"

Check::Check() :name("nunown"), bank_id("nunown")
{
}

void Check::set_payment()
{
	Payment::set_payment();

	cout << "ENTER CHECK NAME: ";
    cin.ignore();
    getline(cin, name);

	cout << "ENTER BANK ID: ";
    cin.ignore();
    getline(cin, bank_id);
}

void Check::dispaly_payment()
{
   
    int width = 40; // Set the width of the box
    cout << "+" << setfill('-') << setw(width - 2) << "+" << endl;
    cout << "|" << setfill(' ') << setw(width - 2) << "|" << endl;
    cout << "| DATE: " << setw(width - 20) << paid_date.day << " \\" << paid_date.month << " \\" << paid_date.year << " |" << endl;
    cout << "| AMOUNT: " << setw(width - 13) << amount << " |" << endl;
    cout << "| CHECK NAME: " << setw(width - 17) << name << " |" << endl;
    cout << "| BANK ID: " << setw(width - 14) << bank_id << " |" << endl;
    cout << "|" << setfill(' ') << setw(width - 2) << "|" << endl;
    cout << "+" << setfill('-') << setw(width - 2) << "+" << endl;
}

void Check::update()
{
    int option;
    char c;
    while (true)
    {
        cout << "===========[EDIE CHECK]========" << endl;
        cout << "| 1. EDIT AMOUNT               |" << endl;
        cout << "| 2. EDIT ADDED DATE           |" << endl;
        cout << "| 3. EDIT CHECK NAME           |" << endl;
        cout << "| 4. EDIT BANK ID              |" << endl;
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
            cout << "CHECK NAME: " << name << endl;
            cout << "NEW CHECK NAME: ";
            cin.ignore();
            getline(cin, name);
            break;
        case 4:
            cout << "BANK ID  : " << bank_id << endl;
            cout << "NEW BANK ID  : ";
            cin.ignore();
            getline(cin, bank_id);
            break;
        case 0:
            return;

        default:
            cout << "ENTER VALID OPTION" << endl;
        }

    }
}
