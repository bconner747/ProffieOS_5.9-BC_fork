
#ifdef CONFIG_TOP
#include "proffieboard_v2_config.h"
#define NUM_BLADES 2
#define NUM_BUTTONS 1
#define VOLUME 1500
const unsigned int maxLedsPerStrip = 144;
// #define EXTRA_COLOR_BUFFER_SPACE 30               // New define that can speed up processing a bit. Basically, it can calculate the colors for the next blade (or the next frame for the same blade) even though it's not done feeding out the data for the data in the color buffer yet.
#define CLASH_THRESHOLD_G 3.5
#define ENABLE_AUDIO
#define ENABLE_MOTION
#define ENABLE_WS2811
#define ENABLE_SD
#define ENABLE_SERIAL // Bluetooth
// #define ENABLE_SSD1306 //OLED
// #define DISABLE_COLOR_CHANGE
#define SHARED_POWER_PINS
#define SAVE_STATE
    // #define SAVE_VOLUME
    // #define SAVE_PRESET
    // #define SAVE_COLOR_CHANGE
    // #define SAVE_DYNAMIC_DIMMING
// #define KEEP_SAVEFILES_WHEN_PROGRAMMING        // upload overwrites presets.ini/tmp unless this is defined
#define BLADE_DETECT_PIN blade3Pin
// #define ENABLE_POWER_FOR_ID PowerPINS<bladePowerPin2, bladePowerPin3>
// #define BLADE_ID_CLASS ExternalPullupBladeID<bladeIdentifyPin, 33000>
// #define BLADE_ID_CLASS SnapshotBladeID<bladeIdentifyPin> // This will make it use the speed-of-charging-a-capacitor method of blade ID which sometimes works without resistors 
// #define SPEAK_BLADE_ID
// #define ENABLE_I2S_OUT
// #define ENABLE_SPDIF_OUT
// #define LINE_OUT_VOLUME 2000                   // SPDIF out
//#define ENABLE_DEVELOPER_COMMANDS
//#define DISABLE_DIAGNOSTIC_COMMANDS
#define IDLE_OFF_TIME 60 * 5 * 1000
#define MOTION_TIMEOUT 60 * 5 * 1000
// #define ORIENTATION ORIENTATION_FETS_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_USB_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_TOP_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_BOTTOM_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_SDA_TOWARDS_BLADE
// #define ORIENTATION ORIENTATION_SERIAL_TOWARDS_BLADE
// #define ORIENTATION_ROTATION 0,-20,0           // changes the angle required to register twists on curved hilts. example is for Assaj Ventress curved hit install
// #define CONFIG_STARTUP_DELAY 15000             // BC now canon
// #define OLED_FLIP_180                          // BC now canon
// #define USE_AUREBESH_FONT                      // BC now canon
#define FEMALE_TALKIE_VOICE                       // BC now canon
#define VOLUME_MENU_CYCLE                         // BC now canon
#define NO_REPEAT_RANDOM                          // BC now canon

// ------- Gesture stuff -------

// #define BC_SWING_ON                            // Motion time out causing false ignitions on preset switch. This is annoying but possibly resolved with I2C updates.
// #define BC_STAB_ON
#define BC_THRUST_ON
#define BC_TWIST_ON
#define BC_TWIST_OFF
// #define BC_FORCE_PUSH
// #define BC_FORCE_PUSH_LENGTH 5
#define ENABLE_SPINS
// #define GESTURE_AUTO_BATTLE_MODE
#define BC_LOCKUP_DELAY 200

// ------- Custom / Experimental / BC Personal only stuff ---------
#define NO_VOLUME_MENU                            // self evident
#define ENABLE_AUTO_SWING_BLAST                   // BC Multiblast continues as long as swinging within 1 second. 
#define NO_BLADE_NO_GEST_ONOFF                    // If using blade detect, No Blade = No Gesture ignitions or retractions
#define AUTO_HUMSTART                             // 200ms delay from on.wav beginning all the time.             **Requires modified hybrid_font.h file.
#define ENABLE_AUTO_SPINS_BLAST                   // Same as auto-multi-blast but for spins. 2 second window.    **Required modified prop_base.h
// #define LOW_BATT_ONCE                          // No repeated warnings                                        **Required modified prop_base.h
#define USE_WAVS_FOR_TALKIE                       // This will use wav files instead of built in Talkie.
// #define ENABLE_GESTURE_MENU                    // PSISTORM prop - cool stuff! the TrySound else beep void.

