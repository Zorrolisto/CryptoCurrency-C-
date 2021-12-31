#ifndef block_func_decl_H
#define block_func_decl_H

#include"../TransactionData/transaction_data.h"
#include"block.h"

#include <ctime>
#include <vector>
#include <iostream>

Block::Block(int idx, TransactionData d, size_t prevHash){
    index = idx;
    data = d;
    previousHash = prevHash;
    blockHash = generateHash();
}

size_t Block::generateHash(){
    std::string toHash = std::to_string(data.amount) + data.recieverKey + data.senderKey + std::to_string(data.timestamp);
    std::hash<std::string> transactionDataHash;
    std::hash<std::string> prevHash;

    return transactionDataHash(toHash) ^ (prevHash(std::to_string(previousHash)) << 1);
}
size_t Block::getOriginalHash(){
    return blockHash;
}
int Block::getIndex(){
    return index;
}
size_t Block::getPreviousHash(){
    return previousHash;
}
bool Block::isHashValid(){
    return generateHash() == getOriginalHash();
}

#endif
