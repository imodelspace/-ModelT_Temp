#pragma once


// CCommandWindow 对话框

class CCommandWindow : public CDialogEx
{
	DECLARE_DYNAMIC(CCommandWindow)

public:
	CCommandWindow(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CCommandWindow();

// 对话框数据
	enum { IDD = IDD_COMMAND_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	virtual BOOL OnInitDialog();
};
