// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef FASTARENASHOOTER_MyWeaponBehaviour_generated_h
#error "MyWeaponBehaviour.generated.h already included, missing '#pragma once' in MyWeaponBehaviour.h"
#endif
#define FASTARENASHOOTER_MyWeaponBehaviour_generated_h

#define FastArenaShooter_Source_FastArenaShooter_MyWeaponBehaviour_h_22_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FdataWeapon_Statics; \
	FASTARENASHOOTER_API static class UScriptStruct* StaticStruct();


template<> FASTARENASHOOTER_API UScriptStruct* StaticStruct<struct FdataWeapon>();

#define FastArenaShooter_Source_FastArenaShooter_MyWeaponBehaviour_h_41_SPARSE_DATA
#define FastArenaShooter_Source_FastArenaShooter_MyWeaponBehaviour_h_41_RPC_WRAPPERS
#define FastArenaShooter_Source_FastArenaShooter_MyWeaponBehaviour_h_41_RPC_WRAPPERS_NO_PURE_DECLS
#define FastArenaShooter_Source_FastArenaShooter_MyWeaponBehaviour_h_41_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMyWeaponBehaviour(); \
	friend struct Z_Construct_UClass_AMyWeaponBehaviour_Statics; \
public: \
	DECLARE_CLASS(AMyWeaponBehaviour, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/FastArenaShooter"), NO_API) \
	DECLARE_SERIALIZER(AMyWeaponBehaviour)


#define FastArenaShooter_Source_FastArenaShooter_MyWeaponBehaviour_h_41_INCLASS \
private: \
	static void StaticRegisterNativesAMyWeaponBehaviour(); \
	friend struct Z_Construct_UClass_AMyWeaponBehaviour_Statics; \
public: \
	DECLARE_CLASS(AMyWeaponBehaviour, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/FastArenaShooter"), NO_API) \
	DECLARE_SERIALIZER(AMyWeaponBehaviour)


#define FastArenaShooter_Source_FastArenaShooter_MyWeaponBehaviour_h_41_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMyWeaponBehaviour(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMyWeaponBehaviour) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyWeaponBehaviour); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyWeaponBehaviour); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMyWeaponBehaviour(AMyWeaponBehaviour&&); \
	NO_API AMyWeaponBehaviour(const AMyWeaponBehaviour&); \
public:


#define FastArenaShooter_Source_FastArenaShooter_MyWeaponBehaviour_h_41_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMyWeaponBehaviour(AMyWeaponBehaviour&&); \
	NO_API AMyWeaponBehaviour(const AMyWeaponBehaviour&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyWeaponBehaviour); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyWeaponBehaviour); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMyWeaponBehaviour)


#define FastArenaShooter_Source_FastArenaShooter_MyWeaponBehaviour_h_41_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO___dataWeapon() { return STRUCT_OFFSET(AMyWeaponBehaviour, _dataWeapon); } \
	FORCEINLINE static uint32 __PPO___typeOfWeapon() { return STRUCT_OFFSET(AMyWeaponBehaviour, _typeOfWeapon); }


#define FastArenaShooter_Source_FastArenaShooter_MyWeaponBehaviour_h_38_PROLOG
#define FastArenaShooter_Source_FastArenaShooter_MyWeaponBehaviour_h_41_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FastArenaShooter_Source_FastArenaShooter_MyWeaponBehaviour_h_41_PRIVATE_PROPERTY_OFFSET \
	FastArenaShooter_Source_FastArenaShooter_MyWeaponBehaviour_h_41_SPARSE_DATA \
	FastArenaShooter_Source_FastArenaShooter_MyWeaponBehaviour_h_41_RPC_WRAPPERS \
	FastArenaShooter_Source_FastArenaShooter_MyWeaponBehaviour_h_41_INCLASS \
	FastArenaShooter_Source_FastArenaShooter_MyWeaponBehaviour_h_41_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FastArenaShooter_Source_FastArenaShooter_MyWeaponBehaviour_h_41_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FastArenaShooter_Source_FastArenaShooter_MyWeaponBehaviour_h_41_PRIVATE_PROPERTY_OFFSET \
	FastArenaShooter_Source_FastArenaShooter_MyWeaponBehaviour_h_41_SPARSE_DATA \
	FastArenaShooter_Source_FastArenaShooter_MyWeaponBehaviour_h_41_RPC_WRAPPERS_NO_PURE_DECLS \
	FastArenaShooter_Source_FastArenaShooter_MyWeaponBehaviour_h_41_INCLASS_NO_PURE_DECLS \
	FastArenaShooter_Source_FastArenaShooter_MyWeaponBehaviour_h_41_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FASTARENASHOOTER_API UClass* StaticClass<class AMyWeaponBehaviour>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FastArenaShooter_Source_FastArenaShooter_MyWeaponBehaviour_h


#define FOREACH_ENUM_TYPEOFWEAPON(op) \
	op(Riffle) \
	op(Shotgun) \
	op(RocketLauncher) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
