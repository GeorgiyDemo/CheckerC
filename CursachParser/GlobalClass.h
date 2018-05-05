#include <regex>
#include "tinyxml2.h"
#pragma once

namespace Globals
{
	using namespace System;
	using namespace tinyxml2;
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

		static void GetXML()
		{
			XMLDocument doc;
			doc.LoadFile("../dream.xml");

			// Structure of the XML file:
			// - Element "PLAY"      the root Element, which is the
			//                       FirstChildElement of the Document
			// - - Element "TITLE"   child of the root PLAY Element
			// - - - Text            child of the TITLE Element

			// Navigate to the title, using the convenience function,
			// with a dangerous lack of error checking.
			const char* title = doc.FirstChildElement("PLAY")->FirstChildElement("TITLE")->GetText();
		
			String^ clistr = gcnew String(title);
			MessageBox::Show("Name of play (1):"+ clistr +"\n");

			// Text is just another Node to TinyXML-2. The more
			// general way to get to the XMLText:
			XMLText* textNode = doc.FirstChildElement("PLAY")->FirstChildElement("TITLE")->FirstChild()->ToText();
			title = textNode->Value();
			String^ clistr1 = gcnew String(title);
			MessageBox::Show("Name of play (2): "+ clistr1 +"\n");
		}

	};
}