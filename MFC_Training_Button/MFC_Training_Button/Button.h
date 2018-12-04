#include <afxwin.h>
#include <string>
#include "resource.h"
#include "SimpleButton.h"

#define IDC_MYBUTTON 100	// ������������� ������
#define IDC_MYEDIT 102	// ������������� ���� ��������������

class CMyButton: public CButton
{
public:
	afx_msg void OnLButtonDblClk(UINT, CPoint);
	afx_msg void OnRButtonDblClk(UINT, CPoint);
private:
	DECLARE_MESSAGE_MAP(); // ������� �������� ������
};

// ����� ��������� ����
class CMainWnd : public CFrameWnd
{
public:
	CMainWnd();
	afx_msg void OnLButtonDblClk(UINT, CPoint);
	afx_msg void OnRButtonDblClk(UINT, CPoint);
	afx_msg void OnKeyDown(UINT, UINT, UINT);
	afx_msg void OnDestroy();
private:
	CStatic* MyStatic;      // ������� ���������� ��� ������ ������
	CMyButton* MyButton;// ������� ���������� ������
	CEdit* MyEdit;  // ������� ��������������
	DECLARE_MESSAGE_MAP(); // ������� ��������
};
// ����� ����������
class CApp: public CWinApp {
public:
	BOOL InitInstance();
};