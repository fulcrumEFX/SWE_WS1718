#pragma once
class CDisplayValue
{
public:
	virtual CString getDisplayValueAsCString(int _index, double _value) = 0;
};

class CDisplayValueCapacitor :
	public CDisplayValue
{
public:
	CDisplayValueCapacitor();
	~CDisplayValueCapacitor();
	CString getDisplayValueAsCString(int _index, double _value);
};

class CDisplayValueInductor :
	public CDisplayValue
{
public:
	CDisplayValueInductor();
	~CDisplayValueInductor();
	CString getDisplayValueAsCString(int _index, double _value);
};

class CDisplayValueResistor :
	public CDisplayValue
{
public:
	CDisplayValueResistor();
	~CDisplayValueResistor();
	CString getDisplayValueAsCString(int _index, double _value);
};


