/* $Id$
 *
 * OpenMAMA: The open middleware agnostic messaging API
 * Copyright (C) 2011 NYSE Technologies, Inc.
 *
 * This library is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 *
 * This library is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public
 * License along with this library; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston, MA
 * 02110-1301 USA
 */

#include "mama/mamacpp.h"
#include "mamacppinternal.h"

namespace Wombat 
{
    
MamaDispatcher::MamaDispatcher (void)
    : mDispatcher (NULL)
{
}

MamaDispatcher::~MamaDispatcher (void)
{
    destroy();
}
    
void MamaDispatcher::create (MamaQueue* queue)
{
    mamaQueue qHandle = (queue == NULL) ? NULL : queue->getCValue();
    mamaTry (mamaDispatcher_create (&mDispatcher, qHandle));
}

void MamaDispatcher::destroy (void)
{
    if (mDispatcher)
    {
        mamaTry (mamaDispatcher_destroy (mDispatcher));
        mDispatcher = NULL;
    }
}

} // namespace Wombat
