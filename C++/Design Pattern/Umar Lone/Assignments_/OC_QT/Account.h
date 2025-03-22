#pragma once
enum AccountType{SAVINGS, FIXED};
class Account
{
	AccountType m_Type{} ;
	float m_Balance{} ;
	float m_InterestRate{} ;
	float m_MinAvgBalance{} ;
public:
	Account(AccountType type, float balance);
	float Balance()const ;
	void AccumulateInterest() ;
	void Withdraw(float amount) ;
	void Deposit(float amount) ;
};

