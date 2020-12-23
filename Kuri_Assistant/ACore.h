#pragma once
#include "Dictionary.h"
class ACore
{
private:
	Dictionary Dict;
public:
	//Constructors
	ACore();

	//make a query
	//pre-condition: a sentence
	//post-condition: a reply string of the core
	string Query(const Sentence& question) const;
};

