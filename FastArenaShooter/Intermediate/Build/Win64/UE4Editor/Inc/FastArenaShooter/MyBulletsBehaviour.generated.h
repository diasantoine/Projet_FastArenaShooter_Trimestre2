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
#ifdef FASTARENASHOOTER_MyBulletsBehaviour_generated_h
#error "MyBulletsBehaviour.generated.h already included, missing '#pragma once' in MyBulletsBehaviour.h"
#endif
#define FASTARENASHOOTER_MyBulletsBehaviour_generated_h

#define FastArenaShooter_Source_FastArenaShooter_MyBulletsBehaviour_h_15_GENERATED_BODY \
	friend struct Z_Construct_UScriptStruct_FBulletParameter_Statics; \
	FASTARENASHOOTER_API static class UScriptStruct* StaticStruct();


template<> FASTARENASHOOTER_API UScriptStruct* StaticStruct<struct FBulletParameter>();

#define FastArenaShooter_Source_FastArenaShooter_MyBulletsBehaviour_h_22_SPARSE_DATA
#define FastArenaShooter_Source_FastArenaShooter_MyBulletsBehaviour_h_22_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execOnHit);


#define FastArenaShooter_Source_FastArenaShooter_MyBulletsBehaviour_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execOnHit);


#define FastArenaShooter_Source_FastArenaShooter_MyBulletsBehaviour_h_22_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesAMyBulletsBehaviour(); \
	friend struct Z_Construct_UClass_AMyBulletsBehaviour_Statics; \
public: \
	DECLARE_CLASS(AMyBulletsBehaviour, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/FastArenaShooter"), NO_API) \
	DECLARE_SERIALIZER(AMyBulletsBehaviour)


#define FastArenaShooter_Source_FastArenaShooter_MyBulletsBehaviour_h_22_INCLASS \
private: \
	static void StaticRegisterNativesAMyBulletsBehaviour(); \
	friend struct Z_Construct_UClass_AMyBulletsBehaviour_Statics; \
public: \
	DECLARE_CLASS(AMyBulletsBehaviour, AActor, COMPILED_IN_FLAGS(0 | CLASS_Config), CASTCLASS_None, TEXT("/Script/FastArenaShooter"), NO_API) \
	DECLARE_SERIALIZER(AMyBulletsBehaviour)


#define FastArenaShooter_Source_FastArenaShooter_MyBulletsBehaviour_h_22_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API AMyBulletsBehaviour(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(AMyBulletsBehaviour) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyBulletsBehaviour); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyBulletsBehaviour); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMyBulletsBehaviour(AMyBulletsBehaviour&&); \
	NO_API AMyBulletsBehaviour(const AMyBulletsBehaviour&); \
public:


#define FastArenaShooter_Source_FastArenaShooter_MyBulletsBehaviour_h_22_ENHANCED_CONSTRUCTORS \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API AMyBulletsBehaviour(AMyBulletsBehaviour&&); \
	NO_API AMyBulletsBehaviour(const AMyBulletsBehaviour&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, AMyBulletsBehaviour); \
	DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(AMyBulletsBehaviour); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(AMyBulletsBehaviour)


#define FastArenaShooter_Source_FastArenaShooter_MyBulletsBehaviour_h_22_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__CollisionComp() { return STRUCT_OFFSET(AMyBulletsBehaviour, CollisionComp); } \
	FORCEINLINE static uint32 __PPO__ProjectileMovement() { return STRUCT_OFFSET(AMyBulletsBehaviour, ProjectileMovement); } \
	FORCEINLINE static uint32 __PPO___meshOfBullet() { return STRUCT_OFFSET(AMyBulletsBehaviour, _meshOfBullet); }


#define FastArenaShooter_Source_FastArenaShooter_MyBulletsBehaviour_h_19_PROLOG
#define FastArenaShooter_Source_FastArenaShooter_MyBulletsBehaviour_h_22_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FastArenaShooter_Source_FastArenaShooter_MyBulletsBehaviour_h_22_PRIVATE_PROPERTY_OFFSET \
	FastArenaShooter_Source_FastArenaShooter_MyBulletsBehaviour_h_22_SPARSE_DATA \
	FastArenaShooter_Source_FastArenaShooter_MyBulletsBehaviour_h_22_RPC_WRAPPERS \
	FastArenaShooter_Source_FastArenaShooter_MyBulletsBehaviour_h_22_INCLASS \
	FastArenaShooter_Source_FastArenaShooter_MyBulletsBehaviour_h_22_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define FastArenaShooter_Source_FastArenaShooter_MyBulletsBehaviour_h_22_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	FastArenaShooter_Source_FastArenaShooter_MyBulletsBehaviour_h_22_PRIVATE_PROPERTY_OFFSET \
	FastArenaShooter_Source_FastArenaShooter_MyBulletsBehaviour_h_22_SPARSE_DATA \
	FastArenaShooter_Source_FastArenaShooter_MyBulletsBehaviour_h_22_RPC_WRAPPERS_NO_PURE_DECLS \
	FastArenaShooter_Source_FastArenaShooter_MyBulletsBehaviour_h_22_INCLASS_NO_PURE_DECLS \
	FastArenaShooter_Source_FastArenaShooter_MyBulletsBehaviour_h_22_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


template<> FASTARENASHOOTER_API UClass* StaticClass<class AMyBulletsBehaviour>();

#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID FastArenaShooter_Source_FastArenaShooter_MyBulletsBehaviour_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
