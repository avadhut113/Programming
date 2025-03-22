#pragma once

enum class Option_Type
{
	call = 0,
	put
};

class GenericOption
{
	Option_Type m_OptionType;
	double m_StrikePrice;
	double m_Cost;
public:
	GenericOption(Option_Type optionType, double strikePrice, double cost);
	GenericOption(const GenericOption& genOption);
	GenericOption& operator=(const GenericOption& genOption);
	double valueAtExpiration(double underlyingAssetAtExpiration);
	double profitAtExpiration(double underlyingAssetAtExpiration);
	~GenericOption() = default;
};

