#include "ExampleDataAssetTypeActions.h"

#include "ExampleDataEditorToolkit.h"

void FExampleDataAssetTypeActions::OpenAssetEditor(const TArray<UObject*>& InObjects,
                                                   TSharedPtr<IToolkitHost> EditWithinLevelEditor)
{
	UE_LOG(LogTemp, Warning, TEXT("OpenAssetEditor"));
	for (auto ObjIt = InObjects.CreateConstIterator(); ObjIt; ++ObjIt)
	{
		if(UExampleDataAsset* ExampleData = Cast<UExampleDataAsset>(*ObjIt))
		{
			TSharedRef<FExampleDataEditorToolkit> Editor = MakeShared<FExampleDataEditorToolkit>();
			Editor->InitMyObjectEditor(EToolkitMode::Standalone, EditWithinLevelEditor, ExampleData);
		}
	}
}
