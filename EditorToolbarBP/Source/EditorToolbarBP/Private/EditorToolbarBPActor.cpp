// Copyright 2020 InnerLoop LLC. All Rights Reserved.

#include "EditorToolbarBPActor.h"

AEditorToolbarBPActor::AEditorToolbarBPActor(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = false;
	bIsEditorOnlyActor = 1;
	
}