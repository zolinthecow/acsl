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
string toBinary(int n)
{
    string r;
    while(n!=0){
    	r=(n%2==0 ?"0":"1")+r;
    	n/=2;
    }
    if(r.length()==2){
    	r.insert(0, "0");
    }
    if(r.length()==1){
    	r.insert(0,"00");
    }
    if(r.length()==0){
    	r.insert(0,"000");
    }
    return r;
}
string modes(string a, string y){
	string final;
	if(y=="0"){
		if(a.substr(0, 1)=="1"){
			final.append("r");
		}else{
			final.append("-");
		}
		if(a.substr(1, 1)=="1"){
			final.append("w");
		}else{
			final.append("-");
		}
		if(a.substr(2, 1)=="1"){
			final.append("x");
		}else{
			final.append("-");
		}
	}else if(y=="1"||y=="2"){
		if(a.substr(0, 1)=="1"){
			final.append("r");
		}else{
			final.append("-");
		}
		if(a.substr(1, 1)=="1"){
			final.append("w");
		}else{
			final.append("-");
		}
		if(a.substr(2, 1)=="1"){
			final.append("s");
		}else{
			final.append("-");
		}
	}else if(y=="4"){
		if(a.substr(0, 1)=="1"){
			final.append("r");
		}else{
			final.append("-");
		}
		if(a.substr(1, 1)=="1"){
			final.append("w");
		}else{
			final.append("-");
		}
		if(a.substr(2, 1)=="1"){
			final.append("t");
		}else{
			final.append("-");
		}
	}
	return final;
}
int main() {
	/*ifstream kevinisstupid;
	ofstream kevinisamongol;
	kevinisstupid.open("chmodIn.txt");*/
	int a, b, c, z;
	cin>>z>>a>>b>>c;
	string d, e, f, y;
	d=toBinary(a);
	e=toBinary(b);
	f=toBinary(c);
	stringstream ss;
	ss << z;
	y = ss.str();
	cout<<d<<" "<<e<<" "<<f<<" and "<<modes(d, y)<<" "<<modes(e, y)<<" "<<modes(f, y)<<endl;
	//kevinisstupid.close();
}
