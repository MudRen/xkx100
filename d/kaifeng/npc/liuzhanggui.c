inherit NPC;
inherit F_DEALER;

void create()
{
        set_name("刘掌柜", ({ "liu zhanggui", "liu", "zhanggui" }) );
        set("gender", "男性" );
        set("age", 25);
        set("title", "雅琪轩老板");
        set("combat_exp", 5000);
        set("attitude", "friendly");
        set_temp("apply/attack", 20);
        set_temp("apply/defense", 20);
        set_temp("apply/armor", 20);
        set_temp("apply/damage", 30);

        set("vendor_goods", ({
                __DIR__"obj/ciwan",
                __DIR__"obj/luowenhai",
                __DIR__"obj/bibohu",
        }));

        setup();
        carry_object("/clone/cloth/jinduan")->wear();
}

void init()
{       
         

        add_action("do_buy", "buy");
        add_action("do_list", "list");
        ::init();
}