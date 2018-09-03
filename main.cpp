
#include <tchar.h>
#include <Windows.h>
#include "CELLWinApp.hpp"


int CALLBACK _tWinMain(HINSTANCE hInstance,HINSTANCE hPrevInst,LPTSTR lpCmdLine,int nShowCmd)
{

    for(int i = 0; i < 100; i++)
    {
     std::cout<<"hello world!"<<std::end;   
    }
    CELLWinApp  app(hInstance);

    app.main(800,600);
    system("pause");
    return  0;
}
