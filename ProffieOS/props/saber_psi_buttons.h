#ifndef PROPS_SABER_PSISTORM_BUTTONS_H
#define PROPS_SABER_PSISTORM_BUTTONS_H

 
#include "prop_base.h"
#include "../sound/hybrid_font.h"
 
#undef PROP_TYPE
#define PROP_TYPE SaberPsistormButtons
 
EFFECT(battery);
EFFECT(vmbegin);
EFFECT(vmend);
EFFECT(vmup);
EFFECT(vmdown);
EFFECT(vmmax);
EFFECT(vmmin);
 
class SaberPsistormButtons : public PropBase {
public:
    SaberPsistormButtons() : PropBase() {}
    const char* name() override { return "SaberPsistormButtons"; }
    
    void Loop() override {
        PropBase::Loop();
        DetectTwist();
        DetectSwing();
    }
    
    //play sound if present, else play beeper
    void trySound(Effect* sound, float duration, int beepfreq, int beepfreq2)
    {
        if (sound){
            hybrid_font.PlayCommon(sound);
        }
        else {
            beeper.Beep(duration, beepfreq);
            if (beepfreq2 > 0) beeper.Beep(duration, beepfreq2);
        }
    }
    
    //volume change function
    void ChangeVolume(bool up) {
        if (up) {
            STDOUT.println("Volume up");
            if (dynamic_mixer.get_volume() < VOLUME) {
                dynamic_mixer.set_volume(std::min<int>(VOLUME + VOLUME * 0.1, dynamic_mixer.get_volume() + VOLUME * 0.10));
                //beeper.Beep(0.5, 2000);
                trySound(&SFX_vmup, 0.5, 2000, 0);
                STDOUT.print("Current Volume: ");
                STDOUT.println(dynamic_mixer.get_volume());
            }
            else {
                trySound(&SFX_vmmax, 0.5, 3000, 0);
                //beeper.Beep(0.5, 3000);
            }
        }
        
        else {
            STDOUT.println("Volume Down");
            if (dynamic_mixer.get_volume() > (0.10 * VOLUME)) {
                dynamic_mixer.set_volume(std::max<int>(VOLUME * 0.1, dynamic_mixer.get_volume() - VOLUME * 0.10));
                //beeper.Beep(0.5, 2000);
                trySound(&SFX_vmdown, 0.5, 2000, 0);
                STDOUT.print("Current Volume: ");
                STDOUT.println(dynamic_mixer.get_volume());
            }
            else{
                trySound(&SFX_vmmin, 0.5, 1000, 0);
            }
        }
    }
    
    bool Event2(enum BUTTON button, EVENT event, uint32_t modifiers) override {
        
        switch (EVENTID(button, event, modifiers)) {
            
            //determine whether blade is pointing up or down
            case EVENTID(BUTTON_POWER, EVENT_PRESSED, MODE_ON):
                if (accel_.x < -0.15) {
                    pointing_down_ = true;
                }
                else {
                    pointing_down_ = false;
                }
                return true;
            
            case EVENTID(BUTTON_POWER, EVENT_PRESSED, MODE_OFF):
                SaberBase::RequestMotion();
                return true;
            
            //turn blade off
            case EVENTID(BUTTON_POWER, EVENT_FIRST_HELD_MEDIUM, MODE_ON):
                if (!SaberBase::Lockup()) {
                    Off();
                }
                return true;
            
            //saber On or volume up
            case EVENTID(BUTTON_POWER, EVENT_FIRST_SAVED_CLICK_SHORT, MODE_OFF):
            #ifdef ENABLE_STAB_ON
            case EVENTID(BUTTON_NONE, EVENT_STAB, MODE_OFF);
            #endif
                if (!mode_volume_) {
                  On();
                }
                
                else {
                  ChangeVolume(true);
                }
                return true;
            
            //previous preset
            case EVENTID(BUTTON_POWER, EVENT_FIRST_HELD_LONG, MODE_OFF):
                if (!mode_volume_) {
                    previous_preset();
                }
                return true;
            
            //next preset or volume down
            case EVENTID(BUTTON_POWER, EVENT_FIRST_CLICK_LONG, MODE_OFF):
                if (!mode_volume_) {
                    next_preset();
                }
                
                else {
                    ChangeVolume(false);
                }
                return true;
            
            //volume change mode if pointing down, battery level if pointing up
            case EVENTID(BUTTON_NONE, EVENT_CLASH, MODE_OFF | BUTTON_POWER):
                if (pointing_down_)
                {
                    if (!mode_volume_) {
                        mode_volume_ = true;
                        trySound(&SFX_vmbegin, 0.1, 2000, 2500);
                        STDOUT.println("Enter Volume Menu");
                    }
                    
                    else {
                        mode_volume_ = false;
                        trySound(&SFX_vmend, 0.1, 2500, 2000);
                        STDOUT.println("Exit Volume Menu");
                    }
                }
                
                else {
                    SaberBase::DoEffect(EFFECT_BATTERY_LEVEL, 0);
                }
                return true;
            
            //on button release while on, end lockups if active
            case EVENTID(BUTTON_POWER, EVENT_RELEASED, MODE_ANY_BUTTON | MODE_ON):
                if (SaberBase::Lockup()) {
                    SaberBase::DoEndLockup();
                    SaberBase::SetLockup(SaberBase::LOCKUP_NONE);
                    return true;
                }
            
            //melt
            case EVENTID(BUTTON_NONE, EVENT_STAB, MODE_ON | BUTTON_POWER):
                if (!SaberBase::Lockup()) {
                    SaberBase::SetLockup(SaberBase::LOCKUP_MELT);
                    SaberBase::DoBeginLockup();
                    return true;
                }
                break;
            
            //force effect
            case EVENTID(BUTTON_NONE, EVENT_TWIST, MODE_ON | BUTTON_POWER):
                SaberBase::DoForce();
                return true;
            
            //blaster hit
            case EVENTID(BUTTON_POWER, EVENT_FIRST_SAVED_CLICK_SHORT, MODE_ON):
            case EVENTID(BUTTON_POWER, EVENT_SECOND_CLICK_SHORT, MODE_ON):
            case EVENTID(BUTTON_POWER, EVENT_THIRD_CLICK_SHORT, MODE_ON):
                SaberBase::DoBlast();
                return true;
            
            //lockup
            case EVENTID(BUTTON_NONE, EVENT_CLASH, MODE_ON | BUTTON_POWER):
                if (!SaberBase::Lockup()) {
                    if (pointing_down_) {
                        SaberBase::SetLockup(SaberBase::LOCKUP_DRAG);
                    } else {
                        SaberBase::SetLockup(SaberBase::LOCKUP_NORMAL);
                    }
                    
                    SaberBase::DoBeginLockup();
                    return true;
                }
                break;
        }
        return false;
    }
    
    void SB_Effect(EffectType effect, float location) override {
        switch (effect) {
            case EFFECT_BATTERY_LEVEL:
                trySound(&SFX_battery, 0.5, 3000, 0);
        }
    }
    
    private:
        //bool aux_on_      = true;
        bool mode_volume_   = false;
        bool pointing_down_ = false;
        
};
#endif