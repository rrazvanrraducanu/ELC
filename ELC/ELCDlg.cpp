
// ELCDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "ELC.h"
#include "ELCDlg.h"
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


// CELCDlg dialog



CELCDlg::CELCDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_ELC_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CELCDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CELCDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CELCDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CELCDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CELCDlg::OnBnClickedButton3)


END_MESSAGE_MAP()


// CELCDlg message handlers

BOOL CELCDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
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

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CELCDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CELCDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CELCDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CELCDlg::OnBnClickedButton1()
{
	// TODO: Add your control notification handler code here
	CEdit* pe = (CEdit*)GetDlgItem(IDC_EDIT1);
	CListBox* plb = (CListBox*)GetDlgItem(IDC_LIST1);
	CString str;
	pe->GetWindowText(str);
	plb->AddString(str);
}


void CELCDlg::OnBnClickedButton2()
{
	// TODO: Add your control notification handler code here
	CComboBox* pcb = (CComboBox*)GetDlgItem(IDC_COMBO1);
	CListBox* plb = (CListBox*)GetDlgItem(IDC_LIST1);
	CString str;
	int sel = plb->GetCurSel();
	if (sel != CB_ERR) {
		plb->GetText(sel, str);
		pcb->AddString(str);
	}
	else
		MessageBox(_T("Nu ati selectat nimic!"),_T("Message"));
}


void CELCDlg::OnBnClickedButton3()
{
	// TODO: Add your control notification handler code here
	CComboBox* pcb = (CComboBox*)GetDlgItem(IDC_COMBO1);
	CListBox* plb = (CListBox*)GetDlgItem(IDC_LIST1);
	CString str;
	for (int i = 0; i < plb->GetCount(); i++) {
		plb->GetText(i, str);
		pcb->AddString(str);
	}
}



