#include <iostream>
#include <map>
#include <string>
#include <fstream>
using namespace std;

bool checkFile(string lastname);
void createFile(string firstname,string lastname,int agE);
void displayFile(string lastname);
void update(string lastname);

int main() {
	int option, age;
	string first, last;
	bool x = true, flag;
	while(x) {
		cout << "Select an option:  \n";
		cout << "+======================================+\n";
		cout << "| 1. Enter new Patient                 |\n";
		cout << "| 2. Find Patient Information          |\n";
		cout << "| 3. Update Information                |\n";
		cout << "| 4. Close program                     |\n";
		cout << "+======================================+\n";
		cout << "Enter option:"; cin >> option;
		switch(option) {
		case 1:
			cout << "Enter Patient Last Name:"; cin >> last;
			flag = checkFile(last);
			if(!flag) {
				cout << "\n--- !Patient File already exists! ---\n\n";
			}
			else {
				cout << "Enter Patient First Name: "; cin >> first;
				cout << "Enter Patient Age: "; cin >> age;
				createFile(first,last,age);
			}
			break;
		
		case 2:
			cout << "Enter Patient Last Name: "; cin >> last;
			flag = checkFile(last);
			if(!flag) {
				displayFile(last);
			}
			else {
				cout << "\nPatient file does not exist!\n\n";
			}
			break;
		
		case 3:
			cout << "\nEnter Patient Last Name: "; cin >> last;
			flag = checkFile(last);
			if(!flag) {
				update(last);
			}
			else {
				cout << "\nFile is not present!\n\n";
			}
			break;
		
		case 4:
			x = false;
			break;
			
		default:
			cout << "\nEnter 1,2,3, or 4\n";
		}
	}

}

bool checkFile(string lastname) {
	ifstream input;
	input.open(lastname + ".txt");
	if(input.fail()) {
		return true;
	}
	return false;
}

void createFile(string firstname,string lastname, int agE) {
	ofstream output;
	output.open(lastname + ".txt");
	
	output << "First Name: " << firstname << endl;
	output << "Last Name: " << lastname << endl;
	output << "Age: " << agE <<endl;
	
	output.close();
	bool check;
	check = checkFile(lastname); // Check if file was created
	if(!check) {
		cout << "File created!\n";
	}
	else {
		cout << "There was an error creating Patient file!" << endl;
	}
}

void displayFile(string lastname) {
	ifstream input;
	string line;
	input.open(lastname + ".txt");
	cout << "\n***** PATIENT INFORMATION *****\n\n";
	
	while(getline(input,line)) {
		cout << line << endl;
	}
	cout << endl;cout << endl;
}

void update(string lastname) {
	ofstream output;
	string last, first;
	int aGe;
	
	cout << "Enter Patient First Name: "; cin >> first;
	cout << "Enter Patient Age: "; cin >> aGe;
	
	output.open(lastname + ".txt");
	output << "First Name: " << first << endl;
	output << "Last Name: " << lastname << endl;
	output << "Age: " << aGe << endl;
	output.close();
	
	cout << "\n File updated! \n\n";
}
