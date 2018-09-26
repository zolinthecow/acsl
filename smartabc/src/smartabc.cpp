#include <map>
#include <set>
#include <list>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <string>
#include <bitset>
#include <cstdio>
#include <limits>
#include <vector>
#include <climits>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <numeric>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <map>
using namespace std;

int board[3][3];

bool checkRow(int row, int letter){
	for(int i=0; i<3; i++){
		if(board[row][i]==letter){
			return false;
		}
	}
	return true;
}
bool checkColumn(int column, int letter){
	for(int i=0; i<3; i++){
		if(board[i][column]==letter){
			return false;
		}
	}
	return true;
}

void fillBoard(int aCount, int bCount, int cCount){
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(aCount==3){
				break;
			}
			if(checkRow(i, 1) && checkColumn(j, 1) && board[i][j]==0){
				board[i][j]=1;
				aCount++;
			}
		}
	}
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(checkRow(i, 2)){
				if(bCount==3){
					break;
				}
				if(checkRow(i, 2) && checkColumn(j, 2) && board[i][j]==0){
					board[i][j]=2;
					bCount++;
				}
			}
		}
	}
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++){
			if(cCount==3){
				break;
			}
			if(checkRow(i, 3) && checkColumn(j, 3) && board[i][j]==0){
				board[i][j]=3;
				cCount++;
			}
		}
	}
}
int main() {
	int amount;
	cin>>amount;
	int aCount=0, bCount=0, cCount=0;
	for(int i=0; i<amount; i++){
		int place;
		string letter;
		cin>>place>>letter;
		int realLetter;
		place-=1;
		int row=place/3, column=place%3;
		if(letter=="A"){
			realLetter=1;
			aCount++;
		}else if(letter=="B"){
			realLetter=2;
			bCount++;
		}else{
			realLetter=3;
			cCount++;
		}
		board[row][column]=realLetter;
	}
	fillBoard(aCount, bCount, cCount);
	for(int j=0; j<3; j++){
		for(int k=0; k<3; k++){
			if(board[j][k]==1){
				cout<<"A";
			}else if(board[j][k]==2){
				cout<<"B";
			}else{
				cout<<"C";
			}
		}
	}
}
