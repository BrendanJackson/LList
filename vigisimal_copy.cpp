// 0-J
// static_cast<new_type>(expression) static_cast<char>(varname) 

#include <iostream>
using namespace std;
#undef NULL
const int NULL = 0;
typedef int element;
const element SENTINEL = 35;
// const element SENTINEL = '#';

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
		// Constructor for each object
		LList();
		// Deconstructor for each object
		~LList();
		// initial running method for the program
		void Bootstrap();
		// Displays menu to the user
		void Menu();
		// Gets the users menu selection
		char ReadMenu();
		// Gets a vigisimail number form the user
		void Enter();
		// Adds a new viesimal number to the current vigesimal number
		void Add();
		// multiply a new vigesimal number by the current vig. number
		void Multiply();
		// divides an integer by 10, saving the remainder 
		//for the current listnode and adding anything additional to the 
		// next listnode
		void Print();
		void InsertHead(element thing);
		void InsertTail(element thing);
		// WAS TYPE ELEMENT
		int DeleteHead();
		void ReadForward();
		void ReadBackward();
		void Clean();
		void Steal(LList & Victim);
		void Duplicate(LList & Source);
		void Reverse();
	};


int main(){
	LList L;
	L.Bootstrap();
	
	}
 
	// if (character == 'A' || character == 'a')
	// 	number = 10;
	// else if (character == 'B'  || character == 'b')
	// 	number = 11;
	// else if (character == 'C'  || character == 'c')
	// 	number = 12;
	// else if (character == 'C'  || character == 'c')
	// 	number = 13;
	// else if (character == 'C'  || character == 'c')
	// 	number = 14;
	// else if (character == 'C'  || character == 'c')
	// 	number = 15;
	// else if (character == 'C'  || character == 'c')
	// 	number = 16;
	// else if (character == 'C'  || character == 'c')
	// 	number = 17;
	// else if (character == 'C'  || character == 'c')
	// 	number = 18;
	// else if (character == 'J'  || character == 'j')
	// 	number = 19;
	

	

