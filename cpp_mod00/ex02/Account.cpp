#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

void printimestamp()
{
    std::time_t now = std::time(nullptr);
    std::tm *parts = std::localtime(&now);
    std::cout << "[" << std::put_time(parts, "%Y%m%d_%H%M%S") << "]"; 
    return ;
}

int	Account::getNbAccounts(void)
{
	return (Account::_nbAccounts);
}

int	Account::getTotalAmount(void)
{
	return (Account::_totalAmount);
}

int	Account::getNbDeposits(void)
{
	return (Account::_totalNbDeposits);
}

int	Account::getNbWithdrawals(void)
{
	return (Account::_totalNbWithdrawals);
}

Account::Account(int initial_deposit)
{
    _accountIndex = getNbAccounts();
    _amount = initial_deposit;
    _nbWithdrawals = 0;
    _nbDeposits = 0;
    _nbAccounts++;
    _totalAmount = _totalAmount + initial_deposit;
    printimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

Account::~Account()
{
    printimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

void Account::displayAccountsInfos()
{
    printimestamp();
    std::cout << " accounts:" << getNbAccounts() << ";total:" << getTotalAmount()
    << ";deposits:" << getNbDeposits()
    << ";withdrawals:" << getNbWithdrawals() << std::endl;
}

/*
// Metodo di deposito
void Account::makeDeposit(int deposit) {
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";p_amount:" << _amount
              << ";deposit:" << deposit;
    _amount += deposit;
    _nbDeposits++;
    _totalAmount += deposit;
    _totalNbDeposits++;
    std::cout << ";amount:" << _amount
              << ";nb_deposits:" << _nbDeposits << std::endl;
}

// Metodo di prelievo
bool Account::makeWithdrawal(int withdrawal) {
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";p_amount:" << _amount;
    if (withdrawal > _amount) {
        std::cout << ";withdrawal:refused" << std::endl;
        return false;
    }
    _amount -= withdrawal;
    _nbWithdrawals++;
    _totalAmount -= withdrawal;
    _totalNbWithdrawals++;
    std::cout << ";withdrawal:" << withdrawal
              << ";amount:" << _amount
              << ";nb_withdrawals:" << _nbWithdrawals << std::endl;
    return true;
}

// Metodo per visualizzare lo stato dell'account
void Account::displayStatus() const {
    _displayTimestamp();
    std::cout << " index:" << _accountIndex
              << ";amount:" << _amount
              << ";deposits:" << _nbDeposits
              << ";withdrawals:" << _nbWithdrawals << std::endl;
}

// Metodo per controllare l'importo
int Account::checkAmount() const {
    return _amount;
}

// Metodo privato per visualizzare il timestamp
void Account::_displayTimestamp() {
    std::time_t now = std::time(nullptr);
    std::tm *ptm = std::localtime(&now);
    std::cout << "[" << (ptm->tm_year + 1900)
              << std::setw(2) << std::setfill('0') << ptm->tm_mon + 1
              << std::setw(2) << std::setfill('0') << ptm->tm_mday << "_"
              << std::setw(2) << std::setfill('0') << ptm->tm_hour
              << std::setw(2) << std::setfill('0') << ptm->tm_min
              << std::setw(2) << std::setfill('0') << ptm->tm_sec << "]";
}
*/