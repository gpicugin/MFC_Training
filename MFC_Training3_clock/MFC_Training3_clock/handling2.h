﻿#include <afxwin.h>
// Класс основного окна
class CMainWin: public CFrameWnd {
public:
	CMainWin();
	afx_msg void OnPaint();
	// Обработчик сообщения WM_DESTROY
	afx_msg void OnDestroy();
	// Обработчик сообщения WM_TIMER
	afx_msg void OnTimer(UINT ID);
	char str[50];
	DECLARE_MESSAGE_MAP()
};
// Класс приложения
class CApp: public CWinApp {
public:
	BOOL InitInstance();
};


