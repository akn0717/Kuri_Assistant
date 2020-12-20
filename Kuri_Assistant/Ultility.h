#pragma once
#include <string>
#include <vector>
using std::string;
using std::vector;

string string_store_format(const string& s);

int word_count(const string& s);

void copy_string2array(const string& s, vector<string>& sArray);

int hash(const string& Word);
