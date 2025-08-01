////////////////////////////////////////////////////////////////////////
// OpenTibia - an opensource roleplaying game
////////////////////////////////////////////////////////////////////////
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 3 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.
////////////////////////////////////////////////////////////////////////

#ifndef __CONST__
#define __CONST__
#include "definitions.h"

enum MagicEffect_t
{
    MAGIC_EFFECT_DRAW_BLOOD = 0x00,
    MAGIC_EFFECT_LOSE_ENERGY = 0x01,
    MAGIC_EFFECT_POFF = 0x02,
    MAGIC_EFFECT_BLOCKHIT = 0x03,
    MAGIC_EFFECT_EXPLOSION_AREA = 0x04,
    MAGIC_EFFECT_EXPLOSION_DAMAGE = 0x05,
    MAGIC_EFFECT_FIRE_AREA = 0x06,
    MAGIC_EFFECT_YELLOW_RINGS = 0x07,
    MAGIC_EFFECT_POISON_RINGS = 0x08,
    MAGIC_EFFECT_HIT_AREA = 0x09,
    MAGIC_EFFECT_TELEPORT = 0x0A, //10
    MAGIC_EFFECT_ENERGY_DAMAGE = 0x0B, //11
    MAGIC_EFFECT_WRAPS_BLUE = 0x0C, //12
    MAGIC_EFFECT_WRAPS_RED = 0x0D, //13
    MAGIC_EFFECT_WRAPS_GREEN = 0x0E, //14
    MAGIC_EFFECT_HITBY_FIRE = 0x0F, //15
    MAGIC_EFFECT_POISON = 0x10, //16
    MAGIC_EFFECT_MORT_AREA = 0x11, //17
    MAGIC_EFFECT_SOUND_GREEN = 0x12, //18
    MAGIC_EFFECT_SOUND_RED = 0x13, //19
    MAGIC_EFFECT_POISON_AREA = 0x14, //20
    MAGIC_EFFECT_SOUND_YELLOW = 0x15, //21
    MAGIC_EFFECT_SOUND_PURPLE = 0x16, //22
    MAGIC_EFFECT_SOUND_BLUE = 0x17, //23
    MAGIC_EFFECT_SOUND_WHITE = 0x18, //24
    MAGIC_EFFECT_BUBBLES = 0x19, //25
    MAGIC_EFFECT_CRAPS = 0x1A, //26
    MAGIC_EFFECT_GIFT_WRAPS = 0x1B, //27
    MAGIC_EFFECT_FIREWORK_YELLOW = 0x1C, //28
    MAGIC_EFFECT_FIREWORK_RED = 0x1D, //29
    MAGIC_EFFECT_FIREWORK_BLUE = 0x1E, //30
    MAGIC_EFFECT_STUN = 0x1F, //31
    MAGIC_EFFECT_SLEEP = 0x20, //32
    MAGIC_EFFECT_WATERCREATURE = 0x21, //33
    MAGIC_EFFECT_GROUNDSHAKER = 0x22, //34
    MAGIC_EFFECT_HEARTS = 0x23, //35
    MAGIC_EFFECT_FIREATTACK = 0x24, //36
    MAGIC_EFFECT_ENERGY_AREA = 0x25, //37
    MAGIC_EFFECT_SMALLCLOUDS = 0x26, //38
    MAGIC_EFFECT_HOLYDAMAGE = 0x27, //39
    MAGIC_EFFECT_BIGCLOUDS = 0x28, //40
    MAGIC_EFFECT_ICEAREA = 0x29, //41
    MAGIC_EFFECT_ICETORNADO = 0x2A, //42
    MAGIC_EFFECT_ICEATTACK = 0x2B, //43
    MAGIC_EFFECT_STONES = 0x2C, //44
    MAGIC_EFFECT_SMALLPLANTS = 0x2D, //45
    MAGIC_EFFECT_CARNIPHILA = 0x2E, //46
    MAGIC_EFFECT_PURPLEENERGY = 0x2F, //47
    MAGIC_EFFECT_YELLOWENERGY = 0x30, //48
    MAGIC_EFFECT_HOLYAREA = 0x31, //49
    MAGIC_EFFECT_BIGPLANTS = 0x32, //50
    MAGIC_EFFECT_CAKE = 0x33, //51
    MAGIC_EFFECT_GIANTICE = 0x34, //52
    MAGIC_EFFECT_WATERSPLASH = 0x35, //53
    MAGIC_EFFECT_PLANTATTACK = 0x36, //54
    MAGIC_EFFECT_TUTORIALARROW = 0x37, //55
    MAGIC_EFFECT_TUTORIALSQUARE = 0x38, //56
    MAGIC_EFFECT_MIRRORHORIZONTAL = 0x39, //57
    MAGIC_EFFECT_MIRRORVERTICAL = 0x3A, //58
    MAGIC_EFFECT_SKULLHORIZONTAL = 0x3B, //59
    MAGIC_EFFECT_SKULLVERTICAL = 0x3C, //60
    MAGIC_EFFECT_ASSASSIN = 0x3D, //61
    MAGIC_EFFECT_STEPSHORIZONTAL = 0x3E, //62
    MAGIC_EFFECT_BLOODYSTEPS = 0x3F, //63
    MAGIC_EFFECT_STEPSVERTICAL = 0x40, //64
    MAGIC_EFFECT_YALAHARIGHOST = 0x41, //65
    MAGIC_EFFECT_BATS = 0x42, //66
    MAGIC_EFFECT_SMOKE = 0x43, //67
    MAGIC_EFFECT_INSECTS = 0x44, //68
    MAGIC_EFFECT_DRAGONHEAD = 0x45, //69

    MAGIC_EFFECT_NOVO1 = 0x46, //70
    MAGIC_EFFECT_NOVO2 = 0x47, //71
    MAGIC_EFFECT_NOVO3 = 0x48, //72
    MAGIC_EFFECT_NOVO4 = 0x49, //73
    MAGIC_EFFECT_NOVO5 = 0x50, //74
    MAGIC_EFFECT_NOVO6 = 0x51, //75
    MAGIC_EFFECT_NOVO7 = 0x52, //76
    MAGIC_EFFECT_NOVO8 = 0x53, //77
    MAGIC_EFFECT_NOVO9 = 0x54, //78
    MAGIC_EFFECT_NOVO10 = 0x55, //79

