DELETE FROM `trinity_string` WHERE `entry` = 12002;
INSERT INTO `trinity_string` (`entry`,`content_default`) VALUES (12002, 'Player wishes to not be disturbed and cannot receive whisper messages.');

DELETE FROM `command` WHERE `name` = 'fake account' OR `name` = 'fake player';
INSERT INTO `command` (`name`, `security`, `help`) VALUES
('fake account', 2, 'Syntax: .fake account [accountName] [on/off]\nSets all characters of the given account to fake online or offline.'),
('fake player', 2, 'Syntax: .fake player [characterName] [on/off]\nSets character of the given name to fake online or offline.');
