////////////////////////////////////////////////////////////////////////
// OpenTibia - an opensource roleplaying game
////////////////////////////////////////////////////////////////////////
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
////////////////////////////////////////////////////////////////////////

#ifndef __ITEMS__
#define __ITEMS__
#include "otsystem.h"
#include "itemloader.h"

#include "const.h"
#include "enums.h"

#include "position.h"
#include <libxml/parser.h>

#define ITEMS 11500
#define SLOTP_WHEREEVER 0xFFFFFFFF
#define SLOTP_HEAD 1 << 0
#define	SLOTP_NECKLACE 1 << 1
#define	SLOTP_BACKPACK 1 << 2
#define	SLOTP_ARMOR 1 << 3
#define	SLOTP_RIGHT 1 << 4
#define	SLOTP_LEFT 1 << 5
#define	SLOTP_LEGS 1 << 6
#define	SLOTP_FEET 1 << 7
#define	SLOTP_RING 1 << 8
#define	SLOTP_AMMO 1 << 9
#define	SLOTP_DEPOT 1 << 10
#define	SLOTP_TWO_HAND 1 << 11
#define SLOTP_HAND SLOTP_LEFT | SLOTP_RIGHT

enum ItemTypes_t
{
	ITEM_TYPE_NONE = 0,
	ITEM_TYPE_DEPOT,
	ITEM_TYPE_MAILBOX,
	ITEM_TYPE_TRASHHOLDER,
	ITEM_TYPE_CONTAINER,
	ITEM_TYPE_DOOR,
	ITEM_TYPE_MAGICFIELD,
	ITEM_TYPE_TELEPORT,
	ITEM_TYPE_BED,
	ITEM_TYPE_KEY,
	ITEM_TYPE_LAST
};

