/*
 * Account.cpp
 */
#include <iostream>
#include "Account.h"
using namespace std;


Account::Account(string hold, string codeH, string codeA, double bal): holder(hold), codeHolder(codeH), codeIBAN(codeA), balance(bal) {}

Account::~Account(){ }

string Account::getCodH() const {
	return codeHolder;
}

string Account::getCodIBAN() const {
	return codeIBAN;
}

double Account::getBalance() const {
	return balance;
}

double Account::getWithdraw() const {
    return getBalance();
}

bool Account::operator<(const Account &a2) {
    return this->balance < a2.balance;
}

SavingsAccount::SavingsAccount (string hold, string codeH, string codeA, double bal, double pct):
		Account(hold, codeH, codeA, bal), rate(pct/100)
{ }

double SavingsAccount::getRate() const {
    return this->rate;
}

double SavingsAccount::getCharge() const {
    if(getRate()*100 > 2.0)
        return 0.8;

    return 0.0;
}


CheckingAccount::CheckingAccount(string hold, string codeH, string codeA, double bal,double lim):
			Account(hold, codeH, codeA, bal) {
	limit = lim;
}

double CheckingAccount::getLimit() const {
    return this->limit;
}

double CheckingAccount::getCharge() const {

    if(getLimit() <= 500)
        return 0.5;
    else if(500 < getLimit() && getLimit() <= 1000)
        return 0.25;


    return 0.0;

}


TimeAccount::TimeAccount(string hold, string codeH, string codeA, double bal, double pct):
			SavingsAccount(hold, codeH, codeA, bal, pct) {
	funds_avail = balance*rate;
}

double TimeAccount::getWithdraw() const {
    return Account::getWithdraw()*getRate();
}




