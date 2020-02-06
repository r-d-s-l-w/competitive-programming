#include <iostream>
#include <string>

using namespace std;

string xd(string txt)
{
	string haslo;
	for (int i = 0; i < txt.length(); i += 2)
		haslo += (txt[i]-'A')+(txt[i+1]-'A')*16;
	return haslo;
}

int main()
{
	string txt;
	while (getline(cin, txt))
		cout << xd(txt) << endl;
	return 0;
}


