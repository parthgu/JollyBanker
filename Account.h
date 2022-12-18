#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <string>
#include "Fund.h"
class Account
{
private:
    // Array of client Fund objects.
    Fund funds[10];
    // Unique four-digit identifier.
    std::string id;
    // Name
    std::string firstName, lastName;

public:
    /*
    Default constructors and destructor.
    */
    Account();
    Account(std::string firstName, std::string lastName, std::string id);
    ~Account();

    /**
     * Deposit method for depositing into a Fund.
     * @param f An integer for Fund index.
     * @param amt An integer for deposit amount.
     * @post Returns bool indicating success
     * or failure.
     */
    bool deposit(int f, int amt);
    /**
     * Withdraw method for depositing into a Fund.
     * @param f An integer for Fund index.
     * @param amt An integer for withdraw amount.
     * @post Returns bool indicating success
     * or failure.
     */
    bool withdraw(int f, int amt);
    /**
     * Transfer method for transferring between two Funds.
     * @param f An integer for Fund index.
     * @param f1 An integer for second Fund index.
     * @param amt An integer for transfer amount.
     * @post Returns bool indicating success
     * or failure.
     */
    bool transfer(int f, int f1, int amt);
    /**
     * Transfer method for sending an amount to
     * a different Account Fund.
     * @param f An integer for Fund index.
     * @param amt An integer for transfer amount.
     * @post Returns int representing amount
     * sent.
     */
    int transferSend(int f, int amt);
    /**
     * Transfer method for receiving an amount from
     * a different Account Fund.
     * @param f An integer for Fund index.
     * @param amt An integer for transfer amount.
     * @post Returns bool indicating success
     * or failure.
     */
    bool transferReceive(int f, int amt);
    /**
     * Method for retrieving first name.
     * @post Returns string representing
     * Account first name.
     */
    std::string getFirstName() const;
    /**
     * Method for retrieving last name.
     * @post Returns string representing
     * Account first name.
     */
    std::string getLastName() const;
    /**
     * Method for retrieving ID.
     * @post Returns string representing
     * Account first name.
     */
    std::string getId() const;

    /**
     * Method for retrieving balance of
     * a Fund.
     * @param f An integer for Fund index.
     * @post Returns int representing balance
     * amount.
     */
    int getBalance(int f) const;
    /**
     * Method for retrieving the name
     * of a Fund.
     * @param f An integer for Fund index.
     * @post Returns string representing
     * Fund name.
     */
    std::string getNameOfFund(int f);
    /**
     * Method for retrieving a Fund.
     * @param f An integer for Fund index.
     * @post Returns Fund reference.
     */
    Fund &getFund(int f);
    /**
     * Method for viewing overall
     * account Transaction history.
     */
    void viewHistory() const;
    /**
     * Method for viewing
     * Transaction history from
     * specific Fund
     * @param f An integer for Fund index.
     */
    void viewHistory(int f) const;
    /**
     * Method for adding a Transaction to a
     * Fund's history.
     * @param f An integer for Fund index.
     * @param toAdd A Transaction object to
     * add to the Fund history.
     */
    bool addHistory(int f, Transaction toAdd);
    /**
     * '<<' operator overload for displaying Account
     * information.
     * @param OUT An ostream object reference.
     * @param a A constant Account object reference.
     */
    friend ostream &operator<<(ostream &OUT, const Account &a);
};

#endif // ACCOUNT_H