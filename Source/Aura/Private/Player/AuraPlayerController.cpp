// Copyright Stavroschr


#include "Player/AuraPlayerController.h"

#include "EnhancedInputSubsystems.h"

#include "EnhancedInputComponent.h"
#include "Interaction/EnemyInterface.h"


AAuraPlayerController::AAuraPlayerController()
{
	bReplicates = true;
}

void AAuraPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	CursorTrace();
}

void AAuraPlayerController::CursorTrace()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECC_Visibility,false,CursorHit);
	if (!CursorHit.bBlockingHit) return;

	Cast<IEnemyInterface>(CursorHit.GetActor());
	LastActor = ThisActor;
	ThisActor = Cast<IEnemyInterface>(CursorHit.GetActor());

	/**A line trace from cursore there are several scenarios
	*a lastActor is Null and ThisActor is null

*B LastActor is null and ThisActor is valid
* highlight ThisActor
*C LastActor is Valid and ThisActor is null
-unhighlight lastActor
*both actors are valid but LastActor!= ThisActor ..hovering different actors
*unhighlight lastactors and highlight ThisActor
*Both actors are valid and are the same actor -do nothing
	*/
	
	if (LastActor == nullptr)
	{
		if(ThisActor!= nullptr)
		{
			//Case B
			ThisActor-> HighlightActor();
		}
		else
		{
			//Case B both null do nothingo
		}
	}
	else //Last actor is valid
	{
	if(ThisActor ==nullptr)
	{
	//Case C lastactor valid this actor null
	LastActor->UnHighlightActor();
	}
else //both actors are valid
{
if(LastActor !=ThisActor)
{
LastActor->UnHighlightActor();
ThisActor->HighlightActor();

}
else
{//case E - do nothing
}
}
	}
}

void AAuraPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(AuraContext);  //assert..if fails it will crash the game

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());

	check(Subsystem);

	Subsystem->AddMappingContext(AuraContext, 0);
	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;

	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);


}

void AAuraPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	
	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);

	EnhancedInputComponent->BindAction(MoveAction,ETriggerEvent::Triggered, this, &AAuraPlayerController::Move);
}

void AAuraPlayerController::Move(const FInputActionValue& InputActionValue) //callback functiongia
{
const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
const FRotator Rotation = GetControlRotation();


const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);
	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn= GetPawn<APawn>())
	{
		//ControlledPawn-> AddMovementInput(FVector::ForwardVector, InputAxisVector.Y);
	//	ControlledPawn-> AddMovementInput(FVector::RightVector, InputAxisVector.X);
		
		ControlledPawn-> AddMovementInput(ForwardDirection, InputAxisVector.Y);
		ControlledPawn-> AddMovementInput(RightDirection, InputAxisVector.X);
	}
}
