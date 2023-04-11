#pragma once
#include <vector>
#include "Card.h"

using namespace std;

class CardStackIterator
{
private:
	vector<Card*> data;
	int top;
public:
	CardStackIterator(vector<Card*> data, int top);
	bool hasNext();
	Card* next();
};

