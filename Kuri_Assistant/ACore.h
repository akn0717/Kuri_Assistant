#pragma once
#include "Dictionary.h"
class ACore
{
private:
	Dictionary Dict;
public:
	ACore();
	string Query(const Sentence& question) const;
};

