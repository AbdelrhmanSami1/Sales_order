#pragma once
#include<iostream>
#include<string>
#include <iomanip>
using namespace std;
struct date
{
	int day;
	int month;
	int year;
	date(int d=0,int m=0,int y=0)
	{
		day = d;
		month = m;
		year = y;
	}
	
};
class Payment
{
protected:
	date paid_date;
	double amount;

public:

	Payment();

	void set_amount(double);
	double get_amount();

	virtual void set_payment();
	virtual void dispaly_payment() = 0;
	virtual void update() = 0;
};

