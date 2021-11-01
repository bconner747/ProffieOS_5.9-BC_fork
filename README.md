# ProffieOS_5.9-BC_fork
For use with custom "non-canon" saber_BC_buttons prop file. Includes upgrades from 5.9 towards OS6.  
 ProffieOS 5.9-BC fork - Control software for lightsabers and other props.
 http://fredrik.hubbe.net/lightsaber/teensy_saber.html
 Copyright (c) 2016-2019 Fredrik Hubinette
 Additional copyright holders listed inline below.

 This program is free software: you can redistribute it and/or modify
 it under the terms of the GNU General Public License as published by
 the Free Software Foundation, either version 3 of the License, or
 (at your option) any later version.

 This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

 You should have received a copy of the GNU General Public License
 along with this program.  If not, see <http://www.gnu.org/licenses/>.

5.9 Plus by BC. Nov 2021
Includes:
WavLen
OLED supports idle.bmp loop instead of constant battery meter
OLED supports Aurebesh text font
Matching preon/out  pstoff/in
Hum always start after 200ms of ignition.
Auto Spins blaster blocks.
Low battery warning only once
Wavs for talkie
i2c bus sleep less
Save some memory
Added TrColorCycleX with replaced transitions colorcycle.h 
Latest manuals in /doc folder
Updated motion file to support LGT Proffieboards

Included is a template config file named containing most defines (commented out if not used),
a sample preset.
Also there's an OLED folder inside /display containing a bunch of display files and goodies.

Also included are my signature effects packs via aliases.
-Replace all the layers in a style for clash, stab, blast, lockup, drag, lightning block, and melt, 
with ONE layer using one of the aliases listed in the sample config template ‘BC_sample_config.h’ 
ie:
BC_effects_1,
would replace all those layers in a style for you with custom animations by me. 
Variations for different base color blades included ;) See sample preset for an example of this.

I suggest using the Font Search Paths feature by setting up a 'common' font folder,
and putting the Volume Menu wavs and Spoken Battery Level wavs in there.
You'll need this for the future if you want to use Edit Mode anyway.
More info here:
https://github.com/profezzorn/ProffieOS/wiki/Sound-Font-Configuration#font-search-paths

The Volume Menu and Spoken stuff can also be the downloadable versions from the OS6.x alpha release.
I made 7 different languages, most with varieties of voices. 
They are basically "robotic, droid-ish" sort of sounding, but there's a mix of female and male. 
The point is, the spoken stuff (if #define USE_WAVS_FOR_TALKIE is enabled) will all match if you have a consistent voice.

Voicepack packages:
http://fredrik.hubbe.net/lightsaber/sound/

*Disclaimer Note* 
The spoken battery level in the 5.9 version uses delay(), 
which is not the “best” way to accomplish things, 
and Fredrik wouldn’t approve it for the official version,
but it does let things work well enough for me since nothing much is going on
while the blade is off, and performance wise, only accent and crystal chamber
LEDs will pause for a moment while it speaks.  ¯\_(ツ)_/¯


This is almost OS 6, just not:
Edit mode
Official method of linking effects (preon/out  pstoff/in matching)  etc…
WavNum nor ColorSelect, so no matching preon01 to a specific preon blade animation for example)
a bunch of other things. JUST UPDATE TO OS 6!!
