#include "Menu.h"



MainMenu::MainMenu()
{
}


MainMenu::~MainMenu()
{
}

void MainMenu::BeginDraw()
{
	menuOpened = ImGui::BeginMainMenuBar();
}

void MainMenu::InnerDraw()
{
	if (menuOpened)
	{
		if (ImGui::BeginMenu("TEST SUB"))
		{
			bool selected;
			ImGui::MenuItem("Test", "", nullptr);

			ImGui::EndMenu();
		}

		ImGui::MenuItem("Test2", "", nullptr);
	}
}

void MainMenu::EndDraw()
{
	if(menuOpened)
		ImGui::EndMainMenuBar();
}
