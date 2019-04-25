#include "PayOff1.h"
#include <minmax.h>

PayOff::PayOff(double Strike_, OptionType TheOptionType_) :
	Strike(Strike_), TheOptionsType(TheOptionType_)
{
}

double PayOff::operator()(double spot) const{
	switch (TheOptionsType) {
	case call:
		return max(spot - Strike, 0.0);
	case put:
		return max(Strike - spot, 0.0);
	default:
		throw("unknown option type found.");
	}
}

