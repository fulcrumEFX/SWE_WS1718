
// Exercise 7Dlg.h : header file
//

#pragma once
#include "afxwin.h"


// CExercise7Dlg dialog
class CExercise7Dlg : public CDialog
{
// Construction
public:
	CExercise7Dlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_EXERCISE7_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	float imag;
	float real;
//	CButton calculate;
	afx_msg void OnBnClickedButton1();
	CListBox ComponentList;
//	CComboBox m_Components;
//	CString m_NameComponents;
//	afx_msg void OnCbnSelchangeCombo1();
};
