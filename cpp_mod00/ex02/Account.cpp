#include "Account.hpp"
#include <iostream>
#include <iomanip>
#include <ctime>

// Inizializzazione delle variabili statiche
int Account::_nbAccounts = 0;
int Account::_totalAmount = 0;
int Account::_totalNbDeposits = 0;
int Account::_totalNbWithdrawals = 0;

// Costruttore
Account::Account(int initial_deposit) 
    : _accountIndex(_nbAccounts), _amount(initial_deposit), _nbDeposits(0), _nbWithdrawals(0) {
    _nbAccounts++;
    _totalAmount += initial_deposit;
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";created" << std::endl;
}

// Distruttore
Account::~Account() {
    _displayTimestamp();
    std::cout << " index:" << _accountIndex << ";amount:" << _amount << ";closed" << std::endl;
}

// Metodi statici
int Account::getNbAccounts() { return _nbAccounts; }
int Account::getTotalAmount() { return _totalAmount; }
int Account::getNbDeposits() { return _totalNbDeposits; }
int Account::getNbWithdrawals() { return _totalNbWithdrawals; }

void Account::displayAccountsInfos() {
    _displayTimestamp();
    std::cout << " accounts:" << _nbAccounts
              << ";total:" << _totalAmount
              << ";deposits:" << _totalNbDeposits
              << ";withdrawals:" << _totalNbWithdrawals << std::endl;
}

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
