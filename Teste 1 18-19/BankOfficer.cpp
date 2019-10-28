/*
 * BankOfficer.cpp
 */
#include "BankOfficer.h"


BankOfficer::BankOfficer(): id(0) {}

void BankOfficer::setName(string nm){
	name = nm;
}

string BankOfficer::getName() const{
	return name;
}

vector<Account *> BankOfficer::getAccounts() const {
	return myAccounts;
}

void BankOfficer::addAccount(Account *a) {
	myAccounts.push_back(a);
}

unsigned int BankOfficer::getID() const{
	return id;
}


// ----------------------------------------------------------------------------------------------

unsigned int BankOfficer::number = 0;


BankOfficer::BankOfficer(string nm): id(++number) {
    name = nm;
}

bool BankOfficer::operator==(const string &name) const {
    return (this->name == name);
}

bool BankOfficer::operator>(const BankOfficer &bO) const {

    if(this->getAccounts().size() == bO.getAccounts().size())
        return this->name > bO.name;

    return this->getAccounts().size() > bO.getAccounts().size();
}

NoBankOfficerException::NoBankOfficerException(const string & name){
    this->name=name;
}

string NoBankOfficerException::getName() const {
    return name;
}







