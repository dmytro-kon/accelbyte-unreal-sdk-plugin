﻿#pragma once

#include "CoreMinimal.h"
#include "ABUser.h"
#include "AccelByteBPLobby.h"
#include "ABParty.h"
#include "ABMatchmaking.h"
#include "ABFriends.h"
#include "ABCatalog.h"
#include "ABOrder.h"
#include "ABEntitlement.h"
#include "ABCurrency.h"
#include "ABWallet.h"
#include "ABFulfillment.h"
#include "ABCloudSave.h"
#include "ABAgreement.h"
#include "ABReward.h"
#include "ABSeasonPass.h"
#include "ABStatistic.h"
#include "ABLeaderboard.h"
#include "ABAchievement.h"
#include "ABSessionBrowser.h"
#include "ABUGC.h"
#include "ABPresence.h"
#include "ABBlock.h"
#include "ABMessage.h"
#include "ABSessionAttribute.h"
#include "ABSignaling.h"
#include "ABGroup.h"
#include "AccelByteUe4Sdk/Public/Core/AccelByteError.h"
#include "Core/AccelByteMultiRegistry.h"
#include "AccelByteBPApiClient.generated.h"

using namespace AccelByte;
using namespace AccelByte::Api;

UCLASS(Blueprintable, BlueprintType)
class UABCredentials final : public UObject
{
	GENERATED_BODY()

public:
	void SetApiClient(FApiClientPtr const& NewApiClientPtr);

	UFUNCTION(BlueprintCallable)
	FString GetAccessToken();

	UFUNCTION(BlueprintCallable)
	FString GetUserId();

private:
	FApiClientPtr ApiClientPtr;
};


UCLASS(Blueprintable, BlueprintType)
class UABApiClient final : public UObject
{
	GENERATED_BODY()

public:
	UABApiClient();

	void SetApiClient(FApiClientPtr NewApiClientPtr);

	UPROPERTY(BlueprintReadOnly)
	UABCredentials* Credentials;

	UPROPERTY(BlueprintReadOnly)
	UABUser* User;

	UPROPERTY(BlueprintReadOnly)
	UABLobby* Lobby;

	UPROPERTY(BlueprintReadOnly)
	UABParty* Party;
	
	UPROPERTY(BlueprintReadOnly)
	UABMatchmaking* Matchmaking;
	
	UPROPERTY(BlueprintReadOnly)
	UABFriends* Friends;

	UPROPERTY(BlueprintReadOnly)
	UABCatalog* Catalog;

	UPROPERTY(BlueprintReadOnly)
	UABOrder* Order;

	UPROPERTY(BlueprintReadOnly)
	UABEntitlement* Entitlement;

	UPROPERTY(BlueprintReadOnly)
	UABCurrency* Currency;

	UPROPERTY(BlueprintReadOnly)
	UABWallet* Wallet;

	UPROPERTY(BlueprintReadOnly)
	UABFulfillment* Fulfillment;

	UPROPERTY(BlueprintReadOnly)
	UABCloudSave* CloudSave;

	UPROPERTY(BlueprintReadOnly)
	UABAgreement* Agreement;

	UPROPERTY(BlueprintReadOnly)
	UABReward* Reward;

	UPROPERTY(BlueprintReadOnly)
	UABSeasonPass* SeasonPass;

	UPROPERTY(BlueprintReadOnly)
	UABStatistic* Statistic;

	UPROPERTY(BlueprintReadOnly)
	UABLeaderboard* Leaderboard;

	UPROPERTY(BlueprintReadOnly)
	UABAchievement* Achievement;

	UPROPERTY(BlueprintReadOnly)
	UABSessionBrowser* SessionBrowser;

	UPROPERTY(BlueprintReadOnly)
	UABUGC* UGC;

	UPROPERTY(BlueprintReadOnly)
	UABPresence* Presence;
	
	UPROPERTY(BlueprintReadOnly)
	UABBlock* Block;
	
	UPROPERTY(BlueprintReadOnly)
	UABMessage* Message;
	
	UPROPERTY(BlueprintReadOnly)
	UABSessionAttribute* SessionAttribute;
	
	UPROPERTY(BlueprintReadOnly)
	UABSignaling* Signaling;

	UPROPERTY(BlueprintReadOnly)
	UABGroup* Group;

private:
	FApiClientPtr ApiClientPtr;
};


UCLASS(Blueprintable, BlueprintType)
class UABMultiRegistry final : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:

	UFUNCTION(BlueprintCallable)
	static UABApiClient* GetApiClient(FString const& Key);
};

