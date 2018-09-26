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

vi firstFit(vi numbers){
	vi answers;
	for(int i=0; i<(int)numbers.size(); i++){
		bool used=false;
		for(int j=0; j<(int)answers.size(); j++){
			if(answers[j]+numbers[i]<=10){
				answers[j]+=numbers[i];
				used=true;
				break;
			}
		}
		if(!used){
			answers.push_back(numbers[i]);
		}
	}
	return answers;
}
vi firstFitIncreasing(vi numbers){
	vi numCopy=numbers;
	sort(numCopy.begin(), numCopy.end());
	vi answers;
	for(int i=0; i<(int)numCopy.size(); i++){
		bool used=false;
		for(int j=0; j<(int)answers.size(); j++){
			if(answers[j]+numCopy[i]<=10){
				answers[j]+=numCopy[i];
				used=true;
				break;
			}
		}
		if(!used){
			answers.push_back(numCopy[i]);
		}
	}
	return answers;
}

int main() {
	for(auto it: test){
		cout<<it<<" ";
	}
	ifstream fin;
	fin.open("text.txt");
	for(int z=0; z<5; z++){
		vi numbers;
		string line;
		getline(fin, line);
		vs nums;
		string delims=", ";
		split(line, delims, nums);
		for(int i=0; i<(int)nums.size(); i++){
			numbers.push_back(stoi(nums[i]));
		}
		vi firstFitg;
		firstFitg=firstFit(numbers);
		vi firstFitIncreasingg;
		firstFitIncreasingg=firstFitIncreasing(numbers);
		for(auto it=firstFitg.begin(); it!=firstFitg.end(); it++){
			cout<<*it<<" ";
		}
		cout<<endl;
		for(auto itr=firstFitIncreasingg.begin(); itr!=firstFitIncreasingg.end(); itr++){
			cout<<*itr<<" ";
		}
		cout<<endl<<endl;
	}
}
