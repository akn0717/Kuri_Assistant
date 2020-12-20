#include "Dictionary.h"
#include "Ultility.h"
#include <fstream>

Sentence::Sentence() : keywords_ptr(nullptr), size(0) {}
Sentence::Sentence(const string& s_raw) 
{
	string s = string_store_format(s_raw);
	size = word_count(s);
	keywords_ptr = new string[size];
	copy_string2array(s, keywords_ptr);
}

Sentence::~Sentence()
{
	delete[] keywords_ptr;
	keywords_ptr = nullptr;
	size = 0;
}

Sentence& Sentence::operator=(const Sentence& s)
{
	if (this == &s) return *this;
	this->size = s.size;
	for (int i = 0; i < size; ++i) keywords_ptr[i] = s.keywords_ptr[i];
	return *this;
}

Sentence& Sentence::operator=(const string& s)
{
	string ss = string_store_format(s);
	int ss_size = word_count(ss);
	if (size!=0 && size!=ss_size)
	{
		this->~Sentence();
		size = ss_size;
		keywords_ptr = new string[ss_size];
	}
	int cnt = 0;
	for (int i = 0; i < s.size(); ++i)
	{
		if (s[i] == ' ') ++cnt;
		else keywords_ptr[cnt] += s[i];
	}
	return *this;
}

string Sentence::getString() const
{
	string s;
	for (int i = 0; i < size-1; ++i)
	{
		s += keywords_ptr[i] + ' ';
	}
	s += keywords_ptr[size - 1];
	return s;
}

int Sentence::getSize() const
{
	return size;
}

string Sentence::getWord(const int& index) const
{
	return keywords_ptr[index];
}

ifstream& operator>>(ifstream& fin, Sentence& s)
{
	string temp;
	getline(fin, temp);
	s = temp;
	return fin;
}

//Dictionary Constructors
Dictionary::Dictionary() : node_database(nullptr), size(0), max_size(2) 
{
	node_database = new Node[max_size];
}
Dictionary::Dictionary(const string& path) : size(0), max_size(2)
{
	node_database = new Node[max_size];
	ifstream fin(path);
	int m;
	fin >> size;
	fin >> m;
	Sentence temp;
	for (int i = 0; i < size; ++i)
	{
		fin >> temp;
		add(temp);
	}
	for (int u, v, i = 0; i < m; ++i)
	{
		fin >> u >> v;
		node_database[u].next = &node_database[v];
	}
}


Dictionary::~Dictionary()
{
	if (max_size > 0)
	{
		delete[] node_database;
	}
	node_database = nullptr;
	max_size = 0;
	size = 0;
}

Node* Dictionary::find_MatchingSentence(const Sentence& s) const
{
	Word_Detector WD(s);
	for (int i = 0; i < size; ++i)
		if (WD.isMatching(node_database[i].s_data)) return &node_database[i];
	return nullptr;
}