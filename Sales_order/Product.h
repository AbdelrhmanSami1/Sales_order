#pragma once
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;
class Product
{
	int m_id;
	string m_number;
	string m_name;
	double m_price;
	int m_type;
public:
	// constractor:
	Product();

	// seter method:
	void set_id(int);
	void set_number(string);
	void set_name(string);
	void set_price(double);
	void set_type(int);
	/////////////////////////
	
	// geter method:
	int get_id();
	string get_number();
	string get_name();
	double get_price();
	int get_type();
	///////////////////////

	void update();

	// operator overloading:
	friend std::istream& operator>>(std::istream& in, Product& product);
	friend std::ostream& operator<<(std::ostream& out, const Product& product);
	
};

