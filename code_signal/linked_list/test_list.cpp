#include "linked_list.hpp"

int main(int argv, char **argc){
	List *a = new List(nullptr, 0);
	for(int i = 0 ; i < 5 ; i++){
		Node *b = new Node(2 * i, nullptr);
		a->appendNode(b);
	}
	a->printList();
	a->prependNode(new Node(1, nullptr) );
	a->printList();
}
