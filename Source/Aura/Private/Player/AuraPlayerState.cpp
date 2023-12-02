// Copyright Stavroschr


#include "Player/AuraPlayerState.h"

#include "AbilitySystem/AuraAbilitySystemComponent.h"
#include "AbilitySystem/AuraAttributeSet.h"

AAuraPlayerState::AAuraPlayerState()
{
	AbilitySystemComponent = CreateDefaultSubobject<UAuraAbilitySystemComponent>("AbilitySystemComponent");

	AbilitySystemComponent ->SetIsReplicated(true);

AbilitySystemComponent ->SetReplicationMode(EGameplayEffectReplicationMode::Mixed);


	AttributeSet = CreateDefaultSubobject<UAuraAttributeSet>("AttributeSet"); //created attribute set for the enemy
	NetUpdateFrequency = 100.f; //server is sending information that syncs up 
}

UAbilitySystemComponent* AAuraPlayerState::GetAbilitySystemComponent() const
{
	return AbilitySystemComponent;
}
