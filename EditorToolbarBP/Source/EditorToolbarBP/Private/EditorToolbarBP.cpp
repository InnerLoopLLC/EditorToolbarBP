// Copyright Epic Games, Inc. All Rights Reserved.

#include "EditorToolbarBP.h"
#include "EditorToolbarBPStyle.h"
#include "EditorToolbarBPCommands.h"
#include "Misc/MessageDialog.h"
#include "ToolMenus.h"
#include "EditorToolbarBPActor.h"
#include "Engine/Selection.h"

DEFINE_LOG_CATEGORY(LogEditorToolbarBP);

static const FName EditorToolbarBPTabName("EditorToolbarBP");

#define LOCTEXT_NAMESPACE "FEditorToolbarBPModule"

void FEditorToolbarBPModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FEditorToolbarBPStyle::Initialize();
	FEditorToolbarBPStyle::ReloadTextures();

	FEditorToolbarBPCommands::Register();
	
	PluginCommands = MakeShareable(new FUICommandList);

	PluginCommands->MapAction(
		FEditorToolbarBPCommands::Get().ToolbarAction1,
		FExecuteAction::CreateRaw(this, &FEditorToolbarBPModule::ToolbarAction1),
		FCanExecuteAction());

	PluginCommands->MapAction(
		FEditorToolbarBPCommands::Get().ToolbarAction2,
		FExecuteAction::CreateRaw(this, &FEditorToolbarBPModule::ToolbarAction2),
		FCanExecuteAction());

	UToolMenus::RegisterStartupCallback(FSimpleMulticastDelegate::FDelegate::CreateRaw(this, &FEditorToolbarBPModule::RegisterMenus));
}

void FEditorToolbarBPModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	UToolMenus::UnRegisterStartupCallback(this);

	UToolMenus::UnregisterOwner(this);

	FEditorToolbarBPStyle::Shutdown();

	FEditorToolbarBPCommands::Unregister();
}

void FEditorToolbarBPModule::ToolbarAction1()
{
	for (TObjectIterator<AEditorToolbarBPActor> ActorItr; ActorItr; ++ActorItr)
	{
		ActorItr->ToolbarAction1();
	}
	UE_LOG(LogEditorToolbarBP, Log, TEXT("Executed event ToolbarAction1()."));
}

void FEditorToolbarBPModule::ToolbarAction2()
{
	for (TObjectIterator<AEditorToolbarBPActor> ActorItr; ActorItr; ++ActorItr)
	{
		ActorItr->ToolbarAction2();
	}
	UE_LOG(LogEditorToolbarBP, Log, TEXT("Executed event ToolbarAction2()."));
}

void FEditorToolbarBPModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FEditorToolbarBPCommands::Get().PluginAction, PluginCommands);
		}
	}

	{
		UToolMenu* ToolbarMenu = UToolMenus::Get()->ExtendMenu("LevelEditor.LevelEditorToolBar");
		{
			FToolMenuSection& Section = ToolbarMenu->FindOrAddSection("Settings");
			{
				FToolMenuEntry& Entry1 = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FEditorToolbarBPCommands::Get().ToolbarAction1));
				Entry1.SetCommandList(PluginCommands);
				FToolMenuEntry& Entry2 = Section.AddEntry(FToolMenuEntry::InitToolBarButton(FEditorToolbarBPCommands::Get().ToolbarAction2));
				Entry2.SetCommandList(PluginCommands);
			}
		}
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FEditorToolbarBPModule, EditorToolbarBP)