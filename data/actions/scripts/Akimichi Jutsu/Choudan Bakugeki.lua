local temp = {
    exhausted = 3,
}
local confg = {
    level = 55,
    chakra = 120,
}
function onUse(cid, item, fromPosition, itemEx, toPosition)
    -----[Restri��es]-----
    if impossibleUse(cid) then
        return true
    end

    if checkDoing(cid) then
        return true
    end

    if checkJutsu(cid, "Nikudan") then
        return doPlayerSendCancel(cid, "you cannot use jutsu")
    end
    if checkJutsu(cid, "Hari") then
        return doPlayerSendCancel(cid, "you cannot use jutsu ")
    end
    if checkJutsu(cid, "Chou Baika") then
        return doPlayerSendCancel(cid, "you cannot use jutsu ")
    end
    if impossibleUse(cid) then
        return true
    end

    if checkDoing(cid) then
        return true
    end
    -----[Restri��es]-----
    -----------------------
    if isPlayer(cid) then
        removeChakraLife(cid, -confg.chakra)
        doPlayerCastSpell(cid, "#YZakimichi4")
        setPlayerStorageValue(cid, sto_jutsu[1], os.time() + temp.exhausted)
    else
        doPlayerSendCancel(cid, "you do not have stamina or chakra.")
    end
end
