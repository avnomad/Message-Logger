//	Copyright (C) 2010-2012 Vaptistis Anogeianakis <el05208@mail.ntua.gr>
/*
 *	This file is part of Message Logger.
 *
 *	Message Logger is free software: you can redistribute it and/or modify
 *	it under the terms of the GNU General Public License as published by
 *	the Free Software Foundation, either version 3 of the License, or
 *	(at your option) any later version.
 *
 *	Message Logger is distributed in the hope that it will be useful,
 *	but WITHOUT ANY WARRANTY; without even the implied warranty of
 *	MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *	GNU General Public License for more details.
 *
 *	You should have received a copy of the GNU General Public License
 *	along with Message Logger.  If not, see <http://www.gnu.org/licenses/>.
 */

#include <iostream>
using std::cout;
using std::cin;
using std::endl;
using std::cerr;
using std::clog;
using std::left;

#include <cstdlib>
using std::system;
using std::exit;

#include <windows.h>

#define escape(A) #A
#define length(A) (sizeof(A)/sizeof((A)[0]))

LRESULT CALLBACK logWindowProcedure(HWND window,UINT message,WPARAM argW,LPARAM argL);

int main()
{
	WNDCLASS trivialClass;

	trivialClass.style = CS_HREDRAW | CS_VREDRAW;
	trivialClass.lpfnWndProc = logWindowProcedure;
	trivialClass.cbClsExtra = 0;
	trivialClass.cbWndExtra = 0;
	trivialClass.hInstance = GetModuleHandle(NULL);
	trivialClass.hIcon = LoadIcon(NULL,IDI_APPLICATION);
	trivialClass.hCursor = LoadCursor(NULL,IDC_ARROW);
	trivialClass.hbrBackground = (HBRUSH)GetStockObject(BLACK_BRUSH);
	trivialClass.lpszMenuName = NULL;
	trivialClass.lpszClassName = TEXT("trivialClass");

	RegisterClass(&trivialClass);

	HWND mainWindow = CreateWindow(TEXT("trivialClass"),TEXT("Log Messages"),WS_OVERLAPPEDWINDOW,
			CW_USEDEFAULT,CW_USEDEFAULT,100,100,NULL,NULL,GetModuleHandle(NULL),NULL);
	ShowWindow(mainWindow,SW_SHOWNORMAL);
	UpdateWindow(mainWindow);

	RegisterTouchWindow(mainWindow,TWF_FINETOUCH|TWF_WANTPALM);
	//UINT n = 0;
	//RAWINPUTDEVICE devices[2];
	//devices[0].usUsagePage = 1;
	//devices[0].usUsage = 6;
	//devices[0].dwFlags = RIDEV_DEVNOTIFY|RIDEV_INPUTSINK|RIDEV_NOLEGACY;
	//devices[0].hwndTarget = mainWindow;
	//devices[1].usUsagePage = 1;
	//devices[1].usUsage = 2;
	//devices[1].dwFlags = RIDEV_DEVNOTIFY|RIDEV_INPUTSINK;
	//devices[1].hwndTarget = mainWindow;
	//RegisterRawInputDevices(devices,length(devices),sizeof(devices[0]));
	//GetRegisteredRawInputDevices(devices,&n,sizeof(devices[0]));
	//cout << "n = " << n << endl;


	MSG message;
	while(GetMessage(&message,NULL,0,0))
	{
		//cout << "loop in" << endl;
		TranslateMessage(&message);
		//cout << "loop middle" << endl;
		DispatchMessage(&message);
		//cout << "loop out" << endl;
	} // end while

	system("pause");
	return message.wParam;
} // end function main


LRESULT CALLBACK logWindowProcedure(HWND window,UINT message,WPARAM argW,LPARAM argL)
{
	switch(message)
	{
#include "cases.h"	// include automatically generated cases.
	case WM_DESTROY:
		cout << escape(WM_DESTROY)<< endl;
		PostQuitMessage(0);
		break;
	default:
		cout << message << endl;
		break;
	} // end switch
	return DefWindowProc(window,message,argW,argL);
} // end fuction logWindowProcedure
