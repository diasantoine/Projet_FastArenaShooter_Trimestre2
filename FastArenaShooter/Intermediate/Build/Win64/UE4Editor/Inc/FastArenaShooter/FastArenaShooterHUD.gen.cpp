// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FastArenaShooter/FastArenaShooterHUD.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeFastArenaShooterHUD() {}
// Cross Module References
	FASTARENASHOOTER_API UClass* Z_Construct_UClass_AFastArenaShooterHUD_NoRegister();
	FASTARENASHOOTER_API UClass* Z_Construct_UClass_AFastArenaShooterHUD();
	ENGINE_API UClass* Z_Construct_UClass_AHUD();
	UPackage* Z_Construct_UPackage__Script_FastArenaShooter();
// End Cross Module References
	void AFastArenaShooterHUD::StaticRegisterNativesAFastArenaShooterHUD()
	{
	}
	UClass* Z_Construct_UClass_AFastArenaShooterHUD_NoRegister()
	{
		return AFastArenaShooterHUD::StaticClass();
	}
	struct Z_Construct_UClass_AFastArenaShooterHUD_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AFastArenaShooterHUD_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AHUD,
		(UObject* (*)())Z_Construct_UPackage__Script_FastArenaShooter,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AFastArenaShooterHUD_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Rendering Actor Input Replication" },
		{ "IncludePath", "FastArenaShooterHUD.h" },
		{ "ModuleRelativePath", "FastArenaShooterHUD.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AFastArenaShooterHUD_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AFastArenaShooterHUD>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AFastArenaShooterHUD_Statics::ClassParams = {
		&AFastArenaShooterHUD::StaticClass,
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
		0x008002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AFastArenaShooterHUD_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AFastArenaShooterHUD_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AFastArenaShooterHUD()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AFastArenaShooterHUD_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AFastArenaShooterHUD, 3127043986);
	template<> FASTARENASHOOTER_API UClass* StaticClass<AFastArenaShooterHUD>()
	{
		return AFastArenaShooterHUD::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AFastArenaShooterHUD(Z_Construct_UClass_AFastArenaShooterHUD, &AFastArenaShooterHUD::StaticClass, TEXT("/Script/FastArenaShooter"), TEXT("AFastArenaShooterHUD"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AFastArenaShooterHUD);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
