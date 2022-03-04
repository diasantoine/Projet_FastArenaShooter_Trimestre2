// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FastArenaShooter/MyWeaponBehaviour.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyWeaponBehaviour() {}
// Cross Module References
	FASTARENASHOOTER_API UClass* Z_Construct_UClass_AMyWeaponBehaviour_NoRegister();
	FASTARENASHOOTER_API UClass* Z_Construct_UClass_AMyWeaponBehaviour();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_FastArenaShooter();
// End Cross Module References
	void AMyWeaponBehaviour::StaticRegisterNativesAMyWeaponBehaviour()
	{
	}
	UClass* Z_Construct_UClass_AMyWeaponBehaviour_NoRegister()
	{
		return AMyWeaponBehaviour::StaticClass();
	}
	struct Z_Construct_UClass_AMyWeaponBehaviour_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMyWeaponBehaviour_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_FastArenaShooter,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyWeaponBehaviour_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "MyWeaponBehaviour.h" },
		{ "ModuleRelativePath", "MyWeaponBehaviour.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMyWeaponBehaviour_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMyWeaponBehaviour>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMyWeaponBehaviour_Statics::ClassParams = {
		&AMyWeaponBehaviour::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		0,
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AMyWeaponBehaviour_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AMyWeaponBehaviour_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMyWeaponBehaviour()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMyWeaponBehaviour_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMyWeaponBehaviour, 3603211455);
	template<> FASTARENASHOOTER_API UClass* StaticClass<AMyWeaponBehaviour>()
	{
		return AMyWeaponBehaviour::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMyWeaponBehaviour(Z_Construct_UClass_AMyWeaponBehaviour, &AMyWeaponBehaviour::StaticClass, TEXT("/Script/FastArenaShooter"), TEXT("AMyWeaponBehaviour"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMyWeaponBehaviour);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
