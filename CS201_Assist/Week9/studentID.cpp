#include <vector>
#include <string>
#include <iostream>
#include "RandGen.h"
using namespace std;























struct studentID
{
	string name;
	unsigned int ID;
};



















void checkIDSequential(const vector<studentID> list, int id) {	
	int size = list.size();
	bool find = false;
	for (int i = 0; i < size; i++) {	
		if(list[i].ID == id) 
			cout << list[i].name << endl;
			find = true;
	}
	if(!find){

		cout <<  id << " student ID is not in the list!" << endl;
	}
	
}





// return true if ID is unique, return false if it already exists in the vector
bool uniqueID(vector<studentID> list, int id){
	for (int i=0; i<list.size(); i++)
		if(list[i].ID == id)
			return false;
	return true;
}

















// creates a new studentID struct and inserts this struct to the list. 
// vector list is passed by reference because it will be modified
void insertID(vector<studentID> & list, int id, string name){
	studentID stu;
	stu.ID = id;
	stu.name = name;
	list.push_back(stu);
}













void printList(vector<studentID> list){	
	cout << endl << "ID" << "\t" << "NAME" << endl;
	for (int i=0; i<list.size(); i++)
		cout << list[i].ID << "\t" << list[i].name << endl; 
	cout << endl;
}














int main(){

	string name;
	RandGen rnd;
	vector<studentID> list;

	cout << "Enter the students name to create list of student, stop process by entering END." << endl;
	cout << "Enter student name and lastname: ";
	getline(cin,name);

	
	if(name == "END"){

		cout << "Your list is empty!" << endl;
	}else{
		while(name != "END"){
			int id;
			do{
				id = rnd.RandInt(10,99);
			}while (!uniqueID(list, id));
			insertID(list, id, name);
			cout << "Enter student name and lastname: ";
			getline(cin,name);
		}

		printList(list);
		int id;
		cout << "Enter an ID to be searched: ";
		cin >> id;
		checkIDSequential(list, id);
	}

	return 0;
}
