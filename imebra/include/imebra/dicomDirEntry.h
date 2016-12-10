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

/*! \file dicomDir.h
    \brief Declaration of the class DicomDirEntry
        structure (DicomDir and DirectoryRecord)

*/

#if !defined(imebraDicomDirEntry__INCLUDED_)
#define imebraDicomDirEntry__INCLUDED_

#include <memory>
#include <string>
#include "definitions.h"

#ifndef SWIG

namespace imebra
{
namespace implementation
{
class directoryRecord;
}
}

#endif

namespace imebra
{

class DataSet;

///
/// \brief Represents a single DICOMDIR entry.
///
/// Each entry can be followed by a sibling entry (on the same depth level)
/// or can point to its first child entry (one level deeper).
///
/// Each DicomDirEntry object manages a DataSet which is used to store the
/// entry's data. The DataSet objects managed by DicomDirEntry objects are
/// inserted as sequence items into the DicomDir's DataSet.
///
///////////////////////////////////////////////////////////////////////////////
class IMEBRA_API DicomDirEntry
{
    DicomDirEntry(const DicomDirEntry&) = delete;
    DicomDirEntry& operator=(const DicomDirEntry&) = delete;

#ifndef SWIG
	friend class DicomDir;
private:
    DicomDirEntry(std::shared_ptr<imebra::implementation::directoryRecord> pDirectoryRecord);
#endif

public:

    virtual ~DicomDirEntry();

    /// \brief Return the DataSet managed by the DicomDirEntry object.
    ///
    /// \return the DataSet managed by the DicomDirEntry object
    /// 
    ///////////////////////////////////////////////////////////////////////////////
    DataSet* getEntryDataSet();

    /// \brief Return the next sibling entry (on the same depth level).
    /// 
    /// If the next DicomDirEntry is missing (this is the last entry) then
    /// return a null pointer.
    ///
    /// \return the next sibling DicomDirEntry object, or a null pointer if the
    ///         next sibling DicomDirEntry does not exist
    /// 
    ///////////////////////////////////////////////////////////////////////////////
    DicomDirEntry* getNextEntry();

    /// \brief Return the first child entry (one level deeper).
    /// 
    /// If the first child DicomDirEntry is missing then return a null pointer.
    ///
    /// \return the first child DicomDirEntry object, or a null pointer if there
    ///         aren't any children
    /// 
    ///////////////////////////////////////////////////////////////////////////////
    DicomDirEntry* getFirstChildEntry();
	
    /// \brief Set the next sibling entry (one the same depth level).
    /// 
    /// \param nextEntry the next sibling DicomDirEntry object
    /// 
    ///////////////////////////////////////////////////////////////////////////////
    void setNextEntry(const DicomDirEntry& nextEntry);

    /// \brief Set the first child entry (one level deeper).
    /// 
    /// \param firstChildEntry the first child DicomDirEntry object
    /// 
    ///////////////////////////////////////////////////////////////////////////////
    void setFirstChildEntry(const DicomDirEntry& firstChildEntry);

    /// \brief Returns the parts that form the name of the file referenced by the
    ///        DicomDirEntry object.
    /// 
    /// \return a list of strings that form the name of the file referenced by the
    ///         DicomDirEntry object. The last item in the list is the file name,
    ///         while the preceding items contain the folders names.
    ///         For instance, on Linux the parts "folder0", "folder1", "fileName"
    ///         represent the path "folder0/folder1/fileName"
    /// 
    ///////////////////////////////////////////////////////////////////////////////
    fileParts_t getFileParts() const;

    /// \brief Set the parts that form the name of the file referenced by the
    ///        DicomDirEntry object.
    /// 
    /// \param fileParts  a list of strings that form the name of the file 
    ///                   referenced by the DicomDirEntry object. The last item 
    ///                   in the list is the file name, while the preceding items 
    ///                   contain the folders names.
    ///                   For instance, on Linux the parts "folder0", "folder1", 
    ///                   "fileName" represent the path "folder0/folder1/fileName"
    /// 
    ///////////////////////////////////////////////////////////////////////////////
    void setFileParts(const fileParts_t& fileParts);

    /// \brief 
    directoryRecordType_t getType() const;

    std::string getTypeString() const;

#ifndef SWIG
protected:
    std::shared_ptr<imebra::implementation::directoryRecord> m_pDirectoryRecord;
#endif
};

}

#endif // !defined(imebraDicomDirEntry__INCLUDED_)
