-- Arena Spectator
DELETE FROM `trinity_string` WHERE `entry` BETWEEN '11608' AND '11613';
INSERT INTO `trinity_string` (`entry`, `content_default`, `content_loc8`) VALUES
('11608', 'Player %s forbided you to watch his arena match.', 'Игрок %s не находится в вашем списке друзей.'),
('11609', 'Player %s is not on arena match.', 'Игрок %s не на арене.'),
('11610', 'You should not on arena or battleground to be a spectator.', 'Вы не можете стать зрителем, находясь на поле боя или арене.'),
('11611', 'You already have a spectator state.', 'Вы уже являетесь зрителем.'),
('11612', 'Arena spectators system disabled.', 'Система зрителей отключена.'),
('11613', 'You cannot use chat while you are a spectator.', 'Находясь в режиме зрителя, вы не можете использовать чат.');
DELETE FROM `command` WHERE `name` = 'spectate';
INSERT INTO `command` VALUES ('spectate', '0', 'Syntax: .spectate $player\r\n\r\nMakes you a spectator of arena match with $player');

UPDATE creature_template SET AIName = "" WHERE entry IN (36725, 36724, 37012, 37007, 36811, 36807, 36829, 36805, 36808, 37098, 37022, 37038, 37023, 10404, 36880, 37664, 37595, 37663, 37901, 37571, 37662, 37665, 37666, 38125, 37127, 37132, 37134, 37133); 
UPDATE `creature_template` SET `ScriptName` = 'npc_NerubarBroodkeeper' WHERE `entry` = 36725;
UPDATE `creature_template` SET `ScriptName` = 'npc_ServantoftheThrone' WHERE `entry` = 36724;
UPDATE `creature_template` SET `ScriptName` = 'npc_AncientSkeletalSoldier' WHERE `entry` = 37012;
UPDATE `creature_template` SET `ScriptName` = 'npc_DeathboundWard' WHERE `entry` = 37007;
UPDATE `creature_template` SET `ScriptName` = 'npc_DeathspeakerAttedant' WHERE `entry` = 36811;
UPDATE `creature_template` SET `ScriptName` = 'npc_DeathspeakerDisciple' WHERE `entry` = 36807;
UPDATE `creature_template` SET `ScriptName` = 'npc_DeathspeakerHighPriest' WHERE `entry` = 36829;
UPDATE `creature_template` SET `ScriptName` = 'npc_DeathspeakerServant' WHERE `entry` = 36805;
UPDATE `creature_template` SET `ScriptName` = 'npc_DeathspeakerZealot' WHERE `entry` = 36808;
UPDATE creature_template SET scriptname = "npc_valkyr_herald" WHERE entry = 37098;
UPDATE creature_template SET scriptname = "npc_blighted_abomination" WHERE entry = 37022;
UPDATE creature_template SET scriptname = "npc_vengeful_fleshreapert" WHERE entry = 37038;
UPDATE creature_template SET scriptname = "npc_plague_scientist" WHERE entry = 37023;
UPDATE creature_template SET scriptname = "npc_pustulating_horror" WHERE entry = 10404;
UPDATE creature_template SET scriptname = "npc_decaying_colossus" WHERE entry = 36880;
UPDATE creature_template SET scriptname = "npc_darkfallen_archmage" WHERE entry = 37664;
UPDATE creature_template SET scriptname = "npc_darkfallen_blood_knight" WHERE entry = 37595;
UPDATE creature_template SET scriptname = "npc_darkfallen_noble" WHERE entry = 37663;
UPDATE creature_template SET scriptname = "npc_vampiric_fiend" WHERE entry = 37901;
UPDATE creature_template SET scriptname = "npc_darkfallen_advisor" WHERE entry = 37571;
UPDATE creature_template SET scriptname = "npc_darkfallen_commander" WHERE entry = 37662;
UPDATE creature_template SET scriptname = "npc_darkfallen_lieutenant" WHERE entry = 37665;
UPDATE creature_template SET scriptname = "npc_darkfallen_tactician" WHERE entry = 37666;
UPDATE creature_template SET scriptname = "npc_ymirjar_deathbringer" WHERE entry = 38125;
UPDATE creature_template SET scriptname = "npc_ymirjar_frostbinder" WHERE entry = 37127;
UPDATE creature_template SET scriptname = "npc_ymirjar_battlemaiden" WHERE entry = 37132;
UPDATE creature_template SET scriptname = "npc_ymirjar_huntress" WHERE entry = 37134;
UPDATE creature_template SET scriptname = "npc_ymirjar_warlord" WHERE entry = 37133;

SET @GUID := 153100;
DELETE FROM `gameobject` WHERE `id` IN(201959, 202338, 202339, 202340);
INSERT INTO `gameobject` (`guid`, `id`, `map`, `spawnMask`, `phaseMask`, `position_x`, `position_y`, `position_z`, `orientation`, `rotation0`, `rotation1`, `rotation2`, `rotation3`, `spawntimesecs`, `animprogress`, `state`) VALUES
(@GUID+0, 201959, 631, 1, 1, 4203.65, 2484.56, 364.873, 6.28004, 0, 0, 0.00157252, -1, -120, 0, 1),
(@GUID+1, 202339, 631, 2, 1, 4203.65, 2484.56, 364.873, 6.28004, 0, 0, 0.00157252, -1, -120, 0, 1),
(@GUID+2, 202338, 631, 4, 1, 4203.65, 2484.56, 364.873, 6.28004, 0, 0, 0.00157252, -1, -120, 0, 1),
(@GUID+3, 202340, 631, 8, 1, 4203.65, 2484.56, 364.873, 6.28004, 0, 0, 0.00157252, -1, -120, 0, 1);