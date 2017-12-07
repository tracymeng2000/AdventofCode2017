#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int convtToInt(const string& s){
	int number = 0;
	int digit = 0;
	int power = 1;
	if(s[0] == '-'){
		for(int i = 1; i < s.size(); i++){
			for(int j = 0; j < s.size() - 1 - i; j++){
				power *= 10;
			}
			digit = s[i] - '0';
			number -= digit * power;
			power = 1;
		}
	}
	else{
		for(int i = 0; i < s.size(); i++){
			for(int j = 0; j < s.size() - 1 - i; j++){
				power *= 10;
			}
			digit = s[i] - '0';
			number += digit * power;
			power = 1;
		}
	}
	return number;

}

int main(){
	ifstream list; 
	list.open("list.txt");
	vector<int> v;
	string number;
	while(! list.eof()){
		getline(list, number);
		v.push_back(convtToInt(number));
		number = "";
	}

	int i = 0;
	int i_prev = 0;
	int count = 0;
	while(i < v.size()){
		i_prev = i;
		i += v[i];
		v[i_prev]++;
		count++;
	}
	cout << count << endl;
}