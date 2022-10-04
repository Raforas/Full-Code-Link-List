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
vehicle * head; //head  is a start pointer , used to point to the 1st node
vehicle * tmp;  //tmp is a pointer to do a traversing
vehicle* temp;  //temp is a pointer to addrear/addmiddle/delrear by traversing

string mdl;		//variable mdl 

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
	if (head==NULL) { //true semasa bil node 0
		cout << endl << "Linked List is EMPTY!!! Cannot perform Add Middle" << endl;

	}
	else if (head-> next == NULL) { //true semasa bil node 1
		cout << endl << "Linked List is EMPTY!!! Cannot perform Add Middle" << endl;

	}
	else { //true semasa bil node 2 dan lebih
		display();

		cout << endl << "Kereta baru nk diAdd selepas model mana?: ";
		cin >> mdl;

		while (temp != NULL) {
			if (temp->model == mdl) {
				//stop  traverse
				break;
			}
			else
			{
				//gerakkan temp ke next node 
				temp = temp->next;
			}
		}

		temp = head;
		vehicle* node = new vehicle;

		cout << "\nMasukkan Brand : ";
		getline(cin >> ws, node->brand);

		cout << "Masukkan Model : ";
		getline(cin >> ws, node->model);

		cout << "Masukkan  Tahun Keluaran: ";
		cin >> node->yearmade;

		cout << "Masukkan Harga: ";
		cin >> node->price;

		node->next = temp->next;
		temp->next = node;

	}
}
void addrear() {
	vehicle* node = new vehicle;

	cout << "\nMasukkan Brand : ";
	getline(cin >> ws, node->brand);

	cout << "Masukkan Model : ";
	getline(cin >> ws, node->model);

	cout << "Masukkan  Tahun Keluaran: ";
	cin >> node->yearmade;

	cout << "Masukkan Harga: ";
	cin >> node->price;

	node->next = NULL;
	if (head == NULL)//true utk 1st node
		head = node;
	else {//true utk 2nd, 3rd and the rest
		
		temp = head;
		while (temp -> next != NULL) {
			temp = temp->next;
		}
		head->next = node;
	}
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
			<< tmp->model << "\t"
			<< tmp->price << "\t"
			<< tmp->yearmade << "\t\n";
			
	tmp = tmp ->next;
	

	 }

}