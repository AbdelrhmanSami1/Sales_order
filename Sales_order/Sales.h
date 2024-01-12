#pragma once
#include"Customer.h"
#include"Company.h"
#include"Person.h"
#include"Product.h"
#include"Stock.h"
#include"Order.h"
#include"Transaction.h"
class Sales
{
    //Customers array:
    int count_customer;
    int size_cutomer;
    Customer** customers;

    /////////////////////////////////

    //Product array:
    int count_product;
    int size_product;
    Product* products;

    ////////////////////////////////

    Stock* stock;

    ////////////////////////////////

    // Oeders array:
    int count_order;
    int size_order;
    Order** orders;

    ////////////////////////////////

    //Transection array:
    int count_tra;
    int size_tra;
    Transaction** transactions;



public:
    Sales();

    //Customers:
    void add_customer();
    void edit_cutomer();
    void delete_customer();
    void display_customer();
    void display_all_customer();

    ////////////////////////////////////

    //Products:
    void add_product();
    void edit_product();
    void delete_product();
    void display_product();
    void display_all_product();

    //Stock:
    void add_stock();
    void update_stock();
    void delete_stock();
    void get_quantity();
    void display_stock();

    //Odrers:
    void creatr_order();
    void edit_order();
    void delete_order();
    void display_order();
    void display_all_order();
    void update_order();

    //Transection:
    void create_tra();
    void edit_tra();
    void delete_tra();
    void display_tra();
    void display_all_tra();

    ~Sales();



};

