
// ModelTDlg.h : 头文件
//

#pragma once

#include "StateWindow.h"
#include "CommandWindow.h"

// CModelTDlg 对话框
class CModelTDlg : public CDialogEx
{
// 构造
public:
	CModelTDlg(CWnd* pParent = NULL);	// 标准构造函数
	~CModelTDlg();

// 对话框数据
	enum { IDD = IDD_MODELT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持

// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()

	void CreateStateWindow();
	void CreateCommandWindow();

private:
	CStateWindow *m_pStateWindow;
	CCommandWindow *m_pCommandWindow;

private:
	CFont m_fontTitle; // !!!
	CFont m_fontSubTitle; // !!!
	CFont m_fontText;

public:
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);

private:
	void unnameFun();
public:
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	CString m_cstrVal0;
};
