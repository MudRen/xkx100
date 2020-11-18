// globals.h
// this file will be automatically included by the driver
// for XKX mudlib, by Xiang
// for XKX100 mudlib, by Winder 2001.6.3
#ifndef GLOBALS_H
#define GLOBALS_H

// Important directories
#define INC_DIR                   "/include/"
#define BACKUP_DIR                "/backup/"
#define COMMAND_DIR               "/cmds/"
#define CONFIG_DIR                "/adm/etc/"
#define STORY_DIR                 "/adm/daemons/story/"
#define DATA_DIR                  "/data/"
#define HELP_DIR                  "/help/"
#define LOG_DIR                   "/log/"
#define ARMOR_DIR                 "/clone/armor/"              //护具
#define WEAPON_DIR                "/clone/weapon/"             //兵器
#define BOOK_DIR                  "/clone/book/"               //书籍
#define MONEY_DIR                 "/clone/money/"              //货币
#define ANIMAL_DIR                "/clone/animal/"             //动物
#define JEWELRY_DIR               "/clone/jewelry/"            //珠宝
#define FOOD_DIR                  "/clone/food/"               //食物
#define FRUIT_DIR                 "/clone/food/fruit/"         //水果
#define LIQUID_DIR                "/clone/food/liquid/"        //饮料
#define TEA_DIR                   "/clone/food/tea/"           //茶水
#define FODDER_DIR                "/clone/food/fodder/"        //饲料
#define CLOTH_DIR                 "/clone/cloth/"              //衣服
#define HEAD_DIR                  "/clone/cloth/head/"         //盔帽
#define BOOT_DIR                  "/clone/cloth/boot/"         //鞋靴
#define NOSTRUM_DIR               "/clone/medicine/nostrum/"   //成药
#define POISON_DIR                "/clone/medicine/poison/"    //毒药
#define VEGETABLE_DIR             "/clone/medicine/vegetable/" //草药
#define SHOP_DIR                  "/clone/shop/"               //商店

// Daemons
#define PK_D                      "/adm/daemons/pkd"
#define EVENT_DIR                 "/adm/daemons/event/"
#define ALIAS_D                   "/adm/daemons/aliasd"
#define AUTOSAVE_D                "/adm/daemons/autosaved"
#define BAN_D                     "/adm/daemons/band"
#define CHANNEL_D                 "/adm/daemons/channeld"
#define CHAR_D                    "/adm/daemons/chard"
#define CHINESE_D                 "/adm/daemons/chinesed"
#define COMBAT_D                  "/adm/daemons/combatd"
#define COMMAND_D                 "/adm/daemons/commandd"
#define CONVERT_D                 "/adm/daemons/convertd"
#define CRON_D                    "/adm/daemons/crond"
#define DISASTER_D                "/adm/daemons/disaster"
#define EMOTE_D                   "/adm/daemons/emoted"
#define FINGER_D                  "/adm/daemons/fingerd"
#define FTP_D                     "/adm/daemons/ftpd"
#define GIFT_D                    "/adm/daemons/giftd"
#define INQUIRY_D                 "/adm/daemons/inquiryd"
#define LOGIN_D                   "/adm/daemons/logind"
#define MAP_D                     "/adm/daemons/mapd"
#define MONEY_D                   "/adm/daemons/moneyd"
#define NAME_D                    "/adm/daemons/named"
#define NATURE_D                  "/adm/daemons/natured"
#define NPC_D                     "/adm/daemons/npcd"
#define NEWS_D                    "/adm/daemons/newsd"
#define PERSONAL_D                "/adm/daemons/personald"
#define PIG_D                     "/adm/daemons/pigd"
#define PROFILE_D                 "/adm/daemons/profiled"
#define RANK_D                    "/adm/daemons/rankd"
#define SECURITY_D                "/adm/daemons/securityd"
#define SHOP_D                    "/adm/daemons/shopd"
#define SCBORN_D                  "/adm/daemons/scbornd"
#define STORY_D                   "/adm/daemons/storyd"
#define TASK_D                    "/adm/daemons/questd"
#define UPDATE_D                  "/adm/daemons/updated"
#define VIRTUAL_D                 "/adm/daemons/virtuald"
#define WEAPON_D                  "/adm/daemons/weapond"
#define TIME_D                    "/adm/daemons/timed"

#define CLASS_D(x)                ("/kungfu/class/" + x)
#define SKILL_D(x)                ("/kungfu/skill/" + x)
#define CONDITION_D(x)            ("/kungfu/condition/" + x)

// 高手排行板
#define RICHMAN_D                 "/adm/daemons/tenrichmand"
#define GAOSHOU_D                 "/adm/daemons/tengaoshoud"

