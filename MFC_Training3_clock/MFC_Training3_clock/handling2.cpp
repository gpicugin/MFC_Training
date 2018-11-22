#include <afxwin.h>
#include <time.h>
#include <string>
#include "handling2.h"
// Реализация
BOOL CApp::InitInstance()
{
	m_pMainWnd = new CMainWin;
	m_pMainWnd->ShowWindow(SW_RESTORE);
	m_pMainWnd->UpdateWindow();

	// Установка таймера с идентификатором 1 и
	// интервалом 500 мс

	m_pMainWnd->SetTimer(1, 500, 0);
	return TRUE;
}

CMainWin::CMainWin()
{
	// Определение прямоугольника, в котором будет
	// размещено окно

	RECT rect;
	rect.left = rect.top = 10;
	rect.right = 220;
	rect.bottom = 80;

	// Создание окна в определенном экранном
	// прямоугольнике

	this->Create(0, "CLOCK", WS_OVERLAPPEDWINDOW, rect);
	strcpy(str, "");
}

// Реализация карты сообщений главного окна
BEGIN_MESSAGE_MAP(CMainWin, CFrameWnd)
	ON_WM_PAINT() 
	ON_WM_DESTROY()
	ON_WM_TIMER()
END_MESSAGE_MAP()
afx_msg void CMainWin::OnPaint()
{
	CPaintDC dc(this);
	// Выводим в окно строку текущего времени
	dc.TextOut(1, 1, " ");
	dc.TextOut(1, 1, str);
}

afx_msg void CMainWin::OnTimer(UINT ID)
{
	// Предполагаем, что в программе один таймер, поэтому
	// не проверяем ID.
	// Получаем строку текущего времени
	CTime curtime = CTime::GetCurrentTime();
	tm *newtime;
	tm osTime;
	newtime = curtime.GetLocalTm(&osTime);
	sprintf(str, asctime(newtime));
	str[strlen(str) - 1] = '\0';

	// Посылаем сообщение WM_PAINT -- его обработчик
	// отобразит строку.
	this->InvalidateRect(0);
}

afx_msg void CMainWin::OnDestroy()
{

	// При закрытии окна удаляем связанный с ним
	// таймер.
	KillTimer(1);
}
CApp App; // Единственный экземпляр приложения.


