#include "stdafx.h"
#include "DisplayValue.h"

CDisplayValueCapacitor::CDisplayValueCapacitor()
{
}
CDisplayValueCapacitor::~CDisplayValueCapacitor()
{
}
CString CDisplayValueCapacitor::getDisplayValueAsCString(int _index, double _value)
{
	std::stringstream sOutput;


	if (_index == 0) {
		sOutput << _value;
	}
	else
		if (_index == 1) {
			_value = _value * 1e3;
			sOutput << _value;
		}
		else
			if (_index == 2) {
				_value = _value * 1e6;
				sOutput << _value;
			}
			else
				if (_index == 3) {
					_value = _value * 1e9;
					sOutput << _value;
				}
				else
					if (_index == 4) {
						_value = _value * 1e12;
						sOutput << _value;
					}
					else sOutput << "Error";
					return sOutput.str().c_str();
}


CDisplayValueInductor::CDisplayValueInductor()
{
}
CDisplayValueInductor::~CDisplayValueInductor()
{
}
CString CDisplayValueInductor::getDisplayValueAsCString(int _index, double _value)
{
	std::stringstream sOutput;
	

	if (_index == 0) {
		sOutput << _value;
	}
	else
		if (_index == 1) {
			_value = _value * 1e3;
			sOutput << _value;
		}
		else
			if (_index == 2) {
				_value = _value * 1e6;
				sOutput << _value;
			}
			else
				if (_index == 3) {
					_value = _value * 1e9;
					sOutput << _value;
				}
				else sOutput << "Error";
				return sOutput.str().c_str();
}


CDisplayValueResistor::CDisplayValueResistor()
{
}
CDisplayValueResistor::~CDisplayValueResistor()
{
}
CString CDisplayValueResistor::getDisplayValueAsCString(int _index, double _value)
{
	std::stringstream sOutput;
	

	if (_index == 0) {
		sOutput << _value;
	}
	else
		if (_index == 1) {
			_value = _value * 1e-3;
			sOutput << _value;
		}
		else
			if (_index == 2) {
				_value = _value * 1e-6;
				sOutput << _value;
			}
			else sOutput << "Error";

			return sOutput.str().c_str();
}


