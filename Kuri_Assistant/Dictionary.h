#pragma once
#include <string>
#include <map>

#include "Ultility.h"

using std::string;
using std::ifstream;
using std::ofstream;
using std::getline;

class Sentence
{
public:
	string* keywords_ptr;
	int size;
	Sentence();
	Sentence(const string& s);

	~Sentence();

	Sentence& operator=(const Sentence& s);
	Sentence& operator=(const string& s);

	string getString() const;
	int getSize() const;

	string getWord(const int& index) const;
	
	friend ifstream& operator>>(ifstream& fin, Sentence& s);

};

class Node
{
public:
	Sentence s_data;
	Node* next;

	Node() : next(nullptr) {}
	Node(Sentence s) : s_data(s), next(nullptr) {}
	Node(Sentence s, Node* node) : s_data(s), next(node) {}

	void operator=(const Node& node)
	{
		s_data = node.s_data;
		next = node.next;
	}
};

class Dictionary
{
private:
	Node* node_database;
	int size;
	int max_size;
public:
	Dictionary();
	Dictionary(const string& path);

	~Dictionary();

	void import(const string& path)
	{
		size = 0;
		ifstream fin;
		fin.open(path);
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

	Node* find_MatchingSentence(const Sentence& s) const;
	void add(const Sentence& s)
	{
		if (max_size <= size)
		{
			max_size *= 2;
			Node* new_nodelist = new Node[max_size];
			for (int i = 0; i < size; ++i) new_nodelist[i] = node_database[i];
			delete[] node_database;
			node_database = new_nodelist;
		}
		node_database[size++] = Node(s);
	}
};

#define MAX_LENGTH_WORD 10
#define Hashing_Prime 53
#define Modulo 1000007
class Word_Detector
{
private:
	int* hash_f;
	int size;
public:
	static int HP_Power[MAX_LENGTH_WORD];

	Word_Detector(const Sentence& s)
	{
		size = s.getSize();
		hash_f = new int[size];
		for (int i = 0; i < size; ++i)
		{
			string Word = s.getWord(i);
			hash_f[i] = hash(Word,HP_Power,Modulo);
		}

	}
	~Word_Detector()
	{
		delete[] hash_f;
	}

	bool findWord(const string& s) const
	{
		int hash_s = hash(s, HP_Power, Modulo);
		for (int i = 0; i < size; ++i)
		{
			if (hash_f[i] == hash_s) return 1;
		}
		return 0;
	}

	bool isMatching(const Sentence& s) const
	{
		for (int i = 0; i < s.getSize(); ++i)
			if (!findWord(s.getWord(i))) return 0;
		return 1;
	}
};