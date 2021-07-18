#pragma once
#include"EngineMinimal.h"
#include "Modules/ModuleInterface.h"

class FLearnEditorExtensionEditorModule : public IModuleInterface {
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};