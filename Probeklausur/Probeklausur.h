
// Probeklausur.h: Hauptheaderdatei für die PROJECT_NAME-Anwendung
//

#pragma once

#ifndef __AFXWIN_H__
	#error "'stdafx.h' vor dieser Datei für PCH einschließen"
#endif

#include "resource.h"		// Hauptsymbole


// CProbeklausurApp:
// Siehe Probeklausur.cpp für die Implementierung dieser Klasse
//

class CProbeklausurApp : public CWinApp
{
public:
	CProbeklausurApp();

// Überschreibungen
public:
	virtual BOOL InitInstance();

// Implementierung

	DECLARE_MESSAGE_MAP()
};

extern CProbeklausurApp theApp;