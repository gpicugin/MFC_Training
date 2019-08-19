#include "ContextMenu.h"

CApp App;

BOOL CApp::InitInstance()
{
	m_pMainWnd = new CMainWnd();	
	m_pMainWnd->ShowWindow(SW_RESTORE);
	m_pMainWnd->UpdateWindow();
	return TRUE;
}

void CMyButton::OnLButtonUp(UINT nFlags, CPoint point)
{
	MoveWindow(CRect(120,100,220,150),TRUE);
	CButton::OnLButtonUp(nFlags, point);
}

void CMyButton::OnRButtonUp(UINT nFlags, CPoint point)
{
	// TODO: Add your message handler code here and/or call default
	MoveWindow(CRect(120,10,220,50),TRUE);
	CButton::OnRButtonUp(nFlags, point);
}

void CMyButton::OnContextMenu(CWnd* pWnd, CPoint point)
{
	CRect rRect(0, 0, 0, 0);
	CMenu PopupMain;
	CMenu *PopupMenu = NULL;
	ScreenToClient(&point);
	PopupMain.LoadMenu(IDR_MENU2);
	PopupMenu = PopupMain.GetSubMenu(0); // Извлекает указатель на всплывающее меню
	if ( !PopupMenu )
		return;
	POINT menuOrigin;
	GetCursorPos(&menuOrigin); // получает позицию курсора на экране:

	SetForegroundWindow(); // использует поле класса в котором вызывается
	// Приводит поток, который создал указанное окно на передний план и активирует окно.
	CString s = _T(""); 
	CString i;
		//for (int iPos = 0; iPos < PopupMenu->GetMenuItemCount(); iPos++)
		//{
		//	CString str;			
		//	if (PopupMenu->GetMenuString(iPos, str, MF_BYPOSITION) && str.Compare(_T("2"))==0)
		//		PopupMenu->EnableMenuItem(iPos,MF_BYPOSITION | MF_GRAYED); // pich find

		//	i.Format("%i", iPos);
		//	s = s + str + _T(" - ") + i + _T("\n");			
		//}		
	PopupMenu->EnableMenuItem(0, MF_BYPOSITION | MF_GRAYED); // pich find

	DWORD dwCmdId = TrackPopupMenuEx( PopupMenu->GetSafeHmenu(), TPM_LEFTALIGN | TPM_TOPALIGN |
		TPM_RETURNCMD, menuOrigin.x, menuOrigin.y, m_hWnd, NULL );
	// Функция TrackPopupMenuEx показывает на экране контекстное меню в заданном расположении
	// и отслеживает выбор пунктов на контекстном меню.
	
	PostMessage(WM_NULL, 0, 0);
	// Помещает сообщение в очередь сообщений окна и затем возвращается без того чтобы ждать
	// соответствующее окно которое обрабатывает сообщение.
	// приложение отправляет сообщение WM_NULL, если оно хочет отправить сообщение,
	// которое будет игнорировать окно получателя. Окно получает это сообщение через его функцию WindowProc .
}

BEGIN_MESSAGE_MAP(CMyButton, CButton) // таблица откликов на сообщения
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONUP()
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONDOWN()	
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
}

void CMainWnd::OnKeyDown(UINT, UINT, UINT)
{
	AfxMessageBox(" Key Button Down ");
}
void CMainWnd::OnRButtonUp(UINT, CPoint)
{
	AfxMessageBox(" Rigth Button Click ");
}
void CMainWnd::OnLButtonUp(UINT, CPoint)
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
	ON_WM_LBUTTONUP()
	ON_WM_RBUTTONUP()

END_MESSAGE_MAP()


