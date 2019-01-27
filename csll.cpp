//including library
#include <iostream>
using namespace std;



class Node{
	public:
	// Data 
	int data;
	// Pointer to the next Node
	Node * next;
	Node * prev;
	// Construct that makes the ptr to NULL
	Node(int value){
	next = NULL;
	data = value;
	}
};

class CSLL{
	public:
	Node * head;
	Node * tail;
	CSLL(){
		head = NULL;
		tail = NULL;
	}
	// Inserts to the end of the linked list.
	void insert(int value){

		// Create a new node
		Node * temp = new Node(value);
		// Check if empty list
		if(head == NULL){
		    head = temp;
		}  
		else{ // If not empty list. 
		    Node * current = head;
		    while(current->next != head)
			current = current->next;
		    current->next = temp;
		}
		tail = temp;
		temp->next = head;
	}
	// Displays the linked list.
	void display(){
		Node * current = head;
		if(current == NULL) {
		    cout << "No elements " << endl;
		    return;
		}
		while(current->next != head){ // Stopping at head
		    cout << current -> data << "->";
		    current = current -> next;
		}
		// Printing the last element
		cout << current -> data ;
		cout << endl;
	}
	void InsertAt(int value, int pos){
		//inserting at a particular position
		Node *current = head;
		int i = 1;
		while(current->next != head){
			i++;
			current = current->next;	
		}
		//if position is greater than total elements
		if(pos>i){
			cout<<"the CSLL doesn't consist sufficient elements"<<endl;
		}
		else{
			Node *temp = new Node(value);
			//if pos is first
			if(pos == 1){
				temp->next = head;
				head = temp;
				tail->next = head;
			}
			//for other pos
			else{
				int j = 0;
				while(j<pos-1){
					j++;
					current = current->next;			
				}
				temp->next = current->next;
				current->next = temp;
			}
		}

	}
	void DeleteAt(int pos){
	//delete at given position
	Node *current = head;
	Node *temp;
		int i = 1;
		while(current->next != head){
			i++;
			current = current->next;	
		}
		//if position is greater than total elements
		if(pos>i){
			cout<<"the CSLL doesn't consist sufficient elements"<<endl;
		}
		else{
		//if pos = 1
			if(pos ==1){
				temp = head;
				head = head->next;
				tail->next = head;	
			}
		//for other positions
			else{
				int j = 0;
				while(j<pos-1){
					j++;
					current = current->next;
				}
				temp = current->next;
				current->next = temp->next;
			}
		}
	//delete temp;
	delete temp;
	}
	void Delet(){
		// Deletes the last element.
		Node *current = head;
		Node *temp;
			while(current->next != tail){
			current = current->next;
			}
		temp= current->next;
		tail = current;	
		current->next = head;
		//delete temp
		delete temp;
		
	}
	//counting the total number of elements
	void CountItems(){
		int i = 1;
		Node *current = head;
		while(current->next != head){
			i++;
			current = current->next;	
		}
	cout<<"The number of elements in the CSLL is "<<i<<endl;
	}
};

int main(){
	CSLL csll1;
	for(int i= 1; i < 11; i++){
	csll1.insert(i);
	}
	csll1.insert(1);
	csll1.display();
	csll1.CountItems();
	csll1.InsertAt(8,12);
	csll1.display();
	csll1.Delet();
	csll1.display();
	csll1.DeleteAt(10);
	csll1.display();
}
