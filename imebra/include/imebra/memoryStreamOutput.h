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


#if !defined(imebraMemoryStreamOutput__INCLUDED_)
#define imebraMemoryStreamOutput__INCLUDED_

#include <string>
#include "baseStreamOutput.h"
#include "definitions.h"

namespace imebra
{

class ReadWriteMemory;

///
/// \brief An output stream that writes data into a memory region.
///
/// When new data is written into the memory then it is resized as necessary.
///
///////////////////////////////////////////////////////////////////////////////
class IMEBRA_API MemoryStreamOutput : public BaseStreamOutput
{
    MemoryStreamOutput(const MemoryStreamOutput&) = delete;
    MemoryStreamOutput& operator=(const MemoryStreamOutput&) = delete;

public:
    /// \brief Constructor.
    ///
    /// \param memory the memory region into which the stream will write the data
    ///
    ///////////////////////////////////////////////////////////////////////////////
    MemoryStreamOutput(const ReadWriteMemory& memory);

    virtual ~MemoryStreamOutput();
};

}
#endif // !defined(imebraMemoryStreamOutput__INCLUDED_)
