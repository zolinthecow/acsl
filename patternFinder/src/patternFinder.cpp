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

int grid[8][8];

int stringToInt(string a){
	int result;
	stringstream convert(a);
	if(!(convert>>result)){
		result=-1;//if cannot be converted;
	}
	return result;
}

string charToString(char a){
	stringstream ss;
	string s;
	ss<<a;
	ss>>s;
	return s;
}

string hexBin(string hex){
	string answer;
	if(hex=="0"){
		answer="0000";
	}else if(hex=="1"){
		answer="0001";
	}else if(hex=="2"){
		answer="0010";
	}else if(hex=="3"){
		answer="0011";
	}else if(hex=="4"){
		answer="0100";
	}else if(hex=="5"){
		answer="0101";
	}else if(hex=="6"){
		answer="0110";
	}else if(hex=="7"){
		answer="0111";
	}else if(hex=="8"){
		answer="1000";
	}else if(hex=="9"){
		answer="1001";
	}else if(hex=="A"){
		answer="1010";
	}else if(hex=="B"){
		answer="1011";
	}else if(hex=="C"){
		answer="1100";
	}else if(hex=="D"){
		answer="1101";
	}else if(hex=="E"){
		answer="1110";
	}else{
		answer="1111";
	}
	return answer;
}

bool in(int **subArray, int startheight, int startwidth, int subHeight, int subWidth){
	for(int i=0; i<subHeight; i++){
		for(int j=0; j<subWidth; j++){
			if(grid[i+startheight][j+startwidth]!=subArray[i][j]){
				return false;
			}
		}
	}
	return true;
}
int check(int **subArray, int height, int width, int subHeight, int subWidth){
	int count=0;
	for(int i=0; i<height-subHeight+1; i++){
		for(int j=0; j<width-subWidth+1; j++){
			if(in(subArray, i, j, subHeight, subWidth)){
				count++;
			}
		}
	}
	return count;
}
void fillGrid(vs hex){
	for(int i=0; i<(int)hex.size(); i++){
		string bin=hexBin(charToString(hex[i].at(0)));
		bin.append(hexBin(charToString(hex[i].at(1))));
		for(int j=0; j<(int)bin.length(); j++){
			grid[i][j]=stringToInt(charToString(bin[j]));
		}
	}
}

int main() {
	ifstream fin;
	fin.open("inputg.txt");
	vs hex;
	for(int i=0; i<8; i++){
		string temp;
		fin>>temp;
		hex.push_back(temp);
	}
	fillGrid(hex);
	for(int z=0; z<10; z++){
		int height, width;
		fin>>height>>width;
		vs subBins;
		for(int i=0; i<height; i++){
			string temp;
			fin>>temp;
			subBins.push_back(temp);
		}
		int **subArray;
		subArray=new int*[height];
		for(int i=0; i<height; i++){
			subArray[i]=new int[width];
		}
		for(int i=0; i<(int)subBins.size(); i++){
			for(int j=0; j<(int)subBins[i].length(); j++){
				subArray[i][j]=stringToInt(charToString(subBins[i] [j]));
			}
		}
		cout<<check(subArray, 8, 8, height, width)<<endl;
	}
}
