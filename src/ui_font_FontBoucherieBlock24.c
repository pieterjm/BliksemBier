/*******************************************************************************
 * Size: 24 px
 * Bpp: 1
 * Opts: --bpp 1 --size 24 --font /home/nl077-lab-0028/Downloads/SquarLine_Studio/Test Project/assets/Boucherie Block.otf -o /home/nl077-lab-0028/Downloads/SquarLine_Studio/Test Project/assets/ui_font_FontBoucherieBlock24.c --format lvgl -r 0x20 --symbols ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789_!*. --no-compress --no-prefilter
 ******************************************************************************/

#include "ui.h"

#ifndef UI_FONT_FONTBOUCHERIEBLOCK24
#define UI_FONT_FONTBOUCHERIEBLOCK24 1
#endif

#if UI_FONT_FONTBOUCHERIEBLOCK24

/*-----------------
 *    BITMAPS
 *----------------*/

/*Store the image of the glyphs*/
static LV_ATTRIBUTE_LARGE_CONST const uint8_t glyph_bitmap[] = {
    /* U+0020 " " */
    0x0,

    /* U+0021 "!" */
    0xf6, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x6,
    0x66,

    /* U+002A "*" */
    0x11, 0x27, 0xf9, 0xcf, 0xf2, 0xc6, 0xc,

    /* U+002E "." */
    0xff, 0x80,

    /* U+0030 "0" */
    0xfe, 0xff, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xff, 0xfe,

    /* U+0031 "1" */
    0x6e, 0xee, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66,
    0x6f,

    /* U+0032 "2" */
    0x7f, 0xff, 0xc3, 0xc3, 0xc3, 0xc3, 0x83, 0x7,
    0xe, 0x1c, 0x18, 0x38, 0x70, 0xe0, 0xc0, 0xc1,
    0xff, 0xff,

    /* U+0033 "3" */
    0xfe, 0xff, 0xc3, 0xc3, 0xc3, 0xc3, 0x8f, 0x3c,
    0x3e, 0x27, 0x3, 0x3, 0x43, 0xc3, 0xc3, 0xc3,
    0xff, 0xff,

    /* U+0034 "4" */
    0xf1, 0xec, 0x19, 0x83, 0x30, 0x66, 0xc, 0xc1,
    0x98, 0x33, 0x6, 0x7f, 0xcf, 0xf9, 0x3, 0x0,
    0x60, 0xc, 0x1, 0x80, 0x30, 0x6, 0x0, 0xc0,
    0x3c,

    /* U+0035 "5" */
    0x7f, 0x7f, 0x61, 0x60, 0x60, 0x60, 0x60, 0x7f,
    0x7f, 0x3, 0x3, 0x3, 0x43, 0xc3, 0xc3, 0xc3,
    0xff, 0xff,

    /* U+0036 "6" */
    0xfe, 0xff, 0xc3, 0xc3, 0xc3, 0xc2, 0xc0, 0xc0,
    0xff, 0xff, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xff, 0x7f,

    /* U+0037 "7" */
    0xff, 0xff, 0xe0, 0xc0, 0xe0, 0x70, 0x30, 0x38,
    0x18, 0x1c, 0xe, 0x6, 0x7, 0x3, 0x81, 0x81,
    0xc0, 0xe0, 0x70, 0x78, 0x0,

    /* U+0038 "8" */
    0x7f, 0xbf, 0xd8, 0x6c, 0x36, 0x1b, 0xd, 0xce,
    0x7e, 0x3e, 0x7f, 0xf8, 0xf8, 0x3c, 0x1e, 0xf,
    0x7, 0x83, 0xff, 0xff, 0xc0,

    /* U+0039 "9" */
    0xfe, 0xff, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xff, 0xff, 0x3, 0x3, 0x83, 0xc3, 0xc3, 0xc3,
    0xff, 0x7f,

    /* U+0041 "A" */
    0xf, 0xc0, 0x1e, 0x0, 0x78, 0x1, 0xe0, 0xf,
    0xc0, 0x37, 0x0, 0xdc, 0x3, 0x30, 0x1c, 0xe0,
    0x63, 0x81, 0x8e, 0x6, 0x78, 0x3f, 0xe0, 0xfd,
    0xc3, 0xc3, 0xc, 0xc, 0x70, 0x3b, 0xe1, 0xe0,

    /* U+0042 "B" */
    0xff, 0x1f, 0xe6, 0x19, 0x86, 0x61, 0x98, 0x66,
    0x39, 0xbc, 0x7f, 0x9f, 0xf7, 0xd, 0x83, 0x60,
    0xd8, 0x36, 0xd, 0x83, 0x7f, 0xff, 0xf0,

    /* U+0043 "C" */
    0xfe, 0xff, 0xc3, 0xc3, 0xc3, 0xc2, 0xc0, 0xc0,
    0xc0, 0xc0, 0xc0, 0xc0, 0xc3, 0xc3, 0xc3, 0xc3,
    0xff, 0xfe,

    /* U+0044 "D" */
    0xff, 0x9f, 0xf6, 0xd, 0x83, 0x60, 0xd8, 0x36,
    0xd, 0x83, 0x60, 0xd8, 0x36, 0xd, 0x83, 0x60,
    0xd8, 0x36, 0xd, 0x83, 0x7f, 0xff, 0xf0,

    /* U+0045 "E" */
    0xff, 0xbf, 0xd8, 0x6c, 0x36, 0x13, 0x1, 0x80,
    0xc0, 0x66, 0x3f, 0x1f, 0xe, 0x6, 0xb, 0xd,
    0x86, 0xc3, 0x7f, 0xff, 0xc0,

    /* U+0046 "F" */
    0xff, 0xbf, 0xd8, 0x6c, 0x36, 0x13, 0x1, 0x80,
    0xc0, 0x66, 0x3f, 0x1f, 0xe, 0x6, 0x3, 0x1,
    0x80, 0xc0, 0x60, 0x78, 0x0,

    /* U+0047 "G" */
    0xfe, 0xff, 0xc3, 0xc3, 0xc3, 0xc2, 0xc0, 0xc0,
    0xc0, 0xc3, 0xc7, 0xc7, 0xc3, 0xc3, 0xc3, 0xc3,
    0xff, 0xfe,

    /* U+0048 "H" */
    0xf1, 0xec, 0x19, 0x83, 0x30, 0x66, 0xc, 0xc1,
    0x98, 0x33, 0x6, 0x60, 0xcc, 0x39, 0x9f, 0x3f,
    0xe7, 0xec, 0xf1, 0x98, 0x33, 0x6, 0x60, 0xde,
    0x3c,

    /* U+0049 "I" */
    0xf6, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66, 0x66,
    0x6f,

    /* U+004A "J" */
    0xf, 0x6, 0x6, 0x6, 0x6, 0x6, 0x6, 0x6,
    0x6, 0x6, 0x6, 0x6, 0x46, 0xc6, 0xc6, 0xc6,
    0xfe, 0x7e,

    /* U+004B "K" */
    0xf1, 0xec, 0x39, 0x8e, 0x31, 0xc6, 0x70, 0xcc,
    0x1b, 0x83, 0x60, 0x7c, 0xf, 0xc1, 0xf8, 0x3b,
    0x86, 0x70, 0xc7, 0x18, 0xe3, 0xe, 0x61, 0xde,
    0x3c,

    /* U+004C "L" */
    0xf0, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60,
    0x60, 0x60, 0x60, 0x60, 0x61, 0x63, 0x63, 0x63,
    0x7f, 0xff,

    /* U+004D "M" */
    0xf0, 0xf, 0x70, 0xe, 0x78, 0x1e, 0x78, 0x1e,
    0x78, 0x1e, 0x7c, 0x3e, 0x7c, 0x3e, 0x7c, 0x36,
    0x6c, 0x76, 0x6e, 0x76, 0x6e, 0x66, 0x66, 0xe6,
    0x67, 0xe6, 0x63, 0xc6, 0x63, 0xc6, 0x63, 0xc6,
    0x63, 0xc6, 0xf3, 0xcf,

    /* U+004E "N" */
    0xf0, 0xf7, 0x6, 0x70, 0x67, 0x86, 0x78, 0x67,
    0xc6, 0x7c, 0x66, 0xe6, 0x6e, 0x66, 0x76, 0x67,
    0x66, 0x36, 0x63, 0xe6, 0x1e, 0x61, 0xe6, 0x1e,
    0x60, 0xef, 0xe,

    /* U+004F "O" */
    0xfe, 0xff, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xff, 0xfe,

    /* U+0050 "P" */
    0xff, 0x3f, 0xd8, 0x6c, 0x36, 0x1b, 0xd, 0x86,
    0xc3, 0x63, 0xb3, 0x9f, 0x8f, 0x7, 0x3, 0x1,
    0x80, 0xc0, 0x60, 0x78, 0x0,

    /* U+0051 "Q" */
    0xfe, 0xff, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xff, 0xff, 0x1c, 0xe,

    /* U+0052 "R" */
    0xff, 0x8f, 0xf9, 0x83, 0x30, 0x66, 0xc, 0xc1,
    0x98, 0x33, 0x6, 0x63, 0xcd, 0xf1, 0xfc, 0x3f,
    0xc6, 0x38, 0xc7, 0x18, 0x63, 0xe, 0x61, 0xde,
    0x3c,

    /* U+0053 "S" */
    0xfe, 0xff, 0xc3, 0xc3, 0xc3, 0xc1, 0xe0, 0xf0,
    0x38, 0x1e, 0x7, 0x3, 0xc3, 0xc3, 0xc3, 0xc3,
    0xff, 0x7f,

    /* U+0054 "T" */
    0xff, 0xff, 0xf8, 0xc4, 0x30, 0xc, 0x3, 0x0,
    0xc0, 0x30, 0xc, 0x3, 0x0, 0xc0, 0x30, 0xc,
    0x3, 0x0, 0xc0, 0x30, 0xc, 0x7, 0x80,

    /* U+0055 "U" */
    0xf3, 0xd8, 0x66, 0x19, 0x86, 0x61, 0x98, 0x66,
    0x19, 0x86, 0x61, 0x98, 0x66, 0x19, 0x86, 0x61,
    0x98, 0x66, 0x19, 0x86, 0x7f, 0x9f, 0xc0,

    /* U+0056 "V" */
    0xf8, 0x7b, 0x83, 0x8c, 0x1c, 0x60, 0xe3, 0x86,
    0x1c, 0x30, 0x63, 0x83, 0x1c, 0x1c, 0xc0, 0xe6,
    0x3, 0x70, 0x1b, 0x80, 0xf8, 0x7, 0xc0, 0x1e,
    0x0, 0xf0, 0x7, 0x80, 0x3c, 0x0,

    /* U+0057 "W" */
    0xf8, 0xf1, 0xee, 0x1c, 0x19, 0xc3, 0x83, 0x18,
    0x78, 0xe3, 0xf, 0x1c, 0x71, 0xe3, 0x8e, 0x7c,
    0x60, 0xcd, 0xcc, 0x19, 0xb9, 0x83, 0x33, 0x70,
    0x76, 0x6e, 0xf, 0x8f, 0x80, 0xf0, 0xf0, 0x1e,
    0x1e, 0x3, 0xc3, 0xc0, 0x70, 0x70, 0xe, 0xe,
    0x1, 0xe1, 0xe0,

    /* U+0058 "X" */
    0xf1, 0xee, 0x38, 0xc7, 0x1c, 0xc3, 0xb8, 0x3e,
    0x7, 0xc0, 0x78, 0xe, 0x1, 0xc0, 0x3c, 0xf,
    0x81, 0xb8, 0x77, 0xc, 0x63, 0x8e, 0x71, 0xde,
    0x3c,

    /* U+0059 "Y" */
    0xf0, 0xf7, 0xe, 0x30, 0xe3, 0x8c, 0x39, 0xc1,
    0xd8, 0x1f, 0x80, 0xf0, 0xf, 0x0, 0x60, 0x6,
    0x0, 0x60, 0x6, 0x0, 0x60, 0x6, 0x0, 0x60,
    0x6, 0x0, 0xf0,

    /* U+005A "Z" */
    0x7f, 0xdf, 0xf4, 0x18, 0x6, 0x3, 0x80, 0xc0,
    0x70, 0x18, 0xe, 0x3, 0x1, 0xc0, 0x60, 0x38,
    0xc, 0x3, 0x1, 0xc3, 0x7f, 0xff, 0xf0,

    /* U+005F "_" */
    0xff, 0xff, 0xff, 0xfc
};