#endif

#ifdef CONFIG_PROP
#include "../props/saber_BC_buttons_5.9-BCpersonal.h" // Lately, preferring #define NUM_BUTTONS 1
#endif

#ifdef CONFIG_PRESETS
#include "aliases/BC_effects_1.h"     // For Red, Green, light Blue, ...light colored blades
#include "aliases/BC_effects_2.h"     // For crystals chambers or accents
#include "aliases/BC_effects_Red.h"   // For Red or dark blades
#include "aliases/BC_effects_White.h" // For White blades


Preset BladeIn[] = {

{ "a_BANE/RuleOfTwo;common", "a_BANE/tracks/track3.wav", // Testing IceForce monosfx
// Main Blade    
  StylePtr<Layers<
    AudioFlicker<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<60,0,0>>,500>,RotateColorsX<Variation,Rgb<128,0,0>>>,
    TransitionEffectL<TrConcat<TrFade<7000>,Rgb<0,0,75>,TrDelay<1000>>,EFFECT_USER2>,
    TransitionEffectL<TrConcat<TrWipe<8000>,TransitionEffect<Stripes<10000,-1000,Rgb<50,75,165>,Rgb<25,37,82>,Rgb<50,75,165>,Rgb<13,19,41>>,
      Sparkle<Rgb<25,105,255>,Rgb<250,250,250>,30,200>,
      TrFade<11500>,TrDelay<20000>,EFFECT_USER2>,TrDelay<7000>,
      Sparkle<Rgb<25,105,255>,Rgb<250,250,250>,30,200>,
      TrJoin<TrWipe<7000>,TrSmoothFade<9500>>>,EFFECT_USER2>,
    TransitionEffectL<TrConcat<TrJoin<TrWaveX<BrownNoiseFlicker<Rgb<100,200,255>,DeepSkyBlue,60>,Int<400>,Int<50>,Int<1000>,Int<0>>,TrWaveX<BrownNoiseFlicker<Rgb<100,200,255>,SteelBlue,600>,Int<15000>,Int<400>,Int<8000>,Int<0>>,TrWaveX<Sparkle<AlphaL<Rgb<100,200,255>,Int<0>>,Rgb<100,200,255>,3000,200>,Int<15000>,Int<100>,Int<8000>,Int<-7000>>>,AlphaL<Rgb<100,200,255>,Int<0>>,TrJoin<TrWaveX<BrownNoiseFlicker<Rgb<100,200,255>,DeepSkyBlue,300>,Int<300>,Int<50>,Int<1000>,Int<0>>,TrWaveX<Sparkle<AlphaL<Rgb<100,200,255>,Int<0>>,Rgb<100,200,255>,3000,200>,Int<40000>,Int<300>,Int<7000>,Int<3000>>,TrWaveX<BrownNoiseFlicker<DarkOrange,Yellow,80>,Int<15000>,Int<400>,Int<7000>,Int<0>>>>,EFFECT_USER2>,
    BC_effects_Red, 
    InOutTrL<
      TrConcat<TrInstant,Layers<
      TransitionEffectL<TrConcat<TrInstant,Black,TrDelay<1950>>,EFFECT_IGNITION>,
      AlphaL<AudioFlicker<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<60,0,0>>,500>,RotateColorsX<Variation,Rgb<128,0,0>>>,
        SmoothStep<Scale<Trigger<EFFECT_IGNITION,Scale<Trigger<EFFECT_IGNITION,Int<2000>,Int<1>,Int<1>>,Int<300>,Int<2000>>,Int<1>,Int<1>>,Int<-1200>,Int<35000>>,Int<-3000>>>>,TrDelay<5000>>,
      TrConcat<TrInstant,Layers<
      TransitionEffectL<TrConcat<TrInstant,Black,TrDelay<2000>>,EFFECT_RETRACTION>,
      AlphaL<AudioFlicker<BrownNoiseFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<60,0,0>>,500>,RotateColorsX<Variation,Rgb<128,0,0>>>,
        SmoothStep<Scale<Trigger<EFFECT_RETRACTION,Scale<Trigger<EFFECT_RETRACTION,Int<1000>,Int<1000>,Int<1>>,Int<3000>,Int<10>>,Int<1000>,Int<500>>,Int<35000>,Int<-1200>>,Int<-3000>>>>,TrDelay<1000>>>,
     TransitionEffectL<TrConcat<TrWipe<100>,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<60,0,0>>,90>,SmoothStep<Int<2000>,Int<-500>>>,
     TrDelayX< Percentage<WavLen<EFFECT_PREON>,49> >,AlphaL<HumpFlickerL<RotateColorsX<Variation,Rgb<60,0,0>>,90>,SmoothStep<Int<2000>,Int<-500>>>,
     TrFadeX<  Percentage<WavLen<EFFECT_PREON>,49> >,AlphaL<HumpFlickerL<RotateColorsX<Variation,BrownNoiseFlicker<Yellow,OrangeRed,50>>,90>,SmoothStep<Int<2700>,Int<-500>>>,TrInstant>,EFFECT_PREON>,
    // On-Demand Battery Level
    AlphaL<TransitionEffectL<TrConcat<TrSmoothFade<500>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<Scale<BatteryLevel,Int<0>,Int<35000>>,Int<-1>>>,TrDelay<1000>,AlphaL<Mix<BatteryLevel,Red,Green>,SmoothStep<BatteryLevel,Int<-1>>>,TrSmoothFade<1000>>,EFFECT_BATTERY_LEVEL>,Ifon<Int<0>,Int<32768>>>
  >>(),
// Accents or Crystal chamber
  StylePtr<Layers<
    // Sith Crystal Red
    Stripes<1000,-2000,RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<90,0,0>>,Black>,
    // Sith Force Red
    TransitionEffectL<TrConcat<TrFade<600>,RandomFlicker<RotateColorsX<Variation,Red>,RotateColorsX<Variation,Rgb<160,0,0>>>,TrDelay<3000>,RotateColorsX<Variation,Red>,TrFade<800>>,EFFECT_FORCE>,
    BC_effects_2,
    InOutTrL<TrConcat<TrInstant,White,TrSmoothFade<1000>>,TrConcat<TrSmoothFade<500>,White,TrSmoothFade<500>>,Mix<IsLessThan<SlowNoise<Int<3000>>,Int<6000>>,Pulsing<ColorCycle<RotateColorsX<Variation,Red>,25,20,Black,100,300,1000>,Black,2000>,Black>>
  >>(),
"rule of\ntwo"}

};
//----------------------------------------------------------------------------------------------------------------------------------------------------------------

