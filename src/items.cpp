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
#include "otpch.h"
#include <iostream>
#include <libxml/xmlmemory.h>

#include "items.h"
#include "condition.h"
#include "weapons.h"

#include "configmanager.h"
#include "spells.h"

extern Spells* g_spells;
extern ConfigManager g_config;

uint32_t Items::dwMajorVersion = 0;
uint32_t Items::dwMinorVersion = 0;
uint32_t Items::dwBuildNumber = 0;

const std::unordered_map<std::string, ItemParseAttributes_t> ItemParseAttributesMap = {
	{"type", ITEM_PARSE_TYPE},
	{"name", ITEM_PARSE_NAME},
	{"article", ITEM_PARSE_ARTICLE},
	{"plural", ITEM_PARSE_PLURAL},
	{"description", ITEM_PARSE_DESCRIPTION},
	{"runespellname", ITEM_PARSE_RUNESPELLNAME},
	{"weight", ITEM_PARSE_WEIGHT},
	{"showcount", ITEM_PARSE_SHOWCOUNT},
	{"armor", ITEM_PARSE_ARMOR},
	{"defense", ITEM_PARSE_DEFENSE},
	{"extradef", ITEM_PARSE_EXTRADEF}, // TODO: choose which will still be used extradef / extradefense
	{"extradefense", ITEM_PARSE_EXTRADEF},
	{"attack", ITEM_PARSE_ATTACK},
	{"attackspeed", ITEM_PARSE_ATTACK_SPEED},
	{"rotateto", ITEM_PARSE_ROTATETO},
	{"moveable", ITEM_PARSE_MOVEABLE},
	{"movable", ITEM_PARSE_MOVEABLE},
	{"blockprojectile", ITEM_PARSE_BLOCKPROJECTILE},
	{"allowpickupable", ITEM_PARSE_PICKUPABLE},
	{"pickupable", ITEM_PARSE_PICKUPABLE},
	{"forceserialize", ITEM_PARSE_FORCESERIALIZE},
	{"forcesave", ITEM_PARSE_FORCESERIALIZE},
	{"floorchange", ITEM_PARSE_FLOORCHANGE},
	{"corpsetype", ITEM_PARSE_CORPSETYPE},
	{"containersize", ITEM_PARSE_CONTAINERSIZE},
	{"fluidsource", ITEM_PARSE_FLUIDSOURCE},
	{"readable", ITEM_PARSE_READABLE},
	{"writeable", ITEM_PARSE_WRITEABLE},
	{"maxtextlen", ITEM_PARSE_MAXTEXTLEN},
	{"writeonceitemid", ITEM_PARSE_WRITEONCEITEMID},
	{"weapontype", ITEM_PARSE_WEAPONTYPE},
	{"slottype", ITEM_PARSE_SLOTTYPE},
	{"ammotype", ITEM_PARSE_AMMOTYPE},
	{"shoottype", ITEM_PARSE_SHOOTTYPE},
	{"effect", ITEM_PARSE_EFFECT},
	{"range", ITEM_PARSE_RANGE},
	{"stopduration", ITEM_PARSE_STOPDURATION},
	{"decayto", ITEM_PARSE_DECAYTO},
	{"transformequipto", ITEM_PARSE_TRANSFORMEQUIPTO},
	{"transformdeequipto", ITEM_PARSE_TRANSFORMDEEQUIPTO},
	{"duration", ITEM_PARSE_DURATION},
	{"showduration", ITEM_PARSE_SHOWDURATION},
	{"charges", ITEM_PARSE_CHARGES},
	{"showcharges", ITEM_PARSE_SHOWCHARGES},
	{"showattributes", ITEM_PARSE_SHOWATTRIBUTES},
	{"breakchance", ITEM_PARSE_BREAKCHANCE},
	{"ammoaction", ITEM_PARSE_AMMOACTION},
	{"hitchance", ITEM_PARSE_HITCHANCE},
	{"maxhitchance", ITEM_PARSE_MAXHITCHANCE},
	{"preventloss", ITEM_PARSE_PREVENTLOSS},
	{"preventdrop", ITEM_PARSE_PREVENTDROP},
	{"invisible", ITEM_PARSE_INVISIBLE},
	{"speed", ITEM_PARSE_SPEED},
	{"healthgain", ITEM_PARSE_HEALTHGAIN},
	{"healthticks", ITEM_PARSE_HEALTHTICKS},
	{"managain", ITEM_PARSE_MANAGAIN},
	{"manaticks", ITEM_PARSE_MANATICKS},
	{"manashield", ITEM_PARSE_MANASHIELD},
	{"skillsword", ITEM_PARSE_SKILLSWORD},
	{"skillaxe", ITEM_PARSE_SKILLAXE},
	{"skillclub", ITEM_PARSE_SKILLCLUB},
	{"skilldist", ITEM_PARSE_SKILLDIST},
	{"skillfish", ITEM_PARSE_SKILLFISH},
	{"skillshield", ITEM_PARSE_SKILLSHIELD},
	{"skillfist", ITEM_PARSE_SKILLFIST},
	{"maxhitpoints", ITEM_PARSE_MAXHITPOINTS},
	{"maxhitpointspercent", ITEM_PARSE_MAXHITPOINTSPERCENT},
	{"maxmanapoints", ITEM_PARSE_MAXMANAPOINTS},
	{"maxmanapointspercent", ITEM_PARSE_MAXMANAPOINTSPERCENT},
	{"soulpoints", ITEM_PARSE_SOULPOINTS},
	{"soulpercent", ITEM_PARSE_SOULPOINTSPERCENT},
	{"soulpointspercent", ITEM_PARSE_SOULPOINTSPERCENT},
	{"magicpoints", ITEM_PARSE_MAGICPOINTS},
	{"magiclevelpoints", ITEM_PARSE_MAGICPOINTS},
	{"magicpointspercent", ITEM_PARSE_MAGICPOINTSPERCENT},
	{"increasemagicvalue", ITEM_PARSE_INCREASEMAGICVALUE},
	{"increasemagicpercent", ITEM_PARSE_INCREASEMAGICPERCENT},
	{"increasehealingvalue", ITEM_PARSE_INCREASEHEALINGVALUE},
	{"increasehealingpercent", ITEM_PARSE_INCREASEHEALINGPERCENT},
	{"criticalhitchance", ITEM_PARSE_CRITICALHITCHANCE},
	{"criticalhitamount", ITEM_PARSE_CRITICALHITAMOUNT},
	{"lifeleechchance", ITEM_PARSE_LIFELEECHCHANCE},
	{"lifeleechamount", ITEM_PARSE_LIFELEECHAMOUNT},
	{"manaleechchance", ITEM_PARSE_MANALEECHCHANCE},
	{"manaleechamount", ITEM_PARSE_MANALEECHAMOUNT},
	{"absorbpercentall", ITEM_PARSE_ABSORBPERCENTALL},
	{"absorbpercentallelements", ITEM_PARSE_ABSORBPERCENTALL},
	{"absorbpercentelements", ITEM_PARSE_ABSORBPERCENTELEMENTS},
	{"absorbpercentmagic", ITEM_PARSE_ABSORBPERCENTMAGIC},
	{"absorbpercentenergy", ITEM_PARSE_ABSORBPERCENTENERGY},
	{"absorbpercentfire", ITEM_PARSE_ABSORBPERCENTFIRE},
	{"absorbpercentpoison", ITEM_PARSE_ABSORBPERCENTPOISON},
	{"absorbpercentearth", ITEM_PARSE_ABSORBPERCENTPOISON},
	{"absorbpercentice", ITEM_PARSE_ABSORBPERCENTICE},
	{"absorbpercentholy", ITEM_PARSE_ABSORBPERCENTHOLY},
	{"absorbpercentdeath", ITEM_PARSE_ABSORBPERCENTDEATH},
	{"absorbpercentlifedrain", ITEM_PARSE_ABSORBPERCENTLIFEDRAIN},
	{"absorbpercentmanadrain", ITEM_PARSE_ABSORBPERCENTMANADRAIN},
	{"absorbpercentdrown", ITEM_PARSE_ABSORBPERCENTDROWN},
	{"absorbpercentphysical", ITEM_PARSE_ABSORBPERCENTPHYSICAL},
	{"absorbpercenthealing", ITEM_PARSE_ABSORBPERCENTHEALING},
	{"reflectpercentall", ITEM_PARSE_REFLECTPERCENTALL },
	{"reflectpercentelements", ITEM_PARSE_REFLECTPERCENTELEMENTS },
	{"reflectpercentmagic", ITEM_PARSE_REFLECTPERCENTMAGIC },
	{"reflectpercentenergy", ITEM_PARSE_REFLECTPERCENTENERGY },
	{"reflectpercentfire", ITEM_PARSE_REFLECTPERCENTFIRE },
	{"reflectpercentpoison", ITEM_PARSE_REFLECTPERCENTPOISON },
	{"reflectpercentice", ITEM_PARSE_REFLECTPERCENTICE },
	{"reflectpercentholy", ITEM_PARSE_REFLECTPERCENTHOLY },
	{"reflectpercentdeath", ITEM_PARSE_REFLECTPERCENTDEATH },
	{"reflectpercentlifedrain", ITEM_PARSE_REFLECTPERCENTLIFEDRAIN },
	{"reflectpercentmanadrain", ITEM_PARSE_REFLECTPERCENTMANADRAIN },
	{"reflectpercentdrown", ITEM_PARSE_REFLECTPERCENTDROWN },
	{ "reflectpercentphysical", ITEM_PARSE_REFLECTPERCENTPHYSICAL },
	{"reflectpercenthealing", ITEM_PARSE_REFLECTPERCENTHEALING },
	{"reflectpercentundefined", ITEM_PARSE_REFLECTPERCENTUNDEFINED },
	{"reflectchanceall", ITEM_PARSE_REFLECTCHANCEALL },
	{"reflectchanceelements", ITEM_PARSE_REFLECTCHANCEELEMENTS },
	{"reflectchancemagic", ITEM_PARSE_REFLECTCHANCEMAGIC },
	{"reflectchanceenergy", ITEM_PARSE_REFLECTCHANCEENERGY },
	{"reflectchancefire", ITEM_PARSE_REFLECTCHANCEFIRE },
	{"reflectchancepoison", ITEM_PARSE_REFLECTCHANCEPOISON },
	{"reflectchanceice", ITEM_PARSE_REFLECTCHANCEICE },
	{"reflectchanceholy", ITEM_PARSE_REFLECTCHANCEHOLY },
	{"reflectchancedeath", ITEM_PARSE_REFLECTCHANCEDEATH },
	{"reflectchancelifedrain", ITEM_PARSE_REFLECTCHANCELIFEDRAIN },
	{"reflectchancemanadrain", ITEM_PARSE_REFLECTCHANCEMANADRAIN },
	{"reflectchancedrown", ITEM_PARSE_REFLECTCHANCEDROWN },
	{"reflectchancephysical", ITEM_PARSE_REFLECTCHANCEPHYSICAL },
	{"reflectchancehealing", ITEM_PARSE_REFLECTCHANCEHEALING },
	{"reflectchanceundefined", ITEM_PARSE_REFLECTCHANCEUNDEFINED },
	{"magiclevelenergy", ITEM_PARSE_MAGICLEVELENERGY},
	{"magiclevelfire", ITEM_PARSE_MAGICLEVELFIRE},
	{"magiclevelpoison", ITEM_PARSE_MAGICLEVELPOISON},
	{"magiclevelearth", ITEM_PARSE_MAGICLEVELPOISON},
	{"magiclevelice", ITEM_PARSE_MAGICLEVELICE},
	{"magiclevelholy", ITEM_PARSE_MAGICLEVELHOLY},
	{"magicleveldeath", ITEM_PARSE_MAGICLEVELDEATH},
	{"magiclevellifedrain", ITEM_PARSE_MAGICLEVELLIFEDRAIN},
	{"magiclevelmanadrain", ITEM_PARSE_MAGICLEVELMANADRAIN},
	{"magicleveldrown", ITEM_PARSE_MAGICLEVELDROWN},
	{"magiclevelphysical", ITEM_PARSE_MAGICLEVELPHYSICAL},
	{"magiclevelhealing", ITEM_PARSE_MAGICLEVELHEALING},
	{"magiclevelundefined", ITEM_PARSE_MAGICLEVELUNDEFINED},
	{"suppressshock", ITEM_PARSE_SUPPRESSSHOCK},
	{"suppressburn", ITEM_PARSE_SUPPRESSBURN },
	{"suppresspoison", ITEM_PARSE_SUPPRESSPOISON },
	{"suppressfreeze", ITEM_PARSE_SUPPRESSFREEZE },
	{"suppressdazzle", ITEM_PARSE_SUPPRESSDAZZLE },
	{"suppresscurse", ITEM_PARSE_SUPPRESSCURSE },
	{"suppressdrown", ITEM_PARSE_SUPPRESSDROWN },
	{"suppressphysical", ITEM_PARSE_SUPPRESSPHYSICAL },
	{"suppresshaste", ITEM_PARSE_SUPPRESSHASTE },
	{"suppressparalyze", ITEM_PARSE_SUPPRESSPARALYZE },
	{"suppressdrunk", ITEM_PARSE_SUPPRESSDRUNK },
	{"suppressregeneration", ITEM_PARSE_SUPPRESSREGENERATION },
	{"suppresssoul", ITEM_PARSE_SUPPRESSSOUL },
	{"suppressoutfit", ITEM_PARSE_SUPPRESSOUTFIT },
	{"suppressinvisible", ITEM_PARSE_SUPPRESSINVISIBLE },
	{"suppressinfight", ITEM_PARSE_SUPPRESSINFIGHT },
	{"suppressexhaust", ITEM_PARSE_SUPPRESSEXHAUST },
	{"suppressmuted", ITEM_PARSE_SUPPRESSMUTED },
	{"suppresspacified", ITEM_PARSE_SUPPRESSPACIFIED },
	{"suppresslight", ITEM_PARSE_SUPPRESSLIGHT },
	{"suppressattributes", ITEM_PARSE_SUPPRESSATTRIBUTES },
	{"suppressmanashield", ITEM_PARSE_SUPPRESSMANASHIELD },
	{"field", ITEM_PARSE_FIELD},
	{ "elementphysical", ITEM_PARSE_ELEMENTPHYSICAL },
	{ "elementfire", ITEM_PARSE_ELEMENTFIRE },
	{ "elementenergy", ITEM_PARSE_ELEMENTENERGY },
	{ "elementearth", ITEM_PARSE_ELEMENTEARTH },
	{ "elementice", ITEM_PARSE_ELEMENTICE },
	{ "elementholy", ITEM_PARSE_ELEMENTHOLY },
	{ "elementdeath", ITEM_PARSE_ELEMENTDEATH },
	{ "elementlifedrain", ITEM_PARSE_ELEMENTLIFEDRAIN },
	{ "elementmanadrain", ITEM_PARSE_ELEMENTMANADRAIN },
	{ "elementhealing", ITEM_PARSE_ELEMENTHEALING },
	{ "elementundefined", ITEM_PARSE_ELEMENTUNDEFINED },
	{"replaceable", ITEM_PARSE_REPLACEABLE},
	{"partnerdirection", ITEM_PARSE_PARTNERDIRECTION},
	{"leveldoor", ITEM_PARSE_LEVELDOOR},
	{"maletransformto", ITEM_PARSE_MALETRANSFORMTO},
	{"malesleeper", ITEM_PARSE_MALETRANSFORMTO},
	{"femaletransformto", ITEM_PARSE_FEMALETRANSFORMTO},
	{"femalesleeper", ITEM_PARSE_FEMALETRANSFORMTO},
	{ "transformto", ITEM_PARSE_TRANSFORMTO },
	{ "transformTo", ITEM_PARSE_TRANSFORMTO },
	{"destroyto", ITEM_PARSE_DESTROYTO},
	{"walkstack", ITEM_PARSE_WALKSTACK},
	{"blocking", ITEM_PARSE_BLOCKING},
	{"allowdistread", ITEM_PARSE_ALLOWDISTREAD},
	{"storeitem", ITEM_PARSE_STOREITEM},
	{"worth", ITEM_PARSE_WORTH},
};

