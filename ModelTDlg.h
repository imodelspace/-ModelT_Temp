
// ModelTDlg.h : ͷ�ļ�
//

#pragma once

#include "StateWindow.h"
#include "CommandWindow.h"

// CModelTDlg �Ի���
class CModelTDlg : public CDialogEx
{
// ����
public:
	CModelTDlg(CWnd* pParent = NULL);	// ��׼���캯��
	~CModelTDlg();

// �Ի�������
	enum { IDD = IDD_MODELT_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
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
