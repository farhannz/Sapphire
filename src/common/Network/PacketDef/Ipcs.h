#ifndef _CORE_NETWORK_PACKETS_IPCS_H
#define _CORE_NETWORK_PACKETS_IPCS_H

#include<stdint.h>

namespace Core {
namespace Network {
namespace Packets {

   ////////////////////////////////////////////////////////////////////////////////
   /// Lobby Connection IPC Codes
   /**
   * Server IPC Lobby Type Codes.
   */
   enum ServerLobbyIpcType : uint16_t
   {
      LobbyError                 = 0x0002,
      LobbyServiceAccountList    = 0x000C,
      LobbyCharList              = 0x000D,
      LobbyCharCreate            = 0x000E,
      LobbyEnterWorld            = 0x000F,
      LobbyServerList            = 0x0015,
      LobbyRetainerList          = 0x0017,

   };

   /**
   * Client IPC Lobby Type Codes.
   */
   enum ClientLobbyIpcType : uint16_t
   {
      ReqCharList                = 0x0003,
      ReqEnterWorld              = 0x0004,
      ReqServiceAccountList      = 0x0005,

      ReqCharDelete              = 0x000A,
      ReqCharCreate              = 0x000B,
   };

   ////////////////////////////////////////////////////////////////////////////////
   /// Zone Connection IPC Codes
   /**
   * Server IPC Zone Type Codes.
   */
   enum ServerZoneIpcType : uint16_t
   {
      Ping                       = 0x0065,
      Init                       = 0x0066,
      Chat                       = 0x00B9,
      ChatBanned                 = 0x006B,
      Logout                     = 0x0077,
      CFNotify                   = 0x0078,
      CFMemberStatus             = 0x0079,
      CFDutyInfo                 = 0x007A,
      CFPlayerInNeed             = 0x007F,


      SocialRequestError         = 0x00AD,
      Playtime                   = 0x00B7, // updated 4.1
      CFRegistered               = 0x00B8, // updated 4.1
      SocialRequestResponse      = 0x00BB, // updated 4.1
      SocialList                 = 0x00BE, // updated 4.1
      UpdateSearchInfo           = 0x00C0, // updated 4.1
      InitSearchInfo             = 0x00C1, // updated 4.1
      ServerNotice               = 0x00F0, // updated 4.2
      SetOnlineStatus            = 0x00F1, // updated 4.2

      LogMessage                 = 0x00D0,
      BlackList                  = 0x00D4, // updated 4.1

      LinkshellList              = 0x00DC, // updated 4.1
      StatusEffectList           = 0x0125, // updated 4.2
      Effect                     = 0x0128, // updated 4.2
      GCAffiliation              = 0x00FC,

      PlayerSpawn                = 0x015C, // updated 4.2
      NpcSpawn                   = 0x015D, // updated 4.2
      ActorMove                  = 0x015E, // updated 4.2
      ActorSetPos                = 0x015F, // updated 4.2
      ActorCast                  = 0x0162, // updated 4.2
      HateList                   = 0x0165, // updated 4.2
      UpdateClassInfo            = 0x0169, // updated 4.2
      InitUI                     = 0x016B, // updated 4.2
      ActorOwner                 = 0x012D, // updated 4.1
      PlayerStats                = 0x016C, // updated 4.2
      PlayerStateFlags           = 0x016E, // updated 4.2
      PlayerClassInfo            = 0x016F, // updated 4.2
      ModelEquip                 = 0x0170, // updated 4.2

      AddStatusEffect            = 0x0141,
      ActorControl142            = 0x0142, // updated 4.2
      ActorControl143            = 0x0143, // updated 4.2
      ActorControl144            = 0x0144, // updated 4.2
      UpdateHpMpTp               = 0x0145, // updated 4.2

      ItemInfo                   = 0x017A, // updated 4.2
      ContainerInfo              = 0x017B, // updated 4.2
      InventoryTransactionFinish = 0x017C, // updated 4.2
      InventoryTransaction       = 0x017D, // updated 4.2
      CurrencyCrystalInfo        = 0x017E, // updated 4.2
      InventoryActionAck         = 0x1139,
      UpdateInventorySlot        = 0x0153, // updated 4.1

      EventPlay                  = 0x018E, // updated 4.2
      EventStart                 = 0x0198, // updated 4.2
      EventFinish                = 0x0199, // updated 4.2

      EventLinkshell             = 0x1169,

      QuestMessage               = 0x0188, // updated 4.1
      QuestActiveList            = 0x017D, // updated 4.1
      QuestUpdate                = 0x017E, // updated 4.1
      QuestCompleteList          = 0x017F, // updated 4.1

