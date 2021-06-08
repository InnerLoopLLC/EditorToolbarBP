// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Framework/Commands/Commands.h"
#include "EditorToolbarBPStyle.h"
//#include "EditorToolbarBPStyle.generated.h"

class FEditorToolbarBPCommands : public TCommands<FEditorToolbarBPCommands>
{

public:

	FEditorToolbarBPCommands()
		: TCommands<FEditorToolbarBPCommands>(TEXT("EditorToolbarBP"), NSLOCTEXT("Contexts", "EditorToolbarBP", "EditorToolbarBP Plugin"), NAME_None, FEditorToolbarBPStyle::GetStyleSetName())
	{
	}

	// TCommands<> interface
	virtual void RegisterCommands() override;

	TSharedPtr< FUICommandInfo > OpenActionList;
	TSharedPtr< FUICommandInfo > ToolbarActionStub;
	TArray< TSharedPtr< FUICommandInfo > > ToolbarAction;

private:

	void CreateToolbarActions(uint8 NumberOfActions);
	void CreateToolBarAction1();	
};