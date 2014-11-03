/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.opennn.cimne.com                                                                                        */
/*                                                                                                              */
/*   A R C   L E N G T H   C L A S S   H E A D E R                                                              */
/*                                                                                                              */ 
/*   Roberto Lopez                                                                                              */ 
/*   International Center for Numerical Methods in Engineering (CIMNE)                                          */
/*   Technical University of Catalonia (UPC)                                                                    */
/*   Barcelona, Spain                                                                                           */
/*   E-mail: rlopez@cimne.upc.es                                                                                */ 
/*                                                                                                              */
/****************************************************************************************************************/

#ifndef __ARCLENGTH_H__
#define __ARCLENGTH_H__

#include "../../source/opennn.h"

namespace OpenNN
{

class ArcLength : public OrdinaryDifferentialEquations
{

public:

   // DEFAULT CONSTRUCTOR

   explicit ArcLength(void);

   // DESTRUCTOR

   virtual ~ArcLength(void);


   // METHODS

   // Get methods

   // Set methods

   void set_default(void);

   // Mathematical model methods

   Vector<double> calculate_dependent_variables_dots(const NeuralNetwork&, const Vector<double>&) const;
};

}

#endif


// OpenNN: Open Neural Networks Library.
// Copyright (C) 2005-2012 Roberto Lopez 
//
// This library is free software; you can redistribute it and/or
// modify it under the s of the GNU Lesser General Public
// License as published by the Free Software Foundation; either
// version 2.1 of the License, or any later version.
//
// This library is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
// Lesser General Public License for more details.

// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
