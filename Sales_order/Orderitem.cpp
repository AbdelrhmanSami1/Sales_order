#include "Orderitem.h"

Orderitem::Orderitem(product_quantity& const p) :m_sale_price(0.0), m_quantity(0.0),flag(1)
{
    ptr_product_quantity = &p;
}

void Orderitem::set_sale_price(double sale_price)
{
    m_sale_price = sale_price;
}

void Orderitem::set_quantity(double quantity)
{
    m_quantity = quantity;
}

double Orderitem::get_sale_price()
{
    return m_sale_price;
}

double Orderitem::get_quantity()
{
    return m_quantity;
}

double Orderitem::get_amount()
{
    
    return amount;
}

void Orderitem::delete_item()
{
    ptr_product_quantity->quantity += m_quantity;
}

bool Orderitem::if_quntity()
{
    return flag;
}

void Orderitem::update_quantity(double quantity)
{
    flag = 1;
    // Check if order quantity less than or equla quantity of product in stock
    if (ptr_product_quantity->quantity < quantity - m_quantity)
    {
        cout << "QUANTITY DSOEN'T EXIST IN STOCK" << endl;
        flag = 0;
        return;
        
    }
    
    // Edit quantity of product in the stock 
    ptr_product_quantity->quantity += m_quantity;
    ptr_product_quantity->quantity -= quantity;

    //Edit quantity in order item:
    m_quantity = quantity;


    amount = 0.0;
    amount = m_sale_price * m_quantity;
}

Orderitem Orderitem::operator++()
{
    // Check if order quantity less than or equla quantity of product in stock
    if (ptr_product_quantity->quantity <= 0)
    {
        cout << "Thia quantity dosen't exist in the stock" << endl;
        return *this;
    }
    // Edit quantity in order item:
    m_quantity++;
    // Edit quantity of product in the stock: 
    ptr_product_quantity->quantity--;

    amount = 0.0;
    amount = m_sale_price * m_quantity;
    return *this;
}

Orderitem Orderitem::operator--()
{
    //Edit quantity in order item:
    m_quantity--;
    // Edit quantity of product in the stock 
    ptr_product_quantity->quantity++;

    amount = 0.0;
    amount = m_sale_price * m_quantity;
    return *this;
}

Orderitem Orderitem::operator+=(int quantity)
{
    // Check if order quantity less than or equla quantity of product in stock
    if (ptr_product_quantity->quantity < quantity)
    {
        cout << "Thia quantity dosen't exist in the stock" << endl;
        return *this;
    }
    //Edit quantity in order item:
    m_quantity+=quantity;
    // Edit quantity of product in the stock 
    ptr_product_quantity->quantity -= quantity;

    amount = 0.0;
    amount = m_sale_price * m_quantity;
    return *this;
}

Orderitem Orderitem::operator-=(int quantity)
{
    //Edit quantity in order item:
    m_quantity -= quantity;
    // Edit quantity of product in the stock 
    ptr_product_quantity->quantity += quantity;
    cout << "quantity:" << quantity << endl;
    cout << "stock:" << ptr_product_quantity->quantity << endl;


    amount = 0.0;
    amount = m_sale_price * m_quantity;

    return *this;
}

ostream& operator<<(ostream& out, Orderitem& const orderitem)
{
    out << "PRODUCT ID: " << setw(10) << orderitem.ptr_product_quantity->ptr_prduct->get_id() << " | ";
    out << "PRODUCT NAME: " << setw(15) << orderitem.ptr_product_quantity->ptr_prduct->get_name() << " | ";
    out << "QUANTITY: " << setw(8) << orderitem.m_quantity << " | ";
    out << "SALE PRICE: " << setw(10) << orderitem.m_sale_price << " | ";
    out << "TOTAL: " << setw(10) << orderitem.m_quantity * orderitem.m_sale_price << endl;
    out << "-------------------------------------------------------------------------------------------" << endl;
    return out;
}
