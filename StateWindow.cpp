// StateWindow.cpp : 实现文件
//

#include "stdafx.h"
#include "ModelT.h"
#include "StateWindow.h"
#include "afxdialogex.h"

// CStateWindow 对话框

IMPLEMENT_DYNAMIC(CStateWindow, CDialogEx)

	CStateWindow::CStateWindow(CWnd* pParent /*=NULL*/) : CDialogEx(CStateWindow::IDD, pParent), 
	m_bStartup(false)
{
	m_fontA.CreatePointFont(128, _T("Calibri"));
	m_fontB.CreatePointFont(118, _T("Calibri"));
	m_fontC.CreatePointFont(98, _T("Calibri"));
	m_brushBlueA.CreateSolidBrush(RGB(51, 100, 156));
	m_brushBlueB.CreateSolidBrush(RGB(0, 114, 198));
	m_brushBlueC.CreateSolidBrush(RGB(52, 72, 97));
	m_brushDarkA.CreateSolidBrush(RGB(35, 45, 57));
	m_brushDarkB.CreateSolidBrush(RGB(20, 26, 26));
	//m_brushGrayA.CreateSolidBrush(RGB(176, 176, 176));
}

CStateWindow::~CStateWindow()
{
}

void CStateWindow::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CStateWindow, CDialogEx)
	ON_BN_CLICKED(IDOK, &CStateWindow::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CStateWindow::OnBnClickedCancel)
	ON_WM_CTLCOLOR()
	ON_WM_PAINT()
