//////////////////////////////////////////////////////////////////////////////////////////////////////
// CommandWindow.cpp : ʵ���ļ�

#include "stdafx.h"
#include "ModelT.h"
#include "CommandWindow.h"
#include "afxdialogex.h"

// CCommandWindow �Ի���
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

	// TODO:  �ڴ���Ӷ���ĳ�ʼ��
	SetBackgroundColor(RGB(0, 185, 205));

	return TRUE;  // return TRUE unless you set the focus to a control
	// �쳣: OCX ����ҳӦ���� FALSE
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

