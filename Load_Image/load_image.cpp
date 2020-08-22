


#include <windows.h>
#include <STDLIB.h>
#include <stdio.h>
#include <math.h>



HBITMAP hbitmap;
HDC hmemdc;



//---------------------------------------------------------------------------------
int on_create(HWND hwnd, UINT message, UINT wParam, long lParam)
{
HDC hdc=GetDC(hwnd);


hbitmap=(HBITMAP)malloc(sizeof(HBITMAP));
hbitmap=(HBITMAP)LoadImage((HINSTANCE)hwnd,"sioni.bmp",IMAGE_BITMAP,0,0,LR_LOADFROMFILE|LR_CREATEDIBSECTION);

hmemdc=CreateCompatibleDC(hdc);
SelectObject(hmemdc,hbitmap);

return 0;
}
//---------------------------------------------------------------------------------
int on_paint(HWND hwnd, UINT message, UINT wParam, long lParam)
{
HDC hdc=GetDC(hwnd);
StretchBlt(hdc,0,0,600,600,hmemdc,100,50,300,200,SRCCOPY);

return 0;
}
//---------------------------------------------------------------------------------
long __stdcall saxeli(HWND hwnd, UINT message, UINT wParam, long lParam)
//void saxeli(MSG m)
{

	if(message == WM_CREATE)
	{
	on_create(hwnd, message, wParam,lParam);
	}
	else if(message == WM_COMMAND)
	{
	}
	else if(message == WM_KEYDOWN)
	{
	}
	else if(message == WM_CHAR)
	{
	}
	else if(message == WM_SIZE)
	{
	}
	else if(message == WM_TIMER)
	{
	}
	else if(message == WM_PAINT)
	{
	on_paint(hwnd, message, wParam,lParam);
	}
	else if(message == WM_MOUSEMOVE)
	{
	}
	else if(message == WM_LBUTTONDOWN)
	{
	}
	else if(message == WM_MBUTTONDOWN)
	{

	}
	else if(message == WM_RBUTTONDOWN)
	{
	}
	else if(message == WM_LBUTTONDBLCLK)
	{
	}
	else if(message == WM_DESTROY)
	{
	PostQuitMessage(0);
	}

return DefWindowProc(hwnd, message, wParam,lParam);

}
//---------------------------------------------------------------------------------


//int __stdcall WinMain(HINSTANCE,HINSTANCE,char*,int)
void main() //for win32 consol apps
{
int x=1;
MSG msg;
WNDCLASSEX wcx;
 

wcx.cbSize = sizeof(wcx);           
wcx.style = 0;                
wcx.lpfnWndProc = saxeli;
wcx.cbClsExtra = 0;                
wcx.cbWndExtra = 0;                 
wcx.hInstance = 0;          

wcx.hIcon = 0;              
wcx.hCursor =0;                    
wcx.hbrBackground = (HBRUSH)CreateSolidBrush(RGB(120,103,560));                 

wcx.lpszMenuName =  "MainMenu";   
wcx.lpszClassName = "trainings";  
wcx.hIconSm = 0;
HWND hwnd1;

	if(RegisterClassEx(&wcx))
	{
	hwnd1=CreateWindow(wcx.lpszClassName,"Trainings",WS_OVERLAPPEDWINDOW|WS_CLIPCHILDREN,100,100,800,400,0,0,0,0);

	ShowWindow(hwnd1,SW_SHOW);											



///SetWindowLong(hwnd1, GWL_WNDPROC,(LONG)saxeli);

		while(x)
		{
		x=GetMessage(&msg,0,0,0);
		TranslateMessage(&msg);
		DispatchMessage(&msg);
		}
	}
	
}

	
	
