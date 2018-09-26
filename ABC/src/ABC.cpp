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

int board[9];

bool rowSolved(int a){
	if(board[a]!=board[a+1] && board[a+1]!=board[a+2] && board[a]!=board[a+2]){
		return true;
	}
	return false;
}
bool columnSolved(int a){
	if(board[a]!=board[a+3] && board[a+3]!=board[a+6] && board[a]!=board[a+6]){
		return true;
	}
	return false;
}
bool solved(){
	if(rowSolved(0) && rowSolved(3) && rowSolved(6) && columnSolved(0) && columnSolved(1) && columnSolved(2)){
		return true;
	}
	return false;
}

void find2(int a, int b, int c){
	if((board[a]==0 && board[b]==0) || (board[a]==0 && board[c]==0) || (board[b]==0 && board[c]==0)){
		return;
	}
	int place=-1;
	if(board[a]==0){
		place=a;
	}else if(board[b]==0){
		place=b;
	}else if(board[c]==0){
		place=c;
	}
	if(place!=-1){
		board[place]=6-(board[a]+board[b]+board[c]);
	}
	return;
}
bool checkRow(int row, int letter){
	for(int i=0; i<3; i++){
		if(board[row*3-i]==letter){
			return false;
		}
	}
	return true;
}
void twoSame(){
	int aCount=0, bCount=0, cCount=0;
	for(int i=0; i<9; i++){
		if(board[i]==1){
			aCount++;
		}else if(board[i]==2){
			bCount++;
		}else if(board[i]==3){
			cCount++;
		}
	}
	if(aCount==2){
		vector<int> aRows, aColumns;
		for(int j=0; j<9; j++){
			if(board[j]==1){
				aRows.push_back(j/3);
				aColumns.push_back(j%3);
			}
		}
		int rowcount=0, columncount=0;
		for(int k=0; k<2; k++){
			rowcount+=aRows[k];
			columncount+=aColumns[k];
		}
		int rowplace=5-rowcount, columnplace=5-columncount;
		board[rowplace*3-columnplace]=1;
	}
	if(bCount==2){
		vector<int> bRows, bColumns;
		for(int j=0; j<9; j++){
			if(board[j]==2){
				bRows.push_back(j/3);
				bColumns.push_back(j%3);
			}
		}
		int rowcount=0, columncount=0;
		for(int k=0; k<2; k++){
			rowcount+=bRows[k];
			columncount+=bColumns[k];
		}
		int rowplbce=5-rowcount, columnplbce=5-columncount;
		board[rowplbce*3-columnplbce]=2;
	}
	if(cCount==2){
		vector<int> cRows, cColumns;
		for(int j=0; j<9; j++){
			if(board[j]==3){
				cRows.push_back(j/3);
				cColumns.push_back(j%3);
			}
		}
		int rowcount=0, columncount=0;
		for(int k=0; k<2; k++){
			rowcount+=cRows[k];
			columncount+=cColumns[k];
		}
		int rowplcce=5-rowcount, columnplcce=5-columncount;
		board[rowplcce*3-columnplcce]=3;
	}
}
void fillBoard(){
	while(!solved()){
		find2(0, 1, 2);
		find2(3, 4, 5);
		find2(6, 7, 8);
		find2(0, 3, 6);
		find2(1, 4, 7);
		find2(2, 5, 8);
		twoSame();
		for(int i=0; i<9; i++){
			if(checkRow(i/3, 1)){
				board[i]=1;
				break;
			}
		}
	}
	return;
}
int main() {
	int amount;
	cin>>amount;
	for(int i=0; i<amount; i++){
		int place;
		string letter;
		cin>>place>>letter;
		int realLetter;
		place-=1;
		if(letter=="A"){
			realLetter=1;
		}else if(letter=="B"){
			realLetter=2;
		}else{
			realLetter=3;
		}
		board[place]=realLetter;
	}
	fillBoard();
	for(int j=0; j<9; j++){
		if(board[j]==1){
			cout<<"A";
		}else if(board[j]==2){
			cout<<"B";
		}else{
			cout<<"C";
		}
	}
}
