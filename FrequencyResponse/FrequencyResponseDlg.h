
// FrequencyResponseDlg.h : header file
//

#pragma once
#include "afxwin.h"
#include "LinkedList.h"
#include "Component.h"



// CFrequencyResponseDlg dialog
class CFrequencyResponseDlg : public CDialog
{
// Construction
public:
	CFrequencyResponseDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FREQUENCYRESPONSE_DIALOG };
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
	CComponent* cmpPtr;
	CLinkedList ComponentList;
	
	bool onEdit;		// true -> 'Edit Mode' , false -> 'Static Mode'
	double m_Edit1_val;
	double m_Edit2_val;
	double m_freq_val;
	double m_real;
	double m_imag;
	int m_Edit3_val;
	int m_Edit4_val;
	
	CListBox m_ComponentList;
	CButton m_save;
	CButton m_EditSaveBtn;
	CEdit m_frequency;
	CComboBox m_Unit;
	CEdit m_Edit1;
	CEdit m_Edit2;
	CEdit m_Edit3;
	CEdit m_Edit4;
	CEdit m_Edit8;
	CEdit m_Edit7;

	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton5();
	afx_msg void OnLbnSelchangeList1();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton6();
	afx_msg void OnBnClickedButton7();

	double ConvertUnitToValue(CString _unit);

};
