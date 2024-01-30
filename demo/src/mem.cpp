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
