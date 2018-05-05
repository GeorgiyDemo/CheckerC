#include <regex>
#pragma once

namespace Globals
{
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Text;
	using namespace System::Drawing;

	public ref class GlobalClass
	{
	public:
		
		static String^ XMLFileGlobalPatch;

		static String^ GetXML()
		{
			MessageBox::Show(XMLFileGlobalPatch);
			return "OK";
		}

	};
}