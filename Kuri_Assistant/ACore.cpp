#include "ACore.h"

ACore::ACore()
{
	Dict.import("dictionary.dat");
}

string ACore::Query(const Sentence& question) const
{
	const Node* node = Dict.find_MatchingSentence(question);
	if (node != nullptr && node->next != nullptr)
	{
		return node->next->s_data.getString();
	}
	else return "Not a valid sentence";
}
