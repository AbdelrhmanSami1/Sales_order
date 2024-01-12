#include "Sales.h"

Sales::Sales()
{

	// Customers:
	count_customer = 0;
	size_cutomer = 10;
	customers = new Customer * [size_cutomer];
	

	///////////////////////////////////////////

	//Products:
	count_product = 0;
	size_product = 10;
	products = new Product[size_product];


	// stock
	stock = new Stock(100);

	/////////////////////////////////////////

	//Orders:
	count_order = 0;
	size_order = 10;
	orders = new Order * [size_order];

	/////////////////////////////////////
	
	//Transection:
	count_tra = 0;
	size_tra = 10;
	transactions = new Transaction * [size_tra];

}


void Sales::add_customer()
{
	if (count_customer >= size_cutomer)
	{
		// if the array is full, resize it
		size_cutomer *= 2;
		Customer** temp = new Customer * [size_cutomer];
		for (int i = 0; i < count_customer; i++)
		{
			temp[i] = customers[i];
		}
		delete[] customers;
		customers = temp;
	}

	int option;

	while(true)
	{

		cout << "========[ADD CUSTOMERS]========" << endl;
		cout << "| 1. COMPANY CUSTOMER          |" << endl;
		cout << "| 2. PERSON CUSTOMER           |" << endl;
		cout << "| 3. SAVE                      |" << endl;
		cout << "===============================" << endl;
		cout << "ENTER TOUR OPTION[ ]\b\b";
;
		cin >> option;

		switch (option)
		{
		case 1:
			cout << "ADD COMPANY CUSTOMER: " << endl;
			cout << "----------------------\n";
			customers[count_customer] = new Company;
			cin >> *customers[count_customer];
			++count_customer;
			break;
		case 2:
			cout << "Add PERSON CUSTOMER: " << endl;
			cout << "----------------------\n";
			customers[count_customer] = new Person;
			cin >> *customers[count_customer];
			++count_customer;
			break;
		case 3:
			return;
		default:
			cout << "ENTER INVALID OPTION" << endl;
			break;
		}
	}
	++count_customer;
}
void Sales::edit_cutomer()
{
	int option;


	
	while (true)
	{
		cout << "========[EDIT CUSTOMERS]=======" << endl;
		cout << "| 1. ENTER ID                  |" << endl;
		cout << "| 2. DISPLAY ALL CUSTOMERS     |" << endl;
		cout << "| 3.SAVE                       |" << endl;
		cout << "===============================" << endl;
		cout << "ENTER TOUR OPTION[ ]\b\b";
		cin >> option;
		switch (option)
		{
		case 1:
			int customer_id;
			cout << "ENTER CUSTOMER ID: " << endl;
			cin >> customer_id;
			for (int i = 0; i < count_customer; i++)
			{
				if (customers[i]->get_id() == customer_id)
				{
					customers[i]->edit_customer();
					return;
				}
			}
			cout << "CUSTOMER DOSEN'T EXIST IN CUSTOMER LIST" << endl;
			break;
		case 2:
			int c;
			for (int i = 0; i < count_customer; i++)
			{
				cout << "====[" << i + 1 << "]======" << endl << *customers[i];
			}
			cout << "ENTER YOUR OPTION" << endl;
			cin >> c;
			customers[c - 1]->edit_customer();
			break;
		case 3:
			return;
		default:
			cout << "ENTER INVALID OPTION" << endl;

		}
	}
	
}
void Sales::delete_customer()
{
	bool flag = 1;

	while (true)
	{

		int option;
		cout << "=======[DELETE CUSTOMERS]======" << endl;
		cout << "| 1. ENTER ID                  |" << endl;
		cout << "| 2. DISPLAY ALL CUSTOMERS     |" << endl;
		cout << "| 3.SAVE                       |" << endl;
		cout << "===============================" << endl;
		cout << "ENTER TOUR OPTION[ ]\b\b";
		cin >> option;
		switch (option)
		{
		case 1:
			int customer_id;
			cout << "ENTER CUSTOMER ID: " << endl;
			cin >> customer_id;
			for (int i = 0; i < count_customer; i++)
			{
				if (customers[i]->get_id() == customer_id)
				{
					swap(customers[i], customers[count_customer - 1]);
					--count_customer;
					flag = 0;
					break;
				}
			}
			if(flag)
				cout << "CUSTOMER DOSEN'T EXIST IN CUSTOMER LIST" << endl;
			break;
		case 2:
			int c;
			for (int i = 0; i < count_customer; i++)
			{
				cout << "====[" << i + 1 << "]======" << endl << *customers[i];
			}
			cout << "ENTER YOUR OPTION" << endl;
			cin >> c;
			swap(customers[c-1], customers[count_customer - 1]);
			--count_customer;
			break;
		case 3:
			return;
		default:
			cout << "ENTER INVALID OPTION" << endl;

		}
	}
}
void Sales::display_customer()
{
	int customer_id;
	cout << "ENTER CUSTOMER ID: ";
	cin >> customer_id;
	

	for (int i = 0; i < count_customer; i++)
	{
		//cout << count_customer << endl;
		if (customers[i]->get_id() == customer_id)
		{
			cout << *customers[i];
			return;
		}
	}
	cout << "CUSTOMER DOSEN'T EXIST IN CUSTOMER LIST" << endl;
}
void Sales::display_all_customer()
{
	for (int i = 0; i < count_customer; i++)
	{
		cout << "====[" << i + 1 << "]======" << endl << *customers[i];
	}
}


