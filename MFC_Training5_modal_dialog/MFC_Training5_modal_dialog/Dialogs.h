#include <afxwin.h>
#include "resource.h"

// Класс главного окна
class CMainWin: public CFrameWnd {
public:
	// Конструктор немного изменен.
	// Title -- заголовок окна, HowShow -- код показа окна 	
	CMainWin(CString Title, int HowShow); 
	afx_msg void OnCommand_Dialog(); 
	afx_msg void OnCommand_Exit();
	afx_msg void OnCommand_Help();
	afx_msg void OnPaint();	
	afx_msg void OnDestroy();	
	// Установка строки, отображаемой в верхней
	// части окна
	virtual void SetInfoStr(CString str);
private:
	CString infoStr; 
	// Строка, отображаемая в верхней части окна
	DECLARE_MESSAGE_MAP()
};

// Класс приложения
class CApp: public CWinApp {
public:
	BOOL InitInstance();
};
// Класс диалогового окна
class CSampleDialog: public CDialog {
public:
	// DialogName -- идентификатор диалога в ресурсах,
	// Owner -- окно-владелец (если NULL, то главное окно)
	CSampleDialog(char *DialogName, CWnd *Owner = NULL);
	afx_msg void OnCommand_Red();
	afx_msg void OnCommand_Green();
	afx_msg void OnCancel();
private:
	DECLARE_MESSAGE_MAP()
};