enum ItemParseAttributes_t {
	ITEM_PARSE_TYPE,
	ITEM_PARSE_NAME,
	ITEM_PARSE_ARTICLE,
	ITEM_PARSE_PLURAL,
	ITEM_PARSE_DESCRIPTION,
	ITEM_PARSE_RUNESPELLNAME,
	ITEM_PARSE_WEIGHT,
	ITEM_PARSE_SHOWCOUNT,
	ITEM_PARSE_ARMOR,
	ITEM_PARSE_DEFENSE,
	ITEM_PARSE_EXTRADEF,
	ITEM_PARSE_ATTACK,
	ITEM_PARSE_EXTRAATTACK,
	ITEM_PARSE_ATTACK_SPEED,
	ITEM_PARSE_ROTATETO,
	ITEM_PARSE_MOVEABLE,
	ITEM_PARSE_BLOCKPROJECTILE,
	ITEM_PARSE_PICKUPABLE,
	ITEM_PARSE_FORCESERIALIZE,
	ITEM_PARSE_FLOORCHANGE,
	ITEM_PARSE_CORPSETYPE,
	ITEM_PARSE_CONTAINERSIZE,
	ITEM_PARSE_FLUIDSOURCE,
	ITEM_PARSE_READABLE,
	ITEM_PARSE_WRITEABLE,
	ITEM_PARSE_MAXTEXTLEN,
	ITEM_PARSE_WRITEONCEITEMID,
	ITEM_PARSE_WEAPONTYPE,
	ITEM_PARSE_SLOTTYPE,
	ITEM_PARSE_AMMOTYPE,
	ITEM_PARSE_SHOOTTYPE,
	ITEM_PARSE_EFFECT,
	ITEM_PARSE_RANGE,
	ITEM_PARSE_STOPDURATION,
	ITEM_PARSE_DECAYTO,
	ITEM_PARSE_TRANSFORMEQUIPTO,
	ITEM_PARSE_TRANSFORMDEEQUIPTO,
	ITEM_PARSE_DURATION,
	ITEM_PARSE_SHOWDURATION,
	ITEM_PARSE_CHARGES,
	ITEM_PARSE_SHOWCHARGES,
	ITEM_PARSE_SHOWATTRIBUTES,
	ITEM_PARSE_BREAKCHANCE,
	ITEM_PARSE_AMMOACTION,
	ITEM_PARSE_HITCHANCE,
	ITEM_PARSE_MAXHITCHANCE,
	ITEM_PARSE_PREVENTLOSS,
	ITEM_PARSE_PREVENTDROP,
	ITEM_PARSE_INVISIBLE,
	ITEM_PARSE_SPEED,
	ITEM_PARSE_HEALTHGAIN,
	ITEM_PARSE_HEALTHTICKS,
	ITEM_PARSE_MANAGAIN,
	ITEM_PARSE_MANATICKS,
	ITEM_PARSE_MANASHIELD,
	ITEM_PARSE_SKILLSWORD,
	ITEM_PARSE_SKILLAXE,
	ITEM_PARSE_SKILLCLUB,
	ITEM_PARSE_SKILLDIST,
	ITEM_PARSE_SKILLFISH,
	ITEM_PARSE_SKILLSHIELD,
	ITEM_PARSE_SKILLFIST,
	ITEM_PARSE_MAXHITPOINTS,
	ITEM_PARSE_MAXHITPOINTSPERCENT,
	ITEM_PARSE_MAXMANAPOINTS,
	ITEM_PARSE_MAXMANAPOINTSPERCENT,
	ITEM_PARSE_SOULPOINTS,
	ITEM_PARSE_SOULPOINTSPERCENT,
	ITEM_PARSE_MAGICPOINTS,
	ITEM_PARSE_MAGICPOINTSPERCENT,
	ITEM_PARSE_INCREASEMAGICVALUE,
	ITEM_PARSE_INCREASEMAGICPERCENT,
	ITEM_PARSE_INCREASEHEALINGVALUE,
	ITEM_PARSE_INCREASEHEALINGPERCENT,
	ITEM_PARSE_CRITICALHITCHANCE,
	ITEM_PARSE_CRITICALHITAMOUNT,
	ITEM_PARSE_LIFELEECHCHANCE,
	ITEM_PARSE_LIFELEECHAMOUNT,
	ITEM_PARSE_MANALEECHCHANCE,
	ITEM_PARSE_MANALEECHAMOUNT,
	ITEM_PARSE_ABSORBPERCENTALL,
	ITEM_PARSE_ABSORBPERCENTELEMENTS,
	ITEM_PARSE_ABSORBPERCENTMAGIC,
	ITEM_PARSE_ABSORBPERCENTENERGY,
	ITEM_PARSE_ABSORBPERCENTFIRE,
	ITEM_PARSE_ABSORBPERCENTPOISON,
	ITEM_PARSE_ABSORBPERCENTICE,
	ITEM_PARSE_ABSORBPERCENTHOLY,
	ITEM_PARSE_ABSORBPERCENTDEATH,
	ITEM_PARSE_ABSORBPERCENTLIFEDRAIN,
	ITEM_PARSE_ABSORBPERCENTMANADRAIN,
	ITEM_PARSE_ABSORBPERCENTDROWN,
	ITEM_PARSE_ABSORBPERCENTPHYSICAL,
	ITEM_PARSE_ABSORBPERCENTHEALING,
	ITEM_PARSE_ABSORBPERCENTUNDEFINED,
	ITEM_PARSE_REFLECTPERCENTALL,
	ITEM_PARSE_REFLECTPERCENTELEMENTS,
	ITEM_PARSE_REFLECTPERCENTMAGIC,
	ITEM_PARSE_REFLECTPERCENTENERGY,
	ITEM_PARSE_REFLECTPERCENTFIRE,
	ITEM_PARSE_REFLECTPERCENTPOISON,
	ITEM_PARSE_REFLECTPERCENTICE,
	ITEM_PARSE_REFLECTPERCENTHOLY,
	ITEM_PARSE_REFLECTPERCENTDEATH,
	ITEM_PARSE_REFLECTPERCENTLIFEDRAIN,
	ITEM_PARSE_REFLECTPERCENTMANADRAIN,
	ITEM_PARSE_REFLECTPERCENTDROWN,
	ITEM_PARSE_REFLECTPERCENTPHYSICAL,
	ITEM_PARSE_REFLECTPERCENTHEALING,
	ITEM_PARSE_REFLECTPERCENTUNDEFINED,
	ITEM_PARSE_REFLECTCHANCEALL,
	ITEM_PARSE_REFLECTCHANCEELEMENTS,
	ITEM_PARSE_REFLECTCHANCEMAGIC,
	ITEM_PARSE_REFLECTCHANCEENERGY,
	ITEM_PARSE_REFLECTCHANCEFIRE,
	ITEM_PARSE_REFLECTCHANCEPOISON,
	ITEM_PARSE_REFLECTCHANCEICE,
	ITEM_PARSE_REFLECTCHANCEHOLY,
	ITEM_PARSE_REFLECTCHANCEDEATH,
	ITEM_PARSE_REFLECTCHANCELIFEDRAIN,
	ITEM_PARSE_REFLECTCHANCEMANADRAIN,
	ITEM_PARSE_REFLECTCHANCEDROWN,
	ITEM_PARSE_REFLECTCHANCEPHYSICAL,
	ITEM_PARSE_REFLECTCHANCEHEALING,
	ITEM_PARSE_REFLECTCHANCEUNDEFINED,
	ITEM_PARSE_SUPPRESSSHOCK,
	ITEM_PARSE_SUPPRESSBURN,
	ITEM_PARSE_SUPPRESSPOISON,
	ITEM_PARSE_SUPPRESSFREEZE,
	ITEM_PARSE_SUPPRESSDAZZLE,
	ITEM_PARSE_SUPPRESSCURSE,
	ITEM_PARSE_SUPPRESSDROWN,
	ITEM_PARSE_SUPPRESSPHYSICAL,
	ITEM_PARSE_SUPPRESSHASTE,
	ITEM_PARSE_SUPPRESSPARALYZE,
	ITEM_PARSE_SUPPRESSDRUNK,
	ITEM_PARSE_SUPPRESSREGENERATION,
	ITEM_PARSE_SUPPRESSSOUL,
	ITEM_PARSE_SUPPRESSOUTFIT,
	ITEM_PARSE_SUPPRESSINVISIBLE,
	ITEM_PARSE_SUPPRESSINFIGHT,
	ITEM_PARSE_SUPPRESSEXHAUST,
	ITEM_PARSE_SUPPRESSMUTED,
	ITEM_PARSE_SUPPRESSPACIFIED,
	ITEM_PARSE_SUPPRESSLIGHT,
	ITEM_PARSE_SUPPRESSATTRIBUTES,
	ITEM_PARSE_SUPPRESSMANASHIELD,
	ITEM_PARSE_FIELD,
	ITEM_PARSE_ELEMENTPHYSICAL,
	ITEM_PARSE_ELEMENTFIRE,
	ITEM_PARSE_ELEMENTENERGY,
	ITEM_PARSE_ELEMENTEARTH,
	ITEM_PARSE_ELEMENTICE,
	ITEM_PARSE_ELEMENTHOLY,
	ITEM_PARSE_ELEMENTDEATH,
	ITEM_PARSE_ELEMENTLIFEDRAIN,
	ITEM_PARSE_ELEMENTMANADRAIN,
	ITEM_PARSE_ELEMENTHEALING,
	ITEM_PARSE_ELEMENTUNDEFINED,
	ITEM_PARSE_MAGICLEVELENERGY,
	ITEM_PARSE_MAGICLEVELFIRE,
	ITEM_PARSE_MAGICLEVELPOISON,
	ITEM_PARSE_MAGICLEVELICE,
	ITEM_PARSE_MAGICLEVELHOLY,
	ITEM_PARSE_MAGICLEVELDEATH,
	ITEM_PARSE_MAGICLEVELLIFEDRAIN,
	ITEM_PARSE_MAGICLEVELMANADRAIN,
	ITEM_PARSE_MAGICLEVELDROWN,
	ITEM_PARSE_MAGICLEVELPHYSICAL,
	ITEM_PARSE_MAGICLEVELHEALING,
	ITEM_PARSE_MAGICLEVELUNDEFINED,
	ITEM_PARSE_REPLACEABLE,
	ITEM_PARSE_PARTNERDIRECTION,
	ITEM_PARSE_LEVELDOOR,
	ITEM_PARSE_MALETRANSFORMTO,
	ITEM_PARSE_FEMALETRANSFORMTO,
	ITEM_PARSE_TRANSFORMTO,
	ITEM_PARSE_DESTROYTO,
	ITEM_PARSE_WALKSTACK,
	ITEM_PARSE_BLOCKING,
	ITEM_PARSE_ALLOWDISTREAD,
	ITEM_PARSE_STOREITEM,
	ITEM_PARSE_WORTH,
};

