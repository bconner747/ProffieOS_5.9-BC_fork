// Accent / Pommel / PCB effects

using BC_effects_2 =
Layers<
  // BC custom simplified effects for accents and PCBs.
  TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_CLASH>,
  TransitionEffectL<TrConcat<TrInstant,Blinking<White,Orange,20,500>,TrFade<400>>,EFFECT_BLAST>,
  LockupTrL<Blinking<White,Strobe<Black,Red,15,30>,60,500>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,TrConcat<TrInstant,Blinking<White,Strobe<BrownNoiseFlicker<White,Black,500>,Black,15,30>,60,500>,TrFade<500>>,SaberBase::LOCKUP_NORMAL>,
  LockupTrL<RandomFlicker<Strobe<White,Rgb<60,0,255>,50,10>,BrownNoiseFlicker<Rgb<60,0,255>,Black,500>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlickerL<White,Int<50>>,TrFade<500>>,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
  LockupTrL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,TrConcat<TrInstant,White,TrFade<400>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
  LockupTrL<Pulsing<BrownNoiseFlicker<Red,Black,300>,Yellow,2000>,TrFade<300>,TrFade<300>,SaberBase::LOCKUP_MELT>
     >;
