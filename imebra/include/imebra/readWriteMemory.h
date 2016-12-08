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

/*! \file readWriteMemory.h
    \brief Declaration of the class ReadWriteMemory.

*/

#if !defined(imebraReadWriteMemory__INCLUDED_)
#define imebraReadWriteMemory__INCLUDED_

#include <memory>
#include <string>
#include "definitions.h"
#include "readMemory.h"

#ifndef SWIG

namespace imebra
{
namespace implementation
{
class memory;
}
}
#endif

namespace imebra
{


///
/// \brief Manages a writable buffer of memory.
///
/// The buffer of memory is usually associated with a Tag buffer content.
///
/// The memory used by ReadMemory and ReadWriteMemory is managed by MemoryPool.
///
///////////////////////////////////////////////////////////////////////////////
class IMEBRA_API ReadWriteMemory: public ReadMemory
{
    ReadWriteMemory(const ReadWriteMemory&) = delete;
    ReadWriteMemory& operator=(const ReadWriteMemory&) = delete;

#ifndef SWIG
    friend class MemoryStreamOutput;
    friend class DrawBitmap;
    friend class WritingDataHandlerNumeric;
private:
    ReadWriteMemory(std::shared_ptr<implementation::memory> pMemory);
#endif

public:

    /// \brief Construct an empty buffer of memory.
    ///
    /// The memory can be resized later with resize().
    ///
    ///////////////////////////////////////////////////////////////////////////////
    ReadWriteMemory();

    /// \brief Construct a buffer of memory of the specified size.
    ///
    /// The memory can be resized later with resize().
    ///
    /// \param initialSize the initial memory's size, in bytes
    ///
    ///////////////////////////////////////////////////////////////////////////////
    ReadWriteMemory(size_t initialSize);

    /// \brief Construct a buffer of memory and copy the specified content into it.
    ///
    /// \param sourceMemory the object containing the initial memory's content
    ///
    ///////////////////////////////////////////////////////////////////////////////
    ReadWriteMemory(const ReadMemory& sourceMemory);

    /// \brief Construct a buffer of memory and copy the specified content into it.
    ///
    /// \param source      a pointer to the source data
    /// \param sourceSize  the amount of data to copy into the allocated memory
    ///
    ///////////////////////////////////////////////////////////////////////////////
    ReadWriteMemory(const char* source, size_t sourceSize);

    virtual ~ReadWriteMemory();

    /// \brief Copy the content from another memory object.
    ///
    /// \param sourceMemory the source memory object
    ///
    ///////////////////////////////////////////////////////////////////////////////
    void copyFrom(const ReadMemory& sourceMemory);

    /// \brief Resize the memory to zero bytes.
    ///
    ///////////////////////////////////////////////////////////////////////////////
    void clear();

    /// \brief Resize the memory.
    ///
    /// \param newSize the new memory size, in bytes
    ///
    ///////////////////////////////////////////////////////////////////////////////
    void resize(size_t newSize);

    /// \brief Reserve the specified amount of bytes, without changing the memory
    ///        size
    ///
    /// \param reserveSize the number of bytes to reserve
    ///
    ///////////////////////////////////////////////////////////////////////////////
    void reserve(size_t reserveSize);

#ifndef SWIG
    /// \brief Return a pointer to the referenced memory.
    ///
    /// The referenced buffer is owned by the ReadWriteMemory object and must
    /// not be freed by the client.
    ///
    /// \param pDataSize pointer to a variable that will be filled with the
    ///        memory size, in bytes
    /// \return a pointer to the referenced memory.
    ///        The referenced buffer is owned by the ReadWriteMemory object and
    ///        must not be freed by the client.
    ///
    ///
    ///////////////////////////////////////////////////////////////////////////////
    char* data(size_t* pDataSize) const;
#endif

    /// \brief Copy the content of the specified buffer into the ReadWriteMemory
    ///        object.
    ///
    /// \param source     a pointer to the source memory buffer
    /// \param sourceSize the number of bytes to copy and the new memory size
    ///
    ///////////////////////////////////////////////////////////////////////////////
    void assign(const char* source, size_t sourceSize);

    /// \brief Copy the content of the specified buffer into a region of the
    ///        ReadWriteMemory.
    ///
    /// The memory size remains unchanged.
    ///
    /// \param source     a pointer to the source memory buffer
    /// \param sourceSize the number of bytes to copy
    /// \param destinationOffset the offset into the ReadWriteMemory at which the
    ///                   data must be copied
    ///
    ///////////////////////////////////////////////////////////////////////////////
    void assignRegion(const char* source, size_t sourceSize, size_t destinationOffset);
};

}

#endif // !defined(imebraReadWriteMemory__INCLUDED_)
