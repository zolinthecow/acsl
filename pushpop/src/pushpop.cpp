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

vi number;

string charToString(char a){
	stringstream ss;
	string s;
	ss<<a;
	ss>>s;
	return s;
}

void calculate(string type, vs commands){
	for(auto it: commands){
		if(type=="S"){
			if(it.size()>1){
				if(it[0]=='P'){
					number.push_back(stoi(charToString(it[2])));
				}else if(it[0]=='L'){
					int min=100000000, pos;
					for(int i=0; i<(int)number.size(); i++){
						if(number[i]<min){
							pos=i;
							min=number[i];
						}
					}
					number.emplace(number.begin()+pos-1, stoi(charToString(it[2])));
				}else if(it[0]=='H'){
					int max=0, pos;
					for(int i=0; i<(int)number.size(); i++){
						if(number[i]>=max){
							pos=i;
							max=number[i];
						}
					}
					number.emplace(number.begin()+pos, stoi(charToString(it[2])));
				}else{
					int median;
					if(number.size()%2==0){
						vi numb=number;
						sort(numb.begin(), numb.end());
						median=numb[number.size()/2];
					}else{
						vi numb=number;
						sort(numb.begin(), numb.end());
						median=number[(number.size()-1)/2];
					}
					for(int i=0; i<(int)number.size(); i++){
						if(number[i]==median){
							number.emplace(number.begin()+i, stoi(charToString(it[2])));
							break;
						}
					}
				}
			}else{
				if(it=="P"){
					number.erase(number.begin()+number.size()-1);
				}else if(it=="L"){
					int min=100000, pos;
					for(int i=0; i<(int)number.size(); i++){
						if(number[i]<min){
							pos=i;
							min=number[i];
						}
					}
					number.erase(number.begin()+pos);
				}else{
					int max=0, pos;
					for(int i=0; i<(int)number.size(); i++){
						if(number[i]>max){
							pos=i;
							max=number[i];
						}
					}
					number.erase(number.begin()+max);
				}
			}
		}else{
			if(it.size()>1){
				if(it[0]=='P'){
					number.push_back(stoi(charToString(it[2])));
				}else if(it[0]=='L'){
					int min=100000000, pos;
					for(int i=0; i<(int)number.size(); i++){
						if(number[i]<min){
							pos=i;
							min=number[i];
						}
					}
					number.emplace(number.begin()+pos-1, stoi(charToString(it[2])));
				}else if(it[0]=='H'){
					int max=0, pos;
					for(int i=0; i<(int)number.size(); i++){
						if(number[i]>=max){
							pos=i;
							max=number[i];
						}
					}
					number.emplace(number.begin()+pos, stoi(charToString(it[2])));
				}else{
					int median;
					if(number.size()%2==0){
						vi numb=number;
						sort(numb.begin(), numb.end());
						median=numb[number.size()/2];
					}else{
						vi numb=number;
						sort(numb.begin(), numb.end());
						median=number[(number.size()-1)/2];
					}
					for(int i=0; i<(int)number.size(); i++){
						if(number[i]==median){
							number.emplace(number.begin()+i, stoi(charToString(it[2])));
							break;
						}
					}
				}
			}else{
				if(it=="P"){
					number.erase(number.begin());
				}else if(it=="L"){
					int min=100000, pos;
					for(int i=0; i<(int)number.size(); i++){
						if(number[i]<min){
							pos=i;
							min=number[i];
						}
					}
					number.erase(number.begin()+pos);
				}else{
					int max=0, pos;
					for(int i=0; i<(int)number.size(); i++){
						if(number[i]>max){
							pos=i;
							max=number[i];
						}
					}
					number.erase(number.begin()+max);
				}
			}
		}
	}
}
int main() {
	ifstream fin;
	fin.open("input.txt");
	int p;
	fin>>p;
	number.push_back(p);
	while(number.back()!=0){
		int a;
		fin>>a;
		number.push_back(a);
	}
	number.erase(number.begin()+number.size()-1);
	for(int i=0; i<10; i++){
		string a, b;
		fin>>a>>b;
		vs commandstemp;
		commandstemp.push_back(b);
		while(commandstemp.back()!="E"){
			string q;
			fin>>q;
			commandstemp.push_back(q);
		}
		commandstemp.erase(commandstemp.begin()+commandstemp.size()-1);
		calculate(a, commandstemp);
	}
	for(auto it : number){
		cout<<it<<" ";
	}
}
