#include "Card.h"

Card::Card(string number, string symbol)
{
	this->number = number;
	this->symbol = symbol;
}

string Card::getNumber()
{
	return this->number;
}

string Card::getSymbol()
{
	return this->symbol;
}
