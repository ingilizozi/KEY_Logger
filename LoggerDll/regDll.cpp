#include "pch.h"
#include <iostream>

BOOL CreateRegistryKey(HKEY hKeyParent, LPCSTR subkey)
{
    DWORD dwDisposition; //It verify new key is created or open existing key
    HKEY  hKey;
    DWORD Ret;
    Ret =
        RegCreateKeyExA(
            hKeyParent,
            subkey,
            0,
            NULL,
            REG_OPTION_NON_VOLATILE,
            KEY_ALL_ACCESS,
            NULL,
            &hKey,
            &dwDisposition);
    if (Ret != ERROR_SUCCESS)
    {
        printf("Error opening or creating new key\n");
        return FALSE;
    }
    RegCloseKey(hKey); //close the key
    return TRUE;
}

BOOL WriteDwordInRegistry(HKEY hKeyParent, LPCSTR subkey, LPCSTR valueName, DWORD data)
{
    DWORD Ret; //use to check status
    HKEY hKey; //key
    //Open the key
    Ret = RegOpenKeyExA(
        hKeyParent,
        subkey,
        0,
        KEY_WRITE,
        &hKey
    );
    if (Ret == ERROR_SUCCESS)
    {
        //Set the value in key
        if (ERROR_SUCCESS !=
            RegSetValueExA(
                hKey,
                valueName,
                0,
                REG_DWORD,
                reinterpret_cast<BYTE*>(&data),
                sizeof(data)))
        {
            RegCloseKey(hKey);
            return FALSE;
        }
        //close the key
        RegCloseKey(hKey);
        return TRUE;
    }
    return FALSE;
}

BOOL readDwordValueRegistry(HKEY hKeyParent, LPCSTR subkey, LPCSTR valueName, DWORD* readData)
{
    HKEY hKey;
    DWORD Ret;
    //Check if the registry exists
    Ret = RegOpenKeyExA(
        hKeyParent,
        subkey,
        0,
        KEY_READ,
        &hKey
    );
    if (Ret == ERROR_SUCCESS)
    {
        DWORD data;
        DWORD len = sizeof(DWORD);//size of data
        Ret = RegQueryValueExA(
            hKey,
            valueName,
            NULL,
            NULL,
            (LPBYTE)(&data),
            &len
        );
        if (Ret == ERROR_SUCCESS)
        {
            RegCloseKey(hKey);
            (*readData) = data;
            return TRUE;
        }
        RegCloseKey(hKey);
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}
