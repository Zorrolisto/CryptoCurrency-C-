#include"./TransactionData/transaction_data.h"
#include"./Block/block.h"
#include"./Block/block_func_decl.h"
#include"./Blockchain/blockchain.h"
#include"./Blockchain/blockchain_func_decl.h"

#include <ctime>
#include <vector>
#include <iostream>


int main(){
    Blockchain awesomeCoin;
    
    TransactionData data1;
    time_t data1Time;
    data1.amount = 1.5;
    data1.recieverKey = "Julio";
    data1.senderKey = "Joe";
    data1.timestamp = time(&data1Time);

    awesomeCoin.addBlock(data1);

    std::cout<<"Is chain valid?"<<std::endl;
    std::string validMessage = (awesomeCoin.isChainValid()) ? "Is valid" : "Is not valid";
    std::cout<<validMessage<<std::endl;

    Block *hackBlock = awesomeCoin.getLastestBlock();
    hackBlock->data.amount = 10000;
    hackBlock->data.recieverKey = "Julio - from Crypto Enthusiast";

    std::cout<<"Now is the chain still valid?"<<std::endl;
    validMessage = (awesomeCoin.isChainValid()) ? "Is valid" : "Is not valid";
    std::cout<<validMessage<<std::endl;
}

