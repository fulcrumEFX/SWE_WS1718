
// FrequencyResponseDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ComplexImpedance.h"
#include "NewComponentDlg.h"
#include "FrequencyResponse.h"
#include "FrequencyResponseDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CFrequencyResponseDlg dialog



CFrequencyResponseDlg::CFrequencyResponseDlg(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_FREQUENCYRESPONSE_DIALOG, pParent)
	, onEdit(false)
	, m_Edit1_val(0)
	, m_Edit2_val(0)
	, m_Edit3_val(0)
	, m_Edit4_val(0)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CFrequencyResponseDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_LIST1, m_ComponentList);
	DDX_Control(pDX, IDC_BUTTON1, m_EditSaveBtn);
	DDX_Control(pDX, IDC_EDIT1, m_Edit1);
	DDX_Control(pDX, IDC_EDIT2, m_Edit2);
	DDX_Control(pDX, IDC_EDIT3, m_Edit3);
	DDX_Control(pDX, IDC_EDIT4, m_Edit4);
	DDX_Control(pDX, IDC_COMBO3, m_Unit);
	DDX_Text(pDX, IDC_EDIT1, m_Edit1_val);
	DDX_Text(pDX, IDC_EDIT2, m_Edit2_val);
	DDX_Text(pDX, IDC_EDIT3, m_Edit3_val);
	DDX_Text(pDX, IDC_EDIT4, m_Edit4_val);
}

BEGIN_MESSAGE_MAP(CFrequencyResponseDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON5, &CFrequencyResponseDlg::OnBnClickedButton5)
	ON_LBN_SELCHANGE(IDC_LIST1, &CFrequencyResponseDlg::OnLbnSelchangeList1)
	ON_BN_CLICKED(IDC_BUTTON1, &CFrequencyResponseDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// CFrequencyResponseDlg message handlers

BOOL CFrequencyResponseDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here
	onEdit = false;
	m_EditSaveBtn.SetWindowText(_T("Edit"));

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CFrequencyResponseDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CFrequencyResponseDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CFrequencyResponseDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
	
}



void CFrequencyResponseDlg::OnBnClickedButton5()
{
	CNewComponentDlg newComponent;
	CString cmpName;
	INT_PTR nRet = -1;
	nRet = newComponent.DoModal();
		
	if (nRet == IDOK) {
		if (newComponent.indx == 0) {
			if (newComponent.unitIndx == 1) {
				newComponent.value *= 1e-3;
			}
			if (newComponent.unitIndx == 2) {
				newComponent.value *= 1e-6;
			}
			if (newComponent.unitIndx == 3) {
				newComponent.value *= 1e-9;
			}
			if (newComponent.unitIndx == 4) {
				newComponent.value *= 1e-12;
			}
			cmpPtr = new CCapacitor(newComponent.value, newComponent.x_coord, newComponent.y_coord, newComponent.price);
		}
		if (newComponent.indx == 1) {
			if (newComponent.unitIndx == 1) {
				newComponent.value *= 1e-3;
			}
			if (newComponent.unitIndx == 2) {
				newComponent.value *= 1e-6;
			}
			if (newComponent.unitIndx == 3) {
				newComponent.value *= 1e-9;
			}
			cmpPtr = new CInductor(newComponent.value, newComponent.x_coord, newComponent.y_coord, newComponent.price);

		}
		if (newComponent.indx == 2) {
			if (newComponent.unitIndx == 1) {
				newComponent.value *= 1e3;
			}
			if (newComponent.unitIndx == 2) {
				newComponent.value *= 1e6;
			}
			cmpPtr = new CResistor(newComponent.value, newComponent.x_coord, newComponent.y_coord, newComponent.price);
		}

		ComponentList.add(cmpPtr);
		cmpName = (cmpPtr->getName()).c_str();
		m_ComponentList.AddString(cmpName);
		cmpPtr = NULL;
	}
	else {
		return;
	}
	
}


