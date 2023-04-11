#pragma once
#include <string>

using namespace std;

class Card{
private:
	string number;
	string symbol;
public:
	Card(string number, string symbol);
	string getNumber();
	string getSymbol();
};

