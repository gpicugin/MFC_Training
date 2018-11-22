#include "menu.h"
#include "resource.h"
#include <string>
#include <stdio.h>

CMainWin::CMainWin()
{
	RECT rect;
 	rect.left = 20; rect.top = 10;
 	rect.right = 600; rect.bottom = 460;
 	this->Create(0, "Menus", WS_OVERLAPPEDWINDOW, rect, 0, MAKEINTRESOURCE(IDR_MENU1));
}

BOOL CApp::InitInstance()
{
	m_pMainWnd = new CMainWin;
	m_pMainWnd->ShowWindow(SW_RESTORE);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

BEGIN_MESSAGE_MAP(CMainWin, CFrameWnd)
	ON_WM_PAINT()
 	ON_COMMAND(ID_ONE_ALPHA, OnCommand_Alpha)
 	ON_COMMAND(ID_ONE_BETA, OnCommand_Beta)
 	ON_COMMAND(ID_TWO_GAMMA, OnCommand_Gamma)
 	ON_COMMAND(ID_DELTA_EPSILON, OnCommand_Epsilon)
 	ON_COMMAND(ID_DELTA_ZETA, OnCommand_Zeta)
 	ON_COMMAND(ID_TWO_ETA, OnCommand_Eta)
 	ON_COMMAND(ID_TWO_THETA, OnCommand_Theta)
 	ON_COMMAND(ID_HELP, OnCommand_Help)
END_MESSAGE_MAP()

afx_msg void CMainWin::OnPaint()
{
	CPaintDC dc(this);
	CString s("Press Ctrl-T to get current date and time");
	dc.TextOut(100, 200, s);
}

afx_msg void CMainWin::OnCommand_Alpha()
{
	// Использование окна сообщений
	this->MessageBox("OnCommand_Alpha() handler called.", "WM_COMMAND message", 
		MB_OK | MB_ICONINFORMATION);
}

afx_msg void CMainWin::OnCommand_Beta()
{
	this->MessageBox("OnCommand_Beta() handler called.", "WM_COMMAND message",
		MB_OK | MB_ICONINFORMATION);
}

afx_msg void CMainWin::OnCommand_Gamma()
{
	this->MessageBox("OnCommand_Gamma() handler called.", "WM_COMMAND message", 
		MB_OK | MB_ICONINFORMATION);
}

afx_msg void CMainWin::OnCommand_Epsilon()
{
	this->MessageBox("OnCommand_Epsilon() handler called.", "WM_COMMAND	message", 
		MB_OK | MB_ICONINFORMATION);
}

afx_msg void CMainWin::OnCommand_Zeta()
{
	this->MessageBox("OnCommand_Zeta() handler called.", "WM_COMMAND message", 
		MB_OK | MB_ICONINFORMATION);
}


afx_msg void CMainWin::OnCommand_Eta()
{
	this->MessageBox("OnCommand_Eta() handler called.", "WM_COMMAND message", 
		MB_OK | MB_ICONINFORMATION);
}

afx_msg void CMainWin::OnCommand_Theta()
{
	this->MessageBox("OnCommand_Theta() handler called.", "WM_COMMAND message", 
		MB_OK | MB_ICONINFORMATION);
}

afx_msg void CMainWin::OnCommand_Help()
{
	this->MessageBox("OnCommand_Help() handler called.", "WM_COMMAND message", 
		MB_OK | MB_ICONINFORMATION);
}

CApp App;