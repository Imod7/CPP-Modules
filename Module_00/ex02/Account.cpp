/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   Account.cpp                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: dsaripap <dsaripap@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2021/10/14 20:38:30 by dsaripap      #+#    #+#                 */
/*   Updated: 2021/11/16 17:10:04 by dsaripap      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Account.hpp"

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

Account::Account(int initial_deposit): _amount(initial_deposit) {
  _accountIndex = _nbAccounts;
  _nbDeposits = 0;
  _nbWithdrawals = 0;

  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";";
  std::cout << "amount:" << _amount << ";";
  std::cout << "created";
  std::cout << std::endl;

  _nbAccounts += 1;
  _totalAmount += _amount;
}

Account::~Account(void) {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex;
  std::cout << ";" << "amount:" << _amount << ";";
  std::cout << "closed" << std::endl;
}

int   Account::getNbAccounts(void) {
  return _nbAccounts;
}

int   Account::getTotalAmount(void) {
    return _totalAmount;
}

int   Account::getNbDeposits(void) {
  return _totalNbDeposits;
}

int   Account::getNbWithdrawals(void) {
  return _totalNbWithdrawals;
}

void  Account::displayAccountsInfos(void) {
  _displayTimestamp();
  std::cout << "accounts:" << Account::getNbAccounts() << ";";
  std::cout << "total:" << Account::getTotalAmount() << ";";
  std::cout << "deposits:" << Account::getNbDeposits() << ";";
  std::cout << "withdrawals:" << Account::getNbWithdrawals();
  std::cout << std::endl;
}

void  Account::makeDeposit(int deposit) {
  this->_nbDeposits += 1;

  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";";
  std::cout << "p_amount:" << _amount << ";";
  _amount = _amount + deposit;
  std::cout << "deposit:" << deposit << ";";
  std::cout << "amount:" << _amount << ";";
  std::cout << "nb_deposits:" << _nbDeposits;
  std::cout << std::endl;

  _totalAmount += deposit;
  _totalNbDeposits += 1;
}

bool  Account::makeWithdrawal(int withdrawal) {
  _displayTimestamp();

  std::cout << "index:" << _accountIndex << ";";
  std::cout << "p_amount:" << _amount << ";";
  std::cout << "withdrawal:";
  if (withdrawal > _amount) {
    std::cout << "refused";
  } else {
    _nbWithdrawals += 1;

    std::cout << withdrawal << ";";
    _amount = _amount - withdrawal;
    std::cout << "amount:" << _amount << ";";
    std::cout << "nb_withdrawals:" << _nbWithdrawals;

    _totalAmount -= withdrawal;
    _totalNbWithdrawals += 1;
  }
  std::cout << std::endl;
  return true;
}

void  Account::displayStatus(void) const {
  _displayTimestamp();
  std::cout << "index:" << _accountIndex << ";";
  std::cout << "amount:" << _amount << ";";
  std::cout << "deposits:" << _nbDeposits << ";";
  std::cout << "withdrawals:" << _nbWithdrawals;
  std::cout << std::endl;
  getTotalAmount();
}

void  Account::_displayTimestamp(void) {
  std::time_t rawtime;
  struct tm * timeinfo;
  char buffer[20];

  std::time(&rawtime);
  timeinfo = std::localtime(&rawtime);

  std::strftime(buffer, 20, "[%Y%m%d_%H%M%S] ", timeinfo);
  std::cout << buffer;
}
