// Copyright Stavroschr


#include "Character/AuraCharacter.h"

#include "GameFramework/CharacterMovementComponent.h"




AAuraCharacter::AAuraCharacter()
{
	GetCharacterMovement()-> bOrientRotationToMovement = true; //classic topdown parameters
	GetCharacterMovement()-> RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()-> bConstrainToPlane = true;
	GetCharacterMovement()-> bSnapToPlaneAtStart = true;

bUseControllerRotationPitch = false;
bUseControllerRotationRoll = false;
bUseControllerRotationYaw =false;


}