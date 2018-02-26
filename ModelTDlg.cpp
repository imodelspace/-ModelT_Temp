//////////////////////////////////////////////////////////////////////////////////////////////////////
// ModelTDlg.cpp : 实现文件

#include "stdafx.h"
#include "ModelT.h"
#include "ModelTDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CModelTDlg 对话框
CModelTDlg::CModelTDlg(CWnd* pParent /*=NULL*/) : CDialogEx(CModelTDlg::IDD, pParent), 
	m_pStateWindow(NULL),
	m_pCommandWindow(NULL)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);

	m_fontTitle.CreatePointFont(320, _T("Calibri"));
	m_fontSubTitle.CreatePointFont(132, _T("Calibri"));

	m_fontText.CreatePointFont(120, _T("Calibri"));
	m_cstrVal0 = _T("");
}

void CModelTDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_STATIC_PORT_VALUE0, m_cstrVal0);
}

BEGIN_MESSAGE_MAP(CModelTDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_WM_CTLCOLOR()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CModelTDlg 消息处理程序
BOOL CModelTDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码
	SetBackgroundColor(RGB(86, 116, 142)/*RGB(137, 165, 178)*/);
	SetBackgroundImage(IDB_BITMAP_BACKGROUNDIMAGE);

	CreateStateWindow();
	CreateCommandWindow();

	GetDlgItem(IDC_STATIC_TITLE)->SetFont(&m_fontTitle);
	GetDlgItem(IDC_STATIC_SUBTITLE)->SetFont(&m_fontSubTitle);

	GetDlgItem(IDC_STATIC_NO_TITLE)->SetFont(&m_fontText);
	GetDlgItem(IDC_STATIC_IP_TITLE)->SetFont(&m_fontText);
	GetDlgItem(IDC_STATIC_PORT_TITLE)->SetFont(&m_fontText);

	SetTimer(0, 1000, NULL);

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

//  如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。
void CModelTDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		unnameFun();

		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR CModelTDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

////////////////////////////////////////////////////////////////////////////////////////////////
//
CModelTDlg::~CModelTDlg()
{
	if (m_pStateWindow != NULL)
	{
		m_pStateWindow->OnBnClickedOk();

		delete m_pStateWindow;
		m_pStateWindow = NULL;
	}

	if (m_pCommandWindow != NULL)
	{
		m_pCommandWindow->OnBnClickedOk();

		delete m_pCommandWindow;
		m_pCommandWindow = NULL;
	}
}

////////////////////////////////////////////////////////////////////////////////////////////////
//
void CModelTDlg::CreateStateWindow()
{
	CRect rectPos;
	GetDlgItem(IDC_STATIC_STATE_RECT)->GetWindowRect(&rectPos);
	ScreenToClient(&rectPos);

	m_pStateWindow = new CStateWindow;
	m_pStateWindow->Create(IDD_STATE_DIALOG);
	m_pStateWindow->MoveWindow(&rectPos);
	m_pStateWindow->ShowWindow(SW_SHOW);
}

////////////////////////////////////////////////////////////////////////////////////////////////
//
void CModelTDlg::CreateCommandWindow()
{
	CRect rectPos;
	GetDlgItem(IDC_STATIC_COMMAND_RECT)->GetWindowRect(&rectPos);
	ScreenToClient(&rectPos);

	m_pCommandWindow = new CCommandWindow;
	m_pCommandWindow->Create(IDD_COMMAND_DIALOG);
	m_pCommandWindow->MoveWindow(&rectPos);
	m_pCommandWindow->ShowWindow(SW_SHOW);
}

////////////////////////////////////////////////////////////////////////////////////////////////
//
HBRUSH CModelTDlg::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	switch (pWnd->GetDlgCtrlID())
	{
	case IDC_STATIC_TITLE:
	case IDC_STATIC_SUBTITLE:
	case IDC_STATIC_NO_TITLE:
	case IDC_STATIC_IP_TITLE:
	case IDC_STATIC_PORT_TITLE:

	case IDC_STATIC_NO_VALUE0:
	case IDC_STATIC_NO_VALUE1:
	case IDC_STATIC_NO_VALUE2:
	case IDC_STATIC_NO_VALUE3:
	case IDC_STATIC_NO_VALUE4:
	case IDC_STATIC_NO_VALUE5:
	case IDC_STATIC_NO_VALUE6:
	case IDC_STATIC_NO_VALUE7:
	case IDC_STATIC_NO_VALUE8:
	case IDC_STATIC_NO_VALUE9:
	case IDC_STATIC_NO_VALUE10:
	case IDC_STATIC_NO_VALUE11:
	case IDC_STATIC_NO_VALUE12:
	case IDC_STATIC_NO_VALUE13:
	case IDC_STATIC_NO_VALUE14:

	case IDC_STATIC_IP_VALUE0:
	case IDC_STATIC_IP_VALUE1:
	case IDC_STATIC_IP_VALUE2:
	case IDC_STATIC_IP_VALUE3:
	case IDC_STATIC_IP_VALUE4:
	case IDC_STATIC_IP_VALUE5:
	case IDC_STATIC_IP_VALUE6:
	case IDC_STATIC_IP_VALUE7:
	case IDC_STATIC_IP_VALUE8:
	case IDC_STATIC_IP_VALUE9:
	case IDC_STATIC_IP_VALUE10:
	case IDC_STATIC_IP_VALUE11:
	case IDC_STATIC_IP_VALUE12:
	case IDC_STATIC_IP_VALUE13:
	case IDC_STATIC_IP_VALUE14:

	case IDC_STATIC_PORT_VALUE0:
	case IDC_STATIC_PORT_VALUE1:
	case IDC_STATIC_PORT_VALUE2:
	case IDC_STATIC_PORT_VALUE3:
	case IDC_STATIC_PORT_VALUE4:
	case IDC_STATIC_PORT_VALUE5:
	case IDC_STATIC_PORT_VALUE6:
	case IDC_STATIC_PORT_VALUE7:
	case IDC_STATIC_PORT_VALUE8:
	case IDC_STATIC_PORT_VALUE9:
	case IDC_STATIC_PORT_VALUE10:
	case IDC_STATIC_PORT_VALUE11:
	case IDC_STATIC_PORT_VALUE12:
	case IDC_STATIC_PORT_VALUE13:
	case IDC_STATIC_PORT_VALUE14:
		{
			pDC->SetTextColor(RGB(255, 255, 255));
			pDC->SetBkMode(TRANSPARENT);

			return (HBRUSH)GetStockObject(NULL_BRUSH);
		}
		break;

	default:
		break;
	}

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}

