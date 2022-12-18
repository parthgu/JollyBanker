/*
Author(s):Parth Gupta
Class: CSS 342 C Aut 22
Description: Fund hold 4 data members.
It stores the balance in the fund, name
of the fund, ID of the fund, and the
transaction history of the fund. Fund has
methods that allow of deposit/withdrawl,
displaying history, and displaying the fund.
*/

#include "Fund.h"

Fund::Fund()
{
    this->balance = 0;
}

Fund::Fund(char fundID, std::string fundName)
{
    this->fundID = fundID;
    this->name = fundName;
    this->balance = 0;
}

Fund::~Fund() {}

int Fund::getBalance() const
{
    return this->balance;
}

char Fund::getFundID() const
{
    return this->fundID;
}

std::string Fund::getName() const
{
    return this->name;
}

vector<Transaction> Fund::getHistory()
{
    return this->history;
}

bool Fund::deposit(int amountToDeposit)
{
    if (amountToDeposit < 0) // cannot deposit a negative value
        return false;
    this->balance += amountToDeposit;
    return true;
}

bool Fund::withdraw(int amountToWithdraw)
{
    if (amountToWithdraw < 0)
        return false;
    if (this->balance - amountToWithdraw < 0)
        return false;

    this->balance -= amountToWithdraw;
    return true;
}

bool Fund::addTransaction(Transaction trans)
{
    this->history.push_back(trans);
    return true;
}

void Fund::displayHistory() const
{
    for (int i = 0; i < this->history.size(); i++)
    {
        // transaction type
        char type = this->history[i].getTransactionType();

        // first account id and fund id
        int account1ID = this->history[i].getAccountID();
        int account1Fund = this->history[i].getFundID();

        // amount of transaction
        int amount = this->history[i].getAmount();

        // second account id and fund id
        int account2ID = this->history[i].getTransferToAccountID();
        int account2Fund = this->history[i].getTransferToFundID();

        // print minimum details of transaction
        cout << "  " << type << " " << account1ID << account1Fund << " " << amount;

        // if type transfer, print second account id and second fund id
        if (type == 'T')
        {
            cout << " " << account2ID << account2Fund;
        }

        // if transaction failed, print failed
        if (this->history[i].isFailed())
            cout << " (Failed)";
        cout << endl;
    }
}

int Fund::getHistorySize() const
{
    return this->history.size();
}

bool Fund::operator<(const Fund &other) const
{
    return (this->balance < other.balance);
}

bool Fund::operator>(const Fund &other) const
{
    return (this->balance > other.balance);
}

bool Fund::operator<=(const Fund &other) const
{
    return (this->balance <= other.balance);
}

bool Fund::operator>=(const Fund &other) const
{
    return (this->balance >= other.balance);
}

bool Fund::operator==(const Fund &other) const
{
    return (this->balance == other.balance);
}

ostream &operator<<(ostream &OUT, const Fund &other)
{
    OUT << other.name << ": $" << other.balance;
    return OUT;
}
