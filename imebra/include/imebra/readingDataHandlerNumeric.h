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

/// \file readingDataHandlerNumeric.h
/// \brief Declaration of the class ReadingDataHandler and
///        WritingDataHandler.
///
///////////////////////////////////////////////////////////////////////////////

#if !defined(imebraReadingDataHandlerNumeric__INCLUDED_)
#define imebraReadingDataHandlerNumeric__INCLUDED_

#include <string>
#include <memory>
#include "definitions.h"
#include "readMemory.h"
#include "readingDataHandler.h"

#ifndef SWIG

namespace imebra
{
namespace implementation
{
namespace handlers
{
class readingDataHandlerNumericBase;
}
}
}

#endif


namespace imebra
{

class WritingDataHandlerNumeric;

///
/// \brief Specialized ReadingDataHandler for numeric data types.
///
/// Includes few methods that allow accessing the raw memory containing the
/// buffer's data.
///
///////////////////////////////////////////////////////////////////////////////
class IMEBRA_API ReadingDataHandlerNumeric: public ReadingDataHandler
{
    ReadingDataHandlerNumeric(const ReadingDataHandlerNumeric&) = delete;
    ReadingDataHandlerNumeric& operator=(const ReadingDataHandlerNumeric&) = delete;

public:
#ifndef SWIG
    friend class Image;
    friend class DataSet;
    friend class Tag;
    friend class LUT;
    friend class WritingDataHandlerNumeric;

private:
    ReadingDataHandlerNumeric(std::shared_ptr<imebra::implementation::handlers::readingDataHandlerNumericBase> pDataHandler);
#endif

public:
    virtual ~ReadingDataHandlerNumeric();

    /// \brief Return a ReadMemory object referencing the raw buffer's data.
    ///
    /// \return a ReadMemory object referencing the raw buffer's data
    ///
    ///////////////////////////////////////////////////////////////////////////////
    ReadMemory* getMemory() const;

    /// \brief Copies the buffer's raw memory content into the specified buffer.
    ///
    /// If the allocated buffer is not large enough then the method doesn't
    ///  copy any data and just returns the required buffer' size.
    ///
    /// \param destination     a pointer to the allocated buffer
    /// \param destinationSize the size of the allocated buffer
    /// \return the number of bytes to be copied into the pre-allocated buffer
    ///
    ///////////////////////////////////////////////////////////////////////////////
    size_t data(char* destination, size_t destinationSize) const;

#ifndef SWIG
    /// \brief Returns a pointer to the buffer's raw memory content.
    ///
    /// The referenced buffer is owned by the ReadingDataHandlerNumeric object and
    /// must not be freed by the client.
    ///
    /// \param pDataSize a variable that will contain the raw memory's size in
    ///                  bytes
    /// \return a pointer to the buffer's raw memory.
    ///        The referenced buffer is owned by the ReadingDataHandlerNumeric
    ///        object and must not be freed by the client.
    ///
    ///
    ///////////////////////////////////////////////////////////////////////////////
    const char* data(size_t* pDataSize) const;
#endif

    /// \brief Returns the number of bytes occupied by the numbers handled by the
    ///        data handler
    ///
    /// \return the number of bytes occupied by the numbers handled by the data
    ///         handler
    ///
    ///////////////////////////////////////////////////////////////////////////////
    size_t getUnitSize() const;

    /// \brief Returns true if the numbers stored in the buffer are signed, false
    ///        otherwise.
    ///
    /// \return true if the numbers stored in the buffer are signed, false
    ///         otherwise
    ///
    ///////////////////////////////////////////////////////////////////////////////
    bool isSigned() const;

    /// \brief Returns true if the numbers stored in the buffer are floating point
    ///        numbers, false otherwise.
    ///
    /// \return true if the numbers stored in the buffer are floating point
    ///         numbers, false otherwise
    ///
    ///////////////////////////////////////////////////////////////////////////////
    bool isFloat() const;

    /// \brief Copies the content of the data handler into another data handler,
    ///        converting the data to the destination handler data type.
    ///
    /// \warning the size of the destination data handler stays unchanged: if
    ///          the destination too small to contain all the data to be copied
    ///          then only a part of the data will be copied.
    ///
    /// \param destination the destination data handler
    ///
    ///////////////////////////////////////////////////////////////////////////////
    void copyTo(const WritingDataHandlerNumeric& destination);
};

}

#endif // !defined(imebraReadingDataHandlerNumeric__INCLUDED_)
