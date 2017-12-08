#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

bool contains(const string& s, char c){
	for(int i = 0; i < s.size(); i++){
		if(s[i] == c) return true;
	}
	return false;
}

bool contains(const vector<string>& v, const string&s){
	for(int i = 0; i < v.size(); i++){
		if(v[i] == s) return true;
	}
	return false;
}

string bottom_tower(const vector<string>& tower, const vector<vector<string>>& sub_tower){
	int count = 0;
	for(int i = 0; i < tower.size(); i++){
		count = 0;
		for(int j = 0; j < sub_tower.size(); j++){
			if(contains(sub_tower[j], tower[i])){
				count = 0;
				break;
			}
			else count++;
			if(count == sub_tower.size()) return tower[i];
		}
	}
	return "NONE"; //to satisfy the compiler
}

vector<string> split(const string& s, char delim){
	string word;
	vector<string> result;
	for(int i = 0; i < s.size(); i++){
		if(s[i] == delim){
			result.push_back(word);
			word = "";
			i++; //to skip the space followed by delim
		}
		else{
			word += s[i];
		}
	}
	result.push_back(word);
	return result;
}

int main(){
	ifstream list("list.txt");
	vector<string> with_arrow;
	vector<vector<string>> sub_tower;
	string tower;
	while(!list.eof()){
		getline(list, tower);
		if(contains(tower, '>')){
			string tower_name;
			string subtower_names;
			for(int i = 0; tower[i] != ' '; i++){
				tower_name += tower[i];
			}
			with_arrow.push_back(tower_name);
			for(int i = tower.find('>') + 2; i < tower.size(); i++){
				subtower_names += tower[i];
			}
			sub_tower.push_back(split(subtower_names, ','));
		} 
		tower = "";
	}
	cout << bottom_tower(with_arrow, sub_tower) << endl;
}