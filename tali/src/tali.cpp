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
#include <unordered_map>
#include <iomanip>
#include <math.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<string> vs;
#define INF 1000000000;

inline bool TextContains(const char *text, char ch) {
  while ( *text ) {
    if ( *text++ == ch )
      return true;
  }
  return false;
}
void split(string textg, string delimsg, vector<string> &words) {
  const char *text=textg.c_str();
  const char *delims=delimsg.c_str();
  int beg;
  for (int i = 0; text[i]; ++i) {
    // While the current char is a delimiter, inc i
    while ( text[i] && TextContains(delims, text[i]) )
      ++i;
    // Beginning of word
    beg = i;
    // Continue until end of word is reached
    while ( text[i] && !TextContains(delims, text[i]) )
      ++i;
    // Add word to vector
    words.push_back( string(&text[beg], &text[i]) );
  }
}

string charToString(char a){
	stringstream ss;
	string s;
	ss<<a;
	ss>>s;
	return s;
}

int main() {
	ifstream fin;
	fin.open("text.txt");
	for(int z=0; z<5; z++){
		string line;
		getline(fin, line);
		vs temp;
		string delims=", ";
		split(line, delims, temp);
		string a, b, c, d;
		a=temp[0];
		b=temp[1];
		c=temp[2];
		d=temp[3];
		int atotal=0, btotal=0, ctotal=0, dtotal=0;
		vector<char> testa(a.begin(), a.end());
		vector<char> testb(b.begin(), b.end());
		vector<char> testc(c.begin(), c.end());
		vector<char> testd(d.begin(), d.end());
		int amax=0, bmax=0, cmax=0, dmax=0;
		for(int i=0; i<4; i++){
			atotal+=stoi(charToString(a.at(i)));
			btotal+=stoi(charToString(b.at(i)));
			ctotal+=stoi(charToString(c.at(i)));
			dtotal+=stoi(charToString(d.at(i)));
			amax=max(amax, stoi(charToString(a.at(i))));
			bmax=max(bmax, stoi(charToString(b.at(i))));
			cmax=max(cmax, stoi(charToString(c.at(i))));
			dmax=max(dmax, stoi(charToString(d.at(i))));
		}
		if(find(testa.begin(), testa.end(), '1')!=testa.end() &&
			find(testa.begin(), testa.end(), '3')!=testa.end() &&
			find(testa.begin(), testa.end(), '4')!=testa.end() &&
			find(testa.begin(), testa.end(), '6')!=testa.end()){
			atotal=100;
		}
		if(find(testb.begin(), testb.end(), '1')!=testb.end() &&
				find(testb.begin(), testb.end(), '3')!=testb.end() &&
				find(testb.begin(), testb.end(), '4')!=testb.end() &&
				find(testb.begin(), testb.end(), '6')!=testb.end()){
			btotal=100;
		}
		if(find(testc.begin(), testc.end(), '1')!=testc.end() &&
				find(testc.begin(), testc.end(), '3')!=testc.end() &&
				find(testc.begin(), testc.end(), '4')!=testc.end() &&
				find(testc.begin(), testc.end(), '6')!=testc.end()){
			ctotal=100;
		}
		if(find(testd.begin(), testd.end(), '1')!=testd.end() &&
				find(testd.begin(), testd.end(), '3')!=testd.end() &&
				find(testd.begin(), testd.end(), '4')!=testd.end() &&
				find(testd.begin(), testd.end(), '6')!=testd.end()){
			dtotal=100;
		}
		vii scores={ii(atotal, amax), ii(btotal, bmax), ii(ctotal, cmax), ii(dtotal, dmax)};
		vector< pair<char, int> > winners={pair<char, int>('A', amax), pair<char, int>('B', bmax), pair<char, int>('C', cmax), pair<char, int>('D', dmax)};
		for(int i=0; i<(int)scores.size(); i++){
			for(int j=0; j<(int)scores.size(); j++){
				if(scores[j].first>scores[i].first){
					auto it=find(winners.begin(), winners.end(), pair<char, int>(i+65, scores[i].second));
					winners.erase(it);
					break;
				}
			}
		}
		sort(winners.begin(), winners.end());
		vector< pair<char, int> > realwinners=winners;
		for(int i=0; i<(int)winners.size(); i++){
			for(int j=0; j<(int)winners.size(); j++){
				if(winners[j].second>winners[i].second){
					auto it=find(realwinners.begin(), realwinners.end(), winners[i]);
					realwinners.erase(it);
				}
			}
		}
		for(int i=0; i<(int)realwinners.size(); i++){
			cout<<realwinners[i].first<<" ";
		}
		cout<<endl;
	}
}
