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
	FASTARENASHOOTER_API UEnum* Z_Construct_UEnum_FastArenaShooter_TypeOfWeapon();
	UPackage* Z_Construct_UPackage__Script_FastArenaShooter();
	FASTARENASHOOTER_API UScriptStruct* Z_Construct_UScriptStruct_FdataWeapon();
	COREUOBJECT_API UClass* Z_Construct_UClass_UClass();
	FASTARENASHOOTER_API UClass* Z_Construct_UClass_AMyBulletsBehaviour_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMesh_NoRegister();
	ENGINE_API UClass* Z_Construct_UClass_AActor_NoRegister();
	FASTARENASHOOTER_API UClass* Z_Construct_UClass_AMyWeaponBehaviour_NoRegister();
	FASTARENASHOOTER_API UClass* Z_Construct_UClass_AMyWeaponBehaviour();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
// End Cross Module References
	static UEnum* TypeOfWeapon_StaticEnum()
	{
		static UEnum* Singleton = nullptr;
		if (!Singleton)
		{
			Singleton = GetStaticEnum(Z_Construct_UEnum_FastArenaShooter_TypeOfWeapon, Z_Construct_UPackage__Script_FastArenaShooter(), TEXT("TypeOfWeapon"));
		}
		return Singleton;
	}
	template<> FASTARENASHOOTER_API UEnum* StaticEnum<TypeOfWeapon>()
	{
		return TypeOfWeapon_StaticEnum();
	}
	static FCompiledInDeferEnum Z_CompiledInDeferEnum_UEnum_TypeOfWeapon(TypeOfWeapon_StaticEnum, TEXT("/Script/FastArenaShooter"), TEXT("TypeOfWeapon"), false, nullptr, nullptr);
	uint32 Get_Z_Construct_UEnum_FastArenaShooter_TypeOfWeapon_Hash() { return 1239686438U; }
	UEnum* Z_Construct_UEnum_FastArenaShooter_TypeOfWeapon()
	{
#if WITH_HOT_RELOAD
		UPackage* Outer = Z_Construct_UPackage__Script_FastArenaShooter();
		static UEnum* ReturnEnum = FindExistingEnumIfHotReloadOrDynamic(Outer, TEXT("TypeOfWeapon"), 0, Get_Z_Construct_UEnum_FastArenaShooter_TypeOfWeapon_Hash(), false);
#else
		static UEnum* ReturnEnum = nullptr;
#endif // WITH_HOT_RELOAD
		if (!ReturnEnum)
		{
			static const UE4CodeGen_Private::FEnumeratorParam Enumerators[] = {
				{ "Riffle", (int64)Riffle },
				{ "Shotgun", (int64)Shotgun },
				{ "RocketLauncher", (int64)RocketLauncher },
			};
#if WITH_METADATA
			const UE4CodeGen_Private::FMetaDataPairParam Enum_MetaDataParams[] = {
				{ "ModuleRelativePath", "MyWeaponBehaviour.h" },
				{ "Riffle.Name", "Riffle" },
				{ "RocketLauncher.Name", "RocketLauncher" },
				{ "Shotgun.Name", "Shotgun" },
			};
#endif
			static const UE4CodeGen_Private::FEnumParams EnumParams = {
				(UObject*(*)())Z_Construct_UPackage__Script_FastArenaShooter,
				nullptr,
				"TypeOfWeapon",
				"TypeOfWeapon",
				Enumerators,
				UE_ARRAY_COUNT(Enumerators),
				RF_Public|RF_Transient|RF_MarkAsNative,
				EEnumFlags::None,
				UE4CodeGen_Private::EDynamicType::NotDynamic,
				(uint8)UEnum::ECppForm::Regular,
				METADATA_PARAMS(Enum_MetaDataParams, UE_ARRAY_COUNT(Enum_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUEnum(ReturnEnum, EnumParams);
		}
		return ReturnEnum;
	}
class UScriptStruct* FdataWeapon::StaticStruct()
{
	static class UScriptStruct* Singleton = NULL;
	if (!Singleton)
	{
		extern FASTARENASHOOTER_API uint32 Get_Z_Construct_UScriptStruct_FdataWeapon_Hash();
		Singleton = GetStaticStruct(Z_Construct_UScriptStruct_FdataWeapon, Z_Construct_UPackage__Script_FastArenaShooter(), TEXT("dataWeapon"), sizeof(FdataWeapon), Get_Z_Construct_UScriptStruct_FdataWeapon_Hash());
	}
	return Singleton;
}
template<> FASTARENASHOOTER_API UScriptStruct* StaticStruct<FdataWeapon>()
{
	return FdataWeapon::StaticStruct();
}
static FCompiledInDeferStruct Z_CompiledInDeferStruct_UScriptStruct_FdataWeapon(FdataWeapon::StaticStruct, TEXT("/Script/FastArenaShooter"), TEXT("dataWeapon"), false, nullptr, nullptr);
static struct FScriptStruct_FastArenaShooter_StaticRegisterNativesFdataWeapon
{
	FScriptStruct_FastArenaShooter_StaticRegisterNativesFdataWeapon()
	{
		UScriptStruct::DeferCppStructOps<FdataWeapon>(FName(TEXT("dataWeapon")));
	}
} ScriptStruct_FastArenaShooter_StaticRegisterNativesFdataWeapon;
	struct Z_Construct_UScriptStruct_FdataWeapon_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Struct_MetaDataParams[];
#endif
		static void* NewStructOps();
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__modelOfBullet_MetaData[];
#endif
		static const UE4CodeGen_Private::FClassPropertyParams NewProp__modelOfBullet;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__modelOfWeapon_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp__modelOfWeapon;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__gunOffset_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp__gunOffset;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__dmg_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp__dmg;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__speed_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp__speed;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__impactPower_MetaData[];
#endif
		static const UE4CodeGen_Private::FFloatPropertyParams NewProp__impactPower;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const UE4CodeGen_Private::FStructParams ReturnStructParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FdataWeapon_Statics::Struct_MetaDataParams[] = {
		{ "ModuleRelativePath", "MyWeaponBehaviour.h" },
	};
#endif
	void* Z_Construct_UScriptStruct_FdataWeapon_Statics::NewStructOps()
	{
		return (UScriptStruct::ICppStructOps*)new UScriptStruct::TCppStructOps<FdataWeapon>();
	}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FdataWeapon_Statics::NewProp__modelOfBullet_MetaData[] = {
		{ "Category", "Weapon Parameter" },
		{ "ModuleRelativePath", "MyWeaponBehaviour.h" },
	};
#endif
	const UE4CodeGen_Private::FClassPropertyParams Z_Construct_UScriptStruct_FdataWeapon_Statics::NewProp__modelOfBullet = { "_modelOfBullet", nullptr, (EPropertyFlags)0x0014000000010001, UE4CodeGen_Private::EPropertyGenFlags::Class, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FdataWeapon, _modelOfBullet), Z_Construct_UClass_AMyBulletsBehaviour_NoRegister, Z_Construct_UClass_UClass, METADATA_PARAMS(Z_Construct_UScriptStruct_FdataWeapon_Statics::NewProp__modelOfBullet_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FdataWeapon_Statics::NewProp__modelOfBullet_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FdataWeapon_Statics::NewProp__modelOfWeapon_MetaData[] = {
		{ "Category", "Weapon Parameter" },
		{ "ModuleRelativePath", "MyWeaponBehaviour.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FdataWeapon_Statics::NewProp__modelOfWeapon = { "_modelOfWeapon", nullptr, (EPropertyFlags)0x0010000000010001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FdataWeapon, _modelOfWeapon), Z_Construct_UClass_UStaticMesh_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FdataWeapon_Statics::NewProp__modelOfWeapon_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FdataWeapon_Statics::NewProp__modelOfWeapon_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FdataWeapon_Statics::NewProp__gunOffset_MetaData[] = {
		{ "Category", "Weapon Parameter" },
		{ "ModuleRelativePath", "MyWeaponBehaviour.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UScriptStruct_FdataWeapon_Statics::NewProp__gunOffset = { "_gunOffset", nullptr, (EPropertyFlags)0x0010000000010001, UE4CodeGen_Private::EPropertyGenFlags::Object, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FdataWeapon, _gunOffset), Z_Construct_UClass_AActor_NoRegister, METADATA_PARAMS(Z_Construct_UScriptStruct_FdataWeapon_Statics::NewProp__gunOffset_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FdataWeapon_Statics::NewProp__gunOffset_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FdataWeapon_Statics::NewProp__dmg_MetaData[] = {
		{ "Category", "Weapon Parameter" },
		{ "ModuleRelativePath", "MyWeaponBehaviour.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FdataWeapon_Statics::NewProp__dmg = { "_dmg", nullptr, (EPropertyFlags)0x0010000000010001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FdataWeapon, _dmg), METADATA_PARAMS(Z_Construct_UScriptStruct_FdataWeapon_Statics::NewProp__dmg_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FdataWeapon_Statics::NewProp__dmg_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FdataWeapon_Statics::NewProp__speed_MetaData[] = {
		{ "Category", "Weapon Parameter" },
		{ "ModuleRelativePath", "MyWeaponBehaviour.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FdataWeapon_Statics::NewProp__speed = { "_speed", nullptr, (EPropertyFlags)0x0010000000010001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FdataWeapon, _speed), METADATA_PARAMS(Z_Construct_UScriptStruct_FdataWeapon_Statics::NewProp__speed_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FdataWeapon_Statics::NewProp__speed_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UScriptStruct_FdataWeapon_Statics::NewProp__impactPower_MetaData[] = {
		{ "Category", "Weapon Parameter" },
		{ "ModuleRelativePath", "MyWeaponBehaviour.h" },
	};
#endif
	const UE4CodeGen_Private::FFloatPropertyParams Z_Construct_UScriptStruct_FdataWeapon_Statics::NewProp__impactPower = { "_impactPower", nullptr, (EPropertyFlags)0x0010000000010001, UE4CodeGen_Private::EPropertyGenFlags::Float, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(FdataWeapon, _impactPower), METADATA_PARAMS(Z_Construct_UScriptStruct_FdataWeapon_Statics::NewProp__impactPower_MetaData, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FdataWeapon_Statics::NewProp__impactPower_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UScriptStruct_FdataWeapon_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FdataWeapon_Statics::NewProp__modelOfBullet,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FdataWeapon_Statics::NewProp__modelOfWeapon,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FdataWeapon_Statics::NewProp__gunOffset,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FdataWeapon_Statics::NewProp__dmg,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FdataWeapon_Statics::NewProp__speed,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UScriptStruct_FdataWeapon_Statics::NewProp__impactPower,
	};
	const UE4CodeGen_Private::FStructParams Z_Construct_UScriptStruct_FdataWeapon_Statics::ReturnStructParams = {
		(UObject* (*)())Z_Construct_UPackage__Script_FastArenaShooter,
		nullptr,
		&NewStructOps,
		"dataWeapon",
		sizeof(FdataWeapon),
		alignof(FdataWeapon),
		Z_Construct_UScriptStruct_FdataWeapon_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FdataWeapon_Statics::PropPointers),
		RF_Public|RF_Transient|RF_MarkAsNative,
		EStructFlags(0x00000001),
		METADATA_PARAMS(Z_Construct_UScriptStruct_FdataWeapon_Statics::Struct_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UScriptStruct_FdataWeapon_Statics::Struct_MetaDataParams))
	};
	UScriptStruct* Z_Construct_UScriptStruct_FdataWeapon()
	{
#if WITH_HOT_RELOAD
		extern uint32 Get_Z_Construct_UScriptStruct_FdataWeapon_Hash();
		UPackage* Outer = Z_Construct_UPackage__Script_FastArenaShooter();
		static UScriptStruct* ReturnStruct = FindExistingStructIfHotReloadOrDynamic(Outer, TEXT("dataWeapon"), sizeof(FdataWeapon), Get_Z_Construct_UScriptStruct_FdataWeapon_Hash(), false);
#else
		static UScriptStruct* ReturnStruct = nullptr;
#endif
		if (!ReturnStruct)
		{
			UE4CodeGen_Private::ConstructUScriptStruct(ReturnStruct, Z_Construct_UScriptStruct_FdataWeapon_Statics::ReturnStructParams);
		}
		return ReturnStruct;
	}
	uint32 Get_Z_Construct_UScriptStruct_FdataWeapon_Hash() { return 714523803U; }
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
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__dataWeapon_MetaData[];
#endif
		static const UE4CodeGen_Private::FStructPropertyParams NewProp__dataWeapon;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp__typeOfWeapon_MetaData[];
#endif
		static const UE4CodeGen_Private::FBytePropertyParams NewProp__typeOfWeapon;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
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
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyWeaponBehaviour_Statics::NewProp__dataWeapon_MetaData[] = {
		{ "Category", "Weapon Parameter" },
		{ "ModuleRelativePath", "MyWeaponBehaviour.h" },
	};
#endif
	const UE4CodeGen_Private::FStructPropertyParams Z_Construct_UClass_AMyWeaponBehaviour_Statics::NewProp__dataWeapon = { "_dataWeapon", nullptr, (EPropertyFlags)0x0020080000010001, UE4CodeGen_Private::EPropertyGenFlags::Struct, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyWeaponBehaviour, _dataWeapon), Z_Construct_UScriptStruct_FdataWeapon, METADATA_PARAMS(Z_Construct_UClass_AMyWeaponBehaviour_Statics::NewProp__dataWeapon_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyWeaponBehaviour_Statics::NewProp__dataWeapon_MetaData)) };
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AMyWeaponBehaviour_Statics::NewProp__typeOfWeapon_MetaData[] = {
		{ "Category", "Weapon Parameter" },
		{ "ModuleRelativePath", "MyWeaponBehaviour.h" },
	};
#endif
	const UE4CodeGen_Private::FBytePropertyParams Z_Construct_UClass_AMyWeaponBehaviour_Statics::NewProp__typeOfWeapon = { "_typeOfWeapon", nullptr, (EPropertyFlags)0x0020080000010001, UE4CodeGen_Private::EPropertyGenFlags::Byte, RF_Public|RF_Transient|RF_MarkAsNative, 1, STRUCT_OFFSET(AMyWeaponBehaviour, _typeOfWeapon), Z_Construct_UEnum_FastArenaShooter_TypeOfWeapon, METADATA_PARAMS(Z_Construct_UClass_AMyWeaponBehaviour_Statics::NewProp__typeOfWeapon_MetaData, UE_ARRAY_COUNT(Z_Construct_UClass_AMyWeaponBehaviour_Statics::NewProp__typeOfWeapon_MetaData)) };
	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AMyWeaponBehaviour_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyWeaponBehaviour_Statics::NewProp__dataWeapon,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AMyWeaponBehaviour_Statics::NewProp__typeOfWeapon,
	};
	const FCppClassTypeInfoStatic Z_Construct_UClass_AMyWeaponBehaviour_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AMyWeaponBehaviour>::IsAbstract,
	};
	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AMyWeaponBehaviour_Statics::ClassParams = {
		&AMyWeaponBehaviour::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		Z_Construct_UClass_AMyWeaponBehaviour_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		0,
		UE_ARRAY_COUNT(Z_Construct_UClass_AMyWeaponBehaviour_Statics::PropPointers),
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
	IMPLEMENT_CLASS(AMyWeaponBehaviour, 3764260585);
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
