#include "Button.h"

CApp App;

BOOL CApp::InitInstance()
{
	m_pMainWnd = new CMainWnd();	
	m_pMainWnd->ShowWindow(SW_RESTORE);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

void CMyButton::OnLButtonDblClk(UINT, CPoint)
{
	MoveWindow(CRect(120,100,220,150),TRUE);
}

void CMyButton::OnRButtonDblClk(UINT, CPoint)
{
	MoveWindow(CRect(120,10,220,50),TRUE);
}

BEGIN_MESSAGE_MAP(CMyButton, CButton) // таблица откликов на сообщения
	ON_WM_LBUTTONDBLCLK()
	ON_WM_RBUTTONDBLCLK()
END_MESSAGE_MAP()

CMainWnd::CMainWnd()
{
	Create(NULL,"Step4",WS_OVERLAPPEDWINDOW,rectDefault,
		NULL,NULL);     // Создать окно программы
	// оператор new по умолчанию в случае ошибки вернет NULL
	// проверка указателя на NULL дает возможность избавиться от дальнейших ошибок
	MyStatic = new CStatic();
	if (MyStatic!=NULL)  MyStatic->Create("MyStatic",WS_CHILD|WS_VISIBLE|SS_CENTER,
		CRect(10,10,100,50),this);      // создали 
	MyButton = new CMyButton();  // Меняем класс, на основе которого создается объект
	
	if (MyButton!=NULL) MyButton->Create("MyButton",WS_CHILD|WS_VISIBLE|SS_CENTER,
		CRect(120,10,220,50),this,IDC_MYBUTTON);
	MyEdit = new CEdit();
	if (MyEdit!=NULL) MyEdit->Create(WS_CHILD|WS_VISIBLE|WS_BORDER,
		CRect(240,10,340,50),this,IDC_MYEDIT);
	MyButton->EnableWindow(FALSE); // неактивная кнопка
}

void CMainWnd::OnKeyDown(UINT, UINT, UINT)
{
	AfxMessageBox(" Key Button Down ");
}
void CMainWnd::OnRButtonDblClk(UINT, CPoint)
{
	AfxMessageBox(" Rigth Button Click ");
}
void CMainWnd::OnLButtonDblClk(UINT, CPoint)
{
	AfxMessageBox(" Left Button Click ");
}

afx_msg void CMainWnd::OnDestroy()
{
	
	this->MessageBox("Завершение приложения.", "SimpleButton", MB_ICONEXCLAMATION);
}

BEGIN_MESSAGE_MAP(CMainWnd, CFrameWnd)	
	//ON_WM_PAINT()
	ON_WM_DESTROY()	
	ON_WM_LBUTTONDOWN() // сообщение о нажатии ЛКМ
	ON_WM_RBUTTONDOWN() // сообщение о нажатии ПКМ
	ON_WM_KEYDOWN()
	ON_WM_RBUTTONDBLCLK()
	ON_WM_LBUTTONDBLCLK()

END_MESSAGE_MAP()