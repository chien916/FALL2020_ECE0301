// This program demonstrates a simple class.
#include <iostream>//port in precessor
#include <cmath>//port in precessor 
#include <string>//port in precessor 
#include "FlashLight.cpp"
#include "FlashLight.h"
using namespace std;

int main()
{
	FlashLight x;
	x.displayAll();
	int menuChoice = -2;
	double temp = 0;
	while (menuChoice == -2) {//return to the top of the loop, so that the menu is displayed again.
		while (menuChoice <= -1) {
			cout << "\n(1) Change the battery voltage" << endl
				<< "(2) Change the bulb resistance" << endl
				<< "(3) Toggle the switch state" << endl
				<< "(4) Exit the program" << endl;
			cin >> menuChoice;//After the user makes their selection,
			if (menuChoice > 4 || menuChoice < 1)
				menuChoice = -1; //If the user enters anything other than 1 - 4, return to the top of the loop, so that the menu is displayed again.
		}
		switch (menuChoice) {
		case 1:
			cout << "Enter the new battery voltage:";
			cin >> temp;//Then read the user response from the keyboard
			x.setV(temp);//and call the mutator function to update the battery voltage.
			break;
		case 2:
			cout << "Enter the new bulb resistance:";
			cin >> temp;//Then read the user response from the keyboard,
			x.setR(temp);// and call the mutator function to update the bulb resistance.
			break;
		case 3:
			x.toggle();//If the user chooses to toggle the switch state, call the mutator function that does this. There is no need to prompt the user here.
			break;
		case 4:
		default:
			break;
		}
		if (menuChoice >= 1 && menuChoice <= 3) {//if the user chose any of the options 1-3,
			x.displayAll();//display all information about the flashlight,
			menuChoice = -2;
		}
	}
}