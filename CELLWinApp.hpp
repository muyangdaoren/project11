#pragma once

#include <tchar.h>
#include <Windows.h>

class CELLWinApp
{
protected:

    HWND        _hWnd;
    HINSTANCE   _hInst;
public:

    CELLWinApp(HINSTANCE hInstance)
        :_hInst(hInstance)
    {
        //1 注册一个窗口类
        WNDCLASSEX  wndClass;
        memset(&wndClass,0,sizeof(wndClass));
        wndClass.cbSize         =   sizeof(wndClass);
        wndClass.style          =   CS_VREDRAW | CS_HREDRAW| CS_OWNDC;
        wndClass.hbrBackground  =   (HBRUSH)GetStockObject(BLACK_BRUSH);
        wndClass.hCursor        =   ::LoadCursor(hInstance,IDC_ARROW);

        wndClass.lpszClassName  =   _T("CELLWinApp");
        wndClass.lpfnWndProc    =   wndProc;
        wndClass.hIcon          =   0;
        wndClass.lpszMenuName   =   0;
        
        RegisterClassEx(&wndClass);

    }

    virtual ~CELLWinApp(void)
    {
        UnregisterClass(_T("CELLWinApp"),_hInst);
    }

    static  LRESULT CALLBACK wndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
    {
        switch(msg)
        {
        case WM_CREATE:
            break;
        case WM_DESTROY:
        case WM_CLOSE:
            PostQuitMessage(0);
            break;
        default:
            return  DefWindowProc(hWnd,msg,wParam,lParam);
        }
        return  S_OK;
    }

    int     main(int width,int height)
    {
        //2 创建窗口

        _hWnd   =   CreateWindow(_T("CELLWinApp"),_T("CELLWinApp"),WS_OVERLAPPEDWINDOW,0,0,width,height,0,0,_hInst,this);

        if (_hWnd == 0)
        {
            return  0;
        }
        //3 更新显示窗口
        UpdateWindow(_hWnd);
        //4 显示
        ShowWindow(_hWnd,SW_MAXIMIZE);

        //5 消息循环
        MSG     msg =   {0};

        while(GetMessage(&msg,0,0,0))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
        return  0;
    }
    std::cout<<"hello world!"<<std::endl;
    std::cout<<"hello world!"<<std::endl;
    std::cout<<"hello world!"<<std::endl;
    std::cout<<"hello world!"<<std::endl;
};