// Added for questing
#define QUESTH_D(x)               ("/quest/qhlist" + x)
#define QUESTS_D(x)               ("/quest/qslist" + x)
#define QUESTW_D(x)               ("/quest/qwlist" + x)

// Clonable/Non-inheritable Standard Objects
#define COIN_OB                   "/clone/money/coin"
#define CORPSE_OB                 "/clone/misc/corpse"
#define EXPLIST                   "/clone/quest/explist"
#define GOLD_OB                   "/clone/money/gold"
#define LOGIN_OB                  "/clone/user/login"
#define MASTER_OB                 "/adm/single/master"
#define MAILBOX_OB                "/clone/misc/mailbox"
#define SILVER_OB                 "/clone/money/silver"
#define SIMUL_EFUN_OB             "/adm/single/simul_efun"
#define USER_OB                   "/clone/user/user"
#define VOID_OB                   "/clone/misc/void"

// Inheritable Standard Objects
#define BANK                      "/inherit/room/bank"
#define BULLETIN_BOARD            "/inherit/misc/bboard"
#define CHARACTER                 "/inherit/char/char"
#define COMBINED_ITEM             "/inherit/item/combined"
#define EQUIP                     "/inherit/misc/equip"
#define FORCE                     "/inherit/skill/force"
#define HOCKSHOP                  "/inherit/room/hockshop"
#define ITEM                      "/inherit/item/item"
#define LIQUID                    "/inherit/food/liquid"
#define MONEY                     "/inherit/item/money"
#define NPC                       "/inherit/char/npc"
#define NPC_SAVE                  "/inherit/char/npcsave"
#define NPC_TRAINEE               "/inherit/char/trainee"
#define WAITER                    "/inherit/char/waiter"
#define PILL                      "/inherit/medicine/pill"
#define POWDER                    "/inherit/medicine/powder"
#define RESTROOM_IN               "/inherit/room/restroom_in"
#define RESTROOM_OUT              "/inherit/room/restroom_out"
#define RIVER                     "/inherit/room/river"
#define ROOM                      "/inherit/room/room"
#define SHOP                      "/inherit/room/shop"
#define SKILL                     "/inherit/skill/skill"
#define SKILL_MODEL_UNARMED       "/inherit/meskill/skill_model_unarmed.c"
#define SKILL_MODEL_WEAPON        "/inherit/meskill/skill_model_weapon.c"
#define SKILL_MODEL_DEFAULT       "/inherit/meskill/skill_model_default.c"


// User IDs

#define ROOT_UID                  "Root"
#define BACKBONE_UID              "Backbone"

// Features

#define F_ACTION                  "/feature/action.c"
#define F_ALIAS                   "/feature/alias.c"
#define F_APPRENTICE              "/feature/apprentice.c"
#define F_ATTACK                  "/feature/attack.c"
#define F_ATTRIBUTE               "/feature/attribute.c"
#define F_AUTOLOAD                "/feature/autoload.c"
#define F_BANKER                  "/feature/banker.c"
#define F_CLEAN_UP                "/feature/clean_up.c"
#define F_COMMAND                 "/feature/command.c"
#define F_CONDITION               "/feature/condition.c"
#define F_DAMAGE                  "/feature/damage.c"
#define F_DBASE                   "/feature/dbase.c"
#define F_DEALER                  "/feature/dealer.c"
#define F_EDIT                    "/feature/edit.c"
#define F_EQUIP                   "/feature/equip.c"
#define F_FINANCE                 "/feature/finance.c"
#define F_FOOD                    "/feature/food.c"
#define F_FRUIT                   "/feature/fruit.c"
#define F_LIQUID                  "/feature/liquid.c"
#define F_MASTER                  "/inherit/char/master.c"
#define F_MANAGER                 "/inherit/char/manager.c"
#define F_FIRST                   "/inherit/char/first.c"
#define F_MESSAGE                 "/feature/message.c"
#define F_MORE                    "/feature/more.c"
#define F_MOVE                    "/feature/move.c"
#define F_NAME                    "/feature/name.c"
#define F_QUEST                   "/feature/quest.c"
#define F_SAVE                    "/feature/save.c"
#define F_SKILL                   "/feature/skill.c"
#define F_TEAM                    "/feature/team.c"
#define F_TREEMAP                 "/feature/treemap.c"
#define F_VENDOR                  "/feature/dealer.c"
#define F_VENDOR_SALE             "/feature/vendor_sale.c"
#define F_VI                      "/feature/vi.c"
#define F_SSERVER                 "/feature/sserver.c"
#define F_UNIQUE                  "/feature/unique.c"

// Profiling switches
//
// If you changed any of these defines, you'll need reboot to make it
// in effect.

#undef PROFILE_COMMANDS

// mudcore 框架头文件
#include <mudcore.h>

#endif
