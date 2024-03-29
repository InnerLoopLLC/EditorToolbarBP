// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"
#include "Kismet/GameplayStatics.h"

DECLARE_LOG_CATEGORY_EXTERN(LogEditorToolbarBP, Log, All);

class FToolBarBuilder;
class FMenuBuilder;
class SWidget;

class FEditorToolbarBPModule : public IModuleInterface
{
public:

	// IModuleInterface implementation 
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	
	// These functions will be bound to Commands.
		void ToolbarAction(uint8 ActionNumber);
		void ToolbarAction1();
		void ToolbarAction2();
		void ToolbarAction3();
		void ToolbarAction4();
		void ToolbarAction5();
		void ToolbarAction6();
		void ToolbarAction7();
		void ToolbarAction8();
		void ToolbarAction9();
		void ToolbarAction10();
	
private:

	void CreateCommandList();
	void RegisterMenus();

	TSharedPtr<class FUICommandList> PluginCommands;
};