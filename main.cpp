#include "Encoder.h"
#include <iostream>
#include <bitset>

void test1() {
  vector<int> freq = {1, 2, 3, 4, 5, 6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26};
  shared_ptr<vector<int> > vPtr = make_shared<vector<int> > (freq);
  Encoder encoder(vPtr);
  shared_ptr<vector<char> > temp = encoder.Encode("abc");
  for(int i = 0; i < temp -> size(); i++) {
    bitset<8> y(temp -> at(i));
    cout << y;
  }
  cout << endl;

}

void test2() {
	vector<int> freq = {3, 2, 1, 1, 2, 3, 2, 2, 4, 7, 9, 2, 4, 4, 4, 1, 1, 1, 4, 3, 1, 4, 2, 3, 2, 9};
shared_ptr<vector<int> > vPtr = make_shared<vector<int> > (freq);
Encoder encoder(vPtr);
/*
x: 1111
r: 100011
u: 11001
v: 0001
z: 001
o: 0110
s: 0111
m: 0100
n: 0101
g: 10100
h: 10101
i: 1001
d: 110001
p: 100010
y: 00001      
l: 10110	
w: 10111
e: 10000
c: 110000
f: 1101
a: 00000
t: 1110
*/
//Encoding
shared_ptr<vector<char> > temp = encoder.Encode("happy");
for(int i = 0; i < temp -> size(); i++) {
  bitset<8> y(temp -> at(i));
  cout << y;
}
cout << endl;
//00001101 01000011 10000111 00101101 00010000
//Decoding
vector<char> m ={'0','0', '0','0','1','1', '0','1','0','1','0','0','0', '0','1','1','1','0','0','0','0','1','1','1','0','0','1','0','1','1','0','1','0','0','0','1','0','0','0','0'};
shared_ptr<vector<char> > temp2 = make_shared<vector<char> >(m);
cout << encoder.Decode(temp2) << endl;
//meow
}
 
int main() {
test1();
cout << "First test case done" << endl;
}
