#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

string standard_command;

struct Option{
	bool exist = false;
	bool count = false;
	bool out = false;
	string num;
}option[26];

bool look(char c){
	int pos = c - 'a'; 
	if(option[pos].exist == true)
		return true;
	return false;
}


void read_input_command(void){
	string s, input_command;
	getline(cin, s);
	stringstream ss(s);
	ss >> input_command;

	while(ss >> input_command){
		int  pos = 0;
		bool res;

		if(input_command[0] == '-'){
			res = look(input_command[1]);
			if(res == true){
				pos = input_command[1] - 'a';
				if(option[pos].count == true)
					ss >> option[pos].num;
			} else 
				break;
			option[pos].out = true;
		} else 
			break;
	}
}
/*
	for(int i = start; i < input_command.size(); i++){
		int pos = 0;
		bool res;
		if(input_command[i] == '-'){
			i++;
			res = look(input_command[i]);   
			if(res == true){
				pos = input_command[i] - 'a';
				if(option[pos].count == true){
					int j = i+2;
					string number;
					while(input_command[j] != ' ' && input_command[j] != '\0'){
						number += input_command[j];
						j++;
					}
					option[pos].num = number;
				}
				option[pos].out = true;
			}
			else break;
		}
		else if(input_command[i] >= 'a' && input_command[i] <= 'z'
				&& input_command[i+1] >= 'a' && input_command[i+1] <= 'z')
			break;
	}
*/

// 将读入的标准输入选项进行标记：存在位和计数位
void read_stan_command(void){
	int pos;
	cin >> standard_command;
	for(int i = 0; i < standard_command.size(); i++){
		if(standard_command[i] != ':')
			pos = standard_command[i] - 'a';
		if(standard_command[i+1] == ':')
			option[pos].count = true;
		option[pos].exist = true;
	}
}

void print_res(int i){
	char command;
	string outstring;

	for(int j = 0; j < 26; j++){
		if(option[j].out == true){
			command = j + 'a';
			outstring += '-';
			outstring += command;
			if(option[j].count == true){
				outstring += ' ';
				outstring += option[j].num;
			}
			if(j != 25) outstring += ' ';
		}
	}
	cout << "Case " << i << ": " << outstring << endl;  

	return;
}

void clearOp(void){
	for(int i = 0; i < 26; i++){
		option[i].out = false;
		option[i].num = "";
	}
	return; 
}

int main(){
	int N;
	read_stan_command();
	cin >> N;
	cin.get();
	for(int i = 1; i <= N; i++){
		read_input_command();
		print_res(i);
		clearOp();
	}

	return 0;
}
