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

bool wayToSort(Player p1, Player p2) {
	return (p1.getName().compare(p2.getName()) < 0);
}
vector<Player> sortByName(vector<Player> players){
	sort(players.begin(), players.end(), wayToSort);
	return players;
}
int main(){
	vector<Player> players;
	for(int i=0; i<2; i++){

		string a, b;
		double c, d, e;
		cin>>a>>b>>c>>d>>e;
		Player temp(a, c, b, d, e);
		players.push_back(temp);
	}
	vector<Player> sortedplayers=sortByName(players);
	for(vector<Player>::iterator itr=players.begin(); itr!=players.end(); itr++){
		cout<<(*itr).getAge()<<endl<<(*itr).getAnnualSalary()<<endl;
	}
}




