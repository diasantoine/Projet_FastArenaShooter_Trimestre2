// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class FastArenaShooter : ModuleRules
{
	public FastArenaShooter(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "AIModule", "UMG" });
#if WITH_EDITOR
		PublicDependencyModuleNames.AddRange(new string[] { "UMGEditor" });
#endif
	}
}
