#include "proc.hpp"
#include <iostream>

/**
 * @brief Get the process id of a process by name
 *
 * @param procName Process name (WCHAR)
 * @return DWORD Process id
 */
DWORD ProcUtils::GetProcId(const wchar_t *procName)
{
    // Search for the process window,
    // if found, get a handle to the process
    HWND hwnd = FindWindowW(NULL, procName);
    if (hwnd == NULL)
    {
        // Window not found
        std::cout << "Error: Process not found" << std::endl;
        return 0;
    }

    // Window found, get the process id
    DWORD pid;
    GetWindowThreadProcessId(hwnd, &pid);
    return pid;
}

/**
 * @brief Get the base address of a module in a process
 *
 * @param procId Process id
 * @param modName Module name (WCHAR)
 * @return uintptr_t Module base address, 0 if not found
 */
uintptr_t ProcUtils::GetModuleBaseAddress(DWORD procId, const wchar_t *modName)
{
    uintptr_t modBaseAddr = 0;

    // Create a snapshot of the process
    HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, procId);
    if (hSnap != INVALID_HANDLE_VALUE)
    {
        MODULEENTRY32W modEntry; // Module entry
        modEntry.dwSize = sizeof(modEntry);
        if (Module32FirstW(hSnap, &modEntry))
        {
            do
            {
                // Compare module name with the one we're looking for
                if (!_wcsicmp(modEntry.szModule, modName))
                {
                    // Module found, get the base address
                    modBaseAddr = (uintptr_t)modEntry.modBaseAddr;
                    break;
                }
            } while (Module32NextW(hSnap, &modEntry));
        }
    }

    CloseHandle(hSnap); // Close the snapshot handle to avoid memory leaks
    return modBaseAddr;
}

void ProcUtils::EnumModules(DWORD procId)
{
    // Create a snapshot of the process
    HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, procId);
    if (hSnap != INVALID_HANDLE_VALUE)
    {
        MODULEENTRY32W modEntry; // Module entry
        modEntry.dwSize = sizeof(modEntry);
        if (Module32FirstW(hSnap, &modEntry))
        {
            do
            {
                std::wcout << modEntry.szModule << std::endl;
            } while (Module32NextW(hSnap, &modEntry));
        }
    }

    CloseHandle(hSnap); // Close the snapshot handle to avoid memory leaks
}
