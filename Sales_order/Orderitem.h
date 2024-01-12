#pragma once
#include"Stock.h"
class Orderitem
{
	double m_sale_price;
	double m_quantity;
	double amount;
	product_quantity* ptr_product_quantity;
	bool flag;
public:
	//constractor:
	Orderitem(product_quantity & const);
	 
	////////////////////////

	//seter method:
	void set_sale_price(double);
	void set_quantity(double);

	//////////////////////////////

	//geter method:
	double get_sale_price();
	double get_quantity();
	double get_amount();
	
	void delete_item();

	bool if_quntity();// true-> allowed quantity   false-> not allowed quantity   

	
	void update_quantity(double);
	
	// operator overloading:		
	Orderitem operator ++();
	Orderitem operator --();
	Orderitem operator +=(int);
	Orderitem operator -=(int);

	friend ostream& operator << (ostream& out, Orderitem& const orderitem);




};

