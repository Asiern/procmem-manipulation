#include "mem.hpp"

/**
 * @brief Construct a new Mem Utils:: Mem Utils object
 *
 * @param procId Target process id
 */
MemUtils::MemUtils(DWORD procId)
{
    // Save the process id
    this->procId = procId;
    // Get a handle to the process
    this->hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, procId);
}

/**
 * @brief Destroy the Mem Utils:: Mem Utils object
 *
 */
MemUtils::~MemUtils()
{
    // Close the process handle
    CloseHandle(this->hProcess);
}

/**
 * @brief Patch an instruction in the target process modifying the write protection of the memory region
 *
 * @param addr Target address
 * @param instruction New instruction
 * @param size Size of the new instruction
 */
void MemUtils::patch(uintptr_t addr, BYTE *instruction, size_t size)
{
    DWORD oldProtect;
    // Change the protection of the memory region to allow writing
    VirtualProtectEx(this->hProcess, (LPVOID)addr, size, PAGE_EXECUTE_READWRITE, &oldProtect);
    // Write the new instruction
    WriteProcessMemory(this->hProcess, (LPVOID)addr, instruction, size, NULL);
    // Restore the original protection
    VirtualProtectEx(this->hProcess, (LPVOID)addr, size, oldProtect, &oldProtect);
}