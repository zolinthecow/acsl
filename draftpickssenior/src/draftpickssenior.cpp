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

Player::Player(string a, string b, string c, int d, int e, double f, double g){
	name=a;
	bday=b;
	city=c;
	genderM=d;
	contractYears=e;
	contractAmount=f;
	guaranteedAmount=g;
}

int Player::range16(vector<Player> players){
	int biggest=players.back().contractAmount/16;
	int smallest=players.front().contractAmount/16;
	return biggest-smallest;
}

int Player::midrange(vector<Player> players){
	int biggest=players.back().contractAmount/18;
	int smallest=players.front().contractAmount/18;
	return (biggest+smallest)/2;
}
string Player::highestExpected(vector<Player> players){
	double max=0, count=1, countnumber;
	for(vector<Player>::iterator itr=players.begin(); itr!=players.end(); itr++){
		int e=(1-(*itr).contractYears*.03)*(*itr).contractAmount+(*itr).contractYears * .03*(*itr).guaranteedAmount;
		if(e>max){
			max=e;
			countnumber=count;
		}
		count++;
	}
	string a;
	ostringstream convert;
	convert<<max;
	a=convert.str();
	string b;
	ostringstream converta;
	converta<<countnumber;
	b=converta.str();
	string final=a+" by "+b;
	return final;
}
int Player::averageExpected18(vector<Player> players){
	int count=0;
	for(vector<Player>::iterator itr=players.begin(); itr!=players.end(); itr++){
		int e=((1-(*itr).contractYears*.03)*(*itr).contractAmount+(*itr).contractYears * .03*(*itr).guaranteedAmount)*1000000;
		count+=e;
	}
	return count/10;
}
double Player::median(vector<Player> players){
	vector<int> temp;
	for(vector<Player>::iterator itr=players.begin(); itr!=players.end(); itr++){
		double e=(1-(*itr).contractYears*.03)*(*itr).contractAmount+(*itr).contractYears * .03*(*itr).guaranteedAmount;
		temp.push_back(e);
	}
	double count=0, med;
	for(vector<int>::iterator it=temp.begin(); it!=temp.end(); it++){
		if(count==5||count==6){
			med+=*it;
		}
	}
	return med/2;
}
