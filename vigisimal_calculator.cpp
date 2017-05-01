/*
* Brendan Jackson
* "CS215-J1E1" 
* Spring 2017
* "Programming Assignment #1"
* This program Creates a list using two seperate methods,
* sorts by a number of methods,
* and searches by a couple of methods as well
*/
//Basic Library, primarily used for the cin and cout statemnts
#include <iostream>
//prvents calling std on every operation
using namespace std;
// removes previous NULL definitions from libraries
#undef NULL
// sets null to 0
const int NULL = 0;
// defines element as an in
typedef int element;
// sets sentinel to 35 or '#'
const element SENTINEL = 35;

// decalres and defines a function called read_elemnt
element read_element();
//constant string
const string ELEMENT_NAME = "whole number";

//////////////////////////////////////////////////////////////////////////////

// sets up listnodes name and its creates a pointer for following listnodes
class listnode{
	public:
		element data;
		listnode * next;
	};

// Prototype for a class called LList
class LList{
	// sets pointers for listnodes
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
		// prints a list of contiguous lostnode data
		void Print();
		// inserts a new listnode at the "head" end of the list
		void InsertHead(element thing);
		// inserts a new listnode at the "tail" end of the list
		void InsertTail(element thing);
		//deletes head listnode
		element DeleteHead();
		// reads user data into listnode backwards
		void ReadBackward();
		// reads user data into listnode forwards
		void ReadForward();
		// deletes listnode data
		void Clean();
		// takes all of the data from the given object
		void Steal(LList & Victim);
		// duplicates all of the data from the given object
		void Duplicate(LList & Source);
		// reverses the order of the listnode
		void Reverse();
	};

//////////////////////////////////////////////////////////////////////////////

// Declares an object and starts the Bootstrap method
int main(){
	LList L;
	L.Bootstrap();
	
	}

//////////////////////////////////////////////////////////////////////////////
	
