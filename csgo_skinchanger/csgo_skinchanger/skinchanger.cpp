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
	int knifeIDOffset = knifeID < 10 ? 0 : 1;
	int knifeIDef = getKnifeItemDefinition(knifeID);

	uintptr_t localPlayer = *(uintptr_t*)(clientBase + dwLocalPlayer);

	if (localPlayer) {
		for (int i = 0; i < 3; i++) {
			uintptr_t curWeapon = *(uintptr_t*)(localPlayer + m_hMyWeapons + i * 0x4) & 0xFFF;
			uintptr_t curWeaponBase = *(uintptr_t*)(clientBase + dwEntityList + (curWeapon - 1) * 0x10);

			if (curWeaponBase != 0) {
				short curWeaponID = *(short*)(curWeaponBase + m_iItemDefinitionIndex);

				int paintKit = getSkinID(curWeaponID);
				cout << "curWeaponID: " << curWeaponID << endl;
				cout << "paintkit: " << paintKit << endl;
				if (paintKit == 0) {
					continue;
				}

				*(int*)(curWeaponBase + m_nFallbackPaintKit) = paintKit;
				*(int*)(curWeaponBase + m_iItemIDHigh) = -1;
				*(int*)(curWeaponBase + m_nFallbackSeed) = 661;
				*(float*)(curWeaponBase + m_flFallbackWear) = 0.00001f;

				if (curWeaponID == 42 || curWeaponID == 59 || curWeaponID == knifeIDef) {
					if (modelIndex > 0) {
						*(short*)(curWeaponBase + m_iItemDefinitionIndex) = knifeIDef;
						*(uintptr_t*)(curWeaponBase + m_nModelIndex) = modelIndex;
						*(uintptr_t*)(curWeaponBase + m_iViewModelIndex) = modelIndex;
					}
				}
			}
		}
		uintptr_t activeWeapon = *(uintptr_t*)(localPlayer + m_hActiveWeapon) & 0xFFF;
		uintptr_t activeWeaponBase = *(uintptr_t*)(clientBase + dwEntityList + (activeWeapon - 1) * 0x10);

		if (activeWeaponBase != 0) {
			short activeWaeponID = *(short*)(activeWeaponBase + m_iItemDefinitionIndex);
			int weaponViewModelID = *(int*)(activeWeaponBase + m_iViewModelIndex);

			int localPlayerTeam = *(int*)(localPlayer + m_iTeamNum);

			if (localPlayerTeam == 2 || localPlayerTeam == 3) {

				if (activeWaeponID == 42 || (activeWaeponID == knifeIDef && localPlayerTeam == 3)) {
					modelIndex = weaponViewModelID + precache_bayonet_ct + knifeID * 3 + knifeIDOffset;
					knifeIDef = 42;
				}
				else if (activeWaeponID == 59 || (activeWaeponID == knifeIDef && localPlayerTeam == 2)) {
					modelIndex = weaponViewModelID + precache_bayonet_t + knifeID * 3 + knifeIDOffset;
					knifeIDef = 59;
				}
				else if (activeWeapon != knifeIDef) {
					return;
				}
			}
			uintptr_t knifeViewModel = *(uintptr_t*)(localPlayer + m_hViewModel) & 0xFFF;
			uintptr_t knifeViewModelBase = *(uintptr_t*)(clientBase + dwEntityList + (knifeViewModel - 1) * 0x10);

			if (knifeViewModel != 0) {
				//if (activeWaeponID == 42 || activeWaeponID == 59 || activeWaeponID == knifeIDef) {
					*(short*)(activeWeaponBase + m_iItemDefinitionIndex) = knifeIDef;
					*(uintptr_t*)(knifeViewModelBase + m_nModelIndex) = modelIndex;
					*(uintptr_t*)(knifeViewModelBase + m_iViewModelIndex) = modelIndex;
				//}
			}
		}
	}
	else {
		modelIndex = 0;
	}
}