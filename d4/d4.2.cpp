#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

bool changable(const string& s, const string&t){
	if(s.size() != t.size()) return false;
	else{
		for(char c = 'a'; c <= 'z'; c++){
			int counts = 0, countt = 0;
			for(int i = 0; i < s.size(); i++){
				if(s[i] == c) counts++;
				if(t[i] == c) countt++;
			}
			if(counts != countt) return false;
		}
	}
	return true;
}

bool isValid(const vector<string>& v){
	for(int i = 0; i < v.size(); i++){
		for(int j = 0; j < v.size(); j++){
			if(v[i] == v[j] && i != j) return false;
			if(changable(v[i], v[j]) && i != j) return false;
		}
	}
	return true;
}

int main(){
	ifstream list("list.txt");
	int count = 0;
	while(! list.eof()){
		string passphrase;
		getline(list, passphrase);
		vector<string> v;
		string word;
		for(int i = 0; i < passphrase.size(); i++){
			if(passphrase[i] != ' ' && passphrase[i] != '\n'){
				word += passphrase[i];
			}
			else{
				v.push_back(word);
				word = "";
			}
		}
		v.push_back(word);
		if(isValid(v)) count++;
	}
	cout << count << endl;
}