/*---------------------
 *  GLYPH DESCRIPTION
 *--------------------*/

static const lv_font_fmt_txt_glyph_dsc_t glyph_dsc[] = {
    {.bitmap_index = 0, .adv_w = 0, .box_w = 0, .box_h = 0, .ofs_x = 0, .ofs_y = 0} /* id = 0 reserved */,
    {.bitmap_index = 0, .adv_w = 93, .box_w = 1, .box_h = 1, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 1, .adv_w = 76, .box_w = 4, .box_h = 18, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 10, .adv_w = 129, .box_w = 7, .box_h = 8, .ofs_x = 0, .ofs_y = 10},
    {.bitmap_index = 17, .adv_w = 75, .box_w = 3, .box_h = 3, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 19, .adv_w = 168, .box_w = 8, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 37, .adv_w = 101, .box_w = 4, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 46, .adv_w = 157, .box_w = 8, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 64, .adv_w = 164, .box_w = 8, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 82, .adv_w = 190, .box_w = 11, .box_h = 18, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 107, .adv_w = 156, .box_w = 8, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 125, .adv_w = 161, .box_w = 8, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 143, .adv_w = 159, .box_w = 9, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 164, .adv_w = 173, .box_w = 9, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 185, .adv_w = 161, .box_w = 8, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 203, .adv_w = 222, .box_w = 14, .box_h = 18, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 235, .adv_w = 185, .box_w = 10, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 258, .adv_w = 168, .box_w = 8, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 276, .adv_w = 179, .box_w = 10, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 299, .adv_w = 170, .box_w = 9, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 320, .adv_w = 166, .box_w = 9, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 341, .adv_w = 170, .box_w = 8, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 359, .adv_w = 203, .box_w = 11, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 384, .adv_w = 91, .box_w = 4, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 393, .adv_w = 141, .box_w = 8, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 411, .adv_w = 201, .box_w = 11, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 436, .adv_w = 158, .box_w = 8, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 454, .adv_w = 269, .box_w = 16, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 490, .adv_w = 215, .box_w = 12, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 517, .adv_w = 175, .box_w = 8, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 535, .adv_w = 169, .box_w = 9, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 556, .adv_w = 175, .box_w = 8, .box_h = 20, .ofs_x = 1, .ofs_y = -2},
    {.bitmap_index = 576, .adv_w = 189, .box_w = 11, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 601, .adv_w = 152, .box_w = 8, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 619, .adv_w = 163, .box_w = 10, .box_h = 18, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 642, .adv_w = 182, .box_w = 10, .box_h = 18, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 665, .adv_w = 212, .box_w = 13, .box_h = 18, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 695, .adv_w = 315, .box_w = 19, .box_h = 18, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 738, .adv_w = 197, .box_w = 11, .box_h = 18, .ofs_x = 1, .ofs_y = 0},
    {.bitmap_index = 763, .adv_w = 200, .box_w = 12, .box_h = 18, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 790, .adv_w = 171, .box_w = 10, .box_h = 18, .ofs_x = 0, .ofs_y = 0},
    {.bitmap_index = 813, .adv_w = 257, .box_w = 15, .box_h = 2, .ofs_x = 1, .ofs_y = -2}
};

