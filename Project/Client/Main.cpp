#include "pch.h"

#include "../Core/Framework.h"


INT APIENTRY WinMain(HINSTANCE instanceHandle, HINSTANCE, LPSTR command, INT commandNumber)
{


    Framework::Core::Framework framework;

    if (!framework.Initialize(instanceHandle))
    {
        MessageBox(NULL, TEXT("Framework::Initialize"), TEXT("Fail"), MB_OK);
        return -1;
    }

    framework.Run();

    return 0;

}