// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectMacros.h"
#include "ScriptMacros.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef HOVERCARS_CarPlayerController_generated_h
#error "CarPlayerController.generated.h already included, missing '#pragma once' in CarPlayerController.h"
#endif
#define HOVERCARS_CarPlayerController_generated_h

#define HoverCars_Source_HoverCars_Car_CarPlayerController_h_16_RPC_WRAPPERS
#define HoverCars_Source_HoverCars_Car_CarPlayerController_h_16_RPC_WRAPPERS_NO_PURE_DECLS
#define HoverCars_Source_HoverCars_Car_CarPlayerController_h_16_INCLASS_NO_PURE_DECLS \
private: \
	static void StaticRegisterNativesACarPlayerController(); \
	friend HOVERCARS_API class UClass* Z_Construct_UClass_ACarPlayerController(); \
public: \
	DECLARE_CLASS(ACarPlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), 0, TEXT("/Script/HoverCars"), NO_API) \
	DECLARE_SERIALIZER(ACarPlayerController) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define HoverCars_Source_HoverCars_Car_CarPlayerController_h_16_INCLASS \
private: \
	static void StaticRegisterNativesACarPlayerController(); \
	friend HOVERCARS_API class UClass* Z_Construct_UClass_ACarPlayerController(); \
public: \
	DECLARE_CLASS(ACarPlayerController, APlayerController, COMPILED_IN_FLAGS(0 | CLASS_Config), 0, TEXT("/Script/HoverCars"), NO_API) \
	DECLARE_SERIALIZER(ACarPlayerController) \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define HoverCars_Source_HoverCars_Car_CarPlayerController_h_16_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ACarPlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ACarPlayerController) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACarPlayerController); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACarPlayerController); \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACarPlayerController(ACarPlayerController&&); \
	NO_API ACarPlayerController(const ACarPlayerController&); \
public:


#define HoverCars_Source_HoverCars_Car_CarPlayerController_h_16_ENHANCED_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API ACarPlayerController(const FObjectInitializer& ObjectInitializer = FObjectInitializer::Get()) : Super(ObjectInitializer) { }; \
private: \
	/** Private move- and copy-constructors, should never be used */ \
	NO_API ACarPlayerController(ACarPlayerController&&); \
	NO_API ACarPlayerController(const ACarPlayerController&); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, ACarPlayerController); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(ACarPlayerController); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(ACarPlayerController)


#define HoverCars_Source_HoverCars_Car_CarPlayerController_h_16_PRIVATE_PROPERTY_OFFSET
#define HoverCars_Source_HoverCars_Car_CarPlayerController_h_13_PROLOG
#define HoverCars_Source_HoverCars_Car_CarPlayerController_h_16_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HoverCars_Source_HoverCars_Car_CarPlayerController_h_16_PRIVATE_PROPERTY_OFFSET \
	HoverCars_Source_HoverCars_Car_CarPlayerController_h_16_RPC_WRAPPERS \
	HoverCars_Source_HoverCars_Car_CarPlayerController_h_16_INCLASS \
	HoverCars_Source_HoverCars_Car_CarPlayerController_h_16_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define HoverCars_Source_HoverCars_Car_CarPlayerController_h_16_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	HoverCars_Source_HoverCars_Car_CarPlayerController_h_16_PRIVATE_PROPERTY_OFFSET \
	HoverCars_Source_HoverCars_Car_CarPlayerController_h_16_RPC_WRAPPERS_NO_PURE_DECLS \
	HoverCars_Source_HoverCars_Car_CarPlayerController_h_16_INCLASS_NO_PURE_DECLS \
	HoverCars_Source_HoverCars_Car_CarPlayerController_h_16_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID HoverCars_Source_HoverCars_Car_CarPlayerController_h


PRAGMA_ENABLE_DEPRECATION_WARNINGS
