
// FrequencyResponseDlg.cpp : implementation file
//

#include "stdafx.h"
#include "ComplexImpedanceSerial.h"
#include "ComplexImpedanceParallel.h"
#include "DisplayValue.h"
#include "NewComponentDlg.h"
#include "Graph.h"
#include "LinkedList.h"
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
	
	, m_freq_val(0)
	, m_real(0)
	, m_imag(0)
	, m_xcoord(0)
	, m_ycoord(0)
	, m_fmin(0)
	, m_fmax(0)
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
	DDX_Control(pDX, IDC_BUTTON6, m_save);
	DDX_Control(pDX, IDC_EDIT6, m_frequency);
	DDX_Text(pDX, IDC_EDIT6, m_freq_val);
	DDX_Control(pDX, IDC_EDIT8, m_Edit8);
	DDX_Control(pDX, IDC_EDIT7, m_Edit7);
	DDX_Text(pDX, IDC_EDIT8, m_real);
	DDX_Text(pDX, IDC_EDIT7, m_imag);
	//  DDX_Control(pDX, IDC_EDIT9, m_Edit9);
	//  DDX_Text(pDX, IDC_EDIT9, m_xcoord);
	//  DDX_Control(pDX, IDC_EDIT10, m_Edit10);
	//  DDX_Text(pDX, IDC_EDIT10, m_ycoord);
	DDX_Control(pDX, IDC_EDIT11, m_Edit_fmin);
	DDX_Control(pDX, IDC_EDIT12, m_Edit_fmax);
	DDX_Text(pDX, IDC_EDIT11, m_fmin);
	DDX_Text(pDX, IDC_EDIT12, m_fmax);
}

