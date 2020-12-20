#include "Dictionary.h"
#include "Ultility.cpp"

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
	size = 0;
}

bool Sentence::operator==(const string& s_raw) const
{

}

Sentence& Sentence::operator=(const Sentence& s)
{
	this->size = s.size;
	for (int i = 0; i < size; ++i) keywords_ptr[i] = s.keywords_ptr[i];
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




Dictionary::Dictionary(): node_database(nullptr) {}
Dictionary::Dictionary(const string& path)
{

}

Node* Dictionary::find_MatchingSentence(const Sentence& s) const
{
	Word_Detector WD(s);
	for (int i = 0; i < size; ++i)
		if (WD.isMatching(node_database[i].s_data)) return &node_database[i];
	return nullptr;
}