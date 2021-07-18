#pragma once
#include "AssetTypeActions_Base.h"
#include "LearnEditorExtension/ExampleDataAsset.h"

class FExampleDataAssetTypeActions : public FAssetTypeActions_Base
{
private:
	uint32 MyCategories;
public:
	FExampleDataAssetTypeActions(EAssetTypeCategories::Type InAssetCategory);
	// IAssetTypeActions Implementation
	virtual FText GetName() const override { return NSLOCTEXT("AssetTypeActions", "ExampleDataAssetTypeActions", "ExampleDataAsset"); }
	virtual FColor GetTypeColor() const override { return FColor::Green; }
	virtual UClass* GetSupportedClass() const override { return UExampleDataAsset::StaticClass(); }
	virtual void OpenAssetEditor(const TArray<UObject*>& InObjects, TSharedPtr<class IToolkitHost> EditWithinLevelEditor = TSharedPtr<IToolkitHost>()) override;
	virtual uint32 GetCategories() override { return MyCategories; }
};

inline FExampleDataAssetTypeActions::FExampleDataAssetTypeActions(EAssetTypeCategories::Type InAssetCategory)
{
	MyCategories = InAssetCategory;
}


