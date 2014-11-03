/****************************************************************************************************************/
/*                                                                                                              */
/*   OpenNN: Open Neural Networks Library                                                                       */
/*   www.intelnics.com/opennn                                                                                   */
/*                                                                                                              */
/*   I N D E P E N D E N T   P A R A M E T E R S   E R R O R   C L A S S   H E A D E R                          */
/*                                                                                                              */
/*   Roberto Lopez                                                                                              */
/*   Intelnics - The artificial intelligence company                                                            */
/*   robertolopez@intelnics.com                                                                                 */
/*                                                                                                              */
/****************************************************************************************************************/

#ifndef __INDEPENDENTPARAMETERSERROR_H__
#define __INDEPENDENTPARAMETERSERROR_H__

// System includes

#include <iostream>
#include <fstream>
#include <cmath>
#include <sstream>
#include <string>
#include <limits>

// OpenNN includes

#include "mathematical_model.h"

#include "performance_term.h"

// TinyXml includes

#include "../tinyxml2/tinyxml2.h"

namespace OpenNN
{

/// This performance term measures the error between a set of independent parameteres and a set of targer parameters. 
/// This performance term can be used in optimal control problems. 
///	A typical example are those problems with free final time.

class IndependentParametersError : public PerformanceTerm
{

public:

   // DEFAULT CONSTRUCTOR

   explicit IndependentParametersError(void);

   // NEURAL NETWORK CONSTRUCTOR

   explicit IndependentParametersError(NeuralNetwork*);

   // XML CONSTRUCTOR

   explicit IndependentParametersError(const tinyxml2::XMLDocument&);

   // DESTRUCTOR

   virtual ~IndependentParametersError(void);

   // ASSIGNMENT OPERATOR

   IndependentParametersError& operator = (const IndependentParametersError&);

   // EQUAL TO OPERATOR

   bool operator == (const IndependentParametersError&) const;

   // METHODS

   // Get methods

   const Vector<double>& get_target_independent_parameters(void) const;
   const double& get_target_independent_parameter(const unsigned&) const;

   const Vector<double>& get_independent_parameters_errors_weights(void) const;
   const double& get_independent_parameter_error_weight(const unsigned&) const;

   // Set methods

   void set_target_independent_parameters(const Vector<double>&);
   void set_target_independent_parameter(const unsigned&, const double&);

   void set_independent_parameters_errors_weights(const Vector<double>&);
   void set_independent_parameter_error_weight(const unsigned&, const double&);

   void set_default(void);

   // Checking methods

   void check(void) const;

   // performance methods

   double calculate_performance(void) const;   
   double calculate_performance(const Vector<double>&) const;   

   Vector<double> calculate_gradient(void) const;   
   Matrix<double> calculate_Hessian(void) const;   

   std::string write_performance_term_type(void) const;

   std::string write_information(void) const;

   // Serialization methods

   tinyxml2::XMLDocument* to_XML(void) const;   

   void from_XML(const tinyxml2::XMLDocument&);

private:

   /// Desired independent parameter values. 

   Vector<double> target_independent_parameters;

   /// Weight for each error between the actual independent parameters and their target values. 

   Vector<double> independent_parameters_errors_weights;

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
