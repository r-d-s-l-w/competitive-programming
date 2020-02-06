// Radek Mysliwiec

#include <iostream>
#include <stdio.h>

using namespace std;
void funkcja(long long int x, long long int y);
int main(){

  int t;
  long long int x, y;

  cin >> t;
  while(t--){
	cin >> x >> y;
	funkcja(x, y);
  }
  return 0;
}

void funkcja(long long int x, long long int y){
    if ((x!=1&&y%(x-1)==0)||(y==0)) cout << "NIE" << endl;
    else cout << "TAK" << endl;
}

