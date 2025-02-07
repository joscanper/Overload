/**
* @project: Overload
* @author: Overload Tech.
* @licence: MIT
*/

#include "OvUI/Widgets/Layout/GroupCollapsable.h"
#include "OvUI/ImGui/imgui_internal.h"

OvUI::Widgets::Layout::GroupCollapsable::GroupCollapsable(const std::string & p_name) :
	name(p_name)
{
}

void OvUI::Widgets::Layout::GroupCollapsable::_Draw_Impl()
{
	bool previouslyOpened = opened;

	ImGui::SetNextItemOpen(!collapsed);

	if (ImGui::CollapsingHeader(name.c_str(), closable ? &opened : nullptr))
		Group::_Draw_Impl();

	collapsed = !ImGui::TreeNodeBehaviorIsOpen(ImGui::GetID(name.c_str()), ImGuiTreeNodeFlags_None);

	if (opened != previouslyOpened)
	{
		if (opened)
			OpenEvent.Invoke();
		else
			CloseEvent.Invoke();
	}
}
