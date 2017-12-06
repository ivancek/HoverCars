// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
class AActor;
#ifdef HOVERCARS_CarAIController_generated_h
#error "CarAIController.generated.h already included, missing '#pragma once' in CarAIController.h"
#endif
#define HOVERCARS_CarAIController_generated_h

#define HoverCars_Source_HoverCars_Car_CarAIController_h_17_RPC_WRAPPERS \
 \
	DECLARE_FUNCTION(execSetTargets) \
	{ \
		P_GET_TARRAY(AActor*,Z_Param_TargetsToSet); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SetTargets(Z_Param_TargetsToSet); \
		P_NATIVE_END; \
	}


#define HoverCars_Source_HoverCars_Car_CarAIController_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
 \
	DECLARE_FUNCTION(execSetTargets) \
	{ \
		P_GET_TARRAY(AActor*,Z_Param_TargetsToSet); \
		P_FINISH; \
		P_NATIVE_BEGIN; \
		this->SetTargets(Z_Param_TargetsToSet); \
		P_NATIVE_END; \
	}


#define HoverCars_Source_HoverCars_Car_CarAIController_h_17_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACarAIController(); \
	friend HOVERCARS_API class UClass* Z_Construct_UClass_ACarAIController(); \
public: \
	DECLARE_CLASS(ACarAIController, AAIController, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/HoverCars"), NO_API) \
	DECLARE_SERIALIZER(ACarAIController) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define HoverCars_Source_HoverCars_Car_CarAIController_h_17_INCLASS \
private: \
	static void StaticRegisterNativesACarAIController(); \
	friend HOVERCARS_API class UClass* Z_Construct_UClass_ACarAIController(); \
public: \
	DECLARE_CLASS(ACarAIController, AAIController, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/HoverCars"), NO_API) \
	DECLARE_SERIALIZER(ACarAIController) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define HoverCars_Source_HoverCars_Car_CarAIController_h_17_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ACarAIController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ACarAIController) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACarAIController); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACarAIController); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACarAIController(ACarAIController&&); \
	NO_API ACarAIController(const ACarAIController&); \
public:


#define HoverCars_Source_HoverCars_Car_CarAIController_h_17_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ACarAIController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACarAIController(ACarAIController&&); \
	NO_API ACarAIController(const ACarAIController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACarAIController); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACarAIController); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ACarAIController)


#define HoverCars_Source_HoverCars_Car_CarAIController_h_17_PRIVATE_PROPERTY_OFFSET
#define HoverCars_Source_HoverCars_Car_CarAIController_h_14_PROLOG
#define HoverCars_Source_HoverCars_Car_CarAIController_h_17_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HoverCars_Source_HoverCars_Car_CarAIController_h_17_PRIVATE_PROPERTY_OFFSET \
	HoverCars_Source_HoverCars_Car_CarAIController_h_17_RPC_WRAPPERS \
	HoverCars_Source_HoverCars_Car_CarAIController_h_17_INCLASS \
	HoverCars_Source_HoverCars_Car_CarAIController_h_17_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define HoverCars_Source_HoverCars_Car_CarAIController_h_17_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HoverCars_Source_HoverCars_Car_CarAIController_h_17_PRIVATE_PROPERTY_OFFSET \
	HoverCars_Source_HoverCars_Car_CarAIController_h_17_RPC_WRAPPERS_NO_PURE_DECLS \
	HoverCars_Source_HoverCars_Car_CarAIController_h_17_INCLASS_NO_PURE_DECLS \
	HoverCars_Source_HoverCars_Car_CarAIController_h_17_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID HoverCars_Source_HoverCars_Car_CarAIController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
