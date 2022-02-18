// Copyright Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/ObjectMacros.h"
#include "UObject/ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UPrimitiveComponent;
class AActor;
struct FVector;
struct FHitResult;
#ifdef FASTARENASHOOTER_FastArenaShooterProjectile_generated_h
#error "FastArenaShooterProjectile.generated.h already included, missing '#pragma once' in FastArenaShooterProjectile.h"
#endif
#define FASTARENASHOOTER_FastArenaShooterProjectile_generated_h

#define FastArenaShooter_Source_FastArenaShooter_FastArenaShooterProjectile_h_15_SPARSE_DATA
#define FastArenaShooter_Source_FastArenaShooter_FastArenaShooterProjectile_h_15_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnHit);


#define FastArenaShooter_Source_FastArenaShooter_FastArenaShooterProjectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnHit);


#define FastArenaShooter_Source_FastArenaShooter_FastArenaShooterProjectile_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAFastArenaShooterProjectile(); \
	friend struct Z_Construct_UClass_AFastArenaShooterProjectile_Statics; \
public: \
	DECLARE_CLASS(AFastArenaShooterProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/FastArenaShooter"), NO_API) \
	DECLARE_SERIALIZER(AFastArenaShooterProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define FastArenaShooter_Source_FastArenaShooter_FastArenaShooterProjectile_h_15_INCLASS \
private: \
	static void StaticRegisterNativesAFastArenaShooterProjectile(); \
	friend struct Z_Construct_UClass_AFastArenaShooterProjectile_Statics; \
public: \
	DECLARE_CLASS(AFastArenaShooterProjectile, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/FastArenaShooter"), NO_API) \
	DECLARE_SERIALIZER(AFastArenaShooterProjectile) \
	static const TCHAR* StaticConfigName() {return TEXT("Game");} \



#define FastArenaShooter_Source_FastArenaShooter_FastArenaShooterProjectile_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AFastArenaShooterProjectile(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AFastArenaShooterProjectile) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFastArenaShooterProjectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFastArenaShooterProjectile); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFastArenaShooterProjectile(AFastArenaShooterProjectile&&); \
	NO_API AFastArenaShooterProjectile(const AFastArenaShooterProjectile&); \
public:


#define FastArenaShooter_Source_FastArenaShooter_FastArenaShooterProjectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AFastArenaShooterProjectile(AFastArenaShooterProjectile&&); \
	NO_API AFastArenaShooterProjectile(const AFastArenaShooterProjectile&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AFastArenaShooterProjectile); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AFastArenaShooterProjectile); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AFastArenaShooterProjectile)


#define FastArenaShooter_Source_FastArenaShooter_FastArenaShooterProjectile_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CollisionComp() { return STRUCT_OFFSET(AFastArenaShooterProjectile, CollisionComp); } \
	FORCEINLINE static uint32 __PPO__ProjectileMovement() { return STRUCT_OFFSET(AFastArenaShooterProjectile, ProjectileMovement); }


#define FastArenaShooter_Source_FastArenaShooter_FastArenaShooterProjectile_h_12_PROLOG
#define FastArenaShooter_Source_FastArenaShooter_FastArenaShooterProjectile_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FastArenaShooter_Source_FastArenaShooter_FastArenaShooterProjectile_h_15_PRIVATE_PROPERTY_OFFSET \
	FastArenaShooter_Source_FastArenaShooter_FastArenaShooterProjectile_h_15_SPARSE_DATA \
	FastArenaShooter_Source_FastArenaShooter_FastArenaShooterProjectile_h_15_RPC_WRAPPERS \
	FastArenaShooter_Source_FastArenaShooter_FastArenaShooterProjectile_h_15_INCLASS \
	FastArenaShooter_Source_FastArenaShooter_FastArenaShooterProjectile_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FastArenaShooter_Source_FastArenaShooter_FastArenaShooterProjectile_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FastArenaShooter_Source_FastArenaShooter_FastArenaShooterProjectile_h_15_PRIVATE_PROPERTY_OFFSET \
	FastArenaShooter_Source_FastArenaShooter_FastArenaShooterProjectile_h_15_SPARSE_DATA \
	FastArenaShooter_Source_FastArenaShooter_FastArenaShooterProjectile_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	FastArenaShooter_Source_FastArenaShooter_FastArenaShooterProjectile_h_15_INCLASS_NO_PURE_DECLS \
	FastArenaShooter_Source_FastArenaShooter_FastArenaShooterProjectile_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FASTARENASHOOTER_API UClass* StaticClass<class AFastArenaShooterProjectile>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FastArenaShooter_Source_FastArenaShooter_FastArenaShooterProjectile_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
