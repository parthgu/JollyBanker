#ifndef BANKER_H
#define BANKER_H

#pragma once

#include "AccountTree.h"
#include "TransactionReader.h"
#include "Transaction.h"
// #include "Account.h"
#include <queue>
#include <fstream>
#include <iostream>

class Banker
{
private:
	// BST that stores all accounts
	AccountTree accounts;

	// queue that hold pending transactions
	queue<Transaction> *transactionQueue;

	// reader that fills transaction queue
	TransactionReader reader;

public:
	// constructors
	Banker();
	Banker(string fileName);
	~Banker();

	// utility methods

	/**
	 * read Reads the file from the path passed to the fuction
	 *
	 * @param fileName string of the file path of desired file to read
	 * @post returns boolean value depending on if the file was found and read
	 */
	bool read(string fileName);

	/**
	 * execute Completes all transaction in the transactionQueue
	 *
	 * @post Completes all transactions in the transactionQueue
	 */
	bool execute();

	/**
	 * openAccount Attempts to open an account with data passed to function
	 *
	 * @param firstName First name of the account being opened
	 * @param lastName Last name of te account being opened
	 * @param ID 4 digit ID of the account being opened
	 * @post Returns false if account ID already exists, returns true if account is new and is inserted
	 */
	bool openAccount(std::string firstName, std::string lastName, string ID);

	/**
	 * viewHistory(Account) Prints to console history of all funds, in the account passed to function
	 *
	 * @param a Account of which the history will be printed
	 */
	void viewHistory(const Account &a);

	/**
	 * viewHistory(Account, int) Prints to console history of specific fund of account based on parameters
	 *
	 * @param a Account of which the history will be printed
	 * @param fund 0-9 value declaring of what fund the history will be printed
	 */
	void viewHistory(const Account &a, int fund);

	/**
	 * transferFund Transfers funds from a fund in one account to a fund in another account
	 *
	 * @pre Both account a and b are not null
	 * @param a Account which funds will be removed from
	 * @param fundA Fund ID of account a which funds will be removed from
	 * @param b Account which funds will be tranfered to
	 * @param fundB Fund ID of account which will receive funds
	 * @param amount amount of funds that will be transfered
	 * @post returns boolean representing if transaction was successful
	 */
	bool transferFunds(Account &a, int fundA, Account &b, int fundB, int amount);

	/**
	 * deposit Adds funds to the specific fund of account passed to function
	 *
	 * @param a Account which funds will be deposited to
	 * @param fund ID of fund that will be deposited to
	 * @param amount Amount of funds that will be deposited
	 * @post Returns a boolean based on if transaction was successful
	 */
	bool deposit(Account &a, int fund, int amount);

	/**
	 * withdraw Removes funds to the specific fund of account passed to function
	 *
	 * @param a Account which funds will be withdrawn from
	 * @param fund ID of fund that will be deposited to
	 * @param amount Amount of funds that will be deposited
	 * @post Returns a boolean based on if transaction was successful
	 */
	bool withdraw(Account &a, int fund, int amount);

	/**
	 * processOpen
	 */
	void processOpen(Transaction toDo);

	/**
	 * processDeposit
	 */
	void processDeposit(Transaction toDo, Account *a);

	/**
	 * processWithdraw
	 */
	void processWithdrawl(Transaction toDo, Account *a);

	/**
	 * processTransfer
	 */
	void processTransfer(Transaction toDo, Account *a);

	/**
	 * processHistory
	 */
	void processHistory(Transaction toDo, Account *a);

	/**
	 * main Main function for running the program
	 */
	int main(int argc, char **argv);
};

#endif
