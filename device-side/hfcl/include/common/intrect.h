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
** along with this program. If not, see <https://www.gnu.org/licenses/>.
*/

#ifndef __NGUX_INTRECT_H__
#define __NGUX_INTRECT_H__

#include "nguxcommon.h"

NAMESPACE_BEGIN

class IntRect {
    public:
        IntRect()
            : m_left(0)
            , m_top(0)
            , m_right(0)
            , m_bottom(0)
        {

        }

        IntRect(NGInt ileft, NGInt itop = 0, NGInt iright = 0, NGInt ibottom = 0)
            : m_left(ileft)
            , m_top(itop)
            , m_right(iright)
            , m_bottom(ibottom)
        {

        }

        IntRect(const IntRect& irc)
            : m_left(irc.m_left)
            , m_top(irc.m_top)
            , m_right(irc.m_right)
            , m_bottom(irc.m_bottom)
        {
        }

        IntRect(const RECT& rc)
            : m_left(rc.left)
            , m_top(rc.top)
            , m_right(rc.right)
            , m_bottom(rc.bottom)
        {
        }
        operator RECT() const 
        {
            RECT rect = {left(), top(), right(), bottom()};
            return rect;
        }

        NGInt left(void)   const { return m_left;   }
        NGInt top(void)    const { return m_top;    }
        NGInt right(void)  const { return m_right;  }
        NGInt bottom(void) const { return m_bottom; }

        NGInt width(void)  const { return m_right - m_left; }
        NGInt height(void) const { return m_bottom - m_top; }

        NGBool isEmpty(void) const
        {
            return m_left >= m_right || m_top >= m_bottom;
        }

        void setEmpty(void)
        {
            m_left = m_right = m_top = m_bottom = 0;
        }

        void setRect(NGInt ileft, NGInt itop, NGInt iright, NGInt ibottom)
        {
            m_left   = ileft;
            m_top    = itop;
            m_right  = iright;
            m_bottom = ibottom;
        }

        void setRect(const IntRect& irc)
        {
            m_left   = irc.m_left;
            m_top    = irc.m_top;
            m_right  = irc.m_right;
            m_bottom = irc.m_bottom;
        }

        void getRect(NGInt* pleft, NGInt* ptop, NGInt* pright, NGInt* pbottom)
        {
            *pleft   = m_left;
            *ptop    = m_top;
            *pright  = m_right;
            *pbottom = m_bottom;
        }

		void setWidth(NGInt iwidth) {
			m_right = m_left + iwidth;
		}

		void setHeight(NGInt iheight) {
			m_bottom = m_top + iheight;
		}

		void setSize(NGInt iwidth, NGInt iheight) {
			m_right = m_left + iwidth;
			m_bottom = m_top + iheight;
		}

        const IntRect& getRect(void) const
        {
            return *this;
        }

        IntRect& operator=(const IntRect& irc)
        {
            if (&irc == this)
                return *this;

            m_left   = irc.m_left;
            m_top    = irc.m_top;
            m_right  = irc.m_right;
            m_bottom = irc.m_bottom;

            return *this;
        }

        IntRect& operator=(const IntRect* pirc)
        {
            if (pirc == this)
                return *this;

            m_left   = pirc->m_left;
            m_top    = pirc->m_top;
            m_right  = pirc->m_right;
            m_bottom = pirc->m_bottom;

            return *this;
        }

        NGBool operator==(const IntRect& irc) const
        {
            if (&irc == this)
                return true;

            if (m_left   != irc.m_left  ||
                m_top    != irc.m_top   ||
                m_right  != irc.m_right ||
                m_bottom != irc.m_bottom)
                return false;

            return true;
        }

        NGBool operator!=(const IntRect& irc) const
        {
            if (&irc == this)
                return false;

            if (m_left   != irc.m_left  ||
                m_top    != irc.m_top   ||
                m_right  != irc.m_right ||
                m_bottom != irc.m_bottom)
                return true;

            return false;
        }

        /**
         * Offset set the rectangle by adding x to its left and right,
         * and adding y to its top and bottom.
         */
        void offset(NGInt x, NGInt y)
        {
            m_left   += x;
            m_top    += y;
            m_right  += x;
            m_bottom += y;
        }

