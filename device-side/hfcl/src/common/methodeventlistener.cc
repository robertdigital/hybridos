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
 /*
  ** $Id: MethodEventListener.cpp 1829 2011-10-24 00:59:47Z dongjunjie $
  **
  ** MethodEventListener.cpp:
  **
  ** Copyright (C) 2003 ~ 2011 Beijing FMSoft Technologies Co., Ltd.
  **
  ** All rights reserved by FMSoft.
  **
  ** Current maintainer: shidazhi
  **
  ** Create date: 2011-06-08
  */

#include "nguxcommon.h"
#include "log.h"
#include "nguxobject.h"
#include "intrect.h"
#include "graphicscontext.h"
#include "nguxevent.h"
#include "methodeventlistener.h"

NAMESPACE_BEGIN

MethodEventListener::MethodEventListener(void* ctx, EventHandle event_handle, int event_type)
:EventListener(0)
{
	m_ctx = ctx;
	m_eventHandle = event_handle;
	m_eventType = event_type;
}

MethodEventListener::~MethodEventListener()
{
}

bool MethodEventListener::handleEvent(Event* event)
{
	if (m_ctx && m_eventHandle && event && (m_eventType == 0 || event->eventType() == m_eventType)) {
		(((MethodEventListener*) m_ctx)->*m_eventHandle)(event);
		return EVENT_HANDLED;
	}
	return EVENT_NOT_HANDLED;
}


NAMESPACE_END
