#ifndef transaction_data_H
#define transaction_data_H

#include <ctime>
#include <iostream>

struct TransactionData{
    double amount;
    std::string senderKey;
    std::string recieverKey;
    time_t timestamp;

    TransactionData(){};

    TransactionData(double amt, std::string sender, std::string receiver, std::time_t time){
        amount = amt;
        senderKey = sender;
        recieverKey = receiver;
        timestamp = time;
    };
};

#endif
