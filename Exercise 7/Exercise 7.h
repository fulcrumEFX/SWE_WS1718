
// Exercise 7.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'stdafx.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CExercise7App:
// See Exercise 7.cpp for the implementation of this class
//

class CExercise7App : public CWinApp
{
public:
	CExercise7App();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CExercise7App theApp;
