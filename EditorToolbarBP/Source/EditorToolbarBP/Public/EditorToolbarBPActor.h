// Copyright 2020 InnerLoop LLC. All Rights Reserved.

#pragma once

#include "EditorToolbarBP.h"
#include "EditorToolbarBPActor.generated.h"

UCLASS()
class EDITORTOOLBARBP_API AEditorToolbarBPActor : public AActor
{

	GENERATED_UCLASS_BODY()

public:

	virtual void BeginPlay() override;
		
	UFUNCTION(BlueprintImplementableEvent, CallInEditor, Category = "EditorToolbarBP", Meta = (DisplayName = "Toolbar Action 1"))
		void ToolbarAction1();

	UFUNCTION(BlueprintImplementableEvent, CallInEditor, Category = "EditorToolbarBP")
		void ToolbarAction2();
};