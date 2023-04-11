#pragma once
#include "Card.h"
#include "CardStackIterator.h"
#include <vector>

using namespace std;

class CardStack
{
private:
	int top;
	vector<Card*> data;
public:
	CardStack(int size);
	~CardStack();
	void push(string number, string symbol);
	void push(Card* card);
	Card* pop();
	bool isEmpty();
	void shuffle();
	CardStackIterator* getIterator();
};

