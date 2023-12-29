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

#ifndef __ACTIONS__
#define __ACTIONS__
#include "baseevents.h"

#include "luascript.h"
#include "thing.h"

class Action;
class Container;

using Action_Ptr = boost::shared_ptr<Action>;

enum ActionType_t
{
	ACTION_ANY,
	ACTION_UNIQUEID,
	ACTION_ACTIONID,
	ACTION_ITEMID,
	ACTION_RUNEID,
};

class Actions final : public BaseEvents
{
	public:
		Actions();

		~Actions() override;

		bool useItem(Player* player, const Position& pos, uint8_t index, Item* item);
		bool useItemEx(Player* player, const Position& fromPos, const Position& toPos,
			uint8_t toStackPos, Item* item, bool isHotkey, uint32_t creatureId = 0);

		ReturnValue canUse(const Player* player, const Position& pos);
		ReturnValue canUse(const Player* player, const Position& pos, const Item* item);
		ReturnValue canUseFar(const Creature* creature, const Position& toPos, bool checkLineOfSight);
		bool hasAction(const Item* item) const {return getAction(item);}

	protected:
		[[nodiscard]] std::string getScriptBaseName() const override {return "actions";}

		void clear() override;

		Event_Ptr getEvent(const std::string& nodeName) override;

		bool registerEvent(Event_Ptr event, xmlNodePtr p, bool override) override;

		LuaScriptInterface& getInterface() override {return m_interface;}
		LuaScriptInterface m_interface;

		void registerItemID(int32_t itemId, Event_Ptr event);
		void registerActionID(int32_t actionId, Event_Ptr event);
		void registerUniqueID(int32_t uniqueId, Event_Ptr event);

		typedef std::map<uint16_t, Action_Ptr> ActionMap;

		ActionMap useItemMap;
		ActionMap uniqueItemMap;
		ActionMap actionItemMap;

		static bool executeUse(Action* action, Player* player, Item* item, const PositionEx& posEx, uint32_t creatureId);
		ReturnValue internalUseItem(Player* player, const Position& pos,
			uint8_t index, Item* item, uint32_t creatureId) const;
		static bool executeUseEx(Action* action, Player* player, Item* item, const PositionEx& fromPosEx,
			const PositionEx& toPosEx, bool isHotkey, uint32_t creatureId);
		ReturnValue internalUseItemEx(Player* player, const PositionEx& fromPosEx, const PositionEx& toPosEx,
			Item* item, bool isHotkey, uint32_t creatureId);

		Action* getAction(const Item* item, ActionType_t type = ACTION_ANY) const;
		static void clearMap(ActionMap& map);
};

typedef bool (ActionFunction)(Player* player, Item* item, const PositionEx& posFrom, const PositionEx& posTo, bool extendedUse, uint32_t creatureId);

class Action : public Event
{
	public:
		explicit Action(const Action_Ptr &copy);
		explicit Action(LuaScriptInterface* _interface);

		~Action() override = default;

		bool configureEvent(xmlNodePtr p) override;

		bool loadFunction(const std::string& functionName) override;

		//scripting
		virtual bool executeUse(Player* player, Item* item, const PositionEx& posFrom,
			const PositionEx& posTo, bool extendedUse, uint32_t creatureId);

		[[nodiscard]] bool getAllowFarUse() const {return allowFarUse;}
		void setAllowFarUse(const bool v) {allowFarUse = v;}

		[[nodiscard]] bool getCheckLineOfSight() const {return checkLineOfSight;}
		void setCheckLineOfSight(const bool v) {checkLineOfSight = v;}

		virtual ReturnValue canExecuteAction(const Player* player, const Position& toPos);
		virtual bool hasOwnErrorHandler() {return false;}

		ActionFunction* function{};

	protected:
		[[nodiscard]] std::string getScriptEventName() const override {return "onUse";}
		[[nodiscard]] std::string getScriptEventParams() const override {return "cid, item, fromPosition, itemEx, toPosition";}

		static ActionFunction increaseItemId;
		static ActionFunction decreaseItemId;

		bool allowFarUse;
		bool checkLineOfSight;
};

#endif
