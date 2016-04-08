#ifndef GENERALTREE_H_INCLUDED
#define GENERALTREE_H_INCLUDED
#include <vector>
#include <cstdlib>
#include <exception>
using namespace std;

struct Node
{
	// Structs can have constructors too!
	//Node() : left(NULL), right(NULL) {}
	vector<Node*> ChildNodes;
	char value;
	Node(){

	}
	Node(char value){
	    this->value = value;
		/*for(int i = 0; i < children; i++){
			Node node;
			ChildNodes.push_back(node);
		}*/
	}
	Node* left;
	Node* right;
};

class NoParentException : public exception
{
	public:
		const char *what() const throw()
		{
			return "No Parent!";
		}
};

class GeneralTree
{
	public:
		GeneralTree();
		GeneralTree(const GeneralTree& other);
		~GeneralTree();
		GeneralTree& operator=(const GeneralTree& other);
		Node* insert(char value, Node* parent);
		void print() const;
		Node* start;
	protected:

		void copyOther(const GeneralTree& other);
		void clear();
		void printFrom(Node* start) const;
		void copyFrom(Node* start, Node* parent);
		void clearFrom(Node* start);
};

#endif // GENERALTREE_H_INCLUDED
