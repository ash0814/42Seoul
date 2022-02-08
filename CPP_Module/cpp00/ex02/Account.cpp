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
	std::cout << "accounts:" << _nbAccounts << ";total:"
	<< _totalAmount <<  ";deposits:" << getNbDeposits() << 
	";withdrawals:" << getNbWithdrawals() << std::endl;
}

Account::Account(int initial_deposit)
{
	_displayTimestamp();
	_totalAmount += initial_deposit;
	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	std::cout << "index:"<< _nbAccounts++ 
	<<";amount:"<< initial_deposit << ";created" << std::endl;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:"<< --_nbAccounts 
	<<";amount:"<< _amount << ";closed" << std::endl;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:"<< _accountIndex << ";p_amount:" << _amount;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << ";deposit:" << deposit << ";amount:" << _amount 
	<< ";nb_deposits:" << _nbDeposits << std::endl;
}

bool Account::makeWithdrawal(int withdrawal)
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex << ";p_amount:" << _amount << ";withdrawal:";
	if (withdrawal <= _amount) {
		std::cout << withdrawal;
		_amount -= withdrawal;
		_totalAmount -= withdrawal;
		_nbWithdrawals++;
		_totalNbWithdrawals++;
		std::cout << ";amount:" << _amount << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
		return true;
	}
	std::cout << "refused" << std::endl;
	return false;
}

int Account::checkAmount(void) const 
{
	return _amount;
}

void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << _accountIndex  << ";amount:"
	<< _amount << ";deposits:" << _nbDeposits << ";withdrawals:"
	<< _nbWithdrawals << std::endl;
}

void Account::_displayTimestamp(void)
{
	time_t t;
	struct tm *info;

	t = time(NULL);
	info = localtime(&t);
	std::cout << "[" << info->tm_year + 1900
	<< std::setfill('0') << std::setw(2) << info->tm_mon + 1
	<< std::setfill('0') << std::setw(2) << info->tm_mday << "_"
	<< std::setfill('0') << std::setw(2) << info->tm_hour
	<< std::setfill('0') << std::setw(2) << info->tm_min
	<< std::setfill('0') << std::setw(2) << info->tm_sec
	<< "] ";
	// std::cout << "[19920104_091532] ";
}

Account::Account(void)
{
}