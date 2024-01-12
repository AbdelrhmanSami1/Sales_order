#include<iostream>
#include<windows.h>
using namespace std;
#include "Sales.h"
    
Sales sales;
   


    // MAIN MENU:
    int main_menu()
    {
        int option;

        cout << "==========[MAIN MENU]=========" << endl;
        cout << "| 1. CUSTOMERS MANAGEMENT     |" << endl;
        cout << "| 2. PRODUCT LIST MANAGEMENT  |" << endl;
        cout << "| 3. STOCK MANAGEMENT         |" << endl;
        cout << "| 4. ORDERS MANAGEMENT        |" << endl;
        cout << "| 5. TRANSACTION MANAGEMENT   |" << endl;
        cout << "| 0. EXIT                     |" << endl;
        cout << "===============================" << endl;

        cout << "ENTER YOUR OPTION [ ]\b\b";
        cin >> option;

        return option;
    }

    //MANAGE CUSTOMER LIST:
    void customers_manu()
    {



        int option;
        while(true)
        {
            cout << "=====[CUSTOMER MANAGEMENT]=====" << endl;
            cout << "| 1. ADD CUSTOMER              |" << endl;
            cout << "| 2. DEIT CUSTOMER             |" << endl;
            cout << "| 3. PRINT CUSTOMER            |" << endl;
            cout << "| 4. PRINT ALL CUSTOMER        |" << endl;
            cout << "| 5. DELETE CUSTOMER           |" << endl;
            cout << "| 0. MAIN MENU                 |" << endl;
            cout << "================================" << endl;

            cout << "ENTER YOUR OPTION [ ]\b\b";
            cin >> option;

            switch (option) {
            case 1:
                sales.add_customer();
                break;
            case 2:
                sales.edit_cutomer();
                break;
            case 3:
                sales.display_customer();
                break;
            case 4:
                sales.display_all_customer();
                break;
            case 5:
                sales.delete_customer();
                break;
            case 0:
                return;
            default:
                cout << "INVALID OPTION SELECTED" << endl;
                break;
            }

        }
    }
    

    //MANAGE PRODUCT LIST:
    
    void product_list_manu()
    {
        int option;
        int product_id;
        while (true)
        {
         //   Sleep(1000);
           // system("cls");


            cout << "=====[PRODUCT MANAJEMENT]=====" << endl;
            cout << "| 1. ADD PRODUCT              |" << endl;
            cout << "| 2. EDIT PRODUCT             |" << endl;
            cout << "| 3. DELETE PRODUCT           |" << endl;
            cout << "| 4. PRINT PRODUCT            |" << endl;
            cout << "| 5. PRINT ALL PRODUCTS       |" << endl;
            cout << "| 6. MAIN MENU                |" << endl;
            cout << "==============================" << endl;

            cout << "ENTER YOUR OPTION [ ]\b\b";
            cin >> option;


            switch (option)
            {
            case 1:
                sales.add_product();
                break;
            case 2:
                sales.edit_product();
                break;
            case 3:
                sales.delete_product();
                break;
            case 4:
                sales.display_product();
                break;
            case 5:
                sales.display_all_product();
                break;
            case 6:
                return;
            default:
                cout << "ENTER VALID OPTION" << endl;
                break;
            }
        }
    }
    
    // MANAGE STOCCK:

    void stock_manu()
    {
        int option;
        int product_id;
        int quantity;
        while (true)
        {
            cout << "=====[STOCK MANAJEMENT]=====" << endl;
            cout << "| 1. ADD STOCK                |" << endl;
            cout << "| 2. UPDATE STOCK             |" << endl;
            cout << "| 3. DELETE STOCK             |" << endl;
            cout << "| 4. GET STOCK                |" << endl;
            cout << "| 5. PRINT STOCK              |" << endl;
            cout << "| 6. MAIN MENU                |" << endl;
            cout << "==============================" << endl;

            cout << "ENTER YOUR OPTION [ ]\b\b";
            cin >> option;

            switch (option)
            {
            case 1:
                sales.add_stock();
                break;
            case 2:
                sales.update_stock();
                break;
            case 3:
                sales.delete_stock();
                break;
            case 4:
                sales.get_quantity();
                break;
            case 5:
                sales.display_stock();
                break;
            case 6:
                return;
            default:
                cout << "ENTER VALID OPTION" << endl;
                break;
            }

        }
    }
    

    // MANAGE ORDERS:

    void orders_manu()
    {
        int option;
        int id;

        while (true)
        {
            cout << "=====[ORDERS MANAJEMENT]=====" << endl;
            cout << "| 1. CREATE ORDE              |" << endl;
            cout << "| 2. EDIT ORDER               |" << endl;
            cout << "| 3. DELETE ORDER             |" << endl;
            cout << "| 4. UPDATE ORDER             |" << endl;
            cout << "| 5. PRINT ORDER              |" << endl;
            cout << "| 6. PRINT ALL ORDER          |" << endl;
            cout << "| 7. MAIN MENU                |" << endl;
            cout << "==============================" << endl;

            cout << "ENTER YOUR OPTION [ ]\b\b";
            cin >> option;

            switch (option)
            {
            case 1:
                sales.creatr_order();
                break;
            case 2:
                sales.edit_order();
                break;
            case 3:
                sales.delete_order();
                break;
            case 4:
                sales.update_order();
                break;
            case 5:
                sales.display_order();
                break;
            case 6:
                sales.display_all_order();
                break;
            case 7:
                return;
            default:
                cout << "INVALID OPTION SELECTED" << endl;
                break;
            }

        }
    }
    

    //MANAGE TRANSACTION
    void tra_manu()
    {
        int option;
        int id;

        while (true)
        {
            cout << "===[TRANSACTION MANAJEMENT]===" << endl;
            cout << "| 1. CREATE TRANSACTION       |" << endl;
            cout << "| 2. EDIT TRANSACTION         |" << endl;
            cout << "| 3. DELETE TRANSACTION       |" << endl;
            cout << "| 4. PRINT TRANSACTION        |" << endl;
            cout << "| 5. PRINT ALL TRANSACTION    |" << endl;
            cout << "| 0. MAIN MENU                |" << endl;
            cout << "==============================" << endl;

            cout << "ENTER YOUR OPTION [ ]\b\b";
            cin >> option;

            switch (option)
            {
            case 1:
                sales.create_tra();
                break;
            case 2:
                sales.edit_tra();
                break;
            case 3:
                sales.delete_tra();
                break;
            case 4:
                sales.display_tra();
                break;
            case 5:
                sales.display_all_tra();
                break;
            case 0:
                return;
            default:
                cout << "ENTER INVALID OPTION" << endl;
                break;
            }

        }
    }

    int main()
    {

        system("Color 72");


    
    
        
        while (true)
        {
            int menu_option;
            menu_option = main_menu();

            switch (menu_option)
            {
            case 1:
                customers_manu();
                break;
            case 2:
             
                product_list_manu();
                break;
            case 3:
                 stock_manu();
                break;
            case 4:
                orders_manu();
                break;
            case 5:
                tra_manu();
                break;
            case 0:
                return 0;
            default:
                cout << "ENTER INVALID NUMBER" << endl;
                break;
            }
        }
    }

  

