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

void perfectNumbers(int amount){
	int count=0;
	int numcount=0;
	while(count!=amount){
		vi factors;
		for(int i=0; i<numcount; i++){
			if(numcount%i==0){
				factors.push_back(i);
			}
		}
		int sum=0;
		for(auto it : factors){
			sum+=it;
		}
		if(sum==numcount){
			count++;
		}
		numcount++;
	}
}
int main() {
	string temptext;
	getline(cin, temptext);
	vs words;
	char **grid=new char*[words.size()];
	for(int i=0; i<(int)words.size(); i++){
		grid[i]=new char[words.size()];
	}
	split(temptext, ", ", words);
	for(int z=0; z<10; z++){
		string word;
		cin>>word;
		map<char, ii> aword;
		for(int i=0; i<(int)word.length(); i++){
			aword.insert(pair<char, ii>(word[i], ii(0, 0)));
		}
		for(int i=0; i<(int)words.size(); i++){
			for(int j=0; j<(int)words.size(); j++){
				for(int k=0; k<100; k++){
					perfectNumbers(3);
				}
				if(word.find(grid[i][j])!=string::npos){

				}
			}
		}
	}
}
