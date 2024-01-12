#pragma once
#include "Stock.h"
#include"Orderitem.h"
#include "Customers.h"
#include "Customer.h"
#include <stdlib.h>
#include"Payment.h"
enum Status { NEW, HOLD, PAID, CANCELED };

class Order
{
	int m_id;
	int m_number;
	double total;

	date order_date;

	//Customers* ptr_customers;
	Customer* ptr_customer;
	Stock* ptr_stock;

	Status Order_status;

	int m_max_num_of_items;
	int m_counter_order_item;	
	Orderitem** m_orderitems;

public:
	//costractor:
	Order(Stock& , Customer*, int);


	void create_order();


	int get_id();
	int get_number();
	double get_total();

	Status get_order_status();
	void update_order(int);

	void edit_order();

	void delete_item();


	//operator overloading:
	friend istream& operator >> (istream& in,  Order& order);
	friend ostream& operator << (ostream& out, Order& order);

	~Order();







};



