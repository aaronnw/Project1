#include <iostream>
using namespace std;

class webAddressInfo {
private:
	char url[201]; //allow a maximum of 200 characters
public:
	webAddressInfo();
	webAddressInfo(char* inputString);
	void setWebAddressInfo(char* inputString);
	char* getWebAddressInfo();
	void display();
};

class browserTab {
protected:
	int numAddress; //Current number of web addresses in this tab
	webAddressInfo webAddresses[20]; //Web addreses in this tab
	int currentAddress; //index of current location in webAddresses
						// other private methods if necessary for this class
public:
	browserTab();
	browserTab(char* inputString); //creates a new tab with the inputString
	webAddressInfo& forward();
	webAddressInfo& backward();
	void addAddress(char* inputString);
	void display();
	// and other public methods if necessary
};

webAddressInfo::webAddressInfo() {
}

webAddressInfo::webAddressInfo(char* inputString) {
}

void webAddressInfo::setWebAddressInfo(char * inputString) {
}

char * webAddressInfo::getWebAddressInfo() {
	return nullptr;
}

void webAddressInfo::display() {
}

browserTab::browserTab() {
}

browserTab::browserTab(char * inputString) {
}

webAddressInfo & browserTab::forward() {
	webAddressInfo a = webAddressInfo();
	return a;
}

webAddressInfo & browserTab::backward() {
	webAddressInfo a = webAddressInfo();
	return a;
}

void browserTab::addAddress(char * inputString) {
}

void browserTab::display() {
	cout << numAddress << endl;
}

int main() {
	browserTab myTabs[20];
	int tabNumber;
	int i;
	char c;
	char blank = ' ';
	char action;

	while (!cin.eof()) { // while end of line is not reached

		cin >> tabNumber;
		cin.get(blank);
		cin.get(action);
		char webAddress[201]; //OG: strEmpty(webAddress, 201);
		switch (action) {
		case 'N':{
			cin.get(blank);
			i = 0;
			do {
				cin.get(c);
				if (c != '\n') {
					webAddress[i++] = c;
					webAddressInfo(webAddress);
					//Add the address info to the browser tab list
				}
			} while ((c != '\n') && (i < 201) && !cin.eof());
			for (int j = 0; j < i; j++) {
				cout << webAddress[j];
			}
			cout << endl;
			break;
		}
				 
		case 'F': {
			cout << "forward" << endl;
			break;
		}
				 
		case 'B': {
			cout << "backward" << endl;
			break;
		}
				  
		case 'P': {
			if (!cin.eof()) cout << "print" << endl;
			break;
		}
				 
		default: {
		}
		}

	}
	return 0;
}