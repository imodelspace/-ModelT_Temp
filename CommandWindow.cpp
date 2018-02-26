//////////////////////////////////////////////////////////////////////////////////////////////////////
// CommandWindow.cpp : 实现文件

#include "stdafx.h"
#include "ModelT.h"
#include "CommandWindow.h"
#include "afxdialogex.h"

// CCommandWindow 对话框
IMPLEMENT_DYNAMIC(CCommandWindow, CDialogEx)

CCommandWindow::CCommandWindow(CWnd* pParent /*=NULL*/) : CDialogEx(CCommandWindow::IDD, pParent)
{

}

CCommandWindow::~CCommandWindow()
{
}

void CCommandWindow::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CCommandWindow, CDialogEx)
	ON_BN_CLICKED(IDOK, &CCommandWindow::OnBnClickedOk)
	ON_BN_CLICKED(IDCANCEL, &CCommandWindow::OnBnClickedCancel)
END_MESSAGE_MAP()

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
BOOL CCommandWindow::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  在此添加额外的初始化
	SetBackgroundColor(RGB(0, 185, 205));

	return TRUE;  // return TRUE unless you set the focus to a control
	// 异常: OCX 属性页应返回 FALSE
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
void CCommandWindow::OnBnClickedOk()
{
    DestroyWindow();
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
void CCommandWindow::OnBnClickedCancel()
{

	DestroyWindow();
}

