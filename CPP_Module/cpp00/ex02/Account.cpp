#include "./Account.hpp"
#include <time.h>

#include <iomanip>
#include <iostream>

//private
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

//public
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
// [19920104_091532] accounts:8;total:20049;deposits:0;withdrawals:0
void Account::displayAccountsInfos(void)
{
	_displayTimestamp();
	std::cout << "accounts:" << _nbAccounts << ";total:"
	<< _totalAmount <<  ";deposits:" << Account::getNbDeposits() << 
	";withdrawals:" << Account::getNbWithdrawals() << std::endl;
}


// [19920104_091532] index:0;amount:42;created
Account::Account(int initial_deposit)
{
	_displayTimestamp();
	_totalAmount += initial_deposit;
	Account::_accountIndex = _nbAccounts;
	Account::_amount = initial_deposit;
	std::cout << "index:"<< _nbAccounts++ 
	<<";amount:"<< initial_deposit << ";created" << std::endl;
}

Account::~Account( void )
{
	_displayTimestamp();
	std::cout << "index:"<< --_nbAccounts 
	<<";amount:"<< Account::_amount << ";closed" << std::endl;
}

void Account::makeDeposit(int deposit)
{
	_displayTimestamp();
	std::cout << "index:"<< Account::_accountIndex << ";p_amount:" << _amount;
	_amount += deposit;
	_totalAmount += deposit;
	_nbDeposits++;
	_totalNbDeposits++;
	std::cout << ";deposit:" << deposit << ";amount:" << _amount 
	<< ";nb_deposits:" << _nbDeposits << std::endl;
}
// [19920104_091532] index:1;p_amount:819;withdrawal:34;amount:785;nb_withdrawals:1
// [19920104_091532] index:0;p_amount:47;withdrawal:refused
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
	return 1;
}
// [19920104_091532] index:0;amount:42;deposits:0;withdrawals:0
void Account::displayStatus(void) const
{
	_displayTimestamp();
	std::cout << "index:" << Account::_accountIndex  << ";amount:"
	<< Account::_amount << ";deposits:" << _nbDeposits << ";withdrawals:"
	<< _nbWithdrawals << std::endl;
}


//private
void Account::_displayTimestamp(void)
{
	// time_t t;
	// struct tm *info;

	// t = time(NULL);
	// info = localtime(&t);
	// std::cout << "[" << info->tm_year + 1900
	// << std::setfill('0') << std::setw(2) << info->tm_mon + 1
	// << std::setfill('0') << std::setw(2) << info->tm_mday << "_"
	// << std::setfill('0') << std::setw(2) << info->tm_hour
	// << std::setfill('0') << std::setw(2) << info->tm_min
	// << std::setfill('0') << std::setw(2) << info->tm_sec
	// << "] ";
	std::cout << "[19920104_091532] ";
}

Account::Account(void)
{
}