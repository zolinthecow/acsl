#include <map>
#include <set>
#include <vector>
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
using namespace std;

int main() {
	ifstream fin;
	fin.open("inputdata.txt");
	for(int z=0; z<5; z++){
		int total;
		fin>>total;
		vector<int> playerhand;
		vector<int> remainingcards;
		for(int i=0; i<3; i++){
			int a;
			fin>>a;
			playerhand.push_back(a);
		}
		for(int j=0; j<7; j++){
			int b;
			fin>>b;
			remainingcards.push_back(b);
		}
		int count=2;
		for(vector<int>::iterator itr=remainingcards.begin(); itr!=remainingcards.end(); itr+=2){
			vector<int>::iterator it=playerhand.begin();
			if(*it!=9){
				if(*it==4){
					total-=10;
				}else if(*it==0){
					if(total+11<99){
						total+=11;
					}else{
						total+=1;
					}
				}else{
					total+=*it;
				}
			}
			if(total>99){
				cout<<total<<", "<<"dealer"<<endl;
				break;
			}
			playerhand.erase(playerhand.begin());
			playerhand.push_back(*itr);
			if(*(itr+1)!=9){
				if(*(itr+1)==4){
					total-=10;
				}else if(*(itr+1)==0){
					if(total+11<99){
						total+=11;
					}else{
						total+=1;
					}
				}else{
					total+=*(itr+1);
				}
			}
			if(total>99){
				cout<<total<<", "<<"player"<<endl;
				break;
			}
			count++;
		}
	}
	fin.close();
}
