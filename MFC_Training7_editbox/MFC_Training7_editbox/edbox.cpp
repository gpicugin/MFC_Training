#include "edbox.h"
CApp App;

//-------------------------------------------------------

CMainWin::CMainWin(CString Title, int HowShow)
	:infoStr("")
{
	RECT rect;
	rect.top = 10; rect.left = 50;
	rect.bottom = 460, rect.right = 630;
	this->Create(0, Title, WS_OVERLAPPEDWINDOW, rect, 0, MAKEINTRESOURCE(IDR_MENU1));
	this->ShowWindow(HowShow);
	this->UpdateWindow();
	this->LoadAccelTable(MAKEINTRESOURCE(IDR_MENU1));
}
afx_msg void CMainWin::OnCommand_Dialog()
{
	CSampleDialog sampleDialog(MAKEINTRESOURCE(IDD_DIALOG1));
	sampleDialog.DoModal();
	this->SetInfoStr("Диалог закрыт.");
}
afx_msg void CMainWin::OnDestroy()
{
	
	this->MessageBox("Завершение приложения.", "Editbox", MB_ICONEXCLAMATION);
}

afx_msg void CMainWin::OnCommand_Help()
{
	this->MessageBox("Демонстрация элемента управления Editbox", 
 	"Editbox", MB_ICONINFORMATION);
}

afx_msg void CMainWin::OnPaint()
{
	CPaintDC paintDC(this);
 	paintDC.TextOut(10, 10, infoStr, infoStr.GetLength());
}

void CMainWin::SetInfoStr(CString str)
{
	infoStr = str;
	this->InvalidateRect(0);
}

// Карта откликов на сообщения главного окна
BEGIN_MESSAGE_MAP(CMainWin, CFrameWnd)
	ON_COMMAND(ID_MENU_DIALOG, OnCommand_Dialog)
	ON_COMMAND(ID_HELP, OnCommand_Help)	
	ON_WM_PAINT()
	ON_WM_DESTROY()	
END_MESSAGE_MAP()

//---------------------------------------------------
BOOL CApp::InitInstance()
{	
	m_pMainWnd = new CMainWin("Editbox", SW_RESTORE);	
	return TRUE;
}

//---------------------------------------------------
CSampleDialog::CSampleDialog(char *DialogName, CWnd *Owner)
	:CDialog(DialogName, Owner)
{
}

afx_msg void CSampleDialog::OnCommand_Red()
{
	// Член-функция CWnd::GetOwner() возвращает указатель
	// на окно-собственник данного окна.
	// Так как в данном случае это главное окно,
	// мы проводим преобразование к CMainWin 
	// и вызываем метод SetInfoStr()
	((CMainWin *)(this->GetOwner()))->SetInfoStr("Нажата кнопка 'Red'");
}
afx_msg void CSampleDialog::OnCommand_Green()
{
	// См. комментарий в CSampleDialog::OnCommand_Red()
	((CMainWin *)(this->GetOwner()))->SetInfoStr("Нажата кнопка 'Green'");
} 

// Инициализация диалога
BOOL CSampleDialog::OnInitDialog()
{
	CDialog::OnInitDialog();
	// Вызвать метод базового класса
	// Получить объект списка Listbox

	CListBox *listBoxPtr = (CListBox *) 
		(this->GetDlgItem(IDC_LIST1));

	// Добавить строки в список
	listBoxPtr->AddString("Яблоко");
	listBoxPtr->AddString("Слива");
	listBoxPtr->AddString("Груша");
	listBoxPtr->AddString("Апельсин");
	listBoxPtr->AddString("Мандарин");
	listBoxPtr->AddString("Абрикос");
	listBoxPtr->AddString("Персик");
	listBoxPtr->AddString("Ананас");

	// Получить объект Editbox
 	CEdit *editBoxPtr = (CEdit *) (this->GetDlgItem(IDC_EDIT1));

 	// Установить текст в Editbox
 	editBoxPtr->SetWindowText("Вася");

	return TRUE;
}

// Здесь читается текст из Editbox
afx_msg void CSampleDialog::OnCommand_EditOK()
{
	// Получить объект Editbox
	CEdit *pCEdit = (CEdit *) (this->GetDlgItem(IDC_EDIT1));
	char s[1024];
	// Прочитать текст из Editbox
	pCEdit->GetWindowText(s, sizeof(s) / sizeof(s[0]) - 1);
	// Вывести информацию в окно
	((CMainWin *) (this->GetOwner()))
		->SetInfoStr(CString("Введена строка \"") + s + "\"");
}

// Обработчик сообщения выбора элемента

// (двойной щелчок на списке или нажатие
// специальной кнопки)

afx_msg void CSampleDialog::OnSelectFruit()
{
	CListBox *listBoxPtr = (CListBox *)(this->GetDlgItem(IDC_LIST1));
	// Получить номер текущего выделенного элемента списка
	int index = listBoxPtr->GetCurSel();
	// Если результат LB_ERR, то ни один элемент еще не выделен
	if(index == LB_ERR) 
	{
		((CMainWin *) (this->GetOwner())) 
			->SetInfoStr("Ни один фрукт не выделен");
	}

	else
	{
		char s[100];
		// Получить текст выделенного элемента
		listBoxPtr->GetText(index, s);
		CString infoStr;
		infoStr.Format("Выбран фрукт %s с индексом %i", s, index);
		// Вывести сообщение
		((CMainWin *) (this->GetOwner()))->SetInfoStr(infoStr);
	}
}

afx_msg void CSampleDialog::OnCancel()
{
	// См. комментарий в CSampleDialog::OnCommand_Red()

	((CMainWin *) (this->GetOwner()))->SetInfoStr("Нажата кнопка 'Cancel'");	
	this->EndDialog(TRUE);
}

// Карта откликов на сообщения диалога
BEGIN_MESSAGE_MAP(CSampleDialog, CDialog)
	ON_COMMAND(IDC_BUTTON_RED, OnCommand_Red)
	ON_COMMAND(IDC_BUTTON_GREEN, OnCommand_Green)
	ON_COMMAND(IDC_INSERT, OnCommand_EditOK)
	ON_COMMAND(IDC_CHOOSE, OnSelectFruit) 	
	ON_LBN_DBLCLK(IDC_LIST1, OnSelectFruit)
END_MESSAGE_MAP()

//void CSampleDialog::OnLbnDblclkList1()
//{
//	// TODO: Add your control notification handler code here
//}
