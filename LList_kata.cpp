#include <iostream>
using namespace std;
#undef NULL
const int NULL = 0;
typedef int element;
const element SENTINEL = -1;
element read_element();
const string ELEMENT_NAME = "Whole number";

class listnode {
public:
	element data;
	listnode * next;
};

class LList {
	private:
		listnode * head;
		listnode * tail;
	public:
		LList();
		~LList();
		void Print();
		void Clean();
		element DeleteHead();
};


int main(){

}


element read_element(){
	element userval;

	cin >> boolalpha >> userval;

	while (! cin.good() || userval < -2147483647 || userval > 2147483647 ){
		cin.clear();
		cin.ignore(80, '\n');

		if( !cin.good() ){
			cout << "sorry please enter a" 
				 << ELEMENT_NAME << '\n';
		} else {
			cout << "sorry please enter a number between -2147483647 and 2147483647 \n";
		}
		cin >> boolalpha >> userval;
	}
	return userval;
}

//constructor, head = null on a LList object  creation
LList::LList(){
	head = NULL;
}

//Destructor, returns data back to the program at the end of a LList objects life
LList::~LList(){
	Clean();
}

void LList::Print(){
	listnode * temp;

	temp = head;

	while (temp != NULL){
		cout << temp -> data << endl;
		temp = temp -> next;	
	}

}

void LList::Clean(){
	listnode * temp;

	while (temp != NULL){
		DeleteHead();
	}
}

element LList::DeleteHead(){
	listnode * temp;
	element thing;

	temp = head;
	head = head -> next;
	thing = temp -> data;

	delete temp;
	return thing;

}