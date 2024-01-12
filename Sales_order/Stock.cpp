#include "Stock.h"

Stock::Stock( int size = 100):m_count(0),m_size(size)
{
	product_stock = new product_quantity[m_size];
}
void Stock::add_stock(Product& ptr_product, int quantity)
{
	//check if product exist in stock:
	for (int i = 0; i < m_count; i++)
	{

		if (product_stock[i].ptr_prduct->get_id() == ptr_product.get_id())
		{
			cout << "PRODUCT EXIST IN STOCK" << endl;
			return;
		}
	}
	product_stock[m_count].ptr_prduct = &ptr_product;
	product_stock[m_count].quantity = quantity;
	m_count++;

}

void Stock::update_stock(int product_id, int Quantity)
{
	//check if product exist in stock and update quantity:
	for (int i = 0; i < m_count; i++)
	{
		if (product_stock[i].ptr_prduct->get_id() == product_id)
		{
			cout << "QUANTITY: " << product_stock[i].quantity << endl;
			product_stock[i].quantity = Quantity;
			return;
		}
	}

	cout << "PRODUCT DOSEN'T EXIST IN STOCK" << endl;
}

void Stock::delete_stock(int product_id)
{
	for (int i = 0; i < m_count; i++)
	{
		if (product_stock[i].ptr_prduct->get_id() == product_id)
		{
			swap(product_stock[i], product_stock[m_count - 1]);
			m_count--;
			return;
		}
	}
	// if product id dosen't exist in stock:
	cout << "PRODUCT DOSEN'T EXIST IN STOCK" << endl;
}

double Stock::get_quantity(int product_id)
{
	for (int i = 0; i < m_count; i++)
	{
		if (product_stock[i].ptr_prduct->get_id() == product_id)
		{
			return product_stock[i].quantity;
		}
	}
	cout << "PRODUCT DOSEN'T EXIST IN STOCK" << endl;
	return 0.0;
}

product_quantity* Stock::get_product(int product_id)
{
	for (int i = 0; i < m_count; i++)
	{
		if (product_stock[i].ptr_prduct->get_id() == product_id)
			return &product_stock[i];
	}
	//cout << "PRODUCT DOSEN'T EXIST IN STOCK" << endl;
	return nullptr;
}





Stock::~Stock()
{
	delete[] product_stock;
}

std::istream& operator>>(std::istream& in, Stock& stock)
{
	cout << "Enter stock id: ";
	in >> stock.id;
	return in;
}

std::ostream& operator<<(std::ostream& out, const Stock& stock)
{
	out << "=====Stock id[ " << stock.id << "]=====" << endl;
	out << "Products list in stock: " << endl;
	out << "----------------" << endl;
	for (int i = 0; i < stock.m_count; i++)
	{
		out << "====[" << i + 1 << "]======" << endl;
		out << "Product name: " << stock.product_stock[i].ptr_prduct->get_name() << endl;
		out << "Product ID: " << stock.product_stock[i].ptr_prduct->get_id() << endl;
		out << "Product quantity: " << stock.product_stock[i].quantity << endl;

	}
	return out;
}