    MAGIC_EFFECT_NOVO11 = 0x56, //80
    MAGIC_EFFECT_NOVO12 = 0x57, //81
    MAGIC_EFFECT_NOVO13 = 0x58, //82
    MAGIC_EFFECT_NOVO14 = 0x59, //83
    MAGIC_EFFECT_NOVO15 = 0x60, //84
    MAGIC_EFFECT_NOVO16 = 0x61, //85
    MAGIC_EFFECT_NOVO17 = 0x62, //86
    MAGIC_EFFECT_NOVO18 = 0x63, //87
    MAGIC_EFFECT_NOVO19 = 0x64, //88
    MAGIC_EFFECT_NOVO20 = 0x65, //89

    MAGIC_EFFECT_NOVO21 = 0x66, //90
    MAGIC_EFFECT_NOVO22 = 0x67, //91
    MAGIC_EFFECT_NOVO23 = 0x68, //92
    MAGIC_EFFECT_NOVO24 = 0x69, //93
    MAGIC_EFFECT_NOVO25 = 0x70, //94
    MAGIC_EFFECT_NOVO26 = 0x71, //95
    MAGIC_EFFECT_NOVO27 = 0x72, //96
    MAGIC_EFFECT_NOVO28 = 0x73, //97
    MAGIC_EFFECT_NOVO29 = 0x74, //98
    MAGIC_EFFECT_NOVO30 = 0x75, //99

    MAGIC_EFFECT_NOVO31 = 0x76, //100
    MAGIC_EFFECT_NOVO32 = 0x77, //101
    MAGIC_EFFECT_NOVO33 = 0x78, //102
    MAGIC_EFFECT_NOVO34 = 0x79, //103
    MAGIC_EFFECT_NOVO35 = 0x80, //104
    MAGIC_EFFECT_NOVO36 = 0x81, //105
    MAGIC_EFFECT_NOVO37 = 0x82, //106
    MAGIC_EFFECT_NOVO38 = 0x83, //107
    MAGIC_EFFECT_NOVO39 = 0x84, //108
    MAGIC_EFFECT_NOVO40 = 0x85, //109

    MAGIC_EFFECT_NOVO41 = 0x86, //110
    MAGIC_EFFECT_NOVO42 = 0x87, //111
    MAGIC_EFFECT_NOVO43 = 0x88, //112
    MAGIC_EFFECT_NOVO44 = 0x89, //113
    MAGIC_EFFECT_NOVO45 = 0x90, //114
    MAGIC_EFFECT_NOVO46 = 0x91, //115
    MAGIC_EFFECT_NOVO47 = 0x92, //116
    MAGIC_EFFECT_NOVO48 = 0x93, //117
    MAGIC_EFFECT_NOVO49 = 0x94, //118
    MAGIC_EFFECT_NOVO50 = 0x95, //119

    MAGIC_EFFECT_NOVO51 = 0x96, //120
    MAGIC_EFFECT_NOVO52 = 0x97, //121
    MAGIC_EFFECT_NOVO53 = 0x98, //122
    MAGIC_EFFECT_NOVO54 = 0x99, //123
    MAGIC_EFFECT_NOVO55 = 0x100, //124
    MAGIC_EFFECT_NOVO56 = 0x101, //125
    MAGIC_EFFECT_NOVO57 = 0x102, //126
    MAGIC_EFFECT_NOVO58 = 0x103, //127
    MAGIC_EFFECT_NOVO59 = 0x104, //128
    MAGIC_EFFECT_NOVO60 = 0x105, //129

    MAGIC_EFFECT_NOVO61 = 0x106, //130
    MAGIC_EFFECT_NOVO62 = 0x107, //131
    MAGIC_EFFECT_NOVO63 = 0x108, //132
    MAGIC_EFFECT_NOVO64 = 0x109, //133
    MAGIC_EFFECT_NOVO65 = 0x110, //134
    MAGIC_EFFECT_NOVO66 = 0x111, //135
    MAGIC_EFFECT_NOVO67 = 0x112, //136
    MAGIC_EFFECT_NOVO68 = 0x113, //137
    MAGIC_EFFECT_NOVO69 = 0x114, //138
    MAGIC_EFFECT_NOVO70 = 0x115, //139

    MAGIC_EFFECT_NOVO71 = 0x116, //140
    MAGIC_EFFECT_NOVO72 = 0x117, //141
    MAGIC_EFFECT_NOVO73 = 0x118, //142
    MAGIC_EFFECT_NOVO74 = 0x119, //143
    MAGIC_EFFECT_NOVO75 = 0x120, //144
    MAGIC_EFFECT_NOVO76 = 0x121, //145
    MAGIC_EFFECT_NOVO77 = 0x122, //146
    MAGIC_EFFECT_NOVO78 = 0x123, //147
    MAGIC_EFFECT_NOVO79 = 0x124, //148
    MAGIC_EFFECT_NOVO80 = 0x125, //149

    MAGIC_EFFECT_NOVO81 = 0x126, //150
    MAGIC_EFFECT_NOVO82 = 0x127, //151
    MAGIC_EFFECT_NOVO83 = 0x128, //152
    MAGIC_EFFECT_NOVO84 = 0x129, //153
    MAGIC_EFFECT_NOVO85 = 0x130, //154
    MAGIC_EFFECT_NOVO86 = 0x131, //155
    MAGIC_EFFECT_NOVO87 = 0x132, //156
    MAGIC_EFFECT_NOVO88 = 0x133, //157
    MAGIC_EFFECT_NOVO89 = 0x134, //158
    MAGIC_EFFECT_NOVO90 = 0x135, //159

    MAGIC_EFFECT_NOVO91 = 0x136, //160
    MAGIC_EFFECT_NOVO92 = 0x137, //161
    MAGIC_EFFECT_NOVO93 = 0x138, //162
    MAGIC_EFFECT_NOVO94 = 0x139, //163
    MAGIC_EFFECT_NOVO95 = 0x140, //164
    MAGIC_EFFECT_NOVO96 = 0x141, //165
    MAGIC_EFFECT_NOVO97 = 0x142, //166
    MAGIC_EFFECT_NOVO98 = 0x143, //167
    MAGIC_EFFECT_NOVO99 = 0x144, //168
    MAGIC_EFFECT_NOVO100 = 0x145, //169