void Sales::add_product()
{
	int product_id;
	cout << "ENTER PRODUCT ID: ";
	cin >> product_id;
	// Check if product dosen't exist in product list:
	for (int i = 0; i < count_product; i++)
	{
		if (products[i].get_id() == product_id)
		{
			cout << "THIS PRODUCT EXIST IN PRODUCT LIST" << endl;
			return;
		}
	}

	// If the stock is full, resize the array
	if (count_product == size_product)
	{
		size_product *= 2;
		Product* temp = new Product[size_product];
		for (int i = 0; i < count_product; ++i)
		{
			temp[i] = products[i];
		}
		delete[] products;
		products = temp;
	}
	/////////////////////////////////////////////

	// Set new product in products array:
	products[count_product].set_id(product_id);

	string product_number;
	cout << "ENTER PRODUCT NUMBER: ";
	cin.ignore();
	getline(cin, product_number);
	products[count_product].set_number(product_number);

	string product_name;
	cout << "ENTER PRODUCT NAME: ";
	cin.ignore();
	getline(cin, product_name);
	products[count_product].set_name(product_name);

	double product_price;
	cout << "ENTER PRODUCT PRICE : ";
	cin >> product_price;
	products[count_product].set_price(product_price);

	int product_type;
	cout << "ENTER PRODUCT TYPE: ";
	cin >> product_type;
	products[count_product].set_type(product_type);


	//update counter of array:
	++count_product;

}
void Sales::edit_product()
{
	int index = -1;
	int option;

	string str;
	int x;
	double d;

	bool flag = 1; // checck if new id exit in product list
	bool product_exist = 0;


	/*while (true)
	{

		cout << "=========[EDIT PRODUCR]========" << endl;
		cout << "| 1. ENTER ID                  |" << endl;
		cout << "| 2. DISPLAY ALL PRODUCR       |" << endl;
		cout << "| 3.SAVE                       |" << endl;
		cout << "===============================" << endl;
		cout << "ENTER TOUR OPTION[ ]\b\b";
		cin >> option;
		switch (option)
		{
		case 1:
			int product_id;
			cout << "ENTER PRODUCT ID: ";
			cin >> product_id;
			for (int i = 0; i < count_product; i++)
			{
				if (products[i].get_id() == product_id)
				{
					index = i;
					break;
				}
			}
			cout << "PRODUCT DOSEN'T EXIST IN PRODUCT LIST" << endl;

			break;
		case 2:
			int c;
			for (int i = 0; i < count_product; i++)
			{
				cout << "====[" << i + 1 << "]======" << endl << products[i];
			}
			cout << "ENTER YOUR OPTION" << endl;
			cin >> c;
			index = c - 1;
			break;
		case 3:
			return;
		default:
			break;
		}
	}*/
	do
	{
		cout << "ENTER PRODUCR ID: ";
		cin >> x;
		for (int i = 0; i < count_product; i++)
		{
			if (products[i].get_id() == x)
			{
				index = i;
				product_exist = 1;
				break;
			}
		}
		if (!product_exist)
			cout << "PRODUCT DOSEN'T EXIST IN PRODUCT LIST" << endl;
	
	} while (index == -1);

	while(true)
	{
		int ch;

		cout << "=========[EDIE PRODUCT]========" << endl;
		cout << "| 1. EDIT PRODUCT NAME         |" << endl;
		cout << "| 2. EDIT PRODUCT ID           |" << endl;
		cout << "| 3. EDIT PRODUCT PRICE        |" << endl;
		cout << "| 4. EDIT PRODUCT NUMBER       |" << endl;
		cout << "| 5. EDIT PRODUCT TYPE         |" << endl;
		cout << "| 6. SAVE                      |" << endl;
		cout << "================================" << endl;
		
		cout << "Enter your option[ ]\b\b";
		cin >> ch;

		switch (ch)
		{
		case 1:
			cout << "PRODUCT NAME: " << products[index].get_name() << endl;
			cout << "NEW PRODUCT NAME: ";
			cin.ignore();
			getline(cin, str);
			products[index].set_name(str);
			break;
		case 2:
			cout << "PRODUCT ID: " << products[index].get_id() << endl;
			cout << "NEW PRODUCT ID: ";
			cin >> x;
		
			for (int i = 0; i < count_product; i++)
			{
				
				if (x == products[i].get_id())
				{
					flag = 0;
					cout << "THIS PRODUCT ID EXIST IN PRODUCT LIST" << endl;
					break;
				}
			}
			if(flag)
				products[index].set_id(x);
			break;
		case 3:
			cout << "PRODUCT PRICE: " << products[index].get_price() << endl;
			cout << "NEW PRODUCT PRICE: ";
			cin >> d;
			products[index].set_price(d);
			break;
		case 4:
			cout << "PRODUCT NUMBER: " << products[index].get_number() << endl;
			cout << "NEW PRODUCT NUMBER: ";
			cin.ignore();
			getline(cin, str);
			products[index].set_number(str);
			break;
		case 5:
			cout << "PRODUCT TYPE: " << products[index].get_type() << endl;
			cout << "NEW PRODUCT TYPE: ";
			cin >> x;
			products[index].set_type(x);
			break;
		case 6:
			return;
		default:
			cout << "ENTER INVALID OPTION" << endl;
			break;
		}

	}




}
void Sales::delete_product()
{
	bool flag = 1;

	while (true)
	{

		int option;
		cout << "========[DELETE PRODUCT]=======" << endl;
		cout << "| 1. ENTER ID                  |" << endl;
		cout << "| 2. DISPLAY ALL PRODUCT       |" << endl;
		cout << "| 3.SAVE                       |" << endl;
		cout << "===============================" << endl;
		cout << "ENTER TOUR OPTION[ ]\b\b";
		cin >> option;
		switch (option)
		{
		case 1:
			int product_id;
			cout << "ENTER PRODUCT ID: " << endl;
			cin >> product_id;
			for (int i = 0; i < count_product; i++)
			{
				if (products[i].get_id() == product_id)
				{
					swap(products[i], products[count_product - 1]);
					--count_product;
					flag = 0;
					break;
				}
			}
			if(flag)
				cout << "PRODUCT DOSEN'T EXIST IN PRODUCT LIST" << endl;
			break;
		case 2:
			int c;
			for (int i = 0; i < count_product; i++)
			{
				cout << "====[" << i + 1 << "]======" << endl << products[i];
			}
			cout << "ENTER YOUR OPTION" << endl;
			cin >> c;
			swap(products[c - 1], products[1]);
			--count_product;
			break;
		case 3:
			return;
		default:
			cout << "ENTER INVALID OPTION" << endl;

		}
	}
}
void Sales::display_product()
{
	int product_id;
	cout << "ENTER PRODUCT ID: ";
	cin >> product_id;
	

	for (int i = 0; i < count_product; i++)
	{
		
		if (products[i].get_id() == product_id)
		{
			cout << products[i];
			return;
		}
	}
	cout << "PRODUCT DOSEN'T EXIST IN PRODUCT LIST" << endl;
}
void Sales::display_all_product()
{
	for (int i = 0; i < count_product; i++)
	{
		cout << "====[" << i + 1 << "]======" << endl << products[i];
	}
}



