#include <wx/wx.h>
#include "app.h"
#include "MainFrame.h"
#include "TaskHandler.h"
#include "task.h"
#include "TaskInfo.h"

wxIMPLEMENT_APP(app);

std::string iniatialize();

bool app::OnInit()
{
	
	MainFrame* frame = new MainFrame(iniatialize());
	frame->SetSize(800, 600);
	frame->Center();
	frame->Show(true);
	return true;
}

std::string iniatialize()
{
	TaskInfo taskInfo;
	taskInfo.name = "STasker";
	return taskInfo.name;
}

