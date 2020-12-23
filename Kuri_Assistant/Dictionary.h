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

	//Constructors
	Sentence();
	Sentence(const string& s);

	~Sentence();

	//Assignment Operators
	Sentence& operator=(const Sentence& s);
	Sentence& operator=(const string& s);

	//Return sentence as a string
	//pre-condition: none
	//post-condition: return a string of sentence
	string getString() const;

	//Get number of words in sentence
	//pre-condition: none
	//post-condition: return number of words in a sentence
	int getSize() const;

	//Return the word at index
	//pre-condition: an integer index
	//post-condition: return a string word at index in sentence
	string getWord(const int& index) const;
	
	//Reading sentence data type (Overloading operator cin)
	//pre-condition: an integer index
	//post-condition: return a string word at index in sentence
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
	//Constructors
	Dictionary();
	Dictionary(const string& path);

	~Dictionary();

	//Adding data from file
	//pre-condition: file path as a string
	//post-condition: add new node and relationship of node
	void import(const string& path);
	
	//find a sentence in dictionary matched a parameter sentence
	//pre-condition: a parameter sentence
	//post-condition: return node pointer points to the node containing matched sentence
	const Node* find_MatchingSentence(const Sentence& s) const;

	//add new node to dictionary
	//pre-conditin: a sentence
	//post-conditon: create and add a new node with data to the current dictionary
	void add(const Sentence& s);
	
};

class Word_Detector
{
private:
	vector<int> hash_f;
public:
	/*static int HP_Power[10];*/

	//Constructors
	Word_Detector(const Sentence& s);
	~Word_Detector();

	//find if the parameter match any word in the current sentence
	//pre-condition: a string
	//post-condition: return 1 if the string s is equal to a word of current sentence
	bool findWord(const string& s) const;

	//find if the parameter match the current sentence of word_detector
	//pre-condition: a sentence
	//post-condition: return 1 if the parameter sentence matches the current sentence store in current Word_Detector, 0 if there is some word in the current sentence cannot be found in the parameter sentence
	bool isMatching(const Sentence& s) const;
};