#include <afxwin.h>
#include "resource.h"

// ����� �������� ����
class CMainWin;

class CSampleDialog: public CDialog
{
public:
	CSampleDialog();
	// ������� �������� ������� � ��������

	BOOL Create(LPCSTR DialogName, CWnd *Owner = 0);
	BOOL OnInitDialog();
	afx_msg void OnCommand_Red();
	afx_msg void OnCommand_Green();
	afx_msg void OnCommand_EditOK();
	afx_msg void OnSelectFruit();
	afx_msg void OnCancel();
private:

	// ����������, ������������, ������������ �� �
	// ������ ������ ������

	BOOL inUse;
	CMainWin *owner;
	DECLARE_MESSAGE_MAP()
};

class CMainWin: public CFrameWnd {
public:
	// ����������� ������� �������.
	// Title -- ��������� ����, HowShow -- ��� ������ ���� 	
	CMainWin(CString Title, int HowShow); 
	afx_msg void OnCommand_Dialog(); 
	afx_msg void OnCommand_Exit();
	afx_msg void OnCommand_Help();
	afx_msg void OnPaint();	
	afx_msg void OnDestroy();	
	// ��������� ������, ������������ � �������
	// ����� ����
	virtual void SetInfoStr(CString str);
private:
	// ��������� ������� ������� -
 
 	// ���������� ��� �����, ���� ����������
 	// �������� ����
 
 	CSampleDialog dialog;
	CString infoStr; 
	// ������, ������������ � ������� ����� ����
	DECLARE_MESSAGE_MAP()
};

// ����� ����������
class CApp: public CWinApp {
public:
	BOOL InitInstance();	
};
// ����� ������������ �������
