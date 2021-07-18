#include "ExampleDataEditorToolkit.h"
#define LOCTEXT_NAMESPACE "ExampleDataEditorToolkit"

const FName FExampleDataEditorToolkit::AppIdentifier(TEXT("ExampleAssetEditorApp"));

void FExampleDataEditorToolkit::RegisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)
{
    FAssetEditorToolkit::RegisterTabSpawners(InTabManager);

    InTabManager->RegisterTabSpawner(FName("TestTab"), FOnSpawnTab::CreateLambda(
        [&](const FSpawnTabArgs& Args)
    {
        return SNew(SDockTab)
            [
                SNew(STextBlock).Text(LOCTEXT("TestTab", "TestTab"))
            ];
    }
    ));
}

void FExampleDataEditorToolkit::UnregisterTabSpawners(const TSharedRef<FTabManager>& InTabManager)
{
    FAssetEditorToolkit::UnregisterTabSpawners(InTabManager);

    InTabManager->UnregisterTabSpawner(FName("TestTab"));
}

void FExampleDataEditorToolkit::InitMyObjectEditor(EToolkitMode::Type Mode,
	const TSharedPtr<IToolkitHost>& InitToolkitHost, UExampleDataAsset* Data)
{
    auto StandaloneDefaultLayout = FTabManager::NewLayout("Standalone_MyEditor_Layout")->AddArea
        (
            FTabManager::NewPrimaryArea()->Split(FTabManager::NewStack()->AddTab(FName("TestTab"), ETabState::OpenedTab))
        );
    InitAssetEditor(Mode, InitToolkitHost, AppIdentifier, StandaloneDefaultLayout, true, true, Data);
    RegenerateMenusAndToolbars();
}


#undef LOCTEXT_NAMESPACE