ItemType::ItemType()
{
	group = ITEM_GROUP_NONE;
	type = ITEM_TYPE_NONE;
	stackable = useable = alwaysOnTop = lookThrough = pickupable = rotable = hasHeight = forceSerialize = false;
	blockSolid = blockProjectile = blockPathFind = allowPickupable = false;
	moveable = true;
	alwaysOnTopOrder = 0;
	rotateTo = 0;

	wieldInfo = 0;
	minReqLevel = 0;
	minReqMagicLevel = 0;

	runeMagLevel = runeLevel = 0;

	speed = id = 0;
	clientId = 100;
	maxItems = 8; //maximum size if this is a container
	weight = 0; //weight of the item, e.g. throwing distance depends on it
	showCount = true;
	weaponType = WEAPON_NONE;
	slotPosition = SLOTP_HAND | SLOTP_AMMO;
	wieldPosition = SLOT_HAND;
	ammoType = AMMO_NONE;
	ammoAction = AMMOACTION_NONE;
	shootType = (ShootEffect_t)0;
	magicEffect = MAGIC_EFFECT_NONE;
	attack = extraAttack = 0;
	defense = extraDefense = 0;
	attackSpeed = 0;
	armor = 0;
	decayTo = -1;
	decayTime = 0;
	stopTime = false;
	corpseType = RACE_NONE;
	fluidSource = FLUID_NONE;
	clientCharges = false;
	allowDistRead = false;

	isVertical = isHorizontal = isHangable = false;
	lightLevel = lightColor = 0;

	maxTextLen = 0;
	canReadText = canWriteText = false;
	writeOnceItemId = 0;

	transformEquipTo = transformDeEquipTo = 0;
	showDuration = showCharges = showAttributes = false;
	charges	= 0;
	hitChance = maxHitChance = breakChance = -1;
	shootRange = 1;

	condition = NULL;
	combatType = COMBAT_NONE;

	replaceable = true;
	worth = 0;

	bedPartnerDir = NORTH;
	transformUseTo[PLAYERSEX_FEMALE] = 0;
	transformUseTo[PLAYERSEX_MALE] = 0;
	transformToFree = 0;
	levelDoor = 0;

	memset(floorChange, 0, sizeof(floorChange));
}

ItemType::~ItemType()
{
	delete condition;
}

void Items::clear()
{
	//TODO: clear items?
	moneyMap.clear();
	randomizationMap.clear();
	reverseItemMap.clear();
}

bool Items::reload()
{
	//TODO: reload items?
	/*for(ItemMap::iterator it = items.begin(); it != items.end(); ++it)
		delete it->second->condition;

	clear();
	return loadFromXml();*/
	return false;
}

