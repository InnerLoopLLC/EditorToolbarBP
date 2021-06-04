// Copyright Epic Games, Inc. All Rights Reserved.

#include "EditorToolbarBPCommands.h"

#define LOCTEXT_NAMESPACE "FEditorToolbarBPModule"

void FEditorToolbarBPCommands::RegisterCommands()
{
	/* 
	// This gets action names from DefaultEditor.ini, but the command macro doesn't allow variable text. See workaround below
	FString Action1Name;
	FString Action1Desc;
	GConfig->GetString(TEXT("/Script/EditorToolbarBP"), TEXT("Action_1_Name"), Action1Name, GEditorIni);
	GConfig->GetString(TEXT("/Script/EditorToolbarBP"), TEXT("Action_1_Description"), Action1Desc, GEditorIni);
	*/

	UI_COMMAND(OpenActionList, "EditorToolbarBP", "Execute EditorToolbarBP action", EUserInterfaceActionType::Button, FInputGesture());
	UI_COMMAND(ToolbarAction1, "Toolbar Action 1", "Toolbar Action 1", EUserInterfaceActionType::Button, FInputGesture());
	UI_COMMAND(ToolbarAction2, "Toolbar Action 2", "Toolbar Action 2", EUserInterfaceActionType::Button, FInputGesture());

	/*
	// This creates a new command to replace ToolbarAction1, but with a new name. It's broked though
	FUICommandInfo::MakeCommandInfo(
		//TSharedRef<FEditorToolbarBPCommands>(this),
		//MakeShareable( new FUICommandInfo( InContext->GetContextName() ) );
		MakeShareable(new FBindingContext("", FText::FromString(Action1Name),"","")),
		//this->AsShared(),
		ToolbarAction1,
		//*Action1Name,
		"Toolbar Action 1",
		FText::FromString(Action1Name),
		FText::FromString(Action1Desc),
		ToolbarAction1->GetIcon(),
		EUserInterfaceActionType::Button,
		FInputGesture()
	);
	*/
}

#undef LOCTEXT_NAMESPACE