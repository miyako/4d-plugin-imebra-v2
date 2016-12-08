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

/*! \file readMemory.h
    \brief Declaration of the class ReadMemory.

*/

#if !defined(imebraReadMemory__INCLUDED_)
#define imebraReadMemory__INCLUDED_

#include <memory>
#include <string>
#include "definitions.h"

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
/// \brief Manages a read-only buffer of memory.
///
/// The buffer of memory is usually associated with a Tag buffer content.
///
/// The memory used by ReadMemory and ReadWriteMemory is managed by MemoryPool.
///
///////////////////////////////////////////////////////////////////////////////
class IMEBRA_API ReadMemory
{
    ReadMemory(const ReadMemory&) = delete;
    ReadMemory& operator=(const ReadMemory&) = delete;

#ifndef SWIG
    friend class MemoryStreamInput;
    friend class ReadWriteMemory;
    friend class ReadingDataHandlerNumeric;
private:
    ReadMemory(std::shared_ptr<const implementation::memory> pMemory);
#endif


public:
    /// \brief Construct an empty buffer of memory.
    ///
    ///////////////////////////////////////////////////////////////////////////////
    ReadMemory();

    /// \brief Construct a buffer of memory and copy the specified content into it.
    ///
    /// \param source      a pointer to the source data
    /// \param sourceSize  the amount of data to copy into the allocated memory
    ///
    ///////////////////////////////////////////////////////////////////////////////
    ReadMemory(const char* source, size_t sourceSize);

    virtual ~ReadMemory();

    /// \brief Return the memory size, in bytes.
    ///
    /// \return the memory size in bytes
    ///
    ///////////////////////////////////////////////////////////////////////////////
    size_t size() const;

    /// \brief Copies the raw memory content into the specified buffer.
    ///
    /// If the allocated buffer is not large enough then the method doesn't
    ///  copy any data and just returns the required buffer' size.
    ///
    /// \param destination     a pointer to the allocated buffer
    /// \param destinationSize the size of the allocated buffer, in bytes
    /// \return the number of bytes to be copied into the pre-allocated buffer
    ///
    ///////////////////////////////////////////////////////////////////////////////
    size_t data(char* destination, size_t destinationSize) const;

    /// \brief Copies the raw memory region into the specified buffer.
    ///
    /// If the memory's size is too small to extract the requested region then
    /// throws MemorySizeError.
    ///
    /// \param destination     a pointer to the allocated buffer
    /// \param destinationSize the size of the allocated buffer, in bytes
    /// \param sourceOffset    the offset
    ///
    ///////////////////////////////////////////////////////////////////////////////
    void regionData(char* destination, size_t destinationSize, size_t sourceOffset) const;

#ifndef SWIG
    /// \brief Return a pointer to the constant referenced memory.
    ///
    /// The referenced buffer is owned by the ReadMemory object and must
    /// not be freed by the client.
    ///
    /// \param pDataSize pointer to a variable that will be filled with the
    ///        memory size, in bytes
    /// \return a pointer to the referenced memory.
    ///        The referenced buffer is owned by the ReadMemory object and must
    ///        not be freed by the client.
    ///
    ///////////////////////////////////////////////////////////////////////////////
    const char* data(size_t* pDataSize) const;
#endif

    /// \brief Return true if the referenced memory is zero bytes long or hasn't
    ///        been allocated yet.
    ///
    /// \return true if the referenced memory does not exist or is empty
    ///
    ///////////////////////////////////////////////////////////////////////////////
    bool empty() const;

#ifndef SWIG
protected:
    std::shared_ptr<const implementation::memory> m_pMemory;
#endif
};

}

#endif // !defined(imebraReadMemory__INCLUDED_)
