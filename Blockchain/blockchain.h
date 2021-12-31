#ifndef blockchain_H
#define blockchain_H

#include"../Block/block.h"
#include"../TransactionData/transaction_data.h"

#include <ctime>
#include <vector>
#include <iostream>

class Blockchain{
    private:
        Block createGenesisBlock();

    public:
        std::vector<Block> publicChain;
        Blockchain();
        void addBlock(TransactionData data);
        bool isChainValid();

        Block *getLastestBlock();
};

#endif
