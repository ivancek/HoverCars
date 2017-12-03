// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "GeneratedCppIncludes.h"
#include "HoverCarsGameModeBase.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeHoverCarsGameModeBase() {}
// Cross Module References
	HOVERCARS_API UClass* Z_Construct_UClass_AHoverCarsGameModeBase_NoRegister();
	HOVERCARS_API UClass* Z_Construct_UClass_AHoverCarsGameModeBase();
	ENGINE_API UClass* Z_Construct_UClass_AGameModeBase();
	UPackage* Z_Construct_UPackage__Script_HoverCars();
// End Cross Module References
	void AHoverCarsGameModeBase::StaticRegisterNativesAHoverCarsGameModeBase()
	{
	}
	UClass* Z_Construct_UClass_AHoverCarsGameModeBase_NoRegister()
	{
		return AHoverCarsGameModeBase::StaticClass();
	}
	UClass* Z_Construct_UClass_AHoverCarsGameModeBase()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			static UObject* (*const DependentSingletons[])() = {
				(UObject* (*)())Z_Construct_UClass_AGameModeBase,
				(UObject* (*)())Z_Construct_UPackage__Script_HoverCars,
			};
#if WITH_METADATA
			static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[] = {
				{ "HideCategories", "Info Rendering MovementReplication Replication Actor Input Movement Collision Rendering Utilities|Transformation" },
				{ "IncludePath", "HoverCarsGameModeBase.h" },
				{ "ModuleRelativePath", "HoverCarsGameModeBase.h" },
				{ "ShowCategories", "Input|MouseInput Input|TouchInput" },
			};
#endif
			static const FCppClassTypeInfoStatic StaticCppClassTypeInfo = {
				TCppClassTypeTraits<AHoverCarsGameModeBase>::IsAbstract,
			};
			static const UE4CodeGen_Private::FClassParams ClassParams = {
				&AHoverCarsGameModeBase::StaticClass,
				DependentSingletons, ARRAY_COUNT(DependentSingletons),
				0x00900288u,
				nullptr, 0,
				nullptr, 0,
				nullptr,
				&StaticCppClassTypeInfo,
				nullptr, 0,
				METADATA_PARAMS(Class_MetaDataParams, ARRAY_COUNT(Class_MetaDataParams))
			};
			UE4CodeGen_Private::ConstructUClass(OuterClass, ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AHoverCarsGameModeBase, 359550078);
	static FCompiledInDefer Z_CompiledInDefer_UClass_AHoverCarsGameModeBase(Z_Construct_UClass_AHoverCarsGameModeBase, &AHoverCarsGameModeBase::StaticClass, TEXT("/Script/HoverCars"), TEXT("AHoverCarsGameModeBase"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AHoverCarsGameModeBase);
PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
