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


#include "iconview.h"
#include "graphics/graphicscontext.h"

namespace hfcl {

IconView::IconView(View *_parent)
    : ScrollView(_parent), m_gridView(NULL)
{
    m_gridView = HFCL_NEW_EX(GridView, (this));
    setContent(m_gridView);
    // ref : this view is multi EventListers,
    // which be add to gridview (here) and TimerService (parent).
    ref();
    m_gridView->addEventListener(this);
}

IconView::IconView(View *_parent, DrawableSet *drset)
    : ScrollView(_parent, drset), m_gridView(NULL)
{
    m_gridView = HFCL_NEW_EX(GridView, (this, NULL));
    setContent(m_gridView);
    // ref : this view is multi EventListers,
    // which be add to gridview (here) and TimerService (parent).
    ref();
    m_gridView->addEventListener(this);
}

IconView::~IconView()
{
    // NOTHING
}

void IconView::makeHilightVisible()
{
    if (NULL == m_gridView)
        return;

    int idxF = m_gridView->focusItemIdx();
    View *f = m_gridView->getChildByIndex(idxF);
    if (NULL != f) {
        int h;
        int offY = m_offy;
        IntRect rc = f->getRect();
        getSize(NULL, &h); //get the viewport size

        if ((offY + h) < rc.m_bottom)
            offY = rc.m_bottom - h;

        if (offY > rc.m_top)
            offY = rc.m_top;

        moveViewport(m_offx, offY);
    }
}

bool IconView::handler(Event* event)
{
    if (event->eventType() == Event::CUSTOM_NOTIFY
            && ((CustomEvent *)event)->customWparam() == CustomEvent::CUS_SELCHANGED)
    {
        makeHilightVisible();
        if (!autoShowBar()) {
            setAutoShowBar(true);
            updateView();
        }
    }
    return ScrollView::handler(event);
}

bool IconView::dispatchEvent(Event *e)
{
    if (NULL != m_gridView)
        return m_gridView->dispatchEvent(e);

    return GOON_DISPATCH;
}

} // namespace hfcl