    MAGIC_EFFECT_NOVO101 = 0x146, //170
    MAGIC_EFFECT_NOVO102 = 0x147, //171
    MAGIC_EFFECT_NOVO103 = 0x148, //172
    MAGIC_EFFECT_NOVO104 = 0x149, //173
    MAGIC_EFFECT_NOVO105 = 0x150, //174
    MAGIC_EFFECT_NOVO106 = 0x151, //175
    MAGIC_EFFECT_NOVO107 = 0x152, //176
    MAGIC_EFFECT_NOVO108 = 0x153, //177
    MAGIC_EFFECT_NOVO109 = 0x154, //178
    MAGIC_EFFECT_NOVO110 = 0x155, //179

    MAGIC_EFFECT_NOVO111 = 0x156, //180
    MAGIC_EFFECT_NOVO112 = 0x157, //181
    MAGIC_EFFECT_NOVO113 = 0x158, //182
    MAGIC_EFFECT_NOVO114 = 0x159, //183
    MAGIC_EFFECT_NOVO115 = 0x160, //184
    MAGIC_EFFECT_NOVO116 = 0x161, //185
    MAGIC_EFFECT_NOVO117 = 0x162, //186
    MAGIC_EFFECT_NOVO118 = 0x163, //187
    MAGIC_EFFECT_NOVO119 = 0x164, //188
    MAGIC_EFFECT_NOVO120 = 0x165, //189

    MAGIC_EFFECT_NOVO121 = 0x166, //190
    MAGIC_EFFECT_NOVO122 = 0x167, //191
    MAGIC_EFFECT_NOVO123 = 0x168, //192
    MAGIC_EFFECT_NOVO124 = 0x169, //193
    MAGIC_EFFECT_NOVO125 = 0x170, //194
    MAGIC_EFFECT_NOVO126 = 0x171, //195
    MAGIC_EFFECT_NOVO127 = 0x172, //196
    MAGIC_EFFECT_NOVO128 = 0x173, //197
    MAGIC_EFFECT_NOVO129 = 0x174, //198
    MAGIC_EFFECT_NOVO130 = 0x175, //199

    MAGIC_EFFECT_NOVO131 = 0x176, //200
    MAGIC_EFFECT_NOVO132 = 0x177, //201
    MAGIC_EFFECT_NOVO133 = 0x178, //202
    MAGIC_EFFECT_NOVO134 = 0x179, //203
    MAGIC_EFFECT_NOVO135 = 0x180, //204
    MAGIC_EFFECT_NOVO136 = 0x181, //205
    MAGIC_EFFECT_NOVO137 = 0x182, //206
    MAGIC_EFFECT_NOVO138 = 0x183, //207
    MAGIC_EFFECT_NOVO139 = 0x184, //208
    MAGIC_EFFECT_NOVO140 = 0x185, //209

    MAGIC_EFFECT_NOVO141 = 0x186, //210
    MAGIC_EFFECT_NOVO142 = 0x187, //211
    MAGIC_EFFECT_NOVO143 = 0x188, //212
    MAGIC_EFFECT_NOVO144 = 0x189, //213
    MAGIC_EFFECT_NOVO145 = 0x190, //214
    MAGIC_EFFECT_NOVO146 = 0x191, //215
    MAGIC_EFFECT_NOVO147 = 0x192, //216
    MAGIC_EFFECT_NOVO148 = 0x193, //217
    MAGIC_EFFECT_NOVO149 = 0x194, //218
    MAGIC_EFFECT_NOVO150 = 0x195, //219

    MAGIC_EFFECT_NOVO151 = 0x196, //220
    MAGIC_EFFECT_NOVO152 = 0x197, //221
    MAGIC_EFFECT_NOVO153 = 0x198, //222
    MAGIC_EFFECT_NOVO154 = 0x199, //223
    MAGIC_EFFECT_NOVO155 = 0x200, //224
    MAGIC_EFFECT_NOVO156 = 0x201, //225
    MAGIC_EFFECT_NOVO157 = 0x202, //226
    MAGIC_EFFECT_NOVO158 = 0x203, //227
    MAGIC_EFFECT_NOVO159 = 0x204, //228
    MAGIC_EFFECT_NOVO160 = 0x205, //229

    MAGIC_EFFECT_NOVO161 = 0x206, //230
    MAGIC_EFFECT_NOVO162 = 0x207, //231
    MAGIC_EFFECT_NOVO163 = 0x208, //232
    MAGIC_EFFECT_NOVO164 = 0x209, //233
    MAGIC_EFFECT_NOVO165 = 0x210, //234
    MAGIC_EFFECT_NOVO166 = 0x211, //235
    MAGIC_EFFECT_NOVO167 = 0x212, //236
    MAGIC_EFFECT_NOVO168 = 0x213, //237
    MAGIC_EFFECT_NOVO169 = 0x214, //238
    MAGIC_EFFECT_NOVO170 = 0x215, //239

    MAGIC_EFFECT_NOVO171 = 0x216, //240
    MAGIC_EFFECT_NOVO172 = 0x217, //241
    MAGIC_EFFECT_NOVO173 = 0x218, //242
    MAGIC_EFFECT_NOVO174 = 0x219, //243
    MAGIC_EFFECT_NOVO175 = 0x220, //244
    MAGIC_EFFECT_NOVO176 = 0x221, //245
    MAGIC_EFFECT_NOVO177 = 0x222, //246
    MAGIC_EFFECT_NOVO178 = 0x223, //247
    MAGIC_EFFECT_NOVO179 = 0x224, //248
    MAGIC_EFFECT_NOVO180 = 0x225, //249

    MAGIC_EFFECT_NOVO181 = 0x226, //250
    MAGIC_EFFECT_NOVO182 = 0x227, //251
    MAGIC_EFFECT_NOVO183 = 0x228, //252
    MAGIC_EFFECT_NOVO184 = 0x229, //253
    MAGIC_EFFECT_NOVO185 = 0x230, //254

