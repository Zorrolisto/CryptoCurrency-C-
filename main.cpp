#include <ctime>
#include <vector>
#include <iostream>

struct TransactionData{
    double amount;
    std::string senderKey;
    std::string recieverKey;
    time_t timestamp;
};

class Block{
    private:
        int index;
        size_t blockHash;
        size_t previousHash;
        size_t generateHash();

    public:
        Block(int idx, TransactionData d, size_t prevHash);
        size_t getOriginalHash();
        size_t getPreviousHash();
        TransactionData data;
        bool isHashValid();
};

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

