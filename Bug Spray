#include<iostream>
#include<cstdlib>
using namespace std;

int stove_on = 1;
int cans = 5;
int found_bugs = 0;
int gassed = 1;
int done = 0;
int room = 2;
int bugs_found = 0;
string action;

int living_room();
int kitchen();
int bathroom();
int bedroom();
int entryway();



int main(){
	cout << "you're standing in the living room of a strange house, this is nothing new to you though\n";
	cout << "you are a bug exterminator and if there are bugs, you will need to gas every room in the house.\n";
	do{
		switch (room){
			case 0:
				cout << "you have been poisoned, better luck in the next life" << endl;
				done = 1;
				break;
			case 2:
				room = living_room();
				break;
			case 3:
				room = kitchen();
				break;
			case 5:
				room = bathroom();
				break;
			case 7:
				room = bedroom();
				break;
			case 11:
				room = entryway();
				break;
			case 13:
				cout << "congratulations! you have exterminated the bugs! you get to keep your job today!" << endl;
				done = 1;
				break;
			default:
				cout << "my bad, I don't know how this happened" << endl;
		}
	cout << endl;
	cout << endl;
	}while(done == 0);
}





int living_room(){
       if ((gassed % 2) == 0)
		return 0;
	cout << "you have enterd the living room" << endl << "you have " << cans << " gas canisters left" << endl;
	cout << "actions available: entryway, kitchen, gas" << endl;
	do{
		cin >> action;
		if ((action == "gas")&&((gassed % 2) != 0)){
			gassed = gassed*2;
			cans--;
			cout << "the room has been gassed, you need to leave, where would you like to go?" << endl;
			cin >> action;
		}
		if (action == "entryway")
			return 11;
		else if (action == "kitchen")
			return 3;
		else
			cout << "there is no doorway to the " << action << endl;
	}while(1==1);
}


int kitchen(){
       if ((gassed % 3) == 0)
		return 0;
	cout << "you have enterd the kitchen" << endl << "you have " << cans << " gas canisters left" << endl;
	if (stove_on == 1){
		cout << "you see the stove was left on. you turn it off. it was lucky you were there" << endl;
		stove_on = 0;
	}
	cout << "actions available: entryway, living_room, bathroom, gas" << endl;
	do{
 	cin >> action;
	if ((action == "gas")&&((gassed % 3) != 0)){
		gassed = gassed*3;
		cans--;
		cout << "the room has been gassed, you need to leave, where would you like to go?" << endl;
		cin >> action;
		}
	if (action == "entryway")
		return 11;
	else if (action == "living_room")
		return 2;
	else if (action == "bathroom")
		return 5;
	else
		cout << "there is no doorway to the " << action << endl;
	}while(1==1);
}


int bathroom(){
       if ((gassed % 5) == 0)
		return 0;
	cout << "you have enterd the bathroom" << endl << "you have " << cans << " gas canisters left" << endl;
	if (bugs_found == 0){
		cout << "you hear a scuttling sound in the walls. bugs. you will need to clear the house of them" << endl;
		bugs_found = 1;
	}
	cout << "actions available: bedroom, kitchen, gas" << endl;
	do{
		cin >> action;
		if ((action == "gas")&&((gassed % 5) != 0)){
			gassed = gassed*5;
			cans--;
			cout << "the room has been gassed, you need to leave, where would you like to go?" << endl;
			cin >> action;
			}
		if (action == "bedroom")
			return 7;
		else if (action == "kitchen")
			return 3;
		else
			cout << "there is no doorway to the " << action << endl;
	}while(1==1);
}


int bedroom(){
       if ((gassed % 7) == 0)
		return 0;
	cout << "you have enterd the bedroom" << endl << "you have " << cans << " gas canisters left" << endl;
	cout << "actions available: entryway, bathroom, gas" << endl;
	do{
 	cin >> action;
	if ((action == "gas")&&((gassed % 7) != 0)){
		gassed = gassed*7;
		cans--;
		cout << "the room has been gassed, you need to leave, where would you like to go?" << endl;
		cin >> action;
		}
	if (action == "entryway")
		return 11;
	else if (action == "bathroom")
		return 5;
	else
		cout << "there is no doorway to the " << action << endl;
	}while(1==1);
}


int entryway(){
       if ((gassed % 11) == 0)
		return 0;
	cout << "you have enterd the entryway" << endl << "you have " << cans << " gas canisters left" << endl;
	cout << "actions available: living_room, bedroom, exit, kitchen, gas" << endl;
	do{
		cin >> action;
		if ((action == "gas")&&((gassed % 11) != 0)){
			gassed = gassed*11;
			cans--;
			cout << "the room has been gassed, you need to leave, where would you like to go?" << endl;
			cin >> action;
			}
		if (action == "bedroom")
			return 7;
		else if (action == "living_room")
			return 2;
		else if (action == "kitchen")
			return 3;
		else if (action == "exit"){
			if (cans == 0)
				return 13;
			else
				cout << "you can't leave yet, not all rooms have been gassed" << endl;
		}
		else
			cout << "there is no doorway to the " << action << endl;
	}while(1==1);
}	
