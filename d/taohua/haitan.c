// Room: /d/taohua/haitan.c
// Last Modified by winder on Nov. 17 2000

#include <ansi.h>
inherit ROOM;
void rtaohua( object ob ) ;

void create()
{
	set("short", "海滩");
	set("long", @LONG
这是桃花岛的海滩。蓝蓝的海蓝蓝的天，金黄色的沙滩，粉红的桃
花，这一切都是那么美。海边泊着一艘大船(chuan)。
LONG );
	set("item_desc", ([
		"chuan" : "这是桃花岛对外联系的大船。岛上的客人或弟子只要\n上船(enter)就可以回中原。\n",
	]));
	set("exits",([
		"west" :__DIR__"zoulang5",
	]));
	set("no_clean_up", 0);
	set("outdoors", "taohua");
	set("coor/x", 10000);
	set("coor/y", -3000);
	set("coor/z", 0);
	setup();
}

void init()
{
	add_action("do_enter", "enter");
}
int do_enter ( string arg )
{
	object ob = this_player () ;
 
	if( !arg || arg !="chuan" ) 
	{
		tell_object(this_player() , "你要 enter 哪儿？\n" ) ;
		return 1 ;
	}
	message_vision("船夫一见有人上船，忙叫了一声：开船喽！\n", ob);
	message_vision("船夫升起帆，船就向西方航行。\n", ob);
	ob ->move("/d/taohua/dahai") ;
	tell_object(ob, BLU "你在海上航行了很久很久.......\n" NOR ) ;
	call_out("rtaohua", 10 , ob );
	return 1 ;
}
void rtaohua( object ob )
{
	tell_object(ob , "大船终于抵达了中原的一个繁华城市。你走下船来。\n" ) ;
	ob->move ("/d/jiaxing/jiaxinggang") ;
}