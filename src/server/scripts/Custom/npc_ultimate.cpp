#include "ScriptPCH.h"


class npc_ultimate : public CreatureScript
{
public:
    npc_ultimate() : CreatureScript("npc_ultimate") { }

    bool OnGossipHello(Player* pPlayer, Creature* pCreature)
    {
        if (pCreature->isQuestGiver())
            pPlayer->PrepareQuestMenu(pCreature->GetGUID());

        pCreature->MonsterWhisper("Приветствую странник'", pPlayer->GetGUID(), false);

                {
                        pPlayer->ADD_GOSSIP_ITEM(10, "Морфер"                   , GOSSIP_SENDER_MAIN, 2215);
                        pPlayer->ADD_GOSSIP_ITEM(11, "Деморф"                   , GOSSIP_SENDER_MAIN, 2300);
        }

        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
        return true;
    }

    bool OnGossipSelect(Player* pPlayer, Creature* pCreature, uint32 /*uiSender*/, uint32 uiAction)
    {
        pPlayer->PlayerTalkClass->ClearMenus();
        switch(uiAction)
        {
                    case 2215: //Превращения
                    pCreature->MonsterWhisper("Дополнительный модуль 'Морфер' загружен.Стоимость морфа 1 Эмблема Льда.", pPlayer->GetGUID(), false);

                                {
    pPlayer->ADD_GOSSIP_ITEM(10, "Иллидан", GOSSIP_SENDER_MAIN, 2216);
    pPlayer->ADD_GOSSIP_ITEM(10, "Акама", GOSSIP_SENDER_MAIN, 2218);
    pPlayer->ADD_GOSSIP_ITEM(10, "Рыцарь смерти", GOSSIP_SENDER_MAIN, 2219);
    pPlayer->ADD_GOSSIP_ITEM(10, "Таурен", GOSSIP_SENDER_MAIN, 2220);
    pPlayer->ADD_GOSSIP_ITEM(10, "Нежить", GOSSIP_SENDER_MAIN, 2221);
    pPlayer->ADD_GOSSIP_ITEM(10, "Человек", GOSSIP_SENDER_MAIN, 2222);
    pPlayer->ADD_GOSSIP_ITEM(10, "Король Лич", GOSSIP_SENDER_MAIN, 2223);
    pPlayer->ADD_GOSSIP_ITEM(10, "Тирион", GOSSIP_SENDER_MAIN, 2224);
    pPlayer->ADD_GOSSIP_ITEM(10, "Утер", GOSSIP_SENDER_MAIN, 2225);
    pPlayer->ADD_GOSSIP_ITEM(10, "Артас", GOSSIP_SENDER_MAIN, 2226);
        pPlayer->ADD_GOSSIP_ITEM(7, "[Ещё] ->"                   , GOSSIP_SENDER_MAIN, 2250);
        pPlayer->ADD_GOSSIP_ITEM(7, "<- [Главное меню]"                          , GOSSIP_SENDER_MAIN, 5552);
                                }

        pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());
                break;

                        case 2250:
                                {
        ///////////// From SPGM
        pPlayer->ADD_GOSSIP_ITEM(10, "Алгалон", GOSSIP_SENDER_MAIN, 2227);
        pPlayer->ADD_GOSSIP_ITEM(10, "Владыка Судеб Каззак", GOSSIP_SENDER_MAIN, 2229);
        pPlayer->ADD_GOSSIP_ITEM(10, "Ониксия", GOSSIP_SENDER_MAIN, 2230);
        pPlayer->ADD_GOSSIP_ITEM(10, "Таддиус", GOSSIP_SENDER_MAIN, 2231);
        pPlayer->ADD_GOSSIP_ITEM(10, "Глут", GOSSIP_SENDER_MAIN, 2232);
        pPlayer->ADD_GOSSIP_ITEM(10, "Мексна", GOSSIP_SENDER_MAIN, 2233);
        pPlayer->ADD_GOSSIP_ITEM(10, "Сапфирион", GOSSIP_SENDER_MAIN, 2234);
        pPlayer->ADD_GOSSIP_ITEM(10, "Нот Чумной", GOSSIP_SENDER_MAIN, 2235);
        pPlayer->ADD_GOSSIP_ITEM(10, "Кель'Тузед", GOSSIP_SENDER_MAIN, 2236);
        pPlayer->ADD_GOSSIP_ITEM(10, "Кель'тас Солнечный Скиталец", GOSSIP_SENDER_MAIN, 2237);
        pPlayer->ADD_GOSSIP_ITEM(10, "К'Тун", GOSSIP_SENDER_MAIN, 2238);
        pPlayer->ADD_GOSSIP_ITEM(10, "Тралл", GOSSIP_SENDER_MAIN, 2239);
        pPlayer->ADD_GOSSIP_ITEM(7, "<- [Назад]"                 , GOSSIP_SENDER_MAIN, 2215);
        pPlayer->ADD_GOSSIP_ITEM(7, "<- [Главное меню]"                          , GOSSIP_SENDER_MAIN, 5552);
                                }

        pPlayer->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,pCreature->GetGUID());
        break;




