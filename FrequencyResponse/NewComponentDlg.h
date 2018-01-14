#pragma once
#include "afxwin.h"


// CNewComponentDlg dialog

class CNewComponentDlg : public CDialog
{
	DECLARE_DYNAMIC(CNewComponentDlg)

public:
	CNewComponentDlg(CWnd* pParent = NULL);   // standard constructor
	virtual ~CNewComponentDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_NEW_COMPONENT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	
	CComboBox m_Components;
	CComboBox m_Unit;
	afx_msg void OnCbnSelchangeCombo1();
//	afx_msg void OnBnClickedButton2();
	double value;
	double price;
	int x_coord;
	int y_coord;
	virtual BOOL OnInitDialog();
	int indx;
	int unitIndx;
	afx_msg void OnCbnSelchangeCombo2();
//	afx_msg void OnEnChangeEdit3();
};
