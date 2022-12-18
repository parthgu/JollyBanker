#ifndef FUND_H
#define FUND_H
#include <iostream>
#include <string>
#include <vector>
#include "Transaction.h"

#pragma once

class Fund
{
private:
	// total amount of money in account
	int balance;

	// name of account
	std::string name;

	// one digit id of fund
	char fundID;

	// vector for transaction history
	vector<Transaction> history;

public:
	// constructor / destructor
	Fund();
	Fund(char fundID, std::string fundName);
	~Fund();

	/**
	 * getBalance Returns an integer representing the overall balance in the fund
	 *
	 * @pre	Fund is not NULL
	 * @post Returns fund balance (int)
	 */
	int getBalance() const;

	/**
	 * getFundID Returns a char representing the fund ID (0 - 9)
	 *
	 * @pre Fund is not NULL
	 * @post Returns the fund ID (char)
	 */
	char getFundID() const;

	/**
	 * getName Returns a string representing the fund name
	 *
	 * @pre Fund is not NULL
	 * @post Returns the fund name (string)
	 */
	std::string getName() const;

	/**
	 * getHistory returns vector of Transaction objects representing the transaction history of the fund
	 *
	 * @pre Fund is not NULL
	 * @post Transaction history is returned (vector<Transaction>)
	 */
	vector<Transaction> getHistory();

	/**
	 * deposit Adds amountToDeposit to the balance of the fund
	 *
	 * @param amountToDeposit the integer amount to add to fund balance
	 * @post False if amountToAdd is negative
	 * @post True if amountToAdd is positive and succesfully added to balance
	 */
	bool deposit(int amountToDeposit);

	/**
	 * withdraw Removes amountToWithdraw from balance
	 *
	 * @param amountToWithdraw Subtracts amountToWithdraw from fund balance
	 * @post false if balance does not have enough funds
	 * @post true if amountToWithdraw successfully withdrawn from fund balance
	 */
	bool withdraw(int amountToWithdraw);

	/**
	 * addTransaction adds trans to the transaction history of the fund
	 *
	 * @param trans Transaction to be added to fund history
	 * @post true if transaction successfully added to history
	 */
	bool addTransaction(Transaction trans);

	/**
	 * displayHistory Prints out transaction history of fund to the console
	 *
	 * @post Transaction history printed to console
	 */
	void displayHistory() const;

	/**
	 * getHistorySize returns the number of transactions in the fund's history
	 *
	 * @pre Fund is not null
	 * @post Returns integer value of number of transaction in the fund's history
	 */
	int getHistorySize() const;

	// operator overloads (Compared via balance)
	bool operator<(const Fund &other) const;
	bool operator>(const Fund &other) const;
	bool operator<=(const Fund &other) const;
	bool operator>=(const Fund &other) const;
	bool operator==(const Fund &other) const;
	friend ostream &operator<<(ostream &OUT, const Fund &other);
};

#endif
