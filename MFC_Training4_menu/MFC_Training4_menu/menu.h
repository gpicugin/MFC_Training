#include <afxwin.h>
class CMainWin: public CFrameWnd {
 	public:
 	CMainWin();
 	afx_msg void OnPaint();
 	// ����������� ������ ���� � �������������
 	afx_msg void OnCommand_Alpha();
 	afx_msg void OnCommand_Beta();
 	afx_msg void OnCommand_Gamma();
 	afx_msg void OnCommand_Epsilon();
 	afx_msg void OnCommand_Zeta();
 	afx_msg void OnCommand_Eta();
 	afx_msg void OnCommand_Theta();
 	afx_msg void OnCommand_Help();
 	afx_msg void OnCommand_Time(); //������ �����������
 	DECLARE_MESSAGE_MAP()
 	};

	// ����� ����������
	class CApp: public CWinApp {
   	public:
 	BOOL InitInstance();
 	};