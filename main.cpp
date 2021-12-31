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
    
    time_t data1Time;
    TransactionData data1(1.5, "Joe", "Sally", time(&data1Time));
    awesomeCoin.addBlock(data1);

    time_t data2Time;
    TransactionData data2(2, "Joe", "Sally", time(&data2Time));
    awesomeCoin.addBlock(data2);

    awesomeCoin.printChain();
    printf("\nIs chain still valid? %d\n", awesomeCoin.isChainValid());

    /*std::cout<<"Is chain valid?"<<std::endl;
    std::string validMessage = (awesomeCoin.isChainValid()) ? "Is valid" : "Is not valid";
    std::cout<<validMessage<<std::endl;

    Block *hackBlock = awesomeCoin.getLastestBlock();
    hackBlock->data.amount = 10000;
    hackBlock->data.recieverKey = "Julio - from Crypto Enthusiast";

    std::cout<<"Now is the chain still valid?"<<std::endl;
    validMessage = (awesomeCoin.isChainValid()) ? "Is valid" : "Is not valid";
    std::cout<<validMessage<<std::endl;*/
}

