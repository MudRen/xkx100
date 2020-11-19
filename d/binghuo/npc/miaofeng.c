// miaofeng.c

#include <ansi.h>
inherit NPC;

void create()
{
	set_name("妙风使", ({ "miaofeng shi", "miaofeng", "shi" }));
	set("long", "此人黄须鹰鼻，一看就知道是个胡人。\n");
	set("title",HIG "明教总教"HIM"使者"NOR);
	set("gender", "男性");
	set("age", 30);
	set("shen_type",1);
	set("attitude", "friendly");
	set("class", "fighter");

	set("per", 28);
	set("str", 30);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("qi", 2000);
	set("max_qi", 2000);
	set("jing", 1300);
	set("max_jing", 1300);
	set("neili", 3000);
	set("max_neili", 3000);
	set("jiali", 120);

	set("combat_exp", 500000);
	set("score", 50000);
    
	set_skill("force", 150);
	set_skill("unarmed", 100);
	set_skill("dodge", 100);
	set_skill("parry", 100);
	set_skill("sword",150);
	set_skill("jiuyang-shengong", 150);
	set_skill("qiankun-danuoyi", 150);
	set_skill("changquan",200);
	set_skill("shenghuo-ling",200);

	map_skill("force", "jiuyang-shengong");
	map_skill("dodge", "qiankun-danuoyi");
	map_skill("unarmed", "changquan");
	map_skill("sword","shenghuo-ling");
	map_skill("parry","shenghuo-ling");

	setup();
	carry_object("/clone/weapon/changjian")->wield();
	carry_object("/clone/misc/cloth")->wear();
	add_money("silver",70);
}

void init()
{
        object me;
        ::init();
        if (interactive(me = this_player()))
        {
                set_leader(me);
	        remove_call_out("kill_ob");
                call_out("kill_ob", 1, me);
        }
}
