#include <afxwin.h>
#include <string>
#include "resource.h"
#include "SimpleButton.h"

#define IDC_MYBUTTON 100	// Идентификатор кнопки
#define IDC_MYEDIT 102	// Идентификатор поля редактирования

class CMyButton: public CButton
{
public:
	afx_msg void OnLButtonDblClk(UINT, CPoint);
	afx_msg void OnRButtonDblClk(UINT, CPoint);
private:
	DECLARE_MESSAGE_MAP(); // таблица откликов кнопки
};

// Класс основного окна
class CMainWnd : public CFrameWnd
{
public:
	CMainWnd();
	afx_msg void OnLButtonDblClk(UINT, CPoint);
	afx_msg void OnRButtonDblClk(UINT, CPoint);
	afx_msg void OnKeyDown(UINT, UINT, UINT);
	afx_msg void OnDestroy();
private:
	CStatic* MyStatic;      // Элемент управления для вывода текста
	CMyButton* MyButton;// Элемент управления кнопка
	CEdit* MyEdit;  // Элемент редактирования
	DECLARE_MESSAGE_MAP(); // таблица откликов
};
// Класс приложения
class CApp: public CWinApp {
public:
	BOOL InitInstance();
};