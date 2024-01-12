#include "Payment.h"

Payment::Payment() :paid_date(0, 0, 0), amount(0.0)
{
}

double Payment::get_amount()
{
	return amount;
}

void Payment::set_payment()
{
	char c;
	cout << "ENTER DATE[DD/MM/Y]: " << endl;
	cin >> paid_date.day >> c >> paid_date.month >> c >> paid_date.year;

	cout << "ENTER AMOUNT: ";
	cin >> amount;

}



void Payment::set_amount(double amount)
{
	this->amount = amount;
}