BEGIN_MESSAGE_MAP(CFrequencyResponseDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON5, &CFrequencyResponseDlg::OnBnClickedButton5)
	ON_LBN_SELCHANGE(IDC_LIST1, &CFrequencyResponseDlg::OnLbnSelchangeList1)
	ON_BN_CLICKED(IDC_BUTTON1, &CFrequencyResponseDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON4, &CFrequencyResponseDlg::OnBnClickedButton4)
	ON_BN_CLICKED(IDC_BUTTON6, &CFrequencyResponseDlg::OnBnClickedButton6)
	ON_BN_CLICKED(IDC_BUTTON7, &CFrequencyResponseDlg::OnBnClickedButton7)
	ON_BN_CLICKED(IDC_BUTTON8, &CFrequencyResponseDlg::OnBnClickedButton8)
	ON_WM_MOUSEMOVE()
	ON_BN_CLICKED(IDC_BUTTON8, &CFrequencyResponseDlg::OnBnClickedButton8)
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
	m_Edit1.SetWindowTextA(_T(""));
	m_Edit2.SetWindowTextA(_T(""));
	m_Edit3.SetWindowTextA(_T(""));
	m_Edit4.SetWindowTextA(_T(""));

	CButton* pButton1 = (CButton*)this->GetDlgItem(IDC_RADIO1);
	pButton1->SetFocus();
	pButton1->SetCheck(true);

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
	CPaintDC dc(this);
	diagram.draw(&dc, ComponentList);
	
	if (IsIconic())
	{
		//CPaintDC dc(this); // device context for painting

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
			cmpPtr->setUnitIndex(newComponent.unitIndx);
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
			cmpPtr->setUnitIndex(newComponent.unitIndx);
		}
		if (newComponent.indx == 2) {
			if (newComponent.unitIndx == 1) {
				newComponent.value *= 1e3;
			}
			if (newComponent.unitIndx == 2) {
				newComponent.value *= 1e6;
			}
			cmpPtr = new CResistor(newComponent.value, newComponent.x_coord, newComponent.y_coord, newComponent.price);
			cmpPtr->setUnitIndex(newComponent.unitIndx);
		}
		
		
		/*
		CString unit;
		newComponent.m_Unit.GetLBText(newComponent.m_Unit.GetCurSel(), unit);
		double correctionFactor = ConvertUnitToValue(unit);
		newComponent.value *= correctionFactor;

		if (newComponent.indx == 0) {
			cmpPtr = new CCapacitor(newComponent.value, newComponent.x_coord, newComponent.y_coord, newComponent.price);
			cmpPtr->setUnitIndex(newComponent.unitIndx);
		}if (newComponent.indx == 1) {
			cmpPtr = new CInductor(newComponent.value, newComponent.x_coord, newComponent.y_coord, newComponent.price);
			cmpPtr->setUnitIndex(newComponent.unitIndx);
		}if (newComponent.indx == 2) {
			cmpPtr = new CResistor(newComponent.value, newComponent.x_coord, newComponent.y_coord, newComponent.price);
			cmpPtr->setUnitIndex(newComponent.unitIndx);
		}
		*/
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
	std::stringstream sOutput;

	if (tmpPtr->data->getName()[0] == 'C') {
		m_Unit.ResetContent();
		m_Unit.AddString(_T("F"));
		m_Unit.AddString(_T("mF"));
		m_Unit.AddString(_T("µF"));
		m_Unit.AddString(_T("nF"));
		m_Unit.AddString(_T("pF"));
		CDisplayValue* displayCmpVal = new CDisplayValueCapacitor;
		tmpPtr->data->setDisplayVal(displayCmpVal);
	}
	if (tmpPtr->data->getName()[0] == 'L') {
		m_Unit.ResetContent();
		m_Unit.AddString(_T("H"));
		m_Unit.AddString(_T("mH"));
		m_Unit.AddString(_T("µH"));
		m_Unit.AddString(_T("nH"));
		CDisplayValue* displayCmpVal = new CDisplayValueInductor;
		tmpPtr->data->setDisplayVal(displayCmpVal);
	}
	if (tmpPtr->data->getName()[0] == 'R') {
		m_Unit.ResetContent();
		m_Unit.AddString(_T("Ohm"));
		m_Unit.AddString(_T("kOhm"));
		m_Unit.AddString(_T("MOhm"));
		CDisplayValue* displayCmpVal = new CDisplayValueResistor;
		tmpPtr->data->setDisplayVal(displayCmpVal);
	}	
	
	m_Unit.SetCurSel(tmpPtr->data->getUnitIndex());
	SetDlgItemText(IDC_EDIT1, tmpPtr->data->getDisplayValueAsC_Str(tmpPtr->data->getUnitIndex(), tmpPtr->data->getValue()));
	sOutput.str(std::string());
	sOutput << tmpPtr->data->getPrice();
	SetDlgItemText(IDC_EDIT2, sOutput.str().c_str());
	CPointy _pos = tmpPtr->data->getPosition();
	output.Format("%g", _pos.getX());
	SetDlgItemText(IDC_EDIT3, output);
	output.Format("%g", _pos.getY());
	SetDlgItemText(IDC_EDIT4, output);
	
	UpdateData(true);
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
		UpdateData(true);
		CString cmpName;

		m_ComponentList.GetText(m_ComponentList.GetCurSel(), cmpName);
		std::string sCmpName((LPCTSTR)cmpName);
		node* CurSelNode = ComponentList.find(sCmpName);
		/*	if (CurSelNode->data->getName()[0] == 'R') {
				int _indx = m_Unit.GetCurSel();
				CurSelNode->data->setUnitIndex(_indx);
				if (_indx == 1) m_Edit1_val *= 1e3;
				else if (_indx == 2) m_Edit1_val *= 1e6;
			}
			else {
				int _indx = m_Unit.GetCurSel();
				CurSelNode->data->setUnitIndex(_indx);
				if (_indx == 1) m_Edit1_val *= 1e-3;
				else if (_indx == 2) m_Edit1_val *= 1e-6;
				else if (_indx == 3) m_Edit1_val *= 1e-9;
				else if (_indx == 4) m_Edit1_val *= 1e-12;
				m_Unit.GetLBText(m_Unit.GetCurSel());
			}*/
		CString unit;
		m_Unit.GetLBText(m_Unit.GetCurSel(), unit);
		CurSelNode->data->setUnitIndex(m_Unit.GetCurSel());
		double correctionFactor = ConvertUnitToValue(unit);
		m_Edit1_val *= correctionFactor;
		CurSelNode->data->setValue(m_Edit1_val);
		CurSelNode->data->setPrice(m_Edit2_val);
		CurSelNode->data->setPosition(CPointy(m_Edit3_val, m_Edit4_val));
	}
	onEdit = !onEdit;
}

