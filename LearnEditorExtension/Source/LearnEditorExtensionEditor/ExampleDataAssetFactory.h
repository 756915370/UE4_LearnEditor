#pragma once
#include "Engine.h"
#include "ExampleDataAssetFactory.generated.h"

//https://zhuanlan.zhihu.com/p/41332747
UCLASS()
class UExampleDataAssetFactory : public UFactory
{
	GENERATED_UCLASS_BODY()

public:
	virtual bool ShouldShowInNewMenu() const override;
	virtual UObject* FactoryCreateNew(UClass* InClass, UObject* InParent, FName InName, EObjectFlags Flags, UObject* Context, FFeedbackContext* Warn) override;
};