            case 5552: //Back To Main Menu
                {
                        pPlayer->ADD_GOSSIP_ITEM(10, "Морфер"                   , GOSSIP_SENDER_MAIN, 2215);
                        pPlayer->ADD_GOSSIP_ITEM(11, "Деморф"                   , GOSSIP_SENDER_MAIN, 2300);
        }

        pPlayer->SEND_GOSSIP_MENU(pPlayer->GetGossipTextId(pCreature), pCreature->GetGUID());
        return true;

        case 2216:
                pPlayer->CLOSE_GOSSIP_MENU();
                if(pPlayer->HasItemCount(49426, 1, true))
                {
            pPlayer->DestroyItemCount(49426, 1, true);
            pPlayer->SetDisplayId(21135);
                        pPlayer->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);
                }
                else
                {
                        pCreature->MonsterSay("У тебя не достаточно Эмблем Льда.", LANG_UNIVERSAL, NULL);
                }
                break;
 
        case 2218:
                        pPlayer->CLOSE_GOSSIP_MENU();
                        if(pPlayer->HasItemCount(49426, 1, true))
                {
            pPlayer->DestroyItemCount(49426, 1, true);
            pPlayer->SetDisplayId(20681);
                        pPlayer->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);
            }
                else
                {
                        pCreature->MonsterSay("У тебя не достаточно Эмблем Льда.", LANG_UNIVERSAL, NULL);
                }
                break;
 
        case 2219:
                        pPlayer->CLOSE_GOSSIP_MENU();
                        if(pPlayer->HasItemCount(49426, 1, true))
                {
            pPlayer->DestroyItemCount(49426, 1, true);
            pPlayer->SetDisplayId(16508);
                        pPlayer->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);
            }
                else
                {
                        pCreature->MonsterSay("У тебя не достаточно Эмблем Льда.", LANG_UNIVERSAL, NULL);
                }
                break;
 
        case 2220:
                        pPlayer->CLOSE_GOSSIP_MENU();
                        if(pPlayer->HasItemCount(49426, 1, true))
                {
            pPlayer->DestroyItemCount(49426, 1, true);
            pPlayer->SetDisplayId(17332);
                        pPlayer->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);
            }
                else
                {
                        pCreature->MonsterSay("У тебя не достаточно Эмблем Льда.", LANG_UNIVERSAL, NULL);
                }                             
                break;
                
        case 2221:
                                        pPlayer->CLOSE_GOSSIP_MENU();
                                        if(pPlayer->HasItemCount(49426, 1, true))
                {
            pPlayer->DestroyItemCount(49426, 1, true);
            pPlayer->SetDisplayId(2789);
                        pPlayer->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);
            }
                else
                {
                        pCreature->MonsterSay("У тебя не достаточно Эмблем Льда.", LANG_UNIVERSAL, NULL);
                }
                break;
 
                case 2222:
                                        pPlayer->CLOSE_GOSSIP_MENU();
                                        if(pPlayer->HasItemCount(49426, 1, true))
                {
            pPlayer->DestroyItemCount(49426, 1, true);
            pPlayer->SetDisplayId(16280);
                        pPlayer->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);
            }
                else
                {
                        pCreature->MonsterSay("У тебя не достаточно Эмблем Льда.", LANG_UNIVERSAL, NULL);
                }
                                        break;
 
                case 2223:
                                        pPlayer->CLOSE_GOSSIP_MENU();
                                        if(pPlayer->HasItemCount(49426, 1, true))
                {
            pPlayer->DestroyItemCount(49426, 1, true);
            pPlayer->SetDisplayId(24191);
                        pPlayer->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);
            }
                else
                {
                        pCreature->MonsterSay("У тебя не достаточно Эмблем Льда.", LANG_UNIVERSAL, NULL);
                }
                                        break;
 
                case 2224:
                                        pPlayer->CLOSE_GOSSIP_MENU();
                                        if(pPlayer->HasItemCount(49426, 1, true))
                {
                        pPlayer->DestroyItemCount(49426, 1, true);
            pPlayer->SetDisplayId(22209);
                        pPlayer->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);
            }
                else
                {
                        pCreature->MonsterSay("У тебя не достаточно Эмблем Льда.", LANG_UNIVERSAL, NULL);
                }
                                        break;
 
                case 2225:
                                        pPlayer->CLOSE_GOSSIP_MENU();
                                        if(pPlayer->HasItemCount(49426, 1, true))
                {
            pPlayer->DestroyItemCount(49426, 1, true);
            pPlayer->SetDisplayId(23889);
                        pPlayer->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);
            }
                else
                {
                        pCreature->MonsterSay("У тебя не достаточно Эмблем Льда.", LANG_UNIVERSAL, NULL);
                }
                                        break;
 
                                case 2226:
                                        pPlayer->CLOSE_GOSSIP_MENU();
                                        if(pPlayer->HasItemCount(49426, 1, true))
                {
                        pPlayer->DestroyItemCount(49426, 1, true);
                        pPlayer->SetDisplayId(24949);
                                                pPlayer->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);
                        }
                else
                {
                        pCreature->MonsterSay("У тебя не достаточно Эмблем Льда.", LANG_UNIVERSAL, NULL);
                }
                                        break;

                        case 2227: 
                                pPlayer->CLOSE_GOSSIP_MENU();
                                if(pPlayer->HasItemCount(49426, 1, true))
                {
    pPlayer->DestroyItemCount(49426, 1, true);
        pPlayer->SetDisplayId(28641);
        pPlayer->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.2f);
}
                else
                {
                        pCreature->MonsterSay("У тебя не достаточно Эмблем Льда.", LANG_UNIVERSAL, NULL);
                }
                                break;

