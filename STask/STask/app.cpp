#include <wx/wx.h>
#include "app.h"
#include "MainFrame.h"
#include "TaskHandler.h"
#include "task.h"
#include "TaskInfo.h"

wxIMPLEMENT_APP(app);

std::string iniatialize();

void StoreNameAndID(DWORD processID);

void Start();

bool app::OnInit()
{
    Start();

    MainFrame* frame = new MainFrame(iniatialize());
    frame->SetSize(800, 600);
    frame->Center();
    frame->Show(true);
    wxInfoMessageBox(frame);


}
std::string iniatialize()
{
	TaskInfo taskInfo;
	taskInfo.name = "STasker";
	return taskInfo.name;
}


void Start() {
    // Get the list of process identifiers.
    DWORD aProcesses[1024], cbNeeded, cProcesses;

    if (!EnumProcesses(aProcesses, sizeof(aProcesses), &cbNeeded))
    {
        return 1;
    }

    // Calculate how many process identifiers were returned.
    cProcesses = cbNeeded / sizeof(DWORD);

    // Print the name and process identifier for each process.
    for (unsigned int i = 0; i < cProcesses; i++)
    {
        if (aProcesses[i] != 0)
        {
            StoreNameAndID(aProcesses[i]);
        }
    }
    return;
}

void StoreNameAndID(DWORD processID)
{
    TCHAR szProcessName[MAX_PATH] = TEXT("<unknown>");

    // Get a handle to the process.
    HANDLE hProcess = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, FALSE, processID);

    // Get the process name.
    if (NULL != hProcess)
    {
        HMODULE hMod;
        DWORD cbNeeded;

        if (EnumProcessModules(hProcess, &hMod, sizeof(hMod), &cbNeeded))
        {
            GetModuleBaseName(hProcess, hMod, szProcessName, sizeof(szProcessName) / sizeof(TCHAR));
        }
    }

	//Store the id and the name of the process to a list type of "TaskInfo" (struct)
	


    // Release the handle to the process.
    CloseHandle(hProcess);
}



