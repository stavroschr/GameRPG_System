// Copyright Stavroschr


#include "UI/HUD/AuraHUD.h"
#include "UI/Widget/Aur  nbaUserWidget.h"

void AAuraHUD::BeginPlay()
{
	Super::BeginPlay();

UUserWidget* Widget = CreateWidget<UUserWidget>(GetWorld(),OverlayWidgetClass);

Widget->AddToViewport();
}
