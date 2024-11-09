
DROP TABLE IF EXISTS player_depotitems;
DROP TABLE IF EXISTS tile_items;
DROP TABLE IF EXISTS tiles;
DROP TABLE IF EXISTS bans;
DROP TABLE IF EXISTS house_lists;
DROP TABLE IF EXISTS houses;
DROP TABLE IF EXISTS player_items;
DROP TABLE IF EXISTS player_namelocks;
DROP TABLE IF EXISTS player_skills;
DROP TABLE IF EXISTS player_storage;
DROP TABLE IF EXISTS player_viplist;
DROP TABLE IF EXISTS player_spells;
DROP TABLE IF EXISTS player_deaths;
DROP TABLE IF EXISTS killers;
DROP TABLE IF EXISTS environment_killers;
DROP TABLE IF EXISTS player_killers;
DROP TABLE IF EXISTS guild_ranks;
DROP TABLE IF EXISTS guilds;
DROP TABLE IF EXISTS guild_invites;
DROP TABLE IF EXISTS global_storage;
DROP TABLE IF EXISTS players;
DROP TABLE IF EXISTS accounts;
DROP TABLE IF EXISTS server_record;
DROP TABLE IF EXISTS server_motd;
DROP TABLE IF EXISTS server_reports;
DROP TABLE IF EXISTS server_config;
DROP TABLE IF EXISTS account_viplist;

-- SQLINES LICENSE FOR EVALUATION USE ONLY
CREATE SEQUENCE accounts_seq;

CREATE TABLE accounts
(
    id INT NOT NULL DEFAULT NEXTVAL ('accounts_seq'),
    name VARCHAR(32) NOT NULL DEFAULT '',
    password VARCHAR(255) NOT NULL/* SQLINES DEMO *** ULL COMMENT 'MD5'*//* SQLINES DEMO *** ULL COMMENT 'SHA1'*/,
    premdays INT NOT NULL DEFAULT 0,
    lastday INT NOT NULL DEFAULT 0,
    email VARCHAR(255) NOT NULL DEFAULT '',
    key VARCHAR(20) NOT NULL DEFAULT '0',
    blocked SMALLINT NOT NULL DEFAULT 0 ,
    warnings INT NOT NULL DEFAULT 0,
    group_id INT NOT NULL DEFAULT 1,
    PRIMARY KEY (id), UNIQUE (name)
);

INSERT INTO accounts VALUES (1, '1', '1', 65535, 0, '', '0', 0, 0, 1);

-- SQLINES LICENSE FOR EVALUATION USE ONLY
CREATE SEQUENCE players_seq;

CREATE TABLE players
(
    id INT NOT NULL DEFAULT NEXTVAL ('players_seq'),
    name VARCHAR(255) NOT NULL,
    world_id SMALLINT NOT NULL DEFAULT 0,
    group_id INT NOT NULL DEFAULT 1,
    account_id INT NOT NULL DEFAULT 0,
    level INT NOT NULL DEFAULT 1,
    vocation INT NOT NULL DEFAULT 0,
    health INT NOT NULL DEFAULT 150,
    healthmax INT NOT NULL DEFAULT 150,
    experience BIGINT NOT NULL DEFAULT 0,
    lookbody INT NOT NULL DEFAULT 0,
    lookfeet INT NOT NULL DEFAULT 0,
    lookhead INT NOT NULL DEFAULT 0,
    looklegs INT NOT NULL DEFAULT 0,
    looktype INT NOT NULL DEFAULT 136,
    lookaddons INT NOT NULL DEFAULT 0,
    maglevel INT NOT NULL DEFAULT 0,
    mana INT NOT NULL DEFAULT 0,
    manamax INT NOT NULL DEFAULT 0,
    manaspent INT NOT NULL DEFAULT 0,
    soul INT NOT NULL DEFAULT 0,
    town_id INT NOT NULL DEFAULT 0,
    posx INT NOT NULL DEFAULT 0,
    posy INT NOT NULL DEFAULT 0,
    posz INT NOT NULL DEFAULT 0,
    conditions BYTEA NOT NULL,
    cap INT NOT NULL DEFAULT 0,
    sex INT NOT NULL DEFAULT 0,
    lastlogin BIGINT NOT NULL DEFAULT 0,
    lastip INT NOT NULL DEFAULT 0,
    save SMALLINT NOT NULL DEFAULT 1,
    skull SMALLINT NOT NULL DEFAULT 0,
    skulltime INT NOT NULL DEFAULT 0,
    rank_id INT NOT NULL DEFAULT 0,
    guildnick VARCHAR(255) NOT NULL DEFAULT '',
    lastlogout BIGINT NOT NULL DEFAULT 0,
    blessings SMALLINT NOT NULL DEFAULT 0,
    balance BIGINT NOT NULL DEFAULT 0,
    stamina BIGINT NOT NULL DEFAULT 151200000 ,
    direction INT NOT NULL DEFAULT 2,
    loss_experience INT NOT NULL DEFAULT 100,
    loss_mana INT NOT NULL DEFAULT 100,
    loss_skills INT NOT NULL DEFAULT 100,
    loss_containers INT NOT NULL DEFAULT 100,
    loss_items INT NOT NULL DEFAULT 100,
    premend INT NOT NULL DEFAULT 0 ,
    online SMALLINT NOT NULL DEFAULT 0,
    marriage INT NOT NULL DEFAULT 0,
    promotion INT NOT NULL DEFAULT 0,
    deleted SMALLINT NOT NULL DEFAULT 0,
    description VARCHAR(255) NOT NULL DEFAULT '',
    PRIMARY KEY (id), UNIQUE (name, deleted)
    ,
    FOREIGN KEY (account_id) REFERENCES accounts(id) ON DELETE CASCADE
);


