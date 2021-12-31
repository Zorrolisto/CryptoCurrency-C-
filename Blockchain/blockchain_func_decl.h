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

std::vector<Block> Blockchain::getChain(){
    return publicChain;
}
Block Blockchain::createGenesisBlock(){
    std::time_t current;
    TransactionData d(0, "Genesis", "Genesis", time(&current));

    std::hash<int> hash1;
    Block genesis(0, d, hash1(0));
    return genesis;
}

// Only for demo purposes!!
Block *Blockchain::getLastestBlock(){
    return &publicChain.back();
}

void Blockchain::addBlock(TransactionData d){
    int index = (int)publicChain.size();
    std::size_t previousHash = (int)publicChain.size() > 0 ? getLastestBlock()->getOriginalHash() : 0;
    Block newBlock(index, d, previousHash);
    publicChain.push_back(newBlock);
}

bool Blockchain::isChainValid(){
    std::vector<Block>::iterator it;
    bool isValid = true;
    bool isInvalid = false;

    for (it = publicChain.begin(); it != publicChain.end(); ++it){
        Block currentBlock = *it;
        if(!currentBlock.isHashValid()){
            return isInvalid;
        }

        if(it != publicChain.begin()){
            Block previousBlock = *(it - 1);
            if(currentBlock.getPreviousHash() != previousBlock.getOriginalHash()){
                return isInvalid;
            }
        }
    }
    return isValid;
}
void Blockchain::printChain(){
    std::vector<Block>::iterator it;
    for (it = publicChain.begin(); it != publicChain.end(); ++it){
        Block currentBlock = *it;
        printf("\n\nBlock =====================================");
        printf("\nIndex: %d", currentBlock.getIndex());
        printf("\nAmount: %f", currentBlock.data.amount);
        printf("\nSenderKey: %s", currentBlock.data.senderKey.c_str());
        printf("\nReceiverKey: %s", currentBlock.data.recieverKey.c_str());
        printf("\nTimestamp: %ld", currentBlock.data.timestamp);
        printf("\nHash: %zu", currentBlock.getOriginalHash());
        printf("\nPrevious Hash: %zu", currentBlock.getPreviousHash());
        printf("\nIs Block Valid: %d", currentBlock.isHashValid());
    }
}

#endif
