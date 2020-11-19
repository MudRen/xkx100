// mei_po.c
#include <ansi.h>

inherit NPC;

string marry();
string unmarry();

void create()
{
        set_name("媒婆", ({ "mei po","mei" }) );
        set("title", "红娘庄");
        set("gender", "女性" );
        set("age", 43);
        set("long",
                "一位精明能干的老媒婆\n");
        set("max_qi",800);
        set("max_jing",800);
        set("combat_exp", 10000);
        set("attitude", "friendly");
        set("inquiry", ([
                "婚约" : "是啊……这里就可以缔结和解除婚约",
        ]) );
        set_skill("literate", 70);
        set_skill("dodge", 200);
        set_skill("unarmed", 100);
        setup();
        add_money("gold", 10);
        carry_object("/clone/misc/cloth")->wear();
}

void init()
{
        

        ::init();
        add_action("do_marry", "marry");
        add_action("do_unmarry", "unmarry");
}

int do_marry(string arg) {
        object marry_card1,marry_card2, obj, me;
        object *list;
        int i, have_marry;
        me = this_player();
        list = all_inventory(me);
        i = sizeof(list);
        have_marry = 0;
        if((string)me->query("gender")=="无性"){
              say("既然你已经自宫了，就不能结婚了，请回吧！\n");
              return 1;
            }
        if ( (string)me->query("class")=="bonze")
             return notify_fail("你是出家人,怎么能结婚！嗨！现在的和尚……\n");
        if ( (int)me->query("age")<17)
             return notify_fail("你年龄还小,等到十七岁再来吧.\n");
        while (i--) {
              if (((string)list[i]->query("id")) == "marrycard")
                return notify_fail(
                "你已经和别人有婚约了吧?这里不允许重婚的。\n");
        }

        if(!arg || !objectp(obj = present(arg, environment(me)))
                || !find_player(arg)|| !find_living(arg))
        return notify_fail("你想和谁缔结良缘？\n");
        if( !environment()
        ||      base_name(environment()) != query("startroom") )
             return notify_fail(
                "真是抱歉，请您等一下到红娘庄来找我吧。\n");

        if( !living(obj) )
                return notify_fail(obj->name() +
                "已经无法和你缔结良缘了。\n");

        if((string)obj->query("gender")== (string)me->query("gender"))
                return notify_fail("难道你不怕" + RED"AIDS"NOR + "吗？\n");

        if(obj==me)     return notify_fail("你不能和自己缔结婚约。\n");

        if( userp(obj) && !((object)obj->query("marks/"+me->name(1)))){
                message_vision(MAG "\n$N对著$n说道："
                    + RANK_D->query_self(me)
                    + me->name() + "，愿意和"
               + RANK_D->query_respect(obj) +
                "结为夫妇\n\n"NOR, me,obj);
                 me->set("marks/"+obj->name(1), 1);
           tell_object(obj, MAG "如果你愿意和对方结为夫妇，请你也对"
                        +me->name() + "("+(string)me->query("id")+
                        ")"+ "下一次 marry 指令。\n" NOR);
                write(MAG
                        "现在你急切盼望着你的心上人说同意……\n" NOR);
                return 1;
        }


        marry_card1 = new("/obj/marry_card");
        marry_card1->set("name","你和"+obj->query("id")+"的婚约");
        marry_card1->move(me);
        marry_card2 = new("/obj/marry_card");
        marry_card2->set("name","你和"+me->query("id")+"的婚约");
        marry_card2->move(obj);

     message_vision(MAG "恭喜 $N 和 $n ，一对璧人终于喜结良缘。\n" NOR,obj,me);
        CHANNEL_D->do_channel(this_object(), "chat",
        sprintf( "%s 和 %s 现在开始是夫妇啦! \n",
        me->name(1), obj->name(1)));
        return 1;
}

int do_unmarry(string arg)
{
        object marry_card1,marry_card2,  me;
        object *list, couple_ob;
        int i, have_marry;
        string target, tmpstr1, tmpstr2,str1,str2;
        string cardname;

        me = this_player();
        list = all_inventory(me);
        i = sizeof(list);
        have_marry = 0;
        while (i--) {
         if (((string)list[i]->query("id")) == "marrycard") {
                        marry_card1 = list[i];
                        cardname = list[i]->query("name");
                        have_marry = 1;
                }
        }

        if (have_marry == 0)
                return notify_fail("你还未有婚约啊。\n");
        if( !environment()
        ||      base_name(environment()) != query("startroom") )
           return notify_fail("真是抱歉，请您等一下到红娘庄来找我吧。\n");
        if (sscanf(cardname,"你和%s的婚约" ,target)!=1)
                return notify_fail("你没有伴侣.\n");
         if(!objectp(couple_ob = present(target, environment(me)))
                || !find_player(target) )
                return notify_fail("你的伴侣现在不在场.\n");

        if ((string)couple_ob->query("gender") != "女性") {
                tmpstr1 = "老婆"; tmpstr2 = "老公";
                str1 = "她"; str2 = "他";
        } else {
                tmpstr1 = "老公"; tmpstr2 = "老婆";
                str1 = "他"; str2 = "她";
        }

        list = all_inventory(couple_ob);
        i = sizeof(list);
        have_marry = 0;
        while (i--) {
              if (((string)list[i]->query("id")) == "marrycard") {
                        marry_card2 = list[i];
                        have_marry = 1;
                }
        }
        if (have_marry = 0) {
                destruct(marry_card1);
        message_vision(MAG " $N 和 $n 从现在开始解除婚约,互不相干!\n" NOR,
        couple_ob, me);
        CHANNEL_D->do_channel(this_object(), "chat",
        sprintf( "%s 和 %s 从现在开始解除婚约,互不相干! \n",
        me->name(1), couple_ob->name(1)));

                return 1;
        }

        if( userp(couple_ob) && !((object)couple_ob->query("marks/"
                + "unmarry" +me->name(1))) ) {
                message_vision(MAG "\n$N对著$n说道："
                        + RANK_D->query_self(me)
                        + me->name() + "，咱们解除婚约吧!好吗?\n\n"
                        NOR, me, couple_ob);
                 me->set("marks/"+"unmarry"+couple_ob->name(1), 1);
           tell_object(couple_ob, MAG "如果你愿意解除婚约，请你也"
                + "下一次 unmarry 指令。\n" NOR);
                write(MAG
                "现在你只有等着" +str2 +" 同意啦...\n" NOR);
                return 1;
        }
        destruct(marry_card1);
        destruct(marry_card2);

        message_vision(MAG " $N 和 $n 从现在开始解除婚约,互不相干!\n" NOR,
        couple_ob, me);
        CHANNEL_D->do_channel(this_object(), "chat",
        sprintf( "%s 和 %s 从现在开始解除婚约,互不相干! \n",
        me->name(1), couple_ob->name(1)));

        return 1;
}