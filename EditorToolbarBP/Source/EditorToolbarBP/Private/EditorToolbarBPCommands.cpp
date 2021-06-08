// Copyright Epic Games, Inc. All Rights Reserved.

#include "EditorToolbarBPCommands.h"
#include "EditorToolbarBPActor.h"

#define LOCTEXT_NAMESPACE "FEditorToolbarBPModule"

void FEditorToolbarBPCommands::RegisterCommands()
{
	// Create each action
	UI_COMMAND(OpenActionList, "EditorToolbarBP", "Execute EditorToolbarBP action", EUserInterfaceActionType::Button, FInputGesture());
	CreateToolbarActions(10);
}

void FEditorToolbarBPCommands::CreateToolbarActions(uint8 NumberOfActions)
{	
	for (size_t i = 0; i < NumberOfActions; i++)
	{
		// Action numbers will be one greater than then array index.
		uint8 ActionID = i + 1;
		
		// Get action name and description from Editor.ini and use it to populate the button text
		// Build Key string
		FString ActionConfigPrefix = "Action_" + FString::FromInt(ActionID);
		FString ActionNameConfigKey = ActionConfigPrefix + "_Name";

		// Create stub reference to hold Value, and fill it from Editor.ini
		FString ActionName;
		GConfig->GetString(TEXT("/Script/EditorToolbarBP.EditorToolbarBPCommands"), *ActionNameConfigKey, ActionName, GEditorIni);
		
		// Build button text string
		FString ActionNamePrefix = "Toolbar Action " + FString::FromInt(ActionID);
		ActionName = ActionNamePrefix + "\r" + ActionName;
		
		// Get action description from Editor.ini
		FString ActionDescConfigKey = ActionConfigPrefix + TEXT("_Description");
		FString ActionDesc;
		GConfig->GetString(TEXT("/Script/EditorToolbarBP.EditorToolbarBPCommands"), *ActionDescConfigKey, ActionDesc, GEditorIni);

		// Make sure the ptr in the array is valid
		ToolbarAction.Add(ToolbarActionStub);

		// Create the command directly, instead of using the macro.
		FUICommandInfo::MakeCommandInfo(
			MakeShareable(new FBindingContext(GetContextName(), GetContextDesc(), GetContextParent(), GetStyleSetName())),
			ToolbarAction[i],
			*ActionName,
			FText::FromString(ActionName),
			FText::FromString(ActionDesc),
			FSlateIcon(GetStyleSetName(), ISlateStyle::Join(GetContextName(), ".ToolbarAction" + ActionID)),
			EUserInterfaceActionType::Button,
			FInputGesture()
		);
	}
}

void FEditorToolbarBPCommands::CreateToolBarAction1()
{
	// NO LONGER USED. KEPT AS A SIMPLE REMINDER HOW IT WORKS, FOR NOW
	
	// This gets action names from DefaultEditor.ini, but the command macro doesn't allow variable text. See below
	FString Action1Name;
	FString Action1Desc;
	GConfig->GetString(TEXT("/Script/EditorToolbarBP.EditorToolbarBPCommands"), TEXT("Action_1_Name"), Action1Name, GEditorIni);
	GConfig->GetString(TEXT("/Script/EditorToolbarBP.EditorToolbarBPCommands"), TEXT("Action_1_Description"), Action1Desc, GEditorIni);
	Action1Name = "Toolbar Action 1\r" + Action1Name;

	// This is really just for doing multiple commands at once
	uint8 ActionID = 1;

	// Make sure the ptr is valid
	ToolbarAction.Add(ToolbarActionStub);

	// Instead, we'll just create the command directly.
	FUICommandInfo::MakeCommandInfo(
		MakeShareable(new FBindingContext(GetContextName(), GetContextDesc(), GetContextParent(), GetStyleSetName())),
		ToolbarAction[0],
		*Action1Name,
		FText::FromString(Action1Name),
		FText::FromString(Action1Desc),
		FSlateIcon(GetStyleSetName(), ISlateStyle::Join(GetContextName(), ".ToolbarAction" + ActionID)),
		EUserInterfaceActionType::Button,
		FInputGesture()
	);
}

#undef LOCTEXT_NAMESPACE