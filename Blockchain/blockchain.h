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
        std::vector<Block> publicChain;

    public:
        Blockchain();
        std::vector<Block> getChain();
        void addBlock(TransactionData data);
        bool isChainValid();
        void printChain();

        Block *getLastestBlock();
};

#endif
