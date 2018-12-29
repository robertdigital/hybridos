/*
** HFCL - HybridOS Foundation Class Library
**
** Copyright (C) 2018 Beijing FMSoft Technologies Co., Ltd.
**
** This file is part of HFCL.
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

#include "view/imageview.h"

namespace hfcl {

ImageView::ImageView(const char* cssClass, const char* name, int id)
    : View(cssClass, name, id)
{
    init();
}

ImageView::~ImageView()
{
    if(m_image) {
        HFCL_DELETE(m_image);
    }
}

void ImageView::drawContent(GraphicsContext* context, IntRect &rc)
{
    if(m_format.rotationAngle != 0){
        m_format.drawMode = DRAWMODE_ROTATIONANGLE;
    }

    if(m_image != NULL){
        m_image->paint(context, rc, m_format, m_xo, m_yo);
    }
}


bool ImageView::setImage(Image *pImg)
{
    if (pImg == m_image) {
        HFCL_DELETE(pImg);
        return true;
    }

    if(m_image != NULL) {
        HFCL_DELETE(m_image);
    }
    m_image = pImg;

    updateView();

    return true;
}

bool ImageView::setReplaceColor(Uint32 color)
{
    m_image->setReplaceColor(color);
    updateView();
    return true;
}

void ImageView::setPartBoxXoYo(int xo, int yo)
{
    m_xo = xo;
    m_yo = yo;
}

void ImageView::getPartBoxXoYo(int& xo, int& yo)
{
    xo = m_xo;
    yo = m_yo;
}

void ImageView::setFromImgRect(bool bSet)
{
    if (!bSet)
        return;

    if (m_image == NULL)
        return;

    setRect(0, 0, getImageWidth(), getImageHeight());
}

int ImageView::getImageWidth(void)
{
    if (m_image != NULL)
        return m_image->width();

    return 0;
}

int ImageView::getImageHeight(void)
{
    if (m_image != NULL)
        return m_image->height();

    return 0;
}

DEFINE_CLASS_NAME(ImageView)

} // namespace hfcl

