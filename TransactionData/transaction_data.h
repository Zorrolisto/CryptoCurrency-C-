#ifndef transaction_data_H
#define transaction_data_H

#include <ctime>
#include <iostream>

struct TransactionData{
    double amount;
    std::string senderKey;
    std::string recieverKey;
    time_t timestamp;
};

#endif
