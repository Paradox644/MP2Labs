#include "QueueForm.h"
#include <Windows.h> 

using namespace System;
using namespace System::Windows::Forms;


[STAThread]
void Main(array<String^>^ args)
{
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);

	QueueVisualInterface::QueueVisualInterface form;
	Application::Run(% form);
}