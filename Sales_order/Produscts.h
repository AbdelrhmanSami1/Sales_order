#pragma once
#include"Product.h"
class Produscts
{
	int m_max_num_of_product;
	int m_count_product;
	Product* m_products;
public:
	// constractor:
	Produscts(int);

	void add_product(int);
	void edit_product(int);
	void delete_product(int);
	void display_product(int);

	Product* get_product(int);

	bool if_id(int);


	//operator overloading:
	friend ostream& operator<<(ostream& out, const Produscts& products);

	//destractor:
	~Produscts();




	

};

