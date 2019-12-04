#include "stdafx.h"
class CMyApp : CWinApp
{
	afx_msg LRESULT OnThreadEnded(WPARAM wParam, LPARAM lParam);
};

LRESULT CMyApp::OnThreadEnded(WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(wParam);
	UNREFERENCED_PARAMETER(lParam);
	::MessageBox((HWND)wParam, "Thread Ended", "Message from thread", MB_OK);
}

BEGIN_MESSAGE_MAP(CMyApp, CWinApp)

	ON_MESSAGE(WM_THREADENDED, OnThreadEnded)

END_MESSAGE_MAP()