/*---------------------
 *  CHARACTER MAPPING
 *--------------------*/

static const uint16_t unicode_list_0[] = {
    0x0, 0x1, 0xa, 0xe
};

/*Collect the unicode lists and glyph_id offsets*/
static const lv_font_fmt_txt_cmap_t cmaps[] =
{
    {
        .range_start = 32, .range_length = 15, .glyph_id_start = 1,
        .unicode_list = unicode_list_0, .glyph_id_ofs_list = NULL, .list_length = 4, .type = LV_FONT_FMT_TXT_CMAP_SPARSE_TINY
    },
    {
        .range_start = 48, .range_length = 10, .glyph_id_start = 5,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 65, .range_length = 26, .glyph_id_start = 15,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    },
    {
        .range_start = 95, .range_length = 1, .glyph_id_start = 41,
        .unicode_list = NULL, .glyph_id_ofs_list = NULL, .list_length = 0, .type = LV_FONT_FMT_TXT_CMAP_FORMAT0_TINY
    }
};

/*-----------------
 *    KERNING
 *----------------*/


/*Pair left and right glyphs for kerning*/
static const uint8_t kern_pair_glyph_ids[] =
{
    3, 15,
    3, 24,
    3, 38,
    3, 39,
    4, 9,
    4, 34,
    4, 36,
    4, 37,
    4, 39,
    7, 9,
    8, 9,
    10, 6,
    11, 6,
    11, 9,
    11, 13,
    11, 14,
    12, 4,
    12, 6,
    15, 3,
    15, 17,
    15, 21,
    15, 29,
    15, 31,
    15, 33,
    15, 34,
    15, 35,
    15, 36,
    15, 37,
    15, 39,
    16, 15,
    16, 34,
    16, 36,
    16, 37,
    16, 38,
    16, 39,
    17, 15,
    17, 36,
    17, 39,
    18, 15,
    18, 20,
    18, 36,
    18, 37,
    18, 39,
    18, 40,
    20, 4,
    20, 15,
    20, 24,
    20, 34,
    20, 40,
    21, 15,
    21, 35,
    21, 36,
    21, 37,
    21, 38,
    21, 39,
    22, 39,
    23, 17,
    25, 17,
    25, 21,
    25, 29,
    25, 31,
    25, 33,
    25, 35,
    25, 39,
    26, 3,
    26, 34,
    26, 36,
    26, 37,
    26, 39,
    28, 15,
    28, 38,
    29, 15,
    29, 36,
    29, 37,
    29, 38,
    29, 39,
    30, 4,
    30, 15,
    30, 24,
    30, 34,
    30, 38,
    30, 40,
    31, 15,
    31, 37,
    31, 39,
    32, 34,
    32, 36,
    32, 37,
    32, 39,
    33, 15,
    33, 36,
    33, 37,
    33, 38,
    33, 39,
    34, 4,
    34, 15,
    34, 24,
    34, 40,
    35, 15,
    36, 4,
    36, 15,
    36, 17,
    36, 21,
    36, 24,
    36, 29,
    36, 31,
    36, 40,
    37, 4,
    37, 15,
    37, 17,
    37, 21,
    37, 24,
    37, 29,
    37, 31,
    37, 38,
    37, 40,
    38, 17,
    38, 21,
    38, 29,
    38, 31,
    39, 4,
    39, 15,
    39, 17,
    39, 21,
    39, 24,
    39, 29,
    39, 31,
    39, 33,
    39, 40,
    40, 17
};

