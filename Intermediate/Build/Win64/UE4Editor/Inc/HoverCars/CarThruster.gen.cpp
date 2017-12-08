// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "Car/CarThruster.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeCarThruster() {}
// Cross Module References
	HOVERCARS_API UClass* Z_Construct_UClass_UCarThruster_NoRegister();
	HOVERCARS_API UClass* Z_Construct_UClass_UCarThruster();
	ENGINE_API UClass* Z_Construct_UClass_UStaticMeshComponent();
	UPackage* Z_Construct_UPackage__Script_HoverCars();
// End Cross Module References
	void UCarThruster::StaticRegisterNativesUCarThruster()
	{
	}
	UClass* Z_Construct_UClass_UCarThruster_NoRegister()
	{
		return UCarThruster::StaticClass();
	}
	UClass* Z_Construct_UClass_UCarThruster()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_UStaticMeshComponent,
				(UObject* (*)())Z_Construct_UPackage__Script_HoverCars,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "BlueprintSpawnableComponent", "" },
				{ "ClassGroupNames", "Custom" },
				{ "HideCategories", "Object Activation Components|Activation Trigger" },
				{ "IncludePath", "Car/CarThruster.h" },
				{ "ModuleRelativePath", "Car/CarThruster.h" },
			};
#endif
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_ThrustPower_MetaData[] = {
				{ "Category", "Setup" },
				{ "ModuleRelativePath", "Car/CarThruster.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_ThrustPower = { UE4CodeGen_Private::EPropertyClass::Float, "ThrustPower", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000010001, 1, nullptr, STRUCT_OFFSET(UCarThruster, ThrustPower), METADATA_PARAMS(NewProp_ThrustPower_MetaData, ARRAY_COUNT(NewProp_ThrustPower_MetaData)) };
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam NewProp_HoverDistance_MetaData[] = {
				{ "Category", "Setup" },
				{ "ModuleRelativePath", "Car/CarThruster.h" },
			};
#endif
			static const UE4CodeGen_Private::FFloatPropertyParams NewProp_HoverDistance = { UE4CodeGen_Private::EPropertyClass::Float, "HoverDistance", RF_Public|RF_Transient|RF_MarkAsNative, 0x0040000000010001, 1, nullptr, STRUCT_OFFSET(UCarThruster, HoverDistance), METADATA_PARAMS(NewProp_HoverDistance_MetaData, ARRAY_COUNT(NewProp_HoverDistance_MetaData)) };
			static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[] = {
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_ThrustPower,
				(const UE4CodeGen_Private::FPropertyParamsBase*)&NewProp_HoverDistance,
			};
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<UCarThruster>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&UCarThruster::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00B01080u,
				nullptr, 0,
				PropPointers, ARRAY_COUNT(PropPointers),
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(UCarThruster, 1367784276);
	static FCompiledInDefer Z_CompiledInDefer_UClass_UCarThruster(Z_Construct_UClass_UCarThruster, &UCarThruster::StaticClass, TEXT("/Script/HoverCars"), TEXT("UCarThruster"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(UCarThruster);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
