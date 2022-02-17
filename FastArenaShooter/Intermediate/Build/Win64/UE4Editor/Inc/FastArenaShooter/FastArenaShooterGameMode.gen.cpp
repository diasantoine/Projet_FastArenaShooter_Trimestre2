// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "OtherScript/FastArenaShooterGameMode.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFastArenaShooterGameMode() {}
// Cross Module References
	FASTARENASHOOTER_API UClass* Z_Construct_UClass_AFastArenaShooterGameMode_NoRegister();
	FASTARENASHOOTER_API UClass* Z_Construct_UClass_AFastArenaShooterGameMode();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_FastArenaShooter();
// End Cross Module References
	void AFastArenaShooterGameMode::StaticRegisterNativesAFastArenaShooterGameMode()
	{
	}
	UClass* Z_Construct_UClass_AFastArenaShooterGameMode_NoRegister()
	{
		return AFastArenaShooterGameMode::StaticClass();
	}
	struct Z_Construct_UClass_AFastArenaShooterGameMode_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AFastArenaShooterGameMode_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_FastArenaShooter,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFastArenaShooterGameMode_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "FastArenaShooterGameMode.h" },
		{ "ModuleRelativePath", "FastArenaShooterGameMode.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AFastArenaShooterGameMode_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFastArenaShooterGameMode>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AFastArenaShooterGameMode_Statics::ClassParams = {
		&AFastArenaShooterGameMode::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x008802ACu,
		METADATA_PARAMS(Z_Construct_UClass_AFastArenaShooterGameMode_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AFastArenaShooterGameMode_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AFastArenaShooterGameMode()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AFastArenaShooterGameMode_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AFastArenaShooterGameMode, 2716942096);
	template<> FASTARENASHOOTER_API UClass* StaticClass<AFastArenaShooterGameMode>()
	{
		return AFastArenaShooterGameMode::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AFastArenaShooterGameMode(Z_Construct_UClass_AFastArenaShooterGameMode, &AFastArenaShooterGameMode::StaticClass, TEXT("/Script/FastArenaShooter"), TEXT("AFastArenaShooterGameMode"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFastArenaShooterGameMode);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
