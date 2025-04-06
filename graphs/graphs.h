
// graphs.h: основной файл заголовка для приложения graphs
//
#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"       // основные символы


// CgraphsApp:
// Сведения о реализации этого класса: graphs.cpp
//

class CgraphsApp : public CWinApp
{
public:
	CgraphsApp() noexcept;


// Переопределение
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Реализация
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CgraphsApp theApp;
