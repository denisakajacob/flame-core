#include "ScriptPCH.h"
#include "ScriptMgr.h"

#define MSG_GOSSIP_TEXT_GETTING_STARTED "Приветствуем вас на нашем сервере!"

#define MSG_ERR_INCOMBAT "Вы находитесь в бою. Чтобы использовать данного Npc выйдите из него."

#define MSG_GOSSIP_TEXT_PROFFESION_SECON_MENU "[Меню Второстепенных профессий] ->"
#define MSG_GOSSIP_TEXT_MAIN_MENU "<- [Вернутся в Главное меню]"

#define MSG_GOSSIP_TEXT_ALCHEMY "Изучить Алхимию."
#define MSG_GOSSIP_TEXT_BLACKSMITHING "Изучить Кузнечное Дело."
#define MSG_GOSSIP_TEXT_ENCNANTING "Изучить Наложение Чар."
#define MSG_GOSSIP_TEXT_ENGINEERING "Изучить Инженерное дело."
#define MSG_GOSSIP_TEXT_HERBALISM "Изучить Травничество."
#define MSG_GOSSIP_TEXT_INSCRIPTION "Изучить Начертание."
#define MSG_GOSSIP_TEXT_JEWELCRAFTING "Изучить Ювелирное дело."
#define MSG_GOSSIP_TEXT_LEATHERWORKING "Изучить Кожевничество."
#define MSG_GOSSIP_TEXT_MINING "Изучить Горное дело."
#define MSG_GOSSIP_TEXT_SKINNING "Изучить Снятие шкур."
#define MSG_GOSSIP_TEXT_TAILORING "Изучить Портное дело."

#define MSG_GOSSIP_TEXT_COOKING "Изучить Кулинарию."
#define MSG_GOSSIP_TEXT_FIRST_AID "Изучить Первую помощь."
#define MSG_GOSSIP_TEXT_FISHING "Изучить Рыбную ловлю."

class npc_proff : public CreatureScript
{
    public: 
    npc_proff() : CreatureScript("npc_proff") { }
        
        void CompleteLearnProfession(Player *player, Creature * _creature, SkillType skill) 
     { 
         if (PlayerAlreadyHasNineProfessions(player) && !IsSecondarySkill(skill)) 
            _creature->MonsterWhisper("Вы уже выучили 3 професcии!", player->GetGUID()); 
         else 
         { 
             if (!LearnAllRecipesInProfession(player, skill)) 
                 _creature->MonsterWhisper("Ошибка!", player->GetGUID()); 
         } 
     } 
   
   bool IsSecondarySkill(SkillType skill) const 
     { 
         return skill == SKILL_COOKING || skill == SKILL_FIRST_AID; 
     } 
   
   bool PlayerAlreadyHasNineProfessions(const Player *pPlayer) const 
     { 
         uint32 skillCount = 0; 

         if (pPlayer->HasSkill(SKILL_MINING)) 
             skillCount++; 
         if (pPlayer->HasSkill(SKILL_SKINNING)) 
             skillCount++; 
         if (pPlayer->HasSkill(SKILL_HERBALISM)) 
             skillCount++; 

         if (skillCount >= 3) 
             return true; 

         for (uint32 i = 0; i < sSkillLineStore.GetNumRows(); ++i) 
         { 
             SkillLineEntry const *SkillInfo = sSkillLineStore.LookupEntry(i); 
             if (!SkillInfo) 
                 continue; 

             if (SkillInfo->categoryId == SKILL_CATEGORY_SECONDARY) 
                 continue; 

             if ((SkillInfo->categoryId != SKILL_CATEGORY_PROFESSION) || !SkillInfo->canLink) 
                 continue; 

             const uint32 skillID = SkillInfo->id; 
             if (pPlayer->HasSkill(skillID)) 
                 skillCount++; 

             if (skillCount >= 3) 
                 return true; 
         } 

         return false; 
     } 

