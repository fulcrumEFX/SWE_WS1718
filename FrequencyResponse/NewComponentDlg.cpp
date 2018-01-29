// NewComponentDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ComplexImpedance.h"
#include "FrequencyResponse.h"
#include "NewComponentDlg.h"
#include "afxdialogex.h"


// CNewComponentDlg dialog

IMPLEMENT_DYNAMIC(CNewComponentDlg, CDialog)

CNewComponentDlg::CNewComponentDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_NEW_COMPONENT, pParent)
	, value(0)
	, price(0)
	, x_coord(0)
	, y_coord(0)
	, indx(0)
	, unitIndx(0)
{

}

CNewComponentDlg::~CNewComponentDlg()
{
}

void CNewComponentDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);

	DDX_Control(pDX, IDC_COMBO1, m_Components);
	DDX_CBIndex(pDX, IDC_COMBO1, indx);
	DDX_Control(pDX, IDC_COMBO2, m_Unit);
	DDX_CBIndex(pDX, IDC_COMBO2, unitIndx);
	DDX_Text(pDX, IDC_EDIT3, value);
	DDV_MinMaxDouble(pDX, value, 0, DBL_MAX);
	DDX_Text(pDX, IDC_EDIT4, price);
	DDV_MinMaxDouble(pDX, price, 0, DBL_MAX);
	DDX_Text(pDX, IDC_EDIT6, x_coord);
	DDX_Text(pDX, IDC_EDIT5, y_coord);
}


BEGIN_MESSAGE_MAP(CNewComponentDlg, CDialog)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CNewComponentDlg::OnCbnSelchangeCombo1)

	ON_CBN_SELCHANGE(IDC_COMBO2, &CNewComponentDlg::OnCbnSelchangeCombo2)

END_MESSAGE_MAP()


// CNewComponentDlg message handlers
BOOL CNewComponentDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_Components.AddString(_T("Capacitor"));
	m_Components.AddString(_T("Inductor"));
	m_Components.AddString(_T("Resistor"));
	m_Unit.AddString(_T("Ohm"));
	m_Unit.AddString(_T("kOhm"));
	m_Unit.AddString(_T("MOhm"));
	m_Components.SetCurSel(2);
	m_Unit.SetCurSel(0);
	unitIndx = m_Unit.GetCurSel();
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

void CNewComponentDlg::OnCbnSelchangeCombo1()
{
	indx = m_Components.GetCurSel();

	if (indx == 0) {
		m_Unit.ResetContent();
		m_Unit.AddString(_T("F"));
		m_Unit.AddString(_T("mF"));
		m_Unit.AddString(_T("µF"));
		m_Unit.AddString(_T("nF"));
		m_Unit.AddString(_T("pF"));
		m_Unit.SetCurSel(3);
		unitIndx = 3;
	}
	if (indx == 1) {
		m_Unit.ResetContent();
		m_Unit.AddString(_T("H"));
		m_Unit.AddString(_T("mH"));
		m_Unit.AddString(_T("µH"));
		m_Unit.AddString(_T("nH"));
		m_Unit.SetCurSel(2);
		unitIndx = 2;
	}
	if (indx == 2) {
		m_Unit.ResetContent();
		m_Unit.AddString(_T("Ohm"));
		m_Unit.AddString(_T("kOhm"));
		m_Unit.AddString(_T("MOhm"));
		m_Unit.SetCurSel(0);
		unitIndx = 0;
	}
}


void CNewComponentDlg::OnCbnSelchangeCombo2()
{
	unitIndx = m_Unit.GetCurSel();
}



