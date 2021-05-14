#include "skins.h"


int getSkinID(int weaponID, bool isKnife) {
	if (isKnife) {
		switch (knifeID) {
		case 0:
			return bayonet;
		case 2:
			return flip;
		case 4:
			return karambit;
		case 5:
			return m9Bayonet;
		case 6:
			return huntsman;
		case 7:
			return falchion;
		case 14:
			return navaja;
		case 16:
			return stiletto;
		default:
			return 0;
		}
	}
	else {
		switch (weaponID) {
		case 1:
			return desertEagle;
		case 2:
			return dualBerettas;
		case 3:
			return fiveSeven;
		case 4:
			return glock18;
		case 7:
			return ak47;
		case 8:
			return aug;
		case 9:
			return awp;
		case 10:
			return famas;
		case 11:
			return g3sg1;
		case 13:
			return galilAr;
		case 14:
			return m249;
		case 16:
			return m4a4;
		case 17:
			return mac10;
		case 19:
			return p90;
		case 262167:
			return mp5sd;
		case 24:
			return ump45;
		case 25:
			return xm1014;
		case 26:
			return ppBizon;
		case 27:
			return mag7;
		case 28:
			return negev;
		case 29:
			return sawedOff;
		case 30:
			return tec9;
		case 32:
			return p2000;
		case 33:
			return mp7;
		case 34:
			return mp9;
		case 35:
			return nova;
		case 36:
			return p250;
		case 38:
			return scar20;
		case 39:
			return sg553;
		case 40:
			return ssg08;
		case 262207:
			return cz75;
		case 262205:
			return usps;
		case 262204:
			return m4a1s;
		case 262208:
			return revolver;
		default:
			return 0;
		}
	}
}


int getKnifeItemDefinition(int knifeID) {
	switch (knifeID) {
	case 0:
		return 500;
	case 2:
		return 505;
	case 4:
		return 507;
	case 5:
		return 508;
	case 6:
		return 509;
	case 7:
		return 512;
	case 14:
		return 520;
	case 16:
		return 522;
	default:
		break;
	}
}