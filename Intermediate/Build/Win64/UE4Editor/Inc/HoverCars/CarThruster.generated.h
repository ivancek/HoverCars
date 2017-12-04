// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef HOVERCARS_CarThruster_generated_h
#error "CarThruster.generated.h already included, missing '#pragma once' in CarThruster.h"
#endif
#define HOVERCARS_CarThruster_generated_h

#define HoverCars_Source_HoverCars_Car_CarThruster_h_15_RPC_WRAPPERS
#define HoverCars_Source_HoverCars_Car_CarThruster_h_15_RPC_WRAPPERS_NO_PURE_DECLS
#define HoverCars_Source_HoverCars_Car_CarThruster_h_15_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCarThruster(); \
	friend HOVERCARS_API class UClass* Z_Construct_UClass_UCarThruster(); \
public: \
	DECLARE_CLASS(UCarThruster, UStaticMeshComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/HoverCars"), NO_API) \
	DECLARE_SERIALIZER(UCarThruster) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define HoverCars_Source_HoverCars_Car_CarThruster_h_15_INCLASS \
private: \
	static void StaticRegisterNativesUCarThruster(); \
	friend HOVERCARS_API class UClass* Z_Construct_UClass_UCarThruster(); \
public: \
	DECLARE_CLASS(UCarThruster, UStaticMeshComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/HoverCars"), NO_API) \
	DECLARE_SERIALIZER(UCarThruster) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define HoverCars_Source_HoverCars_Car_CarThruster_h_15_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCarThruster(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCarThruster) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCarThruster); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCarThruster); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCarThruster(UCarThruster&&); \
	NO_API UCarThruster(const UCarThruster&); \
public:


#define HoverCars_Source_HoverCars_Car_CarThruster_h_15_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCarThruster(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCarThruster(UCarThruster&&); \
	NO_API UCarThruster(const UCarThruster&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCarThruster); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCarThruster); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCarThruster)


#define HoverCars_Source_HoverCars_Car_CarThruster_h_15_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__HoverDistance() { return STRUCT_OFFSET(UCarThruster, HoverDistance); } \
	FORCEINLINE static uint32 __PPO__ThrustPower() { return STRUCT_OFFSET(UCarThruster, ThrustPower); }


#define HoverCars_Source_HoverCars_Car_CarThruster_h_12_PROLOG
#define HoverCars_Source_HoverCars_Car_CarThruster_h_15_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HoverCars_Source_HoverCars_Car_CarThruster_h_15_PRIVATE_PROPERTY_OFFSET \
	HoverCars_Source_HoverCars_Car_CarThruster_h_15_RPC_WRAPPERS \
	HoverCars_Source_HoverCars_Car_CarThruster_h_15_INCLASS \
	HoverCars_Source_HoverCars_Car_CarThruster_h_15_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define HoverCars_Source_HoverCars_Car_CarThruster_h_15_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HoverCars_Source_HoverCars_Car_CarThruster_h_15_PRIVATE_PROPERTY_OFFSET \
	HoverCars_Source_HoverCars_Car_CarThruster_h_15_RPC_WRAPPERS_NO_PURE_DECLS \
	HoverCars_Source_HoverCars_Car_CarThruster_h_15_INCLASS_NO_PURE_DECLS \
	HoverCars_Source_HoverCars_Car_CarThruster_h_15_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID HoverCars_Source_HoverCars_Car_CarThruster_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
