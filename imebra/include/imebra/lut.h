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

/*! \file tag.h
    \brief Declaration of the class Tag.

*/

#if !defined(imebraLut__INCLUDED_)
#define imebraLut__INCLUDED_

#include <string>
#include <cstdint>
#include "readingDataHandlerNumeric.h"
#include "definitions.h"

#ifndef SWIG

namespace imebra
{
namespace implementation
{
class lut;
}
}

#endif

namespace imebra
{

///
/// \brief This class represents Lookup Table.
///
///////////////////////////////////////////////////////////////////////////////
class IMEBRA_API LUT
{
    LUT(const LUT&) = delete;
    LUT& operator=(const LUT&) = delete;

#ifndef SWIG
    friend class DataSet;
    friend class VOILUT;
private:
    LUT(std::shared_ptr<imebra::implementation::lut> pLut);
#endif

public:
    virtual ~LUT();

    /// \brief Returns the LUT's description.
    ///
    /// \return the LUT's description
    ///
    ///////////////////////////////////////////////////////////////////////////////
    std::wstring getDescription() const;

    ReadingDataHandlerNumeric* getReadingDataHandler() const;

    /// \brief Return the number of bits used to store a LUT value.
    ///
    /// @return the number of bits used to store a mapped value
    ///
    ///////////////////////////////////////////////////////////////////////////////
    size_t getBits() const;

    /// \brief Return the lut's size (the number of stored values).
    ///
    /// @return the number of mapped values stored in the lut
    ///
    ///////////////////////////////////////////////////////////////////////////////
    size_t getSize() const;

    std::int32_t getFirstMapped() const;

    std::uint32_t getMappedValue(std::int32_t index) const;


#ifndef SWIG
protected:
    std::shared_ptr<imebra::implementation::lut> m_pLut;
#endif
};

}

#endif // !defined(imebraLut__INCLUDED_)
