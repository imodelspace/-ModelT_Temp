#pragma once


// CCommandWindow �Ի���

class CCommandWindow : public CDialogEx
{
	DECLARE_DYNAMIC(CCommandWindow)

public:
	CCommandWindow(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~CCommandWindow();

// �Ի�������
	enum { IDD = IDD_COMMAND_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	virtual BOOL OnInitDialog();
};
