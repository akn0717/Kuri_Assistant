#pragma once
#include "Dictionary.h"

Sentence::Sentence() {}
Sentence::Sentence(const string& s_raw) 
{
	string s = string_store_format(s_raw);
	copy_string2array(s, keywords);
}

Sentence::~Sentence()
{
}

Sentence& Sentence::operator=(const Sentence& s)
{
	if (this == &s) return *this;
	this->keywords = s.keywords;
	return *this;
}

Sentence& Sentence::operator=(const string& s)
{
	*this = Sentence(string_store_format(s));
	return *this;
}

string Sentence::getString() const
{
	string s;
	for (int i = 0; i < keywords.size()-1; ++i)
	{
		s += keywords[i] + ' ';
	}
	s += keywords[keywords.size() - 1];
	return s;
}

int Sentence::getSize() const
{
	return keywords.size();
}

string Sentence::getWord(const int& index) const
{
	return keywords[index];
}

ifstream& operator>>(ifstream& fin, Sentence& s)
{
	string temp = "";
	while (temp== "") getline(fin, temp);
	s = temp;
	return fin;
}

//Dictionary Constructors
Dictionary::Dictionary() 
{}
Dictionary::Dictionary(const string& path)
{
	ifstream fin(path);
	int m,n;
	fin >> n;
	fin >> m;
	Sentence temp;
	for (int i = 0; i < n; ++i)
	{
		fin >> temp;
		add(temp);
	}
	for (int u, v, i = 0; i < m; ++i)
	{
		fin >> u >> v;
		list_node[u].next = &list_node[v];
	}
}


Dictionary::~Dictionary()
{
}

void Dictionary::import(const string& path)
{
	ifstream fin;
	fin.open(path);
	int m,n;
	fin >> n;
	fin >> m;
	Sentence temp;
	for (int i = 0; i < n; ++i)
	{
		fin >> temp;
		add(temp);
	}
	for (int u, v, i = 0; i < m; ++i)
	{
		fin >> u >> v;
		list_node[u].next = &list_node[v];
	}
}

void Dictionary::add(const Sentence& s)
{
	list_node.push_back(Node(s));
}

const Node* Dictionary::find_MatchingSentence(const Sentence& s) const
{
	Word_Detector WD(s);
	for (int i = 0; i < list_node.size(); ++i)
		if (WD.isMatching(list_node[i].s_data)) return &list_node[i];
	return nullptr;
}



Word_Detector::Word_Detector(const Sentence& s)
{
	for (int i = 0; i < s.getSize(); ++i)
	{
		hash_f.push_back(hash(s.getWord(i)));
	}

}

Word_Detector::~Word_Detector()
{
}

bool Word_Detector::findWord(const string& s) const
{
	int hash_s = hash(s);
	for (int i = 0; i < hash_f.size(); ++i)
	{
		if (hash_f[i] == hash_s) return 1;
	}
	return 0;
}

bool Word_Detector::isMatching(const Sentence& s) const
{
	for (int i = 0; i < s.getSize(); ++i)
		if (!findWord(s.getWord(i))) return 0;
	return 1;
}
