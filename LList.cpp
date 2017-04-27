#include <iostream>
using namespace std;
#undef NULL
const int NULL = 0;
typedef int element;
const element SENTINEL = -1;
element read_element();
//constant string
const string ELEMENT_NAME = "whole number";

class listnode{
	public:
		element data;
		listnode * next;
	};

class LList{
	private:
		listnode * head;
		listnode * tail;
	public:
		LList();
		~LList();
		void Print();
		void InsertHead(element thing);
		void InsertTail(element thing);
		element DeleteHead();
		void ReadForward();
		void ReadBackward();
		void Clean();
		void Steal(LList & Victim);
		void Duplicate(LList & Source);
		void Reverse();
	};


int main (){
	LList L;

	cout << "object created and constructed, calling Print" << endl;
	L.Print();
	cout << "object printed, calling ReadForward" << endl;
	L.ReadForward();
	cout << "object read forward, calling Print" << endl;
	L.Print();
	cout << "object printed, calling ReadBackward" << endl;
	L.ReadBackward();
	cout << "object read backward, calling Print" << endl;
	L.Print();
	cout << "object printed, calling Clean" << endl;
	L.Clean();
	cout << "object cleaned, calling Print" << endl;
	L.Print();
	cout << "object printed" << endl;
	}

//Data and range checks data, returns a sanatized value to be used later
element read_element() {
    // PRE:  the user must enter a series of zero or
    // more non-valid element values, followed by a valid element value
    // POST: all entered non-valid element values will 
    //be successfully discarded, and the first valid element
    //  value entered will be returned
    element userval;        // used to collect the user's input value
                            
    // attempt to get an input value whose data type is an element
    
    // the boolalpha manipulator is used in case elements are bools,
    // to allow for inputs using the keystroke sequences of
    // "true" and "false" instead of "1" and "0"
    cin >> boolalpha >> userval;

    // repeat the following as long as this attempt failed,
    // presumably because the data type of the user's input was not an element
    while (! cin.good() || userval < -2147483647 || userval > 2147483647) {

      // re-enable the just-disabled cin object
      cin.clear();

      // from the input buffer, discard up to 80 
      //keystrokes or until the enter key is seen, whichever comes first
      cin.ignore(80, '\n');

      // tell the user what happened, and to try again
     if(!cin.good()){
        cout << "Invalid data type, should be an element ("
              << ELEMENT_NAME
              << "), try again: ";
        } else
        cout << "Invalid range type, should be within -2147483647" 
             << " and 2147483647, try again: ";

      // attempt to get an input value whose data type is an element
      //
      // the boolalpha manipulator is used in case elements are bools,
      // to allow for inputs using the keystroke
      // sequences of "true" and "false" instead of "1" and "0"
      cin >> boolalpha >> userval;
      }

    // return the valid element value given by the user
    return userval;
  }

LList::LList(){
	//PRE: none
	//POST: hte N.O. LList is valid and empty

	head = NULL;
	}

LList::~LList(){
	//PRE: the N.O. LList is valid
	//POST: the N.O. LList is valid and empty, 
	// its listnodes have been deleted
	Clean();
	}

void LList::Print(){
	//Pre: the N.O. LList is valid
	//Post: the N.O. LList is unchangend , 
	// and its elements have been displayed
	listnode * temp;

	temp = head;
	while (temp != NULL){
		cout << temp -> data << endl;
		temp = temp -> next;
		}
	}

void LList::InsertHead(element thing){
	// PRE: the N.O. LList is valid
	// POST:: the N.O. LList is cunchanged, except that a new 
	//listnode containing element thing has been 
	// inserted at the head end of the list

	listnode * temp;

	temp = new listnode;
	temp -> data = thing;
	temp -> next = head;
	if (head == NULL)
		tail = temp;
	else
		;
	head = temp;
	}

void LList::InsertTail(element thing){
	//PRE: the N.O. LList is valid
	// POST: the N.O. LList is unchanged, except that a new listnode 
	// containing element thing has been 
	// inserted at the tail end of the list
	listnode * temp;

	temp = new listnode;
	temp -> data = thing;
	temp -> next = NULL;
	if (head == NULL)
		head = temp;
	else
		tail -> next = temp;
	tail = temp;
	}

void LList::Clean(){
	// PRE: the N.O. LList is valid
	// POST: the N.O. LList is valid and empty. and all of its 
	// listnodes have been deleted
	while(head != NULL)
		DeleteHead();
	}

element LList::DeleteHead(){
	// PRE: the N.O. LList is valid and not empty
	// POST: the N.O. LList is unchanged, except that the listnode 
	// at the head end of the list has been deleted, 
	// and its data element has been retureed
	listnode * temp;
	element thing;

	temp = head;
	head = head -> next;
	thing = temp -> data;
	delete temp;
	return thing;
	}

void LList::ReadBackward(){
	// PRE: the N.O. LList is valid
	// POST: the N.O. LList is valid, all of its previous listnodes 
	// have been deleted, and its now consists of new listnodes 
	// containing elements given by the user in backward order
	element userval;

	Clean();
	cout << "Enter elements, " << SENTINEL << " to stop: ";
	userval = read_element();
	while (userval != SENTINEL) {
		InsertHead(userval);
		userval = read_element();
		}
	}

void LList::ReadForward(){
	// PRE: the N.O. LList is valid
	// POST: the N.O. LList is valid, all of its previous listnodes 
	// have been deleted, and it now consists of new listnodes
	 // containing elements given by the user in forward order
	element userval;

	Clean();
	cout << "Enter elements, " << SENTINEL << " to stop: ";
	userval = read_element();
	while (userval != SENTINEL){
		InsertTail(userval);
		userval = read_element();
		}
	}

void LList ::Steal(LList & Victim) {
	// PRE: the N.O. and victom LLists are valid
	// POST: the Victim LList is vlaid and empty the N.O. LList is valid, 
	// all of its previous listnodes havn been deleted, and it now
	 // consists of the listnodes originally the Victim LList

	Clean();
	head = Victim.head;
	tail = Victim.tail;
	Victim.head = NULL;
}

void LList::Duplicate(LList & Source){
	// PRE: the N.O. and Source LList are valid
	// POST:: the Source LList is unchanged the N.O. LList is valid,
	 // all of its previous listnodes have been deleted, and it now consists
	  // of listnodes containing the same elements and
	   // in tne same order as on the Source LList
	listnode * temp;

	Clean();
	temp = Source.head;
	while(temp != NULL){
		InsertTail(temp -> data);
		temp = temp -> next;
		}
	}

void LList::Reverse(){
	//PRE: the N.O. LList is valid
	//POST: the N.O. LList is unchanged, 
	// except its elements are in reverse order

	listnode * temp;
	LList Helper;

	temp = head;
	while (temp != NULL){
		Helper.InsertHead(temp -> data);
		temp = temp -> next;
		}
	Steal(Helper);
	}

