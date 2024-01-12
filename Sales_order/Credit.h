#pragma once
#include "Payment.h"
class Credit :
    public Payment
{
    string number;
    date expire_date;
    string type;
public:
    Credit();

    void set_payment();
    void dispaly_payment();
    void update();
};

