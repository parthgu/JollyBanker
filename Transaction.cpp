// Transaction.cpp
/*
Author(s): Alex Covaci
Class: CSS 342 C Aut 22
Description: Transaction hold 9 data values.
It holds first and last name, transaction type,
account ID, fund ID, account ID of recipient,
fund ID of recipient, amount, and a boolean
representing if the transaction failed
*/

#include "Transaction.h"

Transaction::Transaction()
{
}

Transaction::~Transaction()
{
}

Transaction::Transaction(char typeOfTransaction, string firstName, string lastName, int accountNumber)
{
    this->transactionType = typeOfTransaction;
    this->firstName = firstName;
    this->lastName = lastName;
    this->accountID = accountNumber;
    this->failed = false;
}

Transaction::Transaction(char typeOfTransaction, int accountNo)
{
    this->transactionType = typeOfTransaction;
    this->accountID = accountNo;
    this->failed = false;
}

Transaction::Transaction(char typeOfTransaction, int accountNo, int fundNo)
{
    this->transactionType = typeOfTransaction;
    this->accountID = accountNo;
    this->fundID = fundNo;
    this->failed = false;
}

Transaction::Transaction(char typeOfTransaction, int accountNo, int fundNo, int amount)
{
    this->transactionType = typeOfTransaction;
    this->accountID = accountNo;
    this->fundID = fundNo;
    this->amount = amount;
    this->failed = false;
}

Transaction::Transaction(char typeOfTransaction, int accountNo, int fundNo, int amount, int transferToAccount, int transferToFund)
{
    this->transactionType = typeOfTransaction;
    this->accountID = accountNo;
    this->transferToAccountID = transferToAccount;
    this->fundID = fundNo;
    this->transferToFundID = transferToFund;
    this->amount = amount;
    this->failed = false;
}

char Transaction::getTransactionType() const
{
    return transactionType;
}

string Transaction::getFirstName() const
{
    return firstName;
}

string Transaction::getLastName() const
{
    return lastName;
}

int Transaction::getAccountID() const
{
    return accountID;
}

int Transaction::getTransferToAccountID() const
{
    return transferToAccountID;
}

int Transaction::getFundID() const
{
    return fundID;
}

int Transaction::getTransferToFundID() const
{
    return transferToFundID;
}

int Transaction::getAmount() const
{
    return amount;
}

void Transaction::setFailed(bool isFailed)
{
    this->failed = true;
}

bool Transaction::isFailed() const
{
    return this->failed;
}

void Transaction::setFirstName(std::string firstName)
{
    this->firstName = firstName;
}

void Transaction::setLastName(std::string lastName)
{
    this->lastName = lastName;
}

void Transaction::setName(std::string firstName, std::string lastName)
{
    this->firstName = firstName;
    this->lastName = lastName;
}
