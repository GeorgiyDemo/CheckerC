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
				
				XMLElement* maintitle = place;

				const char* Charmainttitle = maintitle->GetText();
				String^ Stringmainttitle = gcnew String(Charmainttitle);
				MessageBox::Show(Stringmainttitle);

				for (XMLElement* menu = place->FirstChildElement("menu"); menu != NULL; menu = menu->NextSiblingElement("menu")) {
					const char* title = menu->FirstChildElement("price")->GetText();
					String^ clistr = gcnew String(title);
					if (System::Convert::ToInt32(clistr) <= your_price) {
				
						XMLElement* FoodContent = menu;

						const char* FoodContenttitle = FoodContent->GetText();
						String^ clistr1 = gcnew String(FoodContenttitle);

						String^ content = "";
						bool FlagChecker = false;
						for (XMLElement* FoodContent = menu->FirstChildElement("content"); FoodContent != NULL; FoodContent = FoodContent->NextSiblingElement("content")) {
							const char* FoodContenttitle1 = FoodContent->GetText();
							String^ clistr2 = gcnew String(FoodContenttitle1);

							for each(String^ ArrString in SplitStringArray)
								if (ArrString == clistr2) {
									FlagChecker = true;
									MessageBox::Show(ArrString);
								}

							content += "\nï "+clistr2;
							MessageBox::Show(clistr2);

						}
						if (FlagChecker == true)
						RETURN_STR += "\n"+ Stringmainttitle +": "+ clistr1 + "÷ÂÌ‡: " + clistr +" "+ content + "\n";

					}

						
				}

			}
			
			MessageBox::Show(RETURN_STR);
			return RETURN_STR;
		
		}

	};
}