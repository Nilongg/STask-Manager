#pragma once
#include <windows.h>
#include <tlhelp32.h>
#include <tchar.h>
#include <psapi.h>
#include <iostream>
#include <Task.h>

class TaskHandler
{
	Task task;

	public:
		TaskHandler(Task t) {
			this->task = t;
		}
		void SuspendTask();
		void ResumeTask();
		void KillTask();
		void SetPriority(int priority);
};
