/*
Author(s): Oliver Schwab & Parth Gupta
Class: CSS 342 C Aut 22
Description: TransactionReader reads the
input from the file and make Transaction
objects out of each line. Then, it
stores these objects in the Banker class
queue using a queue pointer.
*/

#ifndef TRANSACTION_READER_CPP
#define TRANSACTION_READER_CPP

#include "TransactionReader.h"

TransactionReader::TransactionReader() {}

TransactionReader::TransactionReader(std::queue<Transaction> *transactionQueue)
{
    readerQueue = transactionQueue;
}

bool TransactionReader::read(std::string fileName)
{

    std::ifstream inFile;
    /*
    ifstream is opened using input file,
    and each line is parsed to make
    a Transaction object.
    */
    inFile.open(fileName);

    if (inFile.fail())
    {
        std::cerr << "File incompatible." << std::endl;
        return false;
    }

    std::string line;
    while (std::getline(inFile, line))
    {
        defineTransaction(line);
    }
    inFile.close();
    return true;
}

void TransactionReader::defineTransaction(std::string line)
{
    /*
    Different Transaction types are
    considered given the char indicator
    recieved.
    */
    Transaction t;
    char type = line[0];
    if (type == 'D' || type == 'W')
    {
        t = defineDepositWithdrawal(line, type);
    }
    else if (type == 'T')
    {
        t = defineFundTransfer(line, type);
    }
    else if (type == 'H')
    {
        t = defineHistoryQuery(line, type);
    }
    else if (type == 'O')
    {
        t = defineAccountOpen(line, type);
    }

    readerQueue->push(t);
}

Transaction &TransactionReader::defineDepositWithdrawal(std::string line, char type)
{
    std::string accountId;
    std::string amt;
    char f;

    int i;
    /*
    Account ID is parsed.
    */
    for (i = 2; i < 6; i++)
    {
        accountId += line[i];
    }
    /*
    Fund index is obtained.
    */
    f = line[i];
    /*
    Deposit / Withdrawal amount is parsed.
    */
    for (i += 2; i < line.size(); i++)
    {
        if (!isdigit(line.at(i)))
            break;
        amt += line[i];
    }
    /*
    Transaction object is made to be pushed to queue.
    stoi() is used to convert strings to int, and the
    expression 'f- '0'' is used to properly format
    the Fund index to base 10.
    */
    Transaction *new_T = new Transaction(type, std::stoi(accountId), f - '0', std::stoi(amt));
    return *new_T;
}

Transaction &TransactionReader::defineAccountOpen(std::string line, char type)
{
    std::string firstName;
    std::string lastName;
    std::string accountId;

    int i;
    /*
    First name of new Account is parsed.
    */
    for (i = 2; i < line.size(); i++)
    {
        if (line[i] == ' ')
        {
            break;
        }
        lastName += line[i];
    }
    /*
    Last name of Account is parsed.
    */
    for (i += 1; i < line.size(); i++)
    {
        if (line[i] == ' ')
        {
            break;
        }
        firstName += line[i];
    }
    /*
    Account ID is parsed.
    */
    for (i += 1; i < line.size(); i++)
    {
        if (line[i] == ' ' || !isdigit(line.at(i)))
        {
            break;
        }
        accountId += line[i];
    }
    /*
    Transaction object is made to be pushed to queue.
    stoi() is used to convert string to int.
    */
    Transaction *new_T = new Transaction(type, firstName, lastName, std::stoi(accountId));
    return *new_T;
}

Transaction &TransactionReader::defineFundTransfer(std::string line, char type)
{
    Transaction *new_T;
    std::string accountId_1 = "";
    std::string accountId_2 = "";
    int fund_index_1;
    int fund_index_2;
    std::string amt;
    /*
    Transfers follow this format:
        [Transaction Type] [Account Number (Fund index as last integer)] [Amount]
        [Account Number (Fund index as last integer)]
    */
    int i;
    /*
    First Account ID parsed.
    */
    for (i = 2; i < 6; i++)
    {
        accountId_1 += line[i];
    }
    /*
    First Fund index is located.
    */
    fund_index_1 = stoi(to_string(line[i]));
    /*
    Transfer amount is parsed.
    */
    for (i += 2; i < line.size(); i++)
    {
        if (line[i] == ' ')
        {
            break;
        }
        amt += line[i];
    }
    /*
    Second Account ID is parsed.
    */
    for (i += 1; i < line.size(); i++)
    {
        if (i == line.size() - 1 || accountId_2.length() == 4)
        {
            break;
        }
        accountId_2 += line[i];
    }
    /*
    Second Fund index is located.
    */
    fund_index_2 = stoi(to_string(line[i]));
    /*
    Transaction object is made to be pushed to queue.
    stoi() is used to convert strings to int, and the
    expression 'f- '0'' is used to properly format
    the Fund index to base 10.
    */
    new_T = new Transaction(type, std::stoi(accountId_1), fund_index_1 - '0',
                            std::stoi(amt), std::stoi(accountId_2), fund_index_2 - '0');
    return *new_T;
}

Transaction &TransactionReader::defineHistoryQuery(std::string line, char type)
{
    Transaction *new_T;
    std::string account;
    /*
    Account ID is parsed.
    */
    for (int i = 2; i < line.size(); i++)
    {
        if (!isdigit(line.at(i)))
            break;
        account += line[i];
    }

    /*
    If the ID has 5 characters, then extract the
    Fund index from the end of the query.
    Otherwise, make a Transaction with the
    four character Account ID.
    */
    if (account.size() == 5)
    {
        int f_index = account[account.size() - 1];
        account.erase(account.size() - 1);
        new_T = new Transaction(type, std::stoi(account), f_index - 48);
        return *new_T;
    }
    /*
    Transaction object is made to be pushed to queue.
    stoi() is used to convert string to int.
    */
    new_T = new Transaction(type, std::stoi(account), -1);
    return *new_T;
}

#endif // TRANSACTION_READER_CPP