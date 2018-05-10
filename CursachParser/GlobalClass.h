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
	using namespace System::Text;
	using namespace System::Drawing;
	using namespace cliext;

	public ref class GlobalClass
	{
	public:
		
		static array<String^> ^ SplitStringArray;

		static  DataTable^ GetXML(int your_price)
		{

			String^ RETURN_STR = "";

			DataTable ^table;
			DataColumn ^column;
			DataRow ^row;

			array<String^> ^ NameColumnsArray = { "Название заведения","Блюдо", "Цена", "Состав" };

			vector<String^>^ nameColumns = gcnew vector<String^>();
			
			table = gcnew DataTable();

			for (int i = 0; i < (NameColumnsArray->Length); i++) {
				nameColumns->push_back(NameColumnsArray[i]);
				column = gcnew DataColumn(nameColumns->at(i), String::typeid);
				table->Columns->Add(column);
			}


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

							content += ","+clistr2;
							MessageBox::Show(clistr2);

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

		static DataTable^ DataGridExample() {

			DataTable ^table;
			DataColumn ^column;
			DataRow ^row;

			array<String^> ^ NameColumnsArray = {"Название заведения","Блюдо", "Состав"};

			vector<String^>^ nameColumns = gcnew vector<String^>();
			table = gcnew DataTable();

			for (int i = 0; i < (NameColumnsArray->Length); i++) {
				nameColumns->push_back(NameColumnsArray[i]);
				column = gcnew DataColumn(nameColumns->at(i), String::typeid);
				table->Columns->Add(column);
			}

			////


			
			//table = gcnew DataTable();
			//nameColumns->push_back("Название");
			//column = gcnew DataColumn(nameColumns->at(0), String::typeid);
			//table->Columns->Add(column);

			row = table->NewRow();
			row[nameColumns->at(0)] = "TEST";
			table->Rows->Add(row);

			return table;
		}

	};
}