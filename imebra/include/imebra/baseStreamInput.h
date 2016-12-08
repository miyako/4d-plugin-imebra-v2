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

/*! \file baseStreamInput.h
    \brief Declaration of the the base stream class BaseStreamInput.
*/

#if !defined(imebraBaseStreamInput__INCLUDED_)
#define imebraBaseStreamInput__INCLUDED_

#ifndef SWIG

#include <memory>
#include "definitions.h"

namespace imebra
{
namespace implementation
{
    class baseStreamInput;
}
}

#endif

namespace imebra
{

///
/// \brief This class represents a generic input stream.
///
/// Specialized classes derived from this one can read data from files stored
/// on the computer's disks (FileStreamInput) or from memory
/// (MemoryStreamInput).
///
/// The client application cannot read the data directly from a
/// BaseStreamInput but must use a StreamReader. Several StreamReader objects
/// can read data from the same BaseStreamInput object.
///
/// The StreamReader class is not thread-safe, but different StreamReader
/// objects in different threads can access the same BaseStreamInput object.
///
///////////////////////////////////////////////////////////////////////////////
class IMEBRA_API BaseStreamInput
{
    BaseStreamInput(const BaseStreamInput&) = delete;
    BaseStreamInput& operator=(const BaseStreamInput&) = delete;

#ifndef SWIG
	friend class StreamReader;
    friend class FileStreamInput;
    friend class MemoryStreamInput;

private:
    /// \brief Construct a BaseStreamInput object from an implementation object.
    ///
    /// \param pStream the implementation of BaseStreamInput
    ///
    ///////////////////////////////////////////////////////////////////////////////
    BaseStreamInput(std::shared_ptr<implementation::baseStreamInput> pStream);
#endif

public:
    /// \brief Destructor.
    ///
    ///////////////////////////////////////////////////////////////////////////////
    virtual ~BaseStreamInput();

#ifndef SWIG
protected:
    std::shared_ptr<implementation::baseStreamInput> m_pStream;
#endif
};

}

#endif // !defined(imebraBaseStreamInput__INCLUDED_)
