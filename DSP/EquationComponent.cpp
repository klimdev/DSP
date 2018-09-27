#include "EquationComponent.h"

EquationComponent::EquationComponent()
{
	// add component to manager - manager draw all lines and handle connection directly
}


EquationComponent::~EquationComponent()
{
}

void EquationComponent::BeginDraw()
{
	Begin("Equeation");
}

void EquationComponent::InnerDraw()
{
	ImGui::Columns
	// window

	// from - button can connect n-component(specify on component)
	// to - button output base on button click - can have miltiple, may not have it
	// functionality - can change



	// handle drag and drop
		// if Drag
			// add to manager
		// if Drop
			// ask to manager
}

void EquationComponent::EndDraw()
{
	ImGui::End();
}
