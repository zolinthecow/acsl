/*
 * Legion of Learners
 * Colin Zhao
 * Junior Division
 * Fifteen Puzzle
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
typedef vector<string> vs;
#define INF 1000000000;

vi grid(16);

string charToString(char a){
	stringstream ss;
	string s;
	ss<<a;
	ss>>s;
	return s;
}

void swap(string move, int place){
	if(move=="R"){
		grid[place]=grid[place+1];
		grid[place+1]=-1;
	}else if(move=="L"){
		grid[place]=grid[place-1];
		grid[place-1]=-1;
	}else if(move=="A"){
		grid[place]=grid[place-4];
		grid[place-4]=-1;
	}else{
		grid[place]=grid[place+4];
		grid[place+4]=-1;
	}
}

int findBlank(){
	for(int i=0; i<(int)grid.size(); i++){
		if(grid[i]==-1){
			return i;
		}
	}
	return -1;
}

int main() {
	ifstream fin;
	fin.open("input.txt");
	for(int z=0; z<10; z++){
		for(int i=1; i<17; i++){
			grid[i-1]=i;
		}
		int remove;
		fin>>remove;
		string movestring;
		fin>>movestring;
		grid.emplace(grid.begin()+(remove-1), -1);
		grid.erase(grid.begin()+grid.size()-1);
		vs moves;
		for(int i=0; i<(int)movestring.length(); i++){
			moves.push_back(charToString(movestring[i]));
		}
		for(auto it : moves){
			swap(it, findBlank());
		}
		cout<<findBlank()+1<<endl;
	}
}
