#include <iostream>
#include <sstream>
#include <string>
using namespace std;

int main(){
	
	string inputS = "Hello|World|!";
	stringstream ss(inputS);

	string word;
	char delimiter = '|';
	while(getline(ss, word, delimiter))
		cout << word << endl;
	return 0;

}
