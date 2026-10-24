/****************************************************************

	Program Name: Queue Array
	By: Pamela Gloria

****************************************************************/

#include <iostream>
#include <string>
#include "queueArray.h"

using namespace std;



int main() {
	// declare
	int choice;
	string customerName;
	queueArray starbucksQueue;

	do {
		// display menu

		cout << "************************************************" << endl;
		cout << "               STARBUCKS QUEUE" << endl;
		cout << "************************************************" << endl;
		cout << " 1. Create Queue" << endl;
		cout << " 2. Initialize Queue" << endl;
		cout << " 3. Is Queue Empty" << endl;
		cout << " 4. Is Queue Full" << endl;
		cout << " 5. Add Customer" << endl;
		cout << " 6. View First Customer" << endl;
		cout << " 7. View Last Customer" << endl;
		cout << " 8. Remove Top customer" << endl;
		cout << " 9. Display current size of Queue" << endl;
		cout << " 10. Search for Customer" << endl;
		cout << " 11. Display Queue" << endl;
		cout << " 12. Delete Queue" << endl;
		cout << " 13. Exit Menu" << endl;
		cout << "************************************************" << endl;
		cout << " Enter Choice: ";
		cin >> choice;

		// swicth for menu choice
		switch (choice) {
		case 1:
			starbucksQueue.createQueue();
			break;
		case 2:
			starbucksQueue.initializeQueue();
			break;
		case 3:
			// check if Empty
			if (starbucksQueue.isEmptyQueue()) {
				cout << " Starbucks Queue is Empty" << endl;
			}
			else {
				cout << " Starbucks Queue is Not Empty" << endl;
			}
			break;
		case 4:
			// check if Full
			if (starbucksQueue.isFullQueue()) {
				cout << " Starbucks is Full" << endl;
			}
			else {
				cout << " Queue is not Full" << endl;
			}

			break;
		case 5:
			cout << " Enter Starbucks Customer Name: ";
			cin.ignore();
			getline(cin, customerName);
			starbucksQueue.addQueue(customerName);
			break;
		case 6:
			cout << " First Starbucks Customer in Queue: " << starbucksQueue.top() << endl;
			break;
		case 7:
			cout << " Last Starbucks Customer in Queue: " << starbucksQueue.last() << endl;
			break;
		case 8:
			starbucksQueue.next();
			break;
		case 9:
			cout << " " << starbucksQueue.queueSize() << " are in the Starbucks Queue" << endl;
			break;
		case 10:
			cout << " Enter Starbucks Customer Name: ";
			cin.ignore();
			getline(cin, customerName);

			if (starbucksQueue.searchQueue(customerName)) {
				cout << " YAY!!! CUSTOMER FOUND 🎊" << endl;
			}
			else {
				cout << " Customer Not Found 😿" << endl;
			}
			break;
		case 11:
			starbucksQueue.printQueue();
			break;
		case 12:
			starbucksQueue.deleteQueue();
			break;
		case 13:
			cout << " Thank you for coming to Starbucks!!! Please come again 😺🥤";
		default:
			cout << " Invalid choice" << endl;
			break;
		}
	} while (choice != 13);


	return 0;
}