        /**
         * Inset the rectangle y (x,y). If dx is positive, then the sides are moved inwards,
         * making the rectangle narrower. If x is negative, then the sides are moved outwards,
         * making the rectangle wider. The same hods true for y and the top and bottom.
         */
        void inset(NGInt x, NGInt y)
        {
            m_left   += x;
            m_top    += y;
            m_right  -= x;
            m_bottom -= y;
        }

		void inset(NGInt ileft, NGInt itop, NGInt iright, NGInt ibottom) {
			m_left += ileft;
			m_top  += itop;
			m_right -= iright;
			m_bottom -= ibottom;
		}

        NGBool contains(NGInt x, NGInt y) const
        {
            return  (unsigned)(x - m_left) <= (unsigned)(m_right - m_left) &&
                    (unsigned)(y - m_top) <= (unsigned)(m_bottom - m_top);
        }

        NGBool contains(NGInt ileft, NGInt itop, NGInt iright, NGInt ibottom) const
        {
            return  ileft < iright && itop < ibottom && !this->isEmpty() && // check for empties
                    m_left <= ileft && m_top <= itop &&
                    m_right >= iright && m_bottom >= ibottom;
        }

        NGBool contains(const IntRect& irc) const
        {
            return  !irc.isEmpty() && !this->isEmpty() &&     // check for empties
                    m_left <= irc.m_left && m_top <= irc.m_top &&
                    m_right >= irc.m_right && m_bottom >= irc.m_bottom;
        }

        NGBool intersect(const IntRect& irc)
        {
            return this->intersect(irc.m_left, irc.m_top, irc.m_right, irc.m_bottom);
        }

        NGBool intersect(const IntRect& a, const IntRect& b)
        {
            if (!a.isEmpty() && !b.isEmpty() &&
                    a.m_left < b.m_right && b.m_left < a.m_right &&
                    a.m_top < b.m_bottom && b.m_top < a.m_bottom) {
                m_left   = (a.m_left   > b.m_left  ) ? a.m_left   : b.m_left;
                m_top    = (a.m_top    > b.m_top   ) ? a.m_top    : b.m_top;
                m_right  = (a.m_right  < b.m_right ) ? a.m_right  : b.m_right;
                m_bottom = (a.m_bottom < b.m_bottom) ? a.m_bottom : b.m_bottom;
                return true;
            }
            return false;
        }
        
        NGBool intersect(NGInt ileft, NGInt itop, NGInt iright, NGInt ibottom)
        {
            if (ileft < iright && itop < ibottom && !this->isEmpty() &&
                    m_left < iright && ileft < m_right && m_top < ibottom && itop < m_bottom) {
                if (m_left < ileft) m_left = ileft;
                if (m_top < itop) m_top = itop;
                if (m_right > iright) m_right = iright;
                if (m_bottom > ibottom) m_bottom = ibottom;
                return true;
            }
            return false;
        }
    
        /**
         * Update this rectangle to enclose itself and the specified rectangle.
         * If this rectangle is empty, just set it to the specified rectangle. If the specified
         * rectangle is empty, do nothing.
         */
        void join(NGInt ileft, NGInt itop, NGInt iright, NGInt ibottom);

        /**
         * Update this rectangle to enclose itself and the specified rectangle.
         * If this rectangle is empty, just set it to the specified rectangle. If the specified
         * rectangle is empty, do nothing.
         */
        void join(const IntRect& irc)
        {
            join(irc.m_left, irc.m_top, irc.m_right, irc.m_bottom);
        }

        /**
         * Swap top/bottom or left/right if there are flipped.
         * This can be called if the edges are computed separately,
         * and may have crossed over each other.
         * When this returns, left <= right && top <= bottom
         */
        void sort();


		NGBool isIn(NGInt x, NGInt y) const {
			return (x >= m_left && x < m_right
					&& y >= m_top && y < m_bottom);
		}
    
    public:
        NGInt m_left;
        NGInt m_top;
        NGInt m_right;
        NGInt m_bottom;
};

NAMESPACE_END

#endif /* __NGUX_INTRECT_H__ */

