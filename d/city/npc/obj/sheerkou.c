// sheerkou.c 蛇儿口
#include <ansi.h>
inherit ITEM;

#define max_poison 24
#define least_poison 8

void init()
{
	add_action("do_shot","shot");
}

void create()
{
	set_name(HIM"蛇儿口"NOR, ({ "sheer kou", "sk" }) );
	set_weight(600);
	if( clonep() )
		set_default_object(__FILE__);
	else {
		set("unit", "支");
		set("value", 0);
		set("material", "steel");
		set("long", "这是传说中古老而神秘的暗器--蛇儿口。\n");
	}
	setup();
}

int do_shot(string arg)
{
 object obj;
	object me = this_player();
 
	int tired;

	if (environment(me)->query("no_fight"))
		return notify_fail("这里禁止战斗。\n");
	if( !arg)
		return notify_fail("你要攻击谁？\n");
	if( !objectp(obj = present(arg, environment(me)) ))
		return notify_fail("这里没有这个人！\n");
	if(!present(this_object(), me))
		return notify_fail("这里没有这个人！\n");
	if( me->is_busy() )
		return notify_fail("别急，慢慢吃，小心别噎着了。\n");

	if( !obj->is_character() || obj->is_corpse() )
	if( !obj->is_character() || obj->is_corpse() )
		return notify_fail("看清楚一点，那并不是活物。\n");
	if (obj == me)
		return notify_fail("对自己下毒手？别想不开啊。\n");

	tired = obj->query("total_tired");
	message_vision(HIM "$N手一扬，一股粉红色的烟雾将$n包围在其中，$n一阵迷乱之下，好象感觉到烟雾中\n"+"有许多蛇正在争先恐后地缠绕着自己！\n" NOR, me, obj);
	obj->apply_condition("snake_poison",random(max_poison) + random(least_poison * tired));

	destruct(this_object());
	return 1;
}
