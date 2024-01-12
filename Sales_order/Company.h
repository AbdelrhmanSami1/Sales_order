#pragma once
#include"Customer.h"
#include<string>
#include<iomanip>
class Company:
	public Customer
{
private:
	string m_location;
	string m_company_name;
public:
	// constractor:
	Company();

	//////////////////////

	// seter method:
	void set_location(string);
	void set_m_company_name(string);

	/////////////////////////////////////////

	// geter method:	
	string get_location()const;
	string get_company_name()const;
	/////////////////////////////////////////




	void display_customer(ostream& out);
	void add_customer(istream& in);
	void edit_customer();
	
};

