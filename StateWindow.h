//////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
#pragma once

// CStateWindow 对话框
class CStateWindow : public CDialogEx
{
	DECLARE_DYNAMIC(CStateWindow)

public:
	CStateWindow(CWnd* pParent = NULL);   // 标准构造函数
	virtual ~CStateWindow();

// 对话框数据
	enum { IDD = IDD_STATE_DIALOG };

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 支持

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	virtual BOOL OnInitDialog();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	afx_msg void OnPaint();

public:
	bool Init();
	void Deinit();

private:
	static UINT TimerProc(LPVOID param);
	static UINT CalculateLoadProc(LPVOID param);

private:
	void DoSomething();

private:
	CFont m_fontA; // !!!
	CFont m_fontB; // !!!
	CFont m_fontC;
	CBrush m_brushBlueA;
	CBrush m_brushBlueB;
	CBrush m_brushBlueC;
	CBrush m_brushDarkA;
	CBrush m_brushDarkB;
	CBrush m_brushGrayA;

	bool m_bStartup;

	float m_fLoadCPU;
	float m_fLoadMemory;
	float m_fLoadNetA;
	float m_fLoadNetB;

	HANDLE m_handleThread[2];
	CEvent m_eventExitTimer;
	CEvent m_eventExitCalcuLoadProc;
};