void CFrequencyResponseDlg::OnLbnSelchangeList1()
{
	node* tmpPtr = NULL;
	CString cs_SelectedItem;
	m_ComponentList.GetText(m_ComponentList.GetCurSel(), cs_SelectedItem);
	std::string SelectedItem((LPCTSTR)cs_SelectedItem);
	tmpPtr = ComponentList.find(SelectedItem);

	CString output;
	CString unit;
	int unitType;		// 0=Capacitor, 1=Inductor, 2=Resistor
	std::stringstream sOutput;

	if (tmpPtr->data->getName()[0] == 'C') {
		/*unit = "F";
		unitType = 0;*/
		m_Unit.ResetContent();
		m_Unit.AddString("F");
		m_Unit.AddString("mF");
		m_Unit.AddString("µF");
		m_Unit.AddString("nF");
		m_Unit.AddString("pF");
	}
	if (tmpPtr->data->getName()[0] == 'L') {
		/*unit = "H";
		unitType = 1;*/
		m_Unit.ResetContent();
		m_Unit.AddString("H");
		m_Unit.AddString("mH");
		m_Unit.AddString("µH");
		m_Unit.AddString("nH");
	}
	if (tmpPtr->data->getName()[0] == 'R') {
		/*unit = "Ohm";
		unitType = 2;*/
		m_Unit.ResetContent();
		m_Unit.AddString("Ohm");
		m_Unit.AddString("kOhm");
		m_Unit.AddString("MOhm");
	}

	double _val = tmpPtr->data->getValue();
	if ((_val < 1e9) && (_val >= 1e6)) {
		/*sOutput << "M" << unit;
		m_Unit.AddString(sOutput.str().c_str());*/
	}else
	if ((_val < 1e6) && (_val >= 1e3)) {
		//sOutput << "k" << unit;

	}else
	if ((_val < 1) && (_val >= 1e-3)) {
		//sOutput << "m" << unit;
	}else
	if ((_val < 1e-3) && (_val >= 1e-6)) {
		//sOutput << "µ" << unit;
	}else
	if ((_val < 1) && (_val >= 1e-9)) {
		//sOutput << "n" << unit;
	}else
	if (_val < 1e-12) {
		//sOutput << "p" << unit;
	}
	else sOutput << unit;
	
	SetDlgItemText(IDC_EDIT1, sOutput.str().c_str());
	sOutput.str(std::string());
	sOutput << tmpPtr->data->getPrice() << "€";
	SetDlgItemText(IDC_EDIT2, sOutput.str().c_str());
	CPointy _pos = tmpPtr->data->getPosition();
	output.Format("%g", _pos.getX());
	SetDlgItemText(IDC_EDIT3, output);
	output.Format("%g", _pos.getY());
	SetDlgItemText(IDC_EDIT4, output);
	
	UpdateData(false);
}


void CFrequencyResponseDlg::OnBnClickedButton1()
{
	if (!onEdit) m_EditSaveBtn.SetWindowText(_T("Save"));
	else m_EditSaveBtn.SetWindowText(_T("Edit"));
	m_Edit1.SetReadOnly(onEdit);
	m_Edit2.SetReadOnly(onEdit);
	m_Edit3.SetReadOnly(onEdit);
	m_Edit4.SetReadOnly(onEdit);

	if (onEdit) {
		UpdateData(false);
		CString cmpName;
		m_ComponentList.GetText(m_ComponentList.GetCurSel(), cmpName);
		std::string sCmpName = cmpName;
		node* CurSelNode = ComponentList.find(sCmpName);
		CurSelNode->data->setValue(m_Edit1_val);
		CurSelNode->data->setPrice(m_Edit2_val);
		CurSelNode->data->setPosition(CPointy(m_Edit3_val, m_Edit4_val));

	}

	onEdit = !onEdit;

	

	
}
