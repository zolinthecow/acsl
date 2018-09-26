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

int **graphMatrix;
int vertices;
vector<int> components;

string hexToBinary(string hex) {
	string result;
	int length = hex.length();
	for (int i = 0; i < length; i++) {
		string temp=hex.substr(i, 1);
		if(temp=="0"){
			result.append("0000");
		}else if(temp=="1"){
			result.append("0001");
		}else if(temp=="2"){
			result.append("0010");
		}else if(temp=="3"){
			result.append("0011");
		}else if(temp=="4"){
			result.append("0100");
		}else if(temp=="5"){
			result.append("0101");
		}else if(temp=="6"){
			result.append("0110");
		}else if(temp=="7"){
			result.append("0111");
		}else if(temp=="8"){
			result.append("1000");
		}else if(temp=="9"){
			result.append("1001");
		}else if(temp=="A"){
			result.append("1010");
		}else if(temp=="B"){
			result.append("1011");
		}else if(temp=="C"){
			result.append("1100");
		}else if(temp=="D"){
			result.append("1101");
		}else if(temp=="E"){
			result.append("1110");
		}else if(temp=="F"){
			result.append("1111");
		}
	}
	return result;
}
void createGraph(string hexstring ){
	int previousloop=0;
	for(int i=1; i<=vertices; i++){
		int at=i-1;
		for(int j=previousloop; j<previousloop+(vertices-i); j++){
			if(at==i-1){
				at++;
			}
			if(hexstring.at(j)=='1'){
				graphMatrix[i-1][at]=1;
				graphMatrix[at][i-1]=1;
			}
			at++;
		}
		previousloop=(previousloop+(vertices-i));
	}
}
void largestComponent(int x){
	if(find(components.begin(), components.end(), x)!=components.end()){
		return;
	}else{
		components.push_back(x);
		for(int i=0; i<vertices; i++){
			if(graphMatrix[x][i]==1){
				largestComponent(i);
			}
		}
	}
}
int main() {
	string hex;
	cin>>vertices>>hex;
	graphMatrix=new int*[vertices];
	for(int i=0; i<vertices; i++){
		graphMatrix[i]=new int[vertices];
	}
	for(int j=0; j<vertices; j++){
		for(int k=0; k<vertices; k++){
			graphMatrix[j][k]=0;
		}
	}
	createGraph(hexToBinary(hex));
	largestComponent(0);
	sort(components.begin(), components.end());

	for(vector<int>::iterator itr=components.begin(); itr!=components.end(); itr++){
		char temp=*itr+65;
		cout<<temp;
	}

}
