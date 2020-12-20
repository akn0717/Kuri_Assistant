#pragma once
#include <string>
#include <fstream>
#include <vector>

#include "Ultility.h"

using std::ifstream;
using std::ostream;
using std::string;
using std::vector;

class Sentence
{
public:
	vector<string> keywords;

	Sentence();
	Sentence(const string& s);

	~Sentence();

	Sentence& operator=(const Sentence& s);
	Sentence& operator=(const string& s);

	string getString() const;
	int getSize() const;

	string getWord(const int& index) const;
	
	friend std::ifstream& operator>>(std::ifstream& fin, Sentence& s);

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
	vector<Node> list_node;
public:
	Dictionary();
	Dictionary(const string& path);

	~Dictionary();

	void import(const string& path);
	

	const Node* find_MatchingSentence(const Sentence& s) const;
	void add(const Sentence& s);
	
};

class Word_Detector
{
private:
	vector<int> hash_f;
public:
	/*static int HP_Power[10];*/

	Word_Detector(const Sentence& s);
	~Word_Detector();

	bool findWord(const string& s) const;

	bool isMatching(const Sentence& s) const;
};