//Data and range checks data, returns a sanatized value to be used later
element read_element(){
 	// PRE:  the user must enter a series of zero or
    // more non-valid element values, followed by a valid element value
    // POST: all entered non-valid element values will 
    //be successfully discarded, and the first valid element
    //  value entered will be returned
    char userval;        // used to collect the user's input value
    int int_userval;

   cin >> boolalpha >> userval;
   while (! cin.good() 	) {
          cin.clear();

          // from the input buffer, 
          //discard up to 80 keystrokes or
          // until the enter key is seen, whichever comes first
          cin.ignore(80, '\n');

          // tell the user what happened, and to try again
          if(!cin.good()){
            cout << "\nInvalid data type, should be an element ("
                  << "char"
                  << "), try again: ";
            } else
            cout << "\nInvalid range type, should be characters" 
            	 << " 1-9 or A-J please try again: ";
            
          // attempt to get an input value whose data type is an element
          //
          // the boolalpha manipulator is used 
          //  in case elements are bools, to allow 
          //for inputs using the keystroke
          // sequences of "true" and "false" instead of "1" and "0"
          cin >> boolalpha >> userval;
          }

          // converts user data to integers
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

//////////////////////////////////////////////////////////////////////////////

// constructor
LList::LList(){
	//PRE: none
	//POST: hte N.O. LList is valid and empty

	head = NULL;
	}

//////////////////////////////////////////////////////////////////////////////

LList::~LList(){
	//PRE: the N.O. LList is valid
	//POST: the N.O. LList is valid and empty, 
	// its listnodes have been deleted
	Clean();
	}

//////////////////////////////////////////////////////////////////////////////

//startup procedure for the program
void LList::Bootstrap(){
	// PRE: The Program has not started
	// POST: The user is given a new message, some initial values are given 
	// to the program, and the menu is called
	
	cout << "\n\nVigesimal Calculator, Version 1.0 \n"
		 << "(c) 2017, (Brendan Jackson)\n\n";
	//Sets the starting value to '0'
	InsertHead(0);
	// calls the menu
	Menu();
	}

//////////////////////////////////////////////////////////////////////////////	

//displays and reads user the menu
void LList::Menu(){
	// PRE: The Program has started
	// POST: The user is given a new message, a method is called, or
	// the program ends

	// gets menu selection from user
	char menu_selection;

	// Runs menu unless the user chooses to quit
	while (menu_selection != 'q'){

	// user feedback message
	cout << "\nCurrent vigesimal number is: " ;
	// prints native list
	Print();
	// user feedback message
	cout  << "\n\nCommand (h for help) : ";
		 

	 //get user input method
	 menu_selection = ReadMenu();
	 // cout << "testing menu selection: " << menu_selection;

	 	// checks user input
	 	switch (menu_selection){
	 	// calls enter method
	 	case 'e':
	 	case 'E':
	 		Enter();
	 		break;
 		
 		// calls add method
 		case 'a':
 		case 'A':
 			Add();
	 		break;

	 	// calls multiply method
 		case 'm':
 		case 'M':
 			Multiply();
	 		break;

 		// Displays menu for the user
 		case 'h':
 			cout << "\n\nValid commands are:\n"
				 <<	 "e enter enter the current "
				 << "vigesimal number from the keyboard\n"
				 <<	"a add add a new vigesimal number to"
				 << " the current vig. number\n"
				 <<	 "m multiply multiply a new vigesimal"
				 << " number by the current vig. number\n"
				 <<	 "h help show this help menu\n"
				 <<	 "q quit quit the program\n\n";
	 		break;

	 	// breaks menu in off case
 		default:
 			break;

		}	
	 }
	 // ending program message
		cout << "\nFinishing Vigesimal Calculator, version 1.0\n\n";
	}

///////////////////////////////////////////////////////////////////////////////

//This method takes in the users input for the menu,
//types and range checks it, then returns the result, 
//  selecting the next method to be called
char LList::ReadMenu(){
	// PRE: The Menu has been called
	// POST: the users menu selection has been validated

  //stores user choice in an int variable for this method 
  char menu_selection;
  //accepts true/false values(future), saves user input in menu_choice
  cin >> boolalpha >> menu_selection;

  // repeat the following as long as this attempt failed, 
  //presumably because the data type of the user's input was not an element
  while (! cin.good() || 
  	(menu_selection != 'e' && menu_selection != 'a' && menu_selection
  	 != 'm' && menu_selection != 'h' && menu_selection != 'q')  &&
  	(menu_selection != 'E' && menu_selection != 'A' && menu_selection
  	 != 'M' && menu_selection != 'H' && menu_selection != 'Q')
  	) {
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
            cout << "Invalid range type, should be characters "
            	 << "'e', 'a', 'm', 'h', or 'q', please try again: ";
            
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

///////////////////////////////////////////////////////////////////////////////

// Gets new Vigesimal number from the user
void LList::Enter(){
	// PRE: The Enter method was called from the menu method
	// POST: The users input has been recieved and validated


	cout << "\nEnter a vigesimal number, followed by #: " ;
	ReadBackward();
	cout << "\nEntering completed.\n";

	}

///////////////////////////////////////////////////////////////////////////////

// adds a new vigesimal number to the current vig. number
void LList::Add() {
	// PRE: The Add method was called from the menu method
	// POST: The users input has been recieved and validated,
	// the Native list and the Second list have been added together
	 

	//Local object used to gather information to add form the user
	LList Second;
	// local object which will store the result of the N.O and Second Object
	LList Sum;
	// creates a pointer to a listnode
	listnode * temp1;
	//points to the natives head
	temp1 = head;
	// creates a new listeode pointer
	listnode * temp2;
	// points temp 2 at Second Objects head
	temp2 = Second.head;
	// defines and declares a integer known as carry
	int carry;
	//defines and declares a an integer total,
	 // stores sum of local and native
	int total;
	// initializes carry to 0
	carry = 0;

	// Defines and declares a variable 
	int native;
	// Defines and declares a variable 
	int local;

	//intialiazes a variable that will get sum objects listnode values
	int remainder;
	

	//  Add Methods call to Action for the user
	cout << "\nAdding a new vigesimal number to the current vig. number." 
		 << "\nEnter a vigesimal number, followed by #: " ;

	// reads in user input
	Second.ReadBackward();

	// points temp2 at Second's head
	temp2 = Second.head;

	// stores temp1's data
	int temp1_data;
	// stores temp2's data
	int temp2_data;	

	// if either list has nodes, continues loop
	while(temp1 != NULL || temp2 != NULL){
		// sets 0 as a placehodler if data is not located in listnode
		if(temp1 != NULL){
			temp1_data = temp1->data;
			temp1 = temp1->next;
		} else
			temp1_data = 0;

		// sets 0 as a placehodler if data is not located in listnode
		if(temp2 != NULL){
			temp2_data = temp2->data;
			temp2 = temp2->next;
		} else
			temp2_data = 0;

		// gets sum total
		total = temp1_data + temp2_data + carry;
		// gets current places integer
		remainder = total % 20;
		// gets number to be carried to the next place/listnode
		carry = total / 20;

		// sets sum objects value
	   Sum.InsertTail(remainder);
		
		
     	
		}
	// if there are leftover numbers, creates a new listnode and sets value
	if (carry > 0) 
		Sum.InsertTail(carry);

	
	/**************************************************
	******************** wrap up **********************
	**************************************************/
	// steals Sum, applies it to the N.O.
	Steal(Sum);
	// user feedback
 	cout << "\nNew vigesimal number is: ";
 	// prints Native list
	Print(); 
	// user feedback
	cout << "\nAdding completed.\n";
}
	
///////////////////////////////////////////////////////////////////////////////

// multiplys a new vigesimal number by the current vig. number
void LList::Multiply(){
	// PRE: The Add method was called from the menu method
	// POST: The users input has been recieved and validated,
	// the Native list and the Multiplier list have been multiplied together


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
	//defines and declares a an integer total,
	 // stores sum of local and native
	int total;
	// initializes carry to 0
	carry = 0;

	
	// stores vigesimal remainder
	int remainder;
	
	// defines and decalres a variable to capture listnode data
	int temp1_data;
	// defines and decalres a variable to capture listnode data
	int temp3_data;	

	//  Add Methods call to Action for the user
	cout << "\nMultiplying a new vigesimal number"
		 << "to the current vig. number." 
		 << "\nEnter a vigesimal number, followed by #: " ;

	 // gets multiplier from the user
	Multiplier.ReadBackward();

	// creates a pointer to a listnode
	listnode * temp2;
	// points at the multiplier objects head
	temp2 = Multiplier.head;

	// reads in native objects value into Products list
	while(temp1 != NULL){
		Product.InsertTail(temp1->data);	
		temp1 = temp1->next;
	}
	
	
	
	// creates a pointer to a listnode
	listnode * temp3;
	// points at the Product objects head
	temp3 = Product.head;

	// catches multiplication by 1
	if(temp2->data == 1)
		;
	else{
		// validates  Multiplier list
		while(temp2 != NULL){

		// adds native object to product based on multiplier
		for(int i = temp2->data; i > 0; i--){
			// resets list at the start
			temp1 = head;
			// resets list at the start
			temp3 = Product.head;
			
			// checks to see if at least one list is valid
			while(temp1 != NULL || temp3 != NULL){
				// if list is empty, sets 0 as placeholder
				if(temp1 != NULL){
					temp1_data = temp1->data;
				} else
					temp1_data = 0;

				// if list is empty, sets 0 as placeholder
				if(temp3 != NULL){
					temp3_data = temp3->data;
				} else
					temp3_data = 0;

				// gets sum
				total = temp1_data + temp3_data + carry;
				// gets remainder for new node
				remainder = total % 20;
				// gets carry for next node
				carry = total / 20;

				// sets list3s data with remainder
			    temp3->data = remainder;
			    // if list isnt empty, moves to next node
				if(temp1 != NULL){
					temp1 = temp1->next;
					}
				// if list isnt empty, moves to next node
				if(temp3 != NULL){
					temp3 = temp3->next;
					}
				}

			// inserts leftovers in the next node
			if (carry > 0) 
				Product.InsertTail(carry);
				
			}
		// moves to the next multiplier
		temp2 = temp2->next;	
		// adds a 0 to the N.O.
		InsertHead(0);
		}
	}
	
	// points to multipliers head
	temp2 = Multiplier.head;
	// in case of multiplication by 0
	if(temp2->data == 0)
		Product.Clean();	

	
	/**************************************************
	******************** wrap up **********************
	**************************************************/
	// Gives N.O  back the results
	Steal(Product);
	// user feedback
	cout << "\nNew vigesimal number is: ";
	// prints native list
	Print(); 
	// user feedback
	cout << "\nMultiplying completed.";

	}

///////////////////////////////////////////////////////////////////////

//Prints contiguous listnodes
void LList::Print(){
	//Pre: the N.O. LList is valid
	//Post: the N.O. LList is unchangend , 
	// and its elements have been displayed
	//Reverses the order of the list
	Reverse();
	// declares and defines var for number of loop passes
	int counter;
	// initializes the counter to 0
	counter = 0;
	// creates a pointer named temp
	listnode * temp;
	// declares and defines a character var to store user input
	char char_data;
	// points the pointer at the N.O.'s head of the list
	temp = head;
	while (temp != NULL){
	//Prints everything in the original character format for the user
		if(temp->data >= 0 && temp->data <= 9)
			char_data = temp->data + 48 ;
	 	else if(temp->data >= 10 && temp->data <= 19)
			char_data = temp->data + 55 ;
		
		
		//breaks line every 30 listnodes "Pretty Frint"
		if(counter % 30 == 0)
			cout << endl;
		else
			;

		// outputs character data to screen
		cout << char_data;

		//easy print
		// cout << temp -> data << " ";
	
		// adds to the counter
		counter++;

		//inserts a "," every 3 listnodes "Pretty Frint"
		if(counter > 0 && counter % 3 == 0)
			cout << ",";
		else
			;	

		//moves to the next listnode
		temp = temp -> next;

		}
		// breaks line
		cout << endl;
		// Puts list back in order for calculations
		Reverse();
	}

///////////////////////////////////////////////////////////////////////

// inserts an element into a new listnode at the head of the list
void LList::InsertHead(element thing){
	// PRE: the N.O. LList is valid
	// POST:: the N.O. LList is cunchanged, except that a new 
	//listnode containing element thing has been 
	// inserted at the head end of the list

	// creates a listnode pointer named temp
	listnode * temp;

	// creates a new listnode
	temp = new listnode;
	// fills listnode with data from in arguent
	temp -> data = thing;
	// the followiling listnode is now the head
	temp -> next = head;
	// tail is the new listnode if head is null
	if (head == NULL)
		tail = temp;
	else
		;
	// head is the new listnode
	head = temp;
	}

///////////////////////////////////////////////////////////////////////


// puts a new fills a new listnode at the tail
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


///////////////////////////////////////////////////////////////////////

//WAS TYPE ELEMENT
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

///////////////////////////////////////////////////////////////////////

void LList::ReadBackward(){
	// PRE: the N.O. LList is valid
	// POST: the N.O. LList is valid, all of its previous listnodes 
	// have been deleted, and its now consists of new listnodes 
	// containing elements given by the user in backward order
	LList Invalid;

	listnode * temp;
 	temp = Invalid.head;
 	
	 
	int userval;
	Clean();
	
	// cout << "\nEnter elements, " << SENTINEL << " to stop: \n";
	userval = read_element();

	while (userval != SENTINEL) {
		InsertHead(userval);
		userval = read_element();
		}

		// cout << "\nWarning: invalid vigesimal digits seen: "
 	// 	 << "'', ''"
 	// 	 << "; ignoring these" ;
	}

///////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////

// deletes all listnodes
void LList::Clean(){
	// PRE: the N.O. LList is valid
	// POST: the N.O. LList is valid and empty. and all of its 
	// listnodes have been deleted
	while(head != NULL)
		DeleteHead();
	}

///////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////

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

///////////////////////////////////////////////////////////////////////

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
	