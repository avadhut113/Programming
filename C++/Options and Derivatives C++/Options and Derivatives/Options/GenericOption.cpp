#include "GenericOption.h"

GenericOption::GenericOption(Option_Type optionType, double strikePrice, double cost):m_OptionType(optionType)
																					 , m_StrikePrice(strikePrice)
																					 , m_Cost(cost)
{
}

GenericOption::GenericOption(const GenericOption& genOption) : m_OptionType(genOption.m_OptionType)
															 , m_StrikePrice(genOption.m_StrikePrice) 
															 , m_Cost(genOption.m_Cost)
{
}

GenericOption& GenericOption::operator=(const GenericOption& genOption)
{
	if (this != &genOption) {
		m_OptionType = genOption.m_OptionType;
		m_StrikePrice = genOption.m_StrikePrice;
		m_Cost = genOption.m_Cost;
	}
	return *this;
}

double GenericOption::valueAtExpiration(double underlyingAssetAtExpiration)
{
	double  value{ 0.0 };
	if (m_OptionType == Option_Type::call) {
		if (m_StrikePrice < underlyingAssetAtExpiration)
			value = underlyingAssetAtExpiration - m_StrikePrice;
	}
	else {
		if (m_StrikePrice > underlyingAssetAtExpiration)
			value = m_StrikePrice - underlyingAssetAtExpiration;
 	}
	return 0.0;
}

double GenericOption::profitAtExpiration(double underlyingAssetAtExpiration)
{
	double value{ 0.0 };
	double finalValue = valueAtExpiration(underlyingAssetAtExpiration);
	if (finalValue > m_Cost)
		value = finalValue - m_Cost;
	return value;
}
