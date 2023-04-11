
#include <iostream>
#include "CardStack.h"
using namespace std;

int main(){
	CardStack* stack = new CardStack(52);
	stack->shuffle();
	CardStackIterator* iterator = stack->getIterator();

	int count = 1;

	while (iterator->hasNext()) {
		Card* card = iterator->next();
		cout << count << ". " << card->getNumber() << " " << card->getSymbol() << endl;
		count++;
	}
}

