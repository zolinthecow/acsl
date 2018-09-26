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

int binToDec(string bin){
	bitset<64> bits(bin);
	unsigned long bob=bits.to_ulong();
	return bob;
}

vi calculateSequence(vi fibonacci, int number){
	fibonacci.push_back(0);
	fibonacci.push_back(1);
	int count=2;
	while(fibonacci[count-1]<=number){
		fibonacci.push_back(fibonacci[count-1]+fibonacci[count-2]);
		count++;
	}
	fibonacci.erase(fibonacci.begin()+fibonacci.size()-1);
	fibonacci.erase(fibonacci.begin()+1);
	fibonacci.erase(fibonacci.begin());
	return fibonacci;
}

int main() {
	ifstream fin;
	fin.open("text.txt");
	for(int z=0; z<10; z++){
		if(z<5){
			vi fibonacci;
			int number;
			string test;
			getline(fin, test);
			number=stoi(test);
			fibonacci=calculateSequence(fibonacci, number);
			vi binary(fibonacci.size()+1, 0);
			int difference=number;
			while(difference!=0){
				for(int i=fibonacci.size()-1; i>=0; i--){
					if(fibonacci[i]<=difference && difference!=0){
						difference-=fibonacci[i];
						binary[i]=1;
					}
				}
			}
			binary[fibonacci.size()]=1;
			string binStr;
			for(int i=0; i<(int)binary.size(); i++){
				string temp=to_string(binary[i]);
				binStr.append(temp);
			}
			//binStr.erase(0, min(binStr.find_first_not_of('0'), binStr.size()-1));
			int decAns=binToDec(binStr);
			cout<<setbase(16);
			cout<<decAns<<" ";
			cout<<setbase(10);
			cout<<binStr.length()<<endl;
			fibonacci.empty();
		}else{
			vi fib;
			fib=calculateSequence(fib, 99999);
			string number;
			int length;
			string line;
			getline(fin, line);
			vs temp;
			string delim=", ";
			split(line, delim, temp);
			number=temp[0];
			length=stoi(temp[1]);
			stringstream ss;
			ss<<hex<<number;
			unsigned n;
			ss>>n;
			bitset<64> b(n);
			string binary=b.to_string();
			binary.erase(0, 64-length);
			binary.erase(binary.length()-1);
			int answer=0;
			for(int i=0; i<(int)binary.length(); i++){
				if(binary.at(i)=='1'){
					answer+=fib[i];
				}
			}
			cout<<answer<<endl;
		}
	}
}