int32_t Items::loadFromOtb(std::string file)
{
	FileLoader f;
	if(!f.openFile(file.c_str(), false, true))
		return f.getError();

	uint32_t type;
	NODE node = f.getChildNode(NO_NODE, type);

	PropStream props;
	if(f.getProps(node, props))
	{
		//4 byte flags
		//attributes
		//0x01 = version data
		uint32_t flags;
		if(!props.GET_ULONG(flags))
			return ERROR_INVALID_FORMAT;

		attribute_t attr;
		if(!props.GET_VALUE(attr))
			return ERROR_INVALID_FORMAT;

		if(attr == ROOT_ATTR_VERSION)
		{
			datasize_t length = 0;
			if(!props.GET_VALUE(length))
				return ERROR_INVALID_FORMAT;

			if(length != sizeof(VERSIONINFO))
				return ERROR_INVALID_FORMAT;

			VERSIONINFO *vi;
			if(!props.GET_STRUCT(vi))
				return ERROR_INVALID_FORMAT;

			Items::dwMajorVersion = vi->dwMajorVersion; //items otb format file version
			Items::dwMinorVersion = vi->dwMinorVersion; //client version
			Items::dwBuildNumber = vi->dwBuildNumber; //revision
		}
	}

	if(Items::dwMajorVersion == 0xFFFFFFFF)
		std::cout << "[Warning - Items::loadFromOtb] items.otb using generic client version." << std::endl;
	else if(Items::dwMajorVersion < 3)
	{
		std::cout << "[Error - Items::loadFromOtb] Old version detected, a newer version of items.otb is required." << std::endl;
		return ERROR_INVALID_FORMAT;
	}
	else if(Items::dwMajorVersion > 3)
	{
		std::cout << "[Error - Items::loadFromOtb] New version detected, an older version of items.otb is required." << std::endl;
		return ERROR_INVALID_FORMAT;
	}
	else if(Items::dwMinorVersion != CLIENT_VERSION_854)
	{
		std::cout << "[Error - Items::loadFromOtb] Another (client) version of items.otb is required." << std::endl;
		return ERROR_INVALID_FORMAT;
	}

	uint16_t lastId = 99;
	for(node = f.getChildNode(node, type); node != NO_NODE; node = f.getNextNode(node, type))
	{
		PropStream props;
		if(!f.getProps(node, props))
			return f.getError();

		ItemType* iType = new ItemType();
		iType->group = (itemgroup_t)type;

		flags_t flags;
		switch(type)
		{
			case ITEM_GROUP_CONTAINER:
				iType->type = ITEM_TYPE_CONTAINER;
				break;
			case ITEM_GROUP_DOOR:
				//not used
				iType->type = ITEM_TYPE_DOOR;
				break;
			case ITEM_GROUP_MAGICFIELD:
				//not used
				iType->type = ITEM_TYPE_MAGICFIELD;
				break;
			case ITEM_GROUP_TELEPORT:
				//not used
				iType->type = ITEM_TYPE_TELEPORT;
				break;
			case ITEM_GROUP_NONE:
			case ITEM_GROUP_GROUND:
			case ITEM_GROUP_SPLASH:
			case ITEM_GROUP_FLUID:
			case ITEM_GROUP_CHARGES:
			case ITEM_GROUP_DEPRECATED:
				break;
			default:
				return ERROR_INVALID_FORMAT;
		}

		//read 4 byte flags
		if(!props.GET_VALUE(flags))
			return ERROR_INVALID_FORMAT;

		iType->blockSolid = hasBitSet(FLAG_BLOCK_SOLID, flags);
		iType->blockProjectile = hasBitSet(FLAG_BLOCK_PROJECTILE, flags);
		iType->blockPathFind = hasBitSet(FLAG_BLOCK_PATHFIND, flags);
		iType->hasHeight = hasBitSet(FLAG_HAS_HEIGHT, flags);
		iType->useable = hasBitSet(FLAG_USEABLE, flags);
		iType->pickupable = hasBitSet(FLAG_PICKUPABLE, flags);
		iType->moveable = hasBitSet(FLAG_MOVEABLE, flags);
		iType->stackable = hasBitSet(FLAG_STACKABLE, flags);

		iType->alwaysOnTop = hasBitSet(FLAG_ALWAYSONTOP, flags);
		iType->isVertical = hasBitSet(FLAG_VERTICAL, flags);
		iType->isHorizontal = hasBitSet(FLAG_HORIZONTAL, flags);
		iType->isHangable = hasBitSet(FLAG_HANGABLE, flags);
		iType->allowDistRead = hasBitSet(FLAG_ALLOWDISTREAD, flags);
		iType->rotable = hasBitSet(FLAG_ROTABLE, flags);
		iType->canReadText = hasBitSet(FLAG_READABLE, flags);
		iType->clientCharges = hasBitSet(FLAG_CLIENTCHARGES, flags);
		iType->lookThrough = hasBitSet(FLAG_LOOKTHROUGH, flags);

		attribute_t attr;
		while(props.GET_VALUE(attr))
		{
			//size of data
			datasize_t length = 0;
			if(!props.GET_VALUE(length))
			{
				delete iType;
				return ERROR_INVALID_FORMAT;
			}

			switch(attr)
			{
				case ITEM_ATTR_SERVERID:
				{
					if(length != sizeof(uint16_t))
						return ERROR_INVALID_FORMAT;

					uint16_t serverId;
					if(!props.GET_USHORT(serverId))
						return ERROR_INVALID_FORMAT;

					if(serverId > 20000 && serverId < 20100)
						serverId = serverId - 20000;
					else if(lastId > 99 && lastId != serverId - 1)
					{
						static ItemType dummyItemType;
						while(lastId != serverId - 1)
						{
							dummyItemType.id = ++lastId;
							items.addElement(&dummyItemType, lastId);
						}
					}

					iType->id = serverId;
					lastId = serverId;
					break;
				}
				case ITEM_ATTR_CLIENTID:
				{
					if(length != sizeof(uint16_t))
						return ERROR_INVALID_FORMAT;

					uint16_t clientId;
					if(!props.GET_USHORT(clientId))
						return ERROR_INVALID_FORMAT;

					iType->clientId = clientId;
					break;
				}
				case ITEM_ATTR_SPEED:
				{
					if(length != sizeof(uint16_t))
						return ERROR_INVALID_FORMAT;

					uint16_t speed;
					if(!props.GET_USHORT(speed))
						return ERROR_INVALID_FORMAT;

					iType->speed = speed;
					break;
				}
				case ITEM_ATTR_LIGHT2:
				{
					if(length != sizeof(lightBlock2))
						return ERROR_INVALID_FORMAT;

					lightBlock2* block;
					if(!props.GET_STRUCT(block))
						return ERROR_INVALID_FORMAT;

					iType->lightLevel = block->lightLevel;
					iType->lightColor = block->lightColor;
					break;
				}
				case ITEM_ATTR_TOPORDER:
				{
					if(length != sizeof(uint8_t))
						return ERROR_INVALID_FORMAT;

					uint8_t topOrder;
					if(!props.GET_UCHAR(topOrder))
						return ERROR_INVALID_FORMAT;

					iType->alwaysOnTopOrder = topOrder;
					break;
				}
				default:
				{
					//skip unknown attributes
					if(!props.SKIP_N(length))
						return ERROR_INVALID_FORMAT;

					break;
				}
			}
		}

		// store the found item
		items.addElement(iType, iType->id);
		if(iType->clientId)
			reverseItemMap[iType->clientId] = iType->id;
	}

	return ERROR_NONE;
}

