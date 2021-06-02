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

	/** IModuleInterface implementation */
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
	
	/** This function will be bound to Command. */
		void ToolbarAction1();
		void ToolbarAction2();
	
private:

	void RegisterMenus();

	TSharedPtr<class FUICommandList> PluginCommands;
};
