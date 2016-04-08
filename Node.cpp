struct Node
{
	// Structs can have constructors too!
	//Node() : left(NULL), right(NULL) {}
	vector<*Node> ChildNodes;
	Node(){

	}
	Node(int children){
		for(int i = 0; i < children; i++){
			Node node;
			ChildNodes.push_back(node);
		}
	}
	Node* left;
	Node* right;
	char value;
};
