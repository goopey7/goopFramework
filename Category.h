//Copyright Sam Collier 2022
#pragma once

// Each category will have one bit set to 1
// this allows us to use bitwise OR '|' to combine
// categories
// These are categories for Nodes/Actors for dispatching commands
namespace Category
{
	enum Type
	{
		None = 0,
		Scene = 1 << 0,
		PlayerCharacter = 1 << 1,
		Actor = 1 << 2,
		Enemy = 1 << 3,
		Shuriken = 1 << 4,
		EnemyBlock = 1 << 5,
		Bullet = 1 << 6,
		MenuPlayer = 1 << 7,
		OriginTP = 1 << 8,
		Pickup = 1 << 9,
		WinPickup = 1 << 10,
	};
}
// so for example
// unsigned int allNodes = Category::Scene | Category::PlayerCharacter;

