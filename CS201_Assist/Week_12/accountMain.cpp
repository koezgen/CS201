/*
 * In order to demonstrate Account classes. 
 */

#include <iostream>
#include "account.h"
using namespace std;

void displayBalances(Account& a1, Account& a2, Account& a3, Account& a4){
	a1.displayBalance();
	a2.displayBalance();
	a3.displayBalance();
	a4.displayBalance();
}

int main() {
	Account m(0,"Mazhar");
	Account f(1,"Fuat");
	Account o(2,"Ozkan");

	Account a(3);

	// display owners of the ceated accounts
	m.displayOwner();
	f.displayOwner();
	o.displayOwner();
	a.displayOwner();

	// deposit money to accounts of mazhar and fuat
	m.deposit(100);
	f.deposit(150);
	a.deposit(1000);

	// display balance of each account
	cout << endl << "Initial balance of accounts" << endl;
	displayBalances(m, f, o, a);

	// transfer some amount of money from Mazhar's account to Fuat's.
	cout << endl << "Mazhar is transfering 25 ytl to Fuat" << endl;
	m.transfer(f,25);

	// display balance of each account after the transfer
	cout << endl << "Balance of accounts after transfer" << endl;
	displayBalances(m,f,o, a);

	// transfer some amount of money from Mazhar's account to Ozkan's
	cout << endl << "Mazhar is transfering 45 ytl to Ozkan" << endl;
	m.transfer(o,45);

	// display balance of each account after the transfer
	cout << endl << "Balance of accounts after transfer" << endl;
	displayBalances(m,f,o, a);

	// transfer some amount of money from Ozkan's account to Fuat's
	cout << endl << "Ozkan is transfering 50 ytl to Fuat" << endl;
	o.transfer(f,50);

	// display balance of each account after the transfer
	cout << endl << "Balance of accounts after transfer" << endl;
	displayBalances(m,f,o, a);

	// withdraw some money from anonymous account and display new balance
	a.withdraw(100);
	cout << endl << "100 ytl is withdrawn from anonymous account" << endl;
	cout << "Now "; 
	a.displayBalance();
	cout << endl;
	
	return 0;
}