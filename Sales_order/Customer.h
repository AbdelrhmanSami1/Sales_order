#pragma once
#include<iostream>
using namespace std;
class Customer
{
protected:
	int m_id;
	string m_phone;
public:
	//constractor:
	Customer();

	//////////////////
	// seter method:
	void set_id(int);
	void set_phone(string);

	///////////////////////

	// geter method:
	int get_id()const;
	string get_phone()const;

	//////////////////////////////

	virtual void display_customer(ostream& out) = 0;
	virtual void add_customer(istream& in) = 0;
	virtual void edit_customer()=0;


	//operator overloading:

	friend istream& operator >> (istream& in, Customer& c);
	friend ostream& operator << (ostream& out,  Customer& c);

};

