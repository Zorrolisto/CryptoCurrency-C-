#ifndef block_H
#define block_H

#include"../TransactionData/transaction_data.h"

#include <ctime>
#include <iostream>

class Block{
    private:
        int index;
        size_t blockHash;
        size_t previousHash;
        size_t generateHash();

    public:
        Block(int idx, TransactionData d, size_t prevHash);
        int getIndex();
        size_t getOriginalHash();
        size_t getPreviousHash();
        TransactionData data;
        bool isHashValid();
};

#endif
