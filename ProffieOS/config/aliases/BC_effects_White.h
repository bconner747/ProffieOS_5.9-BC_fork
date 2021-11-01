// Main Blade effects package for White blades

using BC_effects_White =
Layers<

// Dim Blade 50% "Power Save" button combo
  EffectSequence<EFFECT_POWERSAVE,
  AlphaL<Black,Int<16384>>,
  AlphaL<Black,Int<0>>>,
// Clash
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<TransitionEffect<BrownNoiseFlicker<Rgb<255,150,0>,Black,50>,Moccasin,TrInstant,TrFade<300>,EFFECT_CLASH>,Bump<Scale<BladeAngle<>,Int<25000>,Int<8000>>,Int<18000>>>,TrFade<600>>,EFFECT_CLASH>,
// Stab - OrangeRed stripes
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<300>,AlphaL<Stripes<5000,1000,Orange,DarkOrange,Rgb<150,60,0>,Rgb<60,30,0>,Rgb<150,14,0>,OrangeRed>,SmoothStep<Int<20000>,Int<20000>>>,TrJoin<TrSmoothFade<900>,TrWipe<700>>>,EFFECT_STAB>,
// Blast - for white blades
    TransitionEffectL<TrConcat<
    // Impact Flash - BC always
    TrInstant,GreenYellow,TrDelay<25>>,EFFECT_BLAST>,
    // Waves
    BlastL<EffectSequence<EFFECT_BLAST,Red,Green,Blue,Black>,850,250,351>,
    // Impact point afterimage
    AlphaL<TransitionEffectL<TrConcat<TrFade<300>,Red,TrFade<300>>,EFFECT_BLAST>,BlastF<700,250,100000>>,
    // Impact point
    BlastL<Black,300,350,100000>,
// Lockup - BC custom range mid-blade
    TransitionEffectL<TrConcat<TrInstant,Strobe<GreenYellow,Black,20,30>,TrFade<200>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<300>>>,EFFECT_LOCKUP_END>,
    LockupTrL<Layers<
      //Random Strobe Flash no dimming
      AlphaL<TransitionLoopL<TrConcat<TrDelayX<Scale<SlowNoise<Int<3000>>,Int<30>,Int<800>>>,Mix<SlowNoise<Int<1000>>,Black,Black,White,Black>,TrDelayX<Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>>,Int<32768>>,
      //AlphaL<White,StrobeF<Scale<SlowNoise<Int<1000>>,Int<1>,Int<3>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>,
      // Bottom Layer Bump - random width
      AlphaL<Blinking<Tomato,Strobe<Yellow,Black,15,30>,60,500>,                                                Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<8000>,Int<18000>>>>,
      // Top Layer Bump - fixed width
      AlphaL<BrownNoiseFlicker<Yellow,Black,50>,                                                                Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<10000>>>>,
      // Begin Lockup Transition
      TrConcat<TrInstant,AlphaL<Blinking<White,Strobe<BrownNoiseFlicker<Yellow,Black,500>,Black,15,30>,60,500>, Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Scale<SlowNoise<Int<3000>>,Int<25000>,Int<32000>>>>,TrFade<500>>,
      // End Lockup Transition
      TrSmoothFade<900>,SaberBase::LOCKUP_NORMAL>,
      TransitionEffectL<TrConcat<TrInstant,AlphaL<Strobe<GreenYellow,Black,20,30>,                             Bump<Scale<BladeAngle<5000,28000>,Scale<BladeAngle<8000,16000>,Int<3000>,Int<44000>>,Int<3000>>,Int<15000>>>,TrFade<600>>,EFFECT_LOCKUP_BEGIN>,
    TransitionEffectL<TrConcat<TrInstant,HumpFlickerL<Strobe<AlphaL<White,Int<20000>>,Black,20,30>,30>,TrSmoothFade<250>>,EFFECT_LOCKUP_BEGIN>,
    TransitionEffectL<TrConcat<TrInstant,GreenYellow,TrDelay<25>>,EFFECT_LOCKUP_BEGIN>,
    // Non-Responsive Drag
    LockupTrL<AlphaL<AudioFlicker<BrownNoiseFlicker<Strobe<Black,OrangeRed,20,25>,Yellow,200>,White>,SmoothStep<Int<30000>,Int<2000>>>,TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrFade<150>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_DRAG>,
// Lightning Block Non-Responsive    
    LockupTrL<Layers<
        //Random Strobe Flash and 16000 = 50% base blade dimming to make lb pop
        AlphaL<Black,Int<16000>>,
        AlphaL<White,StrobeF<Scale<SlowNoise<Int<1000>>,Int<1>,Int<6>>,Scale<SlowNoise<Int<1000>>,Int<10>,Int<50>>>>,
        AlphaL<RandomFlicker<Strobe<White,Rgb<83,0,255>,50,10>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>>,LayerFunctions<
        Bump<Scale<SlowNoise<Int<2000>>,Int<3000>,Int<16000>>,Scale<BrownNoiseF<Int<10>>,Int<14000>,Int<8000>>>,
        Bump<Scale<SlowNoise<Int<2300>>,Int<26000>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<10000>>>,
        Bump<Scale<SlowNoise<Int<2300>>,Int<20000>,Int<30000>>,Scale<IsLessThan<SlowNoise<Int<1500>>,Int<8000>>,Scale<NoisySoundLevel,Int<5000>,Int<0>>,Int<0>>>>>>,
        // Begin Lightning Transition
        TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>,TrFade<100>>,
        // End Lightning Transition    
        TrConcat<TrInstant,GreenYellow,TrDelay<25>,BrownNoiseFlicker<Rgb<83,0,255>,Black,500>,TrFade<150>,BrownNoiseFlickerL<AlphaL<White,Int<16000>>,Int<50>>,TrJoinR<TrWipe<200>,TrWipeIn<200>,TrFade<400>> >,SaberBase::LOCKUP_LIGHTNING_BLOCK>,
// Melt    
    LockupTrL<
    AlphaL<Mix<TwistAngle<>,Yellow,RandomPerLEDFlicker<Orange,OrangeRed>,BrownNoiseFlicker<Rgb16<20095,128,128>,Rgb16<35103,8175,298>,150>,StyleFire<Rgb16<20393,93,93>,Red,0,4,FireConfig<0,2000,5>,FireConfig<3000,0,0>,FireConfig<0,4000,0>>>,
    // Melt Shape
    SmoothStep<Scale<TwistAngle<>,Int<24000>,Int<29000>>,Int<2000>>>,
    //Melt Begin and End transitions
    TrConcat<TrInstant,GreenYellow,TrDelay<25>,AlphaL<Black,Int<0>>,TrWipeIn<600>>,TrColorCycle<1500,-2000,100>,SaberBase::LOCKUP_MELT>

>;