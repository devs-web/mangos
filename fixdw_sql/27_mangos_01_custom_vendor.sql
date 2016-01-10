INSERT INTO `command` VALUES
('reload custom_vendor',3,'reload _customvendors table');

CREATE TABLE `_customvendors` (
  `guid` int(11) NOT NULL AUTO_INCREMENT,
  `entry` int(11) DEFAULT NULL,
  `vendor_entry` int(11) DEFAULT NULL,
  `group` int(11) DEFAULT NULL,
  `daug_guid` int(11) DEFAULT NULL,
  `icon` int(11) DEFAULT NULL,
  `desc` text,
  `sort` int(255) NOT NULL DEFAULT '1',
  PRIMARY KEY (`guid`)
) ENGINE=InnoDB AUTO_INCREMENT=400506 DEFAULT CHARSET=utf8;
