#pragma once
#include"Customer.h"
#include<string>
#include<iomanip>
class Person:
	public Customer
{
private:
	// use getline to input this
	string m_billing_address;
	string m_full_name; 
public:
	// constractor:
	Person();

	///////////////////////////////
	// seter method:
	void set_billing_address(string);
	void setfull_name(string);
	////////////////////////////////////
	// geter method:
	string get_billing_address()const;
	string get_full_name()const;
	/////////////////////////////////////


	/////////////////////////////////////////

	void display_customer(ostream& out);
	void add_customer(istream& in);
	void edit_customer();
};