INSERT INTO players VALUES (1, 'Account Manager', 0, 1, 1, 1, 0, 150, 150, 0, 0, 0, 0, 0, 110, 0, 0, 0, 0, 0, 0, 0, 50, 50, 7, '', 400, 0, 0, 0, 0, 0, 0, 0, '', 0, 0, 0, 201660000, 0, 100, 100, 100, 100, 100, 0, 0, 0, 0, 0, '');

-- SQLINES LICENSE FOR EVALUATION USE ONLY
CREATE TABLE account_viplist
(
    account_id INT NOT NULL,
    world_id SMALLINT NOT NULL DEFAULT 0,
    player_id INT NOT NULL
    , UNIQUE (account_id, player_id),
    FOREIGN KEY (account_id) REFERENCES accounts(id) ON DELETE CASCADE,
    FOREIGN KEY (player_id) REFERENCES players(id) ON DELETE CASCADE
);


-- SQLINES LICENSE FOR EVALUATION USE ONLY
CREATE SEQUENCE player_deaths_seq;

CREATE TABLE player_deaths
(
    id INT NOT NULL DEFAULT NEXTVAL ('player_deaths_seq'),
    player_id INT NOT NULL,
    date BIGINT NOT NULL,
    level INT NOT NULL,
    PRIMARY KEY (id),
    FOREIGN KEY (player_id) REFERENCES players(id) ON DELETE CASCADE
);


-- SQLINES LICENSE FOR EVALUATION USE ONLY
CREATE TABLE player_depotitems
(
    player_id INT NOT NULL,
    sid INT NOT NULL ,
    pid INT NOT NULL DEFAULT 0,
    itemtype INT NOT NULL,
    count INT NOT NULL DEFAULT 0,
    attributes BYTEA NOT NULL
    , UNIQUE (player_id, sid),
    FOREIGN KEY (player_id) REFERENCES players(id) ON DELETE CASCADE
);


-- SQLINES LICENSE FOR EVALUATION USE ONLY
CREATE TABLE player_items
(
    player_id INT NOT NULL DEFAULT 0,
    pid INT NOT NULL DEFAULT 0,
    sid INT NOT NULL DEFAULT 0,
    itemtype INT NOT NULL DEFAULT 0,
    count INT NOT NULL DEFAULT 0,
    attributes BYTEA NOT NULL
    , UNIQUE (player_id, sid),
    FOREIGN KEY (player_id) REFERENCES players(id) ON DELETE CASCADE
);


-- SQLINES LICENSE FOR EVALUATION USE ONLY
CREATE TABLE player_namelocks
(
    player_id INT NOT NULL DEFAULT 0,
    name VARCHAR(255) NOT NULL,
    new_name VARCHAR(255) NOT NULL,
    date BIGINT NOT NULL DEFAULT 0
    ,
    FOREIGN KEY (player_id) REFERENCES players(id) ON DELETE CASCADE
);


-- SQLINES LICENSE FOR EVALUATION USE ONLY
CREATE TABLE player_skills
(
    player_id INT NOT NULL DEFAULT 0,
    skillid SMALLINT NOT NULL DEFAULT 0,
    value INT NOT NULL DEFAULT 0,
    count INT NOT NULL DEFAULT 0
    , UNIQUE (player_id, skillid),
    FOREIGN KEY (player_id) REFERENCES players(id) ON DELETE CASCADE
);


