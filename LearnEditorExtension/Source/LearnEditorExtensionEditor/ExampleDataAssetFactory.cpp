#include "ExampleDataAssetFactory.h"
#include "LearnEditorExtension/ExampleDataAsset.h"

UExampleDataAssetFactory::UExampleDataAssetFactory(class FObjectInitializer const& ObjectInitializer)
	: Super(ObjectInitializer)
{
	bCreateNew = true;
	bEditAfterNew = true;
	SupportedClass = UExampleDataAsset::StaticClass();
}

bool UExampleDataAssetFactory::ShouldShowInNewMenu() const
{
	return true;
}

UObject* UExampleDataAssetFactory::FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName,
	EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn)
{
	UExampleDataAsset* NewObjectAsset = NewObject<UExampleDataAsset>(InParent, InClass, InName, Flags | RF_Transactional);
	return NewObjectAsset;
}
