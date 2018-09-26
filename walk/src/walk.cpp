/*
 * Colin Zhao
 * Legion of Learners
 * Junior Division
 * Contest #3 2017-2018
 */
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
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

int board[4][4];

int stringToInt(string a){
	int result;
	stringstream convert(a);
	if(!(convert>>result)){
		result=-1;//if cannot be converted;
	}
	return result;
}

ii traverseBoard(ii start){
	int hight=start.first, width=start.second;
	for(int i=0; i<6; i++){
		if(board[hight][width]==0){
			board[hight][width]=1;
			width+=1;
			if(width==4){
				width=0;
			}
		}else if(board[hight][width]==1){
			board[hight][width]=2;
			width-=1;
			if(width==-1){
				width=3;
			}
		}else if(board[hight][width]==2){
			board[hight][width]=3;
			hight-=1;
			if(hight==-1){
				hight=3;
			}
		}else if(board[hight][width]==3){
			board[hight][width]=0;
			hight+=1;
			if(hight==4){
				hight=0;
			}
		}
	}
	hight+=1, width+=1;
	ii finish;
	finish.first=hight, finish.second=width;
	return finish;
}
int main() {
	board[0][0]=0;
	for(int i=0; i<4; i++){
		string place;
		cin>>place;
		string zeroes;
		if(place.length()<4){
			for(int j=place.length(); j<4; j++){
				zeroes.append("0");
			}
		}
		zeroes+=place;
		place=zeroes;
		for(int k=0; k<4; k++){
			board[i][k]=stringToInt(place.substr(k, 1));
		}
	}
	for(int l=0; l<5; l++){
		int place1, place2;
		cin>>place1>> place2;
		place1-=1, place2-=1;
		ii startingPlace;
		int tboard[4][4];
		for(int m=0; m<4; m++){
			for(int n=0; n<4; n++){
				tboard[m][n]=board[m][n];
			}
		}
		startingPlace.first=place1, startingPlace.second=place2;
		ii endingPlace=traverseBoard(startingPlace);
		cout<<endingPlace.first<<", "<<endingPlace.second<<endl;
		for(int o=0; o<4; o++){
			for(int p=0; p<4; p++){
				board[o][p]=tboard[o][p];
			}
		}
	}
}
