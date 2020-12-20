#include "ACore.h"

ACore::ACore()
{
	Dict.import("dictionary.dat");
}

string ACore::Query(const Sentence& question) const
{
	Node* node = Dict.find_MatchingSentence(question);
	if (node != nullptr)
	{
		return node->s_data.getString();
	}
	else return "";
}