-- SQLINES LICENSE FOR EVALUATION USE ONLY
CREATE TABLE player_spells
(
    player_id INT NOT NULL,
    name VARCHAR(255) NOT NULL
    , UNIQUE (player_id, name),
    FOREIGN KEY (player_id) REFERENCES players(id) ON DELETE CASCADE
);


-- SQLINES LICENSE FOR EVALUATION USE ONLY
CREATE TABLE player_storage
(
    player_id INT NOT NULL DEFAULT 0,
    key INT NOT NULL DEFAULT 0,
    value VARCHAR(255) NOT NULL DEFAULT '0'
    , UNIQUE (player_id, key),
    FOREIGN KEY (player_id) REFERENCES players(id) ON DELETE CASCADE
);


-- SQLINES LICENSE FOR EVALUATION USE ONLY
CREATE TABLE player_viplist
(
    player_id INT NOT NULL,
    vip_id INT NOT NULL
    , UNIQUE (player_id, vip_id),
    FOREIGN KEY (player_id) REFERENCES players(id) ON DELETE CASCADE,
    FOREIGN KEY (vip_id) REFERENCES players(id) ON DELETE CASCADE
);


-- SQLINES LICENSE FOR EVALUATION USE ONLY
CREATE SEQUENCE killers_seq;

CREATE TABLE killers
(
    id INT NOT NULL DEFAULT NEXTVAL ('killers_seq'),
    death_id INT NOT NULL,
    final_hit SMALLINT NOT NULL DEFAULT 0,
    unjustified SMALLINT NOT NULL DEFAULT 0,
    PRIMARY KEY (id),
    FOREIGN KEY (death_id) REFERENCES player_deaths(id) ON DELETE CASCADE
);

-- SQLINES LICENSE FOR EVALUATION USE ONLY
CREATE TABLE player_killers
(
    kill_id INT NOT NULL,
    player_id INT NOT NULL,
    FOREIGN KEY (kill_id) REFERENCES killers(id) ON DELETE CASCADE,
    FOREIGN KEY (player_id) REFERENCES players(id) ON DELETE CASCADE
);

-- SQLINES LICENSE FOR EVALUATION USE ONLY
CREATE TABLE environment_killers
(
    kill_id INT NOT NULL,
    name VARCHAR(255) NOT NULL,
    FOREIGN KEY (kill_id) REFERENCES killers(id) ON DELETE CASCADE
);

-- SQLINES LICENSE FOR EVALUATION USE ONLY
CREATE TABLE houses
(
    id INT NOT NULL,
    world_id SMALLINT NOT NULL DEFAULT 0,
    owner INT NOT NULL,
    paid INT NOT NULL DEFAULT 0,
    warnings INT NOT NULL DEFAULT 0,
    lastwarning INT NOT NULL DEFAULT 0,
    name VARCHAR(255) NOT NULL,
    town INT NOT NULL DEFAULT 0,
    size INT NOT NULL DEFAULT 0,
    price INT NOT NULL DEFAULT 0,
    rent INT NOT NULL DEFAULT 0,
    doors INT NOT NULL DEFAULT 0,
    beds INT NOT NULL DEFAULT 0,
    tiles INT NOT NULL DEFAULT 0,
    guild SMALLINT NOT NULL DEFAULT 0,
    clear SMALLINT NOT NULL DEFAULT 0,
    UNIQUE (id, world_id)
);

-- SQLINES LICENSE FOR EVALUATION USE ONLY
CREATE TABLE house_auctions
(
    house_id INT NOT NULL,
    world_id SMALLINT NOT NULL DEFAULT 0,
    player_id INT NOT NULL,
    bid INT NOT NULL DEFAULT 0,
    "limit" INT NOT NULL DEFAULT 0,
	endtime BIGINT NOT NULL DEFAULT 0,
	UNIQUE (house_id, world_id),
	FOREIGN KEY (house_id, world_id) REFERENCES houses(id, world_id) ON DELETE CASCADE,
	FOREIGN KEY (player_id) REFERENCES players (id) ON DELETE CASCADE
);

-- SQLINES LICENSE FOR EVALUATION USE ONLY
CREATE TABLE house_lists
(
    house_id INT NOT NULL,
    world_id SMALLINT NOT NULL DEFAULT 0,
    listid INT NOT NULL,
    list TEXT NOT NULL,
    UNIQUE (house_id, world_id, listid),
    FOREIGN KEY (house_id, world_id) REFERENCES houses(id, world_id) ON DELETE CASCADE
);

