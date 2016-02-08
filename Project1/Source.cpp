#include <iostream>
using namespace std;

void strEmpty(char* someStr, int length) {
	for (int i = 0; i < length; i++) {
		someStr[i] = '\0';
	}
}
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
	int i = 0;
	strEmpty(url, 201);
	while (inputString[i] != '\0') {
		url[i] = inputString[i];
		i++;
	}
}

void webAddressInfo::setWebAddressInfo(char * inputString) {
	int i = 0;
	while (inputString[i] != '\0') {
		url[i] = inputString[i];
	}
}

char* webAddressInfo::getWebAddressInfo() {
	return url;
}

void webAddressInfo::display() {
	int i = 0;
	while (url[i] != '\0') {
		cout << url[i];
		i++;
	}
	cout << endl;
}

browserTab::browserTab() {
	numAddress = 0;
}

browserTab::browserTab(char* inputString) {
	numAddress = 1;
	webAddresses[numAddress - 1] = webAddressInfo(inputString);
	currentAddress = numAddress - 1;
}

webAddressInfo& browserTab::forward() {
	if ((currentAddress + 1) < numAddress) {
		return webAddresses[currentAddress + 1];
	}
	else {
		return webAddresses[currentAddress];
	}
}

webAddressInfo& browserTab::backward() {
	if (currentAddress > 0) {
		return webAddresses[currentAddress - 1];
	}
	else {
		return webAddresses[currentAddress];
	}
}

void browserTab::addAddress(char* inputString) {
	numAddress++;
	webAddresses[numAddress - 1] = webAddressInfo(inputString);
	currentAddress = numAddress - 1;


}

void browserTab::display() {
	webAddresses[currentAddress].display();
}

int main() {
	browserTab myTabs[20];
	int tabNumber = 0;
	int i;
	char webAddress[201];
	char c;
	char blank = ' ';
	char action;

	while (!cin.eof()) { // while end of file is not reached

		cin >> tabNumber;
		cin.get(blank);
		cin.get(action);
		strEmpty(webAddress, 201);
		switch (action) {
		case 'N': {
			i = 0;
			do {
				cin.get(c);
				if (c != '\n') {
					webAddress[i++] = c;
				}
			} while ((c != '\n') && (i < 201) && !cin.eof());
			webAddressInfo* info = new webAddressInfo(webAddress);
			myTabs[tabNumber].addAddress(webAddress);
			cout << tabNumber << " " << action << " " << webAddress << endl;
			break;
		}

		case 'F': {
			if (!cin.eof()) {
				cout << tabNumber << " " << action << " ";
				myTabs[tabNumber].forward().display();
			}
			break;
		}

		case 'B': {
			if (!cin.eof()) {
				cout << tabNumber << " " << action << " ";
				myTabs[tabNumber].backward().display();
			}
			break;
		}

		case 'P': {
			if (!cin.eof()) {
				cout << tabNumber << " " << action << " ";
				myTabs[tabNumber].display();
			}
			break;
		}

		default: {
		}
		}

	}
	return 0;
}