function onCastSpell(cid, var)
    if not isCreature(cid) then
        return true
    end
    local level = getPlayerLevel(cid)
    local jutsuDmg = 29
    local skill_factor = math.ceil((jutsuSkill_factor(cid, 1) + level) / 2)
    local dmg = -math.max(1, math.ceil(((skill_factor * 0.5) * jutsuDmg) * 0.30))

    actionMove(cid, 385, 500)
    addEvent(actionMove, 600, cid, 386, 600)
    addEvent(doCreatureSay, 200, cid, "Katon:", TALKTYPE_MONSTER)
    addEvent(doCreatureSay, 600, cid, "KARYUU ENDAN!", TALKTYPE_MONSTER)
    local find_area = getFirstCreaturePosOnDirection(cid, 1)
    local pos = getCreaturePosition(cid)
    if getCreatureLookDir(cid) == 0 then
        addEvent(doAreaCombatHealth, 600, cid, COMBAT_FIREDAMAGE, find_area, KATON, dmg, dmg, 255)
        addEvent(doAreaCombatHealth, 1200, cid, COMBAT_FIREDAMAGE, find_area, KATON, dmg, dmg, 255)
        addEvent(doSendMagicEffect, 600, { x = pos.x, y = pos.y - 1, z = pos.z }, 46)
        addEvent(doSendMagicEffect, 1000, { x = pos.x, y = pos.y - 1, z = pos.z }, 46)
    elseif getCreatureLookDir(cid) == 1 then
        addEvent(doAreaCombatHealth, 600, cid, COMBAT_FIREDAMAGE, find_area, KATON, dmg, dmg, 255)
        addEvent(doAreaCombatHealth, 1200, cid, COMBAT_FIREDAMAGE, find_area, KATON, dmg, dmg, 255)
        addEvent(doSendMagicEffect, 600, { x = pos.x + 5, y = pos.y, z = pos.z }, 47)
        addEvent(doSendMagicEffect, 1000, { x = pos.x + 5, y = pos.y, z = pos.z }, 47)
    elseif getCreatureLookDir(cid) == 2 then
        addEvent(doAreaCombatHealth, 600, cid, COMBAT_FIREDAMAGE, find_area, KATON, dmg, dmg, 255)
        addEvent(doAreaCombatHealth, 1200, cid, COMBAT_FIREDAMAGE, find_area, KATON, dmg, dmg, 255)
        addEvent(doSendMagicEffect, 600, { x = pos.x, y = pos.y + 5, z = pos.z }, 45)
        addEvent(doSendMagicEffect, 1000, { x = pos.x, y = pos.y + 5, z = pos.z }, 45)
    elseif getCreatureLookDir(cid) == 3 then
        addEvent(doAreaCombatHealth, 600, cid, COMBAT_FIREDAMAGE, find_area, KATON, dmg, dmg, 255)
        addEvent(doAreaCombatHealth, 1200, cid, COMBAT_FIREDAMAGE, find_area, KATON, dmg, dmg, 255)
        addEvent(doSendMagicEffect, 600, { x = pos.x - 1, y = pos.y, z = pos.z }, 48)
        addEvent(doSendMagicEffect, 1000, { x = pos.x - 1, y = pos.y, z = pos.z }, 48)
    end
end
