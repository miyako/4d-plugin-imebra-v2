/*

Imebra 4.0.7.1 changeset 108a911a22e1

Imebra: a C++ Dicom library

Copyright (c) 2003, 2004, 2005, 2006, 2007, 2008, 2009, 2010, 2011, 2012, 2013, 2014, 2015, 2016
by Paolo Brandoli/Binarno s.p.

All rights reserved.

This program is free software; you can redistribute it and/or modify
 it under the terms of the GNU General Public License version 2 as published by
 the Free Software Foundation.

This program is distributed in the hope that it will be useful,
 but WITHOUT ANY WARRANTY; without even the implied warranty of
 MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 GNU General Public License for more details.

You should have received a copy of the GNU General Public License
 along with this program; if not, write to the Free Software
 Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA

-------------------

If you want to use Imebra commercially then you have to buy the commercial
 license available at http://imebra.com

After you buy the commercial license then you can use Imebra according
 to the terms described in the Imebra Commercial License.
A copy of the Imebra Commercial License is available at http://imebra.com.

Imebra is available at http://imebra.com

The author can be contacted by email at info@binarno.com or by mail at
 the following address:
 Binarno s.p., Paolo Brandoli
 Rakuseva 14
 1000 Ljubljana
 Slovenia



*/

/*! \file memoryPool.h
    \brief Declaration of the class MemoryPool.

*/

#if !defined(imebraMemoryPool__INCLUDED_)
#define imebraMemoryPool__INCLUDED_

#ifndef SWIG

#include <memory>
#include <string>
#include "definitions.h"

namespace imebra
{
namespace implementation
{
class memoryPool;
}
}
#endif

namespace imebra
{

///
/// \brief Used by Imebra to allocate memory.
///
/// MemoryPool keeps around recently deleted memory regions so they can be
/// repurposed quickly when new memory regions are requested.
///
/// Each thread has its own MemoryPool object.
///
///////////////////////////////////////////////////////////////////////////////
class IMEBRA_API MemoryPool
{
public:
    /// \brief Release all the unused memory regions.
    ///
    ///////////////////////////////////////////////////////////////////////////////
    static void flush();

    /// \brief Return the total size of the memory that has been released but not
    ///        yet freed.
    ///
    /// \return the total size of the memory released but not yet freed
    ///
    ///////////////////////////////////////////////////////////////////////////////
    static size_t getUnusedMemorySize();

    /// \brief Set the maximum size of the kept unused memory.
    ///
    /// \param minMemoryBlockSize  if a memory region is smaller than this size
    ///                            then when it is released it is deleted
    ///                            immediately, otherwise it is kept in the memory
    ///                            pool
    /// \param maxMemoryPoolSize   the maximum size of the sum of all the unused
    ///                            memory regions. When the total size of the
    ///                            unused memory regions is greater than this
    ///                            parameter then the oldest memory regions are
    ///                            deleted permanently
    ///
    ///////////////////////////////////////////////////////////////////////////////
    static void setMemoryPoolSize(size_t minMemoryBlockSize, size_t maxMemoryPoolSize);
};

}

#endif // !defined(imebraMemoryPool__INCLUDED_)