    MAGIC_EFFECT_NOVO186 = 0x231, //255
    MAGIC_EFFECT_NOVO187 = 0x232, //256
    MAGIC_EFFECT_NOVO188 = 0x233, //257
    MAGIC_EFFECT_NOVO189 = 0x234, //258
    MAGIC_EFFECT_NOVO190 = 0x235, //259
    MAGIC_EFFECT_NOVO191 = 0x236, //260
    MAGIC_EFFECT_NOVO192 = 0x237, //261
    MAGIC_EFFECT_NOVO193 = 0x238, //262
    MAGIC_EFFECT_NOVO194 = 0x239, //263
    MAGIC_EFFECT_NOVO195 = 0x240, //264
    MAGIC_EFFECT_NOVO196 = 0x241, //265
    MAGIC_EFFECT_NOVO197 = 0x242, //266
    MAGIC_EFFECT_NOVO198 = 0x243, //267
    MAGIC_EFFECT_NOVO199 = 0x244, //268
    MAGIC_EFFECT_NOVO200 = 0x245, //269
    MAGIC_EFFECT_NOVO201 = 0x246, //270
    MAGIC_EFFECT_NOVO202 = 0x247, //271
    MAGIC_EFFECT_NOVO203 = 0x248, //272

    MAGIC_EFFECT_LAST = MAGIC_EFFECT_NOVO203, //272

    //for internal use, dont send to client
    MAGIC_EFFECT_NONE = 0xFF,
    MAGIC_EFFECT_UNKNOWN = 0xFFFF
};

enum ShootEffect_t
{
    SHOOT_EFFECT_SPEAR = 0x00,
    SHOOT_EFFECT_BOLT = 0x01,
    SHOOT_EFFECT_ARROW = 0x02,
    SHOOT_EFFECT_FIRE = 0x03,
    SHOOT_EFFECT_ENERGY = 0x04,
    SHOOT_EFFECT_POISONARROW = 0x05,
    SHOOT_EFFECT_BURSTARROW = 0x06,
    SHOOT_EFFECT_THROWINGSTAR = 0x07,
    SHOOT_EFFECT_THROWINGKNIFE = 0x08,
    SHOOT_EFFECT_SMALLSTONE = 0x09,
    SHOOT_EFFECT_DEATH = 0x0A, //10
    SHOOT_EFFECT_LARGEROCK = 0x0B, //11
    SHOOT_EFFECT_SNOWBALL = 0x0C, //12
    SHOOT_EFFECT_POWERBOLT = 0x0D, //13
    SHOOT_EFFECT_POISONFIELD = 0x0E, //14
    SHOOT_EFFECT_INFERNALBOLT = 0x0F, //15
    SHOOT_EFFECT_HUNTINGSPEAR = 0x10, //16
    SHOOT_EFFECT_ENCHANTEDSPEAR = 0x11, //17
    SHOOT_EFFECT_REDSTAR = 0x12, //18
    SHOOT_EFFECT_GREENSTAR = 0x13, //19
    SHOOT_EFFECT_ROYALSPEAR = 0x14, //20
    SHOOT_EFFECT_SNIPERARROW = 0x15, //21
    SHOOT_EFFECT_ONYXARROW = 0x16, //22
    SHOOT_EFFECT_PIERCINGBOLT = 0x17, //23
    SHOOT_EFFECT_WHIRLWINDSWORD = 0x18, //24
    SHOOT_EFFECT_WHIRLWINDAXE = 0x19, //25
    SHOOT_EFFECT_WHIRLWINDCLUB = 0x1A, //26
    SHOOT_EFFECT_ETHEREALSPEAR = 0x1B, //27
    SHOOT_EFFECT_ICE = 0x1C, //28
    SHOOT_EFFECT_EARTH = 0x1D, //29
    SHOOT_EFFECT_HOLY = 0x1E, //30
    SHOOT_EFFECT_SUDDENDEATH = 0x1F, //31
    SHOOT_EFFECT_FLASHARROW = 0x20, //32
    SHOOT_EFFECT_FLAMMINGARROW = 0x21, //33
    SHOOT_EFFECT_SHIVERARROW = 0x22, //34
    SHOOT_EFFECT_ENERGYBALL = 0x23, //35
    SHOOT_EFFECT_SMALLICE = 0x24, //36
    SHOOT_EFFECT_SMALLHOLY = 0x25, //37
    SHOOT_EFFECT_SMALLEARTH = 0x26, //38
    SHOOT_EFFECT_EARTHARROW = 0x27, //39
    SHOOT_EFFECT_EXPLOSION = 0x28, //40
    SHOOT_EFFECT_CAKE = 0x29, //41

    SHOOT_EFFECT_NOVO1 = 0x30, //42
    SHOOT_EFFECT_NOVO2 = 0x31, //43
    SHOOT_EFFECT_NOVO3 = 0x32, //44
    SHOOT_EFFECT_NOVO4 = 0x33, //45
    SHOOT_EFFECT_NOVO5 = 0x34, //46
    SHOOT_EFFECT_NOVO6 = 0x35, //47
    SHOOT_EFFECT_NOVO7 = 0x36, //48
    SHOOT_EFFECT_NOVO8 = 0x37, //49
    SHOOT_EFFECT_NOVO9 = 0x38, //50
    SHOOT_EFFECT_NOVO10 = 0x39, //51
    SHOOT_EFFECT_NOVO11 = 0x40, //52
    SHOOT_EFFECT_NOVO12 = 0x41, //53
    SHOOT_EFFECT_NOVO13 = 0x42, //54
    SHOOT_EFFECT_NOVO14 = 0x43, //55
    SHOOT_EFFECT_NOVO15 = 0x44, //56
    SHOOT_EFFECT_NOVO16 = 0x44, //57
    SHOOT_EFFECT_NOVO17 = 0x45, //58
    SHOOT_EFFECT_NOVO18 = 0x46, //59
    SHOOT_EFFECT_NOVO19 = 0x47, //60
    SHOOT_EFFECT_NOVO20 = 0x48, //61
    SHOOT_EFFECT_NOVO21 = 0x49, //62
    SHOOT_EFFECT_NOVO22 = 0x50, //63
    SHOOT_EFFECT_NOVO23 = 0x51, //64
    SHOOT_EFFECT_NOVO24 = 0x52, //65
    SHOOT_EFFECT_NOVO25 = 0x53, //66
    SHOOT_EFFECT_NOVO26 = 0x54, //67
    SHOOT_EFFECT_NOVO27 = 0x55, //68
    SHOOT_EFFECT_NOVO28 = 0x56, //69
    SHOOT_EFFECT_NOVO29 = 0x57, //70
    SHOOT_EFFECT_NOVO30 = 0x58, //71
    SHOOT_EFFECT_NOVO31 = 0x46, //72
    SHOOT_EFFECT_NOVO32 = 0x47, //73
    SHOOT_EFFECT_NOVO33 = 0x48, //74
    SHOOT_EFFECT_NOVO34 = 0x49, //75
    SHOOT_EFFECT_NOVO35 = 0x50, //76
    SHOOT_EFFECT_NOVO36 = 0x51, //77
    SHOOT_EFFECT_NOVO37 = 0x52, //78
    SHOOT_EFFECT_NOVO38 = 0x53, //79
    SHOOT_EFFECT_NOVO39 = 0x54, //80
    SHOOT_EFFECT_NOVO40 = 0x55, //81