enum FloorChange_t
{
	CHANGE_PRE_FIRST = 0,
	CHANGE_DOWN = CHANGE_PRE_FIRST,
	CHANGE_FIRST = 1,
	CHANGE_NORTH = CHANGE_FIRST,
	CHANGE_EAST = 2,
	CHANGE_SOUTH = 3,
	CHANGE_WEST = 4,
	CHANGE_FIRST_EX = 5,
	CHANGE_NORTH_EX = CHANGE_FIRST_EX,
	CHANGE_EAST_EX = 6,
	CHANGE_SOUTH_EX = 7,
	CHANGE_WEST_EX = 8,
	CHANGE_NONE = 9,
	CHANGE_LAST = CHANGE_NONE
};

struct Abilities
{
	Abilities()
	{
		memset(skills, 0, sizeof(skills));
		memset(skillsPercent, 0, sizeof(skillsPercent));
		memset(stats, 0 , sizeof(stats));
		memset(statsPercent, 0, sizeof(statsPercent));

		memset(absorb, 0, sizeof(absorb));
		memset(increment, 0, sizeof(increment));
		memset(reflect[REFLECT_PERCENT], 0, sizeof(reflect[REFLECT_PERCENT]));
		memset(reflect[REFLECT_CHANCE], 0, sizeof(reflect[REFLECT_CHANCE]));

		elementType = COMBAT_NONE;
		manaShield = invisible = regeneration = preventLoss = preventDrop = false;
		speed = healthGain = healthTicks = manaGain = manaTicks = elementDamage = conditionSuppressions = 0;
	};

