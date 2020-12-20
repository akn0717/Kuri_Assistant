#include "ACore.h"


ACore::ACore()
{
	Word_Detector::HP_Power[0] = 1;
	for (int i = 1; i < MAX_LENGTH_WORD; ++i) Word_Detector::HP_Power[i] = (Word_Detector::HP_Power[i - 1] * Hashing_Prime) % Modulo;
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