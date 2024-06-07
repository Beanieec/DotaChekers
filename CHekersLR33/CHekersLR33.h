
// CHekersLR33.h: главный файл заголовка для приложения PROJECT_NAME
//

#pragma once

#ifndef __AFXWIN_H__
	#error "включить pch.h до включения этого файла в PCH"
#endif

#include "resource.h"		// основные символы


// CCHekersLR33App:
// Сведения о реализации этого класса: CHekersLR33.cpp
//

class CCHekersLR33App : public CWinApp
{
public:
	CCHekersLR33App();

// Переопределение
public:
	virtual BOOL InitInstance();

// Реализация

	DECLARE_MESSAGE_MAP()
};

extern CCHekersLR33App theApp;
