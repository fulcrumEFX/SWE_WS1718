
// GUI_FreqRespDlg.h: Headerdatei
//

#pragma once


// CGUI_FreqRespDlg-Dialogfeld
class CGUI_FreqRespDlg : public CDialogEx
{
// Konstruktion
public:
	CGUI_FreqRespDlg(CWnd* pParent = NULL);	// Standardkonstruktor

// Dialogfelddaten
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_GUI_FREQRESP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV-Unterstützung


// Implementierung
protected:
	HICON m_hIcon;

	// Generierte Funktionen für die Meldungstabellen
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
};
