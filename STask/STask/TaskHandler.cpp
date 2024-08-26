#include "TaskHandler.h"

void TaskHandler::KillTask()
{
	// Kills the current task that the constructor was given
	// This is done by getting the task's process ID and then killing it

	HANDLE hProcess = OpenProcess(PROCESS_TERMINATE, FALSE, task.GetID());
	if (hProcess == NULL)
	{
		std::cout << "Could not open process" << std::endl;
		return;
	}
	if (TerminateProcess(hProcess, 0) == 0)
	{
		std::cout << "Could not terminate process" << std::endl;
	}
	CloseHandle(hProcess);
	
}
void TaskHandler::SetPriority(int priority)
{
	//Checks if the priority is valid
	if (priority < 0 || priority > 5)
	{
		std::cout << "Invalid priority" << std::endl;
		return;
	}
	
	//Sets the priority of the task to the given priority
	//These are custom not standard windows priorities

	HANDLE hProcess = OpenProcess(PROCESS_SET_INFORMATION, FALSE, task.GetID());
	if (hProcess == NULL)
	{
		std::cout << "Could not open process" << std::endl;
		return;
	}
	if (SetPriorityClass(hProcess, priority) == 0)
	{
		std::cout << "Could not set priority" << std::endl;
	}
	CloseHandle(hProcess);
}
void TaskHandler::ResumeTask()
{
	//TODO 
	//Resumes the suspended task
}
void TaskHandler::SuspendTask()
{
	//TODO
	//Suspends the task
}

