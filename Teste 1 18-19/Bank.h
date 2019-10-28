/*
 * Bank.h
 */

#ifndef SRC_BANK_H_
#define SRC_BANK_H_

#include "Account.h"
#include <vector>

#include "BankOfficer.h"


template<typename T>
unsigned int numberDifferent (const vector<T> & v1){            //there must a easier way to do this!!!!
    vector<T> v2 = v1;

    for(size_t i = 0; i < v1.size(); i++){
        for(size_t j = (i + 1); j< v2.size(); j++){
            if(v1[i] == v2[j])
                v2.erase(v2.begin() + j);
        }
    }

    return v2.size();
}

class Bank {
	vector<Account *> accounts;
	vector<BankOfficer> bankOfficers;
public:
	Bank();
	void addAccount(Account *a);
	void addBankOfficer(BankOfficer b);
	vector<BankOfficer> getBankOfficers() const;
	vector<Account *> getAccounts() const;

	//-------
	double getWithdraw(string cod1) const;
	vector<Account *> removeBankOfficer(string name);
	const BankOfficer& addAccountToBankOfficer(Account *ac, string name);
	void sortAccounts();
};


#endif /* SRC_BANK_H_ */
