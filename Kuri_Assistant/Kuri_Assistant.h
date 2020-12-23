#pragma once
#include "ACore.h"
class Kuri_Assistant
{
private:
	ACore Kuri_Core;

public:
	//Constructors
	Kuri_Assistant();

	//make a query
	//pre-condition: a sentence
	//post-condition: a reply string of the core
	string Query(const string& s) const;
};

