#include "ACore.h"


void initialization()
{
	Word_Detector::HP_Power[0] = 1;
	for (int i = 1; i < MAX_LENGTH_WORD; ++i) Word_Detector::HP_Power[i] = (Word_Detector::HP_Power[i - 1] * Hashing_Prime) % Modulo;
}