#include <string>
#include "SIMPWIN.HPP"

// �������� ������ � ������ ������ ����������
// ����������
 
CApp App;
// ����������
 
BOOL CApp::InitInstance()
{
	//AfxSetAmbientActCtx(FALSE);
	//CWinApp::InitInstance();
// �������� �������� ���� ���������� � ���
// �����������.
 
// ���� CApp::m_pMainWnd - ��� ��������� �� ������
// �������� ����.
 
	m_pMainWnd = new CMainWin;
	m_pMainWnd->ShowWindow(SW_RESTORE);
	m_pMainWnd->UpdateWindow();

// ������������� MFC �� �������� �������������
// ����������. 
 
	return TRUE;
}
 
CMainWin::CMainWin()
{
// �������� ���� � ����������. ������������
// ���������� � MFC
 
// ����� ����, ������� ������ �������� 0.
Create(0, "���������� ���������� �� MFC");
}
 


// ���������� ����� ���������
BEGIN_MESSAGE_MAP(CMainWin /*����� ����*/, CFrameWnd
/*�����-������*/)
END_MESSAGE_MAP()