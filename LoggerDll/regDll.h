#pragma once
#include "pch.h"

BOOL CreateRegistryKey(HKEY hKeyParent, LPCSTR subkey);
BOOL WriteDwordInRegistry(HKEY hKeyParent, LPCSTR subkey, LPCSTR valueName, DWORD data);
BOOL readDwordValueRegistry(HKEY hKeyParent, LPCSTR subkey, LPCSTR valueName, DWORD* readData);