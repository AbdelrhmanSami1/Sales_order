#include "Customer.h"
Customer::Customer() :m_phone("unnown"),m_id(0)
{
}

void Customer::set_id(int id)
{
	m_id = id;
}

void Customer::set_phone(string phone)
{
	m_phone = phone;
}

int Customer::get_id() const
{
	return m_id;
}

string Customer::get_phone() const
{
	return m_phone;
}

istream& operator>>(istream& in, Customer& c)
{
	c.add_customer(in);
	return in;
}

ostream& operator<<(ostream& out,  Customer& c)
{
	c.display_customer(out);
	return out;
}
