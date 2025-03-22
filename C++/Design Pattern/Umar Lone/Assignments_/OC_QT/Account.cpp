#include "Account.h"

#include <cstdio>
#include <exception>

Account::Account(AccountType type, float balance)
	: m_Type{ type },
	m_Balance{ balance }{
	switch (type) {
	case FIXED:
		m_InterestRate = .05f;
		m_MinAvgBalance = 1000;
		break;
	case SAVINGS:
		m_InterestRate = .04f;
		m_MinAvgBalance = 50;
		break;
	}
}

float Account::Balance() const {
	return m_Balance;
}

void Account::AccumulateInterest() {
	m_Balance += m_Balance * m_InterestRate;
}

void Account::Withdraw(float amount) {
//	if (amount > m_Balance)
//	{
//        throw std::exception("Invalid amount");
//	}
	switch (m_Type)
	{
	case SAVINGS:
		if ((m_Balance - amount) < m_MinAvgBalance)
		{
			puts("Balance is less than minimum average balance");
		}//Keep track & deduct fine later
		break;
	case FIXED:
		//Allow withdrawal as a loan only once
		break;
	}

	m_Balance -= amount;
}

void Account::Deposit(float amount) {
	m_Balance += amount ;
}