-- SQLINES LICENSE FOR EVALUATION USE ONLY
CREATE TABLE house_data
(
    house_id INT NOT NULL,
    world_id SMALLINT NOT NULL DEFAULT 0,
    data bytea NOT NULL,
    UNIQUE (house_id, world_id),
    FOREIGN KEY (house_id, world_id) REFERENCES houses(id, world_id) ON DELETE CASCADE
);

-- SQLINES LICENSE FOR EVALUATION USE ONLY
CREATE TABLE tiles
(
    id INT NOT NULL,
    world_id SMALLINT NOT NULL DEFAULT 0,
    house_id INT NOT NULL,
    x INT NOT NULL,
    y INT NOT NULL,
    z SMALLINT NOT NULL,
    UNIQUE (id, world_id) ,
    FOREIGN KEY (house_id, world_id) REFERENCES houses(id, world_id) ON DELETE CASCADE
);


-- SQLINES LICENSE FOR EVALUATION USE ONLY
CREATE TABLE tile_items
(
    tile_id INT NOT NULL,
    world_id SMALLINT NOT NULL DEFAULT 0,
    sid INT NOT NULL,
    pid INT NOT NULL DEFAULT 0,
    itemtype INT NOT NULL,
    count INT NOT NULL DEFAULT 0,
    attributes BYTEA NOT NULL,
    UNIQUE (tile_id, world_id, sid),
    FOREIGN KEY (tile_id, world_id) REFERENCES tiles(id, world_id) ON DELETE CASCADE
);


-- SQLINES LICENSE FOR EVALUATION USE ONLY
CREATE SEQUENCE guilds_seq;

CREATE TABLE guilds
(
    id INT NOT NULL DEFAULT NEXTVAL ('guilds_seq'),
    world_id SMALLINT NOT NULL DEFAULT 0,
    name VARCHAR(255) NOT NULL,
    ownerid INT NOT NULL,
    creationdata INT NOT NULL,
    motd VARCHAR(255) NOT NULL,
    PRIMARY KEY (id),
    UNIQUE (name, world_id)
);

-- SQLINES LICENSE FOR EVALUATION USE ONLY
CREATE TABLE guild_invites
(
    player_id INT NOT NULL DEFAULT 0,
    guild_id INT NOT NULL DEFAULT 0,
    UNIQUE (player_id, guild_id),
    FOREIGN KEY (player_id) REFERENCES players(id) ON DELETE CASCADE,
    FOREIGN KEY (guild_id) REFERENCES guilds(id) ON DELETE CASCADE
);

-- SQLINES LICENSE FOR EVALUATION USE ONLY
CREATE SEQUENCE guild_ranks_seq;

CREATE TABLE guild_ranks
(
    id INT NOT NULL DEFAULT NEXTVAL ('guild_ranks_seq'),
    guild_id INT NOT NULL,
    name VARCHAR(255) NOT NULL,
    level INT NOT NULL ,
    PRIMARY KEY (id),
    FOREIGN KEY (guild_id) REFERENCES guilds(id) ON DELETE CASCADE
);

-- SQLINES LICENSE FOR EVALUATION USE ONLY
CREATE SEQUENCE bans_seq;

CREATE TABLE bans
(
    id INT NOT NULL default nextval ('bans_seq'),
    type SMALLINT NOT NULL ,
    value INT NOT NULL ,
    param INT NOT NULL DEFAULT 4294967295 ,
    active SMALLINT NOT NULL DEFAULT 1,
    expires INT NOT NULL,
    added INT NOT NULL,
    admin_id INT NOT NULL DEFAULT 0,
    comment TEXT NOT NULL,
    reason INT NOT NULL DEFAULT 0,
    action INT NOT NULL DEFAULT 0,
    statement VARCHAR(255) NOT NULL DEFAULT '',
    PRIMARY KEY (id)
);


-- SQLINES LICENSE FOR EVALUATION USE ONLY
CREATE TABLE global_storage
(
    key INT NOT NULL,
    world_id SMALLINT NOT NULL DEFAULT 0,
    value VARCHAR(255) NOT NULL DEFAULT '0',
    UNIQUE  (key, world_id)
);

-- SQLINES LICENSE FOR EVALUATION USE ONLY
CREATE TABLE server_config
(
    config VARCHAR(35) NOT NULL DEFAULT '',
    value INT NOT NULL,
    UNIQUE (config)
);

INSERT INTO server_config VALUES ('db_version', 23);

