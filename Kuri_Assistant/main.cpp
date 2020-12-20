#include "Kuri_Assistant.h"

#include <string>
#include <iostream>
using std::string;
using std::cout;
using std::cin;
using std::getline;
int main()
{
	Kuri_Assistant Kuri;
	string s;
	do
	{
		getline(cin, s);
		cout << Kuri.Query(s) << "\n";
	} while (s != "exit");

	return 0;
}