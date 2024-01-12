#include "Order.h"


Order::Order(Stock& stock, Customer* customer, int max_num_of_items = 100)
	:m_max_num_of_items(max_num_of_items), m_counter_order_item(0)
	,ptr_stock(&stock)
{
	//random id from 1:100000
	//Change random based on time
	srand(time(0));
	m_id = rand() % 100000 + 1;

	//ptr_stock = &stock;
	ptr_customer = customer;

	m_orderitems = new Orderitem * [m_max_num_of_items];
}

Status Order::get_order_status()
{
	return Order_status;
}


void Order::update_order(int status)
{
	switch (status)
	{
	case 1:
		Order_status = NEW;
		break;
	case 2:
		Order_status = HOLD;	
		break;
	case 3:
		Order_status = PAID;
		break;
	case 4:
		Order_status = CANCELED;
		break;
	default:
		cout << "Invalid status provided." << endl;
		break;
	}
}

void Order::create_order()
{

	
	// add orederitem to order:
	char c;
	cout << "ORDER ID: " << m_id << endl;
	cout << "ENTER DATE[DD/MM/Y]: " << endl;
	cin >> order_date.day >> c >> order_date.month >> c >> order_date.year;
	product_quantity* p;
	int product_id;
	int product_quantity;
	int product_sell_price;

	char again;

	bool flag = 0;

	do
	{
		do
		{
			cout << "Enter peoduct ID: ";
			cin >> product_id;
			p = ptr_stock->get_product(product_id);
			if (p == nullptr)
			{
				cout << "PRODUCT DOSEN'T EXIST IN STOCK" << endl;
				flag = 1;
				return;
			}
		} while (p == nullptr);
		m_orderitems[m_counter_order_item] = new Orderitem(*p);

		if (flag)
			return;

		cout << "Enter quantity: ";
		cin >> product_quantity;
		m_orderitems[m_counter_order_item]->update_quantity(product_quantity);

		if (!m_orderitems[m_counter_order_item]->if_quntity())
			return;

		cout << "Enter price: ";
		cin >> product_sell_price;
		m_orderitems[m_counter_order_item]->set_sale_price(product_sell_price);

		m_counter_order_item++;

		cout << "ADED ORDRE ITEM SUCCESSFULLY" << endl;

		cout << "ADD NEW ORDER ITEM[Y,N]...";
		cin >> again;

	} while (again == 'y');

}
int Order::get_id()
{
	return m_id;
}
int Order::get_number()
{
	return m_number;
}

double Order::get_total()
{
	total = 0;

	for (int i = 0; i < m_counter_order_item; i++)
	{
		total += m_orderitems[i]->get_quantity()*m_orderitems[i]->get_sale_price();
	}
	return total;
}

void Order::edit_order()
{
	int quantity;
	int option;
	double temp;
	int edit;


	cout << *this;
	if (m_counter_order_item == 0)
	{
		cout << "NO ORDER ITEMS " << endl;
		return;
	}
	cout << "ENTER YOUR OPTION [ ]\b\b";
	cin >> option;

	while(true)
	{

		cout << "==========[EDIT ORDER]=========" << endl;
		cout << "| 1. EDIT QUANTITY            |" << endl;
		cout << "| 2. EDIT PRICE               |" << endl;
		cout << "| 3. DELETE ITEM              |" << endl;
		cout << "| 4. SAVE                     |" << endl;
		cout << "===============================" << endl;

		cout << "ENTER YOUR OPTION [ ]\b\b";
		cin >> edit;

		switch (edit) 
		{
		case 1:
			cout << "QUAINTITY: " << m_orderitems[option-1]->get_quantity() << endl;
			cout << "NEW QUAINTITY: ";
			cin >> temp;
			m_orderitems[option-1]->update_quantity(temp);

			//cout << "QUANTITY MODIFIED SUCCESSFULLY" << endl;

			break;

		case 2:
			cout << "PRICE: " << m_orderitems[option-1]->get_sale_price() << endl;
			cout << "NEW PRICE: ";
			cin >> temp;
			m_orderitems[option-1]->set_sale_price(temp);

			cout << "PRICE MODIFIED SUCCESSFULLY" << endl;

			break;
		case 3:
		
			m_orderitems[option - 1]->delete_item();
			swap(m_orderitems[option - 1], m_orderitems[m_counter_order_item - 1]);
			m_counter_order_item--;
		
			break;
		case 4:
			return;
		default:
			cout << "ENTER VALID OPTION" << endl;
			break;
		}
	}

}


Order::~Order()
{
	// Delete all dynamically allocated Orderitem objects
	for (int i = 0; i < m_counter_order_item; i++)
	{
		delete m_orderitems[i];
	}
	// Free the memory allocated for the m_orderitems array
	delete[] m_orderitems;
}

istream& operator>>(istream& in, Order& order)
{
	int product_id;
	cout << "Enter producr ID: ";
	cin >> product_id;

	//order.ptr_stock.
	return in;
}
ostream& operator<<(ostream& out, Order& order)
{
	out << "ORDER[" << order.m_id << "]: " << endl;
	out << "TOTAL: " << order.get_total() << endl;
	out << "CUSTOMER ID: " << order.ptr_customer->get_id() << endl;
	out << "DATE: " << order.order_date.day << "//" << order.order_date.month << "//" << order.order_date.year << endl;

	for (int i = 0; i < order.m_counter_order_item; ++i)
	{
		out << "======[" << i + 1 << "]========" << endl;
		out << *order.m_orderitems[i];
	}

	return out;
}