	bool manaShield, invisible, regeneration, preventLoss, preventDrop;
	CombatType_t elementType;

	int16_t elementDamage, absorb[COMBAT_LAST + 1], increment[INCREMENT_LAST + 1], reflect[REFLECT_LAST + 1][COMBAT_LAST + 1];
	int32_t skills[SKILL_LAST + 1], skillsPercent[SKILL_LAST + 1], stats[STAT_LAST + 1], statsPercent[STAT_LAST + 1],
		speed, healthGain, healthTicks, manaGain, manaTicks, conditionSuppressions;
};

class Condition;
class ItemType
{
	private:
		ItemType(const ItemType& it) {}

	public:
		ItemType();
		virtual ~ItemType();

		bool isGroundTile() const {return (group == ITEM_GROUP_GROUND);}
		bool isContainer() const {return (group == ITEM_GROUP_CONTAINER);}
		bool isSplash() const {return (group == ITEM_GROUP_SPLASH);}
		bool isFluidContainer() const {return (group == ITEM_GROUP_FLUID);}

		bool isDoor() const {return (type == ITEM_TYPE_DOOR);}
		bool isMagicField() const {return (type == ITEM_TYPE_MAGICFIELD);}
		bool isTeleport() const {return (type == ITEM_TYPE_TELEPORT);}
		bool isKey() const {return (type == ITEM_TYPE_KEY);}
		bool isDepot() const {return (type == ITEM_TYPE_DEPOT);}
		bool isMailbox() const {return (type == ITEM_TYPE_MAILBOX);}
		bool isTrashHolder() const {return (type == ITEM_TYPE_TRASHHOLDER);}
		bool isBed() const {return (type == ITEM_TYPE_BED);}

		bool isRune() const {return clientCharges;}
		bool hasSubType() const {return (isFluidContainer() || isSplash() || stackable || charges);}

		bool stopTime, showCount, clientCharges, stackable, showDuration, showCharges, showAttributes,
			allowDistRead, canReadText, canWriteText, forceSerialize, isVertical, isHorizontal, isHangable,
			useable, moveable, pickupable, rotable, replaceable, lookThrough,
			hasHeight, blockSolid, blockPickupable, blockProjectile, blockPathFind, allowPickupable, alwaysOnTop,
			floorChange[CHANGE_LAST];

