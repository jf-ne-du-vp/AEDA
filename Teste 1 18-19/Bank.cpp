/*
 * Bank.cpp
 */

#include "Bank.h"
#include <algorithm>
#include <string>

Bank::Bank() {}

void Bank::addAccount(Account *a) {
	accounts.push_back(a);
}

void Bank::addBankOfficer(BankOfficer b){
	bankOfficers.push_back(b);
}

vector<BankOfficer> Bank::getBankOfficers() const {
	return bankOfficers;
}

vector<Account *> Bank::getAccounts() const {
	return accounts;
}


// ----------------------------------------------------------------------------------------------

// a alterar
double Bank::getWithdraw(string cod1) const{
	double levantamento = 0;

    for(size_t i = 0; i < accounts.size(); i++){
        if(accounts[i]->getCodH() == cod1) {
            levantamento += accounts[i]->getWithdraw();
        }
    }

    return levantamento;
}



vector<Account *> Bank::removeBankOfficer(string name){
	vector<Account *> res;
	vector<BankOfficer>::iterator it;

	it = find(bankOfficers.begin(), bankOfficers.end(), name);      //to use find i need to create operator == in bankOfficer

	if(it == bankOfficers.end())
	    return res;

	res=it->getAccounts();
	bankOfficers.erase(it);
	return res;
}



// a alterar
const BankOfficer & Bank::addAccountToBankOfficer(Account *ac, string name) {
    vector<BankOfficer>::iterator it;

    it = find(bankOfficers.begin(), bankOfficers.end(), name);

    if(it == bankOfficers.end())
        throw NoBankOfficerException(name);

    it->addAccount(ac);

    return *it;
}


bool compAccount(const Account  *a1, const Account  *a2){
    if(a1->getBalance()<a2->getBalance())
        return true;
    else if(a1->getBalance()==a2->getBalance() && a1->getCodIBAN()<a2->getCodIBAN())
        return true;

    return false;
}

void Bank::sortAccounts() {
    sort(accounts.begin(), accounts.end(), compAccount);
}