bool Items::loadFromXml()
{
	xmlDocPtr itemDoc = xmlParseFile(getFilePath(FILE_TYPE_OTHER, "items/items.xml").c_str()),
		paletteDoc = xmlParseFile(getFilePath(FILE_TYPE_OTHER, "items/randomization.xml").c_str());
	if(!itemDoc)
	{
		std::cout << "[Warning - Items::loadFromXml] Cannot load items file." << std::endl;
		std::cout << getLastXMLError() << std::endl;
		return false;
	}

	if(!paletteDoc)
	{
		std::cout << "[Warning - Items::loadFromXml] Cannot load randomization file." << std::endl;
		std::cout << getLastXMLError() << std::endl;
		return false;
	}

	xmlNodePtr itemRoot = xmlDocGetRootElement(itemDoc), paletteRoot = xmlDocGetRootElement(paletteDoc);
	if(xmlStrcmp(itemRoot->name,(const xmlChar*)"items"))
	{
		xmlFreeDoc(itemDoc);
		xmlFreeDoc(paletteDoc);

		std::cout << "[Warning - Items::loadFromXml] Malformed items file." << std::endl;
		return false;
	}

	if(xmlStrcmp(paletteRoot->name,(const xmlChar*)"randomization"))
	{
		xmlFreeDoc(itemDoc);
		xmlFreeDoc(paletteDoc);

		std::cout << "[Warning - Items::loadFromXml] Malformed randomization file." << std::endl;
		return false;
	}

	IntegerVec intVector, endVector;
	std::string strValue, endValue;
	StringVec strVector;

	int32_t intValue, id = 0, endId = 0, fromId = 0, toId = 0;
	for(xmlNodePtr itemNode = itemRoot->children; itemNode; itemNode = itemNode->next)
	{
		if(xmlStrcmp(itemNode->name,(const xmlChar*)"item"))
			continue;

		if(readXMLInteger(itemNode, "id", intValue))
			parseItemNode(itemNode, intValue);
		else if(readXMLString(itemNode, "fromid", strValue) && readXMLString(itemNode, "toid", endValue))
		{
			intVector = vectorAtoi(explodeString(strValue, ";"));
			endVector = vectorAtoi(explodeString(endValue, ";"));
			if(intVector[0] && endVector[0] && intVector.size() == endVector.size())
			{
				size_t size = intVector.size();
				for(size_t i = 0; i < size; ++i)
				{
					parseItemNode(itemNode, intVector[i]);
					while(intVector[i] < endVector[i])
						parseItemNode(itemNode, ++intVector[i]);
				}
			}
			else
				std::cout << "[Warning - Items::loadFromXml] Malformed entry (from: \"" << strValue << "\", to: \"" << endValue << "\")" << std::endl;
		}
		else
			std::cout << "[Warning - Items::loadFromXml] No itemid found" << std::endl;
	}

	xmlFreeDoc(itemDoc);
	for(uint32_t i = 0; i < Item::items.size(); ++i) //lets do some checks...
	{
		const ItemType* it = Item::items.getElement(i);
		if(!it)
			continue;

		//check bed items
		if((it->transformToFree || it->transformUseTo[PLAYERSEX_FEMALE] || it->transformUseTo[PLAYERSEX_MALE]) && it->type != ITEM_TYPE_BED)
			std::cout << "[Warning - Items::loadFromXml] Item " << it->id << " is not set as a bed-type." << std::endl;
	}

	for(xmlNodePtr paletteNode = paletteRoot->children; paletteNode; paletteNode = paletteNode->next)
	{
		if(!xmlStrcmp(paletteNode->name, (const xmlChar*)"config"))
		{
			if(readXMLInteger(paletteNode, "chance", intValue) || readXMLInteger(paletteNode, "defaultChance", intValue))
			{
				if(intValue > 100)
				{
					intValue = 100;
					std::cout << "[Warning - Items::loadFromXml] Randomize chance cannot be higher than 100." << std::endl;
				}

				m_randomizationChance = intValue;
			}
		}
		else if(!xmlStrcmp(paletteNode->name, (const xmlChar*)"palette"))
		{
			if(readXMLString(paletteNode, "randomize", strValue))
			{
				std::vector<int32_t> itemList = vectorAtoi(explodeString(strValue, ";"));
				if(itemList.size() >= 2)
				{
					if(itemList[0] < itemList[1])
					{
						fromId = itemList[0];
						toId = itemList[1];
					}
					else
						std::cout << "[Warning - Items::loadFromXml] Randomize min cannot be higher than max." << std::endl;
				}

				int32_t chance = getRandomizationChance();
				if(readXMLInteger(paletteNode, "chance", intValue))
				{
					if(intValue > 100)
					{
						intValue = 100;
						std::cout << "[Warning: Items::loadRandomization] Randomize chance cannot be higher than 100." << std::endl;
					}

					chance = intValue;
				}

				if(readXMLInteger(paletteNode, "itemid", id))
					parseRandomizationBlock(id, fromId, toId, chance);
				else if(readXMLInteger(paletteNode, "fromid", id) && readXMLInteger(paletteNode, "toid", endId))
				{
					parseRandomizationBlock(id, fromId, toId, chance);
					while(id < endId)
						parseRandomizationBlock(++id, fromId, toId, chance);
				}
			}
		}
	}

	xmlFreeDoc(paletteDoc);
	return true;
}

