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

#ifndef __TALKACTION__
#define __TALKACTION__
#include "otsystem.h"

#include "enums.h"
#include "player.h"

#include "tools.h"
#include "luascript.h"
#include "baseevents.h"

enum TalkActionFilter
{
	TALKFILTER_QUOTATION,
	TALKFILTER_WORD,
	TALKFILTER_WORD_SPACED,
	TALKFILTER_LAST
};

class TalkAction;
using TalkAction_Ptr = boost::shared_ptr<TalkAction>;
using TalkActionsMap = std::map<std::string, TalkAction_Ptr>;

class TalkActions : public BaseEvents
{
	public:
		TalkActions();
		virtual ~TalkActions();

		bool onPlayerSay(Creature* creature, uint16_t channelId, const std::string& words, bool ignoreAccess);

		inline TalkActionsMap::const_iterator getFirstTalk() const {return talksMap.begin();}
		inline TalkActionsMap::const_iterator getLastTalk() const {return talksMap.end();}

	protected:
		TalkActionsMap talksMap;

		virtual std::string getScriptBaseName() const {return "talkactions";}
		virtual void clear();

		virtual Event_Ptr getEvent(const std::string& nodeName);
		virtual bool registerEvent(Event_Ptr event, xmlNodePtr p, bool override);

		virtual LuaScriptInterface& getInterface() {return m_interface;}
		LuaScriptInterface m_interface;
};

typedef bool (TalkFunction)(Creature* creature, const std::string& words, const std::string& param);
class TalkAction : public Event
{
	public:
		TalkAction(const TalkAction_Ptr copy);
		TalkAction(LuaScriptInterface* _interface);
		virtual ~TalkAction() {}

		virtual bool configureEvent(xmlNodePtr p);
		virtual bool loadFunction(const std::string& functionName);

		int32_t executeSay(Creature* creature, const std::string& words, std::string param, uint16_t channel);

		std::string getWords() const {return m_words;}
		void setWords(const std::string& words) {m_words = words;}

		TalkActionFilter getFilter() const {return m_filter;}
		uint32_t getAccess() const {return m_access;}
		int32_t getChannel() const {return m_channel;}

		StringVec getExceptions() {return m_exceptions;}
		TalkFunction* getFunction() {return m_function;}

		bool isLogged() const {return m_logged;}
		bool isHidden() const {return m_hidden;}
		bool isSensitive() const {return m_sensitive;}

	protected:
		virtual std::string getScriptEventName() const {return "onSay";}
		virtual std::string getScriptEventParams() const {return "cid, words, param, channel";}

		static TalkFunction houseBuy;
		static TalkFunction houseSell;
		static TalkFunction houseKick;
		static TalkFunction houseDoorList;
		static TalkFunction houseGuestList;
		static TalkFunction houseSubOwnerList;
		static TalkFunction guildJoin;
		static TalkFunction guildCreate;
		static TalkFunction thingProporties;
		static TalkFunction banishmentInfo;
		static TalkFunction diagnostics;
		static TalkFunction addSkill;
		static TalkFunction ghost;

		std::string m_words;
		TalkFunction* m_function;
		TalkActionFilter m_filter;
		uint32_t m_access;
		int32_t m_channel;
		bool m_logged, m_hidden, m_sensitive;
		StringVec m_exceptions;
};
#endif
