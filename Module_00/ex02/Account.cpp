/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Account.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <dsaripap@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/14 20:38:30 by dsaripap      #+#    #+#                 */
/*   Updated: 2021/10/15 03:34:56 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Account.hpp"

int	Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

Account::Account( int initial_deposit ): _amount(initial_deposit) {
    _accountIndex = _nbAccounts;
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "created";
    std::cout << std::endl;
    
}

Account::~Account( void ) {
    std::cout << "index:" << _accountIndex << ";" << "amount:" << _amount << ";";
    std::cout << "closed" << std::endl;
}

int     Account::getNbAccounts( void ) {
    return _nbAccounts;
}

int     Account::getTotalAmount( void ) {
    return _totalAmount;
}

int     Account::getNbDeposits( void ) {
    return _totalNbDeposits;
}

int     Account::getNbWithdrawals( void ) {
    return _totalNbWithdrawals;
}

void    Account::displayAccountsInfos( void ) {
    std::cout << "accounts:" << Account::getNbAccounts() << ";";
    std::cout << "total:" << Account::getTotalAmount() << ";";
    std::cout << "deposits:" << Account::getNbDeposits() << ";";
    std::cout << "withdrawals:" << Account::getNbWithdrawals();
    std::cout << std::endl;
    return;
}

void	Account::makeDeposit( int deposit ) {
    
    _totalNbDeposits += 1;
    (void)deposit;

    std::cout << "index:" << _accountIndex << ";";
    std::cout << "p_amount:" << _amount << ";";
    std::cout << "deposit:" << _amount << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "nb_deposits" << getNbDeposits();
    std::cout << std::endl;
}

bool	Account::makeWithdrawal( int withdrawal ) {
    
    _totalNbWithdrawals += 1;
    (void)withdrawal;

    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << "deposits:" << getNbDeposits() << ";";
    std::cout << "withdrawals:" << getNbWithdrawals() << ";";
    std::cout << std::endl;
    return true;
}

void	Account::displayStatus( void ) const {
    std::cout << "index:" << _accountIndex << ";";
    std::cout << "amount:" << _amount << ";";
    std::cout << std::endl;
    getTotalAmount();
}
