// Copyright Epic Games, Inc. All Rights Reserved.

#include "EditorToolbarBP.h"
#include "EditorToolbarBPStyle.h"
#include "EditorToolbarBPCommands.h"
#include "Misc/MessageDialog.h"
#include "ToolMenus.h"
#include "EditorToolbarBPActor.h"
#include "Engine/Selection.h"
#include "Kismet2/KismetEditorUtilities.h"

DEFINE_LOG_CATEGORY(LogEditorToolbarBP);

static const FName EditorToolbarBPTabName("EditorToolbarBP");

#define LOCTEXT_NAMESPACE "FEditorToolbarBPModule"

void FEditorToolbarBPModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module
	
	FEditorToolbarBPStyle::Initialize();
	FEditorToolbarBPStyle::ReloadTextures();

	// Register menu commands
	FEditorToolbarBPCommands::Register();

	// Make events visible in the actor by default, but disabled until used.
	FKismetEditorUtilities::RegisterAutoGeneratedDefaultEvent(this, AEditorToolbarBPActor::StaticClass(), GET_FUNCTION_NAME_CHECKED(AEditorToolbarBPActor, ToolbarAction1));
	FKismetEditorUtilities::RegisterAutoGeneratedDefaultEvent(this, AEditorToolbarBPActor::StaticClass(), GET_FUNCTION_NAME_CHECKED(AEditorToolbarBPActor, ToolbarAction2));
	FKismetEditorUtilities::RegisterAutoGeneratedDefaultEvent(this, AEditorToolbarBPActor::StaticClass(), GET_FUNCTION_NAME_CHECKED(AEditorToolbarBPActor, ToolbarAction3));
	FKismetEditorUtilities::RegisterAutoGeneratedDefaultEvent(this, AEditorToolbarBPActor::StaticClass(), GET_FUNCTION_NAME_CHECKED(AEditorToolbarBPActor, ToolbarAction4));
	FKismetEditorUtilities::RegisterAutoGeneratedDefaultEvent(this, AEditorToolbarBPActor::StaticClass(), GET_FUNCTION_NAME_CHECKED(AEditorToolbarBPActor, ToolbarAction5));
	FKismetEditorUtilities::RegisterAutoGeneratedDefaultEvent(this, AEditorToolbarBPActor::StaticClass(), GET_FUNCTION_NAME_CHECKED(AEditorToolbarBPActor, ToolbarAction6));
	FKismetEditorUtilities::RegisterAutoGeneratedDefaultEvent(this, AEditorToolbarBPActor::StaticClass(), GET_FUNCTION_NAME_CHECKED(AEditorToolbarBPActor, ToolbarAction7));
	FKismetEditorUtilities::RegisterAutoGeneratedDefaultEvent(this, AEditorToolbarBPActor::StaticClass(), GET_FUNCTION_NAME_CHECKED(AEditorToolbarBPActor, ToolbarAction8));
	FKismetEditorUtilities::RegisterAutoGeneratedDefaultEvent(this, AEditorToolbarBPActor::StaticClass(), GET_FUNCTION_NAME_CHECKED(AEditorToolbarBPActor, ToolbarAction9));
	FKismetEditorUtilities::RegisterAutoGeneratedDefaultEvent(this, AEditorToolbarBPActor::StaticClass(), GET_FUNCTION_NAME_CHECKED(AEditorToolbarBPActor, ToolbarAction10));
	
	PluginCommands = MakeShareable(new FUICommandList);

	// Map actions
	PluginCommands->MapAction(
		FEditorToolbarBPCommands::Get().ToolbarAction1,
		FExecuteAction::CreateRaw(this, &FEditorToolbarBPModule::ToolbarAction1),
		FCanExecuteAction());

	PluginCommands->MapAction(
		FEditorToolbarBPCommands::Get().ToolbarAction2,
		FExecuteAction::CreateRaw(this, &FEditorToolbarBPModule::ToolbarAction2),
		FCanExecuteAction());

	// Register Menus
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
	// Get all uobjects, either in the level or if a blueprint editor is open.
	for (TObjectIterator<AEditorToolbarBPActor> ActorItr; ActorItr; ++ActorItr)
	{
		/*
		// Gets the world. Compare it to the actor.
		GEditor->GetEditorWorldContext();
		GEditor->GetPIEWorldContext();

		// Returns true if blueprint graph is currently open for this class
		FKismetEditorUtilities::GetIBlueprintEditorForObject(ActorItr->GetClass(), false)
		*/

		// Only consider objects if the actor is placed in the editor world. If not, then ignore it. 
		// Objects open in a blueprint editor will be ignored.
		if(ActorItr->GetWorld() == GEditor->GetEditorWorldContext().World())
		{
			ActorItr->ToolbarAction1();
			UE_LOG(LogEditorToolbarBP, Log, TEXT("Executed event Toolbar Action 1."));
		}
	}
}

void FEditorToolbarBPModule::ToolbarAction2()
{
	// Get all uobjects, either in the level or if a blueprint editor is open.
	for (TObjectIterator<AEditorToolbarBPActor> ActorItr; ActorItr; ++ActorItr)
	{
		// Only consider objects if the actor is placed in the editor world. If not, then ignore it. 
		// Objects open in a blueprint editor will be ignored.
		if (ActorItr->GetWorld() == GEditor->GetEditorWorldContext().World())
		{
			ActorItr->ToolbarAction2();
			UE_LOG(LogEditorToolbarBP, Log, TEXT("Executed event Toolbar Action 2."));
		}
	}
}

void FEditorToolbarBPModule::RegisterMenus()
{
	// Owner will be used for cleanup in call to UToolMenus::UnregisterOwner
	FToolMenuOwnerScoped OwnerScoped(this);

	/*
	// This section doesn't seem necessary at the moment. Will worry about it more in the next update, while focusing on appearance
	{
		UToolMenu* Menu = UToolMenus::Get()->ExtendMenu("LevelEditor.MainMenu.Window");
		{
			FToolMenuSection& Section = Menu->FindOrAddSection("WindowLayout");
			Section.AddMenuEntryWithCommandList(FEditorToolbarBPCommands::Get().OpenActionList, PluginCommands);
		}
	}
	*/

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