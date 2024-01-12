#pragma once
#include "Payment.h"
class Check :
    public Payment
{
    string name;
    string bank_id;

public:
    Check();

    void set_payment();
    void dispaly_payment();
    void update();
};

