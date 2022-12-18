/*
Author(s): Parth Gupta & Oliver Schwab
Class: CSS 342 C Aut 22
Description: Banker is passed an input file
with each line being a command the banker needs
to execute. Banker can open accounts each with
10 individual funds, deposit to account funds,
withdraw from account funds, transfer funds
from one fund to another, and display the
transaction history of different accounts/funds
*/

#include "Banker.h"
#include "TransactionReader.h"
#include "Account.h"

int main(int argc, char **argv)
{
	Banker b1;
	if (argc != 2)
	{
		cerr << "ERROR: Invalid amount of arguments." << endl;
		return 1;
	}
	b1.read(argv[1]);
	b1.execute();
	return 0;
}

Banker::Banker()
{
	this->transactionQueue = new queue<Transaction>;
	// TBD
}

Banker::Banker(std::string fileName)
{
	this->transactionQueue = new queue<Transaction>;
	// TBD
}

Banker::~Banker()
{
	// TBD
}

bool Banker::read(std::string fileName)
{
	// create transaction reader using fileName
	reader = TransactionReader(this->transactionQueue);

	// reads fileName, and fills transaction queue
	return (reader.read(fileName));
}

bool Banker::execute()
{
	// while there are transactions in queue
	while (!transactionQueue->empty())
	{
		Transaction toDo = transactionQueue->front(); // transaction at front of queue
		Account *a;

		switch (toDo.getTransactionType())
		{
		case 'O':
			this->processOpen(toDo);
			break;
		case 'D':
			this->processDeposit(toDo, a);
			break;
		case 'W':
			this->processWithdrawl(toDo, a);
			break;
		case 'T':
			this->processTransfer(toDo, a);
			break;
		case 'H':
			this->processHistory(toDo, a);
			break;
		}
		transactionQueue->pop(); // remove transaction from front of queue
	}
	// display final balances of all accounts
	cout << "Processing Done. Final Balances" << endl;
	this->accounts.Display();
	return true;
}

bool Banker::openAccount(std::string firstName, std::string lastName, std::string ID)
{
	Account *newAccount = new Account(firstName, lastName, ID);
	if (this->accounts.Insert(newAccount)) // if account can be inserted in accountTree
		return true;
	delete newAccount;
	return false;
}

void Banker::viewHistory(const Account &a)
{
	a.viewHistory(); // view history of all funds in account a
}

void Banker::viewHistory(const Account &a, int fund)
{
	a.viewHistory(fund); // view history of specific fund in account a
}

bool Banker::transferFunds(Account &a, int fundA, Account &b, int fundB, int amount)
{
	if (a.withdraw(fundA, amount))
	{
		return (b.deposit(fundB, amount));
	}
	return false;
}

bool Banker::deposit(Account &a, int fund, int amount)
{
	return a.deposit(fund, amount);
}

bool Banker::withdraw(Account &a, int fund, int amount)
{
	return a.withdraw(fund, amount);
}

void Banker::processOpen(Transaction toDo)
{
	if (this->openAccount(toDo.getFirstName(), toDo.getLastName(), to_string(toDo.getAccountID())) == false) // account is already open
	{
		cerr << "ERROR: Account " << toDo.getAccountID() << " is already open. Transaction Failed." << endl;
		toDo.setFailed(true);
	}
}

void Banker::processDeposit(Transaction toDo, Account *a)
{
	if (!this->accounts.Retrieve(toDo.getAccountID(), a)) // account does not exist
	{
		cerr << "ERROR: Account " << toDo.getAccountID() << " not found. Deposit refused." << endl;
		toDo.setFailed(true);
	}
	else if (!a->deposit(toDo.getFundID(), toDo.getAmount())) // deposit is not valid
	{
		cerr << "ERROR: Invalid deposit of " << toDo.getAmount() << " to " << a->getFirstName() << " " << a->getLastName() << " " << a->getNameOfFund(toDo.getFundID()) << endl;
		toDo.setFailed(true);
	}
	a->addHistory(toDo.getFundID(), toDo); // add transaction to history
}

void Banker::processWithdrawl(Transaction toDo, Account *a)
{
	if (!this->accounts.Retrieve(toDo.getAccountID(), a)) // account does not exist
	{
		cerr << "ERROR: Account " << toDo.getAccountID() << " not found. Withdrawal refused." << endl;
		toDo.setFailed(true);
	}
	else if (!a->withdraw(toDo.getFundID(), toDo.getAmount())) // withdrawl is invalid
	{
		cerr << "ERROR: Not Enough funds to withdraw " << toDo.getAmount() << " from " << a->getFirstName() << " " << a->getLastName() << " " << a->getNameOfFund(toDo.getFundID()) << endl;
		toDo.setFailed(true);
	}
	a->addHistory(toDo.getFundID(), toDo); // add transaction to history
}

void Banker::processTransfer(Transaction toDo, Account *a)
{
	Account *a2;																					// account to transfer funds to
	if (!this->accounts.Retrieve(toDo.getAccountID(), a)) // account 1 does not exist
	{
		cerr << "ERROR: Account " << toDo.getAccountID() << " not found. Transferal refused." << endl;
		toDo.setFailed(true);
	}
	else if (!this->accounts.Retrieve(toDo.getTransferToAccountID(), a2)) // account 2 is not found
	{
		cerr << "ERROR: Account " << toDo.getTransferToAccountID() << " not found. Transferal refused." << endl;
		toDo.setFailed(true);
		return;
	}
	else if (!this->transferFunds(*a, toDo.getFundID(), *a2, toDo.getTransferToFundID(), toDo.getAmount())) // transfer is invalid
	{
		cerr << "ERROR: Invalid transfer of amount " << toDo.getAmount() << " from " << a->getFirstName() << " " << a->getLastName()
				 << " " << a->getNameOfFund(toDo.getFundID()) << " to " << a2->getFirstName() << " " << a2->getLastName() << " " << a2->getNameOfFund(toDo.getTransferToFundID()) << endl;
		toDo.setFailed(true);
	}
	a2->addHistory(toDo.getTransferToFundID(), toDo); // add transaction to history of account 2
}

void Banker::processHistory(Transaction toDo, Account *a)
{
	if (!this->accounts.Retrieve(toDo.getAccountID(), a)) // account does not exist
	{
		cerr << "ERROR: Account " << toDo.getAccountID() << " not found. History request refused." << endl;
		return;
	}
	cout << "Transaction History for " << a->getFirstName() << " " << a->getLastName() << " ";
	if (toDo.getFundID() < 0 || toDo.getFundID() > 9)
	{
		cout << "by fund." << endl;
		a->viewHistory();
	}
	else
	{
		cout << a->getFund(toDo.getFundID()) << endl;
		a->viewHistory(toDo.getFundID());
	}
}