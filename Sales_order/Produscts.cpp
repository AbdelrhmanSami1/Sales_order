#include "Produscts.h"

Produscts::Produscts(int max_num_of_product = 100) : m_max_num_of_product(max_num_of_product), m_count_product(0)
{
	m_products = new Product[m_max_num_of_product];
}

void Produscts::add_product(int product_id)
{

	

	// Check if product dosen't exist in product list:
	for (int i = 0; i < m_count_product; i++)
	{
		if (m_products[i].get_id() == product_id)
		{
			cout << "This product ia alredy exist in product list" << endl;
			return;
		}
	}

	// If the stock is full, resize the array
	if (m_count_product == m_max_num_of_product)
	{
		m_max_num_of_product *= 2;
		Product* temp = new Product[m_max_num_of_product];
		for (int i = 0; i < m_count_product; ++i)
		{
			temp[i] = m_products[i];
		}
		delete[] m_products;
		m_products = temp;
	}
	/////////////////////////////////////////////
	
	// Set new product in products array:
	m_products[m_count_product].set_id(product_id);

	string product_number;
	cout << "Enter product number: ";
	cin.ignore();
	getline(cin, product_number);
	m_products[m_count_product].set_number(product_number);

	string product_name;
	cout << "Enter product name: ";
	cin.ignore();
	getline(cin, product_name);
	m_products[m_count_product].set_name(product_name);

	double product_price;
	cout << "Enter product price: ";
	cin >> product_price;
	m_products[m_count_product].set_price(product_price);

	int product_type;
	cout << "Enter product type: ";
	cin >> product_type;
	m_products[m_count_product].set_type(product_type);


	//update counter of array:
	m_count_product++;
	

}

void Produscts::edit_product(int product_id)
{
	string str;
	int x;
	double d;
	// Check if product exist in product list:
	for (int i = 0; i < m_count_product; i++)
	{
		if (m_products[i].get_id() == product_id)
		{
			int option;
			while (true)
			{
				//system("cls");
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
					cout << "Product name: " << m_products[i].get_name() << endl;
					cout << "New product name: ";
					cin.ignore();
					getline(cin, str);
					m_products[i].set_name(str);
					break;
				case 2:
					cout << "Product ID: " << m_products[i].get_id() << endl;
					cout << "New product ID: ";
					cin >> x;
					if (if_id(x))
					{
						cout << "This product is alredy exist" << endl;
						return;
					}
					m_products[i].set_id(x);
					break;
				case 3:
					cout << "Product price: " << m_products[i].get_price() << endl;
					cout << "New product price: ";
					cin >> d;
					m_products[i].set_price(d);
					break;
				case 4:
					cout << "Product number: " << m_products[i].get_number() << endl;
					cout << "New product number: ";
					cin.ignore();
					getline(cin, str);
					m_products[i].set_number(str);
					break;
				case 5:
					cout << "Product type: " << m_products[i].get_type() << endl;
					cout << "New product type: ";
					cin >> x;
					m_products[i].set_type(x);
					break;
				case 6:
					return;
				default:
					cout << "Enter invalid number" << endl;
					break;
				}

			}
			return;
		}
	}

	// if product dosen't exist in product list:
	cout << "This product dosen't exist in product list." << endl;
}

void Produscts::delete_product(int product_id)
{
	// find the product in the product list and delet it
	for (int i = 0; i < m_count_product; i++)
	{
		if (m_products[i].get_id() == product_id)
		{
			swap(m_products[i], m_products[m_count_product - 1]);
			m_count_product--;
			return;
		}

	}
	// if the product dosen't exit in the product list
	cout << "This product dosen't exit in product list" << endl;
}

void Produscts::display_product(int product_id)
{ 
	// find the product in the product list and dispaly it
	for (int i = 0; i < m_count_product; i++)
	{
		if (m_products[i].get_id() == product_id)
		{
			cout << m_products[i];
			return;
		}

	}
	// if the product dosen't exit in the product list
	cout << "This product dosen't exit in product list" << endl;
}

Product* Produscts::get_product(int product_id)
{
	// find the product in the product list and trturn address
	for (int i = 0; i < m_count_product; i++)
	{
		if (m_products[i].get_id() == product_id)
		{
			return &m_products[i];
		}

	}

	// if the product dosen't exit in the product list
	cout << "This product dosen't exit in product list" << endl;

	return nullptr;

}

bool Produscts::if_id(int product_id)
{
	for (int i = 0; i < m_count_product; i++)
	{
		if (m_products[i].get_id() == product_id)
			return true;
	}
	return false;
}

Produscts::~Produscts()
{
	delete[] m_products;
}

ostream& operator<<(ostream& out, const Produscts& products)
{
	cout << "Produscts list: " << endl;
	cout << "----------------" << endl;
	for (int i = 0; i < products.m_count_product; i++)
	{
		cout << "====[" << i + 1 << "]======" << endl << products.m_products[i];
	}
	return out;
}
