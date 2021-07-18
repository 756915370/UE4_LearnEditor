#include "LearnEditorExtensionEditorModule.h"


#include "AssetToolsModule.h"
#include "ExampleDataAssetTypeActions.h"
#include "LearnEditorExtensionEditorPCH.h"

#include "Modules/ModuleManager.h"
#define LOCTEXT_NAMESPACE "AssetTypeActions"
IMPLEMENT_MODULE(FLearnEditorExtensionEditorModule, LearnEditorExtensionEditor);

void FLearnEditorExtensionEditorModule::StartupModule()
{
	IAssetTools& AssetTools = FModuleManager::LoadModuleChecked<FAssetToolsModule>("AssetTools").Get();
	EAssetTypeCategories::Type MyAssetCategoryBit = AssetTools.RegisterAdvancedAssetCategory(FName(TEXT("MyAssetCategory")),
		LOCTEXT("MyCategoryName", "MyData"));
	AssetTools.RegisterAssetTypeActions(MakeShareable(new FExampleDataAssetTypeActions(MyAssetCategoryBit)));
}

void FLearnEditorExtensionEditorModule::ShutdownModule()
{
}

#undef LOCTEXT_NAMESPACE
