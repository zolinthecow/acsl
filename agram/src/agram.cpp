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
using namespace std;

int main() {
	ifstream fin;
	fin.open("data.txt");
	for(int z=0; z<5; z++){
		int a, min=10; char b; bool hasOne=false, hasSuit=false;
		fin>>a>>b;
		cout<<a<<" "<<b<<endl;
		char finalSuit; int finalNum, min2=10;
		for(int i=0; i<5; i++){
			int c; char d;
			fin>>c>>d;
			cout<<c<<" "<<d<<" ";
			if(d==b){
				hasSuit=true;
				if(c<min){
					min=c;
				}
				if(c<min2&&c>a){
					min2=c;
				}
			}
			if(d==b&&c==min2){
				finalSuit=d; finalNum=c;
				hasOne=true;
			}
		}
		if(!hasOne&&!hasSuit){
			cout<<"NONE"<<endl;
		}else if(hasSuit&&!hasOne){
			cout<<min<<", "<<b;
		}else{
			cout<<finalNum<<", "<<finalSuit<<endl;
		}
	}
	fin.close();
}
