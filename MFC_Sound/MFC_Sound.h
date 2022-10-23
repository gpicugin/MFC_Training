
// MFC_Sound.h : main header file for the PROJECT_NAME application
//

#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"		// main symbols


// CMFCSoundApp:
// See MFC_Sound.cpp for the implementation of this class
//

class CMFCSoundApp : public CWinApp
{
public:
	CMFCSoundApp();

// Overrides
public:
	virtual BOOL InitInstance();

// Implementation

	DECLARE_MESSAGE_MAP()
};

extern CMFCSoundApp theApp;
