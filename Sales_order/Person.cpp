#include "Person.h"

Person::Person() :m_billing_address("unnown"), m_full_name("unnown")
{
}

void Person::set_billing_address(string billing_address)
{
	m_billing_address = billing_address;
}

void Person::setfull_name(string full_name)
{
	m_full_name = full_name;
}

string Person::get_billing_address() const
{
	return m_billing_address;
}

string Person::get_full_name() const
{
	return m_full_name;
}
void Person::display_customer(ostream& out)
{
	int width = 40; // Set the width of the box
	out << "+" << setfill('-') << setw(width - 2) << "+" << endl;
	out << "|" << setfill(' ') << setw(width - 2) << "|" << endl;
	out << "| CUSTOMER ID: " << setw(width - 17) << m_id << "|" << endl;
	out << "| NAME: " << setw(width - 10) << m_full_name << "|" << endl;
	out << "| BILLING ADDRESS: " << setw(width - 21) << m_billing_address << "|" << endl;
	out << "| PHONE NUMBER: " << setw(width - 18) << m_phone<< "|" << endl;
	out << "|" << setfill(' ') << setw(width - 2) << "|" << endl;
	out << "+" << setfill('-') << setw(width - 2) << "+" << endl;

}
void Person::add_customer(istream& in)
{
	cout << "ENTER CUSTOMER ID: ";
	cin >> m_id;
	
	cout << "ENTER FULL NAME: ";
	cin.ignore();
	getline(in, m_full_name);

	cout << "ENTER BILLING ADDRESS: ";
	//cin.ignore();
	getline(in,m_billing_address);
;
	cout << "ENTER PHONE: ";
	//cin.ignore();
	getline(in, m_phone);

}
void Person::edit_customer()
{
	int option;
	while(true)
	{

		cout << "=====[EDIT PERSON CUSTOMER]====" << endl;
		cout << "| 1. EDIT FULL NAME           |" << endl;
		cout << "| 2. EDIR BILLING ADDRESS     |" << endl;
		cout << "| 3. EDIT PHONE               |" << endl;
		cout << "| 4. SAVE                     |" << endl;
		cout << "===============================" << endl;

		cout << "Enter your option[ ]\b\b";
		cin >> option;
		switch (option)
		{
		case 1:
			cout << "FULL NAME : " << m_full_name << endl;
			cout << "NEW FULL NAME : ";
			cin.ignore();
			getline(cin, m_full_name);
			break;
		case 2:
			cout << "BILLING ADDRESS: " << m_billing_address << endl;
			cout << "NEW BILLING ADDRESS: ";
			cin.ignore();
			getline(cin, m_billing_address);
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

