#include "GeneralTree.h"
#include <vector>
#include <cstdlib>
#include <iostream>
using namespace std;

//default constructor, in which start is NULL
GeneralTree::GeneralTree(){
	this->start = NULL;
}

//constructor for which start is initialized to NULL but
//the tree is then converted to other, using the copyOther
//method
GeneralTree::GeneralTree(const GeneralTree& other){
    this->start = NULL;
    copyOther(other);
}

//destructor, this will print "Destructor successful!"
//if called
GeneralTree::~GeneralTree(){
	clear();
	cout << "Destructor successful!" << endl;
}

//to set the current GeneralTree equal to other, by
//calling the copyOther method and return it
GeneralTree& GeneralTree::operator=(const GeneralTree& other){
    copyOther(other);
    return *this;
}

//insert Node parent with char value into tree
Node* GeneralTree::insert(char value, Node* parent){
    //set the newNode equal to the parent Node
    //and return it
    Node* newNode = new Node(value);
    //throws NoParentException if parent is NULL,and
    //start is not; sets start equal to newNode
    //and return start if start is NULL as well
    //else insert newNode if parent is not NULL
    if(parent == NULL && this->start != NULL){
        delete newNode;
        throw NoParentException();
    } else if(parent == NULL && this->start == NULL){
        this->start = newNode;
        return start;
    } else if(parent != NULL){
        parent->ChildNodes.push_back(newNode);
        return newNode;
    }
}

//prints the whole GeneralTree expression
void GeneralTree::print() const{
    printFrom(this->start);
    cout << endl;
}

//copies the GeneralTree other onto this tree
void GeneralTree::copyOther(const GeneralTree& other){
    copyFrom(other.start, this->start);
}

//clears the whole GeneralTree
void GeneralTree::clear(){
    clearFrom(start);
}

//prints the GeneralTree from Node start and onwards
void GeneralTree::printFrom(Node* start) const{
    if(start == NULL){
        return;
    }
    if(start->value != '.'){
        cout << start->value;
    }

    if(start->ChildNodes.size() > 0){
        cout << "(";
        for(int i = 0; i < start->ChildNodes.size(); i++){
            printFrom(start->ChildNodes.at(i));
        }
        cout << ")";
    }
}

//copies node start onto parent
void GeneralTree::copyFrom(Node* start, Node* parent){
    if (start == NULL) {
		return;
	}
	Node* insertedNode = insert(start->value, parent);
	for(int i = 0; i < start->ChildNodes.size(); i++){
        Node* childNode = start->ChildNodes.at(i);
        copyFrom(childNode, insertedNode);
	}
}

//clears the part of the GeneralTree starting with
//the node start
void GeneralTree::clearFrom(Node* start){
    if(start == NULL){
        return;
    }
    for(int i = 0; i < start->ChildNodes.size(); i++){
        clearFrom(start->ChildNodes.at(i));
    }
    delete start;
}
