
// ProbeklausurDlg.h: Headerdatei
//

#pragma once
#include "afxwin.h"
#include "Strecke.h"


// CProbeklausurDlg-Dialogfeld
class CProbeklausurDlg : public CDialogEx
{
// Konstruktion
public:
	CProbeklausurDlg(CWnd* pParent = NULL);	// Standardkonstruktor

// Dialogfelddaten
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PROBEKLAUSUR_DIALOG };
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
public:
//	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	int m_x;
	int m_y;
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	CStrecke strecke;
	CEdit m_edit1;
	double m_length;
};
