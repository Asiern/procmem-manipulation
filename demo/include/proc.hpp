#include <Windows.h>
#include <TlHelp32.h>

class ProcUtils
{
public:
    static DWORD GetProcId(const wchar_t *procName);
    static uintptr_t GetModuleBaseAddress(DWORD procId, const wchar_t *modName);
};