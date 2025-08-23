/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Account.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kearmand <kearmand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/22 12:30:06 by kearmand          #+#    #+#             */
/*   Updated: 2025/08/22 13:25:49 by kearmand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Account.hpp"
#include <iostream>
#include <ctime>

/***
 * Static attributes
 */
int Account::_nbAccounts        = 0;
int Account::_totalAmount       = 0;
int Account::_totalNbDeposits   = 0;
int Account::_totalNbWithdrawals= 0;

Account::Account( int initial_deposit )
:_accountIndex(Account::_nbAccounts),
 _amount(initial_deposit),
 _nbDeposits(0),
 _nbWithdrawals(0)
{
	_displayTimestamp();
	Account::_nbAccounts++;
	Account::_totalAmount += initial_deposit;
	std::cout << "index:" << this->_accountIndex << ";amount:" << this->_amount << ";created" << std::endl;
};

Account::~Account( void )
{
	_displayTimestamp();
	--(Account::_nbAccounts);
	Account::_totalAmount -= this->_amount;
	std::cout << "index:" << this->_accountIndex 
			  << ";amount:" << this->_amount << ";closed" << std::endl;
}



/***
 * Static member functions
 */

void Account::_displayTimestamp( void )
{
	//TEST FOR CORRECTION
	// std::cout << "[19920104_091532] ";

	
	std::time_t now = std::time(0);
	std::tm *ltm = std::localtime(&now);

	char buf[32];
	std::strftime(buf, sizeof(buf), "[%Y%m%d_%H%M%S] ", ltm);
	std::cout << buf;
}

int Account::getNbAccounts( void )
{
	return (Account::_nbAccounts);
}

int Account::getTotalAmount( void )
{
	return (Account::_totalAmount);
};
int Account::getNbDeposits( void )
{
	return (Account::_totalNbDeposits);
};

int Account::getNbWithdrawals( void )
{
	return (Account::_totalNbWithdrawals);
};

void Account::displayAccountsInfos( void )
{
	_displayTimestamp();
	std::cout << "accounts:" << getNbAccounts() 
		<< ";total:" << getTotalAmount() 
		<< ";deposits:" << getNbDeposits() 
		<< ";withdrawals:" << getNbWithdrawals() 
		<< std::endl;
};

/***
 * Non-static member functions
 */

void Account::makeDeposit( int deposit ) {
	_displayTimestamp();
	this->_amount += deposit;
	this->_nbDeposits++;
	Account::_totalAmount += deposit;
	Account::_totalNbDeposits++;
	std::cout << "index:" << this->_accountIndex 
		<< ";p_amount:" << this->_amount - deposit 
		<< ";deposit:" << deposit 
		<< ";amount:" << this->_amount 
		<< ";nb_deposits:" << this->_nbDeposits 
		<< std::endl;
}

void Account::displayStatus( void ) const
{
	_displayTimestamp();
	std::cout << "index:" << this->_accountIndex 
		<< ";amount:" << this->_amount 
		<< ";deposits:" << this->_nbDeposits 
		<< ";withdrawals:" << this->_nbWithdrawals 
		<< std::endl;
}

bool Account::makeWithdrawal( int withdrawal )
{
	_displayTimestamp();
	if (this->_amount < withdrawal)
	{
		std::cout << "index:" << this->_accountIndex 
			<< ";p_amount:" << this->_amount 
			<< ";withdrawal:refused" 
			<< std::endl;
		return (false);
	}
	this->_amount -= withdrawal;
	this->_nbWithdrawals++;
	Account::_totalAmount -= withdrawal;
	Account::_totalNbWithdrawals++;
	std::cout << "index:" << this->_accountIndex 
		<< ";p_amount:" << this->_amount + withdrawal 
		<< ";withdrawal:" << withdrawal 
		<< ";amount:" << this->_amount 
		<< ";nb_withdrawals:" << this->_nbWithdrawals 
		<< std::endl;
	return (true);
}
