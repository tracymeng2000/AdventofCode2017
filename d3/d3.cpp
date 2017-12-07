#include <iostream>
#include <vector>
#include <cstdlib>
using namespace std;

void setToZero(vector<vector<int>>& v, const int rows, const int columns){
	for(int i = 0; i < rows; i++){
		vector<int> column;
		for(int j = 0 ; j < columns; j++){
			column.push_back(0);
		}
		v.push_back(column);
	}
}

void newnum(vector<vector<int>>& v, const int row, const int column){
	v[row][column] = v[row - 1][column - 1] + v[row - 1][column]
				   + v[row - 1][column + 1] + v[row][column - 1]
				   + v[row][column + 1] + v[row + 1][column - 1]
				   + v[row + 1][column + 1] + v[row + 1][column];
	if(v[row][column] >= 325489){
		cout << v[row][column] << endl;
		exit(0);
	}
}

int main(){
	const int row = 250, column = 250;
	int rowc = 250/2 + 1, columnc = 250/2 + 1;
	vector<vector<int>> spiral;
	setToZero(spiral, row, column);
	spiral[rowc][columnc] = 1;
	for(int i = 0; i < row/2; i++){
		if(i % 2 == 0){
			for(int j = 0; j < i + 1; j++){
				newnum(spiral, rowc, columnc + 1);
				columnc++;
			}
			for(int j = 0; j < i + 1; j++){
				newnum(spiral, rowc + 1, columnc);
				rowc++;
			}
		}
		else if(i % 2 == 1){
			for(int j = 0; j < i + 1; j++){
				newnum(spiral, rowc, columnc - 1);
				columnc--;
			}
			for(int j = 0; j < i + 1; j++){
				newnum(spiral, rowc - 1, columnc);
				rowc--;
			}
		}
	}
}