/*
** HFCL Samples - Samples for HybridOS Foundation Class Library
**
** Copyright (C) 2018 Beijing FMSoft Technologies Co., Ltd.
**
** This file is part of HFCL Samples.
**
** This program is free software: you can redistribute it and/or modify
** it under the terms of the GNU General Public License as published by
** the Free Software Foundation, either version 3 of the License, or
** (at your option) any later version.
**
** This program is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
** GNU General Public License for more details.
**
** You should have received a copy of the GNU General Public License
** along with this program.  If not, see <https://www.gnu.org/licenses/>.
*/

begin_sys_respkg

    def_static_array_real(def_padding, 4, 2, 4, 2)

    // L10N text resource
    begin_text_res()
        text_res_gnumsg (R_LANG_zh_CN, R_ENCODING_utf8, "res/messages/zh_CN/LC_MESSAGES/helloworld.mo")
        text_res_gnumsg (R_LANG_zh_TW, R_ENCODING_utf8, "res/messages/zh_TW/LC_MESSAGES/helloworld.mo")
    end_text_res

    // global images
    begin_image_res()
        image(arrow_left,   "res/images/arrow-left.png")
        image(arrow_right,  "res/images/arrow-right.png")
        image(arrow_up,     "res/images/arrow-up.png")
        image(arrow_down,   "res/images/arrow-down.png")
        image(mark_check,   "res/images/mark-check.png")
        image(ok,           "res/images/icon-ok.png")
        image(cancel,       "res/images/icon-cancel.png")
        image(cloud,        "res/images/icon-cloud.png")
        image(usb,          "res/images/icon-camera-usb.png")
        image(wlan,         "res/images/icon-camera-wlan.png")
        image(loading_nm,   "res/images/loading-nm.gif")
        image(loading_sm,   "res/images/loading-sm.gif")
        image(loading_xm,   "res/images/loading-xm.gif")
    end_image_res

    // global fonts
    begin_font_res()
        font(xxs,  "ttf-HanSans-rrncns-*-10-UTF-8")
        font(xs,   "ttf-HanSans-rrncns-*-12-UTF-8")
        font(sm,   "ttf-HanSans-rrncns-*-14-UTF-8")
        font(nm,   "ttf-HanSans-rrncns-*-16-UTF-8")
        font(lg,   "ttf-HanSans-rrncng-*-20-UTF-8")
        font(xl,   "ttf-HanSans-rrncng-*-26-UTF-8")
        font(xxl,  "ttf-HanSans-rrncng-*-36-UTF-8")
    end_font_res

    // CSS
    begin_css_res
        begin_css(body, "hvbody")
            style(BackgroundColor, PV_COLOR_BLACK)
            style(Color,    PV_RGBA, rgb(0x16, 0xF2, 0x23))
            style(Font,     PV_SYSID, sysid_font(nm))
        end_css
        begin_css(title, "hvtext.title")
            style(Display,  PV_BLOCK)
            style(Height,   PV_LENGTH_PX, 28.0f)
            style(Width,    PV_AUTO)
            style(TextAlign,PV_CENTER)
            style(Color,    PV_RGBA, rgb(0x64, 0x96, 0xc7))
            style(Padding,  PV_LENGTH_PX, array_real(def_padding))
        end_css
        begin_css(subtitle, "hvtext.subtitle")
            style(Display,  PV_BLOCK)
            style(Height,   PV_LENGTH_PX, 20.0f)
            style(Width,    PV_AUTO)
            style(TextAlign,PV_CENTER)
            style(Color,    PV_RGBA, rgb(0xDD, 0xDD, 0xDD))
            style(Font,     PV_SYSID, sysid_font(sm))
        end_css
    end_css_res

    // CSS Group
    begin_css_group_res
        begin_css_group(global)
            css(body)
            css(title)
            css(subtitle)
        end_css_group
    end_css_group_res

end_sys_respkg
