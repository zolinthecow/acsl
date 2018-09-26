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

int main() {
	ifstream fin;
	fin.open("text.txt");
	for(int z=0; z<10; z++){
		unordered_map<char, ii> chart;
		string code, word;
		int start;
		vi topLabel, sideLabel;
		string line;
		getline(fin, line);
		string delim=", ";
		vs tokens;
		split(line, delim, tokens);
		code=tokens[0];
		word=tokens[1];
		start=stoi(tokens[2]);
		int count=start;
		sideLabel.push_back(-1);
		for(int i=0; i<(int)code.length(); i++){
			if(code.at(i)=='#'){
				topLabel.push_back(count);
				sideLabel.push_back(count);
			}else{
				topLabel.push_back(count);
			}
			if(count==9){
				count=0;
			}else{
				count++;
			}
		}
		vector<char> used;
		sort(sideLabel.begin(), sideLabel.end());
		for(int i=0; i<(int)sideLabel.size(); i++){
			for(int j=0; j<(int)topLabel.size(); j++){
				if(sideLabel[i]==-1){
					chart.emplace(code.at(j), ii(-1, topLabel[j]));
					used.push_back(code.at(j));
				}else{
					char letter=65;
					while(find(used.begin(), used.end(), letter)!=used.end()){
						letter++;
						if(letter>=90){
							if(find(used.begin(), used.end(), '.')==used.end()){
								letter='.';
								break;
							}else{
								letter='/';
								break;
							}
						}
					}
					chart.emplace(letter, ii(sideLabel[i], topLabel[j]));
					used.push_back(letter);
				}
			}
		}
		vi answer;
		for(int i=0; i<(int)word.length(); i++){
			ii temp=chart[word.at(i)];
			if(temp.first!=-1){
				answer.push_back(temp.first);
			}
			if(temp.second!=-1){
				answer.push_back(temp.second);
			}
		}
		for(int i=0; i<(int)answer.size(); i++){
			cout<<answer[i]<<" ";
		}
		cout<<endl;
	}
}
