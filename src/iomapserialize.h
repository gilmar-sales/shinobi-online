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

#ifndef __IOMAPSERIALIZE__
#define __IOMAPSERIALIZE__
#include "otsystem.h"

#include "database.h"
#include "map.h"

typedef std::map<int32_t, std::pair<Item *, int32_t>> ItemMap;
typedef std::list<std::pair<Container *, int32_t>> ContainerStackList;

class House;

class IOMapSerialize
{
public:
    virtual ~IOMapSerialize() = default;

    static IOMapSerialize *getInstance()
    {
        static IOMapSerialize instance;
        return &instance;
    }

    bool loadMap(boost::shared_ptr<Map> map);
    bool saveMap(boost::shared_ptr<Map> map);

    bool updateAuctions();

    bool loadHouses();
    bool updateHouses();
    bool saveHouses();

    bool saveHouse(const boost::shared_ptr<Database> db, House *house);
    bool saveHouseItems(const boost::shared_ptr<Database> db, House *house);

protected:
    IOMapSerialize() = default;

    // Relational storage uses a row for each item/tile
    bool loadMapRelational(boost::shared_ptr<Map> map);
    bool saveMapRelational(boost::shared_ptr<Map> map);
    bool saveHouseRelational(const boost::shared_ptr<Database> db, House *house, uint32_t &tileId);

    // Binary storage uses a giant BLOB field for storing everything
    bool loadMapBinary(boost::shared_ptr<Map> map);
    bool saveMapBinary(boost::shared_ptr<Map> map);

    bool loadItems(const boost::shared_ptr<Database> db, DBResult *result, Cylinder *parent, bool depotTransfer);
    bool saveItems(const boost::shared_ptr<Database> db, uint32_t &tileId, uint32_t houseId, const Tile *tile);

    bool loadContainer(PropStream &propStream, Container *container);
    bool loadItem(PropStream &propStream, Cylinder *parent, bool depotTransfer);

    bool saveTile(PropWriteStream &stream, const Tile *tile);
    bool saveItem(PropWriteStream &stream, const Item *item);
};
#endif