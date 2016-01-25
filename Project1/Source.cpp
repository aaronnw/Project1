#include <iostream> 
using namespace std;

void printThis(int x, int y) {
	cout << "x = " << x << " and y = " << y << endl;
}
int main() {
	int x, y;
	cin >> x;
	cin >> y;
	printThis(x, y);
}


//TODO
//Read input file
//Create array of actions
//Print each action along with its number and result
//