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
#include "player.h"
using namespace std;

player::player(string a, string b, string c, string d, double e, double f, double g){
	name=a;
	bday=b;
	city=c;
	gender=d;
	contractyears=e;
	contractamount=f;
	guaranteedamount=g;
}
int player::range16(map<int, player> players){
	double max, min;
	max=(players.rbegin()->second.contractamount*1000000)/players.rbegin()->second.contractyears;
	min=(players.begin()->second.contractamount*1000000)/players.begin()->second.contractyears;
	return max/16-min/16;
}
int player::midrange(map<int, player> players){
	double max, min;
	max=((players.rbegin()->second.contractamount*1000000)/players.rbegin()->second.contractyears)/18;
	min=((players.begin()->second.contractamount*1000000)/players.begin()->second.contractyears)/18;
	return (max+min)/2;
}
string player::expected16(map<int, player> players){
	int max=0, playernumber;
	for(map<int, player>::iterator itr=players.begin(); itr!=players.end(); itr++){
		int expected=(1-((*itr).second.contractyears)*.03)*
				((*itr).second.contractamount)+
				((*itr).second.contractyears)*.03*((*itr).second.guaranteedamount);
		if(expected>max){
			max=expected;
			playernumber=(*itr).first;
		}
	}
	max*=1000000;
	stringstream ss;
	ss<<max;
	string strmax=ss.str();
	stringstream convert;
	convert<<playernumber;
	string strplayernumber=convert.str();
	string final=strmax+"by #"+strplayernumber;
	return final;
}
int player::averageExpected18(map<int, player> players){
	int average=0;
	for(map<int, player>::iterator itr=players.begin(); itr!=players.end(); itr++){
		average+=(1-((*itr).second.contractyears)*.03375)*
			((*itr).second.contractamount)+
			((*itr).second.contractyears)*.03375*((*itr).second.guaranteedamount);
		average*=1000000;
	}
	return average/10;
}
int median(map<int, player> players){
	int fifth, sixth;
	fifth=players.find(4)->second.contractamount*1000000;
	sixth=players.find(5)->second.contractamount*1000000;
	return (fifth+sixth)/2;
}

