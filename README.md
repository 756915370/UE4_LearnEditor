# UE4_LearnEditor
### 本工程实现了以下功能：
- 在菜单下创建继承自UObject的自定义资源类型。（通常我们是继承自UDataAsset的，但是直接继承自UObject可以有更高的自由度。）  
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210719004331946.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2o3NTY5MTUzNzA=,size_16,color_FFFFFF,t_70#pic_center)


- 点击自定义资源类型可以打开自定义的编辑器界面。（这意味着可以完全自定义编辑器界面，当然目前实现的功能极其简单，只会显示一个Text。）  
![在这里插入图片描述](https://img-blog.csdnimg.cn/20210719004340994.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L2o3NTY5MTUzNzA=,size_16,color_FFFFFF,t_70#pic_center)


### 学习资料
[【UE4】编辑器开发（三）资源类型拓展](https://zhuanlan.zhihu.com/p/135315547)  

[UE4项目记录（十一）自定义资源](https://zhuanlan.zhihu.com/p/41332747)  

《大象无形 虚幻引擎程序设计浅析》 第16章  

### 知识点记录
因为编辑器扩展的代码只会在编辑器下跑，所以通常是放在Editor模块。这个功能主要涉及了四个类：
- **UExampleDataAssetFactory**，继承自UFactory，作用是编辑器下生成你的UObject
- **FLearnEditorExtensionEditorModule**，自定义模块类，继承自**IModuleInterface**，我们的老朋友。自定义模块时必须有这个类。这次我们需要在它的**StartupModule**注册菜单目录，还需要注册我们自定义的**AssetTypeActions**类。
- **FExampleDataAssetTypeActions**，自定义资源操作类，继承自**FAssetTypeActions_Base**。最重要的两个函数：
	- **GetSupportedClass()**：要操作哪个资源类型
	- **OpenAssetEditor()**：双击资源时要做什么事情，在这里要定义我们创建的**AssetEditorToolkit**。注意传入的参数是**TArray<UObject*>**。因为点击资源时是可用复数选中的。
- **FExampleDataEditorToolkit** ：自定义资源编辑器实例类，继承自**FAssetEditorToolkit**。这个类里我们需要使用Slate语法创建UI。同时需要实现初始化函数供FExampleDataAssetTypeActions的OpenAssetEditor()方法里调用。

### 遇到的问题记录
- **编译失败：declaration of 'TabManager' hides class member**。原因：方法参数名TabManager，和类名或类文件名重复。
- **编译失败：Super': is not a class or namespace name**。原因：Super只有继承自UObject的类才能用，非UObject子类使用**类名::方法名**来进行调用父类方法。可以看到在UObject的源码里用到这个宏：
```
#define DECLARE_CLASS( TClass, TSuperClass, TStaticFlags, TStaticCastFlags, TPackage, TRequiredAPI  ) \
private: \
    TClass& operator=(TClass&&);   \
    TClass& operator=(const TClass&);   \
	TRequiredAPI static UClass* GetPrivateStaticClass(); \
```
- **编译失败：error LNK2019: unresolved external symbol "__declspec(dllimport) public: __cdecl FSlateColor（同时出现大量类似错误）**。原因：当前模块的.Build.cs里没有引入Slate相关模块。
- **在菜单中看不到自定义的资源类型。** 原因：在UE4.25以后的版本，只创建UFactory菜单里是不会显示的，还必须实现自己的资源操作类FAssetTypeActions才行。
- **双击自定义资源时会卡在进度条，编辑器界面出不来。** 原因：抄《大象无形》里的代码写for循环时抄错了，书中使用了一种不太常见的写法，不太建议这么写，终止条件是指针不为空，每次循环时指针加1：
	```
	for (auto ObjIt = InObjects.CreateConstIterator(); ObjIt; ++ObjIt)
	```
	而在UE4源码里，我看到了一种更好的写法值得学习：
	```
	for(auto Objet : InObjects)
	```
