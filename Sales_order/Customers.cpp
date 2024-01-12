#include "Customers.h"

Customers::Customers(int max_num_of_customers = 100):m_count(0), m_max_num_of_customers(max_num_of_customers)
{
	customers = new Customer*[max_num_of_customers];
}

int Customers::get_count()
{
	return m_count;
}

Customer* Customers::get_customer(int customer_id)
{

	for (int i = 0; i < m_count; i++)
	{
		if (customers[i]->get_id() == customer_id)
			return customers[i];
	}
	return nullptr;
}

void Customers::add_customer()
{
	  if (m_count >= m_max_num_of_customers)
        {
            // if the array is full, resize it
            m_max_num_of_customers *= 2;
            Customer** temp = new Customer*[m_max_num_of_customers];
            for (int i = 0; i < m_count; i++)
            {
                temp[i] = customers[i];
            }
            delete[] customers;
            customers = temp;
        }

	int option;

	do {

		cout << "1-Company customer" << endl;
		cout << "2-Person customer" << endl;
		cout << "Enter your option[ ]\b\b";
		cin >> option;

		switch (option)
		{
		case 1:
			cout << "Add company customer: " << endl;
			cout << "----------------------\n";
			customers[m_count] = new Company;
			cin >> *customers[m_count];
			break;
		case 2:
			cout << "Add person customer: " << endl;
			cout << "----------------------\n";
			customers[m_count] = new Person;
			cin >> *customers[m_count];
			break;
		default:
			cout << "Enter invalid number" << endl;
			break;
		}
	} while (option != 1 && option != 2);
	m_count++;
}

void Customers::edit_cutomer()
{
	int option;


	cout << "Customers list: " << endl;
	cout << "----------------" << endl;
	for (int i = 0; i < m_count; i++)
	{
		cout << "====[" << i + 1 << "]======" << endl << *customers[i];
	}
	cout << "Enter your option[ ]\b\b";
	cin >> option;
	customers[option - 1]->edit_customer();
}

void Customers::delete_customer()
{
	int option;

	cout << "Customers list: " << endl;
	cout << "----------------" << endl;
	for (int i = 0; i < m_count; i++)
	{
		cout << "====[" << i + 1 << "]======" << endl << *customers[i];
	}
	cout << "Enter your option[ ]\b\b";
	cin >> option;
	swap(customers[option - 1], customers[m_count - 1]);
	m_count--;

}


ostream& operator<<(ostream& out, const Customers& c)
{
	cout << "Customers list: " << endl;
	cout << "----------------" << endl;
	for (int i = 0; i < c.m_count; i++)
	{
		cout << "====[" << i + 1 << "]======" << endl << *c.customers[i];
	}
	return out;
}
Customers::~Customers()
{
	for (int i = 0; i < m_count; i++)
	{
		delete customers[i];
	}
	delete[] customers;
}