////////////////////////////////////////////////////////////////////////////////////////////////
//
void CModelTDlg::unnameFun()
{
	CPaintDC dc(this); // device context for painting

	Gdiplus::Graphics graphics(dc.GetSafeHdc());

	Pen penA(Color(192, 255, 255, 255), 2);
	Pen penB(Color(128, 255, 255, 255), 1);
	Pen penC(Color(64, 255, 255, 255), 20);

	CRect rectStaticTemp;

	//GetDlgItem(IDC_STATIC_SUBTITLE)->GetWindowRect(&rectStaticTemp);
	//ScreenToClient(&rectStaticTemp);
	//graphics.DrawLine(&pen, rectStaticTemp.left + 45, rectStaticTemp.top - 3, rectStaticTemp.right - 45, rectStaticTemp.top - 3);

	GetDlgItem(IDC_STATIC_NO_TITLE)->GetWindowRect(&rectStaticTemp);
	ScreenToClient(&rectStaticTemp);
	graphics.DrawLine(&penA, rectStaticTemp.left, rectStaticTemp.top - 3, rectStaticTemp.left + 845, rectStaticTemp.top - 3);
	graphics.DrawLine(&penB, rectStaticTemp.left, rectStaticTemp.bottom + 1, rectStaticTemp.left + 845, rectStaticTemp.bottom + 1);

	GetDlgItem(IDC_STATIC_NO_VALUE14)->GetWindowRect(&rectStaticTemp);
	ScreenToClient(&rectStaticTemp);
	graphics.DrawLine(&penA, rectStaticTemp.left, rectStaticTemp.bottom + 2, rectStaticTemp.left + 845, rectStaticTemp.bottom + 2);

	graphics.DrawLine(&penC, rectStaticTemp.left + 870, rectStaticTemp.bottom - 405, rectStaticTemp.left + 870, rectStaticTemp.bottom + 3);

	// CMemoryDC
}

////////////////////////////////////////////////////////////////////////////////////////////////
//
void CModelTDlg::OnTimer(UINT_PTR nIDEvent)
{
	static int s_tVal = 0;
	CString cstrVal;
	CRect rect;

	switch (nIDEvent)
	{
	case 0:
		{
			++s_tVal;
			cstrVal.Format(_T("%0.5d"), s_tVal);

			m_cstrVal0 = cstrVal;
			UpdateData(FALSE);
			GetDlgItem(IDC_STATIC_PORT_VALUE0)->GetWindowRect(&rect);
			ScreenToClient(&rect);
			InvalidateRect(&rect);

			SetDlgItemText(IDC_STATIC_PORT_VALUE1, cstrVal);
			GetDlgItem(IDC_STATIC_PORT_VALUE1)->GetWindowRect(&rect);
			ScreenToClient(&rect);
			InvalidateRect(&rect);

			GetDlgItem(IDC_STATIC_PORT_VALUE2)->SetWindowText(cstrVal);
			GetDlgItem(IDC_STATIC_PORT_VALUE2)->GetWindowRect(&rect);
			ScreenToClient(&rect);
			InvalidateRect(&rect);
		}
		break;

	default:
		break;
	}

	CDialogEx::OnTimer(nIDEvent);
}