/* Kerning between the respective left and right glyphs
 * 4.4 format which needs to scaled with `kern_scale`*/
static const int8_t kern_pair_values[] =
{
    -39, -57, -12, -6, -48, -39, -42, -39,
    -36, -8, -9, -6, -9, -6, 8, 8,
    -39, -9, -42, -9, -9, -8, -8, -9,
    -33, -18, -48, -39, -51, -8, -12, -12,
    -24, -12, -21, -8, -8, -8, -8, -9,
    -8, -12, -8, -8, -33, -42, -45, 4,
    -8, -8, -8, -12, -8, -8, -8, -8,
    -12, -9, -9, -9, -12, -9, -15, -15,
    -51, -24, -51, -27, -54, -8, -10, -9,
    -15, -12, -12, -13, -33, -33, -44, 9,
    -6, -9, -8, -9, -9, -8, -12, -15,
    -15, -3, -9, -9, -6, -6, -30, -30,
    -30, -6, -9, -33, -45, -9, -6, -38,
    -9, -6, -15, -33, -38, -15, -12, -30,
    -6, -12, -8, -9, -9, -9, -6, -9,
    -33, -45, -15, -8, -48, -6, -9, -6,
    -15, -6
};

/*Collect the kern pair's data in one place*/
static const lv_font_fmt_txt_kern_pair_t kern_pairs =
{
    .glyph_ids = kern_pair_glyph_ids,
    .values = kern_pair_values,
    .pair_cnt = 130,
    .glyph_ids_size = 0
};

