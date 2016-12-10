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

/// \file writingDataHandler.h
/// \brief Declaration of the class WritingDataHandler.
///
///////////////////////////////////////////////////////////////////////////////

#if !defined(imebraWritingDataHandler__INCLUDED_)
#define imebraWritingDataHandler__INCLUDED_

#include <string>
#include <memory>
#include "definitions.h"

#ifndef SWIG

namespace imebra
{
namespace implementation
{
namespace handlers
{
class writingDataHandler;
}
}
}

#endif


namespace imebra
{

///
/// \brief The WritingDataHandler class allows to write the content
///        of a Dicom tag's buffer.
///
/// WritingDataHandler is able to write into the buffer's content strings,
/// numbers, date/time or ages.
///
/// In order to obtain a WritingDataHandler object for a specific tag stored
/// in a DataSet, call DataSet::getWritingDataHandler() or
/// Tag::getWritingDataHandler().
///
/// The WritingDataHandler object always works on a new and clean memory area.
/// The buffer's memory is replaced by the WritingDataHandler memory when the
/// data handler is destroyed.
///
///////////////////////////////////////////////////////////////////////////////
class IMEBRA_API WritingDataHandler
{
    WritingDataHandler(const WritingDataHandler&) = delete;
    WritingDataHandler& operator=(const WritingDataHandler&) = delete;

#ifndef SWIG
    friend class DataSet;
    friend class Tag;
    friend class WritingDataHandlerNumeric;

private:
    WritingDataHandler(std::shared_ptr<imebra::implementation::handlers::writingDataHandler> pDataHandler);
#endif

public:
    /// \brief Destructor: replaces the tag buffer's memory with the memory created
    ///        by this WritingDataHandler.
    ///
    ///////////////////////////////////////////////////////////////////////////////
    virtual ~WritingDataHandler();

    /// \brief Resize the memory to contain the specified number of elements.
    ///
    /// By default, the WritingDataHandler buffer allocates an empty memory block
    /// that must be resized in order to be filled with data.
    ///
    /// The type of the contained elements depends on the tag's VR. The VR can be
    /// retrieved with getDataType().
    ///
    /// \param elementsNumber the number of elements to store in the buffer.
    ///
    ///////////////////////////////////////////////////////////////////////////////
    void setSize(size_t elementsNumber);

    /// \brief Retrieve the number of elements that can be stored in the buffer
    ///        controlled by WritingDataHandler.
    ///
    /// The memory size can be changed with setSize().
    ///
    /// The type of the contained elements depends on the tag's VR. The VR can be
    /// retrieved with getDataType().
    ///
    /// \return the number of elements that can be stored in the buffer
    ///
    ///////////////////////////////////////////////////////////////////////////////
    size_t getSize() const;

    /// \brief Returns the data type (VR) of the data handled by the data handler.
    ///
    /// \return the data type of the handled data
    ///
    ///////////////////////////////////////////////////////////////////////////////
    tagVR_t getDataType() const;

    /// \brief Write a signed long integer (32 bit).
    ///
    /// If the value cannot be converted from a signed long integer
    /// then throws DataHandlerConversionError.
    ///
    /// \param index the element number within the buffer. Must be smaller than
    ///        getSize()
    /// \param value the value to write
    ///
    ///////////////////////////////////////////////////////////////////////////////
    void setSignedLong(size_t index, std::int32_t value);

    /// \brief Write an unsigned long integer (32 bit).
    ///
    /// If the value cannot be converted from an unsigned long integer
    /// then throws DataHandlerConversionError.
    ///
    /// \param index the element number within the buffer. Must be smaller than
    ///        getSize()
    /// \param value the value to write
    ///
    ///////////////////////////////////////////////////////////////////////////////
    void setUnsignedLong(size_t index, std::uint32_t value);

    /// \brief Write a double floating point value (64 bit).
    ///
    /// If the value cannot be converted from a double floating point
    /// then throws DataHandlerConversionError.
    ///
    /// \param index the element number within the buffer. Must be smaller than
    ///        getSize()
    /// \param value the value to write
    ///
    ///////////////////////////////////////////////////////////////////////////////
    void setDouble(size_t index, double value);

    /// \brief Write a string.
    ///
    /// If the value cannot be converted from a string
    /// then throws DataHandlerConversionError.
    ///
    /// \param index the element number within the buffer. Must be smaller than
    ///        getSize()
    /// \param value the value to write
    ///
    ///////////////////////////////////////////////////////////////////////////////
    void setString(size_t index, const std::string& value);

#ifndef SWIG
    /// \brief Write an Unicode string.
    ///
    /// If the value cannot be converted from a Unicode string
    /// then throws DataHandlerConversionError.
    ///
    /// \param index the element number within the buffer. Must be smaller than
    ///        getSize()
    /// \param value the value to write
    ///
    ///////////////////////////////////////////////////////////////////////////////
    void setUnicodeString(size_t index, const std::wstring& value);
#endif

    /// \brief Write a date and/or a time.
    ///
    /// If the value cannot be converted from a Date
    /// then throws DataHandlerConversionError.
    ///
    /// \param index the element number within the buffer. Must be smaller than
    ///        getSize()
    /// \param date  the value to write
    ///
    ///////////////////////////////////////////////////////////////////////////////
    void setDate(size_t index, const Date& date);

    /// \brief Write an Age value.
    ///
    /// If the value cannot be converted from an Age
    /// then throws DataHandlerConversionError.
    ///
    /// \param index the element number within the buffer. Must be smaller than
    ///        getSize()
    /// \param age   the value to write
    ///
    ///////////////////////////////////////////////////////////////////////////////
    void setAge(size_t index, const Age& age);


#ifndef SWIG
protected:
    std::shared_ptr<imebra::implementation::handlers::writingDataHandler> m_pDataHandler;
#endif
};

}

#endif // !defined(imebraWritingDataHandler__INCLUDED_)
