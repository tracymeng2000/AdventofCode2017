#include <iostream>
#include <vector>

using namespace std;
bool seen(const vector<vector<int>>& v, int& index){
	int idt_int = 0;
	for(int i = 0; i < v.size() - 1; i++){
		for(int j = i + 1; j < v.size(); j++){
			for(int k = 0; k < 16; k++){
				if(v[i][k]!= v[j][k]){
					idt_int = 0;
					break;
				}
				else{
					idt_int++;
					if(idt_int ==16){
						index = j;
						for(int n = 0; n < 16; n++){
							cout << v[i -1][n] << " ";
						};

						cout << endl;
						for(int n = 0; n < 16; n++){
							cout << v[i][n] << " ";
						};

						cout << endl;
						for(int n = 0; n < 16; n++){
							cout << v[j][n] << " ";
						};
						return true;
					}
				}
			}
		}
	}
	return false;
}

int gethighest_index(const vector<int>& v){
	int highest = v[0], highest_index = 0;
	for(int i = 0; i < v.size(); i++){
		if(v[i] > highest){
			highest = v[i];
			highest_index = i;
		}
	}
	return highest_index;
}

// void reverse(const vector<int>& v, int start, int end){
// 	while(start < end){
// 		int temp = v[start];
// 		v[start] = v[end];
// 		v[end] = temp;
// 		start++;
// 		end--;
// 	}
// }

// void rotateOnce(const vector<int>& v){
// 	reverse(v, 1, v.size() - 1);
// 	reverse(v, 0, v.size() - 1);
// }

int findi(int i, vector<vector<int>>& combo){

	int n = 0;
	while(true){
		 combo.push_back(combo[i]); //copy previous combination to a new vector
		 int inew = i + 1;
		 int highest_index = gethighest_index(combo[inew]);
		 int total = combo[inew][highest_index];
		 int j = highest_index + 1;
		 if(j > combo[inew].size() - 1) j = 0;
		 while(total > 0){
		 	if(j > combo[inew].size() - 1) j = 0;
		 	combo[inew][j]++;
		 	combo[inew][highest_index]--;
		 	j++;
		 	total--;
		 }
		 n++;
		 //check every 100 rounds
		 if(n % 1000 == 0){
		 	 int index = 0;
			 if(seen(combo, index)){
			 	return index;
			 }
		}

		 i++;
		 cout << "count = " << i << endl;
	}
}

int main(){
	vector<vector<int>> combo;
	vector<int> initial = {4, 10, 4, 1, 8, 4, 9, 14, 5, 1, 14, 15, 0, 15, 3, 5};
	combo.push_back(initial);
	int i2 = 0;
	i2 = findi(0, combo);
	cout << findi(i2, combo);
}