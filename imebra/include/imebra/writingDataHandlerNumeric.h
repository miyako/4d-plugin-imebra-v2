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

/// \file writingDataHandlerNumeric.h
/// \brief Declaration of the class WritingDataHandlerNumeric.
///
///////////////////////////////////////////////////////////////////////////////

#if !defined(imebraWritingDataHandlerNumeric__INCLUDED_)
#define imebraWritingDataHandlerNumeric__INCLUDED_

#include <string>
#include <memory>
#include "definitions.h"
#include "readWriteMemory.h"
#include "writingDataHandler.h"

#ifndef SWIG

namespace imebra
{
namespace implementation
{
namespace handlers
{
class writingDataHandlerNumericBase;
}
}
}

#endif


namespace imebra
{

class ReadingDataHandlerNumeric;

///
/// \brief Specialized WritingDataHandler for numeric data types.
///
/// Includes few methods that allow accessing the raw memory containing the
/// buffer's data.
///
///////////////////////////////////////////////////////////////////////////////
class IMEBRA_API WritingDataHandlerNumeric: public WritingDataHandler
{
    WritingDataHandlerNumeric(const WritingDataHandlerNumeric&) = delete;
    WritingDataHandlerNumeric& operator=(const WritingDataHandlerNumeric&) = delete;

#ifndef SWIG
    friend class Image;
    friend class DataSet;
    friend class Tag;
    friend class ReadingDataHandlerNumeric;
private:
    WritingDataHandlerNumeric(std::shared_ptr<imebra::implementation::handlers::writingDataHandlerNumericBase> pDataHandler);
#endif

public:

    virtual ~WritingDataHandlerNumeric();

    /// \brief Return a ReadWriteMemory object referencing the raw buffer's data.
    ///
    /// \return a ReadWriteMemory object referencing the raw buffer's data
    ///
    ///////////////////////////////////////////////////////////////////////////////
    ReadWriteMemory* getMemory() const;

    /// \brief Copy the content of the specified buffer into the content managed
    ///        by data handler.
    ///
    /// \param source     a pointer to the source memory buffer
    /// \param sourceSize the number of bytes to copy and the new memory size
    ///
    ///////////////////////////////////////////////////////////////////////////////
    void assign(const char* source, size_t sourceSize);

#ifndef SWIG
    /// \brief Returns a pointer to the buffer's raw memory content.
    ///
    /// The referenced buffer is owned by the WritingDataHandlerNumeric
    /// object and must not be freed by the client.
    ///
    /// \param pDataSize a variable that will contain the raw memory's size in
    ///                  bytes
    /// \return a pointer to the buffer's raw memory. The referenced buffer
    ///         is owned by the WritingDataHandlerNumeric object and must not be
    ///         freed by the client
    ///
    ///////////////////////////////////////////////////////////////////////////////
    char* data(size_t* pDataSize) const;
#endif

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

    /// \brief Returns the number of bytes occupied by the numbers handled by the
    ///        data handler
    ///
    /// \return the number of bytes occupied by the numbers handled by the data
    ///         handler
    ///
    ///////////////////////////////////////////////////////////////////////////////
    size_t getUnitSize() const;

    /// \brief Returns true if the numbers handled by the data handler are signed,
    ///        false otherwise.
    ///
    /// \return true if the numbers handled by the data handler are signed, false
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

    /// \brief Copies data from another data handler, converting the data type
    ///        if necessary.
    ///
    /// The data handler is resized to the same size of the source data handler.
    ///
    /// \param source the data handler from which the data must be copied
    ///
    ///////////////////////////////////////////////////////////////////////////////
    void copyFrom(const ReadingDataHandlerNumeric& source);
};

}

#endif // !defined(imebraWritingDataHandlerNumeric__INCLUDED_)
