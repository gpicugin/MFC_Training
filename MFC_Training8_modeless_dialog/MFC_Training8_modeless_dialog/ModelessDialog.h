#include <afxwin.h>
#include "resource.h"

// Класс главного окна
class CMainWin;

class CSampleDialog: public CDialog
{
public:
	CSampleDialog();
	// Функция привязки диалога к ресурсам

	BOOL Create(LPCSTR DialogName, CWnd *Owner = 0);
	BOOL OnInitDialog();
	afx_msg void OnCommand_Red();
	afx_msg void OnCommand_Green();
	afx_msg void OnCommand_EditOK();
	afx_msg void OnSelectFruit();
	afx_msg void OnCancel();
private:

	// Переменная, показывающая, используется ли в
	// данный момент диалог

	BOOL inUse;
	CMainWin *owner;
	DECLARE_MESSAGE_MAP()
};

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
	// Экземпляр объекта диалога -
 
 	// существует все время, пока существует
 	// основное окно
 
 	CSampleDialog dialog;
	CString infoStr; 
	// Строка, отображаемая в верхней части окна
	DECLARE_MESSAGE_MAP()
};

// Класс приложения
class CApp: public CWinApp {
public:
	BOOL InitInstance();	
};
// Класс немодального диалога