    SHOOT_EFFECT_LAST = SHOOT_EFFECT_NOVO40,

    //for internal use, dont send to client
    SHOOT_EFFECT_WEAPONTYPE = 0xFE, //254
    SHOOT_EFFECT_NONE = 0xFF,
    SHOOT_EFFECT_UNKNOWN = 0xFFFF
};

enum SpeakClasses
{
    SPEAK_CLASS_NONE = 0x00,
    SPEAK_CLASS_FIRST = 0x01,
    SPEAK_SAY = SPEAK_CLASS_FIRST,
    SPEAK_WHISPER = 0x02,
    SPEAK_YELL = 0x03,
    SPEAK_PRIVATE_PN = 0x04,
    SPEAK_PRIVATE_NP = 0x05,
    SPEAK_PRIVATE = 0x06,
    SPEAK_CHANNEL_Y = 0x07,
    SPEAK_CHANNEL_W = 0x08,
    SPEAK_RVR_CHANNEL = 0x09,
    SPEAK_RVR_ANSWER = 0x0A,
    SPEAK_RVR_CONTINUE = 0x0B,
    SPEAK_BROADCAST = 0x0C,
    SPEAK_CHANNEL_RN = 0x0D, //red - #c text
    SPEAK_PRIVATE_RED = 0x0E, //@name@text
    SPEAK_CHANNEL_O = 0x0F,
    //SPEAK_UNKNOWN_1		= 0x10,
    SPEAK_CHANNEL_RA = 0x11, //red anonymous - #d text
    //SPEAK_UNKNOWN_2		= 0x12,
    SPEAK_MONSTER_SAY = 0x13,
    SPEAK_MONSTER_YELL = 0x14,
    SPEAK_CLASS_LAST = SPEAK_MONSTER_YELL
};

enum MessageClasses
{
    MSG_CLASS_FIRST = 0x12,
    MSG_STATUS_CONSOLE_RED = MSG_CLASS_FIRST, /*Red message in the console*/
    MSG_EVENT_ORANGE = 0x13, /*Orange message in the console*/
    MSG_STATUS_CONSOLE_ORANGE = 0x14, /*Orange message in the console*/
    MSG_STATUS_WARNING = 0x15, /*Red message in game window and in the console*/
    MSG_EVENT_ADVANCE = 0x16, /*White message in game window and in the console*/
    MSG_EVENT_DEFAULT = 0x17, /*White message at the bottom of the game window and in the console*/
    MSG_STATUS_DEFAULT = 0x18, /*White message at the bottom of the game window and in the console*/
    MSG_INFO_DESCR = 0x19, /*Green message in game window and in the console*/
    MSG_STATUS_SMALL = 0x1A, /*White message at the bottom of the game window"*/
    MSG_STATUS_CONSOLE_BLUE = 0x1B, /*Blue message in the console*/
    MSG_CLASS_LAST = MSG_STATUS_CONSOLE_BLUE
};

enum MapMarks_t
{
    MAPMARK_TICK = 0x00,
    MAPMARK_QUESTION = 0x01,
    MAPMARK_EXCLAMATION = 0x02,
    MAPMARK_STAR = 0x03,
    MAPMARK_CROSS = 0x04,
    MAPMARK_TEMPLE = 0x05,
    MAPMARK_KISS = 0x06,
    MAPMARK_SHOVEL = 0x07,
    MAPMARK_SWORD = 0x08,
    MAPMARK_FLAG = 0x09,
    MAPMARK_LOCK = 0x0A,
    MAPMARK_BAG = 0x0B,
    MAPMARK_SKULL = 0x0C,
    MAPMARK_DOLLAR = 0x0D,
    MAPMARK_REDNORTH = 0x0E,
    MAPMARK_REDSOUTH = 0x0F,
    MAPMARK_REDEAST = 0x10,
    MAPMARK_REDWEST = 0x11,
    MAPMARK_GREENNORTH = 0x12,
    MAPMARK_GREENSOUTH = 0x13
};

enum FluidColors_t
{
    FLUID_EMPTY = 0x00,
    FLUID_BLUE = 0x01,
    FLUID_RED = 0x02,
    FLUID_BROWN = 0x03,
    FLUID_GREEN = 0x04,
    FLUID_YELLOW = 0x05,
    FLUID_WHITE = 0x06,
    FLUID_PURPLE = 0x07
};

enum FluidTypes_t
{
    FLUID_NONE = FLUID_EMPTY,
    FLUID_WATER = FLUID_BLUE,
    FLUID_BLOOD = FLUID_RED,
    FLUID_BEER = FLUID_BROWN,
    FLUID_SLIME = FLUID_GREEN,
    FLUID_LEMONADE = FLUID_YELLOW,
    FLUID_MILK = FLUID_WHITE,
    FLUID_MANA = FLUID_PURPLE,

    FLUID_LIFE = FLUID_RED + 8,
    FLUID_OIL = FLUID_BROWN + 8,
    FLUID_URINE = FLUID_YELLOW + 8,
    FLUID_COCONUTMILK = FLUID_WHITE + 8,
    FLUID_WINE = FLUID_PURPLE + 8,

