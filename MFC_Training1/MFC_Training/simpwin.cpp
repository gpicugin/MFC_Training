#include <string>
#include "SIMPWIN.HPP"

// создание одного и только одного экземпл¤ра
// приложения
 
CApp App;
// реализация
 
BOOL CApp::InitInstance()
{	
// создание главного окна приложени¤ и его
// отображение.
 
// член CApp::m_pMainWnd - это указатель на объект
// главного окна.
 
	m_pMainWnd = new CMainWin;
	m_pMainWnd->ShowWindow(SW_RESTORE);
	m_pMainWnd->UpdateWindow();

// сигнализируем MFC об успешной инициализации
// приложения. 
 
	return TRUE;
}
 
CMainWin::CMainWin()
{
	// создание окна с заголовком. »спользуется
	// встроенный в MFC

	// класс окна, поэтому первый параметр 0.
	Create(0, "простейшее приложение на MFC");
}
 


// реализация карты сообщений
BEGIN_MESSAGE_MAP(CMainWin /*класс окна*/,
				  CFrameWnd /*класс-предок*/)
END_MESSAGE_MAP()