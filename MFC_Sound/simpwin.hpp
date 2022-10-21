#include <afxwin.h>
#include "TestDialog.h"
 	// класс основного окна приложения
class CMainWin: public CFrameWnd {
public:
    TestDialog* test;
    CMainWin();
    // декларирование карты сообщений
    DECLARE_MESSAGE_MAP()
};

// класс приложения. должен существовать только
// один экземпляр этого класса.
 
// член-функция InitInstance() вызывается при запуске
// приложения.
 
class CApp: public CWinApp {
public:
    BOOL InitInstance();
};