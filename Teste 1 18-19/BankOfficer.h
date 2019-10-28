/*
 * BankOfficer.h
 */

#ifndef SRC_BANKOFFICER_H_
#define SRC_BANKOFFICER_H_

#include "Account.h"
#include <string>
#include <vector>

class NoBankOfficerException{
public:
    string name;
    NoBankOfficerException(const string & name);
    string getName() const;
};

class BankOfficer {
	unsigned int id;
	static unsigned int number;
	string name;
	vector<Account *> myAccounts;
public:
	BankOfficer();
	void setName(string nm);
	void addAccount(Account *a);
	void addAccount(vector<Account *> accounts);
	string getName() const;
	vector<Account *> getAccounts() const;
	unsigned int getID() const;
	static unsigned int getNumber() {return number;}


	//-------
	BankOfficer(string nm);
	vector<Account *> removeBankOfficer(string name);

	bool operator == (const string & name) const;
	bool operator > (const BankOfficer & bO) const;
};

#endif /* SRC_BANKOFFICER_H_ */
