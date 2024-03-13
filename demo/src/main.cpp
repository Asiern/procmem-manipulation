#include "mem.hpp"
#include "proc.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
    MemUtils *mem;

    // ------------------------------------------------
    // --- Process Info
    // ------------------------------------------------

    // Get Process ID
    DWORD pid = ProcUtils::GetProcId(L"Playground");
    std::cout << "PID: " << pid << std::endl;

    // Enumerate Modules
    ProcUtils::EnumModules(pid);

    // Get Process Module Base Address (Playground.exe)
    uintptr_t moduleBase = ProcUtils::GetModuleBaseAddress(pid, L"Playground.exe");
    std::cout << "Module Base Address: " << std::hex << moduleBase << std::endl;

    // ------------------------------------------------
    // --- Simple Memory Read/Write
    // ------------------------------------------------

    // Initialize Memory Class
    mem = new MemUtils(pid);

    // Define target address (Counter in Playground.exe)
    // Address: Playground.exe+16E3B0
    uintptr_t addr = moduleBase + 0x16E3B0;

    // Read Memory
    int counterValue = mem->readMem<int>(addr);
    std::cout << "Counter Value: " << std::dec << counterValue << std::endl;

    // Write Memory
    int newValue = 100;
    mem->writeMem<int>(addr, newValue);

    // ------------------------------------------------
    // --- Instruction Modification
    // --- Documentation: https://en.wikipedia.org/wiki/X86_instruction_listings
    // ------------------------------------------------

    // Define target address (Increment button in Playground.exe)
    // Instruction: inc eax (FF C0)
    uintptr_t incAddr = 0x0;

    // Disable increment button
    mem->patch(incAddr, (BYTE *)"\x90\x90", 2); // replace inc eax with nop nop

    return 0;
}
