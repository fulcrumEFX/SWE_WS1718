
// GUI_FreqResp.h: Hauptheaderdatei für die PROJECT_NAME-Anwendung
//

#pragma once

#ifndef __AFXWIN_H__
	#error "'stdafx.h' vor dieser Datei für PCH einschließen"
#endif

#include "resource.h"		// Hauptsymbole


// CGUI_FreqRespApp:
// Siehe GUI_FreqResp.cpp für die Implementierung dieser Klasse
//

class CGUI_FreqRespApp : public CWinApp
{
public:
	CGUI_FreqRespApp();

// Überschreibungen
public:
	virtual BOOL InitInstance();

// Implementierung

	DECLARE_MESSAGE_MAP()
};

extern CGUI_FreqRespApp theApp;