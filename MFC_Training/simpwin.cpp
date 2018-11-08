#include <string>
#include "SIMPWIN.HPP"

// Создание одного и только одного экземпляра
// приложения
 
CApp App;
// Реализация
 
BOOL CApp::InitInstance()
{
	//AfxSetAmbientActCtx(FALSE);
	//CWinApp::InitInstance();
// Создание главного окна приложения и его
// отображение.
 
// Член CApp::m_pMainWnd - это указатель на объект
// главного окна.
 
	m_pMainWnd = new CMainWin;
	m_pMainWnd->ShowWindow(SW_RESTORE);
	m_pMainWnd->UpdateWindow();

// Сигнализируем MFC об успешной инициализации
// приложения. 
 
	return TRUE;
}
 
CMainWin::CMainWin()
{
// Создание окна с заголовком. Используется
// встроенный в MFC
 
// класс окна, поэтому первый параметр 0.
Create(0, "Простейшее приложение на MFC");
}
 


// Реализация карты сообщений
BEGIN_MESSAGE_MAP(CMainWin /*класс окна*/, CFrameWnd
/*класс-предок*/)
END_MESSAGE_MAP()