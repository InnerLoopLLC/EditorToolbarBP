// Copyright 2020 InnerLoop LLC. All Rights Reserved.

#include "EditorToolbarBPActor.h"

AEditorToolbarBPActor::AEditorToolbarBPActor(const FObjectInitializer& ObjectInitializer)
	: Super(ObjectInitializer)
{
	PrimaryActorTick.bCanEverTick = false;
}

void AEditorToolbarBPActor::BeginPlay()
{
	Super::BeginPlay();
}