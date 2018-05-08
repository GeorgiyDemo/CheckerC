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
			String^ RETURN_STR = "";
			for each(String^ temp in SplitStringArray)
				MessageBox::Show(temp);
			
			XMLDocument doc;
			doc.LoadFile("../main.xml");
			XMLElement* MainNode = doc.FirstChildElement("restaurants");

			for (XMLElement* place = MainNode->FirstChildElement("place"); place != NULL; place = place->NextSiblingElement("place")) {
				for (XMLElement* menu = place->FirstChildElement("menu"); menu != NULL; menu = menu->NextSiblingElement("menu")) {
					const char* title = menu->FirstChildElement("price")->GetText();
					String^ clistr = gcnew String(title);
					if (System::Convert::ToInt32(clistr) <= your_price) {
						//MessageBox::Show("��� ���� ����!" + clistr);
						XMLElement* FoodContent = menu;
						for (XMLElement* FoodContent = menu; FoodContent != NULL; FoodContent = FoodContent->NextSiblingElement("content")) {
							const char* FoodContenttitle = FoodContent->GetText();
							String^ clistr1 = gcnew String(FoodContenttitle);
							RETURN_STR += "\n" + clistr1 + "����: " + clistr + "\n";
							//MessageBox::Show(clistr1);
						}

					}

						
				}

			}
			MessageBox::Show(RETURN_STR);
			return RETURN_STR;
		
		}

	};
}