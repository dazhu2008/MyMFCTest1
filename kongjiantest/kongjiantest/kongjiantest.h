
// kongjiantest.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CkongjiantestApp:
// �йش����ʵ�֣������ kongjiantest.cpp
//

class CkongjiantestApp : public CWinApp
{
public:
	CkongjiantestApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CkongjiantestApp theApp;