case 2229: 
        pPlayer->CLOSE_GOSSIP_MENU();
        if(pPlayer->HasItemCount(49426, 1, true))
                {
    pPlayer->DestroyItemCount(49426, 1, true);
        pPlayer->SetDisplayId(17887);
        pPlayer->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.10f);
}
                else
                {
                        pCreature->MonsterSay("У тебя не достаточно Эмблем Льда.", LANG_UNIVERSAL, NULL);
                }
        break;

case 2230: 
        pPlayer->CLOSE_GOSSIP_MENU();
        if(pPlayer->HasItemCount(49426, 1, true))
                {
    pPlayer->DestroyItemCount(49426, 1, true);
        pPlayer->SetDisplayId(8570);
        pPlayer->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.1f);
}
                else
                {
                        pCreature->MonsterSay("У тебя не достаточно Эмблем Льда.", LANG_UNIVERSAL, NULL);
                }
        break;

case 2231:
        pPlayer->CLOSE_GOSSIP_MENU();
        if(pPlayer->HasItemCount(49426, 1, true))
                {
                        pPlayer->DestroyItemCount(49426, 1, true);
        pPlayer->SetDisplayId(16137);
        pPlayer->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.2f);
}
                else
                {
                        pCreature->MonsterSay("У тебя не достаточно Эмблем Льда.", LANG_UNIVERSAL, NULL);
                }
        break;

