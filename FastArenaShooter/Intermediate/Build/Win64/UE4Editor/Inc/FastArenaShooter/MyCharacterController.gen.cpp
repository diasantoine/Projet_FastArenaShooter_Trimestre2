// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "FastArenaShooter/MyCharacterController.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeMyCharacterController() {}
// Cross Module References
	FASTARENASHOOTER_API UScriptStruct* Z_Construct_UScriptStruct_FdataStruct();
	UPackage* Z_Construct_UPackage__Script_FastArenaShooter();
	FASTARENASHOOTER_API UClass* Z_Construct_UClass_AMyCharacterController_NoRegister();
	FASTARENASHOOTER_API UClass* Z_Construct_UClass_AMyCharacterController();
	ENGINE_API UClass* Z_Construct_UClass_ACharacter();
// End Cross Module References
class UScriptStruct* FdataStruct::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern FASTARENASHOOTER_API uint32 Get_Z_Construct_UScriptStruct_FdataStruct_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FdataStruct, Z_Construct_UPackage__Script_FastArenaShooter(), TEXT("dataStruct"), sizeof(FdataStruct), Get_Z_Construct_UScriptStruct_FdataStruct_Hash());
	}
	return Singleton;
}
template<> FASTARENASHOOTER_API UScriptStruct* StaticStruct<FdataStruct>()
{
	return FdataStruct::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FdataStruct(FdataStruct::StaticStruct, TEXT("/Script/FastArenaShooter"), TEXT("dataStruct"), false, nullptr, nullptr);
static struct FScriptStruct_FastArenaShooter_StaticRegisterNativesFdataStruct
{
	FScriptStruct_FastArenaShooter_StaticRegisterNativesFdataStruct()
	{
		UScriptStruct::DeferCppStructOps<FdataStruct>(FName(TEXT("dataStruct")));
	}
} ScriptStruct_FastArenaShooter_StaticRegisterNativesFdataStruct;
	struct Z_Construct_UScriptStruct_FdataStruct_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__groundAcceleration_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp__groundAcceleration;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__maxSpeed_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp__maxSpeed;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__height_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp__height;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__jumpWindow_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp__jumpWindow;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__minimumAngleForBunny_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp__minimumAngleForBunny;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__weight_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp__weight;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__airAcceleration_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp__airAcceleration;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__timeBeforeDecceleration_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp__timeBeforeDecceleration;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__deceleration_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp__deceleration;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FdataStruct_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyCharacterController.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FdataStruct_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FdataStruct>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FdataStruct_Statics::NewProp__groundAcceleration_MetaData[] = {
		{ "Category", "Stat Character" },
		{ "ModuleRelativePath", "MyCharacterController.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FdataStruct_Statics::NewProp__groundAcceleration = { "_groundAcceleration", nullptr, (EPropertyFlags)0x0010000000010001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FdataStruct, _groundAcceleration), METADATA_PARAMS(Z_Construct_UScriptStruct_FdataStruct_Statics::NewProp__groundAcceleration_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FdataStruct_Statics::NewProp__groundAcceleration_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FdataStruct_Statics::NewProp__maxSpeed_MetaData[] = {
		{ "Category", "Stat Character" },
		{ "ModuleRelativePath", "MyCharacterController.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FdataStruct_Statics::NewProp__maxSpeed = { "_maxSpeed", nullptr, (EPropertyFlags)0x0010000000010001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FdataStruct, _maxSpeed), METADATA_PARAMS(Z_Construct_UScriptStruct_FdataStruct_Statics::NewProp__maxSpeed_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FdataStruct_Statics::NewProp__maxSpeed_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FdataStruct_Statics::NewProp__height_MetaData[] = {
		{ "Category", "Stat Character" },
		{ "ModuleRelativePath", "MyCharacterController.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FdataStruct_Statics::NewProp__height = { "_height", nullptr, (EPropertyFlags)0x0010000000010001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FdataStruct, _height), METADATA_PARAMS(Z_Construct_UScriptStruct_FdataStruct_Statics::NewProp__height_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FdataStruct_Statics::NewProp__height_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FdataStruct_Statics::NewProp__jumpWindow_MetaData[] = {
		{ "Category", "Stat Character" },
		{ "ModuleRelativePath", "MyCharacterController.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FdataStruct_Statics::NewProp__jumpWindow = { "_jumpWindow", nullptr, (EPropertyFlags)0x0010000000010001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FdataStruct, _jumpWindow), METADATA_PARAMS(Z_Construct_UScriptStruct_FdataStruct_Statics::NewProp__jumpWindow_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FdataStruct_Statics::NewProp__jumpWindow_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FdataStruct_Statics::NewProp__minimumAngleForBunny_MetaData[] = {
		{ "Category", "Stat Character" },
		{ "ModuleRelativePath", "MyCharacterController.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FdataStruct_Statics::NewProp__minimumAngleForBunny = { "_minimumAngleForBunny", nullptr, (EPropertyFlags)0x0010000000010001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FdataStruct, _minimumAngleForBunny), METADATA_PARAMS(Z_Construct_UScriptStruct_FdataStruct_Statics::NewProp__minimumAngleForBunny_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FdataStruct_Statics::NewProp__minimumAngleForBunny_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FdataStruct_Statics::NewProp__weight_MetaData[] = {
		{ "Category", "Stat Character" },
		{ "ModuleRelativePath", "MyCharacterController.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FdataStruct_Statics::NewProp__weight = { "_weight", nullptr, (EPropertyFlags)0x0010000000010001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FdataStruct, _weight), METADATA_PARAMS(Z_Construct_UScriptStruct_FdataStruct_Statics::NewProp__weight_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FdataStruct_Statics::NewProp__weight_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FdataStruct_Statics::NewProp__airAcceleration_MetaData[] = {
		{ "Category", "Stat Character" },
		{ "ModuleRelativePath", "MyCharacterController.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FdataStruct_Statics::NewProp__airAcceleration = { "_airAcceleration", nullptr, (EPropertyFlags)0x0010000000010001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FdataStruct, _airAcceleration), METADATA_PARAMS(Z_Construct_UScriptStruct_FdataStruct_Statics::NewProp__airAcceleration_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FdataStruct_Statics::NewProp__airAcceleration_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FdataStruct_Statics::NewProp__timeBeforeDecceleration_MetaData[] = {
		{ "Category", "Stat Character" },
		{ "ModuleRelativePath", "MyCharacterController.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FdataStruct_Statics::NewProp__timeBeforeDecceleration = { "_timeBeforeDecceleration", nullptr, (EPropertyFlags)0x0010000000010001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FdataStruct, _timeBeforeDecceleration), METADATA_PARAMS(Z_Construct_UScriptStruct_FdataStruct_Statics::NewProp__timeBeforeDecceleration_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FdataStruct_Statics::NewProp__timeBeforeDecceleration_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FdataStruct_Statics::NewProp__deceleration_MetaData[] = {
		{ "Category", "Stat Character" },
		{ "ModuleRelativePath", "MyCharacterController.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FdataStruct_Statics::NewProp__deceleration = { "_deceleration", nullptr, (EPropertyFlags)0x0010000000010001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FdataStruct, _deceleration), METADATA_PARAMS(Z_Construct_UScriptStruct_FdataStruct_Statics::NewProp__deceleration_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FdataStruct_Statics::NewProp__deceleration_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FdataStruct_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FdataStruct_Statics::NewProp__groundAcceleration,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FdataStruct_Statics::NewProp__maxSpeed,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FdataStruct_Statics::NewProp__height,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FdataStruct_Statics::NewProp__jumpWindow,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FdataStruct_Statics::NewProp__minimumAngleForBunny,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FdataStruct_Statics::NewProp__weight,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FdataStruct_Statics::NewProp__airAcceleration,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FdataStruct_Statics::NewProp__timeBeforeDecceleration,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FdataStruct_Statics::NewProp__deceleration,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FdataStruct_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_FastArenaShooter,
		nullptr,
		&NewStructOps,
		"dataStruct",
		sizeof(FdataStruct),
		alignof(FdataStruct),
		Z_Construct_UScriptStruct_FdataStruct_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FdataStruct_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FdataStruct_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FdataStruct_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FdataStruct()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FdataStruct_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_FastArenaShooter();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("dataStruct"), sizeof(FdataStruct), Get_Z_Construct_UScriptStruct_FdataStruct_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FdataStruct_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FdataStruct_Hash() { return 2397197918U; }
	void AMyCharacterController::StaticRegisterNativesAMyCharacterController()
	{
	}
	UClass* Z_Construct_UClass_AMyCharacterController_NoRegister()
	{
		return AMyCharacterController::StaticClass();
	}
	struct Z_Construct_UClass_AMyCharacterController_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__fDataStruct_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp__fDataStruct;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AMyCharacterController_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_ACharacter,
		(UObject* (*)())Z_Construct_UPackage__Script_FastArenaShooter,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacterController_Statics::Class_MetaDataParams[] = {
		{ "HideCategories", "Navigation" },
		{ "IncludePath", "MyCharacterController.h" },
		{ "ModuleRelativePath", "MyCharacterController.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyCharacterController_Statics::NewProp__fDataStruct_MetaData[] = {
		{ "Category", "Stat Character" },
		{ "ModuleRelativePath", "MyCharacterController.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AMyCharacterController_Statics::NewProp__fDataStruct = { "_fDataStruct", nullptr, (EPropertyFlags)0x0010000000010001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyCharacterController, _fDataStruct), Z_Construct_UScriptStruct_FdataStruct, METADATA_PARAMS(Z_Construct_UClass_AMyCharacterController_Statics::NewProp__fDataStruct_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacterController_Statics::NewProp__fDataStruct_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMyCharacterController_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyCharacterController_Statics::NewProp__fDataStruct,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMyCharacterController_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMyCharacterController>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMyCharacterController_Statics::ClassParams = {
		&AMyCharacterController::StaticClass,
		"Game",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AMyCharacterController_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacterController_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AMyCharacterController_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AMyCharacterController_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AMyCharacterController()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AMyCharacterController_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AMyCharacterController, 440111531);
	template<> FASTARENASHOOTER_API UClass* StaticClass<AMyCharacterController>()
	{
		return AMyCharacterController::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AMyCharacterController(Z_Construct_UClass_AMyCharacterController, &AMyCharacterController::StaticClass, TEXT("/Script/FastArenaShooter"), TEXT("AMyCharacterController"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AMyCharacterController);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
