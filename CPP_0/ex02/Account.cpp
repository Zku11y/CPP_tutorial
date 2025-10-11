#include "Account.hpp"
#include <ctime>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int	Account::getNbAccounts(){return _nbAccounts;}
int	Account::getTotalAmount(){return _totalAmount;}
int	Account::getNbDeposits(){return _totalNbDeposits;}
int	Account::getNbWithdrawals(){return _totalNbWithdrawals;}
int Account::checkAmount() const {return _amount;}

Account::Account(int initial_deposit){
    _accountIndex = _nbAccounts++;
    _amount = initial_deposit;
    _totalAmount += _amount;
    _nbDeposits = 0;
    _nbWithdrawals = 0;
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount
        << ";created" << std::endl;
}

Account::~Account(){
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount
        << ";closed" << std::endl;
}

void Account::_displayTimestamp(){
    time_t current = time(NULL);
    struct tm *localTime = localtime(&current);
    std::cout << "[" << (localTime->tm_year + 1900)
        << (localTime->tm_mon) << localTime->tm_mday
        << "_" << localTime->tm_hour << localTime->tm_min
        << localTime->tm_sec << "] ";
}

void Account::displayAccountsInfos(){
    _displayTimestamp();
    std::cout << "accounts:" << _nbAccounts << ";total:" << _totalAmount
        << ";deposits:" << _totalNbDeposits << ";withdrawals:"
        << _totalNbWithdrawals << std::endl;
}

void Account::displayStatus() const {

    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";amount:" << _amount
        << ";deposits:" << _nbDeposits << ";withdrawals:"
        << _nbWithdrawals << std::endl;
}

void Account::makeDeposit(int deposit){
    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
        << ";deposit:" << deposit << ";amount:";
    _amount += deposit;
    _totalAmount += deposit;
    _nbDeposits++;
    _totalNbDeposits++;
    std::cout << _amount << ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal){

    _displayTimestamp();
    std::cout << "index:" << _accountIndex << ";p_amount:" << _amount
        << ";withdrawal:";
    if(_amount - withdrawal < 0)
        return(std::cout << "refused" << std::endl, false);
    _amount -= withdrawal;
    _totalAmount -= withdrawal;
    _nbWithdrawals++;
    _totalNbWithdrawals++;
    std::cout << withdrawal << ";amount:" << _amount << ";nb_withdrawals"
        << _nbWithdrawals << std::endl;
    return true;
}