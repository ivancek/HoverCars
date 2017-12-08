// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class UCarThruster;
#ifdef HOVERCARS_CarMovementComponent_generated_h
#error "CarMovementComponent.generated.h already included, missing '#pragma once' in CarMovementComponent.h"
#endif
#define HOVERCARS_CarMovementComponent_generated_h

#define HoverCars_Source_HoverCars_Car_CarMovementComponent_h_16_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execIntendTurn) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Throw); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->IntendTurn(Z_Param_Throw); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIntendMoveForward) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Throw); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->IntendMoveForward(Z_Param_Throw); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execInitialise) \
	{ \
		P_GET_OBJECT(UCarThruster,Z_Param_FrontLeftThrusterToSet); \
		P_GET_OBJECT(UCarThruster,Z_Param_FrontRightThrusterToSet); \
		P_GET_OBJECT(UCarThruster,Z_Param_RearLeftThrusterToSet); \
		P_GET_OBJECT(UCarThruster,Z_Param_RearRightThrusterToSet); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->Initialise(Z_Param_FrontLeftThrusterToSet,Z_Param_FrontRightThrusterToSet,Z_Param_RearLeftThrusterToSet,Z_Param_RearRightThrusterToSet); \
		P_NATIVE_END; \
	}


#define HoverCars_Source_HoverCars_Car_CarMovementComponent_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execIntendTurn) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Throw); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->IntendTurn(Z_Param_Throw); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execIntendMoveForward) \
	{ \
		P_GET_PROPERTY(UFloatProperty,Z_Param_Throw); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->IntendMoveForward(Z_Param_Throw); \
		P_NATIVE_END; \
	} \
 \
	DECLARE_FUNCTION(execInitialise) \
	{ \
		P_GET_OBJECT(UCarThruster,Z_Param_FrontLeftThrusterToSet); \
		P_GET_OBJECT(UCarThruster,Z_Param_FrontRightThrusterToSet); \
		P_GET_OBJECT(UCarThruster,Z_Param_RearLeftThrusterToSet); \
		P_GET_OBJECT(UCarThruster,Z_Param_RearRightThrusterToSet); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->Initialise(Z_Param_FrontLeftThrusterToSet,Z_Param_FrontRightThrusterToSet,Z_Param_RearLeftThrusterToSet,Z_Param_RearRightThrusterToSet); \
		P_NATIVE_END; \
	}


#define HoverCars_Source_HoverCars_Car_CarMovementComponent_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesUCarMovementComponent(); \
	friend HOVERCARS_API class UClass* Z_Construct_UClass_UCarMovementComponent(); \
public: \
	DECLARE_CLASS(UCarMovementComponent, UNavMovementComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), 0, TEXT("/Script/HoverCars"), NO_API) \
	DECLARE_SERIALIZER(UCarMovementComponent) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define HoverCars_Source_HoverCars_Car_CarMovementComponent_h_16_INCLASS \
private: \
	static void StaticRegisterNativesUCarMovementComponent(); \
	friend HOVERCARS_API class UClass* Z_Construct_UClass_UCarMovementComponent(); \
public: \
	DECLARE_CLASS(UCarMovementComponent, UNavMovementComponent, COMPILED_IN_FLAGS(0 | CLASS_Config), 0, TEXT("/Script/HoverCars"), NO_API) \
	DECLARE_SERIALIZER(UCarMovementComponent) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define HoverCars_Source_HoverCars_Car_CarMovementComponent_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCarMovementComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCarMovementComponent) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCarMovementComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCarMovementComponent); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCarMovementComponent(UCarMovementComponent&&); \
	NO_API UCarMovementComponent(const UCarMovementComponent&); \
public:


#define HoverCars_Source_HoverCars_Car_CarMovementComponent_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API UCarMovementComponent(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API UCarMovementComponent(UCarMovementComponent&&); \
	NO_API UCarMovementComponent(const UCarMovementComponent&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, UCarMovementComponent); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(UCarMovementComponent); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(UCarMovementComponent)


#define HoverCars_Source_HoverCars_Car_CarMovementComponent_h_16_PRIVATE_PROPERTY_OFFSET \
	FORCEINLINE static uint32 __PPO__SidewaysStabilizeAmount() { return STRUCT_OFFSET(UCarMovementComponent, SidewaysStabilizeAmount); } \
	FORCEINLINE static uint32 __PPO__GroundedDistance() { return STRUCT_OFFSET(UCarMovementComponent, GroundedDistance); } \
	FORCEINLINE static uint32 __PPO__TurnForce() { return STRUCT_OFFSET(UCarMovementComponent, TurnForce); }


#define HoverCars_Source_HoverCars_Car_CarMovementComponent_h_13_PROLOG
#define HoverCars_Source_HoverCars_Car_CarMovementComponent_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HoverCars_Source_HoverCars_Car_CarMovementComponent_h_16_PRIVATE_PROPERTY_OFFSET \
	HoverCars_Source_HoverCars_Car_CarMovementComponent_h_16_RPC_WRAPPERS \
	HoverCars_Source_HoverCars_Car_CarMovementComponent_h_16_INCLASS \
	HoverCars_Source_HoverCars_Car_CarMovementComponent_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define HoverCars_Source_HoverCars_Car_CarMovementComponent_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HoverCars_Source_HoverCars_Car_CarMovementComponent_h_16_PRIVATE_PROPERTY_OFFSET \
	HoverCars_Source_HoverCars_Car_CarMovementComponent_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	HoverCars_Source_HoverCars_Car_CarMovementComponent_h_16_INCLASS_NO_PURE_DECLS \
	HoverCars_Source_HoverCars_Car_CarMovementComponent_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID HoverCars_Source_HoverCars_Car_CarMovementComponent_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
