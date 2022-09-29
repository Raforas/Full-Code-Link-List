/*

A full code for Linked List:

For your reference to Mini Project




*/

#include <iostream>
#include <string>
using namespace std;

//funtions declaration
void addfront();
void addmiddle();
void addrear();
void delfront();
void delmiddle();
void delrear(); 
void search(); 
void display();

struct vehicle {
	string brand;
	string model;
	int yearmade;
	float price;
	vehicle* next;
};
vehicle* head;
vehicle * tmp;
int main(void) {
	head = NULL;

	int operation;
	while (true) {
		cout << "\nSelect operation for Linked List" << endl;
		cout << "1. Add new node at the front" << endl;
		cout << "2. Add new node at the middle" << endl;
		cout << "3. Add new node at the rear" << endl;
		cout << "4. Delete new node at the front" << endl;
		cout << "5. Delete new node at the middle" << endl;
		cout << "6. Delete new node at the rear" << endl;
		cout << "7. Search a Data" << endl;
		cout << "8. Display the current Linked List" << endl;
		cout << "9. Exit program" << endl;
		cout << "Your Operation: ";
		cin >> operation;

		switch (operation) {
		case 1:addfront(); break;
		case 2:addmiddle(); break;
		case 3:addrear(); break;
		case 4:delfront(); break;
		case 5:delmiddle(); break;
		case 6:addrear(); break;
		case 7:search(); break;
		case 8:display(); break;
		case 9:exit(1); break;

		}//end switch
	}//end while
	

	system("pause");
	return 0;

}


//functions bodies
void addfront() {
	vehicle* node = new vehicle;
	cout << "\nMasukkan Brand : ";
	getline(cin >> ws, node->brand);

	cout << "Masukkan Model : ";
	getline(cin >> ws, node->model);

	cout << "Masukkan  Tahun Keluaran: ";
	cin >> node->yearmade;

	cout << "Masukkan Harga: ";
	cin >> node->price;

	if (head == NULL) //true for the 1st node
		node->next = NULL;
	else//true for the 2st node,3rd note and the rests.
		node->next = head;
	
	head = node;
}


void addmiddle() {


}
void addrear(){


}
void delfront(){


}
void delmiddle(){


}
void delrear(){


}
void search(){


}
void display() {
	//traverse
	tmp = head;
	cout << "\nSenarai Vehicle Terkini"<<endl;
	while (tmp!=NULL)
	{
		cout << tmp->brand << "\t"
			<< tmp->price << "\t"
			<< tmp->model << "\t"
			<< tmp->yearmade << "\t\n";
			
	tmp = tmp ->next;
	

	 }

}