// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "EditorToolbarBPStyle.h"

class FEditorToolbarBPCommands : public TCommands<FEditorToolbarBPCommands>
{
public:

	FEditorToolbarBPCommands()
		: TCommands<FEditorToolbarBPCommands>(TEXT("EditorToolbarBP"), NSLOCTEXT("Contexts", "EditorToolbarBP", "EditorToolbarBP Plugin"), NAME_None, FEditorToolbarBPStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

public:
	TSharedPtr< FUICommandInfo > PluginAction;
	TSharedPtr< FUICommandInfo > ToolbarAction1;
	TSharedPtr< FUICommandInfo > ToolbarAction2;
};
