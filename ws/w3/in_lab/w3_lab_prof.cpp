#include <iostream>
#include "Book.h"
#include "Book.h"

using namespace std;
using namespace sict;

int main()
{
	cout << "Book Management App" << endl;
	cout << "===================" << endl;

	Book aBook;

	cout << "Testing that validation and display are correct:" << endl;
	cout << "------------------------------------------------" << endl;
	aBook.set("Frank", "Herbert", "Dune", 91780441172719LL);
	aBook.display();
	cout << "The Book::isEmpty() should return true --> "
	     << (aBook.isEmpty() ? "correct" : "incorrect") << endl;

	aBook.set("Frank", "Herbert", "Dune", 980441172719LL);
	aBook.display();
	cout << "The Book::isEmpty() should return true --> "
		<< (aBook.isEmpty() ? "correct" : "incorrect") << endl;

	aBook.set("Frank", "Herbert", "Dune", 9780441172719LL);
	aBook.display();
	cout << "The Book::isEmpty() should return false --> "
		<< (aBook.isEmpty() ? "incorrect" : "correct") << endl;

	return 0;
}