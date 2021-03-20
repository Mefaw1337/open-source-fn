#pragma once

#define _ C

namespace GUI
{
	void DoAction()
	{
		ImGui::Begin(_("Fortnite Open-Source [Mefaw#1511]"));
		
		ImGui::Checkbox(_("Aimbot enable"), &Settings->Aim_Enable);
		if (&Settings->Aim_Enable) ImGui::SliderFloat(_("Aimbot FOV"), &Settings->Aim_FoV, 1.f, 1000.f, "%.0f");

		ImGui::Separator();

		ImGui::Checkbox(_("Player esp enable"), &Settings->ESP_Enable);
		ImGui::Checkbox(_("Player 2D box esp enable"), &Settings->ESP_2DBox);
		ImGui::Checkbox(_("Player distance esp enable"), &Settings->ESP_DistanceESP);

		ImGui::End();
	}
}