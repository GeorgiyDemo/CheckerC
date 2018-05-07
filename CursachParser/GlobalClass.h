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

		

		static String^ GetXML()
		{
			XMLDocument doc;
			doc.LoadFile("../main.xml");
			//doc.NewDeclaration("UTF-8");

			XMLElement* textNode = doc.FirstChildElement("restaurants")->FirstChildElement("place");

			for (XMLElement* e = textNode->FirstChildElement("menu"); e != NULL; e = e->NextSiblingElement("menu"))
			{

				const char* title = e->FirstChildElement("price")->GetText();
				String^ clistr1 = gcnew String(title);
				MessageBox::Show(clistr1);

			}

			return "LOL";
			/*
			for (XMLElement* e = textNode->FirstChildElement("menu"); e != NULL; e = e->NextSiblingElement("menu"))
			{
				const char* title = e->Value();
				String^ clistr = gcnew String(title);
				MessageBox::Show(clistr);



			}
			*/
		}

	};
}