// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Car/CarMovementComponent.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCarMovementComponent() {}
// Cross Module References
	HOVERCARS_API UClass* Z_Construct_UClass_UCarMovementComponent_NoRegister();
	HOVERCARS_API UClass* Z_Construct_UClass_UCarMovementComponent();
	ENGINE_API UClass* Z_Construct_UClass_UNavMovementComponent();
	UPackage* Z_Construct_UPackage__Script_HoverCars();
	HOVERCARS_API UFunction* Z_Construct_UFunction_UCarMovementComponent_Initialise();
	HOVERCARS_API UClass* Z_Construct_UClass_UCarThruster_NoRegister();
	HOVERCARS_API UFunction* Z_Construct_UFunction_UCarMovementComponent_IntendMoveForward();
	HOVERCARS_API UFunction* Z_Construct_UFunction_UCarMovementComponent_IntendTurn();
// End Cross Module References
	void UCarMovementComponent::StaticRegisterNativesUCarMovementComponent()
	{
		UClass* Class = UCarMovementComponent::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "Initialise", (Native)&UCarMovementComponent::execInitialise },
			{ "IntendMoveForward", (Native)&UCarMovementComponent::execIntendMoveForward },
			{ "IntendTurn", (Native)&UCarMovementComponent::execIntendTurn },
		};
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, ARRAY_COUNT(Funcs));
	}
	UFunction* Z_Construct_UFunction_UCarMovementComponent_Initialise()
	{
		struct CarMovementComponent_eventInitialise_Parms
		{
			UCarThruster* FrontLeftThrusterToSet;
			UCarThruster* FrontRightThrusterToSet;
			UCarThruster* RearLeftThrusterToSet;
			UCarThruster* RearRightThrusterToSet;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RearRightThrusterToSet_MetaData[] = {
				{ "EditInline", "true" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_RearRightThrusterToSet = { UE4CodeGen_Private::EPropertyClass::Object, "RearRightThrusterToSet", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000080080, 1, nullptr, STRUCT_OFFSET(CarMovementComponent_eventInitialise_Parms, RearRightThrusterToSet), Z_Construct_UClass_UCarThruster_NoRegister, METADATA_PARAMS(NewProp_RearRightThrusterToSet_MetaData, ARRAY_COUNT(NewProp_RearRightThrusterToSet_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_RearLeftThrusterToSet_MetaData[] = {
				{ "EditInline", "true" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_RearLeftThrusterToSet = { UE4CodeGen_Private::EPropertyClass::Object, "RearLeftThrusterToSet", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000080080, 1, nullptr, STRUCT_OFFSET(CarMovementComponent_eventInitialise_Parms, RearLeftThrusterToSet), Z_Construct_UClass_UCarThruster_NoRegister, METADATA_PARAMS(NewProp_RearLeftThrusterToSet_MetaData, ARRAY_COUNT(NewProp_RearLeftThrusterToSet_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FrontRightThrusterToSet_MetaData[] = {
				{ "EditInline", "true" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_FrontRightThrusterToSet = { UE4CodeGen_Private::EPropertyClass::Object, "FrontRightThrusterToSet", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000080080, 1, nullptr, STRUCT_OFFSET(CarMovementComponent_eventInitialise_Parms, FrontRightThrusterToSet), Z_Construct_UClass_UCarThruster_NoRegister, METADATA_PARAMS(NewProp_FrontRightThrusterToSet_MetaData, ARRAY_COUNT(NewProp_FrontRightThrusterToSet_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_FrontLeftThrusterToSet_MetaData[] = {
				{ "EditInline", "true" },
			};
#endif
			static const UE4CodeGen_Private::FObjectPropertyParams NewProp_FrontLeftThrusterToSet = { UE4CodeGen_Private::EPropertyClass::Object, "FrontLeftThrusterToSet", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000080080, 1, nullptr, STRUCT_OFFSET(CarMovementComponent_eventInitialise_Parms, FrontLeftThrusterToSet), Z_Construct_UClass_UCarThruster_NoRegister, METADATA_PARAMS(NewProp_FrontLeftThrusterToSet_MetaData, ARRAY_COUNT(NewProp_FrontLeftThrusterToSet_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_RearRightThrusterToSet,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_RearLeftThrusterToSet,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_FrontRightThrusterToSet,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_FrontLeftThrusterToSet,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Setup" },
				{ "ModuleRelativePath", "Car/CarMovementComponent.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UCarMovementComponent, "Initialise", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(CarMovementComponent_eventInitialise_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UCarMovementComponent_IntendMoveForward()
	{
		struct CarMovementComponent_eventIntendMoveForward_Parms
		{
			float Throw;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Throw = { UE4CodeGen_Private::EPropertyClass::Float, "Throw", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(CarMovementComponent_eventIntendMoveForward_Parms, Throw), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Throw,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Input" },
				{ "ModuleRelativePath", "Car/CarMovementComponent.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UCarMovementComponent, "IntendMoveForward", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(CarMovementComponent_eventIntendMoveForward_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UFunction* Z_Construct_UFunction_UCarMovementComponent_IntendTurn()
	{
		struct CarMovementComponent_eventIntendTurn_Parms
		{
			float Throw;
		};
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_Throw = { UE4CodeGen_Private::EPropertyClass::Float, "Throw", RF_Public|RF_Transient|RF_MarkAsNative, 0x0010000000000080, 1, nullptr, STRUCT_OFFSET(CarMovementComponent_eventIntendTurn_Parms, Throw), METADATA_PARAMS(nullptr, 0) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_Throw,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[] = {
				{ "Category", "Input" },
				{ "ModuleRelativePath", "Car/CarMovementComponent.h" },
			};
#endif
			static const UE4CodeGen_Private::FFunctionParams FuncParams = { (UObject*(*)())Z_Construct_UClass_UCarMovementComponent, "IntendTurn", RF_Public|RF_Transient|RF_MarkAsNative, nullptr, (EFunctionFlags)0x04020401, sizeof(CarMovementComponent_eventIntendTurn_Parms), PropPointers, ARRAY_COUNT(PropPointers), 0, 0, METADATA_PARAMS(Function_MetaDataParams, ARRAY_COUNT(Function_MetaDataParams)) };
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_UCarMovementComponent_NoRegister()
	{
		return UCarMovementComponent::StaticClass();
	}
	UClass* Z_Construct_UClass_UCarMovementComponent()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_UNavMovementComponent,
				(UObject* (*)())Z_Construct_UPackage__Script_HoverCars,
			};
			static const FClassFunctionLinkInfo FuncInfo[] = {
				{ &Z_Construct_UFunction_UCarMovementComponent_Initialise, "Initialise" }, // 863853996
				{ &Z_Construct_UFunction_UCarMovementComponent_IntendMoveForward, "IntendMoveForward" }, // 2511008865
				{ &Z_Construct_UFunction_UCarMovementComponent_IntendTurn, "IntendTurn" }, // 1935030590
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "BlueprintSpawnableComponent", "" },
				{ "ClassGroupNames", "Custom" },
				{ "IncludePath", "Car/CarMovementComponent.h" },
				{ "ModuleRelativePath", "Car/CarMovementComponent.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_GroundedDistance_MetaData[] = {
				{ "Category", "Setup" },
				{ "ModuleRelativePath", "Car/CarMovementComponent.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_GroundedDistance = { UE4CodeGen_Private::EPropertyClass::Float, "GroundedDistance", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000010001, 1, nullptr, STRUCT_OFFSET(UCarMovementComponent, GroundedDistance), METADATA_PARAMS(NewProp_GroundedDistance_MetaData, ARRAY_COUNT(NewProp_GroundedDistance_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_SidewaysStabilizeAmount_MetaData[] = {
				{ "Category", "Setup" },
				{ "ClampMax", "1.0" },
				{ "ClampMin", "0" },
				{ "ModuleRelativePath", "Car/CarMovementComponent.h" },
				{ "ToolTip", "Amount of stabilizing force (0...1)" },
				{ "UIMax", "1.0" },
				{ "UIMin", "0.0" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_SidewaysStabilizeAmount = { UE4CodeGen_Private::EPropertyClass::Float, "SidewaysStabilizeAmount", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000010001, 1, nullptr, STRUCT_OFFSET(UCarMovementComponent, SidewaysStabilizeAmount), METADATA_PARAMS(NewProp_SidewaysStabilizeAmount_MetaData, ARRAY_COUNT(NewProp_SidewaysStabilizeAmount_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_GroundedDistance,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_SidewaysStabilizeAmount,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<UCarMovementComponent>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&UCarMovementComponent::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00B00084u,
				FuncInfo, ARRAY_COUNT(FuncInfo),
				PropPointers, ARRAY_COUNT(PropPointers),
				"Engine",
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UCarMovementComponent, 412813835);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UCarMovementComponent(Z_Construct_UClass_UCarMovementComponent, &UCarMovementComponent::StaticClass, TEXT("/Script/HoverCars"), TEXT("UCarMovementComponent"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCarMovementComponent);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