		MagicEffect_t magicEffect;
		FluidTypes_t fluidSource;
		WeaponType_t weaponType;
		Direction bedPartnerDir;
		AmmoAction_t ammoAction;
		CombatType_t combatType;
		RaceType_t corpseType;
		ShootEffect_t shootType;
		Ammo_t ammoType;

		uint16_t transformUseTo[2], transformToFree, transformEquipTo, transformDeEquipTo,
			id, clientId, maxItems, slotPosition, wieldPosition, speed, maxTextLen, writeOnceItemId;

		int32_t attack, extraAttack, defense, extraDefense, armor, breakChance, hitChance, maxHitChance,
			runeLevel, runeMagLevel, lightLevel, lightColor, decayTo, rotateTo, alwaysOnTopOrder;
		uint32_t shootRange, charges, decayTime, attackSpeed, wieldInfo, minReqLevel, minReqMagicLevel,
			worth, levelDoor;

		std::string name, pluralName, article, description, runeSpellName, vocationString;

		Condition* condition;
		Abilities abilities;
		itemgroup_t group;
		ItemTypes_t type;
		float weight;
};

template<typename A>
class Array
{
	public:
		Array(uint32_t n);
		virtual ~Array();

		A getElement(uint32_t id);
		const A getElement(uint32_t id) const;
		void addElement(A a, uint32_t pos);

		uint32_t size() {return m_size;}

	private:
		A* m_data;
		uint32_t m_size;
};

template<typename A>
Array<A>::Array(uint32_t n)
{
	m_data = (A*)malloc(sizeof(A) * n);
	memset(m_data, 0, sizeof(A) * n);
	m_size = n;
}

template<typename A>
Array<A>::~Array()
{
	free(m_data);
}

template<typename A>
A Array<A>::getElement(uint32_t id)
{
	if(id < m_size)
		return m_data[id];

	return 0;
}

template<typename A>
const A Array<A>::getElement(uint32_t id) const
{
	if(id < m_size)
		return m_data[id];

	return 0;
}

template<typename A>
void Array<A>::addElement(A a, uint32_t pos)
{
	#define INCREMENT 5000
	if(pos >= m_size)
	{
		m_data = (A*)realloc(m_data, sizeof(A) * (pos + INCREMENT));
		memset(m_data + m_size, 0, sizeof(A) * (pos + INCREMENT - m_size));
		m_size = pos + INCREMENT;
	}

	m_data[pos] = a;
}

struct RandomizationBlock
{
	int32_t fromRange, toRange, chance;
};

typedef std::map<int16_t, RandomizationBlock> RandomizationMap;
typedef std::map<int32_t, int32_t> IntegerMap;

class Items
{
	public:
		Items(): m_randomizationChance(50), items(ITEMS) {}
		virtual ~Items() {clear();}

		bool reload();
		int32_t loadFromOtb(std::string);
		bool loadFromXml();
		void parseItemNode(xmlNodePtr itemNode, uint32_t id);

		void addItemType(ItemType* iType);
		ItemType& getItemType(int32_t id);
		const ItemType& getItemType(int32_t id) const;
		const ItemType& operator[](int32_t id) const {return getItemType(id);}

		int32_t getItemIdByName(const std::string& name);
		const ItemType& getItemIdByClientId(int32_t spriteId) const;

		uint16_t getRandomizedItem(uint16_t id);
		uint8_t getRandomizationChance() const {return m_randomizationChance;}
		RandomizationBlock getRandomization(int16_t id) {return randomizationMap[id];}

		uint32_t size() {return items.size();}
		IntegerMap getMoneyMap() {return moneyMap;}
		const ItemType* getElement(uint32_t id) const {return items.getElement(id);}

		static uint32_t dwMajorVersion;
		static uint32_t dwMinorVersion;
		static uint32_t dwBuildNumber;

	private:
		uint8_t m_randomizationChance;
		void clear();

		void parseRandomizationBlock(int32_t id, int32_t fromId, int32_t toId, int32_t chance);

		Array<ItemType*> items;
		RandomizationMap randomizationMap;

		IntegerMap moneyMap;
		IntegerMap reverseItemMap;
};
#endif
