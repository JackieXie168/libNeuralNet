/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.intelnics.com/opennn                                                                                   */
/*                                                                                                              */
/*   R O O T   M E A N   S Q U A R E D   E R R O R   C L A S S   H E A D E R                                    */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   Intelnics - The artificial intelligence company                                                            */
/*   robertolopez@intelnics.com                                                                                 */
/*                                                                                                              */
/****************************************************************************************************************/

#ifndef __ROOTMEANSQUAREDERROR_H__
#define __ROOTMEANSQUAREDERROR_H__

// System includes

#include <iostream>
#include <cmath>
#include <fstream>
#include <limits>
#include <sstream>
#include <string>

// OpenNN includes

#include "performance_term.h"
#include "data_set.h"

// TinyXml includes

#include "../tinyxml2/tinyxml2.h"

namespace OpenNN
{

/// This class represents the root mean squared error performance term.
/// The root mean squared error measures the difference between the outputs from a neural network and the targets in a data set. 
/// This functional is used in data modeling problems.

class RootMeanSquaredError : public PerformanceTerm
{

public:

   // DEFAULT CONSTRUCTOR

   explicit RootMeanSquaredError(void);

   // NEURAL NETWORK CONSTRUCTOR

   explicit RootMeanSquaredError(NeuralNetwork*);

   // DATA SET CONSTRUCTOR

   explicit RootMeanSquaredError(DataSet*);

   // GENERAL CONSTRUCTOR

   explicit RootMeanSquaredError(NeuralNetwork*, DataSet*);

   // XML CONSTRUCTOR

   explicit RootMeanSquaredError(const tinyxml2::XMLDocument&);

   // DESTRUCTOR

   virtual ~RootMeanSquaredError(void);

   // METHODS

   // Get methods

   // Set methods

   // Checking methods

   void check(void) const;

   // Performance term performance methods

   double calculate_performance(void) const;
   double calculate_performance(const Vector<double>&) const;   
   double calculate_generalization_performance(void) const;   

   Vector<double> calculate_gradient(void) const;

   Matrix<double> calculate_Hessian(void) const;

   std::string write_performance_term_type(void) const;

   // Serialization methods

   tinyxml2::XMLDocument* to_XML(void) const;   
   void from_XML(const tinyxml2::XMLDocument&);

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
//
// You should have received a copy of the GNU Lesser General Public
// License along with this library; if not, write to the Free Software
// Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
