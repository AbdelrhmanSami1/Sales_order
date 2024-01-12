#pragma once
#include "Customer.h"
#include"Company.h"
#include"Person.h"
class Customers 
{
    int m_count;
    int m_max_num_of_customers;
    Customer** customers;
public:
    //constractor:
    Customers(int);

    int get_count();

    Customer* get_customer(int);
    //////////////////////////
    void add_customer    ();
    void edit_cutomer();
    void delete_customer();

   ////////////////////////////

    //opreator overloading:
    friend ostream& operator<<(ostream& out, const Customers& c);

    //destractor:
    ~Customers();
};

