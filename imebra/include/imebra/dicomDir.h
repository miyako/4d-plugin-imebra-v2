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
    \brief Declaration of the class DicomDir.

*/

#if !defined(imebraDicomDir__INCLUDED_)
#define imebraDicomDir__INCLUDED_

#include <memory>
#include <string>
#include "definitions.h"

#ifndef SWIG

namespace imebra
{

namespace implementation
{
class dicomDir;
}
}

#endif

namespace imebra
{

class DataSet;
class DicomDirEntry;

///
/// \brief Represents a DICOMDIR structure.
///
/// In order to work DicomDir needs a DataSet, which embeds the DicomDir's
/// entries.
///
/// If the DicomDir's content is modified then the method updateDataSet()
/// has to be called before the managed DataSet can be stored as a DICOMDIR
/// file.
///
///////////////////////////////////////////////////////////////////////////////
class IMEBRA_API DicomDir
{
    DicomDir(const DicomDir&) = delete;
    DicomDir& operator=(const DicomDir&) = delete;

public:
    /// \brief Construct an empty DicomDir.
    ///
    ///////////////////////////////////////////////////////////////////////////////
    DicomDir();

    /// \brief Construct a DicomDir from a DataSet object.
    ///
    /// \param fromDataSet the DataSet created from reading a DICOMDIR file
    ///
    ///////////////////////////////////////////////////////////////////////////////
    DicomDir(const DataSet& fromDataSet);

    /// \brief Destructor.
    ///
    ///////////////////////////////////////////////////////////////////////////////
    virtual ~DicomDir();

    /// \brief Return a new DicomDirEntry record and insert it into the DicomDir's
    ///        DataSet.
    ///
    /// \param recordType the type of the new entry
    /// \return a new DicomDirEntry object that can be inserted into the DicomDir
    ///         object or one of its children DicomDirEntry entries.
    ///
    ///////////////////////////////////////////////////////////////////////////////
    DicomDirEntry* getNewEntry(directoryRecordType_t recordType);

    /// \brief Retrieve the first DicomDir's root entry.
    ///
    /// If the root entry is missing then return a null pointer.
    ///
    /// \return the root DicomDirEntry or a null pointer if the root
    ///         DicomDirEntry does noot exist
    ///
    ///////////////////////////////////////////////////////////////////////////////
    DicomDirEntry* getFirstRootEntry() const;

    /// \brief Set the specified entry as the first DicomDir's root record.
    ///
    /// After the DicomDir's content has been modified it is necessary to call
    /// updateDataSet() before the DataSet managed by DicomDir can be used.
    ///
    /// \param firstEntryRecord the DicomDirEntry object to set as the first root
    ///                         entry
    ///
    ///////////////////////////////////////////////////////////////////////////////
    void setFirstRootEntry(const DicomDirEntry& firstEntryRecord);

    /// \brief This method has to be called to update the managed DataSet after
    ///        the DicomDir's content has been updated.
    ///
    /// It is not necessary to call updateDataSet() after every DicomDir update,
    /// just call it when the updated DataSet object is needed.
    ///
    /// \return the updated managed DataSet object
    ///
    ///////////////////////////////////////////////////////////////////////////////
    DataSet* updateDataSet();

#ifndef SWIG
protected:
    std::shared_ptr<imebra::implementation::dicomDir> m_pDicomDir;
#endif
};

}

#endif // !defined(imebraDicomDir__INCLUDED_)
