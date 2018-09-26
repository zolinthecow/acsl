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
	for(int z=0; z<5; z++){
		int card[5];
		map<int, int> cardAmt;
		for(int i=0; i<5; i++){
			int a;
			cin>>a;
			if(a>=14&&a<=26){
				a-=13;
			}else if(a>=27&&a<=39){
				a-=26;
			}else if(a>=40&&a<=52){
				a-=39;
			}
			card[i]=a;
		}
		for(int j=0; j<5; j++){
			if(cardAmt.find(card[j])==cardAmt.end()){
				cardAmt.insert(pair<int, int>(card[j], 1));
			}else{
				cardAmt.find(card[j])->second+=1;
			}
		}
		int max=1;
		for(map<int, int>::iterator itr=cardAmt.begin(); itr!=cardAmt.end(); itr++){
			if((max==3&&(*itr).second==2)||(max==2&&(*itr).second==3)){
				cout<<"FULL HOUSE"<<endl;
				return 0;
			}
			if((*itr).second>max){
				max=(*itr).second;
			}
		}
		if(max==1){
			cout<<"NONE"<<endl;
		}else{
			switch (max){
			case 2: cout<<"PAIR"<<endl; break;
			case 3: cout<<"THREE OF A KIND"; break;
			case 4: cout<<"FOUR OF A KIND"; break;

			}
		}
	}
}