void Items::parseItemNode(xmlNodePtr itemNode, uint32_t id)
{
	int32_t intValue;
	std::string strValue;

	if(id > 20000 && id < 20100)
	{
		id = id - 20000;

		ItemType* iType = new ItemType();
		iType->id = id;
		items.addElement(iType, iType->id);
	}

	ItemType& it = Item::items.getItemType(id);
	if(!it.name.empty() && (!readXMLString(itemNode, "override", strValue) || !booleanString(strValue)))
		std::cout << "[Warning - Items::loadFromXml] Duplicate registered item with id " << id << std::endl;

	if(readXMLString(itemNode, "name", strValue))
		it.name = strValue;

	if(readXMLString(itemNode, "article", strValue))
		it.article = strValue;

	if(readXMLString(itemNode, "plural", strValue))
		it.pluralName = strValue;

	xmlNodePtr itemAttributesNode = itemNode->children;
	while(itemAttributesNode)
	{
		if(readXMLString(itemAttributesNode, "key", strValue))
		{
			std::string tmpStrValue = asLowerCaseString(strValue);
			auto parseAttribute = ItemParseAttributesMap.find(tmpStrValue);
			if (parseAttribute != ItemParseAttributesMap.end()) {
				ItemParseAttributes_t parseType = parseAttribute->second;
				switch (parseType) {
					case ITEM_PARSE_TYPE: {
						if (readXMLString(itemAttributesNode, "value", strValue))
						{
							tmpStrValue = asLowerCaseString(strValue);
							if (tmpStrValue == "container")
							{
								it.type = ITEM_TYPE_CONTAINER;
								it.group = ITEM_GROUP_CONTAINER;
							}
							else if (tmpStrValue == "key")
								it.type = ITEM_TYPE_KEY;
							else if (tmpStrValue == "magicfield")
								it.type = ITEM_TYPE_MAGICFIELD;
							else if (tmpStrValue == "depot")
								it.type = ITEM_TYPE_DEPOT;
							else if (tmpStrValue == "mailbox")
								it.type = ITEM_TYPE_MAILBOX;
							else if (tmpStrValue == "trashholder")
								it.type = ITEM_TYPE_TRASHHOLDER;
							else if (tmpStrValue == "teleport")
								it.type = ITEM_TYPE_TELEPORT;
							else if (tmpStrValue == "door")
								it.type = ITEM_TYPE_DOOR;
							else if (tmpStrValue == "bed")
								it.type = ITEM_TYPE_BED;
							else
								std::cout << "[Warning - Items::loadFromXml] Unknown type " << strValue << std::endl;
						}
						break;
					}

					case ITEM_PARSE_NAME: {
						if (readXMLString(itemAttributesNode, "value", strValue))
							it.name = strValue;
						break;
					}

					case ITEM_PARSE_ARTICLE: {
						if (readXMLString(itemAttributesNode, "value", strValue))
							it.article = strValue;
						break;
					}

					case ITEM_PARSE_PLURAL: {
						if (readXMLString(itemAttributesNode, "value", strValue))
							it.pluralName = strValue;
						break;
					}

					case ITEM_PARSE_DESCRIPTION: {
						if (readXMLString(itemAttributesNode, "value", strValue))
							it.description = strValue;
						break;
					}

					case ITEM_PARSE_RUNESPELLNAME: {
						if (readXMLString(itemAttributesNode, "value", strValue))
							it.runeSpellName = strValue;
						break;
					}

					case ITEM_PARSE_WEIGHT: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.weight = intValue / 100.f;
						break;
					}

					case ITEM_PARSE_SHOWCOUNT: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.showCount = (intValue != 0);
						break;
					}

					case ITEM_PARSE_ARMOR: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.armor = intValue;
						break;
					}

					case ITEM_PARSE_DEFENSE: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.defense = intValue;
						break;
					}

					case ITEM_PARSE_EXTRADEF: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.extraDefense = intValue;
						break;
					}

					case ITEM_PARSE_ATTACK: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.attack = intValue;
						break;
					}

					case ITEM_PARSE_EXTRAATTACK: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.extraAttack = intValue;
						break;
					}

					case ITEM_PARSE_ATTACK_SPEED: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.attackSpeed = intValue;
						break;
					}

					case ITEM_PARSE_ROTATETO: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.rotateTo = intValue;
						break;
					}

					case ITEM_PARSE_MOVEABLE: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.moveable = (intValue != 0);
						break;
					}

					case ITEM_PARSE_BLOCKPROJECTILE: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.blockProjectile = (intValue != 0);
						break;
					}

					case ITEM_PARSE_PICKUPABLE: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.allowPickupable = (intValue != 0);
						break;
					}

					case ITEM_PARSE_FLOORCHANGE: {

						if (readXMLString(itemAttributesNode, "value", strValue))
						{
							tmpStrValue = asLowerCaseString(strValue);
							if (tmpStrValue == "down")
								it.floorChange[CHANGE_DOWN] = true;
							else if (tmpStrValue == "north")
								it.floorChange[CHANGE_NORTH] = true;
							else if (tmpStrValue == "south")
								it.floorChange[CHANGE_SOUTH] = true;
							else if (tmpStrValue == "west")
								it.floorChange[CHANGE_WEST] = true;
							else if (tmpStrValue == "east")
								it.floorChange[CHANGE_EAST] = true;
							else if (tmpStrValue == "northex")
								it.floorChange[CHANGE_NORTH_EX] = true;
							else if (tmpStrValue == "southex")
								it.floorChange[CHANGE_SOUTH_EX] = true;
							else if (tmpStrValue == "westex")
								it.floorChange[CHANGE_WEST_EX] = true;
							else if (tmpStrValue == "eastex")
								it.floorChange[CHANGE_EAST_EX] = true;
							else {
								std::cout << "[Warning - Items::loadFromXml] Unknown floorChange: " << tmpStrValue << std::endl;
							}
						}
						break;
					}

					case ITEM_PARSE_CORPSETYPE: {
						tmpStrValue = asLowerCaseString(strValue);
						if (readXMLString(itemAttributesNode, "value", strValue))
						{
							tmpStrValue = asLowerCaseString(strValue);
							if (tmpStrValue == "venom")
								it.corpseType = RACE_VENOM;
							else if (tmpStrValue == "blood")
								it.corpseType = RACE_BLOOD;
							else if (tmpStrValue == "undead")
								it.corpseType = RACE_UNDEAD;
							else if (tmpStrValue == "fire")
								it.corpseType = RACE_FIRE;
							else if (tmpStrValue == "energy")
								it.corpseType = RACE_ENERGY;
							else
								std::cout << "[Warning - Items::loadFromXml] Unknown corpseType " << strValue << std::endl;
						}
						break;
					}

					case ITEM_PARSE_CONTAINERSIZE: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.maxItems = intValue;
						break;
					}

					case ITEM_PARSE_FLUIDSOURCE: {
						if (readXMLString(itemAttributesNode, "value", strValue))
						{
							tmpStrValue = asLowerCaseString(strValue);
							FluidTypes_t fluid = getFluidType(tmpStrValue);
							if (fluid != FLUID_NONE)
								it.fluidSource = fluid;
							else
								std::cout << "[Warning - Items::loadFromXml] Unknown fluidSource " << strValue << std::endl;
						}
						break;
					}

					case ITEM_PARSE_READABLE: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.canReadText = (intValue != 0);
						break;
					}

					case ITEM_PARSE_WRITEABLE: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
						{
							it.canWriteText = (intValue != 0);
							it.canReadText = (intValue != 0);
						}
						break;
					}

					case ITEM_PARSE_MAXTEXTLEN: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.maxTextLen = intValue;
						break;
					}

					case ITEM_PARSE_WRITEONCEITEMID: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.writeOnceItemId = intValue;
						break;
					}

					case ITEM_PARSE_WORTH: {

						if (readXMLInteger(itemAttributesNode, "value", intValue))
						{
							if (moneyMap.find(intValue) != moneyMap.end() && (!readXMLString(itemNode, "override", strValue) || !booleanString(strValue)))
								std::cout << "[Warning - Items::loadFromXml] Duplicated money item " << id << " with worth " << intValue << "!" << std::endl;
							else
							{
								moneyMap[intValue] = id;
								it.worth = intValue;
							}
						}
						break;
					}

					case ITEM_PARSE_FORCESERIALIZE: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.forceSerialize = (intValue != 0);
						break;
					}

					case ITEM_PARSE_LEVELDOOR: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.levelDoor = intValue;
						break;
					}

					case ITEM_PARSE_WEAPONTYPE: {
						if (readXMLString(itemAttributesNode, "value", strValue))
						{
							tmpStrValue = asLowerCaseString(strValue);
							if (tmpStrValue == "sword")
								it.weaponType = WEAPON_SWORD;
							else if (tmpStrValue == "club")
								it.weaponType = WEAPON_CLUB;
							else if (tmpStrValue == "axe")
								it.weaponType = WEAPON_AXE;
							else if (tmpStrValue == "shield")
								it.weaponType = WEAPON_SHIELD;
							else if (tmpStrValue == "distance")
								it.weaponType = WEAPON_DIST;
							else if (tmpStrValue == "wand" || tmpStrValue == "rod")
								it.weaponType = WEAPON_WAND;
							else if (tmpStrValue == "ammunition")
								it.weaponType = WEAPON_AMMO;
							else if (tmpStrValue == "fist")
								it.weaponType = WEAPON_FIST;
							else
								std::cout << "[Warning - Items::loadFromXml] Unknown weaponType " << strValue << std::endl;
						}
						break;
					}

					case ITEM_PARSE_SLOTTYPE: {
						if (readXMLString(itemAttributesNode, "value", strValue))
						{
							tmpStrValue = asLowerCaseString(strValue);
							if (tmpStrValue == "head")
							{
								it.slotPosition |= SLOTP_HEAD;
								it.wieldPosition = SLOT_HEAD;
							}
							else if (tmpStrValue == "body")
							{
								it.slotPosition |= SLOTP_ARMOR;
								it.wieldPosition = SLOT_ARMOR;
							}
							else if (tmpStrValue == "legs")
							{
								it.slotPosition |= SLOTP_LEGS;
								it.wieldPosition = SLOT_LEGS;
							}
							else if (tmpStrValue == "feet")
							{
								it.slotPosition |= SLOTP_FEET;
								it.wieldPosition = SLOT_FEET;
							}
							else if (tmpStrValue == "backpack")
							{
								it.slotPosition |= SLOTP_BACKPACK;
								it.wieldPosition = SLOT_BACKPACK;
							}
							else if (tmpStrValue == "two-handed")
							{
								it.slotPosition |= SLOTP_TWO_HAND;
								it.wieldPosition = SLOT_TWO_HAND;
							}
							else if (tmpStrValue == "necklace")
							{
								it.slotPosition |= SLOTP_NECKLACE;
								it.wieldPosition = SLOT_NECKLACE;
							}
							else if (tmpStrValue == "ring")
							{
								it.slotPosition |= SLOTP_RING;
								it.wieldPosition = SLOT_RING;
							}
							else if (tmpStrValue == "ammo")
								it.wieldPosition = SLOT_AMMO;
							else if (tmpStrValue == "hand")
								it.wieldPosition = SLOT_HAND;
							else
								std::cout << "[Warning - Items::loadFromXml] Unknown slotType " << strValue << std::endl;
						}
						break;
					}

					case ITEM_PARSE_AMMOTYPE: {
							if (readXMLString(itemAttributesNode, "value", strValue))
							{
								it.ammoType = getAmmoType(strValue);
								if (it.ammoType == AMMO_NONE)
									std::cout << "[Warning - Items::loadFromXml] Unknown ammoType " << strValue << std::endl;
							}
						break;
					}

					case ITEM_PARSE_SHOOTTYPE: {
						if (readXMLString(itemAttributesNode, "value", strValue))
						{
							ShootEffect_t shoot = getShootType(strValue);
							if (shoot != SHOOT_EFFECT_UNKNOWN)
								it.shootType = shoot;
							else
								std::cout << "[Warning - Items::loadFromXml] Unknown shootType " << strValue << std::endl;
						}
						break;
					}

					case ITEM_PARSE_EFFECT: {
						if (readXMLString(itemAttributesNode, "value", strValue))
						{
							MagicEffect_t effect = getMagicEffect(strValue);
							if (effect != MAGIC_EFFECT_UNKNOWN)
								it.magicEffect = effect;
							else
								std::cout << "[Warning - Items::loadFromXml] Unknown effect " << strValue << std::endl;
						}
						break;
					}

					case ITEM_PARSE_RANGE: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.shootRange = intValue;
						break;
					}

					case ITEM_PARSE_STOPDURATION: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.stopTime = (intValue != 0);
						break;
					}

					case ITEM_PARSE_DECAYTO: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.decayTo = intValue;
						break;
					}

					case ITEM_PARSE_TRANSFORMEQUIPTO: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.transformEquipTo = intValue;
						break;
					}

					case ITEM_PARSE_TRANSFORMDEEQUIPTO: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.transformDeEquipTo = intValue;
						break;
					}

					case ITEM_PARSE_DURATION: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.decayTime = std::max((int32_t)0, intValue);
						break;
					}

					case ITEM_PARSE_SHOWDURATION: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.showDuration = (intValue != 0);
						break;
					}

					case ITEM_PARSE_CHARGES: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.charges = intValue;
						break;
					}

					case ITEM_PARSE_SHOWCHARGES: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.showCharges = (intValue != 0);
						break;
					}

					case ITEM_PARSE_SHOWATTRIBUTES: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.showAttributes = (intValue != 0);
						break;
					}

					case ITEM_PARSE_BREAKCHANCE: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.breakChance = std::max(0, std::min(100, intValue));
						break;
					}

					case ITEM_PARSE_AMMOACTION: {
						if (readXMLString(itemAttributesNode, "value", strValue))
						{
							AmmoAction_t ammo = getAmmoAction(strValue);
							if (ammo != AMMOACTION_NONE)
								it.ammoAction = ammo;
							else
								std::cout << "[Warning - Items::loadFromXml] Unknown ammoAction " << strValue << std::endl;
						}
						break;
					}

					case ITEM_PARSE_HITCHANCE: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.hitChance = std::max(0, std::min(100, intValue));
						break;
					}

					case ITEM_PARSE_MAXHITCHANCE: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.maxHitChance = std::max(0, std::min(100, intValue));
						break;
					}

					case ITEM_PARSE_PREVENTLOSS: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.preventLoss = (intValue != 0);
						break;
					}

					case ITEM_PARSE_PREVENTDROP: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.preventDrop = (intValue != 0);
						break;
					}

					case ITEM_PARSE_INVISIBLE: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.invisible = (intValue != 0);
						break;
					}

					case ITEM_PARSE_SPEED: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.speed = intValue;
						break;
					}

					case ITEM_PARSE_HEALTHGAIN: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
						{
							it.abilities.regeneration = true;
							it.abilities.healthGain = intValue;
						}
						break;
					}

					case ITEM_PARSE_HEALTHTICKS: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
						{
							it.abilities.regeneration = true;
							it.abilities.healthTicks = intValue;
						}
						break;
					}

					case ITEM_PARSE_MANAGAIN: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
						{
							it.abilities.regeneration = true;
							it.abilities.manaGain = intValue;
						}
						break;
					}

					case ITEM_PARSE_MANATICKS: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
						{
							it.abilities.regeneration = true;
							it.abilities.manaTicks = intValue;
						}
						break;
					}

					case ITEM_PARSE_MANASHIELD: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.manaShield = (intValue != 0);
						break;
					}

					case ITEM_PARSE_SKILLSWORD: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.skills[SKILL_SWORD] = intValue;
						break;
					}

					case ITEM_PARSE_SKILLAXE: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.skills[SKILL_AXE] = intValue;
						break;
					}

					case ITEM_PARSE_SKILLCLUB: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.skills[SKILL_CLUB] = intValue;
						break;
					}

					case ITEM_PARSE_SKILLDIST: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.skills[SKILL_DIST] = intValue;
						break;
					}

					case ITEM_PARSE_SKILLFISH: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.skills[SKILL_FISH] = intValue;
						break;
					}

					case ITEM_PARSE_SKILLSHIELD: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.skills[SKILL_SHIELD] = intValue;
						break;
					}

					case ITEM_PARSE_SKILLFIST: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.skills[SKILL_FIST] = intValue;
						break;
					}

					case ITEM_PARSE_MAXHITPOINTS: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.stats[STAT_MAXHEALTH] = intValue;
						break;
					}

					case ITEM_PARSE_MAXHITPOINTSPERCENT: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.statsPercent[STAT_MAXHEALTH] = intValue;
						break;
					}

					case ITEM_PARSE_MAXMANAPOINTS: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.stats[STAT_MAXMANA] = intValue;
						break;
					}

					case ITEM_PARSE_SOULPOINTS: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.stats[STAT_SOUL] = intValue;
						break;
					}

					case ITEM_PARSE_SOULPOINTSPERCENT: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.statsPercent[STAT_SOUL] = intValue;
						break;
					}

					case ITEM_PARSE_MAGICPOINTS: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.stats[STAT_MAGICLEVEL] = intValue;
						break;
					}

					case ITEM_PARSE_MAGICPOINTSPERCENT: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.statsPercent[STAT_MAGICLEVEL] = intValue;
						break;
					}

					case ITEM_PARSE_INCREASEMAGICVALUE: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.increment[MAGIC_VALUE] = intValue;
						break;
					}

					case ITEM_PARSE_INCREASEMAGICPERCENT: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.increment[MAGIC_PERCENT] = intValue;
						break;
					}

					case ITEM_PARSE_INCREASEHEALINGVALUE: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.increment[HEALING_VALUE] = intValue;
						break;
					}

					case ITEM_PARSE_INCREASEHEALINGPERCENT: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.increment[HEALING_PERCENT] = intValue;
						break;
					}

					case ITEM_PARSE_ABSORBPERCENTALL: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
						{
							for (int32_t i = COMBAT_FIRST; i <= COMBAT_LAST; i++)
								it.abilities.absorb[i] += intValue;
						}
						break;
					}

					case ITEM_PARSE_ABSORBPERCENTELEMENTS: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
						{
							it.abilities.absorb[COMBAT_ENERGYDAMAGE] += intValue;
							it.abilities.absorb[COMBAT_FIREDAMAGE] += intValue;
							it.abilities.absorb[COMBAT_EARTHDAMAGE] += intValue;
							it.abilities.absorb[COMBAT_ICEDAMAGE] += intValue;
						}
						break;
					}

					case ITEM_PARSE_ABSORBPERCENTMAGIC: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
						{
							it.abilities.absorb[COMBAT_ENERGYDAMAGE] += intValue;
							it.abilities.absorb[COMBAT_FIREDAMAGE] += intValue;
							it.abilities.absorb[COMBAT_EARTHDAMAGE] += intValue;
							it.abilities.absorb[COMBAT_ICEDAMAGE] += intValue;
							it.abilities.absorb[COMBAT_HOLYDAMAGE] += intValue;
							it.abilities.absorb[COMBAT_DEATHDAMAGE] += intValue;
						}
						break;
					}

					case ITEM_PARSE_ABSORBPERCENTENERGY: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.absorb[COMBAT_ENERGYDAMAGE] += intValue;
						break;
					}

					case ITEM_PARSE_ABSORBPERCENTFIRE: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.absorb[COMBAT_FIREDAMAGE] += intValue;
						break;
					}

					case ITEM_PARSE_ABSORBPERCENTPOISON: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.absorb[COMBAT_EARTHDAMAGE] += intValue;
						break;
					}

					case ITEM_PARSE_ABSORBPERCENTICE: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.absorb[COMBAT_ICEDAMAGE] += intValue;
						break;
					}

					case ITEM_PARSE_ABSORBPERCENTHOLY: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.absorb[COMBAT_HOLYDAMAGE] += intValue;
						break;
					}

					case ITEM_PARSE_ABSORBPERCENTDEATH: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.absorb[COMBAT_DEATHDAMAGE] += intValue;
						break;
					}

					case ITEM_PARSE_ABSORBPERCENTLIFEDRAIN: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.absorb[COMBAT_LIFEDRAIN] += intValue;
						break;
					}

					case ITEM_PARSE_ABSORBPERCENTMANADRAIN: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.absorb[COMBAT_MANADRAIN] += intValue;
						break;
					}

					case ITEM_PARSE_ABSORBPERCENTDROWN: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.absorb[COMBAT_DROWNDAMAGE] += intValue;
						break;
					}

					case ITEM_PARSE_ABSORBPERCENTPHYSICAL: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.absorb[COMBAT_PHYSICALDAMAGE] += intValue;
						break;
					}

					case ITEM_PARSE_ABSORBPERCENTHEALING: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.absorb[COMBAT_HEALING] += intValue;
						break;
					}

					case ITEM_PARSE_ABSORBPERCENTUNDEFINED: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.absorb[COMBAT_UNDEFINEDDAMAGE] += intValue;
						break;
					}

					case ITEM_PARSE_REFLECTPERCENTALL: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
						{
							for (int32_t i = COMBAT_FIRST; i <= COMBAT_LAST; i++)
								it.abilities.reflect[REFLECT_PERCENT][i] += intValue;
						}
						break;
					}

					case ITEM_PARSE_REFLECTPERCENTELEMENTS: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
						{
							it.abilities.reflect[REFLECT_PERCENT][COMBAT_ENERGYDAMAGE] += intValue;
							it.abilities.reflect[REFLECT_PERCENT][COMBAT_FIREDAMAGE] += intValue;
							it.abilities.reflect[REFLECT_PERCENT][COMBAT_EARTHDAMAGE] += intValue;
							it.abilities.reflect[REFLECT_PERCENT][COMBAT_ICEDAMAGE] += intValue;
						}
						break;
					}

					case ITEM_PARSE_REFLECTPERCENTMAGIC: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
						{
							it.abilities.reflect[REFLECT_PERCENT][COMBAT_ENERGYDAMAGE] += intValue;
							it.abilities.reflect[REFLECT_PERCENT][COMBAT_FIREDAMAGE] += intValue;
							it.abilities.reflect[REFLECT_PERCENT][COMBAT_EARTHDAMAGE] += intValue;
							it.abilities.reflect[REFLECT_PERCENT][COMBAT_ICEDAMAGE] += intValue;
							it.abilities.reflect[REFLECT_PERCENT][COMBAT_HOLYDAMAGE] += intValue;
							it.abilities.reflect[REFLECT_PERCENT][COMBAT_DEATHDAMAGE] += intValue;
						}
						break;
					}

					case ITEM_PARSE_REFLECTPERCENTENERGY: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.reflect[REFLECT_PERCENT][COMBAT_ENERGYDAMAGE] += intValue;
						break;
					}

					case ITEM_PARSE_REFLECTPERCENTFIRE: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.reflect[REFLECT_PERCENT][COMBAT_FIREDAMAGE] += intValue;
						break;
					}

					case ITEM_PARSE_REFLECTPERCENTPOISON: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.reflect[REFLECT_PERCENT][COMBAT_EARTHDAMAGE] += intValue;
						break;
					}

					case ITEM_PARSE_REFLECTPERCENTICE: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.reflect[REFLECT_PERCENT][COMBAT_ICEDAMAGE] += intValue;
						break;
					}

					case ITEM_PARSE_REFLECTPERCENTHOLY: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.reflect[REFLECT_PERCENT][COMBAT_HOLYDAMAGE] += intValue;
						break;
					}

					case ITEM_PARSE_REFLECTPERCENTDEATH: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.reflect[REFLECT_PERCENT][COMBAT_DEATHDAMAGE] += intValue;
						break;
					}

					case ITEM_PARSE_REFLECTPERCENTLIFEDRAIN: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.reflect[REFLECT_PERCENT][COMBAT_LIFEDRAIN] += intValue;
						break;
					}

					case ITEM_PARSE_REFLECTPERCENTMANADRAIN: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.reflect[REFLECT_PERCENT][COMBAT_MANADRAIN] += intValue;
						break;
					}

					case ITEM_PARSE_REFLECTPERCENTDROWN: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.reflect[REFLECT_PERCENT][COMBAT_DROWNDAMAGE] += intValue;
						break;
					}

					case ITEM_PARSE_REFLECTPERCENTPHYSICAL: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.reflect[REFLECT_PERCENT][COMBAT_PHYSICALDAMAGE] += intValue;
						break;
					}

					case ITEM_PARSE_REFLECTPERCENTHEALING: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.reflect[REFLECT_PERCENT][COMBAT_HEALING] += intValue;
						break;
					}

					case ITEM_PARSE_REFLECTPERCENTUNDEFINED: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.reflect[REFLECT_PERCENT][COMBAT_UNDEFINEDDAMAGE] += intValue;
						break;
					}

					case ITEM_PARSE_REFLECTCHANCEALL: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
						{
							for (int32_t i = COMBAT_FIRST; i <= COMBAT_LAST; i++)
								it.abilities.reflect[REFLECT_CHANCE][i] += intValue;
						}
						break;
					}

					case ITEM_PARSE_REFLECTCHANCEELEMENTS: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
						{
							it.abilities.reflect[REFLECT_CHANCE][COMBAT_ENERGYDAMAGE] += intValue;
							it.abilities.reflect[REFLECT_CHANCE][COMBAT_FIREDAMAGE] += intValue;
							it.abilities.reflect[REFLECT_CHANCE][COMBAT_EARTHDAMAGE] += intValue;
							it.abilities.reflect[REFLECT_CHANCE][COMBAT_ICEDAMAGE] += intValue;
						}
						break;
					}

					case ITEM_PARSE_REFLECTCHANCEMAGIC: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
						{
							it.abilities.reflect[REFLECT_CHANCE][COMBAT_ENERGYDAMAGE] += intValue;
							it.abilities.reflect[REFLECT_CHANCE][COMBAT_FIREDAMAGE] += intValue;
							it.abilities.reflect[REFLECT_CHANCE][COMBAT_EARTHDAMAGE] += intValue;
							it.abilities.reflect[REFLECT_CHANCE][COMBAT_ICEDAMAGE] += intValue;
							it.abilities.reflect[REFLECT_CHANCE][COMBAT_HOLYDAMAGE] += intValue;
							it.abilities.reflect[REFLECT_CHANCE][COMBAT_DEATHDAMAGE] += intValue;
						}
						break;
					}

					case ITEM_PARSE_REFLECTCHANCEENERGY: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.reflect[REFLECT_CHANCE][COMBAT_ENERGYDAMAGE] += intValue;
						break;
					}

					case ITEM_PARSE_REFLECTCHANCEFIRE: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.reflect[REFLECT_CHANCE][COMBAT_FIREDAMAGE] += intValue;
						break;
					}

					case ITEM_PARSE_REFLECTCHANCEPOISON: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.reflect[REFLECT_CHANCE][COMBAT_EARTHDAMAGE] += intValue;
						break;
					}

					case ITEM_PARSE_REFLECTCHANCEICE: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.reflect[REFLECT_CHANCE][COMBAT_ICEDAMAGE] += intValue;
						break;
					}

					case ITEM_PARSE_REFLECTCHANCEHOLY: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.reflect[REFLECT_CHANCE][COMBAT_HOLYDAMAGE] += intValue;
						break;
					}

					case ITEM_PARSE_REFLECTCHANCEDEATH: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.reflect[REFLECT_CHANCE][COMBAT_DEATHDAMAGE] += intValue;
						break;
					}

					case ITEM_PARSE_REFLECTCHANCELIFEDRAIN: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.reflect[REFLECT_CHANCE][COMBAT_LIFEDRAIN] += intValue;
						break;
					}

					case ITEM_PARSE_REFLECTCHANCEMANADRAIN: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.reflect[REFLECT_CHANCE][COMBAT_MANADRAIN] += intValue;
						break;
					}

					case ITEM_PARSE_REFLECTCHANCEDROWN: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.reflect[REFLECT_CHANCE][COMBAT_DROWNDAMAGE] += intValue;
						break;
					}

					case ITEM_PARSE_REFLECTCHANCEPHYSICAL: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.reflect[REFLECT_CHANCE][COMBAT_PHYSICALDAMAGE] += intValue;
						break;
					}

					case ITEM_PARSE_REFLECTCHANCEHEALING: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.reflect[REFLECT_CHANCE][COMBAT_HEALING] += intValue;
						break;
					}

					case ITEM_PARSE_REFLECTCHANCEUNDEFINED: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.abilities.reflect[REFLECT_CHANCE][COMBAT_UNDEFINEDDAMAGE] += intValue;
						break;
					}

					case ITEM_PARSE_SUPPRESSSHOCK: {
						if (readXMLInteger(itemAttributesNode, "value", intValue) && intValue != 0)
							it.abilities.conditionSuppressions |= CONDITION_ENERGY;
						break;
					}

					case ITEM_PARSE_SUPPRESSBURN: {
						if (readXMLInteger(itemAttributesNode, "value", intValue) && intValue != 0)
							it.abilities.conditionSuppressions |= CONDITION_FIRE;
						break;
					}

					case ITEM_PARSE_SUPPRESSPOISON: {
						if (readXMLInteger(itemAttributesNode, "value", intValue) && intValue != 0)
							it.abilities.conditionSuppressions |= CONDITION_POISON;
						break;
					}

					case ITEM_PARSE_SUPPRESSFREEZE: {
						if (readXMLInteger(itemAttributesNode, "value", intValue) && intValue != 0)
							it.abilities.conditionSuppressions |= CONDITION_FREEZING;
						break;
					}

					case ITEM_PARSE_SUPPRESSDAZZLE: {
						if (readXMLInteger(itemAttributesNode, "value", intValue) && intValue != 0)
							it.abilities.conditionSuppressions |= CONDITION_DAZZLED;
						break;
					}

					case ITEM_PARSE_SUPPRESSCURSE: {
						if (readXMLInteger(itemAttributesNode, "value", intValue) && intValue != 0)
							it.abilities.conditionSuppressions |= CONDITION_CURSED;
						break;
					}

					case ITEM_PARSE_SUPPRESSDROWN: {
						if (readXMLInteger(itemAttributesNode, "value", intValue) && intValue != 0)
							it.abilities.conditionSuppressions |= CONDITION_DROWN;
						break;
					}

					case ITEM_PARSE_SUPPRESSPHYSICAL: {
						if (readXMLInteger(itemAttributesNode, "value", intValue) && intValue != 0)
							it.abilities.conditionSuppressions |= CONDITION_PHYSICAL;
						break;
					}

					case ITEM_PARSE_SUPPRESSHASTE: {
						if (readXMLInteger(itemAttributesNode, "value", intValue) && intValue != 0)
							it.abilities.conditionSuppressions |= CONDITION_HASTE;
						break;
					}

					case ITEM_PARSE_SUPPRESSPARALYZE: {
						if (readXMLInteger(itemAttributesNode, "value", intValue) && intValue != 0)
							it.abilities.conditionSuppressions |= CONDITION_PARALYZE;
						break;
					}

					case ITEM_PARSE_SUPPRESSDRUNK: {
						if (readXMLInteger(itemAttributesNode, "value", intValue) && intValue != 0)
							it.abilities.conditionSuppressions |= CONDITION_DRUNK;
						break;
					}

					case ITEM_PARSE_SUPPRESSREGENERATION: {
						if (readXMLInteger(itemAttributesNode, "value", intValue) && intValue != 0)
							it.abilities.conditionSuppressions |= CONDITION_REGENERATION;
						break;
					}

					case ITEM_PARSE_SUPPRESSSOUL: {
						if (readXMLInteger(itemAttributesNode, "value", intValue) && intValue != 0)
							it.abilities.conditionSuppressions |= CONDITION_SOUL;
						break;
					}

					case ITEM_PARSE_SUPPRESSOUTFIT: {
						if (readXMLInteger(itemAttributesNode, "value", intValue) && intValue != 0)
							it.abilities.conditionSuppressions |= CONDITION_OUTFIT;
						break;
					}

					case ITEM_PARSE_SUPPRESSINVISIBLE: {
						if (readXMLInteger(itemAttributesNode, "value", intValue) && intValue != 0)
							it.abilities.conditionSuppressions |= CONDITION_INVISIBLE;
						break;
					}

					case ITEM_PARSE_SUPPRESSINFIGHT: {
						if (readXMLInteger(itemAttributesNode, "value", intValue) && intValue != 0)
							it.abilities.conditionSuppressions |= CONDITION_INFIGHT;
						break;
					}

					case ITEM_PARSE_SUPPRESSEXHAUST: {
						if (readXMLInteger(itemAttributesNode, "value", intValue) && intValue != 0)
							it.abilities.conditionSuppressions |= CONDITION_EXHAUST;
						break;
					}

					case ITEM_PARSE_SUPPRESSMUTED: {
						if (readXMLInteger(itemAttributesNode, "value", intValue) && intValue != 0)
							it.abilities.conditionSuppressions |= CONDITION_MUTED;
						break;
					}

					case ITEM_PARSE_SUPPRESSPACIFIED: {
						if (readXMLInteger(itemAttributesNode, "value", intValue) && intValue != 0)
							it.abilities.conditionSuppressions |= CONDITION_PACIFIED;
						break;
					}

					case ITEM_PARSE_SUPPRESSLIGHT: {
						if (readXMLInteger(itemAttributesNode, "value", intValue) && intValue != 0)
							it.abilities.conditionSuppressions |= CONDITION_LIGHT;
						break;
					}

					case ITEM_PARSE_SUPPRESSATTRIBUTES: {
						if (readXMLInteger(itemAttributesNode, "value", intValue) && intValue != 0)
							it.abilities.conditionSuppressions |= CONDITION_ATTRIBUTES;
						break;
					}

					case ITEM_PARSE_SUPPRESSMANASHIELD: {
						if (readXMLInteger(itemAttributesNode, "value", intValue) && intValue != 0)
							it.abilities.conditionSuppressions |= CONDITION_MANASHIELD;
						break;
					}

					case ITEM_PARSE_FIELD: {
						it.group = ITEM_GROUP_MAGICFIELD;
						it.type = ITEM_TYPE_MAGICFIELD;
						CombatType_t combatType = COMBAT_NONE;
						ConditionDamage* conditionDamage = NULL;

						if (readXMLString(itemAttributesNode, "value", strValue))
						{
							tmpStrValue = asLowerCaseString(strValue);
							if (tmpStrValue == "fire")
							{
								conditionDamage = new ConditionDamage(CONDITIONID_COMBAT, CONDITION_FIRE, false, 0);
								combatType = COMBAT_FIREDAMAGE;
							}
							else if (tmpStrValue == "energy")
							{
								conditionDamage = new ConditionDamage(CONDITIONID_COMBAT, CONDITION_ENERGY, false, 0);
								combatType = COMBAT_ENERGYDAMAGE;
							}
							else if (tmpStrValue == "earth" || tmpStrValue == "poison")
							{
								conditionDamage = new ConditionDamage(CONDITIONID_COMBAT, CONDITION_POISON, false, 0);
								combatType = COMBAT_EARTHDAMAGE;
							}
							else if (tmpStrValue == "ice" || tmpStrValue == "freezing")
							{
								conditionDamage = new ConditionDamage(CONDITIONID_COMBAT, CONDITION_FREEZING, false, 0);
								combatType = COMBAT_ICEDAMAGE;
							}
							else if (tmpStrValue == "holy" || tmpStrValue == "dazzled")
							{
								conditionDamage = new ConditionDamage(CONDITIONID_COMBAT, CONDITION_DAZZLED, false, 0);
								combatType = COMBAT_HOLYDAMAGE;
							}
							else if (tmpStrValue == "death" || tmpStrValue == "cursed")
							{
								conditionDamage = new ConditionDamage(CONDITIONID_COMBAT, CONDITION_CURSED, false, 0);
								combatType = COMBAT_DEATHDAMAGE;
							}
							else if (tmpStrValue == "drown")
							{
								conditionDamage = new ConditionDamage(CONDITIONID_COMBAT, CONDITION_DROWN, false, 0);
								combatType = COMBAT_DROWNDAMAGE;
							}
							else if (tmpStrValue == "physical")
							{
								conditionDamage = new ConditionDamage(CONDITIONID_COMBAT, CONDITION_PHYSICAL, false, 0);
								combatType = COMBAT_PHYSICALDAMAGE;
							}
							else
								std::cout << "[Warning - Items::loadFromXml] Unknown field value " << strValue << std::endl;

							if (combatType != COMBAT_NONE)
							{
								it.combatType = combatType;
								it.condition = conditionDamage;
								uint32_t ticks = 0;
								int32_t damage = 0, start = 0, count = 1;

								xmlNodePtr fieldAttributesNode = itemAttributesNode->children;
								while (fieldAttributesNode)
								{
									if (readXMLString(fieldAttributesNode, "key", strValue))
									{
										tmpStrValue = asLowerCaseString(strValue);
										if (tmpStrValue == "ticks")
										{
											if (readXMLInteger(fieldAttributesNode, "value", intValue))
												ticks = std::max(0, intValue);
										}

										if (tmpStrValue == "count")
										{
											if (readXMLInteger(fieldAttributesNode, "value", intValue))
												count = std::max(1, intValue);
										}

										if (tmpStrValue == "start")
										{
											if (readXMLInteger(fieldAttributesNode, "value", intValue))
												start = std::max(0, intValue);
										}

										if (tmpStrValue == "damage")
										{
											if (readXMLInteger(fieldAttributesNode, "value", intValue))
											{
												damage = -intValue;
												if (start > 0)
												{
													std::list<int32_t> damageList;
													ConditionDamage::generateDamageList(damage, start, damageList);

													for (std::list<int32_t>::iterator it = damageList.begin(); it != damageList.end(); ++it)
														conditionDamage->addDamage(1, ticks, -*it);

													start = 0;
												}
												else
													conditionDamage->addDamage(count, ticks, damage);
											}
										}
									}

									fieldAttributesNode = fieldAttributesNode->next;
								}

								if (conditionDamage->getTotalDamage() > 0)
									it.condition->setParam(CONDITIONPARAM_FORCEUPDATE, true);
							}
						}
						break;
					}

					case ITEM_PARSE_ELEMENTPHYSICAL: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
						{
							it.abilities.elementDamage = intValue;
							it.abilities.elementType = COMBAT_PHYSICALDAMAGE;
						}
						break;
					}

					case ITEM_PARSE_ELEMENTFIRE: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
						{
							it.abilities.elementDamage = intValue;
							it.abilities.elementType = COMBAT_FIREDAMAGE;
						}
						break;
					}

					case ITEM_PARSE_ELEMENTENERGY: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
						{
							it.abilities.elementDamage = intValue;
							it.abilities.elementType = COMBAT_ENERGYDAMAGE;
						}
						break;
					}

					case ITEM_PARSE_ELEMENTEARTH: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
						{
							it.abilities.elementDamage = intValue;
							it.abilities.elementType = COMBAT_EARTHDAMAGE;
						}
						break;
					}

					case ITEM_PARSE_ELEMENTICE: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
						{
							it.abilities.elementDamage = intValue;
							it.abilities.elementType = COMBAT_ICEDAMAGE;
						}
						break;
					}

					case ITEM_PARSE_ELEMENTHOLY: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
						{
							it.abilities.elementDamage = intValue;
							it.abilities.elementType = COMBAT_HOLYDAMAGE;
						}
						break;
					}

					case ITEM_PARSE_ELEMENTDEATH: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
						{
							it.abilities.elementDamage = intValue;
							it.abilities.elementType = COMBAT_DEATHDAMAGE;
						}
						break;
					}

					case ITEM_PARSE_ELEMENTLIFEDRAIN: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
						{
							it.abilities.elementDamage = intValue;
							it.abilities.elementType = COMBAT_LIFEDRAIN;
						}
						break;
					}

					case ITEM_PARSE_ELEMENTMANADRAIN: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
						{
							it.abilities.elementDamage = intValue;
							it.abilities.elementType = COMBAT_MANADRAIN;
						}
						break;
					}

					case ITEM_PARSE_ELEMENTHEALING: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
						{
							it.abilities.elementDamage = intValue;
							it.abilities.elementType = COMBAT_HEALING;
						}
						break;
					}

					case ITEM_PARSE_ELEMENTUNDEFINED: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
						{
							it.abilities.elementDamage = intValue;
							it.abilities.elementType = COMBAT_UNDEFINEDDAMAGE;
						}
						break;
					}

					case ITEM_PARSE_REPLACEABLE: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.replaceable = (intValue != 0);
						break;
					}

					case ITEM_PARSE_PARTNERDIRECTION: {
						if (readXMLString(itemAttributesNode, "value", strValue))
							it.bedPartnerDir = getDirection(strValue);
						break;
					}

					case ITEM_PARSE_MALETRANSFORMTO: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
						{
							it.transformUseTo[PLAYERSEX_MALE] = intValue;
							ItemType& ot = getItemType(intValue);
							if (!ot.transformToFree)
								ot.transformToFree = it.id;

							if (!it.transformUseTo[PLAYERSEX_FEMALE])
								it.transformUseTo[PLAYERSEX_FEMALE] = intValue;
						}
						break;
					}

					case ITEM_PARSE_FEMALETRANSFORMTO: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
						{
							it.transformUseTo[PLAYERSEX_FEMALE] = intValue;
							ItemType& ot = getItemType(intValue);
							if (!ot.transformToFree)
								ot.transformToFree = it.id;

							if (!it.transformUseTo[PLAYERSEX_MALE])
								it.transformUseTo[PLAYERSEX_MALE] = intValue;
						}
						break;
					}

					case ITEM_PARSE_TRANSFORMTO: {
						if (readXMLInteger(itemAttributesNode, "value", intValue))
							it.transformToFree = intValue;
						break;
					}

					default: {
						std::cout << "[Warning - Items::loadFromXml] Not configured key value: " << strValue << std::endl;
						break;
					}
				}
			}
		}

		itemAttributesNode = itemAttributesNode->next;
	}

	if(it.pluralName.empty() && !it.name.empty())
	{
		it.pluralName = it.name;
		if(it.showCount)
			it.pluralName += "s";
	}
}

