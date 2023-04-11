#include "CardStackIterator.h"

CardStackIterator::CardStackIterator(vector<Card*> data, int top)
{
	this->data = data;
	this->top = top;
}

bool CardStackIterator::hasNext()
{
	return this->top >= 0;
}

Card* CardStackIterator::next()
{	
	Card* result = this->data.back();
	this->top--;
	this->data.pop_back();
	return result;
}
