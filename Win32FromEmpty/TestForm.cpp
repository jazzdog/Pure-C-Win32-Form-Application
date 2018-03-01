#include <windows.h>
#include "resource.h"
//#include "vld.h"



BOOL CALLBACK DialogProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam);

union {
        unsigned char bits;
		struct {
		  unsigned char SWINT:1;
		  unsigned char CAN:1;
		  unsigned char OC0Hold:1;
		  unsigned char CH:1;
		  unsigned char DCH:1;
		  unsigned char IDLE:1;
		 
		};
}FLAG;

void test();
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PSTR pCmdLine, int iCmdShow)
{
	MSG msg;
	int ret;
	
	

	HWND hwnd = CreateDialog(hInstance, MAKEINTRESOURCE(DLG_MAIN), NULL, DialogProc);
	


	while((ret = GetMessage(&msg, NULL, 0, 0)) > 0) 
	{
		if (IsDialogMessage(hwnd, &msg)>0)
		{ 
			
			TranslateMessage(&msg); 
			DispatchMessage(&msg); 
		} 
	} 
	//DestroyWindow(hwnd);
	return 0;
}


BOOL CALLBACK DialogProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{

	switch(message)
    {
		
		case WM_LBUTTONDOWN:
		//case WM_LBUTTONDBLCLK:
        {
            wchar_t szFileName[MAX_PATH];
			DWORD nSize;
            HINSTANCE hInstance = GetModuleHandle(NULL);
            GetModuleFileName(hInstance, szFileName, MAX_PATH);
			GetComputerName(szFileName, &nSize);
			//utility.getComputerName();
			MessageBox(hwnd, szFileName ,L"This program is:", MB_OK | MB_ICONINFORMATION);
			
        }
        break;

        case WM_CLOSE: //right-Top button [X]
            DestroyWindow(hwnd);
		break;

        case WM_DESTROY:
            PostQuitMessage(0);
		break;

		case WM_COMMAND:
			switch(LOWORD(wParam))
			{
				case IDCANCEL://ESC
					SendMessage(hwnd, WM_DESTROY, 0, 0);
					break;
				case IDC_BUTTON_TEST:
					{
						//MessageBox(hwnd, L"test" ,L"This program is:", MB_OK | MB_ICONINFORMATION);
						test();
					}
					break;
				case IDC_BUTTON_EXIT:
					SendMessage(hwnd, WM_DESTROY, 0, 0);
					break;
				case IDOK:
					
					break;
			}
		break;

        default:
            DefWindowProc(hwnd, message, wParam, lParam); ///not good for dialog that can't get any other message
			break;
    }
    return 0;
}

void test()
{
	::OutputDebugStringA("test().........\n ");
	return;
}