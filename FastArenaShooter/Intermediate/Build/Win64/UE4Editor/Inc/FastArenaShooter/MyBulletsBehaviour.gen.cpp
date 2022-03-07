// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FastArenaShooter/MyBulletsBehaviour.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyBulletsBehaviour() {}
// Cross Module References
	FASTARENASHOOTER_API UScriptStruct* Z_Construct_UScriptStruct_FBulletParameter();
	UPackage* Z_Construct_UPackage__Script_FastArenaShooter();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
	FASTARENASHOOTER_API UClass* Z_Construct_UClass_AMyBulletsBehaviour_NoRegister();
	FASTARENASHOOTER_API UClass* Z_Construct_UClass_AMyBulletsBehaviour();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
// End Cross Module References
class UScriptStruct* FBulletParameter::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern FASTARENASHOOTER_API uint32 Get_Z_Construct_UScriptStruct_FBulletParameter_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FBulletParameter, Z_Construct_UPackage__Script_FastArenaShooter(), TEXT("BulletParameter"), sizeof(FBulletParameter), Get_Z_Construct_UScriptStruct_FBulletParameter_Hash());
	}
	return Singleton;
}
template<> FASTARENASHOOTER_API UScriptStruct* StaticStruct<FBulletParameter>()
{
	return FBulletParameter::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FBulletParameter(FBulletParameter::StaticStruct, TEXT("/Script/FastArenaShooter"), TEXT("BulletParameter"), false, nullptr, nullptr);
static struct FScriptStruct_FastArenaShooter_StaticRegisterNativesFBulletParameter
{
	FScriptStruct_FastArenaShooter_StaticRegisterNativesFBulletParameter()
	{
		UScriptStruct::DeferCppStructOps<FBulletParameter>(FName(TEXT("BulletParameter")));
	}
} ScriptStruct_FastArenaShooter_StaticRegisterNativesFBulletParameter;
	struct Z_Construct_UScriptStruct_FBulletParameter_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__modelOfBullet_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp__modelOfBullet;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FBulletParameter_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyBulletsBehaviour.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FBulletParameter_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FBulletParameter>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FBulletParameter_Statics::NewProp__modelOfBullet_MetaData[] = {
		{ "Category", "Bullet Parameter" },
		{ "ModuleRelativePath", "MyBulletsBehaviour.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FBulletParameter_Statics::NewProp__modelOfBullet = { "_modelOfBullet", nullptr, (EPropertyFlags)0x0010000000010001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FBulletParameter, _modelOfBullet), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FBulletParameter_Statics::NewProp__modelOfBullet_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FBulletParameter_Statics::NewProp__modelOfBullet_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FBulletParameter_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FBulletParameter_Statics::NewProp__modelOfBullet,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FBulletParameter_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_FastArenaShooter,
		nullptr,
		&NewStructOps,
		"BulletParameter",
		sizeof(FBulletParameter),
		alignof(FBulletParameter),
		Z_Construct_UScriptStruct_FBulletParameter_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FBulletParameter_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FBulletParameter_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FBulletParameter_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FBulletParameter()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FBulletParameter_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_FastArenaShooter();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("BulletParameter"), sizeof(FBulletParameter), Get_Z_Construct_UScriptStruct_FBulletParameter_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FBulletParameter_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FBulletParameter_Hash() { return 2732647541U; }
	void AMyBulletsBehaviour::StaticRegisterNativesAMyBulletsBehaviour()
	{
	}
	UClass* Z_Construct_UClass_AMyBulletsBehaviour_NoRegister()
	{
		return AMyBulletsBehaviour::StaticClass();
	}
	struct Z_Construct_UClass_AMyBulletsBehaviour_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__meshOfBullet_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp__meshOfBullet;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMyBulletsBehaviour_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_FastArenaShooter,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBulletsBehaviour_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "MyBulletsBehaviour.h" },
		{ "ModuleRelativePath", "MyBulletsBehaviour.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyBulletsBehaviour_Statics::NewProp__meshOfBullet_MetaData[] = {
		{ "Category", "Bullet Parameter" },
		{ "ModuleRelativePath", "MyBulletsBehaviour.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AMyBulletsBehaviour_Statics::NewProp__meshOfBullet = { "_meshOfBullet", nullptr, (EPropertyFlags)0x0020080000010001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyBulletsBehaviour, _meshOfBullet), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(Z_Construct_UClass_AMyBulletsBehaviour_Statics::NewProp__meshOfBullet_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBulletsBehaviour_Statics::NewProp__meshOfBullet_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMyBulletsBehaviour_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyBulletsBehaviour_Statics::NewProp__meshOfBullet,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMyBulletsBehaviour_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMyBulletsBehaviour>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMyBulletsBehaviour_Statics::ClassParams = {
		&AMyBulletsBehaviour::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AMyBulletsBehaviour_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AMyBulletsBehaviour_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AMyBulletsBehaviour_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AMyBulletsBehaviour_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMyBulletsBehaviour()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMyBulletsBehaviour_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMyBulletsBehaviour, 3152185818);
	template<> FASTARENASHOOTER_API UClass* StaticClass<AMyBulletsBehaviour>()
	{
		return AMyBulletsBehaviour::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMyBulletsBehaviour(Z_Construct_UClass_AMyBulletsBehaviour, &AMyBulletsBehaviour::StaticClass, TEXT("/Script/FastArenaShooter"), TEXT("AMyBulletsBehaviour"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMyBulletsBehaviour);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
