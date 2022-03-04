// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FastArenaShooter/GameModeFastArenaFPS.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeGameModeFastArenaFPS() {}
// Cross Module References
	FASTARENASHOOTER_API UScriptStruct* Z_Construct_UScriptStruct_FWaweSytem();
	UPackage* Z_Construct_UPackage__Script_FastArenaShooter();
	COREUOBJECT_API UScriptStruct* Z_Construct_UScriptStruct_FVector();
	FASTARENASHOOTER_API UClass* Z_Construct_UClass_AGameModeFastArenaFPS_NoRegister();
	FASTARENASHOOTER_API UClass* Z_Construct_UClass_AGameModeFastArenaFPS();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
// End Cross Module References
class UScriptStruct* FWaweSytem::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern FASTARENASHOOTER_API uint32 Get_Z_Construct_UScriptStruct_FWaweSytem_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FWaweSytem, Z_Construct_UPackage__Script_FastArenaShooter(), TEXT("WaweSytem"), sizeof(FWaweSytem), Get_Z_Construct_UScriptStruct_FWaweSytem_Hash());
	}
	return Singleton;
}
template<> FASTARENASHOOTER_API UScriptStruct* StaticStruct<FWaweSytem>()
{
	return FWaweSytem::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FWaweSytem(FWaweSytem::StaticStruct, TEXT("/Script/FastArenaShooter"), TEXT("WaweSytem"), false, nullptr, nullptr);
static struct FScriptStruct_FastArenaShooter_StaticRegisterNativesFWaweSytem
{
	FScriptStruct_FastArenaShooter_StaticRegisterNativesFWaweSytem()
	{
		UScriptStruct::DeferCppStructOps<FWaweSytem>(FName(TEXT("WaweSytem")));
	}
} ScriptStruct_FastArenaShooter_StaticRegisterNativesFWaweSytem;
	struct Z_Construct_UScriptStruct_FWaweSytem_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__numberWeakUnity_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp__numberWeakUnity;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__numberBigUnity_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp__numberBigUnity;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__numberRangeUnity_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp__numberRangeUnity;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__cooldownSpawnWeakUnity_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp__cooldownSpawnWeakUnity;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__cooldownBigUnity_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp__cooldownBigUnity;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__cooldownRangeUnity_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp__cooldownRangeUnity;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__spawnWeakUnity_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp__spawnWeakUnity;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__spawnBigUnity_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp__spawnBigUnity;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__spawnRangeUnity_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp__spawnRangeUnity;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FWaweSytem_Statics::Struct_MetaDataParams[] = {
		{ "Comment", "/**\n * \n */" },
		{ "ModuleRelativePath", "GameModeFastArenaFPS.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FWaweSytem_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FWaweSytem>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FWaweSytem_Statics::NewProp__numberWeakUnity_MetaData[] = {
		{ "Category", "Parameter Wawe" },
		{ "ModuleRelativePath", "GameModeFastArenaFPS.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FWaweSytem_Statics::NewProp__numberWeakUnity = { "_numberWeakUnity", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FWaweSytem, _numberWeakUnity), METADATA_PARAMS(Z_Construct_UScriptStruct_FWaweSytem_Statics::NewProp__numberWeakUnity_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWaweSytem_Statics::NewProp__numberWeakUnity_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FWaweSytem_Statics::NewProp__numberBigUnity_MetaData[] = {
		{ "Category", "Parameter Wawe" },
		{ "ModuleRelativePath", "GameModeFastArenaFPS.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FWaweSytem_Statics::NewProp__numberBigUnity = { "_numberBigUnity", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FWaweSytem, _numberBigUnity), METADATA_PARAMS(Z_Construct_UScriptStruct_FWaweSytem_Statics::NewProp__numberBigUnity_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWaweSytem_Statics::NewProp__numberBigUnity_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FWaweSytem_Statics::NewProp__numberRangeUnity_MetaData[] = {
		{ "Category", "Parameter Wawe" },
		{ "ModuleRelativePath", "GameModeFastArenaFPS.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FWaweSytem_Statics::NewProp__numberRangeUnity = { "_numberRangeUnity", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FWaweSytem, _numberRangeUnity), METADATA_PARAMS(Z_Construct_UScriptStruct_FWaweSytem_Statics::NewProp__numberRangeUnity_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWaweSytem_Statics::NewProp__numberRangeUnity_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FWaweSytem_Statics::NewProp__cooldownSpawnWeakUnity_MetaData[] = {
		{ "Category", "Parameter Wawe" },
		{ "ModuleRelativePath", "GameModeFastArenaFPS.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FWaweSytem_Statics::NewProp__cooldownSpawnWeakUnity = { "_cooldownSpawnWeakUnity", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FWaweSytem, _cooldownSpawnWeakUnity), METADATA_PARAMS(Z_Construct_UScriptStruct_FWaweSytem_Statics::NewProp__cooldownSpawnWeakUnity_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWaweSytem_Statics::NewProp__cooldownSpawnWeakUnity_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FWaweSytem_Statics::NewProp__cooldownBigUnity_MetaData[] = {
		{ "Category", "Parameter Wawe" },
		{ "ModuleRelativePath", "GameModeFastArenaFPS.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FWaweSytem_Statics::NewProp__cooldownBigUnity = { "_cooldownBigUnity", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FWaweSytem, _cooldownBigUnity), METADATA_PARAMS(Z_Construct_UScriptStruct_FWaweSytem_Statics::NewProp__cooldownBigUnity_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWaweSytem_Statics::NewProp__cooldownBigUnity_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FWaweSytem_Statics::NewProp__cooldownRangeUnity_MetaData[] = {
		{ "Category", "Parameter Wawe" },
		{ "ModuleRelativePath", "GameModeFastArenaFPS.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FWaweSytem_Statics::NewProp__cooldownRangeUnity = { "_cooldownRangeUnity", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FWaweSytem, _cooldownRangeUnity), METADATA_PARAMS(Z_Construct_UScriptStruct_FWaweSytem_Statics::NewProp__cooldownRangeUnity_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWaweSytem_Statics::NewProp__cooldownRangeUnity_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FWaweSytem_Statics::NewProp__spawnWeakUnity_MetaData[] = {
		{ "Category", "Parameter Wawe" },
		{ "ModuleRelativePath", "GameModeFastArenaFPS.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FWaweSytem_Statics::NewProp__spawnWeakUnity = { "_spawnWeakUnity", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FWaweSytem, _spawnWeakUnity), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FWaweSytem_Statics::NewProp__spawnWeakUnity_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWaweSytem_Statics::NewProp__spawnWeakUnity_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FWaweSytem_Statics::NewProp__spawnBigUnity_MetaData[] = {
		{ "Category", "Parameter Wawe" },
		{ "ModuleRelativePath", "GameModeFastArenaFPS.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FWaweSytem_Statics::NewProp__spawnBigUnity = { "_spawnBigUnity", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FWaweSytem, _spawnBigUnity), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FWaweSytem_Statics::NewProp__spawnBigUnity_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWaweSytem_Statics::NewProp__spawnBigUnity_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FWaweSytem_Statics::NewProp__spawnRangeUnity_MetaData[] = {
		{ "Category", "Parameter Wawe" },
		{ "ModuleRelativePath", "GameModeFastArenaFPS.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UScriptStruct_FWaweSytem_Statics::NewProp__spawnRangeUnity = { "_spawnRangeUnity", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FWaweSytem, _spawnRangeUnity), Z_Construct_UScriptStruct_FVector, METADATA_PARAMS(Z_Construct_UScriptStruct_FWaweSytem_Statics::NewProp__spawnRangeUnity_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWaweSytem_Statics::NewProp__spawnRangeUnity_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FWaweSytem_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWaweSytem_Statics::NewProp__numberWeakUnity,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWaweSytem_Statics::NewProp__numberBigUnity,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWaweSytem_Statics::NewProp__numberRangeUnity,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWaweSytem_Statics::NewProp__cooldownSpawnWeakUnity,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWaweSytem_Statics::NewProp__cooldownBigUnity,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWaweSytem_Statics::NewProp__cooldownRangeUnity,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWaweSytem_Statics::NewProp__spawnWeakUnity,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWaweSytem_Statics::NewProp__spawnBigUnity,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FWaweSytem_Statics::NewProp__spawnRangeUnity,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FWaweSytem_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_FastArenaShooter,
		nullptr,
		&NewStructOps,
		"WaweSytem",
		sizeof(FWaweSytem),
		alignof(FWaweSytem),
		Z_Construct_UScriptStruct_FWaweSytem_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWaweSytem_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FWaweSytem_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FWaweSytem_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FWaweSytem()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FWaweSytem_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_FastArenaShooter();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("WaweSytem"), sizeof(FWaweSytem), Get_Z_Construct_UScriptStruct_FWaweSytem_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FWaweSytem_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FWaweSytem_Hash() { return 1526158249U; }
	void AGameModeFastArenaFPS::StaticRegisterNativesAGameModeFastArenaFPS()
	{
	}
	UClass* Z_Construct_UClass_AGameModeFastArenaFPS_NoRegister()
	{
		return AGameModeFastArenaFPS::StaticClass();
	}
	struct Z_Construct_UClass_AGameModeFastArenaFPS_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp__arrayWaweSytems_Inner;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__arrayWaweSytems_MetaData[];
#endif
		static const UE4CodeGen_Private::FArrayPropertyParams NewProp__arrayWaweSytems;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AGameModeFastArenaFPS_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AGameModeBase,
		(UObject* (*)())Z_Construct_UPackage__Script_FastArenaShooter,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGameModeFastArenaFPS_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
		{ "IncludePath", "GameModeFastArenaFPS.h" },
		{ "ModuleRelativePath", "GameModeFastArenaFPS.h" },
		{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AGameModeFastArenaFPS_Statics::NewProp__arrayWaweSytems_Inner = { "_arrayWaweSytems", nullptr, (EPropertyFlags)0x0000000000000000, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, 0, Z_Construct_UScriptStruct_FWaweSytem, METADATA_PARAMS(nullptr, 0) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AGameModeFastArenaFPS_Statics::NewProp__arrayWaweSytems_MetaData[] = {
		{ "Category", "Number Of Wawe" },
		{ "ModuleRelativePath", "GameModeFastArenaFPS.h" },
	};
#endif
	const UE4CodeGen_Private::FArrayPropertyParams Z_Construct_UClass_AGameModeFastArenaFPS_Statics::NewProp__arrayWaweSytems = { "_arrayWaweSytems", nullptr, (EPropertyFlags)0x0010000000000001, UE4CodeGen_Private::EPropertyGenFlags::Array, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AGameModeFastArenaFPS, _arrayWaweSytems), EArrayPropertyFlags::None, METADATA_PARAMS(Z_Construct_UClass_AGameModeFastArenaFPS_Statics::NewProp__arrayWaweSytems_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AGameModeFastArenaFPS_Statics::NewProp__arrayWaweSytems_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AGameModeFastArenaFPS_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGameModeFastArenaFPS_Statics::NewProp__arrayWaweSytems_Inner,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AGameModeFastArenaFPS_Statics::NewProp__arrayWaweSytems,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AGameModeFastArenaFPS_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AGameModeFastArenaFPS>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AGameModeFastArenaFPS_Statics::ClassParams = {
		&AGameModeFastArenaFPS::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AGameModeFastArenaFPS_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AGameModeFastArenaFPS_Statics::PropPointers),
		0,
		0x009002ACu,
		METADATA_PARAMS(Z_Construct_UClass_AGameModeFastArenaFPS_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AGameModeFastArenaFPS_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AGameModeFastArenaFPS()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AGameModeFastArenaFPS_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AGameModeFastArenaFPS, 220488620);
	template<> FASTARENASHOOTER_API UClass* StaticClass<AGameModeFastArenaFPS>()
	{
		return AGameModeFastArenaFPS::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AGameModeFastArenaFPS(Z_Construct_UClass_AGameModeFastArenaFPS, &AGameModeFastArenaFPS::StaticClass, TEXT("/Script/FastArenaShooter"), TEXT("AGameModeFastArenaFPS"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AGameModeFastArenaFPS);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