void CFrequencyResponseDlg::OnBnClickedButton4()
{
	UpdateData(true);
	CComplexImpedance* circuitWiring;
	CButton* _isPressedSerial;
	_isPressedSerial = (CButton*)(GetDlgItem(IDC_RADIO1));
	if (_isPressedSerial->GetCheck() == BST_CHECKED) circuitWiring = new CComplexImpedanceSerial();
	else circuitWiring = new CComplexImpedanceParallel();
	ComponentList.setWiringPtr(circuitWiring);
	
	double _omega = FreqToOmega(m_freq_val);
	CComplex Impedance = ComponentList.getComplexImpedance(_omega, ComponentList.getHead());
	m_real = Impedance.getReal();
	m_imag = Impedance.getImag();
	UpdateData(false);
}

void CFrequencyResponseDlg::OnBnClickedButton6()		//Save Component list in file
{
	char szFilters[] = "Text Files (*.txt)|*.txt|All Files (*.*)|*.*||";
	CFileDialog saveDlg(FALSE, "txt", ".txt", OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, szFilters, this);

	if (saveDlg.DoModal() == IDOK)
	{
		node* ptr = NULL;
		CString m_strPathname = saveDlg.GetPathName();
		std::ofstream listData;

		listData.open(m_strPathname);
		if (!listData) AfxMessageBox(_T("Wrong Filetype!"), MB_OK | MB_ICONSTOP);
		listData << "Name	Value	Indx	Pos.	Price" << std::endl;
		for (ptr = ComponentList.getHead(); ptr != NULL; ptr = ptr->next) {
			listData << ptr->data->getName() << "	" << ptr->data->getValue() << "	" 
				<< ptr->data->getUnitIndex() << "	" << (ptr->data->getPosition()).getX() << " " 
				<< (ptr->data->getPosition()).getY() << "	" << ptr->data->getPrice() << "	" << std::endl;
		}
		listData.close();
	}
}

void CFrequencyResponseDlg::OnBnClickedButton7()		//Load Component list from file
{
	char szFilters[] = "Text Files (*.txt)|*.txt|All Files (*.*)|*.*||";
	CFileDialog loadDlg(TRUE, "txt", ".txt", OFN_FILEMUSTEXIST | OFN_HIDEREADONLY, szFilters, this);
	

	if (loadDlg.DoModal()) {

		node* ptr = NULL;
		CString m_strPathname = loadDlg.GetPathName();
		std::ifstream listData;
		std::string line;

		listData.open(m_strPathname);
		if (!listData) AfxMessageBox(_T("Error!\nUnable to open file"), MB_OK | MB_ICONSTOP);
		
		getline(listData, line);
		for (std::string line; std::getline(listData, line);) {
			std::istringstream in(line);
			std::string name;
			float value, x_pos, y_pos, price;
			int _unitIndex;

			in >> name >> value >> _unitIndex >> x_pos >> y_pos >> price;
			if (name[0] == 'R') {
				cmpPtr = new CResistor(value, x_pos, y_pos, price);
			}
			if (name[0] == 'L') {
				cmpPtr = new CInductor(value, x_pos, y_pos, price);
			}
			if (name[0] == 'C') {

				cmpPtr = new CCapacitor(value, x_pos, y_pos, price);
			}
			cmpPtr->setUnitIndex(_unitIndex);
			ComponentList.add(cmpPtr);
			m_ComponentList.AddString(name.c_str());
			cmpPtr = NULL;
		}
	}
}

double CFrequencyResponseDlg::ConvertUnitToValue(CString _unit) {
	
	if (_unit[0] == 'm') return 1e-3;
	if (_unit[0] == 'µ') return 1e-6;
	if (_unit[0] == 'n') return 1e-9;
	if (_unit[0] == 'p') return 1e-12;
	if (_unit[0] == 'M') return 1e6;
	if (_unit[0] == 'k') return 1e3;

	return 0;
}

void CFrequencyResponseDlg::OnBnClickedButton8()
{
	CComplexImpedance* circuitWiring;
	CButton* _isPressedSerial;
	_isPressedSerial = (CButton*)(GetDlgItem(IDC_RADIO1));
	if (_isPressedSerial->GetCheck() == BST_CHECKED) circuitWiring = new CComplexImpedanceSerial();
	else circuitWiring = new CComplexImpedanceParallel();
	ComponentList.setWiringPtr(circuitWiring);



}

double CFrequencyResponseDlg::FreqToOmega(double _frequency) {
	return _frequency * 2 * M_PI;
}
