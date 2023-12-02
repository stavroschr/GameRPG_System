// Copyright Stavroschr


#include "Character/AuraEnemy.h"

#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"
#include "Aura/Aura.h"

AAuraEnemy::AAuraEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility,ECR_Block);

AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");

AbilitySystemComponent ->SetIsReplicated(true);
	AbilitySystemComponent ->SetReplicationMode(EGameplayEffectReplicationMode::Minimal);
	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet"); //created attribute set for the enemy
}

void AAuraEnemy::HighlightActor()
{
GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(CUSTOM_RED_DEPTH);
	Weapon->SetRenderCustomDepth(true);
	Weapon->SetCustomDepthStencilValue(CUSTOM_RED_DEPTH);

}

void AAuraEnemy::UnHighlightActor()
{
	GetMesh()->SetRenderCustomDepth(false);
	Weapon->SetRenderCustomDepth(false);

}

void AAuraEnemy::BeginPlay()
{
	Super::BeginPlay();
//check(AbilitySystemComponent) den exw assert giati exw ftiaksei dhmiourgo ,opote ta pointers den einai null
	AbilitySystemComponent -> InitAbilityActorInfo(this, this);
}
