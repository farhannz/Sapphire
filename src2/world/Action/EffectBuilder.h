#ifndef SAPPHIRE_EFFECTBUILDER_H
#define SAPPHIRE_EFFECTBUILDER_H

#include <ForwardsZone.h>
#include <Common.h>

namespace Sapphire::World::Action
{
  class EffectBuilder
  {
  public:
    EffectBuilder( Entity::CharaPtr source, uint32_t actionId, uint16_t sequence );

    void heal( Entity::CharaPtr& effectTarget, Entity::CharaPtr& healingTarget, uint32_t amount,
               Common::ActionHitSeverityType severity = Common::ActionHitSeverityType::NormalHeal,
               Common::ActionEffectResultFlag flag = Common::ActionEffectResultFlag::None);

    void restoreMP( Entity::CharaPtr& effectTarget, Entity::CharaPtr& restoringTarget, uint32_t amount,
                    Common::ActionEffectResultFlag flag = Common::ActionEffectResultFlag::None);

    void damage( Entity::CharaPtr& effectTarget, Entity::CharaPtr& damagingTarget, uint32_t amount,
                 Common::ActionHitSeverityType severity = Common::ActionHitSeverityType::NormalDamage,
                 Common::ActionEffectResultFlag flag = Common::ActionEffectResultFlag::None);

    void startCombo( Entity::CharaPtr& target, uint16_t actionId );

    void comboSucceed( Entity::CharaPtr& target );

    void applyStatusEffect( Entity::CharaPtr& target, uint16_t statusId, uint8_t param );

    void mount( Entity::CharaPtr& target, uint16_t mountId );

    void buildAndSendPackets();


  private:
    void moveToResultList( Entity::CharaPtr& chara, EffectResultPtr result );

    uint64_t getResultDelayMs();

    std::shared_ptr< Sapphire::Network::Packets::FFXIVPacketBase > buildNextEffectPacket( uint32_t globalSequence );

  private:
    uint32_t m_actionId;
    uint16_t m_sequence;

    Entity::CharaPtr m_sourceChara;
    std::unordered_map< uint32_t, std::shared_ptr< std::vector< EffectResultPtr > > > m_resolvedEffects;
  };

}

#endif //SAPPHIRE_EFFECTBUILDER_H