    FLUID_MUD = FLUID_BROWN + 16,
    FLUID_FRUITJUICE = FLUID_YELLOW + 16,

    FLUID_LAVA = FLUID_RED + 24,
    FLUID_RUM = FLUID_BROWN + 24,
    FLUID_SWAMP = FLUID_GREEN + 24,
};

const uint8_t reverseFluidMap[] =
{
    FLUID_EMPTY,
    FLUID_WATER,
    FLUID_MANA,
    FLUID_BEER,
    FLUID_EMPTY,
    FLUID_BLOOD,
    FLUID_SLIME,
    FLUID_EMPTY,
    FLUID_LEMONADE,
    FLUID_MILK
};

enum ClientFluidTypes_t
{
    CLIENTFLUID_EMPTY = 0x00,
    CLIENTFLUID_BLUE = 0x01,
    CLIENTFLUID_PURPLE = 0x02,
    CLIENTFLUID_BROWN_1 = 0x03,
    CLIENTFLUID_BROWN_2 = 0x04,
    CLIENTFLUID_RED = 0x05,
    CLIENTFLUID_GREEN = 0x06,
    CLIENTFLUID_BROWN = 0x07,
    CLIENTFLUID_YELLOW = 0x08,
    CLIENTFLUID_WHITE = 0x09
};

const uint8_t fluidMap[] =
{
    CLIENTFLUID_EMPTY,
    CLIENTFLUID_BLUE,
    CLIENTFLUID_RED,
    CLIENTFLUID_BROWN_1,
    CLIENTFLUID_GREEN,
    CLIENTFLUID_YELLOW,
    CLIENTFLUID_WHITE,
    CLIENTFLUID_PURPLE
};

enum SquareColor_t
{
    SQ_COLOR_NONE = 256,
    SQ_COLOR_BLACK = 0,
};

enum TextColor_t
{
    TEXTCOLOR_BLUE = 5,
    TEXTCOLOR_GREEN = 18,
    TEXTCOLOR_TEAL = 35,
    TEXTCOLOR_LIGHTGREEN = 66,
    TEXTCOLOR_DARKBROWN = 78,
    TEXTCOLOR_LIGHTBLUE = 89,
    TEXTCOLOR_DARKPURPLE = 112,
    TEXTCOLOR_BROWN = 120,
    TEXTCOLOR_GREY = 129,
    TEXTCOLOR_DARKRED = 144,
    TEXTCOLOR_DARKPINK = 152,
    TEXTCOLOR_PURPLE = 154,
    TEXTCOLOR_DARKORANGE = 156,
    TEXTCOLOR_RED = 180,
    TEXTCOLOR_PINK = 190,
    TEXTCOLOR_ORANGE = 192,
    TEXTCOLOR_DARKYELLOW = 205,
    TEXTCOLOR_YELLOW = 210,
    TEXTCOLOR_WHITE = 215,

    TEXTCOLOR_NONE = 255,
    TEXTCOLOR_UNKNOWN = 256
};

enum Icons_t
{
    ICON_NONE = 0,
    ICON_POISON = 1 << 0,
    ICON_BURN = 1 << 1,
    ICON_ENERGY = 1 << 2,
    ICON_DRUNK = 1 << 3,
    ICON_MANASHIELD = 1 << 4,
    ICON_PARALYZE = 1 << 5,
    ICON_HASTE = 1 << 6,
    ICON_SWORDS = 1 << 7,
    ICON_DROWNING = 1 << 8,
    ICON_FREEZING = 1 << 9,
    ICON_DAZZLED = 1 << 10,
    ICON_CURSED = 1 << 11,
    ICON_BUFF = 1 << 12,
    ICON_PZ = 1 << 13,
    ICON_PROTECTIONZONE = 1 << 14
};

enum WeaponType_t
{
    WEAPON_NONE = 0,
    WEAPON_SWORD = 1,
    WEAPON_CLUB = 2,
    WEAPON_AXE = 3,
    WEAPON_SHIELD = 4,
    WEAPON_DIST = 5,
    WEAPON_WAND = 6,
    WEAPON_AMMO = 7,
    WEAPON_FIST = 8
};

enum Ammo_t
{
    AMMO_NONE = 0,
    AMMO_BOLT = 1,
    AMMO_ARROW = 2,
    AMMO_SPEAR = 3,
    AMMO_THROWINGSTAR = 4,
    AMMO_THROWINGKNIFE = 5,
    AMMO_STONE = 6,
    AMMO_SNOWBALL = 7
};

enum AmmoAction_t
{
    AMMOACTION_NONE,
    AMMOACTION_REMOVECOUNT,
    AMMOACTION_REMOVECHARGE,
    AMMOACTION_MOVE,
    AMMOACTION_MOVEBACK
};

enum WieldInfo_t
{
    WIELDINFO_LEVEL = 1,
    WIELDINFO_MAGLV = 2,
    WIELDINFO_VOCREQ = 4,
    WIELDINFO_PREMIUM = 8
};

enum Skulls_t
{
    SKULL_NONE = 0,
    SKULL_YELLOW = 1,
    SKULL_GREEN = 2,
    SKULL_WHITE = 3,
    SKULL_RED = 4,
    SKULL_BLACK = 5,
    SKULL_LAST = SKULL_BLACK
};

enum PartyShields_t
{
    SHIELD_NONE = 0,
    SHIELD_WHITEYELLOW = 1,
    SHIELD_WHITEBLUE = 2,
    SHIELD_BLUE = 3,
    SHIELD_YELLOW = 4,
    SHIELD_BLUE_SHAREDEXP = 5,
    SHIELD_YELLOW_SHAREDEXP = 6,
    SHIELD_BLUE_NOSHAREDEXP_BLINK = 7,
    SHIELD_YELLOW_NOSHAREDEXP_BLINK = 8,
    SHIELD_BLUE_NOSHAREDEXP = 9,
    SHIELD_YELLOW_NOSHAREDEXP = 10,
    SHIELD_LAST = SHIELD_YELLOW_NOSHAREDEXP
};

