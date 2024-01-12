#pragma once
#include"Payment.h"
#include"Cash.h"
#include"Check.h"
#include"Credit.h"
#include"Order.h"
class Transaction
{
	Order* ptr_order;

	double total_payment;

	Payment** payments;
	int size;
	int count;

public:
	Transaction(Order &);

	void payment();
	double get_total_payment();
	int get_order_id();
	void edit_payment();


	friend std::ostream& operator<<(std::ostream& out,  Transaction& t);

	~Transaction();


};

