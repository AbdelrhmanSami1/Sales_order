#include "Transaction.h"

Transaction::Transaction(Order& order) :ptr_order(&order), size(10), count(0), total_payment(0.0)
{
	payments = new Payment * [size];
}

void Transaction::payment()
{
	int option;
    if (count >= size)
    {
        size *= 2;
        Payment** temp = new Payment * [size];
        for (int i = 0; i < count; i++)
        {
            temp[i] = payments[i];
        }
        delete[] payments;
        payments = temp;
    }
	cout << "===========[PAYMENT]===========" << endl;
	cout << "| 1. CREDIT                    |" << endl;
	cout << "| 2. CASH                      |" << endl;
	cout << "| 3. CHECK                     |" << endl;
	cout << "| 0. SAVE                      |" << endl;
	cout << "===============================" << endl;
	cout << "ENTER TOUR OPTION[ ]\b\b";
	;
	cin >> option;

	switch (option)
	{
	case 1:
		cout << "PAYMENT CREDIT: " << endl;
		cout << "----------------------\n";
		payments[count] = new Credit;
		payments[count]->set_payment();
		++count;
		break;
	case 2:
		cout << "PAYMENT CASH: " << endl;
		cout << "----------------------\n";
		payments[count] = new Cash;
		payments[count]->set_payment();
		++count;
		break;
	case 3:
		cout << "PAYMENT CHECK: " << endl;
		cout << "----------------------\n";
		payments[count] = new Check;
		payments[count]->set_payment();
		++count;
		break;
	case 0:
		return;
	default:
		cout << "ENTER VALID OPTION" << endl;
		break;
	}

	cout << "BEEN PAID:" << get_total_payment() << endl;
	cout << "------------------------" << endl;
	payments[count - 1]->dispaly_payment();
	cout << "NOT PAID: " << ptr_order->get_total() - get_total_payment() << endl;
     
}

double Transaction::get_total_payment()
{
	total_payment = 0;

	for (int i = 0; i < count; i++)
	{
		total_payment += payments[i]->get_amount();
	}
	return total_payment;
}

int Transaction::get_order_id()
{
	return ptr_order->get_id();
}

void Transaction::edit_payment()
{
	cout << *this;

	int option;
	cout << "ENTER OPTION: ";
	cin >> option;

	payments[option - 1]->update();

}

Transaction::~Transaction()
{

	for (int i = 0; i < count; i++)
	{
		delete payments[i];
	}
	delete[] payments;
}

std::ostream& operator<<(std::ostream& out,  Transaction& t)
{
	out << "ORDER ID: " << t.ptr_order->get_id() << endl;
	out << "BEEN PAID:" << t.get_total_payment() << endl;
	out << "NOT PAID: " << t.ptr_order->get_total() - t.get_total_payment() << endl;
	for (int i = 0; i < t.count; i++)
	{
		out << "=======[" << i + 1 << "]========" << endl;
		t.payments[i]->dispaly_payment();
	}
	return out;
}
