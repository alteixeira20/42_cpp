#include "../inc/Account.hpp"
#include <ctime>
#include <iostream>
#include <sstream>

// Initialization
int	Account::_nbAccounts = 0;
int	Account::_totalAmount = 0;
int	Account::_totalNbDeposits = 0;
int	Account::_totalNbWithdrawals = 0;

// STDOUT Print Helper
static void	ft_print(const std::string &str, bool endl)
{
	std::cout << str;
	if (endl)
		std::cout << std::endl;
}

// Timestamp Helper
void	Account::_displayTimestamp(void)
{
	std::time_t	now;
	std::tm		*ltm;
	char		buffer[20];

	now = std::time(NULL);
	ltm = std::localtime(&now);
	strftime(buffer, 20, "[%Y%m%d_%H%M%S]", ltm);

	ft_print(buffer, false);
}

// Getters (static)
int	Account::getNbAccounts(void)
{
	return _nbAccounts;
}

int	Account::getTotalAmount(void)
{
	return _totalAmount;
}

int	Account::getNbDeposits(void)
{
	return _totalNbDeposits;
}

int	Account::getNbWithdrawals(void)
{
	return _totalNbWithdrawals;
}

// Print global account Info
void	Account::displayAccountsInfos(void)
{
	std::ostringstream	output;

	output << " accounts:" << getNbAccounts()
		<< ";total:" << getTotalAmount()
		<< ";deposits:" << getNbDeposits()
		<< ";withdrawals:" << getNbWithdrawals();

	_displayTimestamp();
	ft_print(output.str(), true);
}

// Constructor
Account::Account(int initial_deposit)
{
	std::ostringstream	output;

	_accountIndex = _nbAccounts;
	_amount = initial_deposit;
	_nbDeposits = 0;
	_nbWithdrawals = 0;

	_nbAccounts++;
	_totalAmount += initial_deposit;

	output << " index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";created";

	_displayTimestamp();
	ft_print(output.str(), true);
}

// Destructor
Account::~Account(void)
{
	std::ostringstream	output;

	_displayTimestamp();
	output << " index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";closed";
	ft_print(output.str(), true);
}

// Deposit
void	Account::makeDeposit(int deposit)
{
	int			previous;
	std::ostringstream	output;

	previous = _amount;
	_amount += deposit;
	_nbDeposits++;
	
	_totalAmount += deposit;
	_totalNbDeposits++;

	_displayTimestamp();
	output << " index:" << _accountIndex
		<< ";p_amount:" << previous
		<< ";deposit:" << deposit
		<< ";amount:" << _amount
		<< ";nb_deposits:" << _nbDeposits;
	ft_print(output.str(), true);
}

// Withdrawal
bool	Account::makeWithdrawal(int withdrawal)
{
	int			previous;
	std::ostringstream	output;

	previous = _amount;
	if (withdrawal > _amount)
	{
		_displayTimestamp();
		output << " index:" << _accountIndex
			<< ";p_amount:" << previous
			<< ";withdrawal:refused";
		ft_print(output.str(), true);
		return (false);
	}

	_amount -= withdrawal;
	_nbWithdrawals++;

	_totalAmount -= withdrawal;
	_totalNbWithdrawals++;

	_displayTimestamp();
	output << " index:" << _accountIndex
		<< ";p_amount:" << previous
		<< ";withdrawal:" << withdrawal
		<< ";amount:" << _amount
		<< ";nb_withdrawals:" << _nbWithdrawals;
	ft_print(output.str(), true);
	return (true);
}

int	Account::checkAmount(void) const
{
	return _amount;
}

void	Account::displayStatus(void) const
{
	std::ostringstream	output;

	_displayTimestamp();
	output << " index:" << _accountIndex
		<< ";amount:" << _amount
		<< ";deposits:" << _nbDeposits
		<< ";withdrawals:" << _nbWithdrawals;
	ft_print(output.str(), true);
}
