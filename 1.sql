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