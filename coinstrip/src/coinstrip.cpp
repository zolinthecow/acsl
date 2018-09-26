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

int main() {
	int size;
	cin>>size;
	int moves[5];
	for(int z=0; z<5; z++){
		moves[z]=0;
	}
	int coinamount;
	cin>>coinamount;
	int *board;
	board=new int[coinamount+1];
	board[0]=0;
	for(int i=1; i<=coinamount; i++){
		int coin;
		cin>>coin;
		board[i]=coin;
	}
	for(int j=coinamount; j>=0; j--){
		int moveamount=(board[j]-board[j-1])-1;
		for(int m=0; m<moveamount; m++){
			moves[m]++;
		}
	}
	for(int l=0; l<5; l++){
		cout<<moves[l]<<" ";
	}
}