void Items::parseRandomizationBlock(int32_t id, int32_t fromId, int32_t toId, int32_t chance)
{
	RandomizationMap::iterator it = randomizationMap.find(id);
	if(it != randomizationMap.end())
	{
		std::cout << "[Warning - Items::parseRandomizationBlock] Duplicated item with id: " << id << std::endl;
		return;
	}

	RandomizationBlock rand;
	rand.chance = chance;
	rand.fromRange = fromId;
	rand.toRange = toId;

	randomizationMap[id] = rand;
}

uint16_t Items::getRandomizedItem(uint16_t id)
{
	if(!g_config.getBool(ConfigManager::RANDOMIZE_TILES))
		return id;

	RandomizationBlock randomize = getRandomization(id);
	if(randomize.chance > 0 && random_range(0, 100) <= randomize.chance)
		id = random_range(randomize.fromRange, randomize.toRange);

	return id;
}

ItemType& Items::getItemType(int32_t id)
{
	ItemType* iType = items.getElement(id);
	if(iType)
		return *iType;

	#ifdef __DEBUG__
	std::cout << "[Warning - Items::getItemType] Unknown itemtype with id " << id << ", using defaults." << std::endl;
	#endif
	static ItemType dummyItemType; // use this for invalid ids
	return dummyItemType;
}

const ItemType& Items::getItemType(int32_t id) const
{
	if(ItemType* iType = items.getElement(id))
		return *iType;

	static ItemType dummyItemType; // use this for invalid ids
	return dummyItemType;
}

const ItemType& Items::getItemIdByClientId(int32_t spriteId) const
{
	uint32_t i = 100;
	ItemType* iType;
	do
	{
		if((iType = items.getElement(i)) && iType->clientId == spriteId)
			return *iType;

		i++;
	}
	while(iType);
	static ItemType dummyItemType; // use this for invalid ids
	return dummyItemType;
}

int32_t Items::getItemIdByName(const std::string& name)
{
	if(!name.empty())
	{
		uint32_t i = 100;
		ItemType* iType = NULL;
		do
		{
			if((iType = items.getElement(i)) && !strcasecmp(name.c_str(), iType->name.c_str()))
				return i;

			i++;
		}
		while(iType);
	}

	return -1;
}
