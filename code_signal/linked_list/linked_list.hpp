#include <iostream>

using namespace std;

class Node{
	Node *next;
	int val;
		
	public:
		Node(int val, Node *next){
			this->next = next;
			this->val = val;
			// cout << "Node created" << endl;
		}
		
		Node(Node *node){
			this->next = node->next;
			this->val = node->val;
			// cout << "Node created" << endl;
		}

		int getVal(){
			return this->val;
		}

		void setVal(int newVal){
			this->val = newVal;;
		}
	 
		Node* getNext(){
	 		return this->next;
	 	}

	 	void setNext(Node *next){
	 		this->next = next;
	 	}
};

class List{
	Node *head;
	int len = 0;

	public:
		List(){
			this->head = nullptr;
		}

		List(Node *head, int len){
			this->head = head;
			this->len = len;
		}

		Node* getHead(){
			return this->head;
		}

		int getLen(){
			return this->len;
		}

		void prependNode(Node *n){
			if(this->head == nullptr){
				this->head = n;
				this->len = 1;
				return;
			}
			
			n->setNext(this->head);
			this->head = n;
			this->len++;
		}

		void addNode(int pos, Node *n){
			if(pos > this->len){
				cout << "Position can't be greater than list length!" << endl;
				return;
			}
			
			if(this->head == nullptr && pos == 0){
				this->head = n;
				this->len = 1;
				return;
			}

			if(pos == 0){
				n->setNext(this->head);
				this->head = n;
				this->len++;
				return;
			}

			Node *temp1 = this->head;
			Node *temp2;
			for(int i = 0 ; i < pos ; i++){
				temp2 = temp1;
				temp1 = temp1->getNext();
			}
			n->setNext(temp1);
			temp2->setNext(n);
			this->len++;
		}

		void appendNode(Node *n){
			if(this->head == nullptr){
				cout << "Hi I'm here" << endl;
				this->head = n;
				this->len = 1;
				return;
			}

			Node *temp = this->head;
			for(int i = 0 ; i < this->len - 1 ; i++){
				temp = temp->getNext();
			}
			temp->setNext(n);
			this->len++;
		}

		void deleteNode(int pos){
			Node *temp1 = head;
			Node *temp2;
			int counter = 0, found = 0;
			while(counter < this->len){
				if(pos == counter){
					found = 1;
					break;
				}
				temp2 = temp1;
				temp1 = temp1->getNext();
				counter++;
			}
			if(found){
				temp2->setNext(temp1->getNext() );
				delete(temp1);
				this->len--;
				return;
			}
			cout << "Node not found" << endl;
		}

		void printList(){
			if(this->head == nullptr){
				cout << "List empty" << endl;
				return;
			}

			Node *temp = head;
			if(this->len == 1){
				cout << "[" << temp->getVal() << "]" << endl;
				return;
			}

			for(int i = 0 ; i < this->len ; i++){
				if(i == 0){
					cout << "[" << temp->getVal();
					temp = temp->getNext();
					continue;
				}
				if(i == this->len - 1){
					cout << ", " << temp->getVal() << "]" << endl;
					continue;
				}
				cout << ", " << temp->getVal();
				temp = temp->getNext();	
			}
		}
};
