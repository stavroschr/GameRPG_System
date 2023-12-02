// Copyright Stavroschr

#pragma once

#include "CoreMinimal.h"
#include "Character/AuraCharacterBase.h"
#include "Interaction/EnemyInterface.h"
#include "AuraEnemy.generated.h"

/**
 * 
 */
UCLASS()
class AURA_API AAuraEnemy : public AAuraCharacterBase,public IEnemyInterface
{
	GENERATED_BODY()


public:
	AAuraEnemy();

	//enemy interface
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override ;
//end enemy interface
protected:
	virtual void BeginPlay() override;

	
};
