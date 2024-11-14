function onTimer()
    local cor = 22

    local mensagens = {
        [[DingDong: Press�o, loucura e hor�rio, s�o essas tr�s palavras que definem o ritmo da noite que s� os ninjas conseguem compreender e acompanhar...]],
        [[DingDong: Galera da verdura... Virando a noite no efeito da Loucura!]],
        [[DingDong: N�o importa o dia da semana e nem data, nas noites que dita o ritmo somos n�s... Quem tem coragm acompanha, que n�o tem encosta e espera o amanhecer.]],
        [[DingDong: A noite esconde os segredos mais profundos na estrada. S� fica quem n�o tem medo!]],
        [[DingDong: Prefiro o brilho da noite do que as queimaduras do sol!]]
    }

    local players = getPlayersOnline();

    if #players > 0 then
        for i, pid in ipairs(players) do
            doSendPlayerExtendedOpcode(pid, 124, "Default")
        end
    end

    setGlobalStorageValue(pid, 910562, 2)
    doBroadcastMessage(mensagens[math.random(1, #mensagens)], cor)
    return true
end