enum item_t
{
    ITEM_FIREFIELD = 1492,
    ITEM_FIREFIELD_SAFE = 1500,

    ITEM_POISONFIELD = 1496,
    ITEM_POISONFIELD_SAFE = 1503,

    ITEM_ENERGYFIELD = 1495,
    ITEM_ENERGYFIELD_SAFE = 1504,

    ITEM_MAGICWALL = 1497,
    ITEM_MAGICWALL_SAFE = 11095,

    ITEM_WILDGROWTH = 1499,
    ITEM_WILDGROWTH_SAFE = 11096,

    ITEM_DEPOT = 2594,
    ITEM_LOCKER = 2589,
    ITEM_GLOWING_SWITCH = 11060,

    ITEM_MALE_CORPSE = 6080,
    ITEM_FEMALE_CORPSE = 6081,

    ITEM_MEAT = 2666,
    ITEM_HAM = 2671,
    ITEM_GRAPE = 2681,
    ITEM_APPLE = 2674,
    ITEM_BREAD = 2689,
    ITEM_ROLL = 2690,
    ITEM_CHEESE = 2696,

    ITEM_FULLSPLASH = 2016,
    ITEM_SMALLSPLASH = 2019,

    ITEM_PARCEL = 2595,
    ITEM_PARCEL_STAMPED = 2596,
    ITEM_LETTER = 2597,
    ITEM_LETTER_STAMPED = 2598,
    ITEM_LABEL = 2599,

    ITEM_WATERBALL_SPLASH = 7711,
    ITEM_WATERBALL = 7956,

    ITEM_HOUSE_TRANSFER = 1968 //read-only
};

enum PlayerFlags
{
    PlayerFlag_CannotUseCombat = 0, //2^0 = 1
    PlayerFlag_CannotAttackPlayer, //2^1 = 2
    PlayerFlag_CannotAttackMonster, //2^2 = 4
    PlayerFlag_CannotBeAttacked, //2^3 = 8
    PlayerFlag_CanConvinceAll, //2^4 = 16
    PlayerFlag_CanSummonAll, //2^5 = 32
    PlayerFlag_CanIllusionAll, //2^6 = 64
    PlayerFlag_CanSenseInvisibility, //2^7 = 128
    PlayerFlag_IgnoredByMonsters, //2^8 = 256
    PlayerFlag_NotGainInFight, //2^9 = 512
    PlayerFlag_HasInfiniteMana, //2^10 = 1024
    PlayerFlag_HasInfiniteSoul, //2^11 = 2048
    PlayerFlag_HasNoExhaustion, //2^12 = 4096
    PlayerFlag_CannotUseSpells, //2^13 = 8192
    PlayerFlag_CannotPickupItem, //2^14 = 16384
    PlayerFlag_CanAlwaysLogin, //2^15 = 32768
    PlayerFlag_CanBroadcast, //2^16 = 65536
    PlayerFlag_CanEditHouses, //2^17 = 131072
    PlayerFlag_CannotBeBanned, //2^18 = 262144
    PlayerFlag_CannotBePushed, //2^19 = 524288
    PlayerFlag_HasInfiniteCapacity, //2^20 = 1048576
    PlayerFlag_CanPushAllCreatures, //2^21 = 2097152
    PlayerFlag_CanTalkRedPrivate, //2^22 = 4194304
    PlayerFlag_CanTalkRedChannel, //2^23 = 8388608
    PlayerFlag_TalkOrangeHelpChannel, //2^24 = 16777216
    PlayerFlag_NotGainExperience, //2^25 = 33554432
    PlayerFlag_NotGainMana, //2^26 = 67108864
    PlayerFlag_NotGainHealth, //2^27 = 134217728
    PlayerFlag_NotGainSkill, //2^28 = 268435456
    PlayerFlag_SetMaxSpeed, //2^29 = 536870912
    PlayerFlag_SpecialVIP, //2^30 = 1073741824
    PlayerFlag_NotGenerateLoot, //2^31 = 2147483648
    PlayerFlag_CanTalkRedChannelAnonymous, //2^32 = 4294967296
    PlayerFlag_IgnoreProtectionZone, //2^33 = 8589934592
    PlayerFlag_IgnoreSpellCheck, //2^34 = 17179869184
    PlayerFlag_IgnoreEquipCheck, //2^35 = 34359738368
    PlayerFlag_CannotBeMuted, //2^36 = 68719476736
    PlayerFlag_IsAlwaysPremium, //2^37 = 137438953472
    PlayerFlag_CanAnswerRuleViolations, //2^38 = 274877906944
    PlayerFlag_39, //ignore			//2^39 = 549755813888	//not used by us
    PlayerFlag_ShowGroupNameInsteadOfVocation, //2^40 = 1099511627776
    PlayerFlag_HasInfiniteStamina, //2^41 = 2199023255552
    PlayerFlag_CannotMoveItems, //2^42 = 4398046511104
    PlayerFlag_CannotMoveCreatures, //2^43 = 8796093022208
    PlayerFlag_CanReportBugs, //2^44 = 17592186044416
    PlayerFlag_45, //ignore			//2^45 = 35184372088832	//not used by us
    PlayerFlag_CannotBeSeen, //2^46 = 70368744177664

    PlayerFlag_LastFlag
};

