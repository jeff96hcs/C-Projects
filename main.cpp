#include <iostream>
#include "GeneralTree.h"
#include "GeneralTree.cpp"
#include <sstream>
#include <cstdlib>
using namespace std;

void parseRecursive(stringstream& ss, GeneralTree& gt, Node* parent)
{
	char nextChar;
	while (true) {
		ss >> nextChar;
		if (ss.fail())
			return;

		if (nextChar == ')')
			return;

		if (nextChar == '(') {
			Node* newNode = gt.insert(' ', parent);
			parseRecursive(ss, gt, newNode);
		} else {
			gt.insert(nextChar, parent);
		}
	}
}

void parseExpression(const string& expr, GeneralTree& gt)
{
	stringstream ss;
	ss << expr;

	parseRecursive(ss, gt, NULL);
}

int main()
{
	// This should print:
	// (c(ab))
	GeneralTree gt;
	Node* grandparent = gt.insert('.', NULL);
	Node* parent1 = gt.insert('c', grandparent);
	Node* parent2 = gt.insert('.', grandparent);
	Node* kid1 = gt.insert('a', parent2);
	Node* kid2 = gt.insert('b', parent2);
	cout << "gt: ";
	gt.print();

	// This should print:
	// (abab(cd)d(ef(g(h))))
	GeneralTree gt2;
	parseExpression("(abab(cd)d(ef(g(h))))", gt2);
	cout << "gt2: ";
	gt2.print();

	// This should print:
	// (c(ab))
	GeneralTree gt3 = gt;
	cout << "gt3: ";
	gt3.print();

	// This should print:
	// (abab(cd)d(ef(g(h))))
	GeneralTree gt4(gt2);
	cout << "gt4: ";
	gt4.print();
	//testing the NoParentException
	cout << "Inserting a NULL node into gt4 with value 'a'." << endl;
	try{
        gt4.insert('a', NULL);
	}catch(NoParentException npe){
	    cout << "No Parent" << endl;
	}
	//testing the Destructor
	GeneralTree* test = new GeneralTree();
	cout << "Testing Destructor using General Tree test..." << endl;
	delete test;

	return 0;
}

