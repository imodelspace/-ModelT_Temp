
// ModelT.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CModelTApp:
// �йش����ʵ�֣������ ModelT.cpp
//

class CModelTApp : public CWinApp
{
public:
	CModelTApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��
	DECLARE_MESSAGE_MAP()

private:
	ULONG_PTR m_gdiplusToken;
public:
	virtual int ExitInstance();
};

extern CModelTApp theApp;