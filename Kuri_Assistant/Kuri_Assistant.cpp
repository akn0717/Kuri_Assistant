#include "Kuri_Assistant.h"

Kuri_Assistant::Kuri_Assistant() {};

string Kuri_Assistant::Query(const string& question) const
{
	Sentence s(question);
	return Kuri_Core.Query(s);
}