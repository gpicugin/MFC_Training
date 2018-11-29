#include "Dialogs.h"
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
	CSampleDialog sampleDialog(MAKEINTRESOURCE(IDD_DIALOG1), this);
	int result = sampleDialog.DoModal();
	char s[20];
	sprintf(s, "%i", result);
	this->SetInfoStr(infoStr + ". " + "Функция CDialog::DoModal() возвратила " + CString(s));
}
afx_msg void CMainWin::OnDestroy()
{
	this->MessageBox("Завершение приложения.", "Dialogs", MB_ICONEXCLAMATION);
}

afx_msg void CMainWin::OnCommand_Help()
{
	this->MessageBox("Программа, использующая диалог.\n" "Написана с помощью MFC 4.0.", 
		"Dialogs", MB_ICONINFORMATION);
}

afx_msg void CMainWin::OnPaint()
{
	CPaintDC paintDC(this);
	paintDC.TextOut(10, 10, infoStr);
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
	//CMainWin MainWin("Dialogs - приложение с диалогом", SW_RESTORE);
	m_pMainWnd = new CMainWin("Dialogs - приложение с диалогом", SW_RESTORE);	
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

afx_msg void CSampleDialog::OnCancel()
{
	// См. комментарий в CSampleDialog::OnCommand_Red()

	((CMainWin *) (this->GetOwner()))->SetInfoStr("Нажата кнопка 'Cancel'");

	// Закрываем диалог, только если пользователь
	// подтвердил намерение. 

	// Значение 7 будет возвращено DoModal().

	int response = this->MessageBox("Вы уверены ?",	"Cancel", MB_YESNO);

	if(response == IDYES)
		this->EndDialog(7);
}

// Карта откликов на сообщения диалога
BEGIN_MESSAGE_MAP(CSampleDialog, CDialog)
	ON_COMMAND(IDC_BUTTON_RED, OnCommand_Red)
	ON_COMMAND(IDC_BUTTON_GREEN, OnCommand_Green)
END_MESSAGE_MAP()
//------------------------------------------------