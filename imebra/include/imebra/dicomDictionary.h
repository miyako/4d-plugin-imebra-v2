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

/*! \file dicomDictionary.h
    \brief Declaration of the DicomDictionary class.

*/

#if !defined(imebraDicomDictionary__INCLUDED_)
#define imebraDicomDictionary__INCLUDED_

#include <string>
#include "dataSet.h"
#include "streamReader.h"
#include "streamWriter.h"
#include "definitions.h"

namespace imebra
{

class TagId;

///
/// \brief Provides information about the tag's description and their default
///        data type (VR).
///
///////////////////////////////////////////////////////////////////////////////
class IMEBRA_API DicomDictionary
{
public:
    /// \brief Retrieve a tag's description.
    ///
    /// @param id        the tag's id
    /// @return          The tag's description
    ///
    ///////////////////////////////////////////////////////////////////////////////
    static std::wstring getUnicodeTagName(const TagId& id);

    /// \brief Retrieve a tag's description.
    ///
    /// @param id        the tag's id
    /// @return          The tag's description
    ///
    ///////////////////////////////////////////////////////////////////////////////
    static std::string getTagName(const TagId& id);

    /// \brief Retrieve a tag's default data type.
    ///
    /// @param id        the tag's id
    /// @return          The tag's data type
    ///
    ///////////////////////////////////////////////////////////////////////////////
    static tagVR_t getTagType(const TagId& id);

    /// \brief Return the size of the data type's elements
    ///
    /// @param dataType the data type for which the information is required
    /// @return the size of a single element
    ///
    ///////////////////////////////////////////////////////////////////////////////
    static std::uint32_t getWordSize(tagVR_t dataType);

    /// \brief Return the maximum size of the tags with the specified data type.
    ///
    /// @param dataType the data type for which the information is required
    /// @return         the maximum tag's size in bytes
    ///
    ///////////////////////////////////////////////////////////////////////////////
    static std::uint32_t getMaxSize(tagVR_t dataType);
};

}
#endif // !defined(imebraDicomDictionary__INCLUDED_)
