// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FastArenaShooter/MyBulletsForFirstWeapon.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyBulletsForFirstWeapon() {}
// Cross Module References
	FASTARENASHOOTER_API UClass* Z_Construct_UClass_AMyBulletsForFirstWeapon_NoRegister();
	FASTARENASHOOTER_API UClass* Z_Construct_UClass_AMyBulletsForFirstWeapon();
	FASTARENASHOOTER_API UClass* Z_Construct_UClass_AMyBulletsBehaviour();
	UPackage* Z_Construct_UPackage__Script_FastArenaShooter();
// End Cross Module References
	void AMyBulletsForFirstWeapon::StaticRegisterNativesAMyBulletsForFirstWeapon()
	{
	}
	UClass* Z_Construct_UClass_AMyBulletsForFirstWeapon_NoRegister()
	{
		return AMyBulletsForFirstWeapon::StaticClass();
	}
	struct Z_Construct_UClass_AMyBulletsForFirstWeapon_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMyBulletsForFirstWeapon_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AMyBulletsBehaviour,
		(UObject* (*)())Z_Construct_UPackage__Script_FastArenaShooter,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBulletsForFirstWeapon_Statics::Class_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "IncludePath", "MyBulletsForFirstWeapon.h" },
		{ "ModuleRelativePath", "MyBulletsForFirstWeapon.h" },
	};
#endif
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMyBulletsForFirstWeapon_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMyBulletsForFirstWeapon>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMyBulletsForFirstWeapon_Statics::ClassParams = {
		&AMyBulletsForFirstWeapon::StaticClass,
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
		METADATA_PARAMS(Z_Construct_UClass_AMyBulletsForFirstWeapon_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBulletsForFirstWeapon_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMyBulletsForFirstWeapon()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMyBulletsForFirstWeapon_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMyBulletsForFirstWeapon, 655198486);
	template<> FASTARENASHOOTER_API UClass* StaticClass<AMyBulletsForFirstWeapon>()
	{
		return AMyBulletsForFirstWeapon::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMyBulletsForFirstWeapon(Z_Construct_UClass_AMyBulletsForFirstWeapon, &AMyBulletsForFirstWeapon::StaticClass, TEXT("/Script/FastArenaShooter"), TEXT("AMyBulletsForFirstWeapon"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMyBulletsForFirstWeapon);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
