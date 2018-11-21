#include <afxwin.h>
 	// класс основного окна приложени¤
 	class CMainWin: public CFrameWnd {
 	public:
 	CMainWin();
 	// ƒекларирование карты сообщений
 	DECLARE_MESSAGE_MAP()
 	};

 	// класс приложени¤. ƒолжен существовать только
 	// один экземпляр этого класса.
 
 	// член-функция InitInstance() вызывается при запуске
 	// приложения.
 
 	class CApp: public CWinApp {
 	public:
 	BOOL InitInstance();
 	};