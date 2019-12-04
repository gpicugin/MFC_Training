//#define _AFXDLL //<<===notice this
//
//#include <afxwin.h>
//#include <winsock2.h>
//#include <winsock.h>
//#include <windows.h>
//#include <conio.h>
#include "stdafx.h"




//other C++ standard headers here as required




// The one and only application object
CWinApp theApp;

long i = 0;
bool bThreadstop;  //контрольная переменная

UINT ThreadProc(LPVOID pParam) // потоковая функция
{
	::MessageBox((HWND)pParam, "Thread activated", "Message from Thread", MB_OK);
	while (!bThreadstop)
	{
		i++;
		//Выполнение операций
	}
	::MessageBox((HWND)pParam, "Thread ended", "Message from thread", MB_OK);
	return 0;
}

void SomeFunc()
{
	bThreadstop = false;
	AfxBeginThread(ThreadProc, 0);  //Запуск потока
}

void StopThread()
{
	bThreadstop = true;  //остановка потока
	cout << i << '\n';
}

int _tmain(int argc, _TCHAR* argv[])
{


	// initialize MFC
	if (!AfxWinInit(::GetModuleHandle(NULL), NULL, ::GetCommandLine(), 0))
	{
		// TODO: change error code to suit your needs
		_tprintf(_T("Fatal Error: MFC initialization failed\n"));
		return 1;
	}
	int nRetCode = 0;
	cout << "Press ESCAPE to terminate program\r\n";
	cout << i << '\n';
	SomeFunc();	

	Sleep(6000);

	//AfxBeginThread(ThreadProc, 0);
	StopThread();
	cout << i << '\n';
	while (_getch() != 27);

	return nRetCode;

}