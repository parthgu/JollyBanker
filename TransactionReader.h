#ifndef TRANSACTION_READER_H
#define TRANSACTION_READER_H
#include "Transaction.h"
#include <queue>
#include <iostream>
#include <fstream>
#include <cerrno>

class TransactionReader {
private: 
    /*
    'readerQueue' holds the address to Banker's 
    'transactionQueue'.
    */
    std::queue<Transaction> * readerQueue;
public:
    /**
     * Default Constructor.
    */
    TransactionReader();
    /**
     * Parameterized Constructor
     * @param queue<Transaction> Address of Banker class queue.
    */    
    TransactionReader(queue<Transaction> * transactionQueue);
    /**
     * Method for reading file input.
     * @param std::string Name of file to be read.
     * @post bool Indicates success or failure.
    */
    bool read(std::string file);
    /**
     * Method for creating Transaction objects from file 
     * input.
     * @param std::string Line from input file.
    */
    void defineTransaction(std::string line);
    /**
     * Method for creating a Deposit or Withdrawal 
     * Transaction object.
     * @param std::string Line from input file.
     * @post char Type of transaction.
    */
    Transaction& defineDepositWithdrawal(std::string line, char type);
    /**
     * Method for creating an Account Open Transaction object.
     * @param std::string Line from input file.
     * @post char Type of transaction.
    */
    Transaction& defineAccountOpen(std::string line, char type);
    /**
     * Method for creating a Transfer Transaction Object.
     * @param std::string Line from input file.
     * @post char Type of transaction.
    */
    Transaction& defineFundTransfer(std::string line, char type);
    /**
     * Method for creating a History Query Transaction Object.
     * @param std::string Line from input file.
     * @post char Type of transaction.
    */
    Transaction& defineHistoryQuery(std::string line, char type);

};

#endif //TRANSACTION_READER_H