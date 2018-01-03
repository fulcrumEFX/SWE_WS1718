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
	ON_BN_CLICKED(IDC_BUTTON2, &CNewComponentDlg::OnBnClickedButton2)
	ON_CBN_SELCHANGE(IDC_COMBO2, &CNewComponentDlg::OnCbnSelchangeCombo2)

END_MESSAGE_MAP()


// CNewComponentDlg message handlers
BOOL CNewComponentDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	m_Components.AddString("Capacitor");
	m_Components.AddString("Inductor");
	m_Components.AddString("Resistor");

	m_Components.SetCurSel(2);
	return TRUE;  // return TRUE unless you set the focus to a control
				  // EXCEPTION: OCX Property Pages should return FALSE
}

void CNewComponentDlg::OnCbnSelchangeCombo1()
{
	indx = m_Components.GetCurSel();

	if (indx == 0) {
		m_Unit.ResetContent();
		m_Unit.AddString("F");
		m_Unit.AddString("mF");
		m_Unit.AddString("µF");
		m_Unit.AddString("nF");
		m_Unit.AddString("pF");
		m_Unit.SetCurSel(3);
		unitIndx = 3;
	}
	if (indx == 1) {
		m_Unit.ResetContent();
		m_Unit.AddString("H");
		m_Unit.AddString("mH");
		m_Unit.AddString("µH");
		m_Unit.AddString("nH");
		m_Unit.SetCurSel(2);
		unitIndx = 2;
	}
	if (indx == 2) {
		m_Unit.ResetContent();
		m_Unit.AddString("Ohm");
		m_Unit.AddString("kOhm");
		m_Unit.AddString("MOhm");
		m_Unit.SetCurSel(0);
		unitIndx = 0;
	}
}


void CNewComponentDlg::OnBnClickedButton2()
{	
}

void CNewComponentDlg::OnCbnSelchangeCombo2()
{
	unitIndx = m_Unit.GetCurSel();
}


//void CNewComponentDlg::OnEnChangeEdit3()
//{
//	// TODO:  If this is a RICHEDIT control, the control will not
//	// send this notification unless you override the CDialog::OnInitDialog()
//	// function and call CRichEditCtrl().SetEventMask()
//	// with the ENM_CHANGE flag ORed into the mask.
//
//	// TODO:  Add your control notification handler code here
//}
