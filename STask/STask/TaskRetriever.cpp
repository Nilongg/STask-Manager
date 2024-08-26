#include <wx/wx.h>
#include "app.h"
#include "MainFrame.h"
#include "TaskHandler.h"
#include "Task.h"

class TaskRetriever {

    public:
        std::vector<Task> tasks;
        TaskRetriever() {
            Start();
        }

    int Start() {
        // Get the list of process identifiers.
        DWORD aProcesses[1024], cbNeeded, cProcesses;

        if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded)) {
            return 1;
        }

        // Calculate how many process identifiers were returned.
        cProcesses = cbNeeded / sizeof(DWORD);

        // Store the name and process ID of each process.
        for (DWORD i = 0; i < cProcesses; i++) {
            if (aProcesses[i] != 0) {
                StoreNameAndID(aProcesses[i]);
            }
        }
        return 0;
    }

    void StoreNameAndID(DWORD processID) {
        TCHAR szProcessName[MAX_PATH] = TEXT("<unknown>");

        // Get a handle to the process.
        HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processID);

        // Get the process name.
        if (hProcess) {
            HMODULE hMod;
            DWORD cbNeeded;

            if (EnumProcessModules(hProcess, &hMod, sizeof(hMod), &cbNeeded)) {
                GetModuleBaseName(hProcess, hMod, szProcessName, sizeof(szProcessName) / sizeof(TCHAR));
            }
            CloseHandle(hProcess);  // Ensure the handle is closed inside the `if` block
        }

        // Convert TCHAR to wstring and create a Task object
        tasks.emplace_back(processID, TCHARToWString(szProcessName), 0);
    }

    std::wstring TCHARToWString(const TCHAR* tchar) {
        return std::wstring(tchar);
    }
};