      QuestFinish                = 0x0180, // updated 4.1
      MSQTrackerComplete         = 0x0181,
      MSQTrackerProgress         = 0x0182,
      QuestTracker               = 0x018D, // updated 4.1
      ActorSpawn                 = 0x0190, // DEPRECATED
      ActorFreeSpawn             = 0x0191, // unchanged 4.2
      InitZone                   = 0x019A, // unchanged 4.2
      Mount                      = 0x01CD, // updated 4.2
      WeatherChange              = 0x01EA, // updated 4.2
      PlayerTitleList            = 0x01EB, // updated 4.2
      Discovery                  = 0x01EC, // updated 4.2

      EorzeaTimeOffset           = 0x01C0, // updated 4.1

      EquipDisplayFlags          = 0x01CC, // updated 4.1

      CFAvailableContents        = 0x01CF,

      PrepareZoning              = 0x027C, // updated 4.2
      ActorGauge                 = 0x027D, // updated 4.2
      // Unknown IPC types that still need to be sent
      // TODO: figure all these out properly
      IPCTYPE_UNK_320            = 0x0235, // updated 4.2
      IPCTYPE_UNK_322            = 0x0237, // updated 4.2

      PerformNote                = 0x0286, // updated 4.2
   };

   // TODO: Include structures for the individual packet segment types

   /**
   * Client IPC Zone Type Codes.
   */
   enum ClientZoneIpcType : uint16_t
   {

      PingHandler              = 0x0065, // unchanged 4.2
      InitHandler              = 0x0066, // unchanged 4.2
      ChatHandler              = 0x00C7, // updated 4.2

      FinishLoadingHandler     = 0x0069, // unchanged 4.2

      CFCommenceHandler        = 0x006F,
      CFRegisterDuty           = 0x0071,
      CFRegisterRoulette       = 0x0072,
      PlayTimeHandler          = 0x0073, // unchanged 4.2
      LogoutHandler            = 0x0074, // unchanged 4.2

      CFDutyInfoHandler        = 0x0078, // updated 4.2

      SocialReqSendHandler     = 0x00AE, // updated 4.1
      SocialListHandler        = 0x00CF, // updated 4.2
      ReqSearchInfoHandler     = 0x00D4, // updated 4.2
      SetSearchInfoHandler     = 0x00D5, // updated 4.2

      BlackListHandler         = 0x00E0, // updated 4.2

      LinkshellListHandler     = 0x00E8, // updated 4.2

      FcInfoReqHandler         = 0x0109, // updated 4.1

      ZoneLineHandler          = 0x0130, // updated 4.2
      ActionHandler            = 0x0131, // updated 4.2
      DiscoveryHandler         = 0x0132, // updated 4.2

      SkillHandler             = 0x0134, // updated 4.2
      GMCommand1               = 0x0135, // updated 4.2
      GMCommand2               = 0x0136, // updated 4.2
      UpdatePositionHandler    = 0x0138, // updated 4.2
      UpdatePositionInstance   = 0x0177, // updated 4.2

      InventoryModifyHandler   = 0x013F, // updated 4.2

      TalkEventHandler         = 0x0148, // updated 4.2
      EmoteEventHandler        = 0x0149, // updated 4.2
      WithinRangeEventHandler  = 0x014A, // updated 4.2
      OutOfRangeEventHandler   = 0x014B, // updated 4.2
      EnterTeriEventHandler    = 0x014C, // updated 4.2

      ReturnEventHandler       = 0x0151, // updated 4.2 ?
      TradeReturnEventHandler  = 0x0152, // updated 4.2 ?


      LinkshellEventHandler    = 0x0144, // updated 4.1 ??
      LinkshellEventHandler1   = 0x0145, // updated 4.1 ??

      ReqEquipDisplayFlagsChange  = 0x016C, // updated 4.2

      PerformNoteHandler       = 0x0160,
   };

   ////////////////////////////////////////////////////////////////////////////////
   /// Chat Connection IPC Codes
   /**
   * Server IPC Chat Type Codes.
   */
   enum ServerChatIpcType : uint16_t
   {
      Tell                     = 0x0064, // updated for sb
      TellErrNotFound          = 0x0066,
   };

   /**
   * Client IPC Chat Type Codes.
   */
   enum ClientChatIpcType : uint16_t
   {
      TellReq                  = 0x0064,
   };


} /* Packets */
} /* Network */
} /* Core */

#endif /*_CORE_NETWORK_PACKETS_IPCS_H*/