case 2232: 
        pPlayer->CLOSE_GOSSIP_MENU();
        if(pPlayer->HasItemCount(49426, 1, true))
                {
    pPlayer->DestroyItemCount(49426, 1, true);
        pPlayer->SetDisplayId(16064);
        pPlayer->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.2f);
}
                else
                {
                        pCreature->MonsterSay("У тебя не достаточно Эмблем Льда.", LANG_UNIVERSAL, NULL);
                }
        break;

case 2233: 
        pPlayer->CLOSE_GOSSIP_MENU();
        if(pPlayer->HasItemCount(49426, 1, true))
                {
    pPlayer->DestroyItemCount(49426, 1, true);
        pPlayer->SetDisplayId(15928);
        pPlayer->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.15f);
}
                else
                {
                        pCreature->MonsterSay("У тебя не достаточно Эмблем Льда.", LANG_UNIVERSAL, NULL);
                }
        break;

case 2234: 
        pPlayer->CLOSE_GOSSIP_MENU();
        if(pPlayer->HasItemCount(49426, 1, true))
                {
    pPlayer->DestroyItemCount(49426, 1, true);
        pPlayer->SetDisplayId(16033);
        pPlayer->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.1f);
}
                else
                {
                        pCreature->MonsterSay("У тебя не достаточно Эмблем Льда.", LANG_UNIVERSAL, NULL);
                }
        break;

case 2235: 
        pPlayer->CLOSE_GOSSIP_MENU();
        if(pPlayer->HasItemCount(49426, 1, true))
                {
    pPlayer->DestroyItemCount(49426, 1, true);
        pPlayer->SetDisplayId(16590);
        pPlayer->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.7f);
}
                else
                {
                        pCreature->MonsterSay("У тебя не достаточно Эмблем Льда.", LANG_UNIVERSAL, NULL);
                }
        break;

case 2236: 
        pPlayer->CLOSE_GOSSIP_MENU();
        if(pPlayer->HasItemCount(49426, 1, true))
                {
    pPlayer->DestroyItemCount(49426, 1, true);
                pPlayer->SetDisplayId(15945);
        pPlayer->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.2f);
}
                else
                {
                        pCreature->MonsterSay("У тебя не достаточно Эмблем Льда.", LANG_UNIVERSAL, NULL);
                }
        break;

case 2237: 
        pPlayer->CLOSE_GOSSIP_MENU();
        if(pPlayer->HasItemCount(49426, 1, true))
                {
    pPlayer->DestroyItemCount(49426, 1, true);
        pPlayer->SetDisplayId(20023);
        pPlayer->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.5f);
}
                else
                {
                        pCreature->MonsterSay("У тебя не достаточно Эмблем Льда.", LANG_UNIVERSAL, NULL);
                }
        break;

case 2238: 
        pPlayer->CLOSE_GOSSIP_MENU();
        if(pPlayer->HasItemCount(49426, 1, true))
                {
    pPlayer->DestroyItemCount(49426, 1, true);
        pPlayer->SetDisplayId(15786);
        pPlayer->SetFloatValue(OBJECT_FIELD_SCALE_X, 0.2f);
}
                else
                {
                        pCreature->MonsterSay("У тебя не достаточно Эмблем Льда.", LANG_UNIVERSAL, NULL);
                }
        break;

case 2239: 
        pPlayer->CLOSE_GOSSIP_MENU();
        if(pPlayer->HasItemCount(49426, 1, true))
                {
    pPlayer->DestroyItemCount(49426, 1, true);
        pPlayer->SetDisplayId(4527);
        pPlayer->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);
}
                else
                {
                        pCreature->MonsterSay("У тебя не достаточно Эмблем Льда.", LANG_UNIVERSAL, NULL);
                }
        break;

case 2300:
        pPlayer->CLOSE_GOSSIP_MENU();
        pPlayer->RestoreDisplayId();
        pPlayer->SetFloatValue(OBJECT_FIELD_SCALE_X, 1.0f);
break;
/* Конец Превращения */
        }
        return true;
    }
};
void AddSC_npc_ultimate()
{
    new npc_ultimate;
}