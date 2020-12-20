#include "Ultility.h"
	
string string_store_format(const string& s)
{
	string res = "";
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] != ' ') res += s[i];
		else if (res.size() > 0 && res[res.size() - 1] != ' ') res += ' ';
	}
	while (res[res.size() - 1] == ' ') res.erase(res.size() - 1, 1);
	for (int i = 0; i < res.size(); ++i)
		if (isupper(res[i])) res[i] += 32;
	return res;
}

int word_count(const string& s)
{
	int cnt = 0;
	for (int i = 0; i < s.size(); ++i) if (s[i] == ' ') ++cnt;
	return cnt + 1;
}

void copy_string2array(const string& s, string* sArray)
{
	int arr_size = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == ' ') ++arr_size;
		else sArray[arr_size] += s[i];
	}
}

int hash(const string& Word)
{
	int ans = 0;
	int M = 1e9 + 7;
	int P = 1;
	for (int i = 0; i < Word.size(); ++i)
	{
		ans = (ans + (Word[i] * P) % M) % M;
		P = (P * 53) % M;
	}
	return ans;
}

