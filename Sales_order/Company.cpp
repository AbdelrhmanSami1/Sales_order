#include "Company.h"

Company::Company():m_location("unnown"), m_company_name("unnown")
{

}

void Company::set_location(string location)
{
    m_location = location;
}

void Company::set_m_company_name(string company_name)
{
    m_company_name = company_name;
}

string Company::get_location() const
{
    return m_location;
}

string Company::get_company_name() const
{
    return m_company_name;
}

void Company::display_customer(ostream& out)
{
    int width = 40; // Set the width of the box
    out << "+" << setfill('-') << setw(width - 2) << "+" << endl;
    out << "|" << setfill(' ') << setw(width - 2) << "|" << endl;
    out << "| COMPANY ID: " << setw(width - 16) << m_id << "|" << endl;
    out << "| COMPANY NAME: " << setw(width - 18) << m_company_name << "|" << endl;
    out << "| COMPANY LOCATION: " << setw(width - 22) << m_location << "|" << endl;
    out << "| COMPANY PHONE: " << setw(width - 19) << m_phone << "|" << endl;
    out << "|" << setfill(' ') << setw(width - 2) << "|" << endl;
    out << "+" << setfill('-') << setw(width - 2) << "+" << endl;
}

void Company::add_customer(istream& in)
{
    cout << "ENTER CUSTOMER ID: ";
    cin >> m_id;

    cout << "ENTER COMPANY NAME: ";
    cin.ignore();
    getline(in, m_company_name);

    cout << "ENTER COMPANY LOCATION: ";
    cin.ignore();
    getline(in, m_location);

    cout << "ENTER COMPANY PHONE: ";
    cin.ignore();
    getline(in, m_phone);
}

void Company::edit_customer()
{ 
    int option;
    while (true)
    {

        cout << "====[EDIT COMPANY CUSTOMER]====" << endl;
        cout << "| 1. EDIT COMPANY NAME        |" << endl;
        cout << "| 2. EDIR COMPANY LOCATION    |" << endl;
        cout << "| 3. EDIT PHONE               |" << endl;
        cout << "| 4. SAVE                     |" << endl;
        cout << "===============================" << endl;

        cout << "ENTER YOUR OPTION [ ]\b\b";
        cin >> option;

        switch (option)
        {
        case 1:
            cout << "COMPANT NAME: " << m_company_name << endl;
            cout << "NEW COMPANY NAME: ";
            cin.ignore();
            getline(cin, m_company_name);
            break;
        case 2:
            cout << "COMPANY LOCATION: " << m_location << endl;
            cout << "NEW COMPANY LOCATION: ";
            cin.ignore();
            getline(cin, m_location);
            break;
        case 3:
            cout << "PHONE: " << m_phone << endl;
            cout << "NEW PHONE: ";
            cin.ignore();
            getline(cin, m_phone);
            break;
        case 4:
            return;
        default:
            cout << "ENTER INVALID OPTION" << endl;
            break;
        }
    }
}