-- SQLINES LICENSE FOR EVALUATION USE ONLY
CREATE TABLE server_motd
(
    id INT NOT NULL ,
    world_id SMALLINT NOT NULL DEFAULT 0,
    text TEXT NOT NULL,
    UNIQUE (id, world_id)
);

INSERT INTO server_motd VALUES (1, 0, 'Welcome to The Forgotten Server!');

-- SQLINES LICENSE FOR EVALUATION USE ONLY
CREATE TABLE server_record
(
    record INT NOT NULL,
    world_id SMALLINT NOT NULL DEFAULT 0,
    timestamp BIGINT NOT NULL,
    UNIQUE (record, world_id, timestamp)
);

INSERT INTO server_record VALUES (0, 0, 0);

-- SQLINES LICENSE FOR EVALUATION USE ONLY
CREATE SEQUENCE server_reports_seq;

CREATE TABLE server_reports
(
    id INT NOT NULL DEFAULT NEXTVAL ('server_reports_seq'),
    world_id SMALLINT NOT NULL DEFAULT 0,
    player_id INT NOT NULL DEFAULT 1,
    posx INT NOT NULL DEFAULT 0,
    posy INT NOT NULL DEFAULT 0,
    posz INT NOT NULL DEFAULT 0,
    timestamp BIGINT NOT NULL DEFAULT 0,
    report TEXT NOT NULL,
    reads INT NOT NULL DEFAULT 0,
    PRIMARY KEY (id)
    ,
    FOREIGN KEY (player_id) REFERENCES players(id) ON DELETE CASCADE
);

CREATE FUNCTION clear_account_data()
    RETURNS TRIGGER
    LANGUAGE PLPGSQL
AS $$
BEGIN
    DELETE FROM bans WHERE type IN (3, 4) AND value = OLD.id;
END;
$$;

CREATE TRIGGER ondelete_accounts
    BEFORE DELETE
    ON accounts
    FOR EACH ROW EXECUTE PROCEDURE clear_account_data();

CREATE FUNCTION create_guild_ranks()
    RETURNS TRIGGER
    LANGUAGE PLPGSQL
AS $$
BEGIN
    INSERT INTO guild_ranks (name, level, guild_id) VALUES ('Leader', 3, NEW.id);
    INSERT INTO guild_ranks (name, level, guild_id) VALUES ('Vice-Leader', 2, NEW.id);
    INSERT INTO guild_ranks (name, level, guild_id) VALUES ('Member', 1, NEW.id);
END;
$$;

CREATE TRIGGER oncreate_guilds
    AFTER INSERT
    ON guilds
    FOR EACH ROW EXECUTE PROCEDURE create_guild_ranks();

CREATE FUNCTION clear_guild_data()
    RETURNS TRIGGER
    LANGUAGE PLPGSQL
AS $$
BEGIN
    UPDATE players SET guildnick = '', rank_id = 0 WHERE rank_id IN (SELECT id FROM guild_ranks WHERE guild_id = OLD.id);
END;
$$;

CREATE TRIGGER ondelete_guilds
    BEFORE DELETE
    ON guilds
    FOR EACH ROW EXECUTE PROCEDURE clear_guild_data();

CREATE FUNCTION create_player_skills()
    RETURNS TRIGGER
    LANGUAGE PLPGSQL
AS $$
BEGIN
    INSERT INTO player_skills (player_id, skillid, value) VALUES (NEW.id, 0, 10);
    INSERT INTO player_skills (player_id, skillid, value) VALUES (NEW.id, 1, 10);
    INSERT INTO player_skills (player_id, skillid, value) VALUES (NEW.id, 2, 10);
    INSERT INTO player_skills (player_id, skillid, value) VALUES (NEW.id, 3, 10);
    INSERT INTO player_skills (player_id, skillid, value) VALUES (NEW.id, 4, 10);
    INSERT INTO player_skills (player_id, skillid, value) VALUES (NEW.id, 5, 10);
    INSERT INTO player_skills (player_id, skillid, value) VALUES (NEW.id, 6, 10);
END;
$$;

CREATE TRIGGER oncreate_players
    AFTER INSERT
    ON players
    FOR EACH ROW EXECUTE PROCEDURE create_player_skills();


CREATE FUNCTION clear_player_data()
    RETURNS TRIGGER
    LANGUAGE PLPGSQL
AS $$
BEGIN
    DELETE FROM bans WHERE type IN (2, 5) AND value = OLD.id;
    UPDATE houses SET owner = 0 WHERE owner = OLD.id;
END;
$$;

CREATE TRIGGER ondelete_players
    BEFORE DELETE
    ON players
    FOR EACH ROW EXECUTE PROCEDURE clear_player_data();


