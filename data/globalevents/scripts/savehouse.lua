function saveHouses()

	text ="Saving houses!"
	doBroadcastMessage(text)
	doSaveHouses()
end

function onThink(interval)
	-- Use this random to make an interval between servers.
	local delay = math.random(0, 5*60*1000) -- 0 to 5 minutes // Max: 15 minutes
	addEvent(saveHouses, delay)
	return true
end
