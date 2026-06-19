#include "pch.h"
#include "MyForm.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main()
{
//HOLA CABRO
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew TrabajoFinalv1::MyForm());
    
}