/*--------------------
 *  ALL CUSTOM DATA
 *--------------------*/

#if LV_VERSION_CHECK(8, 0, 0)
/*Store all the custom data of the font*/
static  lv_font_fmt_txt_glyph_cache_t cache;
static const lv_font_fmt_txt_dsc_t font_dsc = {
#else
static lv_font_fmt_txt_dsc_t font_dsc = {
#endif
    .glyph_bitmap = glyph_bitmap,
    .glyph_dsc = glyph_dsc,
    .cmaps = cmaps,
    .kern_dsc = &kern_pairs,
    .kern_scale = 16,
    .cmap_num = 4,
    .bpp = 1,
    .kern_classes = 0,
    .bitmap_format = 0,
#if LV_VERSION_CHECK(8, 0, 0)
    .cache = &cache
#endif
};


/*-----------------
 *  PUBLIC FONT
 *----------------*/

/*Initialize a public general font descriptor*/
#if LV_VERSION_CHECK(8, 0, 0)
const lv_font_t ui_font_FontBoucherieBlock24 = {
#else
lv_font_t ui_font_FontBoucherieBlock24 = {
#endif
    .get_glyph_dsc = lv_font_get_glyph_dsc_fmt_txt,    /*Function pointer to get glyph's data*/
    .get_glyph_bitmap = lv_font_get_bitmap_fmt_txt,    /*Function pointer to get glyph's bitmap*/
    .line_height = 20,          /*The maximum line height required by the font*/
    .base_line = 2,             /*Baseline measured from the bottom of the line*/
#if !(LVGL_VERSION_MAJOR == 6 && LVGL_VERSION_MINOR == 0)
    .subpx = LV_FONT_SUBPX_NONE,
#endif
#if LV_VERSION_CHECK(7, 4, 0) || LVGL_VERSION_MAJOR >= 8
    .underline_position = -2,
    .underline_thickness = 1,
#endif
    .dsc = &font_dsc           /*The custom font data. Will be accessed by `get_glyph_bitmap/dsc` */
};



#endif /*#if UI_FONT_FONTBOUCHERIEBLOCK24*/