Preset noblade[] = {

 { "Calibr8;common", "tracks/TalesOfAJediKnight.wav",                            
// Main Blade
    StylePtr<Black>(),
// Accents or Crystal chamber 
  StylePtr<Layers<
  RandomFlicker<Green,Rgb<0,128,0>>,
  BlastFadeoutL<Blue>,  
  LockupL<AudioFlicker<Yellow,Blue>,Blinking<Green,Black,85,500>,Int<32768>,Int<32768>,Int<32768>>,
  SimpleClashL<Yellow,100,EFFECT_CLASH,SmoothStep<Int<0>,Int<24000>>>,
  LockupTrL<Pulsing<Red,Yellow,1000>,TrInstant,TrInstant,SaberBase::LOCKUP_MELT>,  
  InOutTrL<TrWipeSparkTip<Yellow,500,75>,TrInstant,Pulsing<ColorCycle<Green,25,50,Green,75,400,3000>,Black,2000>>>>(),
"calibr8"}

};

BladeConfig blades[] = {
  { 0, WS281XBladePtr<132, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),          // Main Blade
    WS281XBladePtr<2, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin5> >(),                              // Accents or Crystal chamber
    CONFIGARRAY(BladeIn),
    "00_bladein_save"}, // Folder on SD card contains saved state for when blade in.

  { NO_BLADE, WS281XBladePtr<132, bladePin, Color8::GRB, PowerPINS<bladePowerPin2, bladePowerPin3> >(),  // Main Blade
    WS281XBladePtr<2, blade2Pin, Color8::GRB, PowerPINS<bladePowerPin5> >(),                              // Accents or Crystal chamber
    CONFIGARRAY(noblade),
    "01_NO_BLADE_save"}, // Folder on SD card contains saved state for when no blade.
};

#endif

#ifdef CONFIG_BUTTONS
Button PowerButton(BUTTON_POWER, powerButtonPin, "pow");
Button AuxButton(BUTTON_AUX, auxPin, "aux");
#endif