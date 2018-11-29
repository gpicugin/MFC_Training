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
	this->SetInfoStr("������ ������.");
}
afx_msg void CMainWin::OnDestroy()
{
	
	this->MessageBox("���������� ����������.", "Editbox", MB_ICONEXCLAMATION);
}

afx_msg void CMainWin::OnCommand_Help()
{
	this->MessageBox("������������ �������� ���������� Editbox", 
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

// ����� �������� �� ��������� �������� ����
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
	// ����-������� CWnd::GetOwner() ���������� ���������
	// �� ����-����������� ������� ����.
	// ��� ��� � ������ ������ ��� ������� ����,
	// �� �������� �������������� � CMainWin 
	// � �������� ����� SetInfoStr()
	((CMainWin *)(this->GetOwner()))->SetInfoStr("������ ������ 'Red'");
}
afx_msg void CSampleDialog::OnCommand_Green()
{
	// ��. ����������� � CSampleDialog::OnCommand_Red()
	((CMainWin *)(this->GetOwner()))->SetInfoStr("������ ������ 'Green'");
} 

// ������������� �������
BOOL CSampleDialog::OnInitDialog()
{
	CDialog::OnInitDialog();
	// ������� ����� �������� ������
	// �������� ������ ������ Listbox

	CListBox *listBoxPtr = (CListBox *) 
		(this->GetDlgItem(IDC_LIST1));

	// �������� ������ � ������
	listBoxPtr->AddString("������");
	listBoxPtr->AddString("�����");
	listBoxPtr->AddString("�����");
	listBoxPtr->AddString("��������");
	listBoxPtr->AddString("��������");
	listBoxPtr->AddString("�������");
	listBoxPtr->AddString("������");
	listBoxPtr->AddString("������");

	// �������� ������ Editbox
 	CEdit *editBoxPtr = (CEdit *) (this->GetDlgItem(IDC_EDIT1));

 	// ���������� ����� � Editbox
 	editBoxPtr->SetWindowText("����");

	return TRUE;
}

// ����� �������� ����� �� Editbox
afx_msg void CSampleDialog::OnCommand_EditOK()
{
	// �������� ������ Editbox
	CEdit *pCEdit = (CEdit *) (this->GetDlgItem(IDC_EDIT1));
	char s[1024];
	// ��������� ����� �� Editbox
	pCEdit->GetWindowText(s, sizeof(s) / sizeof(s[0]) - 1);
	// ������� ���������� � ����
	((CMainWin *) (this->GetOwner()))
		->SetInfoStr(CString("������� ������ \"") + s + "\"");
}

// ���������� ��������� ������ ��������

// (������� ������ �� ������ ��� �������
// ����������� ������)

afx_msg void CSampleDialog::OnSelectFruit()
{
	CListBox *listBoxPtr = (CListBox *)(this->GetDlgItem(IDC_LIST1));
	// �������� ����� �������� ����������� �������� ������
	int index = listBoxPtr->GetCurSel();
	// ���� ��������� LB_ERR, �� �� ���� ������� ��� �� �������
	if(index == LB_ERR) 
	{
		((CMainWin *) (this->GetOwner())) 
			->SetInfoStr("�� ���� ����� �� �������");
	}

	else
	{
		char s[100];
		// �������� ����� ����������� ��������
		listBoxPtr->GetText(index, s);
		CString infoStr;
		infoStr.Format("������ ����� %s � �������� %i", s, index);
		// ������� ���������
		((CMainWin *) (this->GetOwner()))->SetInfoStr(infoStr);
	}
}

afx_msg void CSampleDialog::OnCancel()
{
	// ��. ����������� � CSampleDialog::OnCommand_Red()

	((CMainWin *) (this->GetOwner()))->SetInfoStr("������ ������ 'Cancel'");	
	this->EndDialog(TRUE);
}

// ����� �������� �� ��������� �������
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
