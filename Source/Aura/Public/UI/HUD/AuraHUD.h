// Copyright Stavroschr

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/HUD.h"
#include "UI/Widget/AuraUserWidget.h"
#include "AuraHUD.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraHUD : public AHUD
{
	GENERATED_BODY()


public:

	TObjectPtr<UAuraUserWidget> OverlayWidget;

protected:

	virtual void BeginPlay() override;

private:

	UPROPERTY(EditAnywhere)
	TSubclassOf<UAuraUserWidget> OverlayWidgetClass;
};