//Data and range checks data, returns a sanatized value to be used later
element read_element() {
 
    char userval;        // used to collect the user's input value
    int int_userval;

   cin >> boolalpha >> userval;
	 
	if(userval >= '0' && userval <= '9')
		int_userval = (int)userval - 48 ;
	 else if(userval >= 'A' && userval <= 'J')
		int_userval = (int)userval - 55 ;
	 else if(userval >= 'a' && userval <= 'j')
		int_userval = (int)userval - 87 ;
	 else if (userval == '#')
	 	int_userval = (int)userval;
	 else
	 	;
	
    // return the valid element value given by the user
    return int_userval;
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

//startup procedure for the program
void LList::Bootstrap(){
	
	cout << "\n\nVigesimal Calculator, Version 1.0 \n"
		 << "(c) 2017, (Brendan Jackson)\n\n";
	//Sets the starting value to '0'
	InsertHead(0);
	// calls the menu
	Menu();
	}

void LList::Menu(){
	char menu_selection;
	while (menu_selection != 'q'){

	cout << "\nCurrent vigesimal number is: " ;
	
	Print();
	
	cout  << "\n\nCommand (h for help) : ";
		 

	 //get user input method
	 menu_selection = ReadMenu();
	 // cout << "testing menu selection: " << menu_selection;

	 
	 	 switch (menu_selection){
	 	case 'e':
	 		Enter();
	 		// Menu();
	 		break;
 		
 		case 'a':
 			Add();
	 		// Menu();
	 		break;

 		case 'm':
 			Multiply();
	 		// Menu();
	 		break;

 		case 'h':
 			cout << "\n\nValid commands are:\n"
				 <<	 "e enter enter the current vigesimal number from the keyboard\n"
				 <<	 "a add add a new vigesimal number to the current vig. number\n"
				 <<	 "m multiply multiply a new vigesimal number by the current vig. number\n"
				 <<	 "h help show this help menu\n"
				 <<	 "q quit quit the program\n\n";
			// Menu();
	 		break;

 		// case 'q':
 		// 	cout << "\nFinishing Vigesimal Calculator, version 1.0\n\n";
 		// 	exit(0);
	 	// 	break;

		}	
	 }
		cout << "\nFinishing Vigesimal Calculator, version 1.0\n\n";
	}

//This method takes in the users input for the menu,
//types and range checks it, then returns the result, 
//  selecting the next method to be called
char LList::ReadMenu(){
  //stores user choice in an int variable for this method 
  char menu_selection;
  //accepts true/false values(future), saves user input in menu_choice
  cin >> boolalpha >> menu_selection;

  // repeat the following as long as this attempt failed, 
  //presumably because the data type of the user's input was not an element
  while (! cin.good() || 
  	(menu_selection != 'e' && menu_selection != 'a' && menu_selection != 'm' && menu_selection != 'h' && menu_selection != 'q')  &&
  	(menu_selection != 'E' && menu_selection != 'A' && menu_selection != 'M' && menu_selection != 'H' && menu_selection != 'Q')
  	) {
// || menu_selection != 'e' || menu_selection != 'a' || menu_selection != 'm' || menu_selection != 'h' || menu_selection != 'q'
          // re-enable the just-disabled cin object
          cin.clear();

          // from the input buffer, 
          //discard up to 80 keystrokes or
          // until the enter key is seen, whichever comes first
          cin.ignore(80, '\n');

          // tell the user what happened, and to try again
          if(!cin.good()){
            cout << "Invalid data type, should be an element ("
                  << "char"
                  << "), try again: ";
            } else
            cout << "Invalid range type, should be characters 'e', 'a', 'm', 'h', or 'q', please try again: ";
            
          // attempt to get an input value whose data type is an element
          //
          // the boolalpha manipulator is used 
          //  in case elements are bools, to allow 
          //for inputs using the keystroke
          // sequences of "true" and "false" instead of "1" and "0"
          cin >> boolalpha >> menu_selection;
          }

  // return the valid element value given by the user
  return menu_selection;
  }

// Gets new Vigesimal number from the user
void LList::Enter(){
	cout << "\nEnter a vigesimal number, followed by #: " ;
	ReadBackward();
	cout << "\nEntering completed.\n";

	/*
	 int i=0;
  char str[]="Test String.\n";
  char c;
  while (str[i])
  {
    c=str[i];
    putchar (toupper(c));
    i++;
  }
	*/
	}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// adds a new vigesimal number to the current vig. number
void LList::Add() {
	//Local object used to gather information to add form the user
	LList Second;
	// local object which will store the result of the N.O and Second Object
	LList Sum;
	// creates a pointer to a listnode
	listnode * temp1;
	//points to the natives head
	temp1 = head;

	listnode * temp2;
	temp2 = Second.head;
	// defines and declares a integer known as carry
	int carry;
	//defines and declares a an integer total, stores sum of local and native
	int total;
	// initializes carry to 0
	carry = 0;

	// Defines and declares a variable 
	int native;
	// Defines and declares a variable 
	int local;

	// Defines and declares a variable to temporarily store native as an int
	// int int_native;
	// Defines and declares a variable to temporarily store local as an int
	// int int_local;

	//intialiazes a variable that will get sum objects listnode values
	int remainder;
	

	//  Add Methods call to Action for the user
	cout << "\nAdding a new vigesimal number to the current vig. number." 
		 << "\nEnter a vigesimal number, followed by #: " ;

	
	Second.ReadBackward();
	cout << "\nSecond Contents: ";
	Second.Print();


	temp2 = Second.head;

	int temp1_data;
	int temp2_data;	

	while(temp1 != NULL || temp2 != NULL){
		if(temp1 != NULL){
			temp1_data = temp1->data;
			temp1 = temp1->next;
		} else
			temp1_data = 0;

		if(temp2 != NULL){
			temp2_data = temp2->data;
			temp2 = temp2->next;
		} else
			temp2_data = 0;

		total = temp1_data + temp2_data + carry;
		remainder = total % 20;
		carry = total / 20;

	   Sum.InsertTail(remainder);
		
		
     	
		}
	if (carry > 0) 
		Sum.InsertTail(carry);

	
	/**************************************************
	******************** wrap up **********************
	**************************************************/
	Steal(Sum);
 	cout << "\nNew vigesimal number is: ";
	Print(); 
	cout << "\nAdding completed.\n";
}
	
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// multiplys a new vigesimal number by the current vig. number
void LList::Multiply(){
	// How do I deal with multipliers of 0 and 1?

	//Local object used to gather information to add form the user
	LList Multiplier;
	// local object which will store the result of the N.O and Second Object
	LList Product;
	//creates a pointer to a listnode
	listnode * temp1;
	//points at the native objects head
	temp1 = head;

	// defines and declares a integer known as carry
	int carry;
	//defines and declares a an integer total, stores sum of local and native
	int total;
	// initializes carry to 0
	carry = 0;

	

	// Defines and declares a variable to temporarily store native as an int
	int int_native;
	// Defines and declares a variable to temporarily store local as an int
	int int_local;
	// Defines and declares a variable to temporarily store local as an int
	int int_product;

	int remainder;
	
	//  Add Methods call to Action for the user
	cout << "\nMultiplying a new vigesimal number to the current vig. number." 
		 << "\nEnter a vigesimal number, followed by #: " ;

	Multiplier.ReadBackward();
	// creates a pointer to a listnode
	listnode * temp2;
	// points at the multiplier objects head
	temp2 = Multiplier.head;

	cout << "\nDuplicating L...";
	while(temp1 != NULL){
		Product.InsertTail(temp1->data);	
		temp1 = temp1->next;
	}
	
	cout << "\nPrinting Product object : ";
	Product.Print();
	
	// creates a pointer to a listnode
	listnode * temp3;
	// points at the Product objects head
	temp3 = Product.head;

	
	int temp1_data;
	int temp3_data;	
	
	// int decrement = temp2->data;
	while(temp2 != NULL){
		//Next step, move to the next listnode
		// convert all of multiplier listnode to digits, when temp2->data = 0, move to the next, until there are no more listnodes
		
		for(int i = temp2->data; i > 0; i--){
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			// listnode * temp1;
			temp1 = head;
			temp3 = Product.head;
					
			while(temp1 != NULL || temp3 != NULL){
				
				if(temp1 != NULL){
					temp1_data = temp1->data;
					cout << "\ntemp1 is not null";
				} else
					temp1_data = 0;

				if(temp3 != NULL){
					temp3_data = temp3->data;
					cout << "\ntemp3 is not null";
				} else
					temp3_data = 0;

				total = temp1_data + temp3_data + carry;
				remainder = total % 20;
				carry = total / 20;

			    temp3->data = remainder;
				if(temp1 != NULL){
					temp1 = temp1->next;
					}

				if(temp3 != NULL){
					temp3 = temp3->next;
					}
				}

			if (carry > 0) 
				Product.InsertTail(carry);
				
			cout << "\ncurrent Product list (after carry): ";
				Product.Print();
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
			cout << "\n\ndecrement: " << i - 1;
			}
		temp2 = temp2->next;	
		InsertHead(0);
		}
	// Steal Sum Listnode

	
	cout << "\ncalculations ending, NO is: ";
	Print();
	/**************************************************
	******************** wrap up **********************
	**************************************************/
	Steal(Product);
	cout << "\nNew vigesimal number is: ";
	Print(); 
	cout << "\nMultiplying completed.";

	}

///////////////////////////////////////////////////////////////////////

void LList::Print(){
	//Pre: the N.O. LList is valid
	//Post: the N.O. LList is unchangend , 
	// and its elements have been displayed
	Reverse();
	listnode * temp;

	temp = head;
	while (temp != NULL){
		// cout << temp -> data << endl;
		cout << temp -> data << " ";
		temp = temp -> next;
		}

		cout << endl;
		Reverse();
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

//WAS TYPE ELEMENT
int LList::DeleteHead(){
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
	int userval;
	Clean();
	
	// cout << "\nEnter elements, " << SENTINEL << " to stop: \n";
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

void LList::Steal(LList & Victim) {
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
	