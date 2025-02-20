// Copyright (c) 2022 AccelByte Inc. All Rights Reserved.
// This is licensed software from AccelByte Inc, for limitations
// and restrictions contact your company contract manager.

#pragma once

#include "CoreMinimal.h"
#include "Core/AccelByteError.h"
#include "Models/AccelByteLobbyModels.h"
#include "Core/AccelByteMultiRegistry.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ABPresence.generated.h"

using namespace AccelByte;

USTRUCT(BlueprintType)
struct FPresenceStatus
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	Availability Availability{};

	UPROPERTY(BlueprintReadWrite)
	FString Activity{};
};

USTRUCT(BlueprintType)
struct FBulkGetUserPresenceRequest
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite)
	bool bCountOnly{};
	
	UPROPERTY(BlueprintReadWrite)
	TArray<FString> UserIds{};
};

DECLARE_DYNAMIC_DELEGATE_OneParam(FDGetAllFriendsStatusResponse, FAccelByteModelsGetOnlineUsersResponse, Response);

DECLARE_DYNAMIC_DELEGATE_OneParam(FDBulkGetUserPresence, FAccelByteModelsBulkUserStatusNotif, Response);

DECLARE_DYNAMIC_DELEGATE_OneParam(FDOnSetUserPresence, FAccelByteModelsSetOnlineUsersResponse, Response);

DECLARE_DYNAMIC_DELEGATE_OneParam(FDFriendStatusNotif, FAccelByteModelsUsersPresenceNotice, Notif);

//Sub-API from AccelByte Lobby
UCLASS(Blueprintable, BlueprintType)
class UABPresence : public UObject
{
	GENERATED_BODY()
public:
	void SetApiClient(FApiClientPtr const& NewApiClientPtr);

//Request-Response
public: 
	UFUNCTION(BlueprintCallable, Category = "AccelByte | Presence")
	void GetAllFriendsStatus(FDGetAllFriendsStatusResponse OnResponse, FDErrorHandler OnError);

	UFUNCTION(BlueprintCallable, Category = "AccelByte | Presence")
	void BulkGetUserPresence(FBulkGetUserPresenceRequest const& Request, FDBulkGetUserPresence OnResponse, FDErrorHandler OnError);
	
	UFUNCTION(BlueprintCallable, Category = "AccelByte | Presence")
	void SetPresenceStatus(FPresenceStatus const& Request, FDOnSetUserPresence OnResponse, FDErrorHandler OnError);

//Notification
public:
	UFUNCTION(BlueprintCallable, Category = "AccelByte | Presence")
	void SetOnFriendStatusNotif(FDFriendStatusNotif OnNotif);

private:
	FApiClientPtr ApiClientPtr;
};
