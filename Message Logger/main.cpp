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

	UINT n = 0;
	RAWINPUTDEVICE devices[2];
	devices[0].usUsagePage = 1;
	devices[0].usUsage = 6;
	devices[0].dwFlags = RIDEV_DEVNOTIFY|RIDEV_INPUTSINK|RIDEV_NOLEGACY;
	devices[0].hwndTarget = mainWindow;
	devices[1].usUsagePage = 1;
	devices[1].usUsage = 2;
	devices[1].dwFlags = RIDEV_DEVNOTIFY|RIDEV_INPUTSINK;
	devices[1].hwndTarget = mainWindow;
	RegisterRawInputDevices(devices,length(devices),sizeof(devices[0]));
	GetRegisteredRawInputDevices(devices,&n,sizeof(devices[0]));
	cout << "n = " << n << endl;


	MSG message;
	while(GetMessage(&message,NULL,0,0))
	{
		TranslateMessage(&message);
		DispatchMessage(&message);
	} // end while

	system("pause");
	return message.wParam;
} // end function main


LRESULT CALLBACK logWindowProcedure(HWND window,UINT message,WPARAM argW,LPARAM argL)
{
	switch(message)
	{
	case WM_NULL:
		cout << escape(WM_NULL) << endl;
		break;
	case WM_CREATE:
		cout << escape(WM_CREATE) << endl;
		break;
	case WM_MOVE:
		cout << escape(WM_MOVE) << endl;
		break;
	case WM_SIZE:
		cout << escape(WM_SIZE) << endl;
		break;
	case WM_ACTIVATE:
		cout << escape(WM_ACTIVATE) << endl;
		break;
	case WM_SETFOCUS:
		cout << escape(WM_SETFOCUS) << endl;
		break;
	case WM_KILLFOCUS:
		cout << escape(WM_KILLFOCUS) << endl;
		break;
	case WM_ENABLE:
		cout << escape(WM_ENABLE) << endl;
		break;
	case WM_SETREDRAW:
		cout << escape(WM_SETREDRAW) << endl;
		break;
	case WM_SETTEXT:
		cout << escape(WM_SETTEXT) << endl;
		break;
	case WM_GETTEXT:
		cout << escape(WM_GETTEXT) << endl;
		break;
	case WM_GETTEXTLENGTH:
		cout << escape(WM_GETTEXTLENGTH) << endl;
		break;
	case WM_PAINT:
		cout << escape(WM_PAINT) << endl;
		break;
	case WM_CLOSE:
		cout << escape(WM_CLOSE) << endl;
		break;
	case WM_QUERYENDSESSION:
		cout << escape(WM_QUERYENDSESSION) << endl;
		break;
	case WM_QUERYOPEN:
		cout << escape(WM_QUERYOPEN) << endl;
		break;
	case WM_ENDSESSION:
		cout << escape(WM_ENDSESSION) << endl;
		break;
	case WM_QUIT:
		cout << escape(WM_QUIT) << endl;
		break;
	case WM_ERASEBKGND:
		cout << escape(WM_ERASEBKGND) << endl;
		break;
	case WM_SYSCOLORCHANGE:
		cout << escape(WM_SYSCOLORCHANGE) << endl;
		break;
	case WM_SHOWWINDOW:
		cout << escape(WM_SHOWWINDOW) << endl;
		break;
	case WM_SETTINGCHANGE:
		cout << escape(WM_SETTINGCHANGE) << endl;
		break;
	case WM_DEVMODECHANGE:
		cout << escape(WM_DEVMODECHANGE) << endl;
		break;
	case WM_ACTIVATEAPP:
		cout << escape(WM_ACTIVATEAPP) << endl;
		break;
	case WM_FONTCHANGE:
		cout << escape(WM_FONTCHANGE) << endl;
		break;
	case WM_TIMECHANGE:
		cout << escape(WM_TIMECHANGE) << endl;
		break;
	case WM_CANCELMODE:
		cout << escape(WM_CANCELMODE) << endl;
		break;
	case WM_SETCURSOR:
		cout << escape(WM_SETCURSOR) << endl;
		break;
	case WM_MOUSEACTIVATE:
		cout << escape(WM_MOUSEACTIVATE) << endl;
		break;
	case WM_CHILDACTIVATE:
		cout << escape(WM_CHILDACTIVATE) << endl;
		break;
	case WM_QUEUESYNC:
		cout << escape(WM_QUEUESYNC) << endl;
		break;
	case WM_GETMINMAXINFO:
		cout << escape(WM_GETMINMAXINFO) << endl;
		break;
	case WM_PAINTICON:
		cout << escape(WM_PAINTICON) << endl;
		break;
	case WM_ICONERASEBKGND:
		cout << escape(WM_ICONERASEBKGND) << endl;
		break;
	case WM_NEXTDLGCTL:
		cout << escape(WM_NEXTDLGCTL) << endl;
		break;
	case WM_SPOOLERSTATUS:
		cout << escape(WM_SPOOLERSTATUS) << endl;
		break;
	case WM_DRAWITEM:
		cout << escape(WM_DRAWITEM) << endl;
		break;
	case WM_MEASUREITEM:
		cout << escape(WM_MEASUREITEM) << endl;
		break;
	case WM_DELETEITEM:
		cout << escape(WM_DELETEITEM) << endl;
		break;
	case WM_VKEYTOITEM:
		cout << escape(WM_VKEYTOITEM) << endl;
		break;
	case WM_CHARTOITEM:
		cout << escape(WM_CHARTOITEM) << endl;
		break;
	case WM_SETFONT:
		cout << escape(WM_SETFONT) << endl;
		break;
	case WM_GETFONT:
		cout << escape(WM_GETFONT) << endl;
		break;
	case WM_SETHOTKEY:
		cout << escape(WM_SETHOTKEY) << endl;
		break;
	case WM_GETHOTKEY:
		cout << escape(WM_GETHOTKEY) << endl;
		break;
	case WM_QUERYDRAGICON:
		cout << escape(WM_QUERYDRAGICON) << endl;
		break;
	case WM_COMPAREITEM:
		cout << escape(WM_COMPAREITEM) << endl;
		break;
	case WM_GETOBJECT:
		cout << escape(WM_GETOBJECT) << endl;
		break;
	case WM_COMPACTING:
		cout << escape(WM_COMPACTING) << endl;
		break;
	case WM_COMMNOTIFY:
		cout << escape(WM_COMMNOTIFY) << endl;
		break;
	case WM_WINDOWPOSCHANGING:
		cout << escape(WM_WINDOWPOSCHANGING) << endl;
		break;
	case WM_WINDOWPOSCHANGED:
		cout << escape(WM_WINDOWPOSCHANGED) << endl;
		break;
	case WM_POWER:
		cout << escape(WM_POWER) << endl;
		break;
	case WM_COPYDATA:
		cout << escape(WM_COPYDATA) << endl;
		break;
	case WM_CANCELJOURNAL:
		cout << escape(WM_CANCELJOURNAL) << endl;
		break;
	case WM_NOTIFY:
		cout << escape(WM_NOTIFY) << endl;
		break;
	case WM_INPUTLANGCHANGEREQUEST:
		cout << escape(WM_INPUTLANGCHANGEREQUEST) << endl;
		break;
	case WM_INPUTLANGCHANGE:
		cout << escape(WM_INPUTLANGCHANGE) << endl;
		break;
	case WM_TCARD:
		cout << escape(WM_TCARD) << endl;
		break;
	case WM_HELP:
		cout << escape(WM_HELP) << endl;
		break;
	case WM_USERCHANGED:
		cout << escape(WM_USERCHANGED) << endl;
		break;
	case WM_NOTIFYFORMAT:
		cout << escape(WM_NOTIFYFORMAT) << endl;
		break;
	case WM_CONTEXTMENU:
		cout << escape(WM_CONTEXTMENU) << endl;
		break;
	case WM_STYLECHANGING:
		cout << escape(WM_STYLECHANGING) << endl;
		break;
	case WM_STYLECHANGED:
		cout << escape(WM_STYLECHANGED) << endl;
		break;
	case WM_DISPLAYCHANGE:
		cout << escape(WM_DISPLAYCHANGE) << endl;
		break;
	case WM_GETICON:
		cout << escape(WM_GETICON) << endl;
		break;
	case WM_SETICON:
		cout << escape(WM_SETICON) << endl;
		break;
	case WM_NCCREATE:
		cout << escape(WM_NCCREATE) << endl;
		break;
	case WM_NCDESTROY:
		cout << escape(WM_NCDESTROY) << endl;
		break;
	case WM_NCCALCSIZE:
		cout << escape(WM_NCCALCSIZE) << endl;
		break;
	case WM_NCHITTEST:
		cout << escape(WM_NCHITTEST) << endl;
		break;
	case WM_NCPAINT:
		cout << escape(WM_NCPAINT) << endl;
		break;
	case WM_NCACTIVATE:
		cout << escape(WM_NCACTIVATE) << endl;
		break;
	case WM_GETDLGCODE:
		cout << escape(WM_GETDLGCODE) << endl;
		break;
	case WM_SYNCPAINT:
		cout << escape(WM_SYNCPAINT) << endl;
		break;
	case WM_NCMOUSEMOVE:
		cout << escape(WM_NCMOUSEMOVE) << endl;
		break;
	case WM_NCLBUTTONDOWN:
		cout << escape(WM_NCLBUTTONDOWN) << endl;
		break;
	case WM_NCLBUTTONUP:
		cout << escape(WM_NCLBUTTONUP) << endl;
		break;
	case WM_NCLBUTTONDBLCLK:
		cout << escape(WM_NCLBUTTONDBLCLK) << endl;
		break;
	case WM_NCRBUTTONDOWN:
		cout << escape(WM_NCRBUTTONDOWN) << endl;
		break;
	case WM_NCRBUTTONUP:
		cout << escape(WM_NCRBUTTONUP) << endl;
		break;
	case WM_NCRBUTTONDBLCLK:
		cout << escape(WM_NCRBUTTONDBLCLK) << endl;
		break;
	case WM_NCMBUTTONDOWN:
		cout << escape(WM_NCMBUTTONDOWN) << endl;
		break;
	case WM_NCMBUTTONUP:
		cout << escape(WM_NCMBUTTONUP) << endl;
		break;
	case WM_NCMBUTTONDBLCLK:
		cout << escape(WM_NCMBUTTONDBLCLK) << endl;
		break;
	case WM_NCXBUTTONDOWN:
		cout << escape(WM_NCXBUTTONDOWN) << endl;
		break;
	case WM_NCXBUTTONUP:
		cout << escape(WM_NCXBUTTONUP) << endl;
		break;
	case WM_NCXBUTTONDBLCLK:
		cout << escape(WM_NCXBUTTONDBLCLK) << endl;
		break;
	case WM_INPUT_DEVICE_CHANGE:
		cout << escape(WM_INPUT_DEVICE_CHANGE) << endl;
		break;
	case WM_INPUT:
		cout << escape(WM_INPUT) << endl;
		break;
	case WM_KEYDOWN:
		cout << escape(WM_KEYDOWN) << endl;
		break;
	case WM_KEYUP:
		cout << escape(WM_KEYUP) << endl;
		break;
	case WM_CHAR:
		cout << escape(WM_CHAR) << endl;
		break;
	case WM_DEADCHAR:
		cout << escape(WM_DEADCHAR) << endl;
		break;
	case WM_SYSKEYDOWN:
		cout << escape(WM_SYSKEYDOWN) << endl;
		break;
	case WM_SYSKEYUP:
		cout << escape(WM_SYSKEYUP) << endl;
		break;
	case WM_SYSCHAR:
		cout << escape(WM_SYSCHAR) << endl;
		break;
	case WM_SYSDEADCHAR:
		cout << escape(WM_SYSDEADCHAR) << endl;
		break;
	case WM_UNICHAR:
		cout << escape(WM_UNICHAR) << endl;
		break;
	case WM_IME_STARTCOMPOSITION:
		cout << escape(WM_IME_STARTCOMPOSITION) << endl;
		break;
	case WM_IME_ENDCOMPOSITION:
		cout << escape(WM_IME_ENDCOMPOSITION) << endl;
		break;
	case WM_IME_COMPOSITION:
		cout << escape(WM_IME_COMPOSITION) << endl;
		break;
	case WM_INITDIALOG:
		cout << escape(WM_INITDIALOG) << endl;
		break;
	case WM_COMMAND:
		cout << escape(WM_COMMAND) << endl;
		break;
	case WM_SYSCOMMAND:
		cout << escape(WM_SYSCOMMAND) << endl;
		break;
	case WM_TIMER:
		cout << escape(WM_TIMER) << endl;
		break;
	case WM_HSCROLL:
		cout << escape(WM_HSCROLL) << endl;
		break;
	case WM_VSCROLL:
		cout << escape(WM_VSCROLL) << endl;
		break;
	case WM_INITMENU:
		cout << escape(WM_INITMENU) << endl;
		break;
	case WM_INITMENUPOPUP:
		cout << escape(WM_INITMENUPOPUP) << endl;
		break;
	case WM_GESTURE:
		cout << escape(WM_GESTURE) << endl;
		break;
	case WM_GESTURENOTIFY:
		cout << escape(WM_GESTURENOTIFY) << endl;
		break;
	case WM_MENUSELECT:
		cout << escape(WM_MENUSELECT) << endl;
		break;
	case WM_MENUCHAR:
		cout << escape(WM_MENUCHAR) << endl;
		break;
	case WM_ENTERIDLE:
		cout << escape(WM_ENTERIDLE) << endl;
		break;
	case WM_MENURBUTTONUP:
		cout << escape(WM_MENURBUTTONUP) << endl;
		break;
	case WM_MENUDRAG:
		cout << escape(WM_MENUDRAG) << endl;
		break;
	case WM_MENUGETOBJECT:
		cout << escape(WM_MENUGETOBJECT) << endl;
		break;
	case WM_UNINITMENUPOPUP:
		cout << escape(WM_UNINITMENUPOPUP) << endl;
		break;
	case WM_MENUCOMMAND:
		cout << escape(WM_MENUCOMMAND) << endl;
		break;
	case WM_CHANGEUISTATE:
		cout << escape(WM_CHANGEUISTATE) << endl;
		break;
	case WM_UPDATEUISTATE:
		cout << escape(WM_UPDATEUISTATE) << endl;
		break;
	case WM_QUERYUISTATE:
		cout << escape(WM_QUERYUISTATE) << endl;
		break;
	case WM_CTLCOLORMSGBOX:
		cout << escape(WM_CTLCOLORMSGBOX) << endl;
		break;
	case WM_CTLCOLOREDIT:
		cout << escape(WM_CTLCOLOREDIT) << endl;
		break;
	case WM_CTLCOLORLISTBOX:
		cout << escape(WM_CTLCOLORLISTBOX) << endl;
		break;
	case WM_CTLCOLORBTN:
		cout << escape(WM_CTLCOLORBTN) << endl;
		break;
	case WM_CTLCOLORDLG:
		cout << escape(WM_CTLCOLORDLG) << endl;
		break;
	case WM_CTLCOLORSCROLLBAR:
		cout << escape(WM_CTLCOLORSCROLLBAR) << endl;
		break;
	case WM_CTLCOLORSTATIC:
		cout << escape(WM_CTLCOLORSTATIC) << endl;
		break;
	case WM_MOUSEMOVE:
		cout << escape(WM_MOUSEMOVE) << endl;
		break;
	case WM_LBUTTONDOWN:
		cout << escape(WM_LBUTTONDOWN) << endl;
		break;
	case WM_LBUTTONUP:
		cout << escape(WM_LBUTTONUP) << endl;
		break;
	case WM_LBUTTONDBLCLK:
		cout << escape(WM_LBUTTONDBLCLK) << endl;
		break;
	case WM_RBUTTONDOWN:
		cout << escape(WM_RBUTTONDOWN) << endl;
		break;
	case WM_RBUTTONUP:
		cout << escape(WM_RBUTTONUP) << endl;
		break;
	case WM_RBUTTONDBLCLK:
		cout << escape(WM_RBUTTONDBLCLK) << endl;
		break;
	case WM_MBUTTONDOWN:
		cout << escape(WM_MBUTTONDOWN) << endl;
		break;
	case WM_MBUTTONUP:
		cout << escape(WM_MBUTTONUP) << endl;
		break;
	case WM_MBUTTONDBLCLK:
		cout << escape(WM_MBUTTONDBLCLK) << endl;
		break;
	case WM_MOUSEWHEEL:
		cout << escape(WM_MOUSEWHEEL) << endl;
		break;
	case WM_XBUTTONDOWN:
		cout << escape(WM_XBUTTONDOWN) << endl;
		break;
	case WM_XBUTTONUP:
		cout << escape(WM_XBUTTONUP) << endl;
		break;
	case WM_XBUTTONDBLCLK:
		cout << escape(WM_XBUTTONDBLCLK) << endl;
		break;
	case WM_MOUSEHWHEEL:
		cout << escape(WM_MOUSEHWHEEL) << endl;
		break;
	case WM_PARENTNOTIFY:
		cout << escape(WM_PARENTNOTIFY) << endl;
		break;
	case WM_ENTERMENULOOP:
		cout << escape(WM_ENTERMENULOOP) << endl;
		break;
	case WM_EXITMENULOOP:
		cout << escape(WM_EXITMENULOOP) << endl;
		break;
	case WM_NEXTMENU:
		cout << escape(WM_NEXTMENU) << endl;
		break;
	case WM_SIZING:
		cout << escape(WM_SIZING) << endl;
		break;
	case WM_CAPTURECHANGED:
		cout << escape(WM_CAPTURECHANGED) << endl;
		break;
	case WM_MOVING:
		cout << escape(WM_MOVING) << endl;
		break;
	case WM_POWERBROADCAST:
		cout << escape(WM_POWERBROADCAST) << endl;
		break;
	case WM_DEVICECHANGE:
		cout << escape(WM_DEVICECHANGE) << endl;
		break;
	case WM_MDICREATE:
		cout << escape(WM_MDICREATE) << endl;
		break;
	case WM_MDIDESTROY:
		cout << escape(WM_MDIDESTROY) << endl;
		break;
	case WM_MDIACTIVATE:
		cout << escape(WM_MDIACTIVATE) << endl;
		break;
	case WM_MDIRESTORE:
		cout << escape(WM_MDIRESTORE) << endl;
		break;
	case WM_MDINEXT:
		cout << escape(WM_MDINEXT) << endl;
		break;
	case WM_MDIMAXIMIZE:
		cout << escape(WM_MDIMAXIMIZE) << endl;
		break;
	case WM_MDITILE:
		cout << escape(WM_MDITILE) << endl;
		break;
	case WM_MDICASCADE:
		cout << escape(WM_MDICASCADE) << endl;
		break;
	case WM_MDIICONARRANGE:
		cout << escape(WM_MDIICONARRANGE) << endl;
		break;
	case WM_MDIGETACTIVE:
		cout << escape(WM_MDIGETACTIVE) << endl;
		break;
	case WM_MDISETMENU:
		cout << escape(WM_MDISETMENU) << endl;
		break;
	case WM_ENTERSIZEMOVE:
		cout << escape(WM_ENTERSIZEMOVE) << endl;
		break;
	case WM_EXITSIZEMOVE:
		cout << escape(WM_EXITSIZEMOVE) << endl;
		break;
	case WM_DROPFILES:
		cout << escape(WM_DROPFILES) << endl;
		break;
	case WM_MDIREFRESHMENU:
		cout << escape(WM_MDIREFRESHMENU) << endl;
		break;
	case WM_TOUCH:
		cout << escape(WM_TOUCH) << endl;
		break;
	case WM_IME_SETCONTEXT:
		cout << escape(WM_IME_SETCONTEXT) << endl;
		break;
	case WM_IME_NOTIFY:
		cout << escape(WM_IME_NOTIFY) << endl;
		break;
	case WM_IME_CONTROL:
		cout << escape(WM_IME_CONTROL) << endl;
		break;
	case WM_IME_COMPOSITIONFULL:
		cout << escape(WM_IME_COMPOSITIONFULL) << endl;
		break;
	case WM_IME_SELECT:
		cout << escape(WM_IME_SELECT) << endl;
		break;
	case WM_IME_CHAR:
		cout << escape(WM_IME_CHAR) << endl;
		break;
	case WM_IME_REQUEST:
		cout << escape(WM_IME_REQUEST) << endl;
		break;
	case WM_IME_KEYDOWN:
		cout << escape(WM_IME_KEYDOWN) << endl;
		break;
	case WM_IME_KEYUP:
		cout << escape(WM_IME_KEYUP) << endl;
		break;
	case WM_MOUSEHOVER:
		cout << escape(WM_MOUSEHOVER) << endl;
		break;
	case WM_MOUSELEAVE:
		cout << escape(WM_MOUSELEAVE) << endl;
		break;
	case WM_NCMOUSEHOVER:
		cout << escape(WM_NCMOUSEHOVER) << endl;
		break;
	case WM_NCMOUSELEAVE:
		cout << escape(WM_NCMOUSELEAVE) << endl;
		break;
	case WM_WTSSESSION_CHANGE:
		cout << escape(WM_WTSSESSION_CHANGE) << endl;
		break;
	case WM_TABLET_FIRST:
		cout << escape(WM_TABLET_FIRST) << endl;
		break;
	case WM_TABLET_LAST:
		cout << escape(WM_TABLET_LAST) << endl;
		break;
	case WM_CUT:
		cout << escape(WM_CUT) << endl;
		break;
	case WM_COPY:
		cout << escape(WM_COPY) << endl;
		break;
	case WM_PASTE:
		cout << escape(WM_PASTE) << endl;
		break;
	case WM_CLEAR:
		cout << escape(WM_CLEAR) << endl;
		break;
	case WM_UNDO:
		cout << escape(WM_UNDO) << endl;
		break;
	case WM_RENDERFORMAT:
		cout << escape(WM_RENDERFORMAT) << endl;
		break;
	case WM_RENDERALLFORMATS:
		cout << escape(WM_RENDERALLFORMATS) << endl;
		break;
	case WM_DESTROYCLIPBOARD:
		cout << escape(WM_DESTROYCLIPBOARD) << endl;
		break;
	case WM_DRAWCLIPBOARD:
		cout << escape(WM_DRAWCLIPBOARD) << endl;
		break;
	case WM_PAINTCLIPBOARD:
		cout << escape(WM_PAINTCLIPBOARD) << endl;
		break;
	case WM_VSCROLLCLIPBOARD:
		cout << escape(WM_VSCROLLCLIPBOARD) << endl;
		break;
	case WM_SIZECLIPBOARD:
		cout << escape(WM_SIZECLIPBOARD) << endl;
		break;
	case WM_ASKCBFORMATNAME:
		cout << escape(WM_ASKCBFORMATNAME) << endl;
		break;
	case WM_CHANGECBCHAIN:
		cout << escape(WM_CHANGECBCHAIN) << endl;
		break;
	case WM_HSCROLLCLIPBOARD:
		cout << escape(WM_HSCROLLCLIPBOARD) << endl;
		break;
	case WM_QUERYNEWPALETTE:
		cout << escape(WM_QUERYNEWPALETTE) << endl;
		break;
	case WM_PALETTEISCHANGING:
		cout << escape(WM_PALETTEISCHANGING) << endl;
		break;
	case WM_PALETTECHANGED:
		cout << escape(WM_PALETTECHANGED) << endl;
		break;
	case WM_HOTKEY:
		cout << escape(WM_HOTKEY) << endl;
		break;
	case WM_PRINT:
		cout << escape(WM_PRINT) << endl;
		break;
	case WM_PRINTCLIENT:
		cout << escape(WM_PRINTCLIENT) << endl;
		break;
	case WM_APPCOMMAND:
		cout << escape(WM_APPCOMMAND) << endl;
		break;
	case WM_THEMECHANGED:
		cout << escape(WM_THEMECHANGED) << endl;
		break;
	case WM_CLIPBOARDUPDATE:
		cout << escape(WM_CLIPBOARDUPDATE) << endl;
		break;
	case WM_DWMCOMPOSITIONCHANGED:
		cout << escape(WM_DWMCOMPOSITIONCHANGED) << endl;
		break;
	case WM_DWMNCRENDERINGCHANGED:
		cout << escape(WM_DWMNCRENDERINGCHANGED) << endl;
		break;
	case WM_DWMCOLORIZATIONCOLORCHANGED:
		cout << escape(WM_DWMCOLORIZATIONCOLORCHANGED) << endl;
		break;
	case WM_DWMWINDOWMAXIMIZEDCHANGE:
		cout << escape(WM_DWMWINDOWMAXIMIZEDCHANGE) << endl;
		break;
	case WM_DWMSENDICONICTHUMBNAIL:
		cout << escape(WM_DWMSENDICONICTHUMBNAIL) << endl;
		break;
	case WM_DWMSENDICONICLIVEPREVIEWBITMAP:
		cout << escape(WM_DWMSENDICONICLIVEPREVIEWBITMAP) << endl;
		break;
	case WM_GETTITLEBARINFOEX:
		cout << escape(WM_GETTITLEBARINFOEX) << endl;
		break;
	case WM_HANDHELDFIRST:
		cout << escape(WM_HANDHELDFIRST) << endl;
		break;
	case WM_HANDHELDLAST:
		cout << escape(WM_HANDHELDLAST) << endl;
		break;
	case WM_AFXFIRST:
		cout << escape(WM_AFXFIRST) << endl;
		break;
	case WM_AFXLAST:
		cout << escape(WM_AFXLAST) << endl;
		break;
	case WM_PENWINFIRST:
		cout << escape(WM_PENWINFIRST) << endl;
		break;
	case WM_PENWINLAST:
		cout << escape(WM_PENWINLAST) << endl;
		break;
	case WM_APP:
		cout << escape(WM_APP) << endl;
		break;
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
