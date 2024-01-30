#include <Windows.h>
#include <TlHelp32.h>

class MemUtils
{
private:
    DWORD procId;
    HANDLE hProcess;

public:
    MemUtils(DWORD procId);
    ~MemUtils();

    // Memory read/write utilities
    template <typename T>
    T readMem(uintptr_t addr);
    template <typename T>
    void writeMem(uintptr_t addr, T val);
};

/**
 * @brief Read memory from a process
 *
 * @tparam T Value type (int, float, etc.)
 * @param addr Target address
 * @return T Value read from memory
 */
template <typename T>
T MemUtils::readMem(uintptr_t addr)
{
    T val;
    ReadProcessMemory(this->hProcess, (LPCVOID)addr, &val, sizeof(T), NULL);
    return val;
}

/**
 * @brief Write memory to a process
 *
 * @tparam T Value type (int, float, etc.)
 * @param addr Target address
 * @param val Value to write
 */
template <typename T>
void MemUtils::writeMem(uintptr_t addr, T val)
{
    WriteProcessMemory(this->hProcess, (LPVOID)addr, &val, sizeof(T), NULL);
}