     bool LearnAllRecipesInProfession(Player *player, SkillType skill) 
     { 
         ChatHandler handler(player); 
         char* skill_name; 

         SkillLineEntry const *SkillInfo = sSkillLineStore.LookupEntry(skill); 
         skill_name = SkillInfo->name[handler.GetSessionDbcLocale()]; 

         if (!SkillInfo) 
         { 
             sLog->outError("Teleport NPC: received non-valid skill ID (LearnAllRecipesInProfession)"); 
             return false; 
         } 

         LearnSkillRecipesHelper(player, SkillInfo->id); 

         uint16 maxLevel = player->GetPureMaxSkillValue(SkillInfo->id); 
         player->SetSkill(SkillInfo->id, player->GetSkillStep(SkillInfo->id), maxLevel, maxLevel); 
         handler.PSendSysMessage(LANG_COMMAND_LEARN_ALL_RECIPES, skill_name); 
          
         return true; 
     } 
     // See "static void HandleLearnSkillRecipesHelper(Player* player,uint32 skill_id)" from cs_learn.cpp  
     void LearnSkillRecipesHelper(Player *player, uint32 skill_id) 
     { 
         uint32 classmask = player->getClassMask(); 

         for (uint32 j = 0; j < sSkillLineAbilityStore.GetNumRows(); ++j) 
         { 
             SkillLineAbilityEntry const *skillLine = sSkillLineAbilityStore.LookupEntry(j); 
             if (!skillLine) 
                 continue; 

             // wrong skill 
             if (skillLine->skillId != skill_id) 
                 continue; 

             // not high rank 
             if (skillLine->forward_spellid) 
                 continue; 

             // skip racial skills 
             if (skillLine->racemask != 0) 
                 continue; 

             // skip wrong class skills 
             if (skillLine->classmask && (skillLine->classmask & classmask) == 0) 
                 continue; 

             SpellInfo const* spellInfo = sSpellMgr->GetSpellInfo(skillLine->spellId);
            if (!spellInfo || !SpellMgr::IsSpellValid(spellInfo, player, false))
                continue; 

             player->learnSpell(skillLine->spellId, false); 
         } 
     } 
         bool OnGossipHello(Player *player, Creature *_creature)
         {
                 player->PlayerTalkClass->ClearMenus();
                 _creature->MonsterWhisper(MSG_GOSSIP_TEXT_GETTING_STARTED, player->GetGUID());
                 player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, MSG_GOSSIP_TEXT_ALCHEMY, GOSSIP_SENDER_MAIN, 2);
                 player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, MSG_GOSSIP_TEXT_BLACKSMITHING, GOSSIP_SENDER_MAIN, 3);
                 player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, MSG_GOSSIP_TEXT_ENCNANTING, GOSSIP_SENDER_MAIN, 4);
                 player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, MSG_GOSSIP_TEXT_ENGINEERING, GOSSIP_SENDER_MAIN, 5);
                 player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, MSG_GOSSIP_TEXT_HERBALISM, GOSSIP_SENDER_MAIN, 6);
                 player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, MSG_GOSSIP_TEXT_INSCRIPTION, GOSSIP_SENDER_MAIN, 7);
                 player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, MSG_GOSSIP_TEXT_JEWELCRAFTING, GOSSIP_SENDER_MAIN, 8);
                 player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, MSG_GOSSIP_TEXT_LEATHERWORKING, GOSSIP_SENDER_MAIN, 9);
                 player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, MSG_GOSSIP_TEXT_MINING, GOSSIP_SENDER_MAIN, 10);
                 player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, MSG_GOSSIP_TEXT_SKINNING, GOSSIP_SENDER_MAIN, 11);
                 player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, MSG_GOSSIP_TEXT_TAILORING, GOSSIP_SENDER_MAIN, 12);
                 player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, MSG_GOSSIP_TEXT_PROFFESION_SECON_MENU, GOSSIP_SENDER_MAIN, 13);
             player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,_creature->GetGUID());
                 return true;
         }
         bool OnGossipSelect(Player *player, Creature *_creature, uint32 sender, uint32 action )
                 {
                  if (!player->getAttackers().empty())
         {
                _creature->MonsterWhisper(MSG_ERR_INCOMBAT, player->GetGUID());
                player->CLOSE_GOSSIP_MENU();
        return false;
                  }
                  switch (action)
        {
        case 2:
                CompleteLearnProfession(player, _creature, SKILL_ALCHEMY); 
                player->CLOSE_GOSSIP_MENU();
                break;
        case 3:
                CompleteLearnProfession(player, _creature, SKILL_BLACKSMITHING); 
                player->CLOSE_GOSSIP_MENU();
                break;
        case 4:
                CompleteLearnProfession(player, _creature,  SKILL_ENCHANTING); 
                player->CLOSE_GOSSIP_MENU();
                break;
        case 5:
                CompleteLearnProfession(player, _creature, SKILL_ENGINEERING); 
                player->CLOSE_GOSSIP_MENU();
                break;
        case 6:
                CompleteLearnProfession(player, _creature, SKILL_HERBALISM); 
                player->CLOSE_GOSSIP_MENU();
                break;
        case 7:
                CompleteLearnProfession(player, _creature, SKILL_INSCRIPTION); 
                player->CLOSE_GOSSIP_MENU();
                break;
        case 8:
                CompleteLearnProfession(player, _creature, SKILL_JEWELCRAFTING);
                player->CLOSE_GOSSIP_MENU();
                break;
        case 9:
                CompleteLearnProfession(player, _creature, SKILL_LEATHERWORKING);
                player->CLOSE_GOSSIP_MENU();
                break;
        case 10:
                CompleteLearnProfession(player, _creature, SKILL_MINING);
                player->CLOSE_GOSSIP_MENU();
            break;
        case 11:
                CompleteLearnProfession(player, _creature, SKILL_SKINNING);
                player->CLOSE_GOSSIP_MENU();
                break;
        case 12:
                CompleteLearnProfession(player, _creature, SKILL_TAILORING);
                player->CLOSE_GOSSIP_MENU();
                break;
        case 13:
                player->PlayerTalkClass->ClearMenus();
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, MSG_GOSSIP_TEXT_COOKING, GOSSIP_SENDER_MAIN, 14);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, MSG_GOSSIP_TEXT_FIRST_AID, GOSSIP_SENDER_MAIN, 15);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TRAINER, MSG_GOSSIP_TEXT_FISHING, GOSSIP_SENDER_MAIN, 16);
                player->ADD_GOSSIP_ITEM(GOSSIP_ICON_TALK, MSG_GOSSIP_TEXT_MAIN_MENU, GOSSIP_SENDER_MAIN, 17);
                player->SEND_GOSSIP_MENU(DEFAULT_GOSSIP_MESSAGE,_creature->GetGUID());
                break;
        case 14:
                CompleteLearnProfession(player, _creature, SKILL_COOKING);
                player->CLOSE_GOSSIP_MENU();
                break;
        case 15:
                CompleteLearnProfession(player, _creature, SKILL_FIRST_AID); 
                player->CLOSE_GOSSIP_MENU();
            break;
        case 16:
                CompleteLearnProfession(player, _creature, SKILL_FISHING); 
                player->CLOSE_GOSSIP_MENU();
            break;
        case 17:
                OnGossipHello(player, _creature);
                break;
         }
                  return true;
         }
         
        };
 void AddSC_npc_proff()
{
    new npc_proff;
}