#include "skinchanger.h"
#include "skins.h"
#include <iostream>

#define precache_bayonet_ct 90
#define precache_bayonet_t 65

extern uintptr_t clientBase;
extern int choosenKnifeID;

using namespace std;


int modelIndex = 0;

void skinchanger() {
	int knifeID = choosenKnifeID;	
	// The offsets of knifemodels differs after the tenth knife
	int knifeIDOffset = knifeID < 10 ? 0 : 1;
	int knifeItemID = getKnifeItemDefinition(knifeID);

	uintptr_t localPlayer = *(uintptr_t*)(clientBase + dwLocalPlayer);

	if (localPlayer) {
		// Iterates to every weapon slot (primary, secondary, knife)
		for (int i = 0; i < 3; i++) {
			uintptr_t curWeapon = *(uintptr_t*)(localPlayer + m_hMyWeapons + i * 0x4) & 0xFFF;
			uintptr_t curWeaponBase = *(uintptr_t*)(clientBase + dwEntityList + (curWeapon - 1) * 0x10);

			if (curWeaponBase != 0) {
				short curWeaponID = *(short*)(curWeaponBase + m_iItemDefinitionIndex);

				// Sets everything but skin, modelindex, knifeItemID
				*(int*)(curWeaponBase + m_iItemIDHigh) = -1;
				*(int*)(curWeaponBase + m_nFallbackSeed) = 661;
				*(float*)(curWeaponBase + m_flFallbackWear) = 0.00001f;

				if (curWeaponID == 42 || curWeaponID == 59 || curWeaponID == knifeItemID) {
					// curWeapon is knife
					if (modelIndex > 0) {
						int paintKit = getSkinID(knifeItemID);

						*(short*)(curWeaponBase + m_iItemDefinitionIndex) = knifeItemID;
						*(int*)(curWeaponBase + m_nFallbackPaintKit) = paintKit;
						*(uintptr_t*)(curWeaponBase + m_nModelIndex) = modelIndex;
					}
				}
				else {
					// curWeapon is weapon
					int paintKit = getSkinID(curWeaponID);
					*(int*)(curWeaponBase + m_nFallbackPaintKit) = paintKit;
				}
			}
		}

		// Calculates and sets the modelindex of the knife
		uintptr_t activeWeapon = *(uintptr_t*)(localPlayer + m_hActiveWeapon) & 0xFFF;
		uintptr_t activeWeaponBase = *(uintptr_t*)(clientBase + dwEntityList + (activeWeapon - 1) * 0x10);

		if (activeWeaponBase != 0) {
			short activeWaeponID = *(short*)(activeWeaponBase + m_iItemDefinitionIndex);
			int weaponViewModelID = *(int*)(activeWeaponBase + m_iViewModelIndex);

			int localPlayerTeam = *(int*)(localPlayer + m_iTeamNum);

			if (localPlayerTeam == 2 || localPlayerTeam == 3) {

				if (activeWaeponID == 42 || (activeWaeponID == knifeItemID && localPlayerTeam == 3)) {
					// ct team
					modelIndex = weaponViewModelID + precache_bayonet_ct + knifeID * 3 + knifeIDOffset;
					knifeItemID = getKnifeItemDefinition(knifeID);
				}
				else if (activeWaeponID == 59 || (activeWaeponID == knifeItemID && localPlayerTeam == 2)) {
					// t team
					modelIndex = weaponViewModelID + precache_bayonet_t + knifeID * 3 + knifeIDOffset;
					knifeItemID = getKnifeItemDefinition(knifeID);
				}
				else if (activeWaeponID != knifeItemID) {
					return;
				}
			}
			uintptr_t knifeViewModel = *(uintptr_t*)(localPlayer + m_hViewModel) & 0xFFF;
			uintptr_t knifeViewModelBase = *(uintptr_t*)(clientBase + dwEntityList + (knifeViewModel - 1) * 0x10);

			if (knifeViewModel != 0) {
				// Write modelindex
				*(uintptr_t*)(knifeViewModelBase + m_nModelIndex) = modelIndex;
			}
		}
	}
	else {
		modelIndex = 0;
	}
}