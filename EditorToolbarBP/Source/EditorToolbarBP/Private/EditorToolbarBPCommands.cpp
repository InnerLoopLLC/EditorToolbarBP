// Copyright Epic Games, Inc. All Rights Reserved.

#include "EditorToolbarBPCommands.h"

#define LOCTEXT_NAMESPACE "FEditorToolbarBPModule"

void FEditorToolbarBPCommands::RegisterCommands()
{
	UI_COMMAND(PluginAction, "EditorToolbarBP", "Execute EditorToolbarBP action", EUserInterfaceActionType::Button, FInputGesture());
	UI_COMMAND(ToolbarAction1, "Toolbar Action 1", "Toolbar Action 1", EUserInterfaceActionType::Button, FInputGesture());
	UI_COMMAND(ToolbarAction2, "Toolbar Action 2", "Toolbar Action 2", EUserInterfaceActionType::Button, FInputGesture());
}

#undef LOCTEXT_NAMESPACE
