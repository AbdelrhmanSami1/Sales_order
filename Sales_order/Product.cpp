	#include "Product.h"

	Product::Product() :m_id(0), m_number("unnown"), m_name("unnown"), m_price(0.0), m_type(0)
	{
	}

	void Product::set_id(int id)
	{
		m_id = id;
	}

	void Product::set_number(string number)
	{
		m_number = number;
	}

	void Product::set_name(string name)
	{
		m_name = name;
	}

	void Product::set_price(double price)
	{
		m_price = price;
	}

	void Product::set_type(int type)
	{
		m_type = type;
	}

	int Product::get_id()
	{
		return m_id;
	}

	string Product::get_number()
	{
		return m_number;
	}

	string Product::get_name()
	{
		return m_name;
	}

	double Product::get_price()
	{
		return m_price;
	}

	int Product::get_type()
	{
		return m_type;
	}

	void Product::update()
	{
		int option;
		while(true)
		{
			system("cls");
			cout << "1-Edit product name" << endl;
			cout << "2-Edit product id" << endl;
			cout << "3-Edit product price" << endl;
			cout << "4-Edit product number" << endl;
			cout << "5-Edit product type" << endl;
			cout << "6-Done editting" << endl;
			cout << "Enter your option[ ]\b\b";
			cin >> option;

			switch (option)
			{
			case 1:
				cout << "Product name: " << m_name << endl;
				cout << "New product name: ";
				cin.ignore();
				getline(cin, m_name);
				break;
			case 2:
				cout << "Product ID: " << m_id << endl;
				cout << "New product ID: ";
				cin >> m_id;
				break;
			case 3:
				cout << "Product price: " << m_price << endl;
				cout << "New product price: ";
				cin >> m_price;
				break;
			case 4:
				cout << "Product number: " << m_number << endl;
				cout << "New product number: ";
				cin.ignore();
				getline(cin, m_number);
				break;
			case 5:
				cout << "Product quantity: " << m_type << endl;
				cout << "New product quantity: ";
				cin >> m_type;
				break;
			case 6:
				return;
			default:
				cout << "Enter invalid number" << endl;
				break;
			}
			
		}

		
	}

	std::istream& operator>>(std::istream& in, Product& product)
	{
		cout << "Enter product ID: ";
		in >> product.m_id;
		cout << "Enter product number: ";
		in.ignore();
		getline(in, product.m_number);
		cout << "Enter product name: ";
		in.ignore();
		getline(in,product.m_name);
		cout << "Enter product price: ";
		in >> product.m_price;
		cout << "Enter product type: ";
		in >> product.m_type;
		return in;
	}

	std::ostream& operator<<(std::ostream& out, const Product& product)
	{
		int width = 40; // Set the width of the box
		out << "+" << std::setfill('-') << std::setw(width - 2) << "+" << std::endl;
		out << "|" << std::setfill(' ') << std::setw(width - 2) << "|" << std::endl;
		out << "| ID: " << std::setw(width - 9) << product.m_id << " |" << std::endl;
		out << "| Number: " << std::setw(width - 13) << product.m_number << " |" << std::endl;
		out << "| Name: " << std::setw(width - 11) << product.m_name << " |" << std::endl;
		out << "| Price: " << std::setw(width - 12) << product.m_price << " |" << std::endl;
		out << "| Type: " << std::setw(width - 15) << product.m_type << " |" << std::endl;
		out << "|" << std::setfill(' ') << std::setw(width - 2) << "|" << std::endl;
		out << "+" << std::setfill('-') << std::setw(width - 2) << "+" << std::endl;
		return out;
	}
