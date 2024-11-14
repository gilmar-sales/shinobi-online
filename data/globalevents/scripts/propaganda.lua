function onThink(interval, lastExecution)
    -- Configura��es
    local cor = 22
    local mensagens = {
        [[News: Ajude nosso otNaruto a crescer, Seja Premium. www.otNaruto.com]],
        [[News: Chame seus amigos, montem suas guildas, venham para o mundo do otNaruto.com!]],
        [[Dica: Seu char da debug quando voce tenta entrar? Voce esta preso em algum lugar sem saida? entre www.otNaruto.com e clique em Desbugar Char, para ser enviado para o centro.]],
        [[News: Conhe�a nosso SHOP. www.otNaruto.com]],
        [[Dica: Importante: Nenhum ADM, GM, TUTOR ou qualquer pessoa da EQUIPE vai pedir sua senha, Nunca passe sua senha para ninguem, Nunca entre em sites enviado por players que pede sua senha, Fique Esperto!.]],
        [[Dica: Perguntas do tipo spoiler devem ser feitas no game-chat e nao no help.]],
        [[Dica: N�o nos responsabilizamos por trocas entre players e/ou itens que possam sumir por qualquer motivo ate bugs.]],
        [[Dica: Antes de aceitar qualquer troca  voce deve dar look no item para nao ser enganado.]],
        [[Dica: Se quer protestar, reclamar, conversar use o game-chat, o help so deve ser usado para tirar duvidas sobre o jogo (mas nao pra spoilers).]],
        [[Dica: Nenhum membro da equipe da itens, lvl, com excess�o de eventos anunciados in game ou pelo facebook, nao adianta insistir.]],
        [[Dica: Ajude nosso server, Fa�a uma doa��o, conhece as vantagens, www.otNaruto.com
]]
    }
    -- Fim de Configura��es

    doBroadcastMessage(mensagens[math.random(1, table.maxn(mensagens))], cor)
    return TRUE
end
