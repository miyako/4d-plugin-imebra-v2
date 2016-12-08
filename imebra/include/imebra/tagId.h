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

/*! \file tagId.h
    \brief Declaration of the class TagId.

*/

#if !defined(imebraTagId__INCLUDED_)
#define imebraTagId__INCLUDED_

#ifndef SWIG

#include <cstdint>
#include <vector>
#include "tagsEnumeration.h"

#endif

#include "definitions.h"

namespace imebra
{

///
/// \brief Represents a Dicom tag's identification.
///
///////////////////////////////////////////////////////////////////////////////
class IMEBRA_API TagId
{
public:

    /// \brief Default constructor.
    ///
    /// Initializes the group id and the tag id to 0.
    ///
    ///////////////////////////////////////////////////////////////////////////////
    TagId();

    /// \brief Constructor.
    ///
    /// \param groupId    the group id
    /// \param tagId      the tag id
    ///
    ///////////////////////////////////////////////////////////////////////////////
    TagId(std::uint16_t groupId, std::uint16_t tagId);

    /// \brief Constructor.
    ///
    /// \param groupId    the group id
    /// \param groupOrder old DICOM files may have several groups with the same id.
    ///                   This parameter specifies which of the groups with the
    ///                   same id must be taken into consideration
    /// \param tagId      the tag id
    ///
    ///////////////////////////////////////////////////////////////////////////////
    TagId(std::uint16_t groupId, std::uint32_t groupOrder, std::uint16_t tagId);

#ifndef SWIGJAVA
    /// \brief Constructor.
    ///
    /// \param id an enumeration representing a tag group and id
    ///
    /// \warning Very large enumeration classes cause an error in Java, therefore
    ///          the tagId_t enumeration is not supported in Java.
    ///
    ///////////////////////////////////////////////////////////////////////////////
    TagId(tagId_t id);

    /// \brief Constructor.
    ///
    /// \param id         an enumeration representing a tag group and id
    /// \param groupOrder old DICOM files may have several groups with the same id.
    ///                   This parameter specifies which of the groups with the
    ///                   same id must be taken into consideration
    ///
    ///////////////////////////////////////////////////////////////////////////////
    TagId(tagId_t id, std::uint32_t groupOrder);
#endif

    virtual ~TagId();

    /// \brief Retrieve the group id.
    ///
    /// \return the group id
    ///
    ///////////////////////////////////////////////////////////////////////////////
    std::uint16_t getGroupId() const;

    /// \brief Return the group order. Old DICOM files may have several groups
    ///        with the same id. This value specifies which of the groups with the
    ///        same id has been taken into consideration.
    ///
    /// \return the group order
    ///
    ///////////////////////////////////////////////////////////////////////////////
    std::uint32_t getGroupOrder() const;

    /// \brief Retrieve the tag id.
    ///
    /// \return the tag id
    ///
    ///////////////////////////////////////////////////////////////////////////////
    std::uint16_t getTagId() const;

private:
    std::uint16_t m_groupId;
    std::uint32_t m_groupOrder;
    std::uint16_t m_tagId;
};

typedef std::vector<TagId> tagsIds_t;

}

#endif // !defined(imebraTagId__INCLUDED_)
