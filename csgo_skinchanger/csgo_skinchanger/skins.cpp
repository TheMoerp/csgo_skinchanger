#include "skins.h"

// weaponskins
int cz75 = 270;
int desertEagle = 37;
int dualBerettas = 625;
int fiveSeven = 979;
int glock18 = 957;
int p2000 = 389;
int p250 = 678;
int tec9 = 179;
int ak47 = 44;
int aug = 690;
int awp = 344;
int famas = 919;
int g3sg1 = 712;
int galilAr = 1038;
int m4a4 = 309;
int scar20 = 597;
int sg553 = 44;
int ssg08 = 1048;
int mac10 = 433;
int mp5sd = 915;
int mp7 = 696;
int mp9 = 1037;
int ppBizon = 676;
int p90 = 359;
int ump45 = 556;
int mag7 = 961;
int nova = 537;
int sawedOff = 638;
int xm1014 = 850;
int m249 = 902;
int negev = 763;
int usps = 1040;
int m4a1s = 587;
int revolver = 522;

/* KnifeID (bayonet = 0, flip = 2, karambit = 4, m9bayonet = 5, huntsman = 6, falchion = 7, navaja = 14, stiletto = 16)
   For every other knife the animations are broken. This may will be fixed at some time. */
int choosenKnifeID = 0;

// Knife Skins
int bayonet = 416;
int flip = 419;
int karambit = 419;
int m9Bayonet = 419;
int huntsman = 419;
int falchion = 419;
int navaja = 419;
int stiletto = 419;


// Get Skin ID by weaponID
int getSkinID(int weaponID) {
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
		case 500:
			return bayonet;
		case 505:
			return flip;
		case 512:
			return falchion;
		case 522:
			return stiletto;
		case 508:
			return m9Bayonet;
		case 520:
			return navaja;
		case 509:
			return huntsman;
		case 59:
			return 44;
		case 42:
			return 44;
		default:
			return 0;
		}
}


// Get KnifeItemID by KnifeID
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