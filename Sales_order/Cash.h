#pragma once
#include "Payment.h"
class Cash :
    public Payment
{
    double cash_value;
public:
    Cash();

    void set_payment();
    void dispaly_payment();
    void update();
};

