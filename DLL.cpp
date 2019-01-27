lab3_q1//including library
#include <iostream>
using namespace std;
lab3_q1
class Node{
	public:
	//variable to store data 
	int data;
	// Pointer to the next Node
	Node * next;
	//pointer to the previous node
	Node * prev;
	//constructer to define the pointer to NULL
	Node(int value){
		next = NULL;
		prev = NULL;
		data = value;
	}
};

class DLL{
	public:
	Node * head;
	//constructer for defining a dlinked list
	DLL(){
		head = NULL;lab3_q1
	}

	void insert(int value){
		// Create a new node
		Node * temp = new Node(value);
		// Check if it is an empty dlist
		if(head == NULL){
			head = temp;
		}  
		// If not an empty dlist.
		else{  
			Node * current = head;
			while(current->next != NULL)
				current = current->next;
				current->next = temp;
				temp->prev = current;    
		}
	}
	void display(){
		Node *current = head;
		Node *last;
		cout << "Print in   order : ";
		while(current!=NULL){
			cout <<current->data<< "->"; 
			// Store the current in last (to catch the tail to print in reverse)
			last = current;
			// Move Forward
			current = current->next;
		}
		cout <<"NULL"<<endl;
		cout << "Print in Reverse order : ";
		while(last!=NULL){
			cout <<last->data<< "->";
			// Move backwards 
			last = last->prev;
		}
		cout <<"NULL"<< endl;   
	}
	void InsertAt(int value, int pos){
		//Create a new Node
		Node *temp = new Node(value);
		//if position is not 1;
		if(pos>1){
			Node * current = head;
			int i=1;
			//looping to cross check the position
			while(i<pos-1){
				i++;
				//moving forward
				current=current->next;
				if(current==NULL){
					cout<<"The dLinked List does not have sufficient element"<<endl; 
					break;
				}
				}
				//if position is greater than total elements
			
				//for other position	
				if(current!=NULL){
					temp->next=current->next;
					current->next->prev=temp;
					current->next=temp;
					temp->prev=current;	
			
			}
		}
		//To position is 1
		else{
			head->prev = temp;
			temp->next = head;
			head = temp;				    
		}
	}
	void Del(){
		// Deletes the last element.
		Node *current = head;
		Node *last;
		while(current!=NULL){
			//store current to last
			last = current;
			//move forward
			current = current->next;
		}
		//making the appropriate pointer changes
		last->prev->next = NULL;
		//delete last Node
		delete last;
	}
	void DeleteAt(int pos){
		Node *temp;
		//if position is not 1;
		if(pos>1){
			Node * current = head;
			int i=1;
			//looping to cross check the position
			while(i<pos-1){
				i++;
				//moving forward
				current=current->next;
				if(current==NULL){
					cout<<"The dLinked List does not have sufficient element"<<endl; 
					break;
				}
				}
				//if position is greater than total elements
			
				//for other position	
				if(current!=NULL){
					temp=current->next;
					temp->next->prev=current;
					current->next=temp->next;	
			}
		}
		//To position is 1
		else{
			temp = head;
			temp->next = head;
			head->prev = NULL;				    
		}
		//delete temp
		delete temp;
	}

	void CountItems(){
		// Counts the Number of items.
		Node *current = head;
		int i = 0;
		while(current != NULL){
			i++;
			current=current->next;
		}
	cout<<"There are a total of "<<i<<" nodes"<<endl;	
	}

};

int main(){
	DLL dll1;
	for(int i= 1; i < 11; i++){
	dll1.insert(i);
	}
	dll1.display();
	dll1.Del();
	dll1.display();
	dll1.CountItems();
	dll1.InsertAt(3,11);
	dll1.display();
	dll1.DeleteAt(7);
	dll1.display();
return 0;
}
