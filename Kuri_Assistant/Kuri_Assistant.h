#pragma once
#include "ACore.h"
class Kuri_Assistant
{
private:
	ACore Kuri_Core;

public:
	Kuri_Assistant();
	string Query(const string& s) const;
};

