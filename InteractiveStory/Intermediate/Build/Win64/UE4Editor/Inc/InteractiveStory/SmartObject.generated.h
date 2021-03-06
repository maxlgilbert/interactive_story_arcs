// Copyright 1998-2016 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	C++ class header boilerplate exported from UnrealHeaderTool.
	This is automatically generated by the tools.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "ObjectBase.h"

PRAGMA_DISABLE_DEPRECATION_WARNINGS
#ifdef INTERACTIVESTORY_SmartObject_generated_h
#error "SmartObject.generated.h already included, missing '#pragma once' in SmartObject.h"
#endif
#define INTERACTIVESTORY_SmartObject_generated_h

#define InteractiveStory_Source_InteractiveStory_SmartObject_h_20_RPC_WRAPPERS
#define InteractiveStory_Source_InteractiveStory_SmartObject_h_20_RPC_WRAPPERS_NO_PURE_DECLS
#define InteractiveStory_Source_InteractiveStory_SmartObject_h_20_INCLASS_NO_PURE_DECLS \
	private: \
	static void StaticRegisterNativesUSmartObject(); \
	friend INTERACTIVESTORY_API class UClass* Z_Construct_UClass_USmartObject(); \
	public: \
	DECLARE_CLASS(USmartObject, UActorComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/InteractiveStory"), NO_API) \
	DECLARE_SERIALIZER(USmartObject) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define InteractiveStory_Source_InteractiveStory_SmartObject_h_20_INCLASS \
	private: \
	static void StaticRegisterNativesUSmartObject(); \
	friend INTERACTIVESTORY_API class UClass* Z_Construct_UClass_USmartObject(); \
	public: \
	DECLARE_CLASS(USmartObject, UActorComponent, COMPILED_IN_FLAGS(0), 0, TEXT("/Script/InteractiveStory"), NO_API) \
	DECLARE_SERIALIZER(USmartObject) \
	/** Indicates whether the class is compiled into the engine */ \
	enum {IsIntrinsic=COMPILED_IN_INTRINSIC};


#define InteractiveStory_Source_InteractiveStory_SmartObject_h_20_STANDARD_CONSTRUCTORS \
	/** Standard constructor, called after all reflected properties have been initialized */ \
	NO_API USmartObject(const FObjectInitializer& ObjectInitializer); \
	DEFINE_DEFAULT_OBJECT_INITIALIZER_CONSTRUCTOR_CALL(USmartObject) \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USmartObject); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USmartObject); \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API USmartObject(const USmartObject& InCopy); \
public:


#define InteractiveStory_Source_InteractiveStory_SmartObject_h_20_ENHANCED_CONSTRUCTORS \
private: \
	/** Private copy-constructor, should never be used */ \
	NO_API USmartObject(const USmartObject& InCopy); \
public: \
	DECLARE_VTABLE_PTR_HELPER_CTOR(NO_API, USmartObject); \
DEFINE_VTABLE_PTR_HELPER_CTOR_CALLER(USmartObject); \
	DEFINE_DEFAULT_CONSTRUCTOR_CALL(USmartObject)


#define InteractiveStory_Source_InteractiveStory_SmartObject_h_17_PROLOG
#define InteractiveStory_Source_InteractiveStory_SmartObject_h_20_GENERATED_BODY_LEGACY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	InteractiveStory_Source_InteractiveStory_SmartObject_h_20_RPC_WRAPPERS \
	InteractiveStory_Source_InteractiveStory_SmartObject_h_20_INCLASS \
	InteractiveStory_Source_InteractiveStory_SmartObject_h_20_STANDARD_CONSTRUCTORS \
public: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#define InteractiveStory_Source_InteractiveStory_SmartObject_h_20_GENERATED_BODY \
PRAGMA_DISABLE_DEPRECATION_WARNINGS \
public: \
	InteractiveStory_Source_InteractiveStory_SmartObject_h_20_RPC_WRAPPERS_NO_PURE_DECLS \
	InteractiveStory_Source_InteractiveStory_SmartObject_h_20_INCLASS_NO_PURE_DECLS \
	InteractiveStory_Source_InteractiveStory_SmartObject_h_20_ENHANCED_CONSTRUCTORS \
private: \
PRAGMA_ENABLE_DEPRECATION_WARNINGS


#undef CURRENT_FILE_ID
#define CURRENT_FILE_ID InteractiveStory_Source_InteractiveStory_SmartObject_h


#define FOREACH_ENUM_ESMARTOBJECTTYPEENUM(op) \
	op(ESmartObjectTypeEnum::SOTE_Ball) \
	op(ESmartObjectTypeEnum::SOTE_Bear) 
PRAGMA_ENABLE_DEPRECATION_WARNINGS
