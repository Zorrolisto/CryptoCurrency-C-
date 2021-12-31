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
    std::hash<std::string> hash1;
    std::hash<size_t> hash2;
    std::hash<size_t> finalHash;
    std::string toHash = std::to_string(data.amount) + data.recieverKey + data.senderKey + std::to_string(data.timestamp);

    return finalHash(hash1(toHash) + hash2(previousHash));
}
size_t Block::getOriginalHash(){
    return blockHash;
}
size_t Block::getPreviousHash(){
    return previousHash;
}
bool Block::isHashValid(){
    return generateHash() == blockHash;
}

#endif
