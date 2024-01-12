#pragma once
#include"Product.h"

struct product_quantity
{
	Product* ptr_prduct;
	double quantity;
};
class Stock		
{
	int id;

	int m_count;
	int m_size;
	product_quantity* product_stock;
	//Product* ptr_products;

public:
	//constractor:
	Stock(int);

	//int get_count();
	
	void add_stock(Product&, int);
	void update_stock(int, int);
	void delete_stock(int);
	double get_quantity(int);

	product_quantity* get_product(int);
	

	~Stock();

	// operator overloading:
	friend std::istream& operator>>(std::istream& in, Stock& stock);
	friend std::ostream& operator<<(std::ostream& out, const Stock& stock);






};

