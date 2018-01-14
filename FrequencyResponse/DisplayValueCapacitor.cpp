#include "stdafx.h"
#include "DisplayValueCapacitor.h"


CDisplayValueCapacitor::CDisplayValueCapacitor()
{
}


CDisplayValueCapacitor::~CDisplayValueCapacitor()
{
}

CString CDisplayValueCapacitor::getDisplayValueAsCString(int _index, double _value)
{
	std::stringstream sOutput;
	std::string unit = "F";
	
	if (_index == 0) {
		sOutput << _value << unit;
	}
	else
		if (_index == 1) {
			_value = _value * 1e3;
			sOutput << _value << " m" << unit;
		}
		else
			if (_index == 2) {
				_value = _value * 1e6;
				sOutput << " µ" << unit;
			}
			else
				if (_index == 3) {
					_value = _value * 1e9;
					sOutput << _value << " n" << unit;
				}
				else 
					if (_index == 4) {
					_value = _value * 1e12;
					sOutput << _value << " p" << unit;
					}
					else sOutput << "Error";
	return sOutput.str().c_str();
}

