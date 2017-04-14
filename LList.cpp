#Include <iostream>
using namespace std;
#undef NULL
const int NULL = 0;
typedef int element;
const element SENTINEL = -1;
element read_element();

int main (){
	LList L;

	cout << "object created and constructed, calling Print" << endl;
	L.Print();
	cout << "object printed, callieg ReadForward" << endl;
}

class listnode {
	public:
		element data;
		listnode * next;
	};

class LList{
	private:
		
	public:

};