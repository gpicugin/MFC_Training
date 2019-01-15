#include <afxwin.h>
#include "resource.h"

// ����� �������� ����
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
	CString infoStr; 
	// ������, ������������ � ������� ����� ����
	DECLARE_MESSAGE_MAP()
};

// ����� ����������
class CApp: public CWinApp {
public:
	BOOL InitInstance();	
};
// ����� ����������� ����
class CSampleDialog: public CDialog {
public:
	// DialogName -- ������������� ������� � ��������,
	// Owner -- ����-�������� (���� NULL, �� ������� ����)
	CSampleDialog(char *DialogName, CWnd *Owner = NULL);
	BOOL OnInitDialog();
	afx_msg void OnCommand_Red();
	afx_msg void OnCommand_Green();
	afx_msg void OnCommand_EditOK();

	// ����� �������� ������ ���� �����
	afx_msg void OnSelectFruit();
	afx_msg void OnCancel();
private:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLbnDblclkList1();
};