void Sales::add_stock()
{
	int product_id;
	int quantity;
	
	cout << "ENTER PRODUCT ID: ";
	cin >> product_id;

	for (int i = 0; i < count_product; i++)
	{
		if (products[i].get_id() == product_id)
		{
			cout << "ENTER QUANTITY: ";
			cin >> quantity;
			stock->add_stock(products[i], quantity);
			return;
		}
	}
	cout << "PRODUCT DOSEN'T EXIST IN PRODUCT LIST" << endl;
	
}

void Sales::update_stock()
{
	int product_id;
	int quantity;

	cout << "ENTER ID: " << endl;
	cin >> product_id;
	cout << "ENTER QUANTITY: " << endl;
	cin >> quantity;
	stock->update_stock(product_id, quantity);
}

void Sales::delete_stock()
{
	int product_id;
	cout << "ENTER ID: " << endl;
	cin >> product_id;
	stock->delete_stock(product_id);

}

void Sales::get_quantity()
{
	int product_id;
	cout << "ENTER ID: " << endl;
	cin >> product_id;
	cout << "QUANTITY: " << stock->get_quantity(product_id) << endl;
}

void Sales::display_stock()
{
	cout << *stock;
}

void Sales::creatr_order()
{
	// serach in customers
	int customer_id;
	
	cout << "ENTER CUSTOMER ID: ";
	cin >> customer_id;
	
	int option;
	for (int i = 0; i < count_customer; i++)
	{
		if (customers[i]->get_id() == customer_id)
		{
			orders[count_order] = new Order(*stock, customers[i], 100);
			orders[count_order]->create_order();
			cout << "1.NEW - 2.HOLD - 3.PAID - 4.CANCELED" << endl;
			cout << "ENTER TOUR OPTION[ ]\b\b";
			cin >> option;
			orders[count_order]->update_order(option);
			count_order++;
			return;
		}

	}
	
	cout << "CUSTOMER DOSEN'T EXIST IN CUSTOMER LIST" << endl;

}

void Sales::edit_order()
{
	int order_id;
	cout << "ENTER ORDER ID: ";
	cin >> order_id;

	for (int i = 0; i < count_order; i++)
	{
		if (order_id == orders[i]->get_id())
		{
			orders[i]->edit_order();
			return;
		}
	}

	cout << "THIS ORDER DOSEN'T EXIST" << endl;	
}

void Sales::delete_order()
{
	int order_id;

	cout << "ENTER ORDER ID: ";
	cin >> order_id;

	for (int i = 0; i < count_order; i++)
	{
		if (order_id == orders[i]->get_id())
		{
			swap(orders[i], orders[count_order - 1]);
			cout << "DELETED SUCCSESSFULLY" << endl;
			return;
		}
	}

	cout << "ORDER DOSEN'T EXIST" << endl;
}

void Sales::display_order()
{
	int order_id;

	cout << "ENTER ORDER ID: ";
	cin >> order_id;

	for (int i = 0; i < count_order; i++)
	{
		if (order_id == orders[i]->get_id())
		{
			cout << *orders[i];
			return;
		}
	}

	cout << "THIS ORDER DOSEN'T EXIST" << endl;
}

void Sales::display_all_order()
{
	for (int i = 0; i < count_order; i++)
	{
		cout << *orders[i];
	}
}