END_MESSAGE_MAP()

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
BOOL CStateWindow::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	SetBackgroundColor(RGB(86, 116, 142)/*RGB(137, 165, 178)*/);

	Init();

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
void CStateWindow::OnBnClickedOk()
{
	DestroyWindow();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
void CStateWindow::OnBnClickedCancel()
{
	DestroyWindow();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
HBRUSH CStateWindow::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)
{
	HBRUSH hbr = CDialogEx::OnCtlColor(pDC, pWnd, nCtlColor);

	// TODO:  在此更改 DC 的任何特性
	switch (pWnd->GetDlgCtrlID())
	{
	case IDC_STATIC_S_TIMER:
		{
			pDC->SetTextColor(RGB(255, 255, 255));
			//if (m_bStartup)
			//{
			//	pDC->SetTextColor(RGB(255, 255, 255));
			//} 
			//else
			//{
			//	pDC->SetTextColor(RGB(255, 0, 0));
			//}

			pDC->SetBkMode(RGB(42, 106, 152));
			pDC->SelectObject(&m_fontA);

			return (HBRUSH)m_brushBlueA;
		}
		break;

	case IDC_STATIC_S_STAGE_TITLE:
		{
			pDC->SetTextColor(RGB(255, 255, 255));
			pDC->SetBkMode(TRANSPARENT/*RGB(35, 45, 57)*/);
			pDC->SelectObject(&m_fontC);

			return (HBRUSH)GetStockObject(NULL_BRUSH);//m_brushDarkA;
		}
		break;

	case IDC_STATIC_S_STAGE_VALUE:
		{
			pDC->SetTextColor(RGB(255, 255, 255));
			//pDC->SetBkMode(RGB(20, 26, 26));
			pDC->SelectObject(&m_fontB);

			return (HBRUSH)m_brushBlueC;
		}
		break;

	case IDC_STATIC_S_CPU_TITLE:
	case IDC_STATIC_S_MEMORY_TITLE:
	case IDC_STATIC_S_NETA_TITLE:
	case IDC_STATIC_S_NETB_TITLE:
		{
			pDC->SetTextColor(RGB(255, 255, 255));
			pDC->SetBkMode(TRANSPARENT);
			pDC->SelectObject(&m_fontC);

			return (HBRUSH)GetStockObject(NULL_BRUSH);
		}
		break;

	case IDC_STATIC_S_CPU_VALUE:
	case IDC_STATIC_S_MEMORY_VALUE:
	case IDC_STATIC_S_NETA_VALUE:
	case IDC_STATIC_S_NETB_VALUE:
		{
			pDC->SetTextColor(RGB(255, 255, 255));
			pDC->SetBkMode(TRANSPARENT);
			pDC->SelectObject(&m_fontB);

			return (HBRUSH)m_brushBlueA;
		}
		break;

	default:
		break;
	}

	// TODO:  如果默认的不是所需画笔，则返回另一个画笔
	return hbr;
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
void CStateWindow::OnPaint()
{
	CPaintDC dc(this); // device context for painting

	// 定义一个画图对象  
	Gdiplus::Graphics graphics(dc.GetSafeHdc());  

	// 获取视图客户区大小  
	CRect rt;

	// Timer
	// GetDlgItem(IDC_STATIC_S_TIMER)->GetWindowRect(&rt);
	// ScreenToClient(&rt);
	// LinearGradientBrush linGrBrush0(Point(rt.left, rt.top), Point(rt.right, rt.bottom), Color(255, 58, 72, 81), Color(255, 131, 141, 166));  
	// graphics.FillRectangle(&linGrBrush0, rt.left, rt.top, rt.Width(), rt.Height());

	//  !!! 能否用赋值？
	GetDlgItem(IDC_STATIC_S_STAGE_TITLE)->GetWindowRect(&rt);
	ScreenToClient(&rt);
	LinearGradientBrush linGrBrush1(Point(rt.left, rt.top), Point(rt.right, rt.bottom), Color(255, 0, 0, 0), Color(255, 52, 72, 97));  
	graphics.FillRectangle(&linGrBrush1, rt.left, rt.top, rt.Width(), rt.Height());

	//
	GetDlgItem(IDC_STATIC_S_CPU_TITLE)->GetWindowRect(&rt);
	ScreenToClient(&rt);
	LinearGradientBrush linGrBrush2(Point(rt.left, rt.top), Point(rt.right, rt.bottom), Color(255, 42, 45, 55), Color(255, 98, 107, 124));  
	graphics.FillRectangle(&linGrBrush2, rt.left, rt.top, rt.Width(), rt.Height());

	GetDlgItem(IDC_STATIC_S_MEMORY_TITLE)->GetWindowRect(&rt);
	ScreenToClient(&rt);
	LinearGradientBrush linGrBrush3(Point(rt.left, rt.top), Point(rt.right, rt.bottom), Color(255, 42, 45, 55), Color(255, 98, 107, 124));  
	graphics.FillRectangle(&linGrBrush3, rt.left, rt.top, rt.Width(), rt.Height());

	GetDlgItem(IDC_STATIC_S_NETA_TITLE)->GetWindowRect(&rt);
	ScreenToClient(&rt);
	LinearGradientBrush linGrBrush4(Point(rt.left, rt.top), Point(rt.right, rt.bottom), Color(255, 42, 45, 55), Color(255, 98, 107, 124));  
	graphics.FillRectangle(&linGrBrush4, rt.left, rt.top, rt.Width(), rt.Height());

	GetDlgItem(IDC_STATIC_S_NETB_TITLE)->GetWindowRect(&rt);
	ScreenToClient(&rt);
	LinearGradientBrush linGrBrush5(Point(rt.left, rt.top), Point(rt.right, rt.bottom), Color(255, 42, 45, 55), Color(255, 98, 107, 124));  
	graphics.FillRectangle(&linGrBrush5, rt.left, rt.top, rt.Width(), rt.Height());

	// 
	//GetDlgItem(IDC_STATIC_S_CPU_VALUE)->GetWindowRect(&rt);
	//ScreenToClient(&rt);

	//Pen pen(Color(255, 255, 255, 255), 1);
	//graphics.DrawLine(&pen, rt.right, rt.top, rt.right, rt.bottom);

	//// 左上
	//graphics.DrawLine(&pen, rt.left - 1, rt.top - 1, rt.left - 1, rt.top + 8);
	//graphics.DrawLine(&pen, rt.left - 1, rt.top - 1, rt.left + 8, rt.top - 1); 
	//// 右上
	//graphics.DrawLine(&pen, rt.right - 8, rt.top - 1, rt.right/* + 1*/, rt.top - 1);
	//graphics.DrawLine(&pen, rt.right/* + 1*/, rt.top - 1, rt.right/* + 1*/, rt.top + 8);

	//GetDlgItem(IDC_STATIC_S_MEMORY_VALUE)->GetWindowRect(&rt);
	//ScreenToClient(&rt);
	//graphics.DrawLine(&pen, rt.left - 1, rt.top - 1, rt.left - 1, rt.top + 8);
	//graphics.DrawLine(&pen, rt.left - 1, rt.top - 1, rt.left + 8, rt.top - 1); 
	//// 右上
	//graphics.DrawLine(&pen, rt.right - 8, rt.top - 1, rt.right/* + 1*/, rt.top - 1);
	//graphics.DrawLine(&pen, rt.right/* + 1*/, rt.top - 1, rt.right/* + 1*/, rt.top + 8);

	// CMemoryDC mdc; // !!!
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
bool CStateWindow::Init()
{
	CWinThread* pThread = NULL;

	// 计时器线程
	pThread = AfxBeginThread(TimerProc, this, THREAD_PRIORITY_NORMAL, 0, 0, NULL);
	if (pThread == NULL)
	{
		return false;
	}
	else
	{
		m_handleThread[0] = pThread->m_hThread;
	}

	// 负荷计算线程
	pThread = AfxBeginThread(CalculateLoadProc, this, THREAD_PRIORITY_NORMAL, 0, 0, NULL);
	if (pThread == NULL)
	{
		SetEvent(m_eventExitTimer);
		CloseHandle(m_handleThread[0]);

		return false;
	}
	else
	{
		m_handleThread[1] = pThread->m_hThread;
	}

	return true;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
void CStateWindow::Deinit() // !!!
{
	SetEvent(m_eventExitTimer);
	SetEvent(m_eventExitCalcuLoadProc);

	WaitForMultipleObjects(2, m_handleThread, TRUE, INFINITE);

	for (int i = 0; i < 2; ++i)
	{
		CloseHandle(m_handleThread[i]);
	}
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
UINT CStateWindow::TimerProc(LPVOID param)
{
	CStateWindow *pSelf = (CStateWindow*)(param);

	DWORD dwRet(0);
	CString cstrTimeValue;

	CTime ctZeroTime(CTime::GetCurrentTime().GetTime() + 5); // 5s
	CTimeSpan ctZeroTimeSpan; 

	while (1)
	{
		dwRet = WaitForSingleObject(pSelf->m_eventExitTimer, 500);

		if (dwRet == WAIT_OBJECT_0)
		{
			break;
		} 
		else if (dwRet == WAIT_TIMEOUT)
		{
			ctZeroTimeSpan = CTime::GetCurrentTime() - ctZeroTime;

			cstrTimeValue.Format(_T("  T%c   %I64d %0.2ld:%0.2ld:%0.2ld"), ((ctZeroTimeSpan.GetTimeSpan() > 0) ? _T('+') : _T('-')), ctZeroTimeSpan.GetDays(), ctZeroTimeSpan.GetHours(), ctZeroTimeSpan.GetMinutes(), abs(ctZeroTimeSpan.GetSeconds()));
			pSelf->SetDlgItemText(IDC_STATIC_S_TIMER, cstrTimeValue);

			if ((ctZeroTimeSpan.GetTimeSpan() == 0) && (!pSelf->m_bStartup))
			{
				pSelf->m_bStartup = true;
				pSelf->DoSomething();
			}
		}
	}

	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
UINT CStateWindow::CalculateLoadProc(LPVOID param)
{
	CStateWindow *pSelf = (CStateWindow*)(param);

	DWORD dwRet(0);
	CString cstrLoadValue;

	while (1)
	{	
		dwRet = WaitForSingleObject(pSelf->m_eventExitCalcuLoadProc, 500);

		if (dwRet == WAIT_OBJECT_0)
		{
			break;
		} 
		else if (dwRet == WAIT_TIMEOUT)
		{
			pSelf->m_fLoadCPU = (float)(rand() % (100 - 0 + 1));
			cstrLoadValue.Format(_T("%0.2f%%"), pSelf->m_fLoadCPU);
			pSelf->SetDlgItemText(IDC_STATIC_S_CPU_VALUE, cstrLoadValue);

			pSelf->m_fLoadMemory = (float)(rand() % (100 - 0 + 1));
			cstrLoadValue.Format(_T("%0.2f%%"), pSelf->m_fLoadMemory);
			pSelf->SetDlgItemText(IDC_STATIC_S_MEMORY_VALUE, cstrLoadValue);

			pSelf->m_fLoadNetA = (float)(rand() % (100 - 0 + 1));
			cstrLoadValue.Format(_T("%0.2f%%"), pSelf->m_fLoadNetA);
			pSelf->SetDlgItemText(IDC_STATIC_S_NETA_VALUE, cstrLoadValue);

			pSelf->m_fLoadNetB = (float)(rand() % (100 - 0 + 1));
			cstrLoadValue.Format(_T("%0.2f%%"), pSelf->m_fLoadNetB);
			pSelf->SetDlgItemText(IDC_STATIC_S_NETB_VALUE, cstrLoadValue);

		}
	}

	return 0;
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
void CStateWindow::DoSomething()
{
	TRACE(_T("iMS - A"));

	return;

	CRect rect;  
	GetDlgItem(IDC_STATIC_S_EVENT)->GetWindowRect(&rect);//获得空间的绝对坐标  
	ScreenToClient(&rect);//获得相对于主窗体的坐标 

	CRect oldRect(rect);

	for (int i = 0; i < rect.Height(); ++i)
	{	
		rect.OffsetRect(CSize(0, -1));//这里要是要移动的相对位置  
		GetDlgItem(IDC_STATIC_S_EVENT)->MoveWindow(rect);//移动到目标位置 
		// ::SetWindowPos((GetDlgItem(IDC_STATIC_S_EVENT))->GetSafeHwnd(), HWND_BOTTOM, rect.left, rect.top, rect.Width(), rect.Height(), SWP_NOSIZE);

		Sleep(500 / rect.Height());
	}

	//GetDlgItem(IDC_STATIC_S_EVENT)->MoveWindow(oldRect);
}

