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
		static array<String^> ^ SplitStringArray;
		

		static String^ GetXML(int your_price)
		{
			for each(String^ temp in SplitStringArray)
				MessageBox::Show(temp);
			
			XMLDocument doc;
			doc.LoadFile("../main.xml");
			//doc.NewDeclaration("UTF-8");
			XMLElement* MainNode = doc.FirstChildElement("restaurants");

			for (XMLElement* place = MainNode->FirstChildElement("place"); place != NULL; place = place->NextSiblingElement("place")) {
				for (XMLElement* menu = place->FirstChildElement("menu"); menu != NULL; menu = menu->NextSiblingElement("menu")) {
					const char* title = menu->FirstChildElement("price")->GetText();
					String^ clistr = gcnew String(title);
					if (System::Convert::ToInt32(clistr) <= your_price)
						MessageBox::Show("Âîò öåíà íîðì!\n"+clistr);
						//ÒÓÒ ÏÅÐÅÁÎÐ ÝËÅÌÅÍÒÎÂ ÌÀÑÑÈÂÀ
				}

			}
			

			/*
			XMLElement* textNode = doc.FirstChildElement("restaurants")->FirstChildElement("place");

			for (XMLElement* e = textNode->FirstChildElement("menu"); e != NULL; e = e->NextSiblingElement("menu"))
			{

				const char* title = e->FirstChildElement("price")->GetText();
				String^ clistr1 = gcnew String(title);
				MessageBox::Show(clistr1);

			}
			*/
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