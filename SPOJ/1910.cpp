#include <iostream>
#include <stack>
#include <vector>

using namespace std;


int main(){
	stack < char, vector<char> > word(vector<char>(1001));
	char ch;
	int i = 0;
	while ((ch = cin.get()) != EOF){
		if (ch == '\n'){
			for (; i > 0; --i){
				cout << word.top();
				word.pop();
			}
			cout << endl;
		}
		else{
			word.push(ch);
			++i;
		}
	}

	return 0;
}
