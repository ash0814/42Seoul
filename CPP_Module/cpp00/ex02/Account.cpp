#include "./Account.hpp"
#include <time.h>

#include <iomanip>
#include <iostream>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

int Account::getNbAccounts( void )
{
	return _nbAccounts;
}

int Account::getTotalAmount(void)
{
	return _totalAmount;
}

int Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
}

Account::Account(int initial_deposit)
{
	std::cout << initial_deposit << "; created" << std::endl;
}

Account::~Account( void )
{
	std::cout << "delete " << _amount << std::endl;
}

void Account::makeDeposit(int deposit)
{
	std::cout << "make deposit : " << deposit << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	return withdrawal;
}

int Account::checkAmount(void) const 
{
	return 1;
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
}

void Account::_displayTimestamp(void)
{
	std::cout << "[19920104_091532] \n";
}

Account::Account(void)
{
	std::cout << _accountIndex << "amount: "<< _amount << ";\n";
}