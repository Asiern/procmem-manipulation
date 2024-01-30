#include "mem.hpp"
#include "proc.hpp"
#include <iostream>

int main(int argc, char const *argv[])
{
    DWORD pid = ProcUtils::GetProcId(L"Task Manager");
    std::cout << "PID: " << pid << std::endl;
    return 0;
}