void Sales::update_order()
{
	int order_id;
	int option;
	Status order_status;

	cout << "ENTER ORDER ID: ";
	cin >> order_id;

	for (int i = 0; i < count_order; i++)
	{
		if (orders[i]->get_id() == order_id)
		{
			order_status = orders[i]->get_order_status();
			switch (order_status)
			{
			case NEW:
				cout << "ORDER STATUS: NEW" << endl;
				break;
			case HOLD:
				cout << "ORDER STATUS: HOLD" << endl;
				break;
			case PAID:
				cout << "ORDER STATUS: PAID" << endl;
				break;
			case CANCELED:
				cout << "ORDER STATUS: CANCELED" << endl;
				break;
			default:
				break;
			}
			cout << "1.NEW - 2.HOLD - 3.PAID - 4.CANCELED" << endl;
			cout << "ENTER TOUR OPTION[ ]\b\b";
			cin >> option;
			orders[i]->update_order(option);
		}
	}
}

void Sales::create_tra()
{
	int order_id;

	cout << "ENTER ORDER ID: ";
	cin >> order_id;

	for (int i = 0; i < count_tra; ++i)
	{
		if (transactions[i]->get_order_id() == order_id)
		{
			transactions[i]->payment();
			return;
		}
	}

	for (int i = 0; i < count_order; ++i)
	{
		if (orders[i]->get_id() == order_id)
		{
			transactions[count_tra] = new Transaction(*orders[i]);
			transactions[count_tra]->payment();
			++count_tra;
			return;
		}
	}

	cout << "ORDER DOSEN'T EXIST" << endl;

}

void Sales::edit_tra()
{
	int order_id;

	cout << "ENTER ORDER ID: ";
	cin >> order_id;

	for (int i = 0; i < count_tra; ++i)
	{
		if (transactions[i]->get_order_id() == order_id)
		{
			transactions[i]->edit_payment();
		}
	}
}

void Sales::delete_tra()
{
	int order_id;

	cout << "ENTER PRODUT ID: ";
	cin >> order_id;

	for (int i = 0; i < count_tra; ++i)
	{
		if (transactions[i]->get_order_id() == order_id)
		{
			swap(transactions[i], transactions[count_tra - 1]);
			--count_tra;
			return;
		}
	}

	cout << "TRANSECTION DOSEN'T EXIST" << endl;

}

void Sales::display_tra()
{

	int order_id;

	cout << "ENTER PRODUT ID: ";
	cin >> order_id;

	for (int i = 0; i < count_tra; ++i)
	{
		if (transactions[i]->get_order_id() == order_id)
		{
			cout << *transactions[i];
			return;
		}
	}

	cout << "TRANSECTION DOSEN'T EXIST" << endl;
}

void Sales::display_all_tra()
{

	if (count_tra == 0)
	{
		cout << "NO TRANSACTIONS" << endl;
		return;
	}
	cout << "TRANSACTIONS LIST: " << endl;

	for (int i = 0; i < count_tra; ++i)
	{
		cout << *transactions[i];
	}
}

Sales::~Sales()
{
	// Deallocate memory for customers
	for (int i = 0; i < count_customer; i++)
	{
		delete customers[i];
	}
	delete[] customers;

	// Deallocate memory for products
	delete[] products;

	// Deallocate memory for orders
	for (int i = 0; i < count_order; i++)
	{
		delete orders[i];
	}
	delete[] orders;

	// Deallocate memory for transactions
	for (int i = 0; i < count_tra; i++)
	{
		delete transactions[i];
	}
	delete[] transactions;

	// Deallocate memory for stock
	delete stock;
}
