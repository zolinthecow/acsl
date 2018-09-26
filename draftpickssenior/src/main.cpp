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

int main(){
	vector<Player> players;
	for(int i=0; i<10; i++){
		string name, bday, city;
		int gender, contractYears;
		double contractAmount, gauranteedAmount;
		cin>>name>>bday>>city>>gender>>contractYears>>contractAmount>>gauranteedAmount;
		contractAmount*=1000000;
		gauranteedAmount*=1000000;
		Player guy(name, bday, city, gender, contractYears, contractAmount, gauranteedAmount);
		players.push_back(guy);
	}
	Player person("ab", "bb", "cbffsdfx", 1, 1, 1, 1);
	cout<<person.range16(players)<<endl<<person.midrange(players)<<endl<<person.highestExpected(players)<<endl
	<<person.averageExpected18(players)<<endl<<person.median(players);
}
