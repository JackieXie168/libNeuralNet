/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.intelnics.com/opennn                                                                                   */
/*                                                                                                              */
/*   B O U N D I N G   L A Y E R   C L A S S   H E A D E R                                                      */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   Intelnics - The artificial intelligence company                                                            */
/*   robertolopez@intelnics.com                                                                                 */
/*                                                                                                              */
/****************************************************************************************************************/

#ifndef __BOUNDINGLAYER_H__
#define __BOUNDINGLAYER_H__

// System includes

#include <cmath>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

// OpenNN includes

#include "vector.h"
#include "matrix.h"

// TinyXml includes

#include "../tinyxml2/tinyxml2.h"

namespace OpenNN
{

/// This class represents a layer of bounding neurons. 
/// A bounding layer is used to ensure that variables will never fall below or above given values. 

class BoundingLayer
{

public:

   // DEFAULT CONSTRUCTOR

   explicit BoundingLayer(void);

   // BOUNDING NEURONS NUMBER CONSTRUCTOR

   explicit BoundingLayer(const unsigned&);

   // XML CONSTRUCTOR

   explicit BoundingLayer(const tinyxml2::XMLDocument&);

   // COPY CONSTRUCTOR

   BoundingLayer(const BoundingLayer&);

   // DESTRUCTOR

   virtual ~BoundingLayer(void);

   // ASSIGNMENT OPERATOR

   BoundingLayer& operator = (const BoundingLayer&);

   // EQUAL TO OPERATOR

   bool operator == (const BoundingLayer&) const;

   // ENUMERATIONS

   /// Enumeration of available methods for bounding the output variables.

   enum BoundingMethod{NoBounding, Boundind};

   // METHODS

   bool is_empty(void) const;

   unsigned get_bounding_neurons_number(void) const;

   // Variables bounds

   const Vector<double>& get_lower_bounds(void) const;
   double get_lower_bound(const unsigned&) const;

   const Vector<double>& get_upper_bounds(void) const;
   double get_upper_bound(const unsigned&) const;

   Vector< Vector<double>* > get_bounds(void);

   // Variables bounds

   void set(void);
   void set(const unsigned&);
   void set(const tinyxml2::XMLDocument&);
   void set(const BoundingLayer&);

   void set_lower_bounds(const Vector<double>&);
   void set_lower_bound(const unsigned&, const double&);

   void set_upper_bounds(const Vector<double>&);
   void set_upper_bound(const unsigned&, const double&);

   void set_bounds(const Vector< Vector<double> >&);

   void set_display(const bool&);

   void set_default(void);

   // Pruning and growing

   void prune_bounding_neuron(const unsigned&);

   // Initialization

   void initialize_random(void);

   // Lower and upper bounds

   Vector<double> calculate_outputs(const Vector<double>&) const;
   Vector<double> calculate_derivative(const Vector<double>&) const;
   Vector<double> calculate_second_derivative(const Vector<double>&) const;

   Matrix<double> arrange_Jacobian(const Vector<double>&) const;
   Vector< Matrix<double> > arrange_Hessian_form(const Vector<double>&) const;

   // Expression methods

   std::string write_expression(const Vector<std::string>&, const Vector<std::string>&) const;

   // Serialization methods

   std::string to_string(void) const;

   tinyxml2::XMLDocument* to_XML(void) const;
   void from_XML(const tinyxml2::XMLDocument&);

protected:

   // MEMBERS

   /// Lower bounds of output variables

   Vector<double> lower_bounds;

   /// Upper bounds of output variables

   Vector<double> upper_bounds;

   /// Display messages to screen. 

   bool display;
};

}

#endif


// OpenNN: Open Neural Networks Library.
// Neural Designer Copyright © 2013 Roberto López and Ismael Santana (Intelnics)
//
// This library is free software; you can redistribute it and/or
// modify it under the terms of the GNU Lesser General Public
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

