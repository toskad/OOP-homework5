#include "CardStack.h"
#include <sstream>
#include <random>

vector<string> simple_tokenizer(string s) {
	vector<string> tokens;
	stringstream ss(s);
	string word;
	while (ss >> word) {
		tokens.push_back(word);
	}
	return tokens;
}

int random_number(int a, int b) {
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> distr(a, b);
	
	return distr(gen);
}

CardStack::CardStack(int size)
{
	this->top = size - 1;
	this->data.reserve(size);

	string numbers = "A 2 3 4 5 6 7 8 9 10 J Q K";
	string symbols = "\3 \4 \5 \6";

	vector<string> nums = simple_tokenizer(numbers);
	vector<string> syms = simple_tokenizer(symbols);

	for (int i = 0; i < nums.size(); i++) {
		for (int j = 0; j < syms.size(); j++) {
			this->data.push_back(new Card(nums[i], syms[j]));
		}
	}
}

CardStack::~CardStack()
{
	for (int i = 0; i < this->data.size(); i++) {
		delete this->data[i];
	}
}

void CardStack::push(string number, string symbol)
{
	Card* card = new Card(number, symbol);
	this->top++;
	this->data.push_back(card);
	
}

void CardStack::push(Card* card)
{	
	this->top++;
	this->data.push_back(card);
	
}

Card* CardStack::pop()
{
	if (!this->isEmpty()) {
		Card* card = this->data[this->top];
		this->data.pop_back();
		this->top--;
		return card;
	}
	return nullptr;
}

bool CardStack::isEmpty()
{
	return this->top == -1;
}


void CardStack::shuffle() {
	int rand1;
	int rand2;
	for (int i = 0; i < 100; i++) {
		rand1 = random_number(0, this->data.size() - 1);
		rand2 = random_number(0, this->data.size() - 1);
		swap(this->data[rand1], this->data[rand2]);
	}
}

CardStackIterator* CardStack::getIterator()
{
	return new CardStackIterator(this->data, this->top);
}


