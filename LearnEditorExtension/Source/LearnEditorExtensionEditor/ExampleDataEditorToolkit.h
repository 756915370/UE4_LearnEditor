#pragma once

#include "LearnEditorExtension/ExampleDataAsset.h"

#define LOCTEXT_NAMESPACE "AssetTypeActions"
class FExampleDataEditorToolkit : public FAssetEditorToolkit
{
public:
	virtual FName GetToolkitFName() const override {
		return FName("MyAssetEditor");
	}

	virtual FLinearColor GetWorldCentricTabColorScale() const override
	{
		return FLinearColor::White;
	}

	virtual FText GetBaseToolkitName() const override
	{
		return LOCTEXT("BaseToolKitName", "MyDataEditor");
	}

	virtual FString GetWorldCentricTabPrefix() const override
	{
		return "TabPrefix";
	}

	//���������ܽ�TabManager�������������ļ����ظ����ᱨ��declaration of 'TabManager' hides class member
	virtual void RegisterTabSpawners(const TSharedRef<FTabManager>& InTabManager) override;
	virtual void UnregisterTabSpawners(const TSharedRef<FTabManager>& InTabManager) override;
	void InitMyObjectEditor(EToolkitMode::Type Mode, const TSharedPtr<IToolkitHost>& InitToolkitHost, UExampleDataAsset* Data);

	static const FName AppIdentifier;
};

#undef LOCTEXT_NAMESPACE