enum PlayerCustomFlags
{
    PlayerCustomFlag_AllowIdle = 0, //2^0 = 1
    PlayerCustomFlag_CanSeePosition, //2^1 = 2
    PlayerCustomFlag_CanSeeItemDetails, //2^2 = 4
    PlayerCustomFlag_CanSeeCreatureDetails, //2^3 = 8
    PlayerCustomFlag_NotSearchable, //2^4 = 16
    PlayerCustomFlag_GamemasterPrivileges, //2^5 = 32
    PlayerCustomFlag_CanThrowAnywhere, //2^6 = 64
    PlayerCustomFlag_CanPushAllItems, //2^7 = 128
    PlayerCustomFlag_CanMoveAnywhere, //2^8 = 256
    PlayerCustomFlag_CanMoveFromFar, //2^9 = 512
    PlayerCustomFlag_CanLoginMultipleCharacters, //2^10 = 1024 (account flag)
    PlayerCustomFlag_HasFullLight, //2^11 = 2048
    PlayerCustomFlag_CanLogoutAnytime, //2^12 = 4096 (account flag)
    PlayerCustomFlag_HideLevel, //2^13 = 8192
    PlayerCustomFlag_IsProtected, //2^14 = 16384
    PlayerCustomFlag_IsImmune, //2^15 = 32768
    PlayerCustomFlag_NotGainSkull, //2^16 = 65536
    PlayerCustomFlag_NotGainUnjustified, //2^17 = 131072
    PlayerCustomFlag_IgnorePacification, //2^18 = 262144
    PlayerCustomFlag_IgnoreLoginDelay, //2^19 = 524288
    PlayerCustomFlag_CanStairhop, //2^20 = 1048576
    PlayerCustomFlag_CanTurnhop, //2^21 = 2097152
    PlayerCustomFlag_IgnoreHouseRent, //2^22 = 4194304
    PlayerCustomFlag_CanWearAllAddons, //2^23 = 8388608

    PlayerCustomFlag_LastFlag
};
// OTCv8 features (from src/client/const.h)
enum GameFeature {
	GameProtocolChecksum = 1,
	GameAccountNames = 2,
	GameChallengeOnLogin = 3,
	GamePenalityOnDeath = 4,
	GameNameOnNpcTrade = 5,
	GameDoubleFreeCapacity = 6,
	GameDoubleExperience = 7,
	GameTotalCapacity = 8,
	GameSkillsBase = 9,
	GamePlayerRegenerationTime = 10,
	GameChannelPlayerList = 11,
	GamePlayerMounts = 12,
	GameEnvironmentEffect = 13,
	GameCreatureEmblems = 14,
	GameItemAnimationPhase = 15,
	GameMagicEffectU16 = 16,
	GamePlayerMarket = 17,
	GameSpritesU32 = 18,
	GameTileAddThingWithStackpos = 19,
	GameOfflineTrainingTime = 20,
	GamePurseSlot = 21,
	GameFormatCreatureName = 22,
	GameSpellList = 23,
	GameClientPing = 24,
	GameExtendedClientPing = 25,
	GameDoubleHealth = 28,
	GameDoubleSkills = 29,
	GameChangeMapAwareRange = 30,
	GameMapMovePosition = 31,
	GameAttackSeq = 32,
	GameBlueNpcNameColor = 33,
	GameDiagonalAnimatedText = 34,
	GameLoginPending = 35,
	GameNewSpeedLaw = 36,
	GameForceFirstAutoWalkStep = 37,
	GameMinimapRemove = 38,
	GameDoubleShopSellAmount = 39,
	GameContainerPagination = 40,
	GameThingMarks = 41,
	GameLooktypeU16 = 42,
	GamePlayerStamina = 43,
	GamePlayerAddons = 44,
	GameMessageStatements = 45,
	GameMessageLevel = 46,
	GameNewFluids = 47,
	GamePlayerStateU16 = 48,
	GameNewOutfitProtocol = 49,
	GamePVPMode = 50,
	GameWritableDate = 51,
	GameAdditionalVipInfo = 52,
	GameBaseSkillU16 = 53,
	GameCreatureIcons = 54,
	GameHideNpcNames = 55,
	GameSpritesAlphaChannel = 56,
	GamePremiumExpiration = 57,
	GameBrowseField = 58,
	GameEnhancedAnimations = 59,
	GameOGLInformation = 60,
	GameMessageSizeCheck = 61,
	GamePreviewState = 62,
	GameLoginPacketEncryption = 63,
	GameClientVersion = 64,
	GameContentRevision = 65,
	GameExperienceBonus = 66,
	GameAuthenticator = 67,
	GameUnjustifiedPoints = 68,
	GameSessionKey = 69,
	GameDeathType = 70,
	GameIdleAnimations = 71,
	GameKeepUnawareTiles = 72,
	GameIngameStore = 73,
	GameIngameStoreHighlights = 74,
	GameIngameStoreServiceType = 75,
	GameAdditionalSkills = 76,
	GameDistanceEffectU16 = 77,
	GamePrey = 78,
	GameDoubleMagicLevel = 79,

	GameExtendedOpcode = 80,
	GameMinimapLimitedToSingleFloor = 81,
	GameSendWorldName = 82,

	GameDoubleLevel = 83,
	GameDoubleSoul = 84,
	GameDoublePlayerGoodsMoney = 85,
	GameCreatureWalkthrough = 86,
	GameDoubleTradeMoney = 87,
	GameSequencedPackets = 88,
	GameTibia12Protocol = 89,

	// 90-99 otclientv8 features
	GameNewWalking = 90,
	GameSlowerManualWalking = 91,

	GameItemTooltip = 93,

	GameBot = 95,
	GameBiggerMapCache = 96,
	GameForceLight = 97,
	GameNoDebug = 98,
	GameBotProtection = 99,

	// Custom features for customer
	GameFasterAnimations = 101,
	GameCenteredOutfits = 102,
	GameSendIdentifiers = 103,
	GameWingsAndAura = 104,
	GamePlayerStateU32 = 105,
	GameOutfitShaders = 106,

	// advanced features
	GamePacketSizeU32 = 110,
	GamePacketCompression = 111,

	LastGameFeature = 120
};

//Reserved player storage key ranges
//[10000000 - 20000000]
#define PSTRG_RESERVED_RANGE_START	10000000
#define PSTRG_RESERVED_RANGE_SIZE	10000000

//[1000 - 1500]
#define PSTRG_OUTFITS_RANGE_START	(PSTRG_RESERVED_RANGE_START + 1000)
#define PSTRG_OUTFITS_RANGE_SIZE	500

//[1500 - 2000]
#define PSTRG_OUTFITSID_RANGE_START	(PSTRG_RESERVED_RANGE_START + 1500)
#define PSTRG_OUTFITSID_RANGE_SIZE	500

#define NETWORKMESSAGE_MAXSIZE 65500
#define IPBAN_FLAG 128
#define LOCALHOST 2130706433

#define IS_IN_KEYRANGE(key, range) (key >= PSTRG_##range##_START && ((key - PSTRG_##range##_START) < PSTRG_##range##_SIZE))
#endif
