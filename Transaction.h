// Transaction.h

#ifndef TRANSACTION_H
#define TRANSACTION_H

#pragma once

#include <string>
#include <iostream>

using namespace std;

class Transaction
{
private:
    string firstName;
    string lastName;

    // char representing transaction type (ex. 'O', 'D', W', 'T', 'H')
    char transactionType;

    // Four digit account ID
    int accountID;

    // One digit fund ID (0-9)
    int fundID;

    // Four didit account ID of recipient account
    int transferToAccountID;

    // One digit fund ID (0-9) of recipient account fund
    int transferToFundID;

    // amount of funds of the transaction
    int amount;

    // boolean representing if the transaction failed (true == failed, false == successful)
    bool failed;

public:
    // constructor/destructor
    Transaction();
    ~Transaction();

    /**
     * Constructor (Typically used when opening an account)
     *
     * @param typeOfTransaction Char representing type of transaction
     * @param firstName String of first name of transaction
     * @param lastName String of last name of transaction
     * @param accountNumber 4 digit integer of accountNumber
     */
    Transaction(char typeOfTransaction, string firstName, string lastName, int accountNumber);

    /**
     * Constructor (Typically used history requests)
     *
     * @param typeOfTransaction Char representing type of transaction
     * @param accountNumber 4 digit integer of accountNumber
     */
    Transaction(char typeOfTransaction, int accountNo);

    /**
     * Constructor (Typically used for history requests)
     *
     * @param typeOfTransaction Char representing type of transaction
     * @param accountNumber 4 digit integer of accountNumber
     * @param fundNo Single digit integer of the fund
     */
    Transaction(char typeOfTransaction, int accountNo, int fundNo);

    /**
     * Constructor (Typically used for deposits/withdrawls)
     *
     * @param typeOfTransaction Char representing type of transaction
     * @param accountNumber 4 digit integer of accountNumber
     * @param fundNo Single digit integer of the fund
     * @param amount Amount of funds accosiated with the transaction
     */
    Transaction(char typeOfTransaction, int accountNo, int fundNo, int amount);

    /**
     * Constructor (Typically used for transfers)
     *
     * @param typeOfTransaction Char representing type of transaction
     * @param accountNumber 4 digit integer of accountNumber
     * @param fundNo Single digit integer of the fund
     * @param amount Amount of funds accosiated with the transaction
     * @param transferToAccount 4 digit account ID of recipient account
     * @param transferToFund Single digit fund ID of recipient account fund
     */
    Transaction(char typeOfTransaction, int accountNo, int fundNo, int amount,
                int transferToAccount, int transferToFund);

    // getters
    char getTransactionType() const;
    string getFirstName() const;
    string getLastName() const;
    int getAccountID() const;
    int getTransferToAccountID() const;
    int getFundID() const;
    int getTransferToFundID() const;
    int getAmount() const;
    void setFailed(bool isFailed);
    void setFirstName(std::string firstName);
    void setLastName(std::string lastName);
    void setName(std::string firstName, std::string lastName);
    bool isFailed() const;
};

#endif // TRANSACTION_H
