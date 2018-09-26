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

string leet[26];
string letters[26];

int main() {
	string word;
	cin>>word;
	leet[0]="4";
	leet[1]="8";
	leet[2]="[";
	leet[3]=")";
	leet[4]="3";
	leet[5]="|=";
	leet[6]="6";
	leet[7]="#";
	leet[8]="|";
	leet[9]="]";
	leet[10]="|<";
	leet[11]="1";
	leet[12]="^^";
	leet[13]="^";
	leet[14]="0";
	leet[15]="|o";
	leet[16]="9";
	leet[17]="2";
	leet[18]="5";
	leet[19]="7";
	leet[20]="(_)";
	leet[21]="\/"; //THERE IS A PROBLEM HERE WHAT DOES THAT MEAN
	leet[23]="><";
	leet[24]="‘/";
	leet[25]="%";

	letters[0]="A";
	letters[1]="B";
	letters[2]="C";
	letters[3]="D";
	letters[4]="E";
	letters[5]="F";
	letters[6]="G";
	letters[7]="H";
	letters[8]="I";
	letters[9]="J";
	letters[10]="K";
	letters[11]="L";
	letters[12]="M";
	letters[13]="N";
	letters[14]="O";
	letters[15]="P";
	letters[16]="Q";
	letters[17]="R";
	letters[18]="S";
	letters[19]="T";
	letters[20]="U";
	letters[21]="V";
	letters[22]="W";
	letters[23]="X";
	letters[24]="Y";
	letters[25]="Z";

	vector<string> vec;

	/*JAVA THING - CONVERT THIS TO C++
	 *
	 *for (int i = 0; i < word.length(); i++) {
	 *	for (int k = 0; k < 26; k++) {
	 *	  if (word.charAt(i) == letters[k]) {
	 *		vec.add(leet[k]);
	 *	  }
	 *	}
	 *}
	 *
	 *for (int i = 0; i < vec.size(); i++) {
	 *	System.out.print(vec.get(i));
	 *}
	 *System.out.println();
	 *
	 */


}
