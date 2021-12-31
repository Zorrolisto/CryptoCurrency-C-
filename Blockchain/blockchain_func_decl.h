#ifndef blockchain_func_decl_H
#define blockchain_func_decl_H

#include"../TransactionData/transaction_data.h"
#include"../Block/block.h"
#include"../Block/block_func_decl.h"
#include"blockchain.h"

#include <ctime>
#include <vector>
#include <iostream>

Blockchain::Blockchain(){
    Block genesis = createGenesisBlock();
    publicChain.push_back(genesis);
}

Block Blockchain::createGenesisBlock(){
    time_t current;
    TransactionData d;
    d.recieverKey = "None";
    d.senderKey = "None";
    d.timestamp = time(&current);

    std::hash<int> hash1;
    Block genesis(0, d, hash1(0));
    return genesis;
}

// Only for demo purposes!!
Block *Blockchain::getLastestBlock(){
    return &publicChain.back();
}

void Blockchain::addBlock(TransactionData d){
    int index = (int)publicChain.size() - 1;
    Block newBlock(index, d, getLastestBlock()->getOriginalHash());
}

bool Blockchain::isChainValid(){
    std::vector<Block>::iterator it;
    int chainLen = (int)publicChain.size();
    bool isValid = true;
    bool isInvalid = false;

    for (it = publicChain.begin(); it != publicChain.end(); ++it){
        Block currentBlock = *it;
        if(!currentBlock.isHashValid()){
            return isInvalid;
        }

        if(chainLen > 1){
            Block previousBlock = *(it - 1);
            if(currentBlock.getPreviousHash() != previousBlock.getOriginalHash()){
                return isInvalid;
            }
        }
    }
    return isValid;
}

#endif
