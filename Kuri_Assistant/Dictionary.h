#pragma once
#include <string>
#include <map>
using std::string;
using std::map;

#define MAX_NUMBER_KEYWORD 100

class Sentence
{
public:
	string* keywords_ptr;
	int size;
	Sentence();
	Sentence(const string& s);

	~Sentence();

	bool operator==(const string& s) const;

	Sentence& operator=(const Sentence& s);

	string getString() const;
	int getSize() const;

	string getWord(const int& index) const;
	

};

class Node
{
public:
	Sentence s_data;
	Node* next;

	Node(Sentence s) : s_data(s), next(nullptr) {}
	Node(Sentence s, Node* node) : s_data(s), next(node) {}
};

class Dictionary
{
private:
	map<string, Node*> dictionary_map;
	Node* node_database;
	int size;
public:
	Dictionary();
	Dictionary(const string& path);

	~Dictionary();

	void import(const string& path);
	void export(const string& path) const;

	Node* find_MatchingSentence(const Sentence& s) const;
	
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