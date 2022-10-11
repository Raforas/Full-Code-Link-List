/*

A full code for Single Linked List:

For your reference to Mini Project

*/





/*

Data struct is a database

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
	string idvehicle;
	string brand;
	string model;
	int yearmade;
	float price;
	vehicle* next;
};
vehicle* head; //head  is a start pointer , used to point to the 1st node
vehicle* tmp;  //tmp is a pointer to do a traversing
vehicle* temp;  //temp is a pointer to addrear/addmiddle/delrear by traversing
vehicle* del;	//del is a pointer to delete node in delrear/delmiddle


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
		case 6:delrear(); break;
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

		cout << endl << "Kereta baru nk di Add selepas model mana?: ";
		cin >>  mdl;

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
	if (head == NULL)
	{
		cout << endl << "Linked List is EMPTY!!Cannot perform delete front." << endl;
	}
	else
		head = head->next;

}
void delmiddle(){

	if (head == NULL) //check 0 node
	{
		cout << endl << "Linked List is EMPTY!!Cannot perform delete middle." << endl;
	}
	else if(head->next==NULL) //check 1 node
	{
		cout << endl << "Linked List ONLY have one node!!!Cannot perform delete middle" << endl;
	}
	else if (head -> next -> next==NULL) //chceck 2 node
	{
		cout << endl << "Linked List ONLY have two nodes!!!Cannot perform delete middle" << endl;

	}
	else // 3 node atau lebih
	{
			display();
		//assume model as PRIMARY KEY
		cout <<endl<< "What type of model you want to delete?"<<endl;
		getline(cin >> ws, mdl); //cari node yang  yang user input
		
		temp = head;
		while (temp!=NULL) //traverse 
		{
			if (temp->model==mdl) // to found choosen model
			{

				break;

			}
			else
			{
				del = temp;
				temp = temp->next;

			}//if else
		
		}//end loop
	del->next = temp-> next;
	

	}//nested else


}


void delrear() {
	if (head == NULL) {
		cout << endl << "Linked List is EMPTY!!Cannot perform delete rear." << endl;
	}
	else {
		temp = head;
		while (temp->next != NULL) {
			del = temp;
			temp = temp->next;
		}
		if (head->next == NULL) {
			head = NULL;
		}
		else
			del->next = NULL;
	}
}


void search(){

	bool jumpa=false;

	cout << endl << "Masukkan model yang dicari:"<<endl;
	getline(cin >> ws, mdl);
	tmp = head;
	while (tmp!=NULL)
	{
		if (tmp->model==mdl)
		{
			jumpa = true;

			break;
		}
		else {
			tmp = tmp->next;
		}//if else



	}//end loop
	if (jumpa) {

		cout << endl << mdl << " ada dalam link list" << endl;

	}
	else
	{
		cout << endl << mdl << " tidak ada dalam Link List" << endl;
	}

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