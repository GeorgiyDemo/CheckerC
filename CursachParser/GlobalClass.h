#include <cliext/vector>
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
	using namespace System::Drawing;
	using namespace cliext;

	public ref class GlobalClass
	{
	public:
		
		static array<String^> ^ SplitStringArray;

		static String^ UTF8Converter(const char* InputChar) {
			std::string s = InputChar;
			char const* buffer = s.c_str();
	
			cli::array<System::Byte>^ a = gcnew cli::array<System::Byte>(s.length());
			int i = s.length();
			while (i-- != 0) 
				a[i] = buffer[i];

			String^ meow = System::Text::Encoding::UTF8->GetString(a);
			return  meow;
		}


		static  DataTable^ GetXML(int your_price)
		{

			String^ RETURN_STR = "";

			DataTable ^table;
			DataColumn ^column;
			DataRow ^row;

			array<String^> ^ NameColumnsArray = { "Название заведения","Блюдо", "Цена (руб.)", "Ингредиенты" };
			vector<String^>^ nameColumns = gcnew vector<String^>();
			
			table = gcnew DataTable();

			for (int i = 0; i < (NameColumnsArray->Length); i++) {
				nameColumns->push_back(NameColumnsArray[i]);
				column = gcnew DataColumn(nameColumns->at(i), String::typeid);
				table->Columns->Add(column);
			}
			
			XMLDocument doc;
			doc.LoadFile("../main.xml");
			XMLElement* MainNode = doc.FirstChildElement("restaurants");

			for (XMLElement* place = MainNode->FirstChildElement("place"); place != NULL; place = place->NextSiblingElement("place")) {
				
				XMLElement* maintitle = place;
				const char* Charmainttitle = maintitle->GetText();
	
				String^ Stringmainttitle = UTF8Converter(Charmainttitle);

				for (XMLElement* menu = place->FirstChildElement("menu"); menu != NULL; menu = menu->NextSiblingElement("menu")) {
					const char* title = menu->FirstChildElement("price")->GetText();
					String^ clistr = UTF8Converter(title);
					if (System::Convert::ToInt32(clistr) <= your_price) {
				
						XMLElement* FoodContent = menu;

						const char* FoodContenttitle = FoodContent->GetText();

						String^ clistr1 = UTF8Converter(FoodContenttitle);

						String^ content = "";
						bool FlagChecker = false;
						int IntFlagIteration = 0;
						for (XMLElement* FoodContent = menu->FirstChildElement("content"); FoodContent != NULL; FoodContent = FoodContent->NextSiblingElement("content")) {
							const char* FoodContenttitle1 = FoodContent->GetText();
							String^ clistr2 = UTF8Converter(FoodContenttitle1);

							for each(String^ ArrString in SplitStringArray)
								if (ArrString == clistr2)
									FlagChecker = true;
							
							content += (IntFlagIteration != 0) ? ", " + clistr2 : clistr2;
							//content += ","+clistr2;
							IntFlagIteration++;
						}
						if (FlagChecker == true) {
							row = table->NewRow();
							row[nameColumns->at(0)] = Stringmainttitle;
							row[nameColumns->at(1)] = clistr1;
							row[nameColumns->at(2)] = clistr;
							row[nameColumns->at(3)] = content;
							table->Rows->Add(row);
						}
						

					}

						
				}

			}
			
			return table;
		